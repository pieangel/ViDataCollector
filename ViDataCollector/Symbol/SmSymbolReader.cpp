#include "pch.h"
#include "SmSymbolReader.h"
#include <filesystem>
#include <sstream>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include "SmMarket.h"
#include "SmMarketManager.h"
#include "SmProduct.h"
#include "SmSymbol.h"
/*#include "../Database/SmTimeSeriesServiceManager.h"*/
#include "SmSymbolManager.h"
// #include "../Database/SmTimeSeriesDBManager.h"
 #include "../Config/ZmConfigManager.h"
#include "../Xml/pugixml.hpp"

SmSymbolReader::SmSymbolReader()
{
	ZmConfigManager* configMgr = ZmConfigManager::GetInstance();
	std::string appPath = configMgr->GetAppPath();
	std::string configPath = appPath;
	configPath.append(_T("\\Config\\Config.xml"));
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

	InitProductSet();
}

void SmSymbolReader::InitProductSet()
{
	ProductSet.insert("6A");
	ProductSet.insert("6B");
	ProductSet.insert("6E");
	ProductSet.insert("6J");
	ProductSet.insert("E7");
	ProductSet.insert("J7");
	ProductSet.insert("M6A");
	ProductSet.insert("M6B");
	ProductSet.insert("M6E");
	ProductSet.insert("ES");
	ProductSet.insert("NIY");
	ProductSet.insert("NKD");
	ProductSet.insert("NQ");
	ProductSet.insert("OES");
	ProductSet.insert("ONQ");
	ProductSet.insert("SP");
	ProductSet.insert("GE");
	ProductSet.insert("CL");
	ProductSet.insert("HO");
	ProductSet.insert("NG");
	ProductSet.insert("QG");
	ProductSet.insert("QM");
	ProductSet.insert("RB");
	ProductSet.insert("GC");
	ProductSet.insert("MGC");
	ProductSet.insert("OGC");
	ProductSet.insert("OSI");
	ProductSet.insert("QO");
	ProductSet.insert("SI");
	ProductSet.insert("YM");
	ProductSet.insert("ZF");
	ProductSet.insert("ZN");
	ProductSet.insert("ZQ");
	ProductSet.insert("OZC");
	ProductSet.insert("OZS");
	ProductSet.insert("OZW");
	ProductSet.insert("ZC");
	ProductSet.insert("ZL");
	ProductSet.insert("ZM");
	ProductSet.insert("ZS");
	ProductSet.insert("ZW");
	ProductSet.insert("CN");
	ProductSet.insert("NK");
	ProductSet.insert("TW");
	ProductSet.insert("BRN");
	ProductSet.insert("HSI");
	ProductSet.insert("VX");
	ProductSet.insert("GF");
	ProductSet.insert("HF");
	ProductSet.insert("HG");
	ProductSet.insert("LE");
}



SmSymbolReader::~SmSymbolReader()
{
}

std::string SmSymbolReader::GetWorkingDir()
{
	return ZmConfigManager::GetInstance()->GetAppPath();
}


void SmSymbolReader::ReadSymbolFromFile(int index, std::string fullPath)
{
	switch (index)
	{
	case 0:
		ReadKospiFutureFile(fullPath);
		break;
	case 1:
		ReadKospiOptionFile(fullPath);
		break;
	case 2:
		ReadKospiWeeklyOptionFile(fullPath);
		break;
	case 3:
		ReadKosdaqFutureFile(fullPath);
		break;
	case 4:
		ReadMiniKospiFutureFile(fullPath);
		break;
	case 5:
		ReadCommodityFutureFile(fullPath);
		break;
	case 6:
		ReadKospiFutureInfo(fullPath);
		break;
	case 7:
		ReadKospiOptionInfo(fullPath);
		break;
	case 8:
		ReadUsDollarFutureInfo(fullPath);
		break;
	case 9:
		ReadMarketFile(fullPath);
		break;
	case 10:
		ReadPmFile(fullPath);
		break;
	case 11:
		ReadJmFile(fullPath);
		break;
	default:
		break;
	}
}

void SmSymbolReader::ReadMarketFile()
{
	ZmConfigManager* configMgr = ZmConfigManager::GetInstance();
	std::string appPath;
	appPath = configMgr->GetAppPath();
	appPath.append(_T("\\"));
	appPath.append(_T("mst"));
	appPath.append(_T("\\"));
	std::string file_name = "MRKT.cod";
	TRACE(file_name.c_str());
	std::string file_path = appPath + file_name;
	ReadMarketFile(file_path);
}

