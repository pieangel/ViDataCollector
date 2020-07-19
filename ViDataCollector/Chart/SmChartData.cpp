#include "pch.h"
#include "SmChartData.h"
//#include "SmUserManager.h"
#include "../Json/json.hpp"
#include "../Log/loguru.hpp"
//#include "../EBCtrl/EbClient.h"
#include "../Util/SmUtil.h"
#include "../Util/VtStringUtil.h"
//#include "../Network/SmServiceDefine.h"
#include "../Format/format.h"

using namespace nlohmann;
void SmChartData::GetChartDataFromDB()
{
	
}

void SmChartData::GetChartDataFromServer()
{
	SmChartDataRequest req;
	req.reqType = SmChartDataReqestType::FIRST;
	req.symbolCode = _SymbolCode;
	req.chartType = _ChartType;
	req.cycle = _Cycle;
	req.count = (int)_DataQueueSize;
	req.next = 0;
	//SmHdClient* client = SmHdClient::GetInstance();
	//client->GetChartData(req);
}

void SmChartData::GetCyclicDataFromServer()
{
	SmChartDataRequest req;
	req.reqType = SmChartDataReqestType::CYCLE;
	req.symbolCode = _SymbolCode;
	req.chartType = _ChartType;
	req.cycle = _Cycle;
	req.count = (int)_CycleDataSize;
	req.next = 0;
	//SmHdClient* client = SmHdClient::GetInstance();
	//client->GetChartData(req);
}

void SmChartData::SendCyclicChartDataToUsers()
{
// 	CString msg;
// 	msg.Format("차트데이터 업데이트 됨 %d\n", 0);
// 	//TRACE(msg);
// 
// 	json send_object;
// 	send_object["res_id"] = SmProtocol::res_chart_cycle_data;
// 	send_object["symbol_code"] = _SymbolCode;
// 	send_object["chart_type"] = (int)_ChartType;
// 	send_object["cycle"] = _Cycle;
// 	send_object["total_count"] = _CycleDataSize;
// 	auto it = _DataMap.begin();
// 	std::advance(it, _DataMap.size() - _CycleDataSize);
// 	int k = 0;
// 	// 가장 최근데이터를 보낸다. 가장 최근 데이터를 먼저 넣는다.
// 	for (; it != _DataMap.end(); ++it) {
// 		SmChartDataItem item = it->second;
// 		std::string time = item.date + item.time;
// 		CString msg;
// 		msg.Format("send cycle data ::symbol = %s, dt = %s , o = %d, h = %d, l= %d, c = %d\n", _SymbolCode.c_str(), time.c_str(), item.o, item.h, item.l, item.c);
// 		//TRACE(msg);
// 		std::string date_time = VtStringUtil::GetLocalTimeByDatetimeString(time);
// 		send_object["data"][k++] = {
// 			{ "date_time",  date_time },
// 			{ "high", item.h },
// 			{ "low",  item.l },
// 			{ "open",  item.o },
// 			{ "close",  item.c },
// 			{ "volume",  item.v }
// 		};
// 		if (k == _CycleDataSize)
// 			break;
// 	}
// 
// 	std::string content = send_object.dump(4);
	
}

SmChartDataItem SmChartData::FindMinuteData(std::string hour_min, int count)
{
	SmChartDataItem item;
	// 수집된 데이터를 돌면서 차트 데이터를 만든다.
	auto it = _DataMap.find(hour_min);
	if (it != _DataMap.end()) {
		SmChartDataItem& temp_item = it->second;
		int cur_count = 0;
		// 시가가 설정되어 있는지 여부
		bool open_set = false;
		for (auto it_item = it; it_item != _DataMap.end(); ++it_item) {
			temp_item = it_item->second;
			// 시가가 설정되어 있지 않고 시가가 0이 아니라면 시가를 설정한다.
			if (!open_set && temp_item.o != 0) { // 시가
				item.o = temp_item.o;
				// 시가 설정됨
				open_set = true;
			}
			// 종가는 지속적으로 업데이트 해준다.
			if (temp_item.c != 0) { // 종가
				item.c = temp_item.c;
			}

			// 고가가 설정되어 있지 않으면 
			if (item.h == 0)
				item.h = temp_item.h;
			else {
				if (temp_item.h > item.h)
					item.h = temp_item.h;
			}

			// 저가가 설정되어 있지 않으면
			if (item.l == 0)
				item.l = temp_item.l;
			else {
				if (temp_item.l < item.l)
					item.l = temp_item.l;
			}


			// 거래량 합산
			item.v += temp_item.v;

			cur_count++;

			// 현재 카운트가 요청한 값과 같으면 루프를 빠져나간다.
			if (cur_count == count)
				break;
		}
	}
	return item;
}

