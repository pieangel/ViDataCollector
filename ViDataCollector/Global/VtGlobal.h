#pragma once
#include <vector>
#include <map>
#include <string>
#include <tuple>
#include <list>
#include "../Global/TemplateSingleton.h"
#include "VtDefine.h"
#include <ctime>

struct VtSysLog {
	std::string LogTime;
	int ErrorCode;
	std::string LogText;
};

class SmSymbolSelector;
class SmSymbol;
class cWaitDialog;
class VtAccount;
class VtStrategyToolWnd;
class VtGlobal : public TemplateSingleton<VtGlobal>
{
public:
	static int CenterWndYPos;
	VtGlobal();
	~VtGlobal();

	void OpenWaitDialog(CString msg);
	void OpenWaitDialog();
	void CloseWaitDialog();
	void OpenWaitDialog(int state);
	void CloseWaitDialog(int state);


	SmSymbolSelector* GetSymSelector(CWnd* wnd);
	void HideSymSelector();
	std::vector<SmSymbol*> FavoriteSymbolList;
	void InitFavorite();
	void AddSymbol(SmSymbol* sym);
	void RemoveSymbol(SmSymbol* sym);
	void ClearSymbol();
	std::map<std::string, std::string> FavoriteDefaultSymbols;

	std::string vcName;
	std::string vcTime;
	int vcNameIndex;
	//std::string DefaultAccountNo;
	VtServerType ServerType() const { return _ServerType; }
	void ServerType(VtServerType val) { 
		_ServerType = val; 
	}

	void InitStressList();
	void InitBandList();
	void InitSystemList();
	void InitIndexList();
	COLORREF ColorTable[45];
	
	std::string SelProduct() const { return _SelProduct; }
	void SelProduct(std::string val) { _SelProduct = val; }
	VtChartType SelType() const { return _SelType; }
	void SelType(VtChartType val) { _SelType = val; }
	int SelCycle() const { return _SelCycle; }
	void SelCycle(int val) { _SelCycle = val; }
	std::string SelExchange() const { return _SelExchange; }
	void SelExchange(std::string val) { _SelExchange = val; }
	VtExchangeName SeLExcIndex() const { return _SeLExcIndex; }
	void SeLExcIndex(VtExchangeName val) { _SeLExcIndex = val; }
	std::vector<std::string> ExchNameVector;
	std::vector<std::string> ExchAliasVector;

	static int DefaultChartDataCount;
	bool Waiting() const { return _Waiting; }
	void Waiting(bool val) { _Waiting = val; }
	std::vector<VtSystemTemplate> SystemList;
	static COLORREF GridTitleBackColor;
	static COLORREF GridTitleTextColor;
	static COLORREF SelDialogBackColor;
	static COLORREF SelCellBackColor;
	static COLORREF MainBackColor;
	static COLORREF MainTextColor;
// 	static COLORREF CallBackColor;
// 	static COLORREF CallRemainGrayColor;
// 	static COLORREF CallRemainEmptyColor;
// 	static COLORREF CallRemainGrayColor;
	static std::pair<int, int> GetScaleFact();
	static int GetHorWidthByScaleFactor(int width);
	static int GetVerHeightByScaleFactor(int height);
	static VtTime GetTime(int time);
	static VtDate GetDate(int date);
	static VtTime GetLocalTime();
	static VtDate GetLocalDate();
	static int GetDate(VtDate date);
	static int GetTime(VtTime time);
	static std::string LoginUserID;
	static std::string GetDateTime();
	
	/// <summary>
	/// 영업 시작시간
	/// </summary>
	static VtTime OpenTime;
	/// <summary>
	/// 영업 종료 시간
	/// </summary>
	static VtTime CloseTime;
	static std::string FileWatchPath;
	static bool EnableFileWatch;
	static VtStrategyToolWnd* StrategyToolWnd;
	static void PushLog(VtSysLog&& log);
	static std::list<VtSysLog>& GetSysLogList() {
		return _SysLogList;
	}
	static int ServerSleepTime;
	static bool SiseHogaEventEnable;

	static CString GetMacAddress();
private:

	VtExchangeName _SeLExcIndex;
	std::string _SelExchange;
	std::string _SelProduct;
	VtChartType _SelType;
	int         _SelCycle;

	SmSymbolSelector* _SymSelector = nullptr;
	SmSymbol* FindSymbol(SmSymbol* sym);

	cWaitDialog* _WaitDlg = nullptr;
	bool _Waiting = false;
	VtServerType _ServerType;
	static std::list<VtSysLog> _SysLogList;
	static size_t _MaxLog;
};

