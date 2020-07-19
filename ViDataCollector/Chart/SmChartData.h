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
	// ��Ʈ�����͸� �̹� �޾����� ǥ���Ѵ�.
	bool _Received = false;
	std::string _SymbolCode;
	SmChartType _ChartType = SmChartType::MIN;
	int _Cycle = 0;
	// �ֽŵ����Ͱ� �� �տ� �´�. 
	// ���� �ε��� 0�� ���� �ֽ� �������̴�.
	std::map<std::string, SmChartDataItem> _DataMap;

	// ƽ������ ���� ����
	// ƽ���� 0�� ���� ���� �������̰� ���� ������ ���� �ֽŵ������̴�.
	// ���� �ε��� 0�� ���� �ֽ� �������̴�.
	// ������ �ε����� �׳� ��Ʈ�� �ε����̴�.
	std::vector<SmChartDataItem> _DataVector;

	// ��Ʈ�� ��û�ϴ� ����� ���̵� ���
	std::set<std::string> _UserList;
	void GetChartDataFromDB();
	void GetChartDataFromServer();
	void GetCyclicDataFromServer();
	size_t _DataQueueSize = ChartDataSize;
	size_t _CycleDataSize = 3;
	// ��ϵ� ����ڵ鿡�� ��Ʈ ���� �����͸� �����ش�.
	void SendCyclicChartDataToUsers();
	
public:
	void Reset() {
		for (auto it = _DataMap.begin(); it != _DataMap.end(); ++it) {
			SmChartDataItem& item = it->second;
			item.Reset();
		}
	}
	// ��Ʈ �����Ϳ��� �ش� ���� ��Ʈ������ �������� �����´�.
	// �Է� ������ �ø� ����Ű�� ���ڸ� ���ڿ��� ���� ����Ű�� ���ڸ� ���ڿ��̴�.
	// ���� ��� 9�� 9���̸� "0909"�̴�
	// count�� ã�� �ε������� ����� ������ ���ΰ��� ��Ÿ����.
	// count �� 5�̸� ���� ã�� �ε������� 5���� ���ļ� ��ȯ�Ѵ�.
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
	// ���ð�, ����Ŭ
	std::pair<int, int> GetCycleByTimeDif();
	// ��Ʈ �����Ͱ� ���� ���������� �˸���.
	void OnChartDataUpdated();
	void PushChartDataItemToBack(SmChartDataItem data);
	void PushChartDataItemToFront(SmChartDataItem data);
	void UpdateChartData(SmChartDataItem data);
	// �к������͸� ������Ʈ �Ѵ�.
	void UpdateChartData(std::string time, int close, int vol);
	// ƽ�����͸� ������Ʈ �Ѵ�.
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
	// Ÿ�̸Ӱ� �Ҹ��� ȣ�� �Ǵ� �Լ�
	/// <summary>
	/// Ÿ�̸Ӱ� �Ҹ� �� ����� ����� �����Ͽ� ��Ʈ �����͸� �����Ͽ� Ŭ���̾�Ʈ���� �����Ѵ�.
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
	// ������ ������ ���� �ð�ǥ�� �ʱ�ȭ �Ѵ�.
	void InitTimeTable();
};

