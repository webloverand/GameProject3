﻿#ifndef __MAIL_MODULE_H__
#define __MAIL_MODULE_H__
#include "ModuleBase.h"
#include "../ServerData/MailData.h"
#include "../ServerData/ServerDefine.h"

struct MailDataObject;
class CMailModule  : public CModuleBase
{
public:
	CMailModule(CPlayerObject* pOwner);

	~CMailModule();

public:
	BOOL OnCreate(UINT64 u64RoleID);

	BOOL OnDestroy();

	BOOL OnLogin();

	BOOL OnLogout();

	BOOL OnNewDay();

	BOOL ReadFromDBLoginData(DBRoleLoginAck& Ack);

	BOOL SaveToClientLoginData(RoleLoginAck& Ack);

	BOOL CalcFightValue(INT32 nValue[PROPERTY_NUM], INT32 nPercent[PROPERTY_NUM], INT32& FightValue);

public:
	BOOL AddMail(MailDataObject* pMail);

	BOOL DeleteMail(UINT64 uGuid);

	BOOL SendMail(std::string strSender, std::string strTitle, std::string strContent);

	MailDataObject* GetMailByGuid(UINT64 uGuid);

	BOOL NotifyChange();
public:
	std::map<UINT64, MailDataObject*> m_mapMailData;

	std::set<UINT64> m_setChange;
	std::set<UINT64> m_setRemove;
};

#endif //__MAIL_MODULE_H__
