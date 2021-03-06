#pragma once
#include "../Global/TemplateSingleton.h"
#include <string>
#include <set>
#include <queue>
#include <map>
class SmSymbolReader : public TemplateSingleton<SmSymbolReader>
{
public:
	SmSymbolReader();
	~SmSymbolReader();

public:
	std::string GetWorkingDir();
	void ReadSymbolFromFile(int index, std::string fullPath);
	std::set<std::string> DomesticSymbolMasterFileSet;
	std::set<std::string> ProductSet;
	void ReadMarketFile();
	void ReadPmFile();
	void ReadJmFile();
private:
	void InitProductSet();
	void ReadMarketFile(std::string fullPath);
	void ReadPmFile(std::string fullPath);
	void ReadJmFile(std::string fullPath);
	
	void ReadKospiFutureFile(std::string fullPath);
	void ReadKospiOptionFile(std::string fullPath);
	void ReadKospiWeeklyOptionFile(std::string fullPath);
	void ReadKosdaqFutureFile(std::string fullPath);
	void ReadMiniKospiFutureFile(std::string fullPath);
	void ReadCommodityFutureFile(std::string fullPath);
	void ReadKospiFutureInfo(std::string fullPath);
	void ReadKospiOptionInfo(std::string fullPath);
	void ReadUsDollarFutureInfo(std::string fullPath);
	std::set<std::string> _DomesticList;
};

