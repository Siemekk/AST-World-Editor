#pragma once

#include "zcvob.h"
#include "zbuffer.h"
#include "zceventmessage.h"


class zCPlayerGroup;

enum  zTNetStreamReadMode
{

};

struct zTNetAddress
{
};

struct zTNetMessageHeader
{
	BYTE n0;
	BYTE n1;
	BYTE n2;
	BYTE n3;
	BYTE n4;
};

struct zTNetPacket
{

};

class zCNetMessage
{
	char size[0x1C];
	void zNetMessage(zTNetMessageHeader&)
	{
		XCALL(0x0045C070);
	};

	zCNetMessage(zTNetMessageHeader& hndl)
	{
		zNetMessage(hndl);
	};

	void zNetMessage(unsigned long const&,unsigned long)
	{
		XCALL(0x0045C140);
	};

	zCNetMessage(unsigned long const& _id,unsigned len)
	{
		zNetMessage(_id,len);
	};

	void CopyFrom(zCNetMessage*)
	{
		XCALL(0x0045C220);
	};

	void zNetMessage(zTNetPacket*)
	{
		XCALL(0x0045C270);
	};

	zCNetMessage(zTNetPacket* packet)
	{
		zNetMessage(packet);
	};

	void Init(void)
	{
		XCALL(0x0045C400);
	};

	void Send(void)
	{
		XCALL(0x0045C4A0);
	};

	void SetTimestamp(unsigned char)
	{
		XCALL(0x0045C5D0);
	};

	unsigned char GetTimestamp(void)
	{
		XCALL(0x0045C5F0);
	};

	void SetTarget(zCPlayerInfo*)
	{
		XCALL(0x0045C600);
	};

	void SetTarget(zCPlayerGroup*)
	{
		XCALL(0x0045C630);
	};

	void GetTarget(zCPlayerInfo*&,zCPlayerGroup*&)
	{
		XCALL(0x0045C660);
	};

	unsigned long Get(void*,unsigned long const&)
	{
		XCALL(0x0045C680);
	};

	void Add(void*,unsigned long)
	{
		XCALL(0x0045C780);
	};

	void AddCursorPtr(unsigned long)
	{
		XCALL(0x0045C890);
	};

	void Add(zSTRING const&)
	{
		XCALL(0x0045C8A0);
	};

	void Get(zSTRING&)
	{
		XCALL(0x0045C900);
	};

	int IsStream(void)
	{
		XCALL(0x0045CA80);
	};

	void SetStream(int)
	{
		XCALL(0x0045CA90);
	};

	void SetFileMessage(zFILE*,zFILE*)
	{
		XCALL(0x0045CAA0);
	};

	zFILE* GetFile(zFILE*&)
	{
		XCALL(0x0045CB30);
	};

	int IsFileMessage(void)
	{
		XCALL(0x0045CB70);
	};

	int IsMultiMessage(void)
	{
		XCALL(0x0045CB90);
	};

	void LogMessage(zFILE*,zSTRING const&)
	{
		XCALL(0x0045CBB0);
	};

	void SetLog(int)
	{
		XCALL(0x0045CF60);
	};

	zTNetMessageHeader* GetHeader(void)
	{
		XCALL(0x0045CF70);
	};

	unsigned char GetHeaderSize(void)
	{
		XCALL(0x0045CF80);
	};

	zCBuffer* GetBuffer(void)
	{
		XCALL(0x0045CF90);
	};

	unsigned char* GetCursorPtr(void)
	{
		XCALL(0x0045CFA0);
	};

	unsigned char* GetPtr(void)
	{
		XCALL(0x0045CFB0);
	};

	unsigned char* GetDataPtr(void)
	{
		XCALL(0x0045CFC0);
	};

	void ResetCursorPtr(void)
	{
		XCALL(0x0045CFD0);
	};

	void SetMode(zTBufferMode)
	{
		XCALL(0x0045CFF0);
	};

	unsigned long GetSize(void)
	{
		XCALL(0x0045D000);
	};

	unsigned long GetDataSize(void)
	{
		XCALL(0x0045D010);
	};

	unsigned long GetRestSize(void)
	{
		XCALL(0x0045D020);
	};

	unsigned long GetID(void)
	{
		XCALL(0x0045D030);
	};

