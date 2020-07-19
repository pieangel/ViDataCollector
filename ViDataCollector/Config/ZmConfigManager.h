#pragma once

#include "../Global/TemplateSingleton.h"
#include <string>
#include <map>


class ZmConfigManager : public TemplateSingleton<ZmConfigManager>
{
public:
	void Begin();
	void End();
	ZmConfigManager();
	~ZmConfigManager();
	std::string getString(const std::string &section, const std::string& name);
	int getInt(const std::string &section, const std::string& name);
	bool getBool(const std::string &section, const std::string& name);
	float getFloat(const std::string &section, const std::string& name);

	void setString(const std::string &section, const std::string &name, std::string& value);
	void setInteger(const std::string &section, const std::string &name, int& value);
	void setBool(const std::string &section, const std::string &name, bool& value);
	void setFloat(const std::string &section, const std::string &name, float& value);
	std::string GetAppPath();
	std::string GetIniPath();
private:
	std::string _filename;
};

