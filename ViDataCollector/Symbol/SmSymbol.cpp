#include "pch.h"
#include "SmSymbol.h"
#include "../Json/json.hpp"
#include "../Network/SmServiceDefine.h"
#include "../Database/SmTimeSeriesDBManager.h"
#include "../Quote/SmQuoteItem.h"
#include "../Util/SmUtil.h"
#include "../Network/SmSessionManager.h"
#include "../Network/SmServiceDefine.h"
#include "../Config/SmConfigManager.h"
#include <chrono>
#include <sstream>
#include <fstream>
#include "../Util/VtStringUtil.h"
#include "../Log/loguru.hpp"
#include <algorithm>
#include "../Chart/SmChartDataManager.h"
#include "../Chart/SmChartData.h"

using namespace nlohmann;
SmSymbol::SmSymbol()
{
}


SmSymbol::~SmSymbol()
{
}

std::string SmSymbol::GetQuoteByJson()
{
	json quote;
	quote["req_id"] = SmProtocol::req_update_quote;
	quote["symbol_code"] = _SymbolCode;
	quote["time"] = Quote.OriginTime;
	quote["high"] = Quote.High;
	quote["low"] = Quote.Low;
	quote["open"] = Quote.Open;
	quote["close"] = Quote.Close;
	quote["sign_to_preday"] = Quote.SignToPreDay;
	quote["gap_from_preday"] = Quote.GapFromPreDay;
	quote["ratio_to_preday"] = Quote.RatioToPreday;
	quote["acc_volume"] = Quote.accVolume;

	return quote.dump();
}

std::string SmSymbol::GetHogaByJson()
{
	json hoga;
	hoga["req_id"] = SmProtocol::req_update_hoga;
	hoga["symbol_code"] = _SymbolCode;
	hoga["time"] = Hoga.Time;
	hoga["domestic_date"] = Hoga.DomesticDate;
	hoga["domestic_time"] = Hoga.DomesticTime;
	hoga["tot_buy_qty"] = Hoga.TotBuyQty;
	hoga["tot_sell_qty"] = Hoga.TotSellQty;
	hoga["tot_buy_cnt"] = Hoga.TotBuyCnt;
	hoga["tot_sell_cnt"] = Hoga.TotSellCnt;

	for (int i = 0; i < 5; i++) {
		hoga["hoga_items"][i]["buy_price"] = Hoga.Ary[i].BuyPrice;
		hoga["hoga_items"][i]["buy_cnt"] = Hoga.Ary[i].BuyCnt;
		hoga["hoga_items"][i]["buy_qty"] = Hoga.Ary[i].BuyQty;
		hoga["hoga_items"][i]["sell_price"] = Hoga.Ary[i].SellPrice;
		hoga["hoga_items"][i]["sell_cnt"] = Hoga.Ary[i].SellCnt;
		hoga["hoga_items"][i]["sell_qty"] = Hoga.Ary[i].SellQty;
	}

	return hoga.dump();
}

