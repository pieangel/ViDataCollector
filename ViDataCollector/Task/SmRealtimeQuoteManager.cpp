#include "pch.h"
#include "SmRealtimeQuoteManager.h"
#include "../Symbol/SmSymbolManager.h"
#include "../Symbol/SmSymbol.h"
#include "SmCallbackManager.h"
//#include "../Order/VtOrderManagerSelector.h"
//#include "../Order/VtOrderManager.h"
#include <array>
#include <set>
#include "../Chart/SmChartDataManager.h"
#include "../Log/loguru.hpp"

SmRealtimeQuoteManager::SmRealtimeQuoteManager()
{
	_BatchProcess = true;
	_Available = true;
	StartTaskThread();
}


SmRealtimeQuoteManager::~SmRealtimeQuoteManager()
{
	StopThread();
}

void SmRealtimeQuoteManager::StartTaskThread()
{
	//_TaskThread = std::thread(&SmRealtimeQuoteManager::ProcessTask, this);

	_FutTaskThread = std::thread(&SmRealtimeQuoteManager::ProcessFutTask, this);
	_OptTaskThread = std::thread(&SmRealtimeQuoteManager::ProcessOptTask, this);
	_ProTaskThread = std::thread(&SmRealtimeQuoteManager::ProcessProTask, this);
}

void SmRealtimeQuoteManager::ClearTasks()
{
	//_TaskQueue.flush();
	_FutTaskQueue.flush();
	_OptTaskQueue.flush();
	_ProTaskQueue.flush();
}

void SmRealtimeQuoteManager::AddTask(SmQuoteData&& item)
{
	// ��Ȱ��ȭ �Ǹ� �������� �ʴ´�.
	if (!_Enable)
		return;
	// �߰��ϰ� ��� ��ȯ�Ѵ�. Ȥ�� ť�� �̿��Ҽ� ���� ��Ȳ�̶� ��ȯ�Ѵ�.
	// �ݵ�� �߰��ϴ� ��쿡�� add() �Լ��� �̿��Ѵ�.
	_TaskQueue.try_add(item);
}

void SmRealtimeQuoteManager::StopThread()
{
	// ���� �۾� ����� ����.
	ClearTasks();
	SmQuoteData arg;
	// ������� ���
	arg.command = 0;
	_FutTaskQueue.add(arg);
	_FutAvailable = true;

	// �����尡 ���������� ��ٸ���.
	if (_FutTaskThread.joinable())
		_FutTaskThread.join();

	_OptTaskQueue.add(arg);
	_OptAvailable = true;

	// �����尡 ���������� ��ٸ���.
	if (_OptTaskThread.joinable())
		_OptTaskThread.join();

	_ProTaskQueue.add(arg);
	_ProAvailable = true;

	// �����尡 ���������� ��ٸ���.
	if (_ProTaskThread.joinable())
		_ProTaskThread.join();
}

void SmRealtimeQuoteManager::AddFutTask(SmQuoteData&& item)
{
	// ��Ȱ��ȭ �Ǹ� �������� �ʴ´�.
	if (!_Enable)
		return;
	// �߰��ϰ� ��� ��ȯ�Ѵ�. Ȥ�� ť�� �̿��Ҽ� ���� ��Ȳ�̶� ��ȯ�Ѵ�.
	// �ݵ�� �߰��ϴ� ��쿡�� add() �Լ��� �̿��Ѵ�.
	_FutTaskQueue.try_add(item);
}

void SmRealtimeQuoteManager::AddOptTask(SmQuoteData&& item)
{
	// ��Ȱ��ȭ �Ǹ� �������� �ʴ´�.
	if (!_Enable)
		return;
	// �߰��ϰ� ��� ��ȯ�Ѵ�. Ȥ�� ť�� �̿��Ҽ� ���� ��Ȳ�̶� ��ȯ�Ѵ�.
	// �ݵ�� �߰��ϴ� ��쿡�� add() �Լ��� �̿��Ѵ�.
	_OptTaskQueue.try_add(item);
}

