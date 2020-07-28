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
// 심볼 관리자는 심볼을 등록하고 관리한다.
// 타이머를 돌려 차트 데이터를 만들고 보낸다.
// 타이머가 만드는 차트 데이터는 이전 데이터 종가를 기반으로 한다.
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
	// 현재 차트 데이터 수집중인 심볼 목록
	std::vector<SmSymbol*> _ChartSymbolVector;

	void OnTimer();
	CppTime::Timer _Timer;
	std::map<int, CppTime::timer_id> _CycleDataReqTimerMap;
};

