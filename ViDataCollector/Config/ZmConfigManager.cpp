#include "pch.h"
#include "ZmConfigManager.h"
#include "IniFile.h"



void ZmConfigManager::Begin()
{
	
}

void ZmConfigManager::End()
{

}

ZmConfigManager::ZmConfigManager()
{
	_filename = GetIniPath();
}


ZmConfigManager::~ZmConfigManager()
{
	
}


std::string ZmConfigManager::getString(const std::string &section, const std::string &name)
{
	CIniReader iniReader(_filename.c_str());

	return iniReader.ReadString(section.c_str(), name.c_str(), _T(""));
}

int ZmConfigManager::getInt(const std::string &section, const std::string &name)
{
	CIniReader iniReader(_filename.c_str());
	return iniReader.ReadInteger(section.c_str(), name.c_str(), 0);
}

bool ZmConfigManager::getBool(const std::string &section, const std::string &name)
{
	CIniReader iniReader(_filename.c_str());
	return iniReader.ReadBoolean(section.c_str(), name.c_str(), 0);
}

float ZmConfigManager::getFloat(const std::string &section, const std::string &name)
{
	CIniReader iniReader(_filename.c_str());
	return iniReader.ReadFloat(section.c_str(), name.c_str(), 0);
}

void ZmConfigManager::setString(const std::string &section, const std::string &name, std::string& value)
{
	CIniWriter iniWriter(_filename.c_str());
	iniWriter.WriteString(section.c_str(), name.c_str(), value.c_str());
}

void ZmConfigManager::setInteger(const std::string &section, const std::string &name, int& value)
{
	CIniWriter iniWriter(_filename.c_str());
	iniWriter.WriteInteger(section.c_str(), name.c_str(), value);
}

void ZmConfigManager::setBool(const std::string &section, const std::string &name, bool& value)
{
	CIniWriter iniWriter(_filename.c_str());
	iniWriter.WriteBoolean(section.c_str(), name.c_str(), value);
}

void ZmConfigManager::setFloat(const std::string &section, const std::string &name, float& value)
{
	CIniWriter iniWriter(_filename.c_str());
	iniWriter.WriteFloat(section.c_str(), name.c_str(), value);
}

std::string ZmConfigManager::GetAppPath()
{
	TCHAR path[1024];
	std::string fullPath;
	int n = GetModuleFileName(0, path, sizeof(path) / sizeof(path[0]));
	if (n > 0) {
		fullPath = path;

		size_t pos = fullPath.rfind('\\');
		if (pos != std::string::npos) {
			fullPath = fullPath.substr(0, pos);
		}
	}
	else throw _T("Cannot get application file name.");

	return fullPath;
}

std::string ZmConfigManager::GetIniPath()
{
	TCHAR path[1024];
	std::string fullPath;
	int n = GetModuleFileName(0, path, sizeof(path) / sizeof(path[0]));
	if (n > 0) {
		fullPath = path;

		size_t pos = fullPath.rfind('.');
		if (pos != std::string::npos) {
			fullPath = fullPath.substr(0, pos + 1);
			fullPath += "ini";
		}
	}
	else throw _T("Cannot get application file name.");

	return fullPath;
}

