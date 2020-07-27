#include "pch.h"
#include "SmSymbolManager.h"
#include "SmSymbol.h"
#include "SmMarketManager.h"
#include "../HdCtrl/HdClient.h"
#include "../Util/SmUtil.h"
#include "../Network/SmSessionManager.h"
#include "../Network/SmServiceDefine.h"
#include "../Config/SmConfigManager.h"
#include <chrono>
#include <sstream>
#include <fstream>
#include "../Util/VtStringUtil.h"
#include "../Log/loguru.hpp"
#include <algorithm>
//#include "../SmDate.h"
#include "../Json/json.hpp"
#include "../Format/format.h"

using namespace nlohmann;

using namespace std::chrono;


SmSymbolManager::SmSymbolManager()
{
}


SmSymbolManager::~SmSymbolManager()
{
	StopThread();

	for (auto it = _SymbolMap.begin(); it != _SymbolMap.end(); ++it) {
		delete it->second;
	}

	for (auto it = _CycleDataReqTimerMap.begin(); it != _CycleDataReqTimerMap.end(); ++it) {
		_Timer.remove(it->second);
	}
}

SmSymbol* SmSymbolManager::FindAddSymbol(std::string symbol_code)
{
	SmSymbol* symbol = FindSymbol(symbol_code);
	if (!symbol) {
		symbol = new SmSymbol();
		symbol->SymbolCode(symbol_code);
		AddSymbol(symbol);
	}

	return symbol;
}

void SmSymbolManager::AddSymbol(SmSymbol* sym)
{
	if (!sym)
		return;

	_SymbolMap[sym->SymbolCode()] = sym;
}

SmSymbol* SmSymbolManager::FindSymbol(std::string symCode)
{
	auto it = _SymbolMap.find(symCode);
	if (it != _SymbolMap.end()) {
		return it->second;
	}

	return nullptr;
}

void SmSymbolManager::AddFutTask(SmTickData&& item)
{
	// 비활성화 되면 수집하지 않는다.
	if (!_Enable)
		return;
	// 추가하고 즉시 반환한다. 혹시 큐가 이용할수 없는 상황이라도 반환한다.
	// 반드시 추가하는 경우에는 add() 함수를 이용한다.
	_FutTaskQueue.try_add(item);
}

void SmSymbolManager::AddAbroadTask(SmTickData&& item)
{
	// 비활성화 되면 수집하지 않는다.
	if (!_Enable)
		return;
	// 추가하고 즉시 반환한다. 혹시 큐가 이용할수 없는 상황이라도 반환한다.
	// 반드시 추가하는 경우에는 add() 함수를 이용한다.
	_AbroadTaskQueue.try_add(item);
}

void SmSymbolManager::StartCollectData()
{
	StartTaskThread();

	SmMarketManager* mrktMgr = SmMarketManager::GetInstance();
	std::vector<SmSymbol*> symbol_list = mrktMgr->GetRecentMonthSymbolList();

	for (auto it = symbol_list.begin(); it != symbol_list.end(); ++it) {
		SmSymbol* symbol = *it;
		//if (symbol->SymbolCode().compare("CLN20") == 0) {
		HdClient::GetInstance()->RegisterProduct(symbol->SymbolCode().c_str());
		//}
	}

	StartTimer();
}



void SmSymbolManager::StartTaskThread()
{
	if (_ThreadStarted)
		return;

	_FutTaskThread = std::thread(&SmSymbolManager::ProcessFutTask, this);
	_AbroadTaskThread = std::thread(&SmSymbolManager::ProcessAbroadTask, this);

	_ThreadStarted = true;
}

void SmSymbolManager::ClearTasks()
{
	_FutTaskQueue.flush();
	_AbroadTaskQueue.flush();
}

void SmSymbolManager::StopThread()
{
	// 더이상 입력을 받지 않게 한다.
	_Enable = false;
	// 먼저 작업 목록을 비운다.
	ClearTasks();
	

	SmTickData arg1;
	// 끝내라는 명령
	arg1.command = 0;
	_FutTaskQueue.add(arg1);
	_FutAvailable = true;

	// 쓰레드가 끝날때까지 기다린다.
	if (_FutTaskThread.joinable())
		_FutTaskThread.join();

	arg1.command = 0;
	_AbroadTaskQueue.add(arg1);
	_AbroadAvailable = true;

	// 쓰레드가 끝날때까지 기다린다.
	if (_AbroadTaskThread.joinable())
		_AbroadTaskThread.join();
}

