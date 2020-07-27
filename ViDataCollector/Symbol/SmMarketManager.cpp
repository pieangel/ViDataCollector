#include "pch.h"
#include "SmMarketManager.h"
#include "../Config/ZmConfigManager.h"
#include <string>
#include "../Xml/pugixml.hpp"
#include "SmSymbolReader.h"
#include "SmMarket.h"
#include "SmProduct.h"
#include "../Util/VtStringUtil.h"
#include "../Json/json.hpp"
#include "../Log/loguru.hpp"
#include "../Util/SmUtil.h"
#include <chrono>
//#include "../Network/SmServiceDefine.h"
//#include "SmUserManager.h"
//#include "SmUser.h"
#include "SmSymbol.h"
#include "SmProduct.h"
//#include "../Task/HdScheduler.h"

#include "SmProductYearMonth.h"
#include "../Task/ViServerDataReceiver.h"
#include "SmSymbolManager.h"
#include "../HdCtrl/HdClient.h"

using namespace std::chrono;
using namespace nlohmann;


SmMarketManager::SmMarketManager()
{
	ZmConfigManager* configMgr = ZmConfigManager::GetInstance();
	std::string appPath = configMgr->GetAppPath();
	std::string configPath = appPath;
	configPath.append(_T("\\Config.xml"));
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(configPath.c_str());
	pugi::xml_node app = doc.first_child();
	pugi::xml_node domestic_list_node = doc.child("application").child("domestic_list");
	pugi::xml_node domestic_node = domestic_list_node.first_child();
	while (domestic_node) {
		std::string code = domestic_node.text().as_string();
		_DomesticList.insert(code);
		domestic_node = domestic_node.next_sibling();
	}

	InitETFTable();
	InitDmMarketProducts();
	InitDmFutures();
	InitCodeToMonth();
	InitAbroadProducts();
}


SmMarketManager::~SmMarketManager()
{
	for (auto it = _MarketList.begin(); it != _MarketList.end(); ++it) {
		delete* it;
	}
}

std::pair<SmProduct*, SmProduct*> SmMarketManager::GetProductPair(SmRunInfo run_info)
{
	SmProduct* call_product = FindProduct(run_info.CallCode);
	SmProduct* put_product = FindProduct(run_info.PutCode);
	return std::make_pair(call_product, put_product);
}

SmSymbol* SmMarketManager::GetDefaultAbroadSymbol()
{
	SmProduct* product = FindProduct("CL");
	if (!product)
		return nullptr;
	return product->GetRecentMonthSymbol();
}

void SmMarketManager::MakeFavoriteList()
{
	SmSymbolManager* symMgr = SmSymbolManager::GetInstance();
	//_AbroadProductSet.insert("NQ");
	for (auto it = _AbroadProductSet.begin(); it != _AbroadProductSet.end(); it++) {
		std::string product_code = *it;
		SmProduct* product = FindProduct(product_code);
		if (product) {
			_FavoriteList.push_back(product->GetRecentMonthSymbol());
			_FavoriteList.push_back(product->GetNextMonthSymbol());
		}
	}

	// �ǽð� ����� ���ش�.
	for (auto it = _FavoriteList.begin(); it != _FavoriteList.end(); ++it) {
		SmSymbol* symbol = *it;
		if (symbol)
			HdClient::GetInstance()->RegisterProduct(symbol->SymbolCode().c_str());
	}
}

SmSymbol* SmMarketManager::GetDefaultSymbol()
{
	SmProduct* product = FindProduct("101");
	if (!product)
		return nullptr;
	return product->GetRecentMonthSymbol();
}

void SmMarketManager::AddProduct(SmProduct* product)
{
	if (!product)
		return;
	_ProductMap[product->Code()] = product;
}


SmProduct* SmMarketManager::FindProductFromMap(std::string product_code)
{
	auto it = _ProductMap.find(product_code);
	if (it != _ProductMap.end()) {
		return it->second;
	}
	return nullptr;
}