void SmSymbol::MakeCurrChartDataByTimer(std::string cur_hour_min)
{
	std::lock_guard<std::mutex> lock(_mutex);

	if (_MinDataMap.size() == 0)
		return;

	std::string start_hourmin = SmUtil::Format("%02d%02d", _StartHour, _StartMin);
	std::string end_hourmin = SmUtil::Format("%02d%02d", _EndHour, _EndMin);
	int start = std::stoi(start_hourmin);
	int end = std::stoi(end_hourmin);
	int cur = std::stoi(cur_hour_min);
	if (std::isdigit(_SymbolCode.at(2))) { // ��������
		if (cur < start || cur > end + 1)
			return;
	}
	else { // �ؿܼ���
		if (end < cur && cur < start)
			return;
	}

	// ���� ��Ʈ �����Ϳ��� ã�ƺ��� �Ѵ�.
	std::vector<int> cycle_vector;
	cycle_vector.push_back(1);
	cycle_vector.push_back(5);
	cycle_vector.push_back(10);
	cycle_vector.push_back(15);
	cycle_vector.push_back(30);
	cycle_vector.push_back(60);

	int cur_hour = std::stoi(cur_hour_min.substr(0, 2));
	int cur_min = std::stoi(cur_hour_min.substr(2, 2));

	auto it = _MinDataMap.rbegin();
	SmChartDataItem last_data = it->second;

	std::string prev_date, prev_time;

	for (size_t i = 0; i < cycle_vector.size(); ++i) {
		int cycle = cycle_vector[i];

		int next_hour = cur_hour;
		int next_min = cur_min + cycle;
		if (next_min >= 60) {
			next_hour = next_hour + 1;
			next_min = 60 - next_min;
		}
		int hour_diff = 0;
		if (next_hour >= StartHour()) {
			hour_diff = next_hour - StartHour();
		}
		else {
			hour_diff = next_hour - StartHour();
			hour_diff += 24;
		}
		int min_diff = 0;
		if (next_min >= StartMin()) {
			min_diff = next_min - StartMin() + 1;
		}
		else {
			min_diff = next_min - StartMin();
			min_diff += 60 + 1;
		}

		int total_min_diff = hour_diff * 60 + min_diff;

		// �ֱⰡ �ƴϸ� ������ �ʴ´�.
		if (cycle != 1 && total_min_diff % cycle != 1)
			continue;
		// Ÿ�̸ӿ� ���ؼ� ������� �����ʹ� �������� �ʴ´�.
		if (last_data.temp)
			continue;




		SmChartDataItem data;
		data.chartType = SmChartType::MIN;
		data.symbolCode = _SymbolCode;
		data.cycle = cycle;
		auto local_date = VtStringUtil::getCurentDate();
		data.date = local_date;

		std::string next_index = SmUtil::Format("%02d%02d", next_hour, next_min);
		std::string time = next_index;
		time.append("00");
		data.time = time;

		SendCycleChartData(data);

		SmChartDataManager* chartDataMgr = SmChartDataManager::GetInstance();
		SmChartData* chart_data = chartDataMgr->FindChartData(data.GetDataKey());
		if (chart_data) {

			data.o = last_data.c;
			data.h = last_data.c;
			data.l = last_data.c;
			data.c = last_data.c;
			data.v = last_data.v;


			chart_data->AddChartData(std::move(data));

			CString msg;
			msg.Format(_T("MakeCurrChartDataByTimer ::code = %s, cycle = %d, date = %s, t = %s, o = %d, h = %d, l = %d, c = %d, v = %d\n"), data.symbolCode.c_str(), data.cycle, data.date.c_str(), data.time.c_str(), data.o, data.h, data.l, data.c, data.v);
			TRACE(msg);
		}
	}
}

void SmSymbol::MakePrevChartDataByTimer(std::string cur_hour_min)
{
	std::lock_guard<std::mutex> lock(_mutex);

	int cur_hour = std::stoi(cur_hour_min.substr(0, 2));
	int cur_min = std::stoi(cur_hour_min.substr(2, 2));


	std::vector<int> date_time = SmUtil::GetLocalDateTime();
	//int cur_hour = date_time[3];
	//int cur_min = date_time[4];
	int hour_diff = 0;

	if (cur_hour >= StartHour()) {
		hour_diff = cur_hour - StartHour();
	}
	else {
		hour_diff = cur_hour - StartHour();
		hour_diff += 24;
	}
	int min_diff = 0;
	if (cur_min >= StartMin()) {
		min_diff = cur_min - StartMin() + 1;
	}
	else {
		min_diff = cur_min - StartMin();
		min_diff += 60 + 1;
	}

	int total_min_diff = hour_diff * 60 + min_diff;

	CString msg;
	msg.Format("symbolcode = %s, starthour = %d, startmin = %d, cur_hour = %d, cur_min = %d, total_min_diff = %d\n", SymbolCode().c_str(), StartHour(), StartMin(), cur_hour, cur_min, total_min_diff);
	TRACE(msg);

	std::vector<int> cycle_vector;
	cycle_vector.push_back(1);
	cycle_vector.push_back(5);
	cycle_vector.push_back(10);
	cycle_vector.push_back(15);
	cycle_vector.push_back(30);
	cycle_vector.push_back(60);


	int prev_hour = cur_hour;
	int prev_min = cur_min - 1;
	if (prev_min < 0) {
		prev_hour = prev_hour - 1;
		prev_min += 60;
	}

	std::string prev_index = SmUtil::Format("%02d%02d", prev_hour, prev_min);
	std::string cur_index = SmUtil::Format("%02d%02d", cur_hour, cur_min);

	for (size_t i = 0; i < cycle_vector.size(); ++i) {
		int cycle = cycle_vector[i];
		// ���� ����� �е����Ϳ��� ��Ʈ �ֱⵥ���͸� �����. ��� �ֱ�� 1�� �����͸� �������� �Ѵ�.
		MakePrevChartData(total_min_diff, SymbolCode(), prev_index, cur_index, cycle);
	}
}