void SmSymbolReader::ReadMarketFile(std::string fullPath)
{
	SmMarketManager* marketMgr = SmMarketManager::GetInstance();
	//CString msg;
	std::ifstream infile(fullPath);
	std::string line;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		std::string market_type = line.substr(0, 20);
		std::string exchange = line.substr(20, 5);
		std::string pmCode = line.substr(25, 3);
		std::string enName = line.substr(28, 50);
		std::string name = line.substr(78, 50);
		
		boost::trim_right(market_type);
		boost::trim_right(exchange);
		boost::trim_right(pmCode);
		boost::trim_right(enName);
		boost::trim_right(name);
		
		SmMarket* market = marketMgr->AddMarket(market_type);
		SmProduct* cat = market->AddProduct(pmCode);
		cat->MarketName(market_type);
		cat->Exchange(exchange);
		cat->Name(enName);
		cat->NameKr(name);
		//msg.Format(_T("market = %s, ex = %s, pmCode = %s, name = %s, ename = %s\n"), market_type.c_str(), exchange.c_str(), pmCode.c_str(), name.c_str(), enName.c_str());
		//TRACE(msg);
	}
}

void SmSymbolReader::ReadPmFile()
{
	ZmConfigManager* configMgr = ZmConfigManager::GetInstance();
	std::string appPath;
	appPath = configMgr->GetAppPath();
	appPath.append(_T("\\"));
	appPath.append(_T("mst"));
	appPath.append(_T("\\"));
	std::string file_name = "PMCODE.cod";
	TRACE(file_name.c_str());
	std::string file_path = appPath + file_name;
	ReadPmFile(file_path);
}



void SmSymbolReader::ReadPmFile(std::string fullPath)
{
	SmMarketManager* marketMgr = SmMarketManager::GetInstance();
	//CString msg;
	std::ifstream infile(fullPath);
	std::string line;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		std::string market = line.substr(0, 20);
		std::string exIndexCode = line.substr(20, 4);
		std::string exChangeCode = line.substr(24, 5);
		std::string pmCode = line.substr(29, 5);
		std::string pmGubun = line.substr(34, 3);
		std::string pmGubun2 = line.substr(84, 30);
		//msg.Format(_T("market = %s, pmCode = %s, ename = %s\n"), market.c_str(), pmCode.c_str(), pmGubun2.c_str());
		//TRACE(msg);

		boost::trim_right(market);
		boost::trim_right(exIndexCode);
		boost::trim_right(exChangeCode);
		boost::trim_right(pmCode);
		boost::trim_right(pmGubun);
		SmProduct* cat = marketMgr->FindProduct(market, pmCode);
		if (cat) {
			cat->ExchangeCode(exChangeCode);
			cat->ExchangeIndex(exIndexCode);
			cat->MarketCode(pmGubun);
			marketMgr->AddCategoryMarket(pmCode, market);
		}
	}
}

void SmSymbolReader::ReadJmFile()
{
	ZmConfigManager* configMgr = ZmConfigManager::GetInstance();
	std::string appPath;
	appPath = configMgr->GetAppPath();
	appPath.append(_T("\\"));
	appPath.append(_T("mst"));
	appPath.append(_T("\\"));
	std::string file_name = "JMCODE.cod";
	TRACE(file_name.c_str());
	std::string file_path = appPath + file_name;
	ReadJmFile(file_path);
}

