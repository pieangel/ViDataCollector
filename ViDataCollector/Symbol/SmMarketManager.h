#pragma once
#include "../Global/TemplateSingleton.h"
#include "SmRunInfo.h"
#include "../Task/HdTaskArg.h"
#include <string>
#include <map>
#include <vector>
#include <set>
#include "../EbCtrl/EbGlobal.h"
class SmMarket;
class SmProduct;
class SmSymbol;
class SmMarketManager : public TemplateSingleton<SmMarketManager>
{
public:
	SmMarketManager();
	~SmMarketManager();
	void ReadAbroadSymbolsFromFile();
	void ReadDomesticSymbolsFromFile();
	/// <summary>
	/// 이름으로 시장 객체를 추가한다.
	/// </summary>
	/// <param name="name"></param>
	/// <returns>생성된 시장 객체를 돌려준다.</returns>
	SmMarket* AddMarket(std::string name);
	SmProduct* FindProduct(std::string mrkt_name, std::string cat_code);
	SmMarket* FindMarket(std::string mrkt_name);
	void AddCategoryMarket(std::string cat_code, std::string mrkt_name);
	SmProduct* FindProduct(std::string cat_code);
	std::vector<SmSymbol*> GetRecentMonthSymbolList();
	SmSymbol* GetRecentSymbol(std::string market_name, std::string product_name);
	SmSymbol* GetRecentSymbol(std::string product_name);
	void SendMarketList(std::string user_id);
	void SendSymbolListByCategory(std::string user_id);
	int GetTotalCategoryCount();
	int GetTotalSymbolCount();
	std::vector<SmMarket*>& GetMarketList() {
		return _MarketList;
	}

	void requestRecentAllSise();
	bool IsInRunList(std::string product_code);
	std::string GetMarketName(std::string market_code);
	// 선물옵션 알파벳과 월매칭 테이블
	std::map<std::string, std::string> _CodeToMonth;
	bool IsInETFList(std::string etf_code);
	std::set<std::string> GetETFList() {
		return _ETFList;
	}
	// ETF 테이블을 초기화 한다.
	void InitETFTable();

	void LoadRunInfo();

	void AddFutureRunInfo(SmRunInfo run_info);
	void AddOptionRunInfo(SmRunInfo run_info);

	void GetSymbolCodeList(std::vector<std::pair<std::string, HdTaskArg>>& argVec);
	std::vector<SmTaskArg> MakeSymbolCodeRequests();
	std::vector<SmRunInfo> GetRunInfoList();
	std::vector<SmRunInfo> GetFutureRunVector() {
		return _FutureRunVector;
	}

	std::vector<SmRunInfo> GetOptionRunVector() {
		return _OptionRunVector;
	}

	SmProduct* FindProductFromMap(std::string product_code);
	void AddProduct(SmProduct* product);
	SmSymbol* GetDefaultSymbol();
	std::pair<SmProduct*, SmProduct*> GetProductPair(SmRunInfo run_info);
	std::set<std::string>& GetAbroadProductSet() {
		return _AbroadProductSet;
	}
	SmSymbol* GetDefaultAbroadSymbol();
	void MakeFavoriteList();
	std::vector<SmSymbol*>& GetFavoriteList() {
		return _FavoriteList;
	}
	std::vector<std::string>& GetMainDmFutures() {
		return _MainFutureVector;
	}
private:
	void InitDmFutures();
	// 서비스할 해외 종목을 초기화 한다.
	// 서비스가 필요한 종목은 여기서 추가한다.
	void InitAbroadProducts();
	// 코드와 월을 초기화 한다.
	void InitCodeToMonth();
	// 시장 목록을 초기화 한다.
	void InitMarketTable();

	// 시장과 제품목록을 초기화 한다.
	void InitDmMarketProducts();
	
	void SendSymbolMaster(std::string user_id, SmSymbol* sym);
	std::vector<SmMarket*> _MarketList;
	/// 품목이 속한 시장 이름 대응 표
	/// <summary>
	/// 각 품목에 대하여 시장이름을 매칭시켜 준다.
	/// 키 : 품목 코드 
	/// 값 : 시장 이름
	/// </summary>
	std::map<std::string, std::string> _CategoryToMarketMap;
	// 국내 운영 목록 
	std::set<std::string> _DomesticList;
	// 시장코드와 시장 이름 매칭 테이블
	std::map<std::string, std::string> _MarketCodeToMarketNameTable;
	// EFT 운영 목록
	std::set<std::string> _ETFList;
	std::vector<SmRunInfo> _FutureRunVector;
	std::vector<SmRunInfo> _OptionRunVector;
	std::vector<std::string> _MainFutureVector;
	std::map<std::string, SmProduct*> _ProductMap;
	std::set<std::string> _AbroadProductSet;
	std::vector<SmSymbol*> _FavoriteList;
};

