#pragma once
#include <string>
#include <vector>
class SmProduct;
class SmMarket
{
public:
	SmMarket();
	~SmMarket();
	std::string Name() const { return _Name; }
	void Name(std::string val) { _Name = val; }
	/// <summary>
	/// 품목을 추가한다.
	/// </summary>
	/// <param name="code"></param>
	/// <returns></returns>
	SmProduct* AddProduct(std::string code);
	SmProduct* FindProduct(std::string code);
	SmProduct* FindAddProduct(std::string code);
	std::vector<SmProduct*>& GetProductList() {
		return _CategoryList;
	}
	std::string MarketCode() const { return _MarketCode; }
	void MarketCode(std::string val) { _MarketCode = val; }
private:
	std::string _Name;
	std::string _MarketCode;
	std::vector<SmProduct*> _CategoryList;
};

