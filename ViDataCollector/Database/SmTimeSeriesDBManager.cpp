#include "pch.h"
#include "SmTimeSeriesDBManager.h"
#include <ctime>
#include "../Util/VtStringUtil.h"
#include <cstring> //memset
#include <sstream>
#include <iostream>
#include <algorithm>
#include <boost/asio.hpp>
#include "../Json/json.hpp"
#include "../Symbol/SmSymbol.h"
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/categories.hpp> 
#include <boost/iostreams/code_converter.hpp>
#include <boost/locale.hpp>
#include <iostream>

namespace io = boost::iostreams;
using namespace nlohmann;

namespace ip = boost::asio::ip;

SmTimeSeriesDBManager::SmTimeSeriesDBManager()
{
	std::vector<std::string> addr_vec = GetIPAddress("angelpie.ddns.net");
	_Ip = addr_vec[0];
	_Port = 8086;
	_DatabaseName = "abroad_future";
	_Id = "angelpie";
	_Password = "orion1";

	
}

SmTimeSeriesDBManager::SmTimeSeriesDBManager(std::string ip, int port, std::string db, std::string id, std::string pwd)
{
	_Ip = ip;
	_Port = port;
	_DatabaseName = db;
	_Id = id;
	_Password = pwd;

	
}

SmTimeSeriesDBManager::~SmTimeSeriesDBManager()
{
	
}

std::string SmTimeSeriesDBManager::ExecQuery(std::string query_string)
{
	std::string resp;
	
	return resp;
}

void SmTimeSeriesDBManager::OnChartDataItem(SmChartDataItem data_item)
{
	
}

void SmTimeSeriesDBManager::CreateDataBase(std::string db_name)
{
	
}

std::vector<std::string> SmTimeSeriesDBManager::GetIPAddress(std::string host_name)
{
	boost::asio::io_service io_service;
	ip::tcp::resolver resolver(io_service);

	std::string h = host_name;
	std::cout << "Host name is " << h << '\n';
	std::cout << "IP addresses are: \n";
	std::stringstream ss;
	std::vector<std::string> addr_vec;
	std::for_each(resolver.resolve({ h, "" }), {}, [ &ss, &addr_vec](const auto& re) {
		ss << re.endpoint().address();
		std::string addr = ss.str();
		addr_vec.push_back(addr);
		ss.str("");
		});
	return addr_vec;
}

void SmTimeSeriesDBManager::UserTest()
{
	std::string resp;
	

}

void SmTimeSeriesDBManager::AddUserToDatabase(std::string id, std::string pwd)
{
	
}

std::pair<std::string, std::string> SmTimeSeriesDBManager::GetUserInfo(std::string id)
{
	
	return std::make_pair("", "");
}

void SmTimeSeriesDBManager::GetChartData()
{
	
}

void SmTimeSeriesDBManager::SaveQuoteItem(SmQuote&& qitem)
{
	
}

void SmTimeSeriesDBManager::SaveCurrentQuoteItem(SmQuote&& qitem)
{
	
}

void SmTimeSeriesDBManager::SaveHogaItem(SmHoga&& qitem)
{
	
}

void SmTimeSeriesDBManager::SaveSymbol(SmSymbol* sym)
{
	
}

void SmTimeSeriesDBManager::GetSymbolMaster(std::string symCode)
{
	
}

void SmTimeSeriesDBManager::DeleteMeasurement(std::string measure_name)
{
	std::string query_string = "DROP MEASUREMENT ";
	query_string.append("\"");
	query_string.append(measure_name);
	query_string.append("\"");
	std::string resp = ExecQuery(query_string);
}
