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
	FIRST = 0, // ���� �䱸
	CYCLE // �ֱ� ������ �䱸
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
	// ���� ��ȸ�� ����ϴ� ��¥�� �ð� - ���� �����Ͱ� ���� �� ������ȸ ��¥�� �ð��� ��û�� �־���� �Ѵ�.
	// ������ȸ�� ����ϴ� ��¥
	std::string cont_date;
	// ������ȸ�� ����ϴ� �ð�
	std::string cont_time;
	int rcvd_count = 0;
	int cycle = 0;
	int count = 0;
	// ���� ������ ���� ���� - ���̸� ���� �����Ͱ� �ִ�
	// ���� �����Ͱ� ������ �߰� ��û�� �ؾ� �Ѵ�.
	int next = 0;
	int reqKey = 0;
	// ������ 0 : ������, 1 : �����
	int seq = 0;
	// ������ ���� ���ð��� �ð� ����
	int time_diff = -1;
	bool domestic = false;
	// ��ü������ ���� ���� - ��Ʈ �����Ͱ� �Ѳ����� ���� ������ ���
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

