#pragma once
#include <string>
struct SmQuoteData {
	int command = 1; // 처리 명령 1 : 처리, 0 : 종료
	std::string symbol_code; // 심볼코드
	std::string time; // 시간
	std::string volume; // 수량
	std::string up_down; // 체결 구분
	std::string close; // 현재가
	std::string open; // 시가
	std::string high; // 고가
	std::string low; // 저가
	std::string to_preday; // 전일대비
	std::string up_down_rate; // 등락율
	std::string sign;
	int acc_vol = 0;
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