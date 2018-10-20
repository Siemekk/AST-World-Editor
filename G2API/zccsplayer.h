#pragma once

#include "occsmanager.h"

class zCView;
class zCCSRole;

class zCCSDebugger
{
	friend class zCCSPlayer;

	zCArray<zCCSBlockBase*>	m_arrBlock;		
	zCCSSyncBlock*			m_pSyncBlock;	
	zCCSDebugger*			m_pNextDebug;	
public:
	zCCSDebugger() {};
	virtual ~zCCSDebugger() { XCALL(0x0041F0E0); };													
	virtual void CSDB_BeginSyncBlock(zCCSSyncBlock*) = 0;						
	virtual void CSDB_BeginAtomBlock(zCCSBlockBase*) = 0;						
	virtual void CSDB_EndAtomBlock(zCCSBlockBase*) = 0;							
	virtual void CSDB_Error(zCCSBlockBase*, zSTRING&) = 0;						
	virtual void CSDB_Warning(zCCSBlockBase*, zSTRING&) = 0;					
	virtual void CSDB_StartPlaying(zCCutscene*) = 0;							
	virtual void CSDB_Stop(zCCutscene*) = 0;									
};

class zCCSPlayer : public zCObject, public zCCSDebugger		
{
public:
	zCLASS(zCCSPlayer)
	friend class oCCSPlayer;

	int								m_nLastProcessDay;	
	int								m_nLastProcessHour;	
	zCList<zCCSCutsceneContext>*	m_pListContext;		
	int								m_nNumberContext;	
	BOOL							m_bDebug;			
	zCView*							m_pDebugView;		
	float							m_fProcessTime;		
	zCList<zCCSCutsceneContext>		m_lstPlayContext;	
	zCCSManager*					m_pCSMan;			
	zCWorld*						m_pWorld;			
public:
	static zCClassDef *classDef;
	void zCSPlayer(void)
	{
		XCALL(0x0041CB00);
	};

	zCCSPlayer(void)
	{
		zCSPlayer();
	};

	void Interrupt(void)
	{
		XCALL(0x0041DEB0);
	};

	void Resume(void)
	{
		XCALL(0x0041DF10);
	};

	int IsAssigned(zSTRING&,zSTRING&)
	{
		XCALL(0x00420180);
	};

	void PrintListOfCutscenes(zSTRING const&)
	{
		XCALL(0x004201E0);
	};

	zCCSCutsceneContext* GetStartedCutscene(zCVob*)
	{
		XCALL(0x004205A0);
	};

	zCCSCutsceneContext* GetStartedCutscene(zSTRING const&)
	{
		XCALL(0x00420610);
	};

	zCCSCutsceneContext* GetPlayingGlobalCutscene(void)
	{
		XCALL(0x00420770);
	};

	int UpdateCutscenesNow(void)
	{
		XCALL(0x00420810);
	};

	void DebugResetInfoscreen(void)
	{
		XCALL(0x00420860);
	};

	void DebugAddCutscene(int,zVEC3,int)
	{
		XCALL(0x00420890);
	};

	void ToggleDebugInfo(void)
	{
		XCALL(0x00420C60);
	};

	virtual void CSDB_BeginSyncBlock(zCCSSyncBlock*)
	{
		XCALL(0x0041F110);
	};

	virtual void CSDB_BeginAtomBlock(zCCSBlockBase*)
	{
		XCALL(0x0041F210);
	};

	virtual void CSDB_EndAtomBlock(zCCSBlockBase*)
	{
		XCALL(0x0041F450);
	};

	virtual void CSDB_Error(zCCSBlockBase*,zSTRING&)
	{
		XCALL(0x0041F660);
	};

	virtual void CSDB_Warning(zCCSBlockBase*,zSTRING&)
	{
		XCALL(0x0041F890);
	};

	virtual void CSDB_StartPlaying(zCCutscene*)
	{
		XCALL(0x0041FAC0);
	};

