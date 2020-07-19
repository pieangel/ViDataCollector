#pragma once
#include <string>
#include <vector>
#include <map>
class SmSymbol;
class SmProductYearMonth
{
public:
	SmProductYearMonth();
	~SmProductYearMonth();
	std::string ProductCode;
	std::string YearMonthCode;
	std::vector<SmSymbol*> SymbolList();
	void AddSymbol(SmSymbol* symbol);
	SmSymbol* GetFirstSymbol();
private:
	std::map<std::string, SmSymbol*> _SymbolMap;
};

