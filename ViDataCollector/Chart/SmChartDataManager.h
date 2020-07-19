#pragma once
#include <string>
#include <map>
#include <memory>
#include "../Global/TemplateSingleton.h"
#include "SmChartDefine.h"
#include "../Task/BlockingCollection.h"
#include <thread>
#include <array>
//#include "../Timer/cpptime.h"
//#include "../Scheduler/Scheduler.h"
//#include "../Task/ThreadPool.h"
#include "../Quote/SmQuoteItem.h"
using namespace code_machina;

using namespace code_machina;
const int ChartArraySize = 100;

class SmChartData;
class SmSymbol;
class SmChartDataManager : public TemplateSingleton<SmChartDataManager>
{
public:
	SmChartDataManager();
	~SmChartDataManager();
	SmChartData* CreateChartData(SmChartDataRequest data_req);
	SmChartData* CreateChartData(std::string symbol_code, int chart_type, int cycle);
	void AddChartData(SmChartData* chart_data);
	SmChartData* FindChartData(std::string data_key);
	SmChartData* CreateChartData(SmChartDataItem data_item);
	std::map<std::string, SmChartData*> GetChartDataMap() {
		return _ChartDataMap;
	}

private:
	
	std::map<std::string, SmChartData*> _ChartDataMap;
	

};

