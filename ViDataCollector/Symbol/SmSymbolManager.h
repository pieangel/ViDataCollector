#pragma once
#include "../Global/TemplateSingleton.h"
#include <string>
#include <map>
#include "../Task/BlockingCollection.h"
#include <thread>
#include <array>
#include "../Quote/SmQuoteItem.h"
#include "../Time/cpptime.h"
#include "../Chart/SmChartDefine.h"

using namespace code_machina;
const int TickArraySize = 100;

class SmSymbol;
class SmSymbolManager : public TemplateSingleton<SmSymbolManager>
{
public:
	SmSymbolManager();
	~SmSymbolManager();
	SmSymbol* FindAddSymbol(std::string symbol_code);
	void AddSymbol(SmSymbol* sym);
	SmSymbol* FindSymbol(std::string symCode);
	std::map<std::string, SmSymbol*>& GetSymbolMap() {
		return _SymbolMap;
	}

	// 국내 선물 옵션 시세 큐에 등록
	void AddFutTask(SmTickData&& item);
	// 해외 선물 시세 큐에 등록
	void AddAbroadTask(SmTickData&& item);

	void StartCollectData();
	void ClearTasks();
	void StopThread();
	bool Enable() const { return _Enable; }
	void Enable(bool val) { _Enable = val; }

	void StartTimer();

	int KospiCurrent;
	int Kospi200Current;
	int Kosdaq150Current;

private:
	
	void StartTaskThread();
	std::map<std::string, SmSymbol*> _SymbolMap;

	bool _Enable = true;
	bool _BatchProcess = false;
	bool _ThreadStarted = false;


	// 국내 선물 시세 처리 쓰레드
	std::thread _FutTaskThread;
	// 해외 선물 시세 처리 쓰레드
	std::thread _AbroadTaskThread;


	// 국내 선물 시세 큐
	BlockingCollection<SmTickData> _FutTaskQueue;
	// 해외 선물 시세 큐
	BlockingCollection<SmTickData> _AbroadTaskQueue;

	bool _FutAvailable = true;
	bool _AbroadAvailable = true;
	// 국내선물 시세 처리 쓰레드 함수
	void ProcessFutTask();
	// 해외 선물 시세 처리 쓰레드 함수
	void ProcessAbroadTask();

	// 시세 업무 처리
	void ExecuteQuoteTask(SmTickData&& item);
	// 시세 업무 배치 처리
	// arr : 데이터가 들어 있는 배열, taken : 실제 데이터가 들어 있는 갯수
	bool ExecuteQuoteTask(std::array<SmTickData, TickArraySize>& arr, int taken);

	// 현재 차트 데이터 수집중인 심볼 목록
	std::vector<SmSymbol*> _ChartSymbolVector;

	void OnTimer();
	CppTime::Timer _Timer;
	std::map<int, CppTime::timer_id> _CycleDataReqTimerMap;
};