	unsigned char GetSenderID(void)
	{
		XCALL(0x0045D040);
	};

	unsigned char GetFlags(void)
	{
		XCALL(0x0045D050);
	};

	bool HasError(void)const 
	{
		XCALL(0x0045D060);
	};

	virtual ~zCNetMessage()
	{
		XCALL(0x0045C420);
	};
};

class zCNetEventManager : public zCEventManager
{
	int u44;

	static int HandleNetMessage(zCNetMessage*,unsigned short,zCWorld*)
	{
		XCALL(0x00457470);
	};

	void zNetEventManager(void)
	{
		XCALL(0x004582F0);
	};

	zCNetEventManager(void)
	{
		zNetEventManager();
	};

	void zNetEventManager(zCVob*)
	{
		XCALL(0x00458340);
	};

	zCNetEventManager(zCVob* vob)
	{
		zNetEventManager(vob);
	};

	void Init(void)
	{
		XCALL(0x00458370);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00457460);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00459EB0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00459EE0);
	};

	virtual ~zCNetEventManager()
	{
		XCALL(0x00458310);
	};

	virtual void OnTrigger(zCVob*,zCVob*)
	{
		XCALL(0x007879F0);
	};

	virtual void OnUntrigger(zCVob*,zCVob*)
	{
		XCALL(0x00787AB0);
	};

	virtual void OnTouch(zCVob*)
	{
		XCALL(0x00787860);
	};

	virtual void OnUntouch(zCVob*)
	{
		XCALL(0x00787920);
	};

	virtual void OnTouchLevel(void)
	{
		XCALL(0x007879E0);
	};

	virtual void OnDamage(zCVob*,zCVob*,float,int,zVEC3 const&)
	{
		XCALL(0x00787B70);
	};

	virtual void OnMessage(zCEventMessage*,zCVob*)
	{
		XCALL(0x00458380);
	};

	virtual void Clear(void)
	{
		XCALL(0x00787580);
	};

	virtual int IsEmpty(int)
	{
		XCALL(0x00787780);
	};

	virtual int GetCutsceneMode(void)
	{
		XCALL(0x00787570);
	};

	virtual void SetCutscene(zCCutscene*)
	{
		XCALL(0x007874F0);
	};

	virtual zCCutscene* GetCutscene(void)
	{
		XCALL(0x00787560);
	};

	virtual int IsRunning(zCEventMessage*)
	{
		XCALL(0x007877E0);
	};

	virtual void SetActive(int)
	{
		XCALL(0x00787110);
	};

	virtual int GetNumMessages(void)
	{
		XCALL(0x00457430);
	};

	virtual zCEventMessage* GetEventMessage(int)
	{
		XCALL(0x00787C40);
	};

	virtual zCEventMessage* GetActiveMessage(void)
	{
		XCALL(0x00787810);
	};

	virtual void ShowList(int,int)
	{
		XCALL(0x00787C50);
	};

	virtual zCNetVobControl* GetNetVobControl(int)
	{
		XCALL(0x00459F60);
	};

	virtual void RemoveFromList(zCEventMessage*)
	{
		XCALL(0x007872B0);
	};

	virtual void InsertInList(zCEventMessage*)
	{
		XCALL(0x00787300);
	};

	virtual void ProcessMessageList(void)
	{
		XCALL(0x00787000);
	};

	virtual void SendMessageToHost(zCEventMessage*,zCVob*,zCVob*)
	{
		XCALL(0x00786C60);
	};

	virtual void Delete(zCEventMessage*)
	{
		XCALL(0x00787270);
	};
};

class zCNetHost
{
	zSTRING GetReadableAddr(void)
	{
		XCALL(0x00450F80);
	};

	int InitHost(zSTRING const&)
	{
		XCALL(0x0045A380);
	};

	zCNetHost(void*)
	{
		XCALL(0x0045A650);
	};

	zCNetHost(zSTRING const&)
	{
		XCALL(0x0045A810);
	};

	zCNetHost( zTNetAddress const&)
	{
		XCALL(0x0045A9A0);
	};

	void Init(void)
	{
		XCALL(0x0045AB30);
	};

	int InitHostForBroadcast(void)
	{
		XCALL(0x0045AC30);
	};

	void InitHostAddr( zTNetAddress* const)
	{
		XCALL(0x0045ADA0);
	};