void SmSymbolReader::ReadJmFile(std::string fullPath)
{
	SmMarketManager* marketMgr = SmMarketManager::GetInstance();
	CString msg;
	std::ifstream infile(fullPath);
	std::string line;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);

		std::string Series = line.substr(0, 32);
		/* 종목코드                             */

		std::string ExchCd = line.substr(32, 5);
		/* 거래소                               */

		std::string IndexCode = line.substr(37, 4);
		/* 품목 인덱스코드                      */

		std::string MrktCd = line.substr(41, 5);
		/* 품목코드                             */

		std::string ExchNo = line.substr(46, 5);
		/* 거래소 번호                          */

		std::string Pdesz = line.substr(51, 5);
		/* 소수점 정보                          */

		std::string Rdesz = line.substr(56, 5);
		/* 소수점 정보2                         */

		std::string CtrtSize = line.substr(61, 20);
		/* 계약크기                             */

		std::string TickSize = line.substr(81, 20);
		/* Tick Size                            */

		std::string TickValue = line.substr(101, 20);
		/* Tick Value                           */

		std::string MltiPler = line.substr(121, 20);
		/* 거래승수                             */

		std::string DispDigit = line.substr(141, 10);
		/* 진법                                 */

		std::string SeriesNm = line.substr(151, 32);
		/* Full 종목명                          */

		std::string SeriesNmKor = line.substr(183, 32);
		/* Full 종목명한글                      */

		std::string NearSeq = line.substr(215, 1);
		/* 최근월물, 주요종목표시               */

		std::string StatTp = line.substr(216, 1);
		/* 거래가능여부                         */

		std::string LockDt = line.substr(217, 8);
		/* 신규거래제한일                       */

		std::string TradFrDt = line.substr(225, 8);
		/* 최초거래일                           */

		std::string last_date = line.substr(233, 8);
		/* 최종거래일                           */

		std::string ExprDt = line.substr(241, 8);
		/* 만기일, 최종결제일                   */

		std::string RemnCnt = line.substr(249, 4);
		/* 잔존일수                             */

		std::string HogaMthd = line.substr(253, 30);
		/* 호가방식                             */

		std::string MinMaxRt = line.substr(283, 6);
		/* 상하한폭비율                         */

		std::string BaseP = line.substr(289, 20);
		/* 기준가                               */

		std::string MaxP = line.substr(309, 20);
		/* 상한가                               */

		std::string MinP = line.substr(329, 20);
		/* 하한가                               */

		std::string TrstMgn = line.substr(349, 20);
		/* 신규주문증거금                       */

		std::string MntMgn = line.substr(369, 20);
		/* 유지증거금                           */

		std::string CrcCd = line.substr(389, 3);
		/* 결제통화코드                         */

		std::string BaseCrcCd = line.substr(392, 3);
		/* BASE CRC CD                          */

		std::string CounterCrcCd = line.substr(395, 3);
		/* COUNTER CRC CD                       */

		std::string PipCost = line.substr(398, 20);
		/* PIP COST                             */

		std::string BuyInt = line.substr(418, 20);
		/* 매수이자                             */

		std::string SellInt = line.substr(438, 20);
		/* 매도이자                             */

		std::string RoundLots = line.substr(458, 6);
		/* LOUND LOTS                           */

		std::string ScaleChiper = line.substr(464, 10);
		/* 진법자리수                           */

		std::string decimalchiper = line.substr(474, 5);
		/* 소수점 정보(KTB기준)                 */

		std::string JnilVolume = line.substr(479, 10);
		/* 전일거래량                           */


		boost::trim_right(Series);
		boost::trim_right(SeriesNm);
		boost::trim_right(SeriesNmKor);
		boost::trim_right(MrktCd);
		//msg.Format(_T("code = %s, name = %s, name_kr = %s\n"), Series.c_str(), SeriesNm.c_str(), SeriesNmKor.c_str());
		//TRACE(msg);

		SmSymbolManager* symMgr = SmSymbolManager::GetInstance();
		SmProduct* product = marketMgr->FindProduct(MrktCd);
		bool included = false;
		std::set<std::string>& abroad_product_set = SmMarketManager::GetInstance()->GetAbroadProductSet();
		auto it = abroad_product_set.find(product->Code());
		if (it != abroad_product_set.end())
			included = true;
		if (product && included) {
			SmSymbol* sym = product->AddSymbol(Series);
			msg.Format(_T("code = %s, name = %s, name_kr = %s\n"), Series.c_str(), SeriesNm.c_str(), SeriesNmKor.c_str());
			TRACE(msg);

			product->AddToYearMonth(sym->SymbolCode(), sym);
			sym->Index(std::stoi(IndexCode));
			sym->NearMonth(std::stoi(IndexCode));
			sym->Name(SeriesNmKor);
			sym->NameEn(SeriesNm);
			symMgr->AddSymbol(sym);
			sym->ProductCode(product->Code());
			sym->MarketName(product->MarketName());
			sym->Decimal(std::stoi(Pdesz));
			sym->Seungsu(std::stoi(MltiPler));
			sym->CtrUnit(std::stod(CtrtSize));
			sym->TickValue(std::stod(TickValue));
			sym->TickSize(std::stod(TickSize));
			sym->LastDate(last_date);
			product->Decimal(std::stoi(Pdesz));
		}
	}
}