void SmMarketManager::ReadAbroadSymbolsFromFile()
{
	SmSymbolReader* symReader = SmSymbolReader::GetInstance();
	ZmConfigManager* configMgr = ZmConfigManager::GetInstance();
	std::string appPath = configMgr->GetAppPath();
	std::string configPath = appPath;
	configPath.append(_T("\\Config\\Config.xml"));
	std::string dataPath = appPath;
	dataPath.append(_T("\\mst\\"));
	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file(configPath.c_str());
	pugi::xml_node app = doc.first_child();
	pugi::xml_node sym_file_list = app.first_child();
	pugi::xml_node abroad_list = sym_file_list.first_child();
	int index = 9;
	for (auto it = abroad_list.begin(); it != abroad_list.end(); ++it) {
		std::string file_name = it->text().as_string();
		//TRACE(file_name.c_str());
		std::string file_path = dataPath + file_name;
		symReader->ReadSymbolFromFile(index++, file_path);
	}
}

void SmMarketManager::ReadDomesticSymbolsFromFile()
{
	SmSymbolReader* symReader = SmSymbolReader::GetInstance();
	ZmConfigManager* configMgr = ZmConfigManager::GetInstance();
	std::string appPath = configMgr->GetAppPath();
	std::string configPath = appPath;
	configPath.append(_T("\\Config\\Config.xml"));
	std::string dataPath = appPath;
	dataPath.append(_T("\\mst\\"));
	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file(configPath.c_str());
	pugi::xml_node app = doc.first_child();
	pugi::xml_node sym_file_list = app.first_child();
	pugi::xml_node abroad_list = sym_file_list.first_child().next_sibling();
	int index = 0;
	for (auto it = abroad_list.begin(); it != abroad_list.end(); ++it) {
		std::string file_name = it->text().as_string();
		//TRACE(file_name.c_str());
		std::string file_path = dataPath + file_name;
		symReader->ReadSymbolFromFile(index++, file_path);
	}

	
}

SmMarket* SmMarketManager::AddMarket(std::string name)
{
	SmMarket* found_market = FindMarket(name);
	if (found_market)
		return found_market;

	SmMarket* market = new SmMarket();
	market->Name(name);
	_MarketList.emplace_back(market);
	return market;
}

SmProduct* SmMarketManager::FindProduct(std::string mrkt_name, std::string cat_code)
{
	SmMarket* cur_market = FindMarket(mrkt_name);
	if (!cur_market)
		return nullptr;
	return cur_market->FindProduct(cat_code);
}

SmProduct* SmMarketManager::FindProduct(std::string cat_code)
{
	auto it = _CategoryToMarketMap.find(cat_code);
	if (it != _CategoryToMarketMap.end()) {
		std::string market_name = it->second;
		SmMarket* mrkt = FindMarket(market_name);
		if (mrkt)
			return mrkt->FindProduct(cat_code);
		else
			return nullptr;
	}

	return nullptr;
}

std::vector<SmSymbol*> SmMarketManager::GetRecentMonthSymbolList()
{
	std::vector<SmSymbol*> symvec;
	for (auto it = _MarketList.begin(); it != _MarketList.end(); ++it) {
		SmMarket* mrkt = *it;
		auto cat_vec = mrkt->GetProductList();
		
		for (auto itc = cat_vec.begin(); itc != cat_vec.end(); ++itc) {
			if (mrkt->Name().compare("ETF") != 0) {
				if (!IsInRunList((*itc)->Code())) {
					continue;
				}
				SmProductYearMonth* ym = (*itc)->GetRecentYearMonth();
				if (ym) {
					std::vector<SmSymbol*> symbol_list = ym->SymbolList();
					for (auto itym = symbol_list.begin(); itym != symbol_list.end(); ++itym) {
						(*itym)->Quote.SymbolCode = (*itym)->SymbolCode();
						symvec.push_back(*itym);
					}
				}
			}
			else {
				std::vector<SmSymbol*> symbol_list = (*itc)->GetSymbolList();
				for (auto it = symbol_list.begin(); it != symbol_list.end(); ++it) {
					symvec.push_back(*it);
				}
			}
		}
	}

	return symvec;
}

