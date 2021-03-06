#pragma once

#include <ctime>
#include <string>



class VtTimeUtil
{
public:

	VtTimeUtil()
	{
	}

	virtual ~VtTimeUtil()
	{
	}

	static struct tm Now()
	{
		time_t timer;
		struct tm t;

		timer = time(NULL); 
		localtime_s(&t, &timer);

		return t;
	}

	static std::string GetDateTimeString()
	{
// 		LocalDateTime now;
// 		std::string curDate(DateTimeFormatter::format(now, "%Y%n%e"));
		std::string curDate;
		return curDate;
	}

	static std::string GetDate(char* src)
	{
		std::string date;
		char buff[16];
		memset(buff, 0x00, sizeof(buff));
		memcpy(buff, src, 4);
		date.append(buff);
		date.append(_T("��"));
		memset(buff, 0x00, sizeof(buff));
		memcpy(buff, src + 4, 2);
		date.append(buff);
		date.append(_T("��"));
		memset(buff, 0x00, sizeof(buff));
		memcpy(buff, src + 6, 2);
		date.append(buff);
		date.append(_T("��"));
		return date;
	}
};