void SmSymbolManager::ProcessFutTask()
{
	while (true) {
		if (!_FutAvailable)
			continue;

		_FutAvailable = false;

		if (_BatchProcess) {
			std::array<SmTickData, TickArraySize> arr;

			size_t taken;

			auto status = _FutTaskQueue.take_bulk(arr.begin(), arr.size(), taken);
			if (status == BlockingCollectionStatus::Ok) {

				// 종료 명령이 아닐때는 데이터를 한꺼번에 처리한다.
				bool result = ExecuteQuoteTask(arr, taken);
				// 종료 명령일 때는 쓰레드를 종료 한다.
				if (!result)
					break;
			}
		}
		else {
			SmTickData data;
			auto status = _FutTaskQueue.take(data);
			// 상태가 좋으면 데이터를 처리한다.
			if (status == BlockingCollectionStatus::Ok) {
				// 종료 명령일 때는 쓰레드를 종료한다.
				if (data.command == 0)
					break;
				// 종료 명령이 아닐때는 데이터를 처리한다.
				ExecuteQuoteTask(std::move(data));
			}
		}

		_FutAvailable = true;
	}
}

void SmSymbolManager::ProcessAbroadTask()
{
	while (true) {
		if (!_AbroadAvailable)
			continue;

		_AbroadAvailable = false;

		if (_BatchProcess) {
			std::array<SmTickData, TickArraySize> arr;

			size_t taken;

			auto status = _AbroadTaskQueue.take_bulk(arr.begin(), arr.size(), taken);
			if (status == BlockingCollectionStatus::Ok) {

				// 종료 명령이 아닐때는 데이터를 한꺼번에 처리한다.
				bool result = ExecuteQuoteTask(arr, taken);
				// 종료 명령일 때는 쓰레드를 종료 한다.
				if (!result)
					break;
			}
		}
		else {
			SmTickData data;
			auto status = _AbroadTaskQueue.take(data);
			// 상태가 좋으면 데이터를 처리한다.
			if (status == BlockingCollectionStatus::Ok) {
				// 종료 명령일 때는 쓰레드를 종료한다.
				if (data.command == 0)
					break;
				// 종료 명령이 아닐때는 데이터를 처리한다.
				ExecuteQuoteTask(std::move(data));
			}
		}

		_AbroadAvailable = true;
	}
}

void SmSymbolManager::ExecuteQuoteTask(SmTickData&& item)
{
	// 데이터가 없을 때는 처리하지 않는다.
	if (item.symbol_code.length() == 0 || item.close == 0)
		return;
	// 차트데이터를 업데이트 한다.
	SmSymbol* symbol = FindSymbol(item.symbol_code);
	if (symbol) {
		//symbol->UpdateMinData(item);
		//symbol->UpdateTickData(item);
	}
	// 차트데이터를 데이터 베이스에 저장하고 네트워크에 전송한다.
	//SendChartData(item);
}

bool SmSymbolManager::ExecuteQuoteTask(std::array<SmTickData, TickArraySize>& arr, int taken)
{
	for (int i = 0; i < taken; ++i) {
		SmTickData data = arr[i];
		// 종료 명령이면 거짓을 반환한다.
		if (data.command == 0)
			return false;
		ExecuteQuoteTask(std::move(data));
	}
	return true;
}


void SmSymbolManager::StartTimer()
{
	std::vector<int> date_time = SmUtil::GetLocalDateTime();
	int cur_min = date_time[4];

	int cycle = 1;
	int waitTime = 0;
	int cycle_time = cycle * 60;
	int total_seconds = cur_min * 60 + date_time[5];
	int mod_seconds = total_seconds % (cycle * 60);
	int wait_seconds = cycle * 60 - mod_seconds;
	waitTime = wait_seconds;

	auto id = _Timer.add(seconds(waitTime), std::bind(&SmSymbolManager::OnTimer, this), seconds(cycle_time));
	// Add to the request map.
	_CycleDataReqTimerMap[cycle] = id;
}


void SmSymbolManager::OnTimer()
{
	for (auto it = _ChartSymbolVector.begin(); it != _ChartSymbolVector.end(); ++it) {
		std::vector<int> date_time = SmUtil::GetLocalDateTime();
		int cur_hour = date_time[3];
		int cur_min = date_time[4];
		SmSymbol* symbol = *it;
		

		int prev_hour = cur_hour;
		int prev_min = cur_min - 1;
		if (prev_min < 0) {
			prev_hour = prev_hour - 1;
			prev_min += 60;
		}

		std::string prev_index = SmUtil::Format("%02d%02d", prev_hour, prev_min);
		std::string cur_index = SmUtil::Format("%02d%02d", cur_hour, cur_min);
		// 과거봉의 차트 데이터를 만든다.
		symbol->MakePrevChartDataByTimer(cur_index);
		// 현재 봉의 차트 데이터를 만든다.
		symbol->MakeCurrChartDataByTimer(cur_index);
	}
}