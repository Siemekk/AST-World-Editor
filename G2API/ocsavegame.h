#pragma once

#include "zcobject.h"

class zCTexture;
class zCTextureConvert;

class oCSavegameInfo : public zCObject
{
	zSTRING			m_sDirectory;		
	zCTexture*		m_pThumbTexture;	
	int				m_nSlot;			
	zSTRING			m_sTitle;			
	zSTRING			m_sWorldName;		
	int				m_nTimeDay;			
	int				m_nTimeHour;		
	int				m_nTimeMin;			
	zSTRING			m_sSaveDate;		
	int				m_nVersionMajor;				
	int				m_nVersionMinor;				
	int				m_nPlayTimeSeconds;	
	int				m_nVersionPoint;				
	int				m_nVersionInt;					
	zSTRING			m_sVersionAppName;				
	BOOL			m_bIncompatible;	
	static zCClassDef			*classDef;
public:

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00436D30);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00437970);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00437EC0);
	};

	virtual ~oCSavegameInfo()
	{
		XCALL(0x00437810);
	};
public:
	zSTRING GetName(void)
	{
		XCALL(0x0042A610);
	};

	zSTRING GetWorldName(void)
	{
		XCALL(0x0042A660);
	};

	zSTRING GetSaveTime(void)
	{
		XCALL(0x0042F130);
	};

	void oSavegameInfo()
	{
		XCALL(0x00436BA0);
	};

	oCSavegameInfo(void)
	{
		oSavegameInfo();
	};

	void oSavegameInfo(int)
	{
		XCALL(0x00436D70);
	};

	oCSavegameInfo(int arg0)
	{
		oSavegameInfo(arg0);
	};

	void Init(void)
	{
		XCALL(0x00436F10);
	};

	int DoesSavegameExist(void)
	{
		XCALL(0x004370E0);
	};

	void UpdateThumbPic(zCTextureConvert*)
	{
		XCALL(0x004370F0);
	};

	zSTRING GetDir(void)
	{
		XCALL(0x00437310);
	};

	void ReloadResources(void)
	{
		XCALL(0x00437360);
	};

	void CleanResources(void)
	{
		XCALL(0x00437550);
	};

	void SetSlot(int)
	{
		XCALL(0x00437580);
	};

	zSTRING GetGameTime(void)
	{
		XCALL(0x00438440);
	};
};


class oCSavegameManager
{
	zCArray<oCSavegameInfo*>	m_arrSaveInfo;		
	oCSavegameInfo*				m_pTempSaveInfo;	
	BOOL						m_bInitialized;		
public:
	virtual ~oCSavegameManager()
	{
		XCALL(0x004388D0);
	};

	oCSavegameManager(void)
	{
		oSavegameManager();
	};

	void oSavegameManager(void)
	{
		XCALL(0x004386F0);
	};

	void Init(void)
	{
		XCALL(0x00438990);
	};

	void Reinit(void)
	{
		XCALL(0x00439070);
	};

	void CleanResources(void)
	{
		XCALL(0x00439080);
	};

	void SetAndWriteSavegame(int,oCSavegameInfo*)
	{
		XCALL(0x004390E0);
	};

	oCSavegameInfo* GetSavegame(int)
	{
		XCALL(0x004392E0);
	};

	void CopyToCurrent(int)
	{
		XCALL(0x00439310);
	};

	void CopyFromCurrent(int)
	{
		XCALL(0x004394C0);
	};

	void ClearCurrent(void)
	{
		XCALL(0x00439670);
	};

	zSTRING GetSlotDirName(int)
	{
		XCALL(0x004397B0);
	};
};