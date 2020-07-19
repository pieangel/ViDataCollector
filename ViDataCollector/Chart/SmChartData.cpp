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
// 	msg.Format("��Ʈ������ ������Ʈ �� %d\n", 0);
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
// 	// ���� �ֱٵ����͸� ������. ���� �ֱ� �����͸� ���� �ִ´�.
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
	// ������ �����͸� ���鼭 ��Ʈ �����͸� �����.
	auto it = _DataMap.find(hour_min);
	if (it != _DataMap.end()) {
		SmChartDataItem& temp_item = it->second;
		int cur_count = 0;
		// �ð��� �����Ǿ� �ִ��� ����
		bool open_set = false;
		for (auto it_item = it; it_item != _DataMap.end(); ++it_item) {
			temp_item = it_item->second;
			// �ð��� �����Ǿ� ���� �ʰ� �ð��� 0�� �ƴ϶�� �ð��� �����Ѵ�.
			if (!open_set && temp_item.o != 0) { // �ð�
				item.o = temp_item.o;
				// �ð� ������
				open_set = true;
			}
			// ������ ���������� ������Ʈ ���ش�.
			if (temp_item.c != 0) { // ����
				item.c = temp_item.c;
			}

			// ���� �����Ǿ� ���� ������ 
			if (item.h == 0)
				item.h = temp_item.h;
			else {
				if (temp_item.h > item.h)
					item.h = temp_item.h;
			}

			// ������ �����Ǿ� ���� ������
			if (item.l == 0)
				item.l = temp_item.l;
			else {
				if (temp_item.l < item.l)
					item.l = temp_item.l;
			}


			// �ŷ��� �ջ�
			item.v += temp_item.v;

			cur_count++;

			// ���� ī��Ʈ�� ��û�� ���� ������ ������ ����������.
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
	// ���⼭ ���ο� �����͸� ������.
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
	// ���۰��� �������� �ʾ����� ������ �Ѵ�.
	if (item.o == 0) {
		item.o = close;
	}
	// ������ �����Ѵ�.
	item.c = close;
	// ���� �������� �ʾҴٸ� ������ �Ѵ�.
	if (item.h == 0)
		item.h = close;
	else {
		// �̹� ���� �����Ǿ� �ִٸ� ������ ���� ���� �� ���� ũ�ٸ� ��ü�� �ش�.
		if (close > item.h)
			item.h = close;
	}

	// ������ �������� �ʾҴٸ� ������ �Ѵ�.
	if (item.l == 0)
		item.l = close;
	else {
		// �̹� ������ �����Ǿ��ٸ� ���� �������� �۴ٸ� ������ ��ü�� �ش�.
		if (close < item.l)
			item.l = close;
	}
}

void SmChartData::UpdateTickData(size_t index, std::string time, int close, int vol)
{
	// ���� ������ ����� �������� �ʴ´�.
	if (index >= _DataVector.size() || index < 0)
		return;

	SmChartDataItem& item = _DataVector[index];
	item.v += vol;
	// ���۰��� �������� �ʾ����� ������ �Ѵ�.
	if (item.o == 0) {
		item.o = close;
	}
	// ������ �����Ѵ�.
	item.c = close;
	// ���� �������� �ʾҴٸ� ������ �Ѵ�.
	if (item.h == 0)
		item.h = close;
	else {
		// �̹� ���� �����Ǿ� �ִٸ� ������ ���� ���� �� ���� ũ�ٸ� ��ü�� �ش�.
		if (close > item.h)
			item.h = close;
	}

	// ������ �������� �ʾҴٸ� ������ �Ѵ�.
	if (item.l == 0)
		item.l = close;
	else {
		// �̹� ������ �����Ǿ��ٸ� ���� �������� �۴ٸ� ������ ��ü�� �ش�.
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