std::pair<int, int> SmChartData::GetCycleByTimeDif()
{
	return std::make_pair(0, 0);
}

void SmChartData::OnChartDataUpdated()
{
	int k = 0;
	CString msg;
	for (auto it = _DataMap.rbegin(); it != _DataMap.rend(); ++it) {
		SmChartDataItem item = it->second;
		msg.Format(_T(">>>>>>>>>>>>>>>>>>> size = %d, code = %s, date = %s, time = %s, o = %d, h = %d, l = %d, c = %d, v = %d\n"), _DataMap.size(), SymbolCode().c_str(), item.date.c_str(), item.time.c_str(), item.o, item.h, item.l, item.c, item.v);
		//TRACE(msg);

		k++;

		if (k == _CycleDataSize)
			break;
	}
	// 여기서 새로운 데이터를 보낸다.
	SendCyclicChartDataToUsers();
}

void SmChartData::PushChartDataItemToBack(SmChartDataItem data)
{
	CString msg;
	

}

void SmChartData::PushChartDataItemToFront(SmChartDataItem data)
{
	CString msg;


	
}

void SmChartData::UpdateChartData(SmChartDataItem data)
{
	
}

void SmChartData::UpdateChartData(std::string time, int close, int vol)
{
	auto it = _DataMap.find(time);
	if (it == _DataMap.end()) {
		return;
	}

	SmChartDataItem& item = it->second;
	item.v += vol;
	// 시작값이 수집되지 않았으면 수집을 한다.
	if (item.o == 0) {
		item.o = close;
	}
	// 종가를 수집한다.
	item.c = close;
	// 고가가 수집되지 않았다면 수집을 한다.
	if (item.h == 0)
		item.h = close;
	else {
		// 이미 고가가 수집되어 있다면 수집된 값이 현재 고가 보다 크다면 교체해 준다.
		if (close > item.h)
			item.h = close;
	}

	// 저가가 수집되지 않았다면 수집을 한다.
	if (item.l == 0)
		item.l = close;
	else {
		// 이미 저가가 수집되었다면 이전 저가보다 작다면 저가를 교체해 준다.
		if (close < item.l)
			item.l = close;
	}
}

void SmChartData::AddChartData(SmChartDataItem&& data)
{
	std::string date_time;
	date_time.append(data.date);
	date_time.append(data.time);
	_DataMap[date_time] = data;

	// 일정한 갯수가 넘어가면 이전 데이터는 제거해 준다.
	if (_DataMap.size() > 3) {
		auto it = _DataMap.begin();
		_DataMap.erase(it);
	}
}

void SmChartData::UpdateTickData(size_t index, std::string time, int close, int vol)
{
	// 수집 범위를 벗어나면 수집하지 않는다.
	if (index >= _DataVector.size() || index < 0)
		return;

	SmChartDataItem& item = _DataVector[index];
	item.v += vol;
	// 시작값이 수집되지 않았으면 수집을 한다.
	if (item.o == 0) {
		item.o = close;
	}
	// 종가를 수집한다.
	item.c = close;
	// 고가가 수집되지 않았다면 수집을 한다.
	if (item.h == 0)
		item.h = close;
	else {
		// 이미 고가가 수집되어 있다면 수집된 값이 현재 고가 보다 크다면 교체해 준다.
		if (close > item.h)
			item.h = close;
	}

	// 저가가 수집되지 않았다면 수집을 한다.
	if (item.l == 0)
		item.l = close;
	else {
		// 이미 저가가 수집되었다면 이전 저가보다 작다면 저가를 교체해 준다.
		if (close < item.l)
			item.l = close;
	}
}

void SmChartData::RemoveUser(std::string user_id)
{
	auto it = _UserList.find(user_id);
	if (it != _UserList.end()) {
		_UserList.erase(it);
	}
}

void SmChartData::OnTimer()
{
	GetCyclicDataFromServer();
}

void SmChartData::InitTimeTable()
{
	for (int i = 0; i < 24; ++i) {
		for (int j = 0; j < 60; ++j) {
			std::string time_key = fmt::format("{0:0>2}{1:0>2}", i, j);
			SmChartDataItem item;
			_DataMap[time_key] = item;
		}
	}
}
