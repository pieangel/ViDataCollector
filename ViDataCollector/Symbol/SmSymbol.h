#pragma once
#include <string>
#include <list>
#include "../Quote/SmQuoteDefine.h"
#include "../Hoga/SmHogaDefine.h"
#include "../Chart/SmChartDefine.h"
#include <mutex>
#include <map>
class SmSymbol
{
public:
	SmSymbol();
	~SmSymbol();
	std::string SymbolCode() const { return _SymbolCode; }
	void SymbolCode(std::string val) { _SymbolCode = val; }
	std::string Name() const { return _Name; }
	void Name(std::string val) { _Name = val; }
	std::string NameEn() const { return _NameEn; }
	void NameEn(std::string val) { _NameEn = val; }
	SmQuote Quote;
	SmHoga  Hoga;
	std::string GetQuoteByJson();
	std::string GetHogaByJson();
	int Decimal() const { return _Decimal; }
	void Decimal(int val) { _Decimal = val; }
	int Seungsu() const { return _Seungsu; }
	void Seungsu(int val) { _Seungsu = val; }
	std::string ProductCode() const { return _ProductCode; }
	void ProductCode(std::string val) { _ProductCode = val; }
	std::string MarketName() const { return _MarketName; }
	void MarketName(std::string val) { _MarketName = val; }
	double CtrUnit() const { return _CtrUnit; }
	void CtrUnit(double val) { _CtrUnit = val; }
	double TickValue() const { return _TickValue; }
	void TickValue(double val) { _TickValue = val; }
	double TickSize() const { return _TickSize; }
	void TickSize(double val) { _TickSize = val; }
	int Index() const { return _Index; }
	void Index(int val) { _Index = val; }
	int Atm() const { return _Atm; }
	void Atm(int val) { _Atm = val; }
	int NearMonth() const { return _NearMonth; }
	void NearMonth(int val) { _NearMonth = val; }
	std::string LastDate() const { return _LastDate; }
	void LastDate(std::string val) { _LastDate = val; }
	std::string hour_min = "9999";
	int AccAmount() const { return _AccAmount; }
	void AccAmount(int val) { _AccAmount = val; }

	int StartHour() const { return _StartHour; }
	void StartHour(int val) { _StartHour = val; }
	int StartMin() const { return _StartMin; }
	void StartMin(int val) { _StartMin = val; }
	int StartSecond() const { return _StartSecond; }
	void StartSecond(int val) { _StartSecond = val; }
	int EndHour() const { return _EndHour; }
	void EndHour(int val) { _EndHour = val; }
	int EndMin() const { return _EndMin; }
	void EndMin(int val) { _EndMin = val; }
	int EndSecond() const { return _EndSecond; }
	void EndSecond(int val) { _EndSecond = val; }

	void MakeCurrChartDataByTimer(std::string cur_hour_min);
	void MakePrevChartDataByTimer(std::string cur_hour_min);

private:
	std::mutex _mutex;
	// ���� �ŷ���
	int _AccAmount;

	/* ATM���� 1:ATM, 2:ITM, 3:OTM					*/
	int _Atm = 0; // 
	// ǰ�񿡼� �����ϴ� �ε���
	int _Index = 0;
	/// <summary>
	/// ���� �ڵ� - ������ �����ϴ� Ű�� �ȴ�.
	/// </summary>
	std::string _SymbolCode;
	/// <summary>
	/// ���� �̸�
	/// </summary>
	std::string _Name;
	/// <summary>
	/// ���� ���� �̸�
	/// </summary>
	std::string _NameEn;
	// �Ҽ��� �ڸ���
	int _Decimal = 0;
	// �ŷ� �¼�
	int _Seungsu = 0;
	// ������
	double _CtrUnit = 0.0;
	// ƽ ��ġ  = ȣ�� ���� * ������
	double _TickValue = 0.0;
	// ƽ ũ�� - ȣ�� ����
	double _TickSize = 0.0;
	// ī���� �ڵ�
	std::string _ProductCode;
	// ���� �̸�
	std::string _MarketName;
	// �ٿ���
	int _NearMonth = 0;
	// ���� �ŷ���
	std::string _LastDate;


	int _StartHour = 9;
	int _StartMin = 0;
	int _StartSecond = 0;

	int _EndHour = 15;
	int _EndMin = 45;
	int _EndSecond = 0;

	// �е����� �� Ű : �ð������� 4�ڸ� Ű, ���� ��,��,��,��, �ŷ����� ����ִ� ��Ʈ ������
	std::map<std::string, SmChartDataItem> _MinDataMap;

	// 120ƽ ī��Ʈ
	int tick_count_120 = -1;
	int tick_count_300 = -1;
	std::string last_tick_time_120 = "";
	std::string last_tick_time_300 = "";

	void MakePrevChartData(int total_min_diff, std::string symbol_code, std::string prev_hour_min, std::string chart_hour_min, int cycle);
	// ����Ŭ �����͸� ������ �����Ѵ�.
	void SendCycleChartData(SmChartDataItem item);
};