void SmRealtimeQuoteManager::AddProTask(SmQuoteData&& item)
{
	// ��Ȱ��ȭ �Ǹ� �������� �ʴ´�.
	if (!_Enable)
		return;
	// �߰��ϰ� ��� ��ȯ�Ѵ�. Ȥ�� ť�� �̿��Ҽ� ���� ��Ȳ�̶� ��ȯ�Ѵ�.
	// �ݵ�� �߰��ϴ� ��쿡�� add() �Լ��� �̿��Ѵ�.
	_ProTaskQueue.try_add(item);
}

void SmRealtimeQuoteManager::ProcessTask()
{
	while (true) {
		if (!_Available)
			continue;

		_Available = false;
		
		if (_BatchProcess) {
			std::array<SmQuoteData, QuoteArraySize> arr;

			size_t taken;

			auto status = _TaskQueue.take_bulk(arr.begin(), arr.size(), taken);
			if (status == BlockingCollectionStatus::Ok) {

				// ���� ����� �ƴҶ��� �����͸� �Ѳ����� ó���Ѵ�.
				bool result = ExecuteTask(arr, taken);
				// ���� ����� ���� �����带 ���� �Ѵ�.
				if (!result)
					break;
			}
		}
		else {
			SmQuoteData data;
			auto status = _TaskQueue.take(data);
			// ���°� ������ �����͸� ó���Ѵ�.
			if (status == BlockingCollectionStatus::Ok) {
				// ���� ����� ���� �����带 �����Ѵ�.
				if (data.command == 0)
					break;
				// ���� ����� �ƴҶ��� �����͸� ó���Ѵ�.
				ExecuteTask(std::move(data));
			}
		}

		_Available = true;
	}
}

void SmRealtimeQuoteManager::ExecuteTask(SmQuoteData&& item)
{
	try {

	// ���� ����̸� ��ȯ�Ѵ�.
	if (item.command == 0)
		return;

	SmSymbolManager* symMgr = SmSymbolManager::GetInstance();
	SmSymbol* sym = symMgr->FindSymbol(item.symbol_code);
	if (!sym)
		return;

// 	if (item.up_down_rate.length() > 0)
// 		sym->UpdownRate = std::stoi(item.up_down_rate);
// 	else
// 		sym->UpdownRate = 0;
	sym->Quote.Close = std::stoi(item.close);
	sym->Quote.Open = std::stoi(item.open);
	sym->Quote.High = std::stoi(item.high);
	sym->Quote.Low = std::stoi(item.low);



	// ��Ʈ ������ ������Ʈ �Ѵ�.
	//sym->UpdateChartValue();

	SmChartDataManager* chartDataMgr = SmChartDataManager::GetInstance();
	// ��Ʈ�����͸� ������Ʈ �Ѵ�.
	//chartDataMgr->UpdateChartData(item.symbol_code, item.time, sym->Quote.intClose);

	
	SmQuoteData quoteItem;

// 	if (item.up_down.compare(_T("+")) == 0)
// 		quoteItem.MatchKind = 1;
// 	else
// 		quoteItem.MatchKind = 2;

	//quoteItem.ClosePrice = std::stoi(item.close);

	std::string quote_time = item.time;
	quote_time.insert(2, ":");
	quote_time.insert(5, ":");

// 	quoteItem.Time = quote_time;
// 
// 
// 	quoteItem.ContQty = std::stoi(item.volume);
// 
// 
// 	quoteItem.Decimal = sym->Decimal;
// 
// 	sym->Quote.QuoteItemQ.push_front(quoteItem);
	if (sym->Quote.QuoteItemQ.size() > 20) {
		sym->Quote.QuoteItemQ.pop_back();
	}

	// ����, ����, ��ž �ֹ��� üũ�Ѵ�.
	SmCallbackManager::GetInstance()->OnQuoteEvent(sym);

	

	// ���õ� �����쿡 �޽����� ������.
	SmCallbackManager::GetInstance()->OnWndQuoteEvent(sym);

	}
	catch (std::exception& e) {
		LOG_F(ERROR, _T(" %s, MSG : %s"), __FUNCTION__, e.what());
	}
	catch (...) {
		LOG_F(ERROR, _T(" %s �˼����� ����"), __FUNCTION__);
	}
}