// 국내는 앞에 3자리가 상품을 나타낸다. 그 다음 한자리가 년도를 나타내며 그 다음 한자리가 월을 나타낸다.
// 나머지 네자리는 행사가를 의미한다.
void SmSymbolReader::ReadKospiFutureFile(std::string fullPath)
{
	SmMarketManager* marketMgr = SmMarketManager::GetInstance();
	std::string market_name = "국내시장";
	SmMarket *market = marketMgr->AddMarket(market_name);
	//CString msg;
	std::ifstream infile(fullPath);
	std::string line;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);

		std::string shcode = line.substr(0, 8);
		/* 종목코드                             */

		std::string expcode = line.substr(8, 12);
		/* 표준코드                               */

		std::string hname = line.substr(20, 30);
		/* 한글 종목명                      */

		std::string item = line.substr(50, 6);
		/* 기초자산코드                             */

		std::string deli = line.substr(56, 2);
		/* 소수점                          */

		std::string hounit = line.substr(58, 5);
		/*호가단위                          */

		// 0이 8개 더 붙어 있어 일부러 13자리만 읽는다.
		std::string tradewin = line.substr(63, 13);
		/* 거래승수                         */

		std::string spjmgubun = line.substr(84, 1);
		/* 스프레드기준종목구분코드*/

		std::string gshcode = line.substr(85, 8);
		/* 근월물코드                            */

		std::string wshcode = line.substr(93, 8);
		/* 원월물코드                           */

		std::string product_code = shcode.substr(0, 3);

		

		boost::trim_right(shcode);
		boost::trim_right(hname);
		boost::trim(item);
		boost::trim(deli);
		//msg.Format(_T("code = %s, name = %s, name_kr = %s\n"), shcode.c_str(), hname.c_str(), item.c_str());
		//TRACE(msg);

// 		SmSymbolManager* symMgr = SmSymbolManager::GetInstance();
// 		SmProduct* product = market->FindAddProduct(product_code);
// 		marketMgr->AddCategoryMarket(product_code, market_name);
// 		product->MarketName(market_name);
// 		product->NameKr("코스피200선물");
// 		product->NameKr("Kospi200F");
// 
// 		SmSymbol* sym = product->AddSymbol(shcode);
// 		sym->Name(hname);
// 		symMgr->AddSymbol(sym);
// 		sym->ProductCode(product->Code());
// 		sym->MarketName(product->MarketName());
// 		sym->Decimal(std::stoi(deli));
// 		sym->Seungsu(std::stoi(tradewin));
// 		int hoga_unit = std::stoi(hounit);
// 		int deci = std::stoi(deli);
// 		product->Decimal(deci);
// 		double tick_size = hoga_unit / std::pow(10, deci);
// 		sym->TickSize(tick_size);
// 		sym->CtrUnit(tick_size);
// 		double tick_value = std::stoi(tradewin) * tick_size;
// 		sym->TickValue(tick_value);
	}
}

void SmSymbolReader::ReadKospiOptionFile(std::string fullPath)
{
	SmMarketManager* marketMgr = SmMarketManager::GetInstance();
	std::string market_name = "국내시장";
	SmMarket* market = marketMgr->AddMarket(market_name);
	CString msg;
	std::ifstream infile(fullPath);
	std::string line;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);

		std::string shcode = line.substr(0, 8);
		/* 종목코드                             */

		std::string expcode = line.substr(8, 12);
		/* 표준코드                               */

		std::string hname = line.substr(20, 30);
		/* 한글 종목명                      */

		std::string atm = line.substr(50, 1);
		/* ATM 구분                      */

		std::string item = line.substr(51, 6);
		/* 기초자산코드                             */

		std::string deli = line.substr(57, 2);
		/* 소수점                          */

		std::string hounit = line.substr(59, 5);
		/*호가단위                          */

		// 0이 8개 더 붙어 있어 일부러 13자리만 읽는다.
		std::string tradewin = line.substr(64, 13);
		/* 거래승수                         */

		std::string spjmgubun = line.substr(85, 1);
		/* 스프레드기준종목구분코드*/

		std::string gshcode = line.substr(86, 8);
		/* 근월물코드                            */

		std::string wshcode = line.substr(94, 8);
		/* 원월물코드                           */

		std::string product_code = shcode.substr(0, 3);



		boost::trim_right(shcode);
		boost::trim_right(hname);
		boost::trim(item);
		boost::trim(deli);
		msg.Format(_T("code = %s, name = %s, name_kr = %s\n"), shcode.c_str(), hname.c_str(), item.c_str());
		//TRACE(msg);

