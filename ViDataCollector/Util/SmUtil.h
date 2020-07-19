#pragma once
#include <tuple>
#include <time.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <stdexcept>

enum STR2INT_ERROR { SM_SUCCESS, SM_OVERFLOW, SM_UNDERFLOW, SM_INCONVERTIBLE };

#define MAX_BUFFER 128

class SmUtil {
public:
	static std::tuple<int, int, int> GetLocalTime();
	static std::vector<int> GetLocalDate();
	static std::vector<int> GetTime(std::string datetime_string);
	static std::vector<int> GetLocalDateTime();
	static std::vector<int> GetUtcDateTime();
	static std::string GetUTCDateTimeString();
	static std::string GetUTCDateTimeStringForNowMin();
	static std::string GetUTCDateTimeStringForPreMin(int previousMinLen);
	static double GetDifTimeBySeconds(std::string newTime, std::string oldTime);
	static double GetDifTimeForNow(std::string srcTime);
	static std::string Format(const char* fmt, ...);
	static STR2INT_ERROR str2long(long& l, char const* s, int base = 0)
	{
		char* end = (char*)s;
		errno = 0;

		l = strtol(s, &end, base);

		if ((errno == ERANGE) && (l == LONG_MAX)) {
			return SM_OVERFLOW;
		}
		if ((errno == ERANGE) && (l == LONG_MIN)) {
			return SM_UNDERFLOW;
		}
		if ((errno != 0) || (s == end)) {
			return SM_INCONVERTIBLE;
		}
		while (isspace((unsigned char)*end)) {
			end++;
		}

		if (*s == '\0' || *end != '\0') {
			return SM_INCONVERTIBLE;
		}

		return SM_SUCCESS;
	}
};