SmSymbol* SmMarketManager::GetRecentSymbol(std::string market_name, std::string product_name)
{
	SmMarket* market = FindMarket(market_name);
	if (!market)
		return nullptr;
	SmProduct* product = market->FindProduct(product_name);
	if (!product)
		return nullptr;
	SmProductYearMonth* ym = product->GetRecentYearMonth();
	if (ym->SymbolList().size() == 0)
		return nullptr;
	return *ym->SymbolList().begin();
}

SmSymbol* SmMarketManager::GetRecentSymbol(std::string product_name)
{
	auto it = _CategoryToMarketMap.find(product_name);
	if (it == _CategoryToMarketMap.end())
		return nullptr;
	std::string market_name = it->second;

	return GetRecentSymbol(market_name, product_name);
}

void SmMarketManager::SendMarketList(std::string user_id)
{
	for (size_t i = 0; i < _MarketList.size(); ++i) {
		SmMarket* market = _MarketList[i];
		json send_object;
// 		send_object["res_id"] = SmProtocol::res_market_list;
// 		send_object["total_market_count"] = (int)_MarketList.size();
// 		send_object["total_category_count"] = GetTotalCategoryCount();
// 		send_object["market_index"] = (int)i;
// 		send_object["market_name"] = SmUtfUtil::AnsiToUtf8((char*)market->Name().c_str());
// 		std::vector<SmProduct*>&  catVec = market->GetProductList();
// 		for (size_t j = 0; j < catVec.size(); ++j) {
// 			SmProduct* cat = catVec[j];
// 			send_object["category"][j] = {
// 				{ "code",  cat->Code() },
// 				{ "name_kr", SmUtfUtil::AnsiToUtf8((char*)cat->NameKr().c_str()) },
// 				{ "name_en",  cat->Name() },
// 				{ "exchange_name",  cat->Exchange() },
// 				{ "exchange_code",  cat->ExchangeCode() },
// 				{ "market_name",  SmUtfUtil::AnsiToUtf8((char*)cat->MarketName().c_str()) }
// 			};
// 		}

		
		std::string content = send_object.dump();
		//SmUserManager* userMgr = SmUserManager::GetInstance();
		//userMgr->SendResultMessage(user_id, content);
	}
	
}

void SmMarketManager::SendSymbolListByCategory(std::string user_id)
{
	for (size_t i = 0; i < _MarketList.size(); ++i) {
		SmMarket* market = _MarketList[i];
		std::vector<SmProduct*>& cat_list = market->GetProductList();
		for (size_t j = 0; j < cat_list.size(); ++j) {
			SmProduct* cat = cat_list[j];
			std::vector<SmSymbol*>& sym_list = cat->GetSymbolList();
			for (size_t k = 0; k < sym_list.size(); ++k) {
				SendSymbolMaster(user_id, sym_list[k]);
			}
		}
	}
}

int SmMarketManager::GetTotalCategoryCount()
{
	int total = 0;
	for (size_t i = 0; i < _MarketList.size(); ++i) {
		SmMarket* market = _MarketList[i];
		total += market->GetProductList().size();
	}

	return total;
}

int SmMarketManager::GetTotalSymbolCount()
{
	int total = 0;
	for (size_t i = 0; i < _MarketList.size(); ++i) {
		SmMarket* market = _MarketList[i];
		std::vector<SmProduct*>& cat_list = market->GetProductList();
		for (size_t j = 0; j < cat_list.size(); ++j) {
			total += cat_list[j]->GetSymbolList().size();
		}
	}

	return total;
}

void SmMarketManager::requestRecentAllSise()
{
	std::vector<SmSymbol*> symVec = GetRecentMonthSymbolList();
	for (auto it = symVec.begin(); it != symVec.end(); ++it) {
		SmSymbol* sym = *it;
		//SmHdClient::GetInstance()->GetSiseData(sym->SymbolCode());
	}
}

bool SmMarketManager::IsInRunList(std::string product_code)
{
	if (product_code.length() > 2 && std::isdigit(product_code.at(2))) {
		auto it = _DomesticList.find(product_code);
		if (it == _DomesticList.end())
			return false;
		else
			return true;
	}
	else {
		return true;
	}
}