	void Pack(zCBuffer&)
	{
		XCALL(0x0045B010);
	};

	void Unpack(zCBuffer&)
	{
		XCALL(0x0045B080);
	};

	static zCNetHost* CreateFromBuffer(zCBuffer&)
	{
		XCALL(0x0045B210);
	};

	void PackToBuffer(zCBuffer&)
	{
		XCALL(0x0045B3C0);
	};

	int HasAddress( zTNetAddress*)
	{
		XCALL(0x0045B3F0);
	};

	zSTRING GetHostname(void)const 
	{
		XCALL(0x00467210);
	};
};

class zCNet
{
	zCNet(unsigned short)
	{
		XCALL(0x00450580);
	};

	int NetReset(void)
	{
		XCALL(0x00450760);
	};

	int NetReset(int)
	{
		XCALL(0x00450900);
	};

	int StreamListen(int (__cdecl*)(void*))
	{
		XCALL(0x00450930);
	};

	int Send(zCNetMessage*&)
	{
		XCALL(0x00450990);
	};

	unsigned long DGramWriteMessage(zCNetMessage*&)
	{
		XCALL(0x00450B40);
	};

	unsigned long DGramWriteToPlayer(zCNetMessage*,zCPlayerInfo*)
	{
		XCALL(0x00450BE0);
	};

	unsigned long DGramWriteToGroup(zCNetMessage*,zCPlayerGroup*)
	{
		XCALL(0x00451000);
	};

	int DGramRead(zCNetMessage*&)
	{
		XCALL(0x00451070);
	};

	unsigned long StreamRead(zCNetMessage*&,zCPlayerInfo*)
	{
		XCALL(0x00451140);
	};

	unsigned long StreamReadFromPlayer(void*,unsigned long size,zCPlayerInfo* from_player,zTNetStreamReadMode mode)
	{
		XCALL(0x00451320);
	};

	unsigned long StreamWriteMessage(zCNetMessage*&)
	{
		XCALL(0x00451390);
	};

	unsigned long StreamWriteToPlayer(void*,unsigned long,zCPlayerInfo*)
	{
		XCALL(0x00451540);
	};

	unsigned long StreamWriteToGroup(void*,unsigned long,zCPlayerGroup*)
	{
		XCALL(0x00451570);
	};

	unsigned long StreamWriteFile(zCNetMessage*&)
	{
		XCALL(0x004515E0);
	};

	unsigned long StreamReadFile(zCNetMessage*,zCPlayerInfo*)
	{
		XCALL(0x00451AA0);
	};

	int MsgGetFromStream(zCPlayerInfo*,zCNetMessage*&)
	{
		XCALL(0x004522D0);
	};

	int MsgPut(zCNetMessage*)
	{
		XCALL(0x004523D0);
	};

	int MsgGet(zCNetMessage*&,unsigned char)
	{
		XCALL(0x00452630);
	};

	int MsgSendFromQueue(void)
	{
		XCALL(0x004526B0);
	};

	int MsgRecvToQueue(void)
	{
		XCALL(0x00452760);
	};

	int HandleReceiving(void)
	{
		XCALL(0x004527B0);
	};

	int HandleSending(void)
	{
		XCALL(0x00452820);
	};

	void Handle(void)
	{
		XCALL(0x00452A50);
	};

	int StreamConnect(zCNetHost*&)
	{
		XCALL(0x00452BA0);
	};

	int StreamDisconnect(zCNetHost*&)
	{
		XCALL(0x00452BD0);
	};

	void LockQueues(int)
	{
		XCALL(0x00452C00);
	};

	int WaitForStreamMessage(zCPlayerInfo*,zCNetMessage*&)
	{
		XCALL(0x00452C10);
	};

	zTNetAddress* GetLocalAddress(void)
	{
		XCALL(0x00452E70);
	};

	void EnableNetwork(bool)
	{
		XCALL(0x00452E80);
	};

	void ApplyTimestamp(zCNetMessage*,unsigned char)
	{
		XCALL(0x00452E90);
	};

	int CheckTimestamp(zCNetMessage*,unsigned char)
	{
		XCALL(0x00452EE0);
	};

	virtual ~zCNet()
	{
		XCALL(0x00450700);
	};
};