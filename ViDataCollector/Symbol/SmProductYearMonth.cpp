#include "pch.h"
#include "SmProductYearMonth.h"
#include "SmSymbol.h"

SmProductYearMonth::SmProductYearMonth()
{
}


SmProductYearMonth::~SmProductYearMonth()
{
}

std::vector<SmSymbol*> SmProductYearMonth::SymbolList()
{
	std::vector<SmSymbol*> vector;
	for (auto it = _SymbolMap.begin(); it != _SymbolMap.end(); ++it) {
		vector.push_back(it->second);
	}

	return vector;
}

void SmProductYearMonth::AddSymbol(SmSymbol* symbol)
{
	if (!symbol)
		return;
	_SymbolMap[symbol->SymbolCode()] = symbol;
}

SmSymbol* SmProductYearMonth::GetFirstSymbol()
{
	if (_SymbolMap.size() == 0)
		return nullptr;
	return _SymbolMap.begin()->second;
}