std::string SmMarketManager::GetMarketName(std::string market_code)
{
	auto it = _MarketCodeToMarketNameTable.find(market_code);
	if (it != _MarketCodeToMarketNameTable.end()) {
		return it->second;
	}

	return "���Ͼ���";
}

bool SmMarketManager::IsInETFList(std::string etf_code)
{
	auto it = _ETFList.find(etf_code);
	if (it != _ETFList.end())
		return true;
	return false;
}

void SmMarketManager::InitDmFutures()
{
	_MainFutureVector.push_back("101F");
	_MainFutureVector.push_back("105F");
	_MainFutureVector.push_back("106F");
	_MainFutureVector.push_back("167F");
	_MainFutureVector.push_back("175F");
}

void SmMarketManager::InitAbroadProducts()
{
 	_AbroadProductSet.insert("6A");
	_AbroadProductSet.insert("6B");
	_AbroadProductSet.insert("6E");
	_AbroadProductSet.insert("6J");
	_AbroadProductSet.insert("E7");
	_AbroadProductSet.insert("J7");
 	_AbroadProductSet.insert("M6A");
	_AbroadProductSet.insert("M6B");
	_AbroadProductSet.insert("M6E");
	_AbroadProductSet.insert("ES");
	_AbroadProductSet.insert("NIY");
	_AbroadProductSet.insert("NKD");
 	_AbroadProductSet.insert("NQ");
	_AbroadProductSet.insert("OES");
	_AbroadProductSet.insert("ONQ");
	_AbroadProductSet.insert("SP");
	_AbroadProductSet.insert("GE");
	_AbroadProductSet.insert("CL"); // ũ��� ����
	_AbroadProductSet.insert("HO"); // ������
	_AbroadProductSet.insert("NG"); // õ������
	_AbroadProductSet.insert("QG"); // �̴�õ������
	_AbroadProductSet.insert("QM"); // �̴�ũ��� ����
	_AbroadProductSet.insert("RB"); // ���ָ�
 	_AbroadProductSet.insert("GC");
 	_AbroadProductSet.insert("MGC");
 	_AbroadProductSet.insert("OGC");
 	_AbroadProductSet.insert("OSI");
 	_AbroadProductSet.insert("QO");
 	_AbroadProductSet.insert("SI");
 	_AbroadProductSet.insert("YM");
	_AbroadProductSet.insert("ZF");
	_AbroadProductSet.insert("ZN");
	_AbroadProductSet.insert("ZQ");
	_AbroadProductSet.insert("OZC");
	_AbroadProductSet.insert("OZS");
	_AbroadProductSet.insert("OZW");
	_AbroadProductSet.insert("ZC");
	_AbroadProductSet.insert("ZL");
	_AbroadProductSet.insert("ZM");
	_AbroadProductSet.insert("ZS");
	_AbroadProductSet.insert("ZW");
 	_AbroadProductSet.insert("CN");
	_AbroadProductSet.insert("NK");
	_AbroadProductSet.insert("TW");
//	_AbroadProductSet.insert("BRN");
	_AbroadProductSet.insert("HSI"); // �׻�
 	_AbroadProductSet.insert("VX");
 	_AbroadProductSet.insert("GF");
 	_AbroadProductSet.insert("HF");
 	_AbroadProductSet.insert("HG");
 	_AbroadProductSet.insert("LE");
}

void SmMarketManager::InitCodeToMonth()
{
	_CodeToMonth["F"] = "01";
	_CodeToMonth["G"] = "02";
	_CodeToMonth["H"] = "03";
	_CodeToMonth["J"] = "04";
	_CodeToMonth["K"] = "05";
	_CodeToMonth["M"] = "06";
	_CodeToMonth["N"] = "07";
	_CodeToMonth["Q"] = "08";
	_CodeToMonth["U"] = "09";
	_CodeToMonth["V"] = "10";
	_CodeToMonth["X"] = "11";
	_CodeToMonth["Z"] = "12";
}