// 		SmSymbolManager* symMgr = SmSymbolManager::GetInstance();
// 		SmProduct* product = market->FindAddProduct(product_code);
// 		marketMgr->AddCategoryMarket(product_code, market_name);
// 		product->MarketName(market_name);
// 		product->NameKr("코스피200옵션");
// 		product->NameKr("Kospi200O");
// 		SmSymbol* sym = product->AddSymbol(shcode);
// 		sym->Name(hname);
// 		symMgr->AddSymbol(sym);
// 		sym->ProductCode(product->Code());
// 		sym->MarketName(product->MarketName());
// 		sym->Decimal(std::stoi(deli));
// 		sym->Seungsu(std::stoi(tradewin));
// 		sym->Atm(std::stoi(atm));
// 		int hoga_unit = std::stoi(hounit);
// 		int deci = std::stoi(deli);
// 		double tick_size = hoga_unit / std::pow(10, deci);
// 		sym->TickSize(tick_size);
// 		sym->CtrUnit(tick_size);
// 		double tick_value = std::stoi(tradewin) * tick_size;
// 		sym->TickValue(tick_value);
// 		product->Decimal(std::stoi(deli));
	}
}

void SmSymbolReader::ReadKospiWeeklyOptionFile(std::string fullPath)
{
	SmMarketManager* marketMgr = SmMarketManager::GetInstance();
	std::string market_name = "국내시장";
	SmMarket* market = marketMgr->AddMarket(market_name);
	CString msg;
	std::ifstream infile(fullPath);
	std::string line;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);

		std::string shcode = line.substr(0, 8);
		/* 종목코드                             */

		std::string expcode = line.substr(8, 12);
		/* 표준코드                               */

		std::string hname = line.substr(20, 30);
		/* 한글 종목명                      */

		std::string atm = line.substr(50, 1);
		/* ATM 구분                      */

		std::string item = line.substr(51, 6);
		/* 기초자산코드                             */

		std::string deli = line.substr(57, 2);
		/* 소수점                          */

		std::string hounit = line.substr(59, 5);
		/*호가단위                          */

		// 0이 8개 더 붙어 있어 일부러 13자리만 읽는다.
		std::string tradewin = line.substr(64, 13);
		/* 거래승수                         */

		std::string spjmgubun = line.substr(85, 1);
		/* 스프레드기준종목구분코드*/

		std::string gshcode = line.substr(86, 8);
		/* 근월물코드                            */

		std::string wshcode = line.substr(94, 8);
		/* 원월물코드                           */

		std::string product_code = shcode.substr(0, 3);



		boost::trim_right(shcode);
		boost::trim_right(hname);
		boost::trim(item);
		boost::trim(deli);
		msg.Format(_T("code = %s, name = %s, name_kr = %s\n"), shcode.c_str(), hname.c_str(), item.c_str());
		//TRACE(msg);

// 		SmSymbolManager* symMgr = SmSymbolManager::GetInstance();
// 		SmProduct* product = market->FindAddProduct(product_code);
// 		marketMgr->AddCategoryMarket(product_code, market_name);
// 		product->MarketName(market_name);
// 		product->NameKr("코스피200위클리선물");
// 		product->NameKr("Kospi200WeeklyF");
// 		SmSymbol* sym = product->AddSymbol(shcode);
// 		sym->Name(hname);
// 		symMgr->AddSymbol(sym);
// 		sym->ProductCode(product->Code());
// 		sym->MarketName(product->MarketName());
// 		sym->Decimal(std::stoi(deli));
// 		sym->Seungsu(std::stoi(tradewin));
// 		sym->Atm(std::stoi(atm));
// 		int hoga_unit = std::stoi(hounit);
// 		int deci = std::stoi(deli);
// 		double tick_size = hoga_unit / std::pow(10, deci);
// 		sym->TickSize(tick_size);
// 		sym->CtrUnit(tick_size);
// 		double tick_value = std::stoi(tradewin) * tick_size;
// 		sym->TickValue(tick_value);
// 		product->Decimal(std::stoi(deli));
	}
}