void SmSymbol::MakePrevChartData(int total_min_diff, std::string symbol_code, std::string prev_hour_min, std::string chart_hour_min, int cycle)
{
	// ����� �����Ͱ� ������ ������ �ʴ´�.
	if (_MinDataMap.size() < cycle)
		return;

	// �ֱⰡ �ƴϸ� ������ �ʴ´�.
	if (cycle != 1 && total_min_diff % cycle != 1)
		return;

	// ���� �ð��� ������ ���� ǥ���Ѵ�.
	// 5�к� ��Ʈ�� ��� 9�� 00���̸� ��Ʈ ǥ�ô� 9�� 5����Ʈ�� �ȴ�.
	// ���� ���� �ð��� �� ������ ��Ʈ�� �ȴ�.
	auto end = _MinDataMap.find(prev_hour_min);
	if (end == _MinDataMap.end())
		return;

	SmChartDataItem data;
	data.chartType = SmChartType::MIN;
	auto local_date = VtStringUtil::getCurentDate();
	data.date = local_date;
	data.cycle = cycle;
	std::string time = chart_hour_min;
	time.append("00");
	data.time = time;
	data.symbolCode = symbol_code;

	for (int i = cycle - 1; i >= 0; i--) {
		auto it = std::prev(end, i);
		if (it == _MinDataMap.end())
			return;

		std::string key = it->first;
		CString msg;
		msg.Format(_T("MakePrevChartData for time = %s\n"), key.c_str());
		TRACE(msg);

		SmChartDataItem& cur_data = it->second;

		if (data.o == 0) {
			data.o = cur_data.o;
		}
		if (data.h == 0) {
			data.h = cur_data.h;
		}
		else {
			if (cur_data.h > data.h) {
				data.h = cur_data.h;
			}
		}
		if (data.l == 0) {
			data.l = cur_data.l;
		}
		else {
			if (cur_data.l < data.l) {
				data.l = cur_data.l;
			}
		}
		data.c = cur_data.c;
	}



	SmChartDataManager* chartDataMgr = SmChartDataManager::GetInstance();
	SmChartData* chart_data = chartDataMgr->FindChartData(data.GetDataKey());
	if (chart_data) {
		chart_data->AddChartData(std::move(data));

		std::map<std::string, SmChartDataItem>& data_list = chart_data->GetDataItemList();
		for (auto it = data_list.begin(); it != data_list.end(); ++it) {
			SendCycleChartData(it->second);
		}

		CString msg;
		msg.Format(_T("MakePrevChartData ::code = %s, cycle = %d, date = %s, t = %s, o = %d, h = %d, l = %d, c = %d, v = %d\n"), data.symbolCode.c_str(), data.cycle, data.date.c_str(), data.time.c_str(), data.o, data.h, data.l, data.c, data.v);
		TRACE(msg);
	}
	else {
		SendCycleChartData(data);
		chart_data = chartDataMgr->CreateChartData(data);
		chart_data->AddChartData(std::move(data));
		CString msg;
		msg.Format(_T("MakePrevChartData ::code = %s, cycle = %d, date = %s, t = %s, o = %d, h = %d, l = %d, c = %d, v = %d\n"), data.symbolCode.c_str(), data.cycle, data.date.c_str(), data.time.c_str(), data.o, data.h, data.l, data.c, data.v);
		TRACE(msg);
	}
}

void SmSymbol::SendCycleChartData(SmChartDataItem item)
{
	json send_object;
	send_object["req_id"] = SmProtocol::req_cycle_data_resend_onebyone;
	send_object["symbol_code"] = item.symbolCode;
	send_object["chart_type"] = item.chartType;
	send_object["cycle"] = item.cycle;
	send_object["date"] = item.date;
	send_object["time"] = item.time;
	send_object["o"] = item.o;
	send_object["h"] = item.h;
	send_object["l"] = item.l;
	send_object["c"] = item.c;
	send_object["v"] = item.v;

	std::string content = send_object.dump();
	SmSessionManager::GetInstance()->Send(content);
}