	virtual void CSDB_Stop(zCCutscene*)
	{
		XCALL(0x0041FAD0);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0041CAF0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0041EA10);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0041ED10);
	};

	virtual ~zCCSPlayer()
	{
		XCALL(0x0041CC30);
	};

	virtual zCCSCutsceneContext* CreateNewOutputUnit(int,zCVob*)
	{
		XCALL(0x0041D540);
	};

	virtual zCCSCutsceneContext* StartOutputUnit(int,zCVob*)
	{
		XCALL(0x0041D850);
	};

	virtual zCCSCutsceneContext* StartCutscene(zCCutscene*,zCVob*,zSTRING)
	{
		XCALL(0x0041CDA0);
	};

	virtual zCCSCutsceneContext* StartCutscene(zSTRING&,zCVob*)
	{
		XCALL(0x0041D240);
	};

	virtual void ForgetCutscene(zCCutscene*)
	{
		XCALL(0x0041DDB0);
	};

	virtual void ResetCutscenePlayer(void)
	{
		XCALL(0x0041FAE0);
	};

	virtual int StopAllCutscenes(zCVob*)
	{
		XCALL(0x0041FB00);
	};

	virtual int StopAllOutputUnits(zCVob*)
	{
		XCALL(0x0041FE30);
	};

	virtual void InsertCutscene(zCCSCutsceneContext*)
	{
		XCALL(0x0041DFB0);
	};

	virtual void RemoveCutscene(zCCSCutsceneContext*)
	{
		XCALL(0x0041E2C0);
	};

	virtual void OnCSTrigger(zSTRING&,zCVob*)
	{
		XCALL(0x0041E5E0);
	};

	virtual void OnCSUntrigger(zSTRING&,zCVob*)
	{
		XCALL(0x0041E880);
	};

	virtual void SetOwnerWorld(zCWorld*)
	{
		XCALL(0x0041CD80);
	};

	virtual void SetOwnerManager(zCCSManager*)
	{
		XCALL(0x0041CD90);
	};

	virtual void Process(void)
	{
		XCALL(0x004208C0);
	};

	virtual void ProcessCutscene(zCCSCutsceneContext*,zVEC3 const&)
	{
		XCALL(0x00420B60);
	};

	virtual void ProcessList(zVEC3 const&,int,int,int)
	{
		XCALL(0x00420980);
	};
};

class oCCSPlayer : public zCCSPlayer	
{
public:
	zCLASS(oCCSPlayer)
public:
	static zCClassDef *classDef;
	void oCSPlayer(void)
	{
		XCALL(0x004038D0);
	};

	oCCSPlayer(void)
	{
		oCSPlayer();
	};

	virtual void CSDB_BeginSyncBlock(zCCSSyncBlock*)
	{
		XCALL(0x0041F110);
	};

	virtual void CSDB_BeginAtomBlock(zCCSBlockBase*)
	{
		XCALL(0x0041F210);
	};

	virtual void CSDB_EndAtomBlock(zCCSBlockBase*)
	{
		XCALL(0x0041F450);
	};

	virtual void CSDB_Error(zCCSBlockBase*,zSTRING&)
	{
		XCALL(0x0041F660);
	};

	virtual void CSDB_Warning(zCCSBlockBase*,zSTRING&)
	{
		XCALL(0x0041F890);
	};

	virtual void CSDB_StartPlaying(zCCutscene*)
	{
		XCALL(0x0041FAC0);
	};

