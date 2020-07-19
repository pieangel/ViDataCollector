// xNetCardInfo.h: interface for the CxNetCardInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XNETCARDINFO_H__FC408BC6_3516_4481_AF7E_0B875C0E2B2C__INCLUDED_)
#define AFX_XNETCARDINFO_H__FC408BC6_3516_4481_AF7E_0B875C0E2B2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CxNetCardInfo  
{
public:
	CxNetCardInfo();
	virtual ~CxNetCardInfo();

private:
	void ParseData();
	void GetInfo();

public:
	CString GetErrorMsg();
	CString GetNetCardWINS();
	CString GetNetCardDeviceName();
	CString GetNetCardMACAddress();
	CString GetDHCPServer();
	CString GetNetCardGateWay();
	CString GetNetCardSubnetMask();
	CString GetNetCardIPAddress();
	CString GetNetCardType();

private:
	BYTE m_data[4096];
	CString ErrMsg;
	CString macaddress;
	CString description;
	CString type;
	CString subnet;
	CString IpAddress;
	CString gateway;
	CString PrimaryWinsServer;
	CString dhcp;

	unsigned long len;
	PIP_ADAPTER_INFO pinfo;
};

#endif // !defined(AFX_XNETCARDINFO_H__FC408BC6_3516_4481_AF7E_0B875C0E2B2C__INCLUDED_)
