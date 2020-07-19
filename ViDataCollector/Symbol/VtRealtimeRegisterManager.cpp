#include "pch.h"
#include "VtRealtimeRegisterManager.h"
//#include "VtKrClient.h"
//#include "VtHogaManager.h"
//#include "VtQuoteManager.h"
#include "../Hoga/VtHoga.h"
#include "../Quote/VtQuote.h"
#include "../HdCtrl/HdClient.h"


VtRealtimeRegisterManager::VtRealtimeRegisterManager()
{
}


VtRealtimeRegisterManager::~VtRealtimeRegisterManager()
{
}

void VtRealtimeRegisterManager::AddAccount(std::string acnt)
{
	AccountMap[acnt] = acnt;
}

void VtRealtimeRegisterManager::AddProduct(std::string prdt)
{
	ProductMap[prdt] = prdt;
}

void VtRealtimeRegisterManager::RemoveAccount(std::string acnt)
{
	auto it = AccountMap.find(acnt);
	if (it != AccountMap.end())
	{
		AccountMap.erase(it);
	}
}

void VtRealtimeRegisterManager::RemoveProduct(std::string prdt)
{
	auto it = ProductMap.find(prdt);
	if (it != ProductMap.end())
	{
		ProductMap.erase(it);
	}
}

/*
void VtRealtimeRegisterManager::RegisterRecentProduct(std::string prdt)
{
	RecentProductMap[prdt] = prdt;
}

void VtRealtimeRegisterManager::UnregisterRecentProduct(std::string prdt)
{
	auto it = RecentProductMap.find(prdt);
	if (it != RecentProductMap.end())
	{
		RecentProductMap.erase(it);
	}
}
*/
void VtRealtimeRegisterManager::RegisterAccount(std::string acnt)
{
	auto it = _AccountMap.find(acnt);
	if (it != _AccountMap.end())
	{
		VtRegisterItem item = _AccountMap[acnt];
		item.RefCount++;
		_AccountMap[acnt] = item;
	}
	else
	{
// 		VtHdClient* client = VtHdClient::GetInstance();
// 		CString userId = client->GetUserId();
// 		if (userId.GetLength() > 0)
// 		{
// 			client->RegisterAccount(acnt.c_str());
// 			VtRegisterItem item;
// 			item.Name = acnt;
// 			item.RefCount = 1;
// 			_AccountMap[acnt] = item;
// 		}
	}
}

void VtRealtimeRegisterManager::RegisterProduct(std::string prdt, int type)
{
	HdClient* client = HdClient::GetInstance();
	client->RegisterProduct(prdt.c_str());
}

void VtRealtimeRegisterManager::UnregisterAccount(std::string acnt)
{
	auto it = _AccountMap.find(acnt);
	if (it != _AccountMap.end())
	{
		VtRegisterItem item = _AccountMap[acnt];
		item.RefCount--;
		if (item.RefCount == 0)
		{
// 			VtHdClient* client = VtHdClient::GetInstance();
// 			CString userId = client->GetUserId();
// 			if (userId.GetLength() > 0)
// 			{
// 				client->UnregisterAccount(acnt.c_str());
// 				_AccountMap.erase(it);
// 			}
		}
	}
}

void VtRealtimeRegisterManager::UnregisterProduct(std::string prdt, int type)
{
// 	VtHdClient* client = VtHdClient::GetInstance();
// 	client->UnregisterProduct(prdt.c_str(), type);
// 	client->UnregisterExpected(prdt.c_str());
}

void VtRealtimeRegisterManager::UnRegisterAll()
{
// 	VtKrClient* client = VtKrClient::GetInstance();
// 	for (auto it = AccountMap.begin(); it != AccountMap.end(); ++it)
// 	{
// 		std::string acntNo = it->second;
// 		client->UnRegisterAccountAutoUpdate(acntNo);
// 	}
// 
// 	AccountMap.clear();
// 
// 	for (auto it = ProductMap.begin(); it != ProductMap.end(); ++it)
// 	{
// 		std::string prdt = it->second;
// 		client->UnReisterProductAutoUpdate(prdt);
// 	}
// 
// 	ProductMap.clear();
}

void VtRealtimeRegisterManager::RegisterCurrent()
{
// 	VtHdClient* client = VtHdClient::GetInstance();
// 	client->RegisterCurrent();
}

void VtRealtimeRegisterManager::UnregisterCurrent()
{
// 	VtHdClient* client = VtHdClient::GetInstance();
// 	client->UnregisterCurrent();
}