	virtual void CSDB_Stop(zCCutscene*)
	{
		XCALL(0x0041FAD0);
	};


	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x004038C0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0041EA10);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0041ED10);
	};

	virtual ~oCCSPlayer()
	{
		XCALL(0x00403920);
	};

	virtual zCCSCutsceneContext* CreateNewOutputUnit(int,zCVob*)
	{
		XCALL(0x0041D540);
	};

	virtual zCCSCutsceneContext* StartOutputUnit(int,zCVob*)
	{
		XCALL(0x0041D850);
	};

	virtual zCCSCutsceneContext* StartCutscene(zCCutscene*,zCVob*,zSTRING)
	{
		XCALL(0x0041CDA0);
	};

	virtual zCCSCutsceneContext* StartCutscene(zSTRING&,zCVob*)
	{
		XCALL(0x0041D240);
	};

	virtual void ForgetCutscene(zCCutscene*)
	{
		XCALL(0x0041DDB0);
	};

	virtual void ResetCutscenePlayer(void)
	{
		XCALL(0x0041FAE0);
	};

	virtual int StopAllCutscenes(zCVob*)
	{
		XCALL(0x0041FB00);
	};

	virtual int StopAllOutputUnits(zCVob*)
	{
		XCALL(0x0041FE30);
	};

	virtual void InsertCutscene(zCCSCutsceneContext*)
	{
		XCALL(0x0041DFB0);
	};

	virtual void RemoveCutscene(zCCSCutsceneContext*)
	{
		XCALL(0x0041E2C0);
	};

	virtual void OnCSTrigger(zSTRING&,zCVob*)
	{
		XCALL(0x0041E5E0);
	};

	virtual void OnCSUntrigger(zSTRING&,zCVob*)
	{
		XCALL(0x0041E880);
	};

	virtual void SetOwnerWorld(zCWorld*)
	{
		XCALL(0x0041CD80);
	};

	virtual void SetOwnerManager(zCCSManager*)
	{
		XCALL(0x0041CD90);
	};

	virtual void Process(void)
	{
		XCALL(0x004208C0);
	};

	virtual void ProcessCutscene(zCCSCutsceneContext*,zVEC3 const&)
	{
		XCALL(0x00403940);
	};

	virtual void ProcessList(zVEC3 const&,int,int,int)
	{
		XCALL(0x00420980);
	};
};

class zCCSProps : public zCObject		
{
public:
	zCLASS(zCCSProps)
	friend class zCCSPlayer;
	friend class oCCSPlayer;
	friend class zCCutscene;
	friend class zCCSCutsceneContext;
	friend class oCNpc;
	friend class zCCSManager;
	friend class zCCSCamera;

public:
	enum zTCSRunBehaviour
	{
		zTCS_RUN_ALWAYS,	
		zTCS_RUN_TIMES,		
		zTCS_RUN_PERHOUR,	
		zTCS_RUN_PERDAY		
	};
private:
	zSTRING				m_sName;				
	BOOL				m_bCsLoop;				
	BOOL				m_bGlobalCutscene;		
	float				m_fDistance;			
	BOOL				m_bHasTriggered;		
	float				m_fRange;				
	BOOL				m_bNoReplay;			
	int					m_nNumLockedBlocks;		
	zSTRING				m_sStageName;			
	zSTRING				m_sScriptFuncOnStop;	
	zTCSRunBehaviour	m_RunBehaviour;			
	int					m_nRunBehaviourValue;	
public:
	static zCClassDef *classDef;
	zSTRING GetName(void)
	{
		XCALL(0x00406300);
	};

	zSTRING GetScriptFuncOnStop(void)
	{
		XCALL(0x00407670);
	};

	zTCSRunBehaviour GetRunBehaviour(int &)
	{
		XCALL(0x00421580);
	};

	zTCSRunBehaviour GetRunBehaviour(void)
	{
		XCALL(0x00421590);
	};

	void SetRunBehaviour(zTCSRunBehaviour,int&)
	{
		XCALL(0x004215A0);
	};

	void zCSProps(void)
	{
		XCALL(0x00421EA0);
	};

	zCCSProps(void)
	{
		zCSProps();
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00422060);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00422160);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00422240);
	};

	virtual ~zCCSProps()
	{
		XCALL(0x004220A0);
	};

	virtual int AcceptRole(zCCSRole*,zCVob*)
	{
		XCALL(0x00422B80);
	};

	virtual int CheckRole(zCCSRole*,zCVob*)
	{
		XCALL(0x00422B90);
	};

	virtual int GetCheckRoleResult(void)
	{
		XCALL(0x004223A0);
	};

	virtual int CheckDistance(float)
	{
		XCALL(0x00422330);
	};

	virtual int CheckRange(float)
	{
		XCALL(0x00422370);
	};

	virtual void PrintDebugInfo(void)
	{
		XCALL(0x004223B0);
	};
};

