#include "pch.h"
#include "SmChartDataManager.h"
#include "SmChartData.h"
#include "../Symbol/SmMarketManager.h"
#include "../Symbol/SmSymbol.h"
#include "../Util/SmUtil.h"
#include "../Symbol/SmSymbolManager.h"
#include "../Json/json.hpp"

using namespace std::chrono;
using namespace nlohmann;

using namespace std::chrono;


SmChartDataManager::SmChartDataManager()
{
	
}

SmChartDataManager::~SmChartDataManager()
{
	for (auto it = _ChartDataMap.begin(); it != _ChartDataMap.end(); ++it) {
		delete it->second;
	}
}

void SmChartDataManager::AddChartData(SmChartData* chart_data)
{
	if (!chart_data)
		return;

	auto it = _ChartDataMap.find(chart_data->GetDataKey());
	if (it == _ChartDataMap.end()) {
		_ChartDataMap[chart_data->GetDataKey()] = chart_data;

		SmSymbol* symbol = SmSymbolManager::GetInstance()->FindSymbol(chart_data->SymbolCode());
		// 심볼에 차트 데이터를 추가해 준다. 
		// 종가 업데이트를 위해서 꼭 필요하다.
		if (symbol) {
			symbol->addChartData(chart_data->GetDataKey(), chart_data);
		}
	}
}

SmChartData* SmChartDataManager::CreateChartData(SmChartDataRequest data_req)
{
	SmChartData* chartData = FindChartData(data_req.GetDataKey());
	if (!chartData) {
		chartData = new SmChartData();
		chartData->SymbolCode(data_req.symbolCode);
		chartData->ChartType(data_req.chartType);
		chartData->Cycle(data_req.cycle);
		_ChartDataMap[data_req.GetDataKey()] = chartData;
		SmSymbol* symbol = SmSymbolManager::GetInstance()->FindSymbol(chartData->SymbolCode());
		// 심볼에 차트 데이터를 추가해 준다. 
		// 종가 업데이트를 위해서 꼭 필요하다.
		if (symbol) {
			symbol->addChartData(chartData->GetDataKey(), chartData);
		}
	}

	return chartData;
}

SmChartData* SmChartDataManager::CreateChartData(SmChartDataItem data_item)
{
	SmChartData* chartData = FindChartData(data_item.GetDataKey());
	if (!chartData) {
		chartData = new SmChartData();
		chartData->SymbolCode(data_item.symbolCode);
		chartData->ChartType(data_item.chartType);
		chartData->Cycle(data_item.cycle);
		_ChartDataMap[data_item.GetDataKey()] = chartData;
		SmSymbol* symbol = SmSymbolManager::GetInstance()->FindSymbol(chartData->SymbolCode());
		// 심볼에 차트 데이터를 추가해 준다. 
		// 종가 업데이트를 위해서 꼭 필요하다.
		if (symbol) {
			symbol->addChartData(chartData->GetDataKey(), chartData);
		}
	}

	return chartData;
}

SmChartData* SmChartDataManager::CreateChartData(std::string symbol_code, int chart_type, int cycle)
{
	std::string data_key = SmChartData::MakeDataKey(symbol_code, chart_type, cycle);
	SmChartData* chartData = FindChartData(data_key);
	if (!chartData) {
		chartData = new SmChartData();
		chartData->SymbolCode(symbol_code);
		chartData->ChartType((SmChartType)chart_type);
		chartData->Cycle(cycle);
		_ChartDataMap[data_key] = chartData;
		SmSymbol* symbol = SmSymbolManager::GetInstance()->FindSymbol(chartData->SymbolCode());
		// 심볼에 차트 데이터를 추가해 준다. 
		// 종가 업데이트를 위해서 꼭 필요하다.
		if (symbol) {
			symbol->addChartData(chartData->GetDataKey(), chartData);
		}
	}

	return chartData;
}

SmChartData* SmChartDataManager::FindChartData(std::string data_key)
{
	auto it = _ChartDataMap.find(data_key);
	if (it != _ChartDataMap.end()) {
		return it->second;
	}

	return nullptr;
}

