#pragma once
#include <string>
#include "SmChartDefine.h"
#include <vector>
#include <set>
#include <list>
#include <map>
class SmChartData
{
private:
	// 차트데이터를 이미 받았음을 표시한다.
	bool _Received = false;
	std::string _SymbolCode;
	SmChartType _ChartType = SmChartType::MIN;
	int _Cycle = 0;
	// 최신데이터가 맨 앞에 온다. 
	// 따라서 인덱스 0이 가장 최신 데이터이다.
	std::map<std::string, SmChartDataItem> _DataMap;

	// 틱데이터 수집 벡터
	// 틱봉은 0이 제일 과거 데이터이고 가장 마지막 봉이 최신데이터이다.
	// 따라서 인덱스 0이 가장 최신 데이터이다.
	// 벡터의 인덱스가 그날 차트의 인덱스이다.
	std::vector<SmChartDataItem> _DataVector;

	// 차트를 요청하는 사용자 아이디 목록
	std::set<std::string> _UserList;
	void GetChartDataFromDB();
	void GetChartDataFromServer();
	void GetCyclicDataFromServer();
	size_t _DataQueueSize = ChartDataSize;
	size_t _CycleDataSize = 3;
	// 등록된 사용자들에게 차트 정기 데이터를 보내준다.
	void SendCyclicChartDataToUsers();
	
public:
	void Reset() {
		for (auto it = _DataMap.begin(); it != _DataMap.end(); ++it) {
			SmChartDataItem& item = it->second;
			item.Reset();
		}
	}
	// 차트 데이터에서 해당 분의 차트데이터 아이템을 가져온다.
	// 입력 변수는 시를 가리키는 두자리 문자열과 분을 가리키는 두자리 문자열이다.
	// 예를 들면 9시 9분이면 "0909"이다
	// count는 찾은 인덱스에서 몇개까지 가져올 것인가를 나타낸다.
	// count 가 5이면 현재 찾은 인덱스에서 5개를 합쳐서 반환한다.
	SmChartDataItem FindMinuteData(std::string hour_min, int count = 0);
	static std::string MakeDataKey(std::string symbol_code, int chart_type, int cycle) {
		std::string key = symbol_code;
		key.append(":");
		key.append(std::to_string(chart_type));
		key.append(":");
		key.append(std::to_string(cycle));
		return key;
	}
	std::map<std::string, SmChartDataItem>& GetDataItemList() {
		return _DataMap;
	}
	size_t GetChartDataCount() {
		return _DataMap.size();
	}
	// 대기시간, 사이클
	std::pair<int, int> GetCycleByTimeDif();
	// 차트 데이터가 새로 도착했음을 알린다.
	void OnChartDataUpdated();
	void PushChartDataItemToBack(SmChartDataItem data);
	void PushChartDataItemToFront(SmChartDataItem data);
	void UpdateChartData(SmChartDataItem data);
	// 분봉데이터를 업데이트 한다.
	void UpdateChartData(std::string time, int close, int vol);
	// 틱데이터를 업데이트 한다.
	void UpdateTickData(size_t index, std::string time, int close, int vol);
	size_t GetUserCount() {
		return _UserList.size();
	}
	void RemoveUser(std::string user_id);
	void AddUser(std::string user_id) {
		if (user_id.length() > 0)
			_UserList.insert(user_id);
	}
	std::string SymbolCode() const { return _SymbolCode; }
	void SymbolCode(std::string val) { _SymbolCode = val; }
	SmChartType ChartType() const { return _ChartType; }
	void ChartType(SmChartType val) { _ChartType = val; }
	int Cycle() const { return _Cycle; }
	void Cycle(int val) { _Cycle = val; }
	// 타이머가 불릴때 호출 되는 함수
	/// <summary>
	/// 타이머가 불릴 때 사용자 목록을 참조하여 차트 데이터를 조작하여 클라이언트에게 전송한다.
	/// </summary>
	void OnTimer();
	std::string GetDataKey() {
		std::string key = _SymbolCode;
		key.append(":");
		key.append(std::to_string((int)_ChartType));
		key.append(":");
		key.append(std::to_string(_Cycle));
		return key;
	}
	size_t DataQueueSize() const { return _DataQueueSize; }
	void DataQueueSize(int val) { _DataQueueSize = val; }
	size_t CycleDataSize() const { return _CycleDataSize; }
	void CycleDataSize(size_t val) { _CycleDataSize = val; }
	bool Received() const { return _Received; }
	void Received(bool val) { _Received = val; }
	// 데이터 수집을 위한 시간표를 초기화 한다.
	void InitTimeTable();
};

