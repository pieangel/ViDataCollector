#pragma once
#include <string>
struct SmQuoteData {
	int command = 1; // ó�� ��� 1 : ó��, 0 : ����
	std::string symbol_code; // �ɺ��ڵ�
	std::string time; // �ð�
	std::string volume; // ����
	std::string up_down; // ü�� ����
	std::string close; // ���簡
	std::string open; // �ð�
	std::string high; // ��
	std::string low; // ����
	std::string to_preday; // ���ϴ��
	std::string up_down_rate; // �����
	std::string sign;
	std::string acc_vol;
	std::string local_date;
};

struct SmTickData {
	std::string symbol_code;
	int command = 1;
	std::string hourmin;
	std::string tick_time;
	std::string local_date;
	int close = 0;
	int volume = 0;
};