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
	/// �̸����� ���� ��ü�� �߰��Ѵ�.
	/// </summary>
	/// <param name="name"></param>
	/// <returns>������ ���� ��ü�� �����ش�.</returns>
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
	// �����ɼ� ���ĺ��� ����Ī ���̺�
	std::map<std::string, std::string> _CodeToMonth;
	bool IsInETFList(std::string etf_code);
	std::set<std::string> GetETFList() {
		return _ETFList;
	}
	// ETF ���̺��� �ʱ�ȭ �Ѵ�.
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
	// ������ �ؿ� ������ �ʱ�ȭ �Ѵ�.
	// ���񽺰� �ʿ��� ������ ���⼭ �߰��Ѵ�.
	void InitAbroadProducts();
	// �ڵ�� ���� �ʱ�ȭ �Ѵ�.
	void InitCodeToMonth();
	// ���� ����� �ʱ�ȭ �Ѵ�.
	void InitMarketTable();

	// ����� ��ǰ����� �ʱ�ȭ �Ѵ�.
	void InitDmMarketProducts();
	
	void SendSymbolMaster(std::string user_id, SmSymbol* sym);
	std::vector<SmMarket*> _MarketList;
	/// ǰ���� ���� ���� �̸� ���� ǥ
	/// <summary>
	/// �� ǰ�� ���Ͽ� �����̸��� ��Ī���� �ش�.
	/// Ű : ǰ�� �ڵ� 
	/// �� : ���� �̸�
	/// </summary>
	std::map<std::string, std::string> _CategoryToMarketMap;
	// ���� � ��� 
	std::set<std::string> _DomesticList;
	// �����ڵ�� ���� �̸� ��Ī ���̺�
	std::map<std::string, std::string> _MarketCodeToMarketNameTable;
	// EFT � ���
	std::set<std::string> _ETFList;
	std::vector<SmRunInfo> _FutureRunVector;
	std::vector<SmRunInfo> _OptionRunVector;
	std::vector<std::string> _MainFutureVector;
	std::map<std::string, SmProduct*> _ProductMap;
	std::set<std::string> _AbroadProductSet;
	std::vector<SmSymbol*> _FavoriteList;
};