void SmSymbolReader::ReadKosdaqFutureFile(std::string fullPath)
{
	SmMarketManager* marketMgr = SmMarketManager::GetInstance();
	std::string market_name = "국내시장";
	SmMarket* market = marketMgr->AddMarket(market_name);
	CString msg;
	std::ifstream infile(fullPath);
	std::string line;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);

		std::string shcode = line.substr(0, 8);
		/* 종목코드                             */

		std::string expcode = line.substr(8, 12);
		/* 표준코드                               */

		std::string hname = line.substr(20, 30);
		/* 한글 종목명                      */

		std::string item = line.substr(50, 6);
		/* 기초자산코드                             */

		std::string deli = line.substr(56, 2);
		/* 소수점                          */

		std::string hounit = line.substr(58, 5);
		/*호가단위                          */

		// 0이 8개 더 붙어 있어 일부러 13자리만 읽는다.
		std::string tradewin = line.substr(63, 13);
		/* 거래승수                         */

		std::string spjmgubun = line.substr(84, 1);
		/* 스프레드기준종목구분코드*/

		std::string gshcode = line.substr(85, 8);
		/* 근월물코드                            */

		std::string wshcode = line.substr(93, 8);
		/* 원월물코드                           */

		std::string product_code = shcode.substr(0, 3);



		boost::trim_right(shcode);
		boost::trim_right(hname);
		boost::trim(item);
		boost::trim(deli);
		msg.Format(_T("code = %s, name = %s, name_kr = %s\n"), shcode.c_str(), hname.c_str(), item.c_str());
		//TRACE(msg);

// 		SmSymbolManager* symMgr = SmSymbolManager::GetInstance();
// 		SmProduct* product = market->FindAddProduct(product_code);
// 		marketMgr->AddCategoryMarket(product_code, market_name);
// 		product->MarketName(market_name);
// 		product->NameKr("코스닥150선물");
// 		product->NameKr("Kosdaqq150F");
// 
// 		SmSymbol* sym = product->AddSymbol(shcode);
// 		sym->Name(hname);
// 		symMgr->AddSymbol(sym);
// 		sym->ProductCode(product->Code());
// 		sym->MarketName(product->MarketName());
// 		sym->Decimal(std::stoi(deli));
// 		sym->Seungsu(std::stoi(tradewin));
// 		int hoga_unit = std::stoi(hounit);
// 		int deci = std::stoi(deli);
// 		double tick_size = hoga_unit / std::pow(10, deci);
// 		sym->TickSize(tick_size);
// 		sym->CtrUnit(tick_size);
// 		double tick_value = std::stoi(tradewin) * tick_size;
// 		sym->TickValue(tick_value);
	}
}

void SmSymbolReader::ReadMiniKospiFutureFile(std::string fullPath)
{
	SmMarketManager* marketMgr = SmMarketManager::GetInstance();
	std::string market_name = "국내시장";
	SmMarket* market = marketMgr->AddMarket(market_name);
	CString msg;
	std::ifstream infile(fullPath);
	std::string line;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);

		std::string shcode = line.substr(0, 8);
		/* 종목코드                             */

		std::string expcode = line.substr(8, 12);
		/* 표준코드                               */

		std::string hname = line.substr(20, 30);
		/* 한글 종목명                      */

		std::string item = line.substr(50, 6);
		/* 기초자산코드                             */

		std::string deli = line.substr(56, 2);
		/* 소수점                          */

		std::string hounit = line.substr(58, 5);
		/*호가단위                          */

		// 0이 8개 더 붙어 있어 일부러 13자리만 읽는다.
		std::string tradewin = line.substr(63, 13);
		/* 거래승수                         */

		std::string spjmgubun = line.substr(84, 1);
		/* 스프레드기준종목구분코드*/

		std::string gshcode = line.substr(85, 8);
		/* 근월물코드                            */

		std::string wshcode = line.substr(93, 8);
		/* 원월물코드                           */

		std::string product_code = shcode.substr(0, 3);



		boost::trim_right(shcode);
		boost::trim_right(hname);
		boost::trim(item);
		boost::trim(deli);
		msg.Format(_T("code = %s, name = %s, name_kr = %s\n"), shcode.c_str(), hname.c_str(), item.c_str());
		//TRACE(msg);