// ���� ���� ����� �ʱ�ȭ �Ѵ�.
void SmMarketManager::InitMarketTable()
{
	SmMarket* market = nullptr;


	market = new SmMarket();
	market->Name("ETF");
	market->MarketCode("009");
	_MarketList.push_back(market);
	_MarketCodeToMarketNameTable["009"] = "ETF";

	market = new SmMarket();
	market->Name("��������");
	market->MarketCode("008");
	_MarketList.push_back(market);
	_MarketCodeToMarketNameTable["008"] = "��������";

	market = new SmMarket();
	market->Name("����");
	market->MarketCode("001");
	_MarketList.push_back(market);
	_MarketCodeToMarketNameTable["001"] = "����";

	market = new SmMarket();
	market->Name("��ȭ");
	market->MarketCode("002");
	_MarketList.push_back(market);
	_MarketCodeToMarketNameTable["002"] = "��ȭ";

	market = new SmMarket();
	market->Name("�ݸ�");
	market->MarketCode("003");
	_MarketList.push_back(market);
	_MarketCodeToMarketNameTable["003"] = "�ݸ�";

	market = new SmMarket();
	market->Name("�����");
	market->MarketCode("004");
	_MarketList.push_back(market);
	_MarketCodeToMarketNameTable["004"] = "�����";

	market = new SmMarket();
	market->Name("�ͱݼ�");
	market->MarketCode("005");
	_MarketList.push_back(market);
	_MarketCodeToMarketNameTable["005"] = "�ͱݼ�";

	market = new SmMarket();
	market->Name("������");
	market->MarketCode("006");
	_MarketList.push_back(market);
	_MarketCodeToMarketNameTable["006"] = "������";

	market = new SmMarket();
	market->Name("��ö�ݼ�");
	market->MarketCode("007");
	_MarketList.push_back(market);
	_MarketCodeToMarketNameTable["007"] = "��ö�ݼ�";
}