class zCCSPoolItem : public zSTRING, public zCObject	
{
public:
	zCLASS(zCCSPoolItem)
	friend class zCCSManager;
	friend class zCCSCutsceneContext;

	BOOL						m_bDeactivated;		
	int							m_nBehaviourValue;	
	zCCSProps::zTCSRunBehaviour	m_RunBehaviour;		
	int							m_nNumberPlayed;	
	int							m_nNumberTotal;		
	int							m_nFlags;			
public:
	static zCClassDef *classDef;
	zCCSPoolItem(void)
	{
		XCALL(0x00421230);
	};

	zCCSPoolItem(zCCSCutsceneContext*)
	{
		XCALL(0x00421390);
	};

	void Init(void)
	{
		XCALL(0x004214F0);
	};

	zCCSProps::zTCSRunBehaviour GetRunBehaviour(int &)
	{
		XCALL(0x00421580);
	};

	zCCSProps::zTCSRunBehaviour GetRunBehaviour(void)
	{
		XCALL(0x00421590);
	};

	void SetRunBehaviour(zCCSProps::zTCSRunBehaviour,int&)
	{
		XCALL(0x004215A0);
	};

	void TestedDeactivation(void)
	{
		XCALL(0x00421820);
	};

	int IsAllowedToPlay(void)
	{
		XCALL(0x00421840);
	};

	void ClrFlags(long)
	{
		XCALL(0x00421BC0);
	};

	void SetFlags(long)
	{
		XCALL(0x00421BE0);
	};

	int HasFlags(long)
	{
		XCALL(0x00421BF0);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00421220);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x004215C0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00421640);
	};

	virtual ~zCCSPoolItem()
	{
		XCALL(0x00421500);
	};
};

class oCCSProps : public zCCSProps		
{
public:
	zCLASS(oCCSProps)
	BOOL		m_bCheckRole;	
public:
	static zCClassDef *classDef;

	void oCSProps(void)
	{
		XCALL(0x00403F00);
	};

	oCCSProps(void)
	{
		oCSProps();
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00403EF0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00403F60);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00403F70);
	};

	virtual ~oCCSProps()
	{
		XCALL(0x00403F50);
	};

	virtual int AcceptRole(zCCSRole*,zCVob*)
	{
		XCALL(0x00403F80);
	};

	virtual int CheckRole(zCCSRole*,zCVob*)
	{
		XCALL(0x00403F90);
	};

	virtual int GetCheckRoleResult(void)
	{
		XCALL(0x004223A0);
	};

	virtual int CheckDistance(float)
	{
		XCALL(0x00422330);
	};

	virtual int CheckRange(float)
	{
		XCALL(0x00422370);
	};

	virtual void PrintDebugInfo(void)
	{
		XCALL(0x004223B0);
	};

	virtual int CheckRoleResult(void)
	{
		XCALL(0x00403FE0);
	};
};

class zCCSRole : public zCObject, public zSTRING	
{
public:
	zCLASS(zCCSRole)
	friend class zCCutscene;

	enum zTCSRoleType
	{
		zTCS_ROLE_REQUIRED,		
		zTCS_ROLE_DELAY,		
		zTCS_ROLE_NONREQUIRED	
	};
	BOOL			m_bAlive;			
	int				m_RoleType;			
	zCVob*			m_pRoleVob;			
public:
	static zCClassDef *classDef;
	void zCSRole()
	{
		XCALL(0x0040B940);
	};

	zCCSRole(void)
	{
		zCSRole();
	};

	zCCSRole(zSTRING&)
	{
		XCALL(0x0040BA90);
	};

	void SetRoleVob(zCVob*)
	{
		XCALL(0x0040BE80);
	};

	zCVob* GetRoleVob(void)
	{
		XCALL(0x0040C330);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0040B550);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0040C340);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0040C3A0);
	};

	virtual ~zCCSRole()
	{
		XCALL(0x0040BBD0);
	};
};