// 		SmSymbolManager* symMgr = SmSymbolManager::GetInstance();
// 		SmProduct* product = market->FindAddProduct(product_code);
// 		marketMgr->AddCategoryMarket(product_code, market_name);
// 		product->MarketName(market_name);
// 		product->NameKr("코스피200미니선물");
// 		product->NameKr("Kospi200MiniF");
// 
// 		SmSymbol* sym = product->AddSymbol(shcode);
// 		sym->Name(hname);
// 		symMgr->AddSymbol(sym);
// 		sym->ProductCode(product->Code());
// 		sym->MarketName(product->MarketName());
// 		sym->Decimal(std::stoi(deli));
// 		sym->Seungsu(std::stoi(tradewin));
// 		int hoga_unit = std::stoi(hounit);
// 		int deci = std::stoi(deli);
// 		double tick_size = hoga_unit / std::pow(10, deci);
// 		sym->TickSize(tick_size);
// 		sym->CtrUnit(tick_size);
// 		double tick_value = std::stoi(tradewin) * tick_size;
// 		sym->TickValue(tick_value);
// 		product->Decimal(std::stoi(deli));
	}
}

void SmSymbolReader::ReadCommodityFutureFile(std::string fullPath)
{
	SmMarketManager* marketMgr = SmMarketManager::GetInstance();
	std::string market_name = "국내시장";
	SmMarket* market = marketMgr->AddMarket(market_name);
	CString msg;
	std::ifstream infile(fullPath);
	std::string line;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);

		std::string shcode = line.substr(0, 8);
		/* 종목코드                             */

		std::string expcode = line.substr(8, 12);
		/* 표준코드                               */

		std::string hname = line.substr(20, 30);
		/* 한글 종목명                      */

		std::string item = line.substr(50, 6);
		/* 기초자산코드                             */

		std::string deli = line.substr(56, 2);
		/* 소수점                          */

		std::string hounit = line.substr(58, 5);
		/*호가단위                          */

		// 0이 8개 더 붙어 있어 일부러 13자리만 읽는다.
		std::string tradewin = line.substr(63, 13);
		/* 거래승수                         */

		std::string spjmgubun = line.substr(84, 1);
		/* 스프레드기준종목구분코드*/

		std::string gshcode = line.substr(85, 8);
		/* 근월물코드                            */

		std::string wshcode = line.substr(93, 8);
		/* 원월물코드                           */

		std::string product_code = shcode.substr(0, 3);



		boost::trim_right(shcode);
		boost::trim_right(hname);
		boost::trim(item);
		boost::trim(deli);
		msg.Format(_T("code = %s, name = %s, name_kr = %s\n"), shcode.c_str(), hname.c_str(), item.c_str());
		//TRACE(msg);

// 		SmSymbolManager* symMgr = SmSymbolManager::GetInstance();
// 		SmProduct* product = market->FindAddProduct(product_code);
// 		marketMgr->AddCategoryMarket(product_code, market_name);
// 		product->MarketName(market_name);
// 		product->NameKr("코스피상품선물");
// 		product->NameKr("KospiCommodityF");
// 
// 		SmSymbol* sym = product->AddSymbol(shcode);
// 		sym->Name(hname);
// 		symMgr->AddSymbol(sym);
// 		sym->ProductCode(product->Code());
// 		sym->MarketName(product->MarketName());
// 		sym->Decimal(std::stoi(deli));
// 		sym->Seungsu(std::stoi(tradewin));
// 		int hoga_unit = std::stoi(hounit);
// 		int deci = std::stoi(deli);
// 		double tick_size = hoga_unit / std::pow(10, deci);
// 		sym->TickSize(tick_size);
// 		sym->CtrUnit(tick_size);
// 		double tick_value = std::stoi(tradewin) * tick_size;
// 		sym->TickValue(tick_value);
// 		product->Decimal(std::stoi(deli));
	}
}