void SmMarketManager::InitDmMarketProducts()
{
	std::string market_name = "��������";
	SmMarket* market = AddMarket(market_name);
	market->MarketCode("101F");
	std::string product_code = "101";
	SmProduct* product = market->FindAddProduct(product_code);
	AddProduct(product);
	AddCategoryMarket(product_code, market_name);
	product->MarketName(market_name);
	product->NameKr("��������");
	product->Name("��������");

	product_code = "105";
	product = market->FindAddProduct(product_code);
	AddProduct(product);
	AddCategoryMarket(product_code, market_name);
	product->MarketName(market_name);
	product->NameKr("�ڽ���200�̴ϼ���");
	product->NameKr("Kospi200MiniF");

	product_code = "106";
	product = market->FindAddProduct(product_code);
	AddProduct(product);
	AddCategoryMarket(product_code, market_name);
	product->MarketName(market_name);
	product->NameKr("�ڽ���150����");
	product->NameKr("Kosdaqq150F");

	product_code = "167";
	product = market->FindAddProduct(product_code);
	AddProduct(product);
	AddCategoryMarket(product_code, market_name);
	product->MarketName(market_name);
	product->NameKr("BMA ����");
	product->Name("BMA Future");

	product_code = "175";
	product = market->FindAddProduct(product_code);
	AddProduct(product);
	AddCategoryMarket(product_code, market_name);
	product->MarketName(market_name);
	product->NameKr("USD ����");
	product->Name("USD Future");

	/*
	std::string market_name = "�ڽ��Ǽ���";
	SmMarket* market = AddMarket(market_name);
	market->MarketCode("101F");
	std::string product_code = "101";
	SmProduct* product = market->FindAddProduct(product_code);
	AddProduct(product);
	AddCategoryMarket(product_code, market_name);
	product->MarketName(market_name);
	product->NameKr("�ڽ���200����");
	product->Name("Kospi200F");

	market_name = "�̴��ڽ��Ǽ���";
	market = AddMarket(market_name);
	market->MarketCode("105F");

	product_code = "105";
	product = market->FindAddProduct(product_code);
	AddProduct(product);
	AddCategoryMarket(product_code, market_name);
	product->MarketName(market_name);
	product->NameKr("�ڽ���200�̴ϼ���");
	product->NameKr("Kospi200MiniF");

	
	market_name = "�ڽ��ڼ���";
	market = AddMarket(market_name);
	market->MarketCode("106F");

	product_code = "106";
	product = market->FindAddProduct(product_code);
	AddProduct(product);
	AddCategoryMarket(product_code, market_name);
	product->MarketName(market_name);
	product->NameKr("�ڽ���150����");
	product->NameKr("Kosdaqq150F");

	market_name = "��ä����";
	market = AddMarket(market_name);
	market->MarketCode("167F");

	product_code = "167";
	product = market->FindAddProduct(product_code);
	AddProduct(product);
	AddCategoryMarket(product_code, market_name);
	product->MarketName(market_name);
	product->NameKr("BMA ����");
	product->Name("BMA Future");


	market_name = "�޷�����";
	market = AddMarket(market_name);
	market->MarketCode("175F");
	product_code = "175";
	product = market->FindAddProduct(product_code);
	AddProduct(product);
	AddCategoryMarket(product_code, market_name);
	product->MarketName(market_name);
	product->NameKr("USD ����");
	product->Name("USD Future");


	market_name = "�ڽ��ǿɼ�";
	market = AddMarket(market_name);
	market->MarketCode("101O");
	product_code = "201";
	product = market->FindAddProduct(product_code);
	AddProduct(product);
	AddCategoryMarket(product_code, market_name);
	product->MarketName(market_name);
	product->NameKr("�ڽ���200�ݿɼ�");
	product->Name("Kospi200O");

	product_code = "301";
	product = market->FindAddProduct(product_code);
	AddProduct(product);
	AddCategoryMarket(product_code, market_name);
	product->MarketName(market_name);
	product->NameKr("�ڽ���200ǲ�ɼ�");
	product->Name("Kospi200O");

	market_name = "�ڽ�����Ŭ���ɼ�";
	market = AddMarket(market_name);
	market->MarketCode("109O");

	product_code = "209";
	product = market->FindAddProduct(product_code);
	AddProduct(product);
	AddCategoryMarket(product_code, market_name);
	product->MarketName(market_name);
	product->NameKr("�ڽ���200��Ŭ���ݿɼ�");
	product->Name("Kospi200WeeklyO");

	product_code = "309";
	product = market->FindAddProduct(product_code);
	AddProduct(product);
	AddCategoryMarket(product_code, market_name);
	product->MarketName(market_name);
	product->NameKr("�ڽ���200��Ŭ��ǲ�ɼ�");
	product->Name("Kospi200WeeklyO");

	market_name = "�ڽ��ǹ̴Ͽɼ�";
	market = AddMarket(market_name);
	market->MarketCode("105O");

	product_code = "205";
	product = market->FindAddProduct(product_code);
	AddProduct(product);
	AddCategoryMarket(product_code, market_name);
	product->MarketName(market_name);
	product->NameKr("�̴��ڽ���200�ݿɼ�");
	product->NameKr("MiniKospi200O");

	product_code = "305";
	product = market->FindAddProduct(product_code);
	AddProduct(product);
	AddCategoryMarket(product_code, market_name);
	product->MarketName(market_name);
	product->NameKr("�̴��ڽ���200ǲ�ɼ�");
	product->NameKr("MiniKospi200O");

	market_name = "�ڽ��ڿɼ�";
	market = AddMarket(market_name);
	market->MarketCode("106O");

	product_code = "206";
	product = market->FindAddProduct(product_code);
	AddProduct(product);
	AddCategoryMarket(product_code, market_name);
	product->MarketName(market_name);
	product->Name("�ڽ���150�ݿɼ�");
	product->NameKr("Kosqaq150O");

	product_code = "306";
	product = market->FindAddProduct(product_code);
	AddProduct(product);
	AddCategoryMarket(product_code, market_name);
	product->MarketName(market_name);
	product->Name("�ڽ���150ǲ�ɼ�");
	product->NameKr("Kosqaq150O");
	*/
}

