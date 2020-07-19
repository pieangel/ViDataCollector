// xNetCardInfo.cpp: implementation of the CxNetCardInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "pch.h"
#include "xNetCardInfo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CxNetCardInfo::CxNetCardInfo()
{
	ErrMsg = _T( "" );

	macaddress = _T( "" );
	description = _T( "" );
	type = _T( "" );
	subnet = _T( "" );
	IpAddress = _T( "" );
	gateway = _T( "" );
	PrimaryWinsServer = _T( "" );
	dhcp = _T( "" );

	ZeroMemory( m_data,4096 );
	len = 0;
	pinfo = ( PIP_ADAPTER_INFO )m_data;

	GetInfo();
}

CxNetCardInfo::~CxNetCardInfo()
{

}

void CxNetCardInfo::GetInfo()
{
	ErrMsg = _T( "Success!" );

	unsigned long nError;

	nError = GetAdaptersInfo( pinfo,&len );
	switch( nError ) {
		case 0:
			ParseData();
			break;
		case ERROR_NO_DATA:
			ErrMsg = _T( "No net device information!" );
			break;
		case ERROR_NOT_SUPPORTED:
			ErrMsg = _T( "The system not support GetAdaptersInfo API function!" );
			break;
		case ERROR_BUFFER_OVERFLOW:
			nError = GetAdaptersInfo( pinfo,&len );
			if( nError == 0 ) ParseData();
			else ErrMsg = _T("Unknow error!");
			break;
	}
}

void CxNetCardInfo::ParseData()
{
	macaddress.Format( _T("%02X:%02X:%02X:%02X:%02X:%02X"),pinfo->Address[0],pinfo->Address[1],pinfo->Address[2],pinfo->Address[3],pinfo->Address[4],pinfo->Address[5] );
	description = pinfo->Description;
	type.Format(_T("%d"),pinfo->Type);

	PIP_ADDR_STRING pAddressList = &(pinfo->IpAddressList);
	IpAddress = _T("");
	do {
		IpAddress += pAddressList->IpAddress.String;
		pAddressList = pAddressList->Next;
		if( pAddressList != NULL ) IpAddress += _T( "\r\n" );
	}while( pAddressList != NULL );

	subnet.Format( _T("%s"),pinfo->IpAddressList.IpMask.String );
	gateway.Format( _T("%s"),pinfo->GatewayList.IpAddress.String );
	if( pinfo->HaveWins )
		PrimaryWinsServer.Format( _T("%s"),pinfo->PrimaryWinsServer.IpAddress.String );
	else
		PrimaryWinsServer.Format( _T("%s"),_T("N/A") );
	if( pinfo->DhcpEnabled )
		dhcp.Format( _T("%s"),pinfo->DhcpServer.IpAddress.String );
	else
		dhcp.Format( _T("%s"),_T("N/A") );
	pinfo = pinfo->Next;
}

CString CxNetCardInfo::GetNetCardType()
{
	return type;
}

CString CxNetCardInfo::GetNetCardIPAddress()
{
	return IpAddress;
}

CString CxNetCardInfo::GetNetCardSubnetMask()
{
	return subnet;
}

CString CxNetCardInfo::GetNetCardGateWay()
{
	return gateway;
}

CString CxNetCardInfo::GetDHCPServer()
{
	return dhcp;
}

CString CxNetCardInfo::GetNetCardMACAddress()
{
	return macaddress;
}

CString CxNetCardInfo::GetNetCardDeviceName()
{
	return description;
}

CString CxNetCardInfo::GetNetCardWINS()
{
	return PrimaryWinsServer;
}

CString CxNetCardInfo::GetErrorMsg()
{
	return ErrMsg;
}