void SmSymbolReader::ReadKospiFutureInfo(std::string fullPath)
{
	CString msg;
	std::ifstream infile(fullPath);
	std::string line;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);

		std::string shcode = line.substr(0, 8);
		/* 종목코드                             */

		std::string deli = line.substr(8, 2);
		/* 소수점                          */

		std::string tick_size = line.substr(10, 5);
		/* 틱사이즈                               */

		std::string tick_value = line.substr(15, 5);
		/* 틱 밸류                      */

		std::string trade_win = line.substr(20, 10);
		/* 거래 승수                            */

		
		std::string near_month = line.substr(90, 2);
		/*근월물                          */

		std::string last_date = line.substr(92, 8);
		/*최종거래일                         */

		SmMarketManager* mrktMgr = SmMarketManager::GetInstance();

// 		SmSymbolManager* symMgr = SmSymbolManager::GetInstance();
// 		SmSymbol* sym = symMgr->FindSymbol(shcode);
// 		if (sym) {
// 			sym->Decimal(std::stoi(deli));
// 			sym->Seungsu(std::stoi(trade_win));
// 			sym->TickSize(std::stod(tick_size));
// 			sym->TickValue(std::stod(tick_value));
// 			sym->NearMonth(std::stoi(near_month));
// 			sym->LastDate(last_date);
// 		}
	}
}

void SmSymbolReader::ReadKospiOptionInfo(std::string fullPath)
{
	CString msg;
	std::ifstream infile(fullPath);
	std::string line;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);

		std::string shcode = line.substr(0, 8);
		/* 종목코드                             */

		std::string deli = line.substr(8, 2);
		/* 소수점                          */

		std::string tick_size = line.substr(10, 5);
		/* 틱사이즈                               */

		std::string tick_value = line.substr(15, 5);
		/* 틱 밸류                      */

		std::string trade_win = line.substr(20, 10);
		/* 거래 승수                            */


		std::string near_month = line.substr(90, 2);
		/*근월물                          */
		if (near_month.compare("A"))
			near_month = "10";
		else if (near_month.compare("B"))
			near_month = "11";
		else if (near_month.compare("C"))
			near_month = "12";
		else if (near_month.compare("D"))
			near_month = "13";
		else if (near_month.compare("E"))
			near_month = "14";
		else if (near_month.compare("F"))
			near_month = "15";

		std::string last_date = line.substr(92, 8);
		/*최종거래일                         */



// 		SmSymbolManager* symMgr = SmSymbolManager::GetInstance();
// 		SmSymbol* sym = symMgr->FindSymbol(shcode);
// 		if (sym) {
// 			sym->Decimal(std::stoi(deli));
// 			sym->Seungsu(std::stoi(trade_win));
// 			sym->TickSize(std::stod(tick_size));
// 			sym->TickValue(std::stod(tick_value));
// 			sym->NearMonth(std::stoi(near_month));
// 			sym->LastDate(last_date);
// 		}
	}
}

void SmSymbolReader::ReadUsDollarFutureInfo(std::string fullPath)
{
	CString msg;
	std::ifstream infile(fullPath);
	std::string line;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);

		std::string shcode = line.substr(0, 8);
		/* 종목코드                             */

		std::string deli = line.substr(8, 2);
		/* 소수점                          */

		std::string tick_size = line.substr(10, 5);
		/* 틱사이즈                               */

		std::string tick_value = line.substr(15, 5);
		/* 틱 밸류                      */

		std::string trade_win = line.substr(20, 10);
		/* 거래 승수                            */


		std::string near_month = line.substr(90, 2);
		/*근월물                          */
		if (near_month.compare("A"))
			near_month = "10";
		else if (near_month.compare("B"))
			near_month = "11";
		else if (near_month.compare("C"))
			near_month = "12";
		else if (near_month.compare("D"))
			near_month = "13";
		else if (near_month.compare("E"))
			near_month = "14";
		else if (near_month.compare("F"))
			near_month = "15";

		std::string last_date = line.substr(92, 8);
		/*최종거래일                         */



// 		SmSymbolManager* symMgr = SmSymbolManager::GetInstance();
// 		SmSymbol* sym = symMgr->FindSymbol(shcode);
// 		if (sym) {
// 			sym->Seungsu(std::stoi(trade_win));
// 			sym->TickSize(std::stod(tick_size));
// 			sym->TickValue(std::stod(tick_value));
// 			sym->NearMonth(std::stoi(near_month));
// 			sym->LastDate(last_date);
// 		}
	}
}