void SmMarketManager::InitETFTable()
{
	_ETFList.insert("102110");
	_ETFList.insert("267770");
	_ETFList.insert("252710");
	_ETFList.insert("123320");
	_ETFList.insert("123310");
	_ETFList.insert("232080");
	_ETFList.insert("250780");
	_ETFList.insert("233160");
	_ETFList.insert("261070");
	_ETFList.insert("143850");
	_ETFList.insert("225040");
	_ETFList.insert("225030");
	_ETFList.insert("133690");
	_ETFList.insert("245340");
	_ETFList.insert("192090");
	_ETFList.insert("204480");
	_ETFList.insert("217780");
	_ETFList.insert("241180");
	_ETFList.insert("302190");
	_ETFList.insert("319640");

	_ETFList.insert("130680");
	_ETFList.insert("217770");
	_ETFList.insert("261110");
	_ETFList.insert("261120");
	_ETFList.insert("292560");
	_ETFList.insert("292590");
}


void SmMarketManager::AddFutureRunInfo(SmRunInfo run_info)
{
	_FutureRunVector.push_back(run_info);
}

void SmMarketManager::AddOptionRunInfo(SmRunInfo run_info)
{
	_OptionRunVector.push_back(run_info);
}

void SmMarketManager::GetSymbolCodeList(std::vector<std::pair<std::string, HdTaskArg>>& argVec)
{
	for (auto it = _FutureRunVector.begin(); it != _FutureRunVector.end(); ++it) {
		SmRunInfo& info = *it;
		HdTaskArg arg;
		arg.Type = HdTaskType::HdSymbolCode;
		arg.AddArg("product_code", info.Code);
		argVec.push_back(std::make_pair(info.Name, arg));
	}

	for (auto it = _OptionRunVector.begin(); it != _OptionRunVector.end(); ++it) {
		SmRunInfo& info = *it;
		HdTaskArg arg;
		arg.Type = HdTaskType::HdSymbolCode;
		arg.AddArg("product_code", info.Code);
		argVec.push_back(std::make_pair(info.Name, arg));
	}

// 	HdScheduler* scheduler = HdScheduler::GetInstance();
// 	int i = 0;
// 	for (auto it = argVec.begin(); it != argVec.end(); ++it) {
// 		scheduler->AddRequest(HdTaskType::HdSymbolCode, i++);
// 	}
}

std::vector<SmTaskArg> SmMarketManager::MakeSymbolCodeRequests()
{
	std::vector<SmTaskArg> arg_list;
// 	for (auto it = _FutureRunVector.begin(); it != _FutureRunVector.end(); ++it) {
// 		SmRunInfo& info = *it;
// 		SmTaskArg arg;
// 		arg.Desc = "�ɺ��ڵ带 �������� ���Դϴ�.";
// 		arg.Detail = info.Name;
// 		arg.ArgId = SmServerDataReceiver::GetId();
// 		arg.TaskType = SmTaskType::EbSymbolCode;
// 		arg.AddArg("product_code", info.Code);
// 		arg_list.push_back(arg);
// 	}
// 
// 	for (auto it = _OptionRunVector.begin(); it != _OptionRunVector.end(); ++it) {
// 		SmRunInfo& info = *it;
// 		SmTaskArg arg;
// 		arg.Desc = "�ɺ��ڵ带 �������� ���Դϴ�.";
// 		arg.Detail = info.Name;
// 		arg.ArgId = SmServerDataReceiver::GetId();
// 		arg.TaskType = SmTaskType::EbSymbolCode;
// 		arg.AddArg("product_code", info.Code);
// 		arg_list.push_back(arg);
// 	}

	return arg_list;
}

std::vector<SmRunInfo> SmMarketManager::GetRunInfoList()
{
	std::vector<SmRunInfo> arg_list;
	for (auto it = _FutureRunVector.begin(); it != _FutureRunVector.end(); ++it) {
		SmRunInfo& info = *it;
		arg_list.push_back(info);
	}

	
	for (auto it = _OptionRunVector.begin(); it != _OptionRunVector.end(); ++it) {
		SmRunInfo& info = *it;
		arg_list.push_back(info);
	}
	

	return arg_list;
}