bool SmRealtimeQuoteManager::ExecuteTask(std::array<SmQuoteData, QuoteArraySize>& arr, int taken)
{
	try {
		//LOG_F(INFO, _T("taken = %d"), taken);
	std::set<SmSymbol*> symbol_set;
	for (int i = 0; i < taken; ++i) {
		SmQuoteData item = arr.at(i);

		// ���� ����̸� ������ ��ȯ�Ѵ�.
		if (item.command == 0)
			return false;

		SmSymbolManager* symMgr = SmSymbolManager::GetInstance();
		SmSymbol* sym = symMgr->FindSymbol(item.symbol_code);
		if (!sym)
			continue;

		// ���տ� �ɺ��� �߰��Ѵ�.
		symbol_set.insert(sym);

// 		if (item.up_down_rate.length() > 0)
// 			sym->UpdownRate = std::stoi(item.up_down_rate);
// 		else
// 			sym->UpdownRate = 0;
// 		sym->Quote.intClose = std::stoi(item.close);
// 		sym->Quote.intOpen = std::stoi(item.open);
// 		sym->Quote.intHigh = std::stoi(item.high);
// 		sym->Quote.intLow = std::stoi(item.low);
// 
// 		sym->Quote.close = sym->Quote.intClose / std::pow(10, sym->Decimal);
// 		sym->Quote.open = sym->Quote.intOpen / std::pow(10, sym->Decimal);
// 		sym->Quote.high = sym->Quote.intHigh / std::pow(10, sym->Decimal);
// 		sym->Quote.low = sym->Quote.intLow / std::pow(10, sym->Decimal);
// 
// 		// ��Ʈ ������ ������Ʈ �Ѵ�.
// 		sym->UpdateChartValue();

		SmChartDataManager* chartDataMgr = SmChartDataManager::GetInstance();
		//chartDataMgr->UpdateChartData(item.symbol_code, item.time, sym->Quote.intClose);

		//OnReceiveSise(_ttoi(strTime), sym);

		SmQuoteData quoteItem;

// 		if (item.up_down.compare(_T("+")) == 0)
// 			quoteItem.MatchKind = 1;
// 		else
// 			quoteItem.MatchKind = 2;
// 
// 		quoteItem.ClosePrice = std::stoi(item.close);
// 
// 		std::string quote_time = item.time;
// 		quote_time.insert(2, ":");
// 		quote_time.insert(5, ":");
// 
// 		quoteItem.Time = quote_time;
// 
// 
// 		quoteItem.ContQty = std::stoi(item.volume);
// 
// 
// 		quoteItem.Decimal = sym->Decimal;
// 
// 		sym->Quote.QuoteItemQ.push_front(quoteItem);
// 		if (sym->Quote.QuoteItemQ.size() > 20) {
// 			sym->Quote.QuoteItemQ.pop_back();
// 		}
		// ����, ����, ��ž �ֹ��� üũ�Ѵ�.
		SmCallbackManager::GetInstance()->OnQuoteEvent(sym);
	}

	// â�� �Ѳ����� ������Ʈ �Ѵ�.
	for (auto it = symbol_set.begin(); it != symbol_set.end(); ++it) {
		SmSymbol* sym = *it;

		// ���õ� �����쿡 �޽����� ������.
		SmCallbackManager::GetInstance()->OnWndQuoteEvent(sym);

	}

	}
	catch (std::exception& e) {
		LOG_F(ERROR, _T(" %s, MSG : %s"), __FUNCTION__, e.what());
	}
	catch (...) {
		LOG_F(ERROR, _T(" %s �˼����� ����"), __FUNCTION__);
	}

	return true;
}

