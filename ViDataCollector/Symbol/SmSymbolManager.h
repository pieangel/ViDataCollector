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

	// ���� ���� �ɼ� �ü� ť�� ���
	void AddFutTask(SmTickData&& item);
	// �ؿ� ���� �ü� ť�� ���
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


	// ���� ���� �ü� ó�� ������
	std::thread _FutTaskThread;
	// �ؿ� ���� �ü� ó�� ������
	std::thread _AbroadTaskThread;


	// ���� ���� �ü� ť
	BlockingCollection<SmTickData> _FutTaskQueue;
	// �ؿ� ���� �ü� ť
	BlockingCollection<SmTickData> _AbroadTaskQueue;

	bool _FutAvailable = true;
	bool _AbroadAvailable = true;
	// �������� �ü� ó�� ������ �Լ�
	void ProcessFutTask();
	// �ؿ� ���� �ü� ó�� ������ �Լ�
	void ProcessAbroadTask();

	// �ü� ���� ó��
	void ExecuteQuoteTask(SmTickData&& item);
	// �ü� ���� ��ġ ó��
	// arr : �����Ͱ� ��� �ִ� �迭, taken : ���� �����Ͱ� ��� �ִ� ����
	bool ExecuteQuoteTask(std::array<SmTickData, TickArraySize>& arr, int taken);

	// ���� ��Ʈ ������ �������� �ɺ� ���
	std::vector<SmSymbol*> _ChartSymbolVector;

	void OnTimer();
	CppTime::Timer _Timer;
	std::map<int, CppTime::timer_id> _CycleDataReqTimerMap;
};