void SmMarketManager::LoadRunInfo()
{
	ZmConfigManager* configMgr = ZmConfigManager::GetInstance();
	std::string appPath;
	appPath = configMgr->GetAppPath();
	appPath.append(_T("\\"));
	appPath.append(_T("config.xml"));

	/// [load xml file]
	// Create empty XML document within memory
	pugi::xml_document doc;
	// Load XML file into memory
	// Remark: to fully read declaration entries you have to specify
	// "pugi::parse_declaration"
	pugi::xml_parse_result result = doc.load_file(appPath.c_str(),
		pugi::parse_default | pugi::parse_declaration);
	if (!result)
	{
		// ���� ������ ���� ��
// 		std::cout << "Parse error: " << result.description()
// 			<< ", character pos= " << result.offset;
		return;
	}

	pugi::xml_node application = doc.child("application");
	pugi::xml_node running_list = application.child("runnig_list");
	if (running_list) {
		pugi::xml_node future_list = running_list.child("future_list");
		if (future_list) {
			for (pugi::xml_node future_node = future_list.first_child(); future_node; future_node = future_node.next_sibling()) {
				std::string code = future_node.attribute("code").as_string();
				std::string name = future_node.attribute("name").as_string();
				std::string custom_name = future_node.attribute("custom_name").as_string();
				SmRunInfo run_info;
				run_info.Code = code;
				run_info.Name = name;
				run_info.UserDefinedName = custom_name;
				AddFutureRunInfo(run_info);
			}
		}

		pugi::xml_node option_list = running_list.child("option_list");
		if (option_list) {
			for (pugi::xml_node option_node = option_list.first_child(); option_node; option_node = option_node.next_sibling()) {
				std::string call_code = option_node.attribute("call").as_string();
				std::string put_code = option_node.attribute("put").as_string();
				std::string name = option_node.attribute("name").as_string();
				std::string code = option_node.child_value();
				SmRunInfo run_info;
				run_info.CallCode = call_code;
				run_info.PutCode = put_code;
				run_info.Name = name;
				run_info.UserDefinedName = name;
				run_info.Code = code;
				AddOptionRunInfo(run_info);
			}
		}
	}
}

void SmMarketManager::SendSymbolMaster(std::string user_id, SmSymbol* sym)
{
	if (!sym)
		return;
	json send_object;
// 	send_object["res_id"] = SmProtocol::res_symbol_master;
// 	send_object["total_symbol_count"] = GetTotalSymbolCount();
// 	send_object["symbol_code"] = sym->SymbolCode();
// 	send_object["category_index"] = sym->Index();
// 	send_object["name_kr"] = SmUtfUtil::AnsiToUtf8((char*)sym->Name().c_str());
// 	send_object["name_en"] = sym->NameEn().c_str();
// 	send_object["category_code"] = sym->ProductCode();
// 	send_object["market_name"] = SmUtfUtil::AnsiToUtf8((char*)sym->MarketName().c_str());
// 	send_object["decimal"] = sym->Decimal();
// 	send_object["contract_unit"] = sym->CtrUnit();
// 	send_object["seungsu"] = sym->Seungsu();
// 	send_object["tick_size"] = sym->TickSize();
//	send_object["tick_value"] = sym->TickValue();

	std::string content = send_object.dump(4);
	//SmUserManager* userMgr = SmUserManager::GetInstance();
	//userMgr->SendResultMessage(user_id, content);
}

SmMarket* SmMarketManager::FindMarket(std::string mrkt_name)
{
	for (auto it = _MarketList.begin(); it != _MarketList.end(); ++it) {
		SmMarket* mrkt = *it;
		if (mrkt->Name().compare(mrkt_name) == 0) {
			return mrkt;
		}
	}

	return nullptr;
}

void SmMarketManager::AddCategoryMarket(std::string cat_code, std::string mrkt_name)
{
	_CategoryToMarketMap[cat_code] = mrkt_name;
}