void SmRealtimeQuoteManager::ProcessFutTask()
{
	while (true) {
		if (!_FutAvailable)
			continue;

		_FutAvailable = false;

		if (_BatchProcess) {
			std::array<SmQuoteData, QuoteArraySize> arr;

			size_t taken;

			auto status = _FutTaskQueue.take_bulk(arr.begin(), arr.size(), taken);
			if (status == BlockingCollectionStatus::Ok) {

				// ���� ����� �ƴҶ��� �����͸� �Ѳ����� ó���Ѵ�.
				bool result = ExecuteTask(arr, taken);
				// ���� ����� ���� �����带 ���� �Ѵ�.
				if (!result)
					break;
			}
		}
		else {
			SmQuoteData data;
			auto status = _FutTaskQueue.take(data);
			// ���°� ������ �����͸� ó���Ѵ�.
			if (status == BlockingCollectionStatus::Ok) {
				// ���� ����� ���� �����带 �����Ѵ�.
				if (data.command == 0)
					break;
				// ���� ����� �ƴҶ��� �����͸� ó���Ѵ�.
				ExecuteTask(std::move(data));
			}
		}

		_FutAvailable = true;
	}
}

void SmRealtimeQuoteManager::ProcessOptTask()
{
	while (true) {
		if (!_OptAvailable)
			continue;

		_OptAvailable = false;

		if (_BatchProcess) {
			std::array<SmQuoteData, QuoteArraySize> arr;

			size_t taken;

			auto status = _OptTaskQueue.take_bulk(arr.begin(), arr.size(), taken);
			if (status == BlockingCollectionStatus::Ok) {

				// ���� ����� �ƴҶ��� �����͸� �Ѳ����� ó���Ѵ�.
				bool result = ExecuteTask(arr, taken);
				// ���� ����� ���� �����带 ���� �Ѵ�.
				if (!result)
					break;
			}
		}
		else {
			SmQuoteData data;
			auto status = _OptTaskQueue.take(data);
			// ���°� ������ �����͸� ó���Ѵ�.
			if (status == BlockingCollectionStatus::Ok) {
				// ���� ����� ���� �����带 �����Ѵ�.
				if (data.command == 0)
					break;
				// ���� ����� �ƴҶ��� �����͸� ó���Ѵ�.
				ExecuteTask(std::move(data));
			}
		}

		_OptAvailable = true;
	}
}

void SmRealtimeQuoteManager::ProcessProTask()
{
	while (true) {
		if (!_ProAvailable)
			continue;

		_ProAvailable = false;

		if (_BatchProcess) {
			std::array<SmQuoteData, QuoteArraySize> arr;

			size_t taken;

			auto status = _ProTaskQueue.take_bulk(arr.begin(), arr.size(), taken);
			if (status == BlockingCollectionStatus::Ok) {

				// ���� ����� �ƴҶ��� �����͸� �Ѳ����� ó���Ѵ�.
				bool result = ExecuteTask(arr, taken);
				// ���� ����� ���� �����带 ���� �Ѵ�.
				if (!result)
					break;
			}
		}
		else {
			SmQuoteData data;
			auto status = _ProTaskQueue.take(data);
			// ���°� ������ �����͸� ó���Ѵ�.
			if (status == BlockingCollectionStatus::Ok) {
				// ���� ����� ���� �����带 �����Ѵ�.
				if (data.command == 0)
					break;
				// ���� ����� �ƴҶ��� �����͸� ó���Ѵ�.
				ExecuteTask(std::move(data));
			}
		}

		_ProAvailable = true;
	}
}
