#include "pch.h"
#include "SmErrorHandler.h"
#include <string>

SmErrorHandler::SmErrorHandler()
{

}

SmErrorHandler::~SmErrorHandler()
{

}

void SmErrorHandler::ShowMessage(std::string msg)
{
	CString strMsg;
	strMsg.Format("%s\n", msg.c_str());
	TRACE(strMsg.Left(2248));
}
