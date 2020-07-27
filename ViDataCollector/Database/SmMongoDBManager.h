#pragma once
#include "../Global/TemplateSingleton.h"
//#include <mongocxx\config\config.hpp>
#include "../Hoga/SmHogaDefine.h"
#include "../Quote/SmQuoteDefine.h"
#include "../Chart/SmChartDefine.h"


// namespace mongocxx
// {
// 	MONGOCXX_INLINE_NAMESPACE_BEGIN
// 		class instance;
// 		class client;
// 		class pool;
// 		class find;
// 	MONGOCXX_INLINE_NAMESPACE_END
// };

class SmChartData;
class MongoDBInstance;
class SmMongoDBManager : public TemplateSingleton<SmMongoDBManager>
{
public:
	SmMongoDBManager();
	~SmMongoDBManager();
	void Test();
	void ReadSymbol();
	void SaveChartData(SmChartData* chart_data);
	void SaveHoga(SmHoga hoga);
	void SaveSise(SmQuote quote);
	void SaveChartDataItem(SmChartDataItem item);
	void LoadChartDataRequest();
	void DropCollection(std::string coll_name);
	void SaveMarketsToDatabase();
	void SaveSymbolsToDatabase();
	void DeleteChartData(SmChartDataRequest req);
private:
	void InitDatabase();
	
// 	mongocxx::instance* _Instance = nullptr;
// 	mongocxx::client* _Client = nullptr;
// 	mongocxx::pool* _ConnPool = nullptr;

	MongoDBInstance* _DBInstance = nullptr;
};
