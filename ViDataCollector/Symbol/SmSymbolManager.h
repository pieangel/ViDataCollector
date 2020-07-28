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
// �ɺ� �����ڴ� �ɺ��� ����ϰ� �����Ѵ�.
// Ÿ�̸Ӹ� ���� ��Ʈ �����͸� ����� ������.
// Ÿ�̸Ӱ� ����� ��Ʈ �����ʹ� ���� ������ ������ ������� �Ѵ�.
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


	bool Enable() const { return _Enable; }
	void Enable(bool val) { _Enable = val; }


	int KospiCurrent;
	int Kospi200Current;
	int Kosdaq150Current;

	void StartCollectData();

private:
	void StartTimer();

	std::map<std::string, SmSymbol*> _SymbolMap;

	bool _Enable = true;
	// ���� ��Ʈ ������ �������� �ɺ� ���
	std::vector<SmSymbol*> _ChartSymbolVector;

	void OnTimer();
	CppTime::Timer _Timer;
	std::map<int, CppTime::timer_id> _CycleDataReqTimerMap;
};

