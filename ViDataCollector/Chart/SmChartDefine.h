#pragma once
#include <string>
#include "../Global/VtDefine.h"
enum class SmChartType
{
	NONE = 0,
	TICK,
	MIN,
	DAY,
	WEEK,
	MON,
	YEAR
};

enum class SmChartDataReqestType {
	FIRST = 0, // 최초 요구
	CYCLE // 주기 데이터 요구
};

struct SmSiseDataRequest {
	std::string user_id;
	std::string symbol_code;
};

struct SmHogaDataRequest {
	std::string user_id;
	std::string symbol_code;
};

struct SmSymbolMasterRequest {
	std::string user_id;
	std::string symbol_code;
};

struct SmChartDataRequest
{
	SmChartDataReqestType reqType = SmChartDataReqestType::FIRST;
	int command = 1;
	int service_req_id;
	int session_id;
	std::string chart_id;
	std::string user_id;
	std::string symbolCode;
	std::string product_code;
	SmChartType chartType;
	// 연속 조회에 사용하는 날짜와 시간 - 다음 데이터가 있을 때 연속조회 날짜와 시간을 요청에 넣어줘야 한다.
	// 연속조회에 사용하는 날짜
	std::string cont_date;
	// 연속조회에 사용하는 시간
	std::string cont_time;
	int rcvd_count = 0;
	int cycle = 0;
	int count = 0;
	// 다음 데이터 존재 여부 - 참이면 다음 데이터가 있다
	// 다음 데이터가 있으면 추가 요청을 해야 한다.
	int next = 0;
	int reqKey = 0;
	// 갭보정 0 : 사용안함, 1 : 사용함
	int seq = 0;
	// 서버와 현재 로컬과의 시간 차이
	int time_diff = -1;
	bool domestic = false;
	// 전체적으로 받은 갯수 - 차트 데이터가 한꺼번에 오지 않을때 사용
	int total_rcvd_count = 0;
	std::string GetDataKey() {
		std::string key = symbolCode;
		key.append(":");
		key.append(std::to_string((int)chartType));
		key.append(":");
		key.append(std::to_string(cycle));
		return key;
	}

	std::string GetDailyKey() {
		std::string key = product_code;
		key.append(":");
		key.append(std::to_string((int)chartType));
		key.append(":");
		key.append(std::to_string(cycle));
		return key;
	}
};

struct SmChartDataItem {
	std::string symbolCode;
	std::string product_code;
	SmChartType chartType;
	int cycle = 0;
	std::string date;
	std::string time;
	// 시간이 되었을 때 그 시간에 데이터가 없을 때는 
	// 이전봉의 종가가 현재 봉의 시고저종이 된다.
	// 이 값은 임시값으로 차트에 표시되며 
	// 실제 값이 왔을 때는 실제값으로 수정되어야 한다.
	// 이 플래그가 true 이면 임시로 만들어진 값으로 반드시 시가를 비롯한 모든 값이 수정되어야 한다.
	bool temp = false;

	int o = 0;
	int h = 0;
	int l = 0;
	int c = 0;
	int v = 0;
	std::string GetDataKey() {
		std::string key = symbolCode;
		key.append(":");
		key.append(std::to_string((int)chartType));
		key.append(":");
		key.append(std::to_string(cycle));
		return key;
	}

	std::string GetDailyKey() {
		std::string key = product_code;
		key.append(":");
		key.append(std::to_string((int)chartType));
		key.append(":");
		key.append(std::to_string(cycle));
		return key;
	}

	void Reset() {
		o = 0;
		h = 0;
		l = 0;
		c = 0;
		v = 0;
	}
};

struct SmSimpleChartDataItem {
	std::string date_time;
	std::string date;
	std::string time;
	int o = 0;
	int h = 0;
	int l = 0;
	int c = 0;
	int v = 0;
};

