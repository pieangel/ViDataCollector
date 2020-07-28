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

void SmSymbolManager::StartCollectData()
{
	SmMarketManager* mrktMgr = SmMarketManager::GetInstance();
	std::vector<SmSymbol*> symbol_list = mrktMgr->GetRecentMonthSymbolList();

	for (auto it = symbol_list.begin(); it != symbol_list.end(); ++it) {
		SmSymbol* symbol = *it;
		//if (symbol->SymbolCode().compare("CLN20") == 0) {
		//HdClient::GetInstance()->RegisterProduct(symbol->SymbolCode().c_str());
		_ChartSymbolVector.push_back(symbol);
		//}
	}

	StartTimer();
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