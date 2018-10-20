#pragma once

#include "zcvob.h"

class zCCSRole;
class zCEventMessage;
class zCCSProps;
class zCCSBlockBase;
class zCBuffer;
class zCCSPoolItem;
typedef zCArray<zCCSRole*>			zTCSRoleList;
typedef zCArray<zCVob*>				zTCSRoleVobList;
typedef zCArray<zCEventManager*>	zTCSRoleEMList;



const int zLIB_STORE_ASCII	= 1;
const int zLIB_STORE_BIN	= 2;

const int zLIB_LOAD_ASCII	= 1;
const int zLIB_LOAD_BIN		= 2;


class zCCSBlockPosition
{
	friend class zCCSBlock;
	friend class zCCSSyncBlock;
	friend class zCCutscene;
	friend class zCCSCutsceneContext;

public:
	float			position;
	zCCSBlockBase*	block;	
public:
	zCCSBlockPosition(void)
	{
		XCALL(0x00416B70);
	};

	zCCSBlockPosition(zCCSBlockBase*)
	{
		XCALL(0x00416B90);
	};

	zCCSBlockPosition(float,zCCSBlockBase*)
	{
		XCALL(0x00416BB0);
	};

	zCCSBlockPosition& operator=(zCCSBlockPosition const&)
	{
		XCALL(0x00416BE0);
	};

	virtual ~zCCSBlockPosition()
	{
		XCALL(0x00416BD0);
	};
};

class zCCSBlockBase : public zCObject			//sizeof 0x24
{
public:
	zCLASS(zCCSBlockBase)
	static zCClassDef*	classDef;
	void zCSBlockBase(void)
	{
		XCALL(0x0040C860);
	};

	zCCSBlockBase(void)
	{
		zCSBlockBase();
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0040AF40);
	};
	virtual ~zCCSBlockBase		(){XCALL(0x0040C9F0)};
	
	virtual zCCSBlockBase *GetChild(int n){XCALL(0x0040CA00)};
	
	virtual void OrganizeRoles	(zCArray<zCVob*> &roles, zTCSRoleList &rolesN)=0;
	virtual zSTRING GetRoleName	(){XCALL(0x0040CA60)};
	virtual void	SetRoleName	(zSTRING & name){XCALL(0x0040CAF0)};

	virtual void Play			(const zTCSRoleEMList &)=0;
	virtual void Play			(const zTCSRoleEMList &, float, float)=0;
	virtual void Play			(zCEventManager*)=0;
	virtual void Play			(zCEventManager*, float, float)=0;

	virtual float GetMinTime	()=0;
	virtual zBOOL IsFinished	(const zTCSRoleEMList &)=0;
	virtual zBOOL IsFinished	(zCEventManager*)=0;

protected:
	// Archiver-Methoden
	virtual void	Archive		(zCArchiver &arc){XCALL(0x00416C00)};
	virtual void	Unarchive	(zCArchiver &arc){XCALL(0x00416C10)};

public:
	virtual zCEventMessage*	GetCommand() { return NULL; };
	virtual int		NewBlock	(int id, int n=0){XCALL(0x0040CA10)};
	virtual void	InsertBlock	(zCCSBlockBase* bl, int n=0) {};
	virtual void	DeleteChild	(int pos){XCALL(0x0040CB00)};
	virtual int		GetNumOfChilds(){XCALL(0x0040CA20)};
	virtual int		GetRoleNumOfChild(int pos){XCALL(0x0040CA30)};
	virtual void	BlockCorrection(){XCALL(0x0040CA40)};
	virtual void	BlockAsFocus(int n){XCALL(0x0040CA50)};
	virtual zCCSBlockPosition*	GetChildPos	(int nr){XCALL(0x0040CB10)};
};

class zCCSAtomicBlock : public zCCSBlockBase		//sizeof 0x34
{
	friend class zCCSManager;
public:
	zCLASS(zCCSAtomicBlock)
private:
	zCVob* roleVob;

protected:
	zCEventMessage* commandRef;
	zCEventMessage*	command;

	enum { EVCOM_NOTSTARTED, EVCOM_PLAYING, EVCOM_FINISHED } commandState;
public:
	static zCClassDef* classDef;
	void zCSAtomicBlock(void)
	{
		XCALL(0x0040CB20);
	};

	zCCSAtomicBlock(void)
	{
		zCSAtomicBlock();
	};

	virtual zCClassDef* _GetClassDef(void)const {XCALL(0x0040A980);};
// Archiver-Methoden
	virtual void	Archive		(zCArchiver &arc){XCALL(0x00416C20)};
	virtual void	Unarchive	(zCArchiver &arc){XCALL(0x00416C40)};
public:
	virtual ~zCCSAtomicBlock	(){XCALL(0x0040CC80)};
	virtual void OrganizeRoles	(zCArray<zCVob*> &roles, zTCSRoleList &rolesN){XCALL(0x0040CD20)};
	virtual void Play			(const zTCSRoleEMList &aiman){XCALL(0x0040CF80)};
	virtual void Play			(const zTCSRoleEMList &aiman, float, float){XCALL(0x0040CFA0)};
	virtual void Play			(zCEventManager* aiman){XCALL(0x0040CFC0)};
	virtual void Play			(zCEventManager* aiman, float b1, float b2){XCALL(0x0040D040)};
	virtual float GetMinTime	(){XCALL(0x0040D050)};
	virtual zBOOL IsFinished	(const zTCSRoleEMList &aiman) { return TRUE; };
	virtual zBOOL IsFinished	(zCEventManager* aiman){XCALL(0x0040D070)};	
	zCEventMessage*	GetCommand() { return command; };
	void			SetCommand(zCEventMessage* msg) { command=msg; };
};

class zCCSBlock : public zCCSBlockBase
{
public:
	zCLASS(zCCSBlock)
	friend class zCCutscene;
	friend class zCCSCutsceneContext;
	friend class zCCSSyncBlock;

	zCArray<zCCSBlockPosition>	blocks;  // Definition blocks[0] ist FoKus und hat eine implementationstechnische Besonderheit
	zSTRING roleName;
public:
	static zCClassDef* classDef;
	void zCSBlock(void)
	{
		XCALL(0x0040D260);
	};

	zCCSBlock(void)
	{
		zCSBlock();
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0040AC80);
	};
	// Archiver-Methoden
	virtual void	Archive		(zCArchiver &arc){XCALL(0x00416C70)};
	virtual void	Unarchive	(zCArchiver &arc){XCALL(0x00416E50)};
	virtual ~zCCSBlock			(){XCALL(0x0040D330)};
	virtual zCCSBlockBase *GetChild(int n){XCALL(0x0040D410)};
	virtual void OrganizeRoles	(zCArray<zCVob*> &roles, zTCSRoleList &rolesN){XCALL(0x0040D940)};
	virtual zSTRING GetRoleName	(){XCALL(0x0040D990)};
	virtual void	SetRoleName	(zSTRING & name){XCALL(0x0040D9E0)};
	virtual void Play			(const zTCSRoleEMList &aiman){XCALL(0x0040D600)};
	virtual void Play			(const zTCSRoleEMList &aiman, float b1, float b2){XCALL(0x0040D6D0)};
	virtual void Play			(zCEventManager* aiman){XCALL(0x0040D4F0)};
	virtual void Play			(zCEventManager* aiman, float b1, float b2){XCALL(0x0040D540)};
	virtual float GetMinTime	(){XCALL(0x0040D7A0)};
	virtual zBOOL IsFinished	(const zTCSRoleEMList &aiman){XCALL(0x0040D880)};
	virtual zBOOL IsFinished	(zCEventManager* aiman){XCALL(0x0040D830)};
	virtual zCCSBlockPosition* GetChildPos(int nr){XCALL(0x0040D430)};
	virtual void	InsertBlock	(zCCSBlockBase* bl, int n=0){XCALL(0x0040DB20)};
	virtual int		NewBlock	(int id, int n=0){XCALL(0x0040DBC0)};
	virtual int		GetNumOfChilds(){XCALL(0x0040D450)};
	virtual void	BlockCorrection(){XCALL(0x0040DCA0)};
	virtual void	BlockAsFocus(int n){XCALL(0x0040DC60)};
	virtual void	DeleteChild(int pos){XCALL(0x0040D460)};
};

class zCCSSyncBlock : public zCCSBlock
{
public:
	zCLASS(zCCSSyncBlock)
private:
	zCArray<int> roleAss;
public:
	static zCClassDef* classDef;

	void zCSSyncBlock(void)
	{
		XCALL(0x0040DDA0);
	};

	zCCSSyncBlock(void)
	{
		zCSSyncBlock();
	};

	void AssignerCorrection(int)
	{
		XCALL(0x0040E3B0);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0040AF70);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00417090);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x004172C0);
	};

	virtual ~zCCSSyncBlock()
	{
		XCALL(0x0040DE80);
	};

	virtual zCCSBlockBase* GetChild(int)
	{
		XCALL(0x0040D410);
	};

	virtual void OrganizeRoles(zCArray<zCVob*>&,zCArray<zCCSRole*>&)
	{
		XCALL(0x0040D940);
	};

	virtual zSTRING GetRoleName(void)
	{
		XCALL(0x0040D990);
	};

	virtual void SetRoleName(zSTRING&)
	{
		XCALL(0x0040D9E0);
	};

	virtual void Play(zCEventManager*,float,float)
	{
		XCALL(0x0040D540);
	};

	virtual void Play(zCEventManager*)
	{
		XCALL(0x0040DF30);
	};

	virtual void Play(zCArray<zCEventManager*> const&,float,float)
	{
		XCALL(0x0040E030);
	};

	virtual void Play(zCArray<zCEventManager*> const&)
	{
		XCALL(0x0040DF80);
	};

	virtual float GetMinTime(void)
	{
		XCALL(0x0040D7A0);
	};

	virtual int IsFinished(zCEventManager*)
	{
		XCALL(0x0040D830);
	};

	virtual int IsFinished(zCArray<zCEventManager*> const&)
	{
		XCALL(0x0040DEE0);
	};

	virtual zCEventMessage* GetCommand(void)
	{
		XCALL(0x00404F70);
	};

	virtual int NewBlock(int,int)
	{
		XCALL(0x0040E1D0);
	};

	virtual void InsertBlock(zCCSBlockBase*,int)
	{
		XCALL(0x0040E100);
	};

	virtual void DeleteChild(int)
	{
		XCALL(0x0040E2F0);
	};

	virtual int GetNumOfChilds(void)
	{
		XCALL(0x0040D450);
	};

	virtual int GetRoleNumOfChild(int)
	{
		XCALL(0x0040E0E0);
	};

	virtual void BlockCorrection(void)
	{
		XCALL(0x0040DCA0);
	};

	virtual void BlockAsFocus(int)
	{
		XCALL(0x0040E2A0);
	};

	virtual zCCSBlockPosition* GetChildPos(int)
	{
		XCALL(0x0040D430);
	};
};

struct zTCSBlockPosition
{
	zCArray<zCCSBlockBase*> flatData;
	int						index;
	int						numInList;
};

class zCCutscene : public zCCSBlock	
{
public:
	zCLASS(zCCutscene)
	friend class zCCSPlayer;
	friend class oCCSPlayer;
	friend class zCCSCutsceneContext;
	friend class oCNpc;
	friend class zCCSManager;
	friend class zCCSCamera;

public:
	enum zTCSCheckResult 
	{ 
		CS_CHECK_UNKNOWN,
		CS_CHECK_OK,
		CS_CHECK_ROLE_ERROR,
		CS_CHECK_ROLE_MISSING,
		CS_CHECK_PLAYER_MISSING,
		CS_CHECK_PLAYER_ERROR,
		CS_CHECK_ROLECHECK_FAILED,
		CS_CHECK_NOSTAGE,
		CS_CHECK_NOWORLD,
		CS_CHECk_MAX
	} 
	lastCheckResult;
	zTCSRoleList				roleList;	// List of roles		
	zTCSRoleEMList				roleEvMList;	
	zTCSRoleVobList				roleVobList;
	zCVob*						mainRoleVob;
	zCCSProps*					properties;	// StartConditions
	zCCSPlayer*					ownerPlayer;	

private:		
	int							actualBlockNum;
	zCCSBlockBase*				actualBlock;
public:
	static zCClassDef* classDef;
	void zCutscene(void)
	{
		XCALL(0x0040E3E0);
	};

	zCCutscene(void)
	{
		zCutscene();
	};

	int IsMember(zCVob*)
	{
		XCALL(0x0040E7C0);
	};

	void SetRoleListForDebugging(zCArray<zCCSRole*>&)
	{
		XCALL(0x0040E7F0);
	};

	void SaveRolesVobs(zCBuffer&)
	{
		XCALL(0x0040E9B0);
	};

	void RestoreRoleVobs(zCBuffer&)
	{
		XCALL(0x0040EC40);
	};

	int CheckMainRole(zCVob*)
	{
		XCALL(0x0040EEB0);
	};

	int CheckPlayState(void)
	{
		XCALL(0x0040FD00);
	};

	zCEventManager* SolveEventManager(int)
	{
		XCALL(0x00414280);
	};

	int GetActualBlockNum(void)
	{
		XCALL(0x00415D30);
	};

	void ResumeAtBlock(int)
	{
		XCALL(0x004160F0);
	};

	void NewRole(zSTRING&)
	{
		XCALL(0x00416600);
	};

	void DeleteRole(int)
	{
		XCALL(0x004167B0);
	};

	void RegisterAdditionalVob(zCTree<zCVob>*)
	{
		XCALL(0x004168A0);
	};

	zCVob* FirstRoleUsed(void)
	{
		XCALL(0x00417840);
	};

	zTCSCheckResult GetLastCheckResult(zSTRING&) 
	{
		XCALL(0x00417910);
	};

	int TryToCancel(void)
	{
		XCALL(0x00417C10);
	};

	zTCSBlockPosition GetFirstBlockPosition(void)
	{
		XCALL(0x00417C40);
	};

	zCEventMessage* GetNextMessage( zTCSBlockPosition&)
	{
		XCALL(0x00417DD0);
	};

	zCCSBlockBase* GetNextBlock( zTCSBlockPosition&)
	{
		XCALL(0x00417E20);
	};

	void SerializeCutscene(zCCutscene*, zTCSBlockPosition&)
	{
		XCALL(0x00417E50);
	};

	void SerializeBlock(zCCSBlockBase*, zTCSBlockPosition&)
	{
		XCALL(0x00417FC0);
	};

	zCCSProps* GetProperties(void)
	{
		XCALL(0x0041D230);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0040E5C0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00417500);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00417590);
	};

	virtual ~zCCutscene()
	{
		XCALL(0x0040E610);
	};

	virtual zCCSBlockBase* GetChild(int)
	{
		XCALL(0x0040D410);
	};

	virtual void OrganizeRoles(zCArray<zCVob*>&,zCArray<zCCSRole*>&)
	{
		XCALL(0x0040D940);
	};

	virtual zSTRING GetRoleName(void)
	{
		XCALL(0x0040D990);
	};

	virtual void SetRoleName(zSTRING&)
	{
		XCALL(0x0040D9E0);
	};

	virtual void Play(zCEventManager*,float,float)
	{
		XCALL(0x0040D540);
	};

	virtual void Play(zCEventManager*)
	{
		XCALL(0x0040D4F0);
	};

	virtual void Play(zCArray<zCEventManager*> const&,float,float)
	{
		XCALL(0x0040D6D0);
	};

	virtual void Play(zCArray<zCEventManager*> const&)
	{
		XCALL(0x0040D600);
	};

	virtual float GetMinTime(void)
	{
		XCALL(0x0040D7A0);
	};

	virtual int IsFinished(zCEventManager*)
	{
		XCALL(0x0040D830);
	};

	virtual int IsFinished(zCArray<zCEventManager*> const&)
	{
		XCALL(0x0040D880);
	};

	virtual zCEventMessage* GetCommand(void)
	{
		XCALL(0x00404F70);
	};

	virtual int NewBlock(int,int)
	{
		XCALL(0x00416170);
	};

	virtual void InsertBlock(zCCSBlockBase*,int)
	{
		XCALL(0x0040DB20);
	};

	virtual void DeleteChild(int)
	{
		XCALL(0x0040D460);
	};

	virtual int GetNumOfChilds(void)
	{
		XCALL(0x0040D450);
	};

	virtual int GetRoleNumOfChild(int)
	{
		XCALL(0x0040CA30);
	};

	virtual void BlockCorrection(void)
	{
		XCALL(0x0040DCA0);
	};

	virtual void BlockAsFocus(int)
	{
		XCALL(0x0040DC60);
	};

	virtual zCCSBlockPosition* GetChildPos(int)
	{
		XCALL(0x0040D430);
	};

	virtual int AddMainRole(zCVob*)
	{
		XCALL(0x00410670);
	};

	virtual void AddRoleOU(zCVob*)
	{
		XCALL(0x0040FE40);
	};

	virtual void RemoveRole(zCVob*)
	{
		XCALL(0x00410EC0);
	};

	virtual void SetOwnerPlayer(zCCSPlayer*)
	{
		XCALL(0x0040E780);
	};

	virtual void Reset(void)
	{
		XCALL(0x00413E30);
	};

	virtual void ClearCutscene(void)
	{
		XCALL(0x00413F30);
	};

	virtual int StartPlaying(void)
	{
		XCALL(0x004130C0);
	};

	virtual void Stop(void)
	{
		XCALL(0x004142C0);
	};

	virtual void StopRole(zCVob*)
	{
		XCALL(0x00414120);
	};

	virtual void Interrupt(void)
	{
		XCALL(0x00415390);
	};

	virtual int ResumeActBlock(void)
	{
		XCALL(0x00415D40);
	};

	virtual int PlaySub(float,float)
	{
		XCALL(0x00416100);
	};

	virtual void NewCS(zCCSManager*)
	{
		XCALL(0x00416350);
	};

	virtual int IsCutscene(void)
	{
		XCALL(0x0040E5D0);
	};

	virtual int IsFinished(void)
	{
		XCALL(0x00416160);
	};

	virtual void PrintDebugInfo(zSTRING const&)
	{
		XCALL(0x00417900);
	};

	virtual int CheckRoles(int&)
	{
		XCALL(0x00417870);
	};

	virtual int CSCheck(int&)
	{
		XCALL(0x00410F40);
	};

	virtual zCVob* GetStage(void)
	{
		XCALL(0x0040FCF0);
	};

	virtual zCVob* LoadStage(void)
	{
		XCALL(0x00416910);
	};

	virtual zCVob* CatchPlayer(zCVob*)
	{
		XCALL(0x00416B30);
	};

	virtual void PrepareBlock(void)
	{
		XCALL(0x0040FDC0);
	};
};

class zCCSCutsceneContext : public zCCutscene
{
public:
	zCLASS(zCCSCutsceneContext)
	friend class zCCSPlayer;
	friend class oCCSPlayer;
	friend class zCCSManager;

public:
	
	enum zTCSPlayResult 
	{ 
		CS_PLAY_STARTEDPLAYING,
		CS_PLAY_STOPPED,
		CS_PLAY_INTERRUPTED,
		CS_PLAY_RESUMED,
		CS_PLAY_CONTINUED,
		CS_PLAY_DISABLED,

		CS_PLAY_STARTFAILED,
		CS_PLAY_RESUMEFAILED,		
		CS_PLAY_TOOFAR,
		CS_PLAY_MAXREACHED,		
		CS_PLAY_NOTTRIGGERED,
		CS_PLAY_CHECKFAILED,
		CS_PLAY_MAX
	} lastPlayResult;
public:
	BOOL allowedToPlay;
	zCVob*			alternativeStageVob;		
	BOOL			wasTriggered;
	BOOL			isCutscene;	
	BOOL			loaded;		
	int				reference;
	zCVob*			stage;	
	zCCSPoolItem*	poolItem;
	float			lastTimeStamp;  // StartTime of the last block
	float			lastTimePoint;	// last TimePoint of call(play)	
public:
	static zCClassDef* classDef;
	static int playDisabled;
	//{
	//	XCALL(0x008C218C);
	//};

	static int DisablePlayCutscenes(int)
	{
		XCALL(0x00404FD0);
	};

	void zCSCutsceneContext(void)
	{
		XCALL(0x00404FE0);
	};

	zCCSCutsceneContext(void)
	{
		zCSCutsceneContext();
	};
	void zCSCutsceneContext(zSTRING&)
	{
		XCALL(0x00405070);
	};

	zCCSCutsceneContext(zSTRING& s)
	{
		zCSCutsceneContext(s);
	};

	void zCSCutsceneContext(zCCSBlock*,int,int)
	{
		XCALL(0x00405790);
	};

	zCCSCutsceneContext(zCCSBlock* block,int n1,int n2)
	{
		zCSCutsceneContext(block,n1,n2);
	};

	void UseThisSubBlock(zCCSBlock*)
	{
		XCALL(0x00405A80);
	};

	zSTRING GetCSName(void)const 
	{
		XCALL(0x00406230);
	};

	void HandleTrigger(void)
	{
		XCALL(0x00408F00);
	};

	void HandleUntrigger(void)
	{
		XCALL(0x004091A0);
	};

	float GetLastTimePoint(void)
	{
		XCALL(0x004091B0);
	};

	float GetLastTimeStamp(void)
	{
		XCALL(0x004091C0);
	};

	zTCSPlayResult GetLastPlayResult(zSTRING&)
	{
		XCALL(0x004091D0);
	};

	int AreU(zSTRING const&)
	{
		XCALL(0x004096A0);
	};

	int AreU(int)
	{
		XCALL(0x00409760);
	};

	int IsForcedInterrupted(void)
	{
		XCALL(0x00409780);
	};

	int ReplayCutscene(void)
	{
		XCALL(0x004097F0);
	};

	void ForcedResume(void)
	{
		XCALL(0x00409930);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00404FA0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00405E20);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00406350);
	};

	virtual ~zCCSCutsceneContext()
	{
		XCALL(0x00405BE0);
	};

	virtual zCCSBlockBase* GetChild(int)
	{
		XCALL(0x0040D410);
	};

	virtual void OrganizeRoles(zCArray<zCVob*>&,zCArray<zCCSRole*>&)
	{
		XCALL(0x0040D940);
	};

	virtual zSTRING GetRoleName(void)
	{
		XCALL(0x0040D990);
	};

	virtual void SetRoleName(zSTRING&)
	{
		XCALL(0x0040D9E0);
	};

	virtual void Play(zCEventManager*,float,float)
	{
		XCALL(0x0040D540);
	};

	virtual void Play(zCEventManager*)
	{
		XCALL(0x0040D4F0);
	};

	virtual void Play(zCArray<zCEventManager*> const&,float,float)
	{
		XCALL(0x0040D6D0);
	};

	virtual void Play(zCArray<zCEventManager*> const&)
	{
		XCALL(0x0040D600);
	};

	virtual float GetMinTime(void)
	{
		XCALL(0x0040D7A0);
	};

	virtual int IsFinished(zCEventManager*)
	{
		XCALL(0x0040D830);
	};

	virtual int IsFinished(zCArray<zCEventManager*> const&)
	{
		XCALL(0x0040D880);
	};

	virtual zCEventMessage* GetCommand(void)
	{
		XCALL(0x00404F70);
	};

	virtual int NewBlock(int,int)
	{
		XCALL(0x00416170);
	};

	virtual void InsertBlock(zCCSBlockBase*,int)
	{
		XCALL(0x0040DB20);
	};

	virtual void DeleteChild(int)
	{
		XCALL(0x0040D460);
	};

	virtual int GetNumOfChilds(void)
	{
		XCALL(0x0040D450);
	};

	virtual int GetRoleNumOfChild(int)
	{
		XCALL(0x0040CA30);
	};

	virtual void BlockCorrection(void)
	{
		XCALL(0x0040DCA0);
	};

	virtual void BlockAsFocus(int)
	{
		XCALL(0x0040DC60);
	};

	virtual zCCSBlockPosition* GetChildPos(int)
	{
		XCALL(0x0040D430);
	};

	virtual int AddMainRole(zCVob*)
	{
		XCALL(0x00409FC0);
	};

	virtual void AddRoleOU(zCVob*)
	{
		XCALL(0x0040FE40);
	};

	virtual void RemoveRole(zCVob*)
	{
		XCALL(0x00410EC0);
	};

	virtual void SetOwnerPlayer(zCCSPlayer*)
	{
		XCALL(0x0040E780);
	};

	virtual void Reset(void)
	{
		XCALL(0x00413E30);
	};

	virtual void ClearCutscene(void)
	{
		XCALL(0x00413F30);
	};

	virtual int StartPlaying(void)
	{
		XCALL(0x00406810);
	};

	virtual void Stop(void)
	{
		XCALL(0x00406E60);
	};

	virtual void StopRole(zCVob*)
	{
		XCALL(0x00414120);
	};

	virtual void Interrupt(void)
	{
		XCALL(0x004076C0);
	};

	virtual int ResumeActBlock(void)
	{
		XCALL(0x00415D40);
	};

	virtual int PlaySub(float,float)
	{
		XCALL(0x00416100);
	};

	virtual void NewCS(zCCSManager*)
	{
		XCALL(0x00416350);
	};

	virtual int IsCutscene(void)
	{
		XCALL(0x00404FB0);
	};

	virtual int IsFinished(void)
	{
		XCALL(0x004097D0);
	};

	virtual void PrintDebugInfo(zSTRING const&)
	{
		XCALL(0x004099C0);
	};

	virtual int CheckRoles(int&)
	{
		XCALL(0x00417870);
	};

	virtual int CSCheck(int&)
	{
		XCALL(0x00410F40);
	};

	virtual zCVob* GetStage(void)
	{
		XCALL(0x004098A0);
	};

	virtual zCVob* LoadStage(void)
	{
		XCALL(0x00416910);
	};

	virtual zCVob* CatchPlayer(zCVob*)
	{
		XCALL(0x00409920);
	};

	virtual void PrepareBlock(void)
	{
		XCALL(0x00409860);
	};

	virtual void SetPoolItem(zCCSPoolItem*)
	{
		XCALL(0x00409800);
	};

	virtual void SetStage(zCVob*)
	{
		XCALL(0x004098C0);
	};

	virtual int Play(zVEC3)
	{
		XCALL(0x00407C20);
	};

	virtual void ForcedInterrupt(void)
	{
		XCALL(0x00407970);
	};

	virtual int CheckRoleReactions(void)
	{
		XCALL(0x00409950);
	};

	virtual int IsPlaying(void)
	{
		XCALL(0x004097A0);
	};

	virtual int IsOutputUnit(void)
	{
		XCALL(0x00404FC0);
	};
};

class zCCSLib : public zCObject	
{
public:
	zCLASS(zCCSLib)
	friend class zCCSManager;
	BOOL					loaded;
	BOOL					wasChanged;
	zCArraySort<zCCSBlock*> ouList;
	zCCSBlock*				searchBlock;
public:
	void	New				() { loaded=TRUE; };
	static zCClassDef* classDef;
	void zCSLib(void)
	{
		XCALL(0x00419320);
	};

	zCCSLib(void)
	{
		zCSLib();
	};
	
	void DeleteLib(void)
	{
		XCALL(0x00419510);
	};

	void RemoveFromLib(int,int)
	{
		XCALL(0x00419580);
	};

	int ValidateToken(zSTRING&)
	{
		XCALL(0x004195F0);
	};

	int IsLoaded(void)
	{
		XCALL(0x00419670);
	};

	int WasChanged(void)
	{
		XCALL(0x00419680);
	};

	int NextFree(void)
	{
		XCALL(0x00419690);
	};

	int Add(zCCSBlock*)
	{
		XCALL(0x004196A0);
	};

	void Change(void)
	{
		XCALL(0x00419750);
	};

	zCCSBlock* GetOU(int)
	{
		XCALL(0x00419760);
	};

	void CompactLib(void)
	{
		XCALL(0x00419770);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00418B40);
	};
	~zCCSLib(){XCALL(0x00419430)};
	virtual void Archive	(zCArchiver &arc){XCALL(0x00418B50)};
	virtual void Unarchive	(zCArchiver &arc){XCALL(0x00418D80)};


	// [AST]
	void DeleteLib_AST();
	// [/AST]
};




class zCCSManager : public  zCObject
{
public:
	zCLASS(zCCSManager)
	zCArray<zSTRING>	libSvmModuleList;
	zCCutscene*			iteration;
	zCCSBlockBase*		iter;
	int					iterA;
	int					iterB;
	zCArray<zCCSPoolItem*>	csPool;
//private:
	zCArray<zSTRING>	commandStrings;
	zCArray<zCCSPlayer*>csPlayerList;
	zCCSLib*			src_lib;
	zCCSLib*			library;
	int					iterator;		
public:
	static zCClassDef* classDef;

	void zCSManager(void)
	{
		XCALL(0x0041A370);
	};

	zCCSManager(void)
	{
		zCSManager();
	};

	zCCSCutsceneContext* InitiateCSwithContext(zCCSCutsceneContext*)
	{
		XCALL(0x0041A800);
	};

	zCCSCutsceneContext* InitiateOUwithContext(zCCSCutsceneContext*)
	{
		XCALL(0x0041A950);
	};

	zCCSCutsceneContext* CreateNewCutscene(zSTRING&)
	{
		XCALL(0x0041A980);
	};

	zCCSCutsceneContext* CreateNewOutputUnit(int)
	{
		XCALL(0x0041AAC0);
	};

	int IsDeactivated(zSTRING&)
	{
		XCALL(0x0041AB50);
	};

	void PoolCountStart(zSTRING&)
	{
		XCALL(0x0041AB70);
	};

	void PoolCountStop(zSTRING&)
	{
		XCALL(0x0041AB90);
	};

	int PoolHasFlags(zSTRING&,int)
	{
		XCALL(0x0041ABB0);
	};

	void PoolClrFlags(zSTRING&,int)
	{
		XCALL(0x0041ABE0);
	};

	void PoolSetFlags(zSTRING&,int)
	{
		XCALL(0x0041AC00);
	};

	int PoolNumPlayed(zSTRING&)
	{
		XCALL(0x0041AC20);
	};

	int PoolAllowedToStart(zSTRING&)
	{
		XCALL(0x0041AC40);
	};

	void PoolResetAll(void)
	{
		XCALL(0x0041AEA0);
	};

	void PoolResetByHour(void)
	{
		XCALL(0x0041AED0);
	};

	void PoolResetByDay(void)
	{
		XCALL(0x0041AF10);
	};

	void AddCommand(zSTRING&)
	{
		XCALL(0x0041AF50);
	};

	int GetNumOfShortCom(void)
	{
		XCALL(0x0041B0C0);
	};

	zSTRING GetShortCom(int)
	{
		XCALL(0x0041B0D0);
	};

	void LibForceToLoad(void)
	{
		XCALL(0x0041C400);
	};
	 




	virtual zCClassDef* _GetClassDef					(void)const										{XCALL(0x0041A470)};
	virtual ~zCCSManager								()												{XCALL(0x0041A4D0)};
	virtual		zCEventMessage* CreateMessage			(int z)											{ return 0;		  };
	virtual		zCEventMessage* CreateOuMessage			()												{ return 0;	      };	
	virtual		zCCSPlayer*		CreateCutscenePlayer	(zCWorld* ownerWorld)							{XCALL(0x0041A610)}; // Creating a cutscenes player with given ownerWorld
	virtual		zCCSProps*		CreateProperties		()												{XCALL(0x0041C420)};
	virtual		void			RemoveCutscenePlayer	(zCCSPlayer* csplayer)							{XCALL(0x0041A6B0)};
	virtual zBOOL				LibIsLoaded				()												{XCALL(0x0041C410)};
	virtual zCCSBlock*			LibGet					(int n)											{XCALL(0x0041BF20)};
	virtual zCCSBlock*			LibGetFirst				()												{XCALL(0x0041BDA0)};
	virtual zCCSBlock*			LibGetNext				()												{XCALL(0x0041BE00)};
	virtual zCCSBlock*			LibGetFirst				(int & n)										{XCALL(0x0041BE50)};
	virtual zCCSBlock*			LibGetNext				(int & n)										{XCALL(0x0041BEC0)};
	virtual int					LibAddOU				(zCCSBlock* bl)									{XCALL(0x0041BF50)};
	virtual void				LibDelOU				(int n)											{XCALL(0x0041BF70)};
	virtual void				LibNullOU				(int n)											{XCALL(0x0041BF90)};	
	virtual void				LibLoad					(int flags = zLIB_LOAD_ASCII | zLIB_LOAD_BIN)	{XCALL(0x0041B700)};	
	virtual void				LibStore				(int flags = zLIB_STORE_ASCII | zLIB_STORE_BIN)	{XCALL(0x0041BFB0)};	
	virtual zBOOL				LibValidateOU			(int ref=0)										{XCALL(0x0041C3B0)};
	virtual int					LibValidateOU			(zSTRING & token)								{XCALL(0x0041C3E0)};
	virtual zSTRING				LibGetSvmModuleName		(int n)											{XCALL(0x00419BC0)};
	virtual zBOOL				LibIsSvmModuleRunning	(int n)											{XCALL(0x00419E80)};
	virtual zBOOL				LibSvmModuleStart		(int n)											{XCALL(0x00419FC0)};
	virtual zBOOL				LibSvmModuleStop 		(int n)											{XCALL(0x0041A160)};
	virtual void				InsertPlayerInList		(zCCSPlayer* csplayer)							{XCALL(0x0041A6C0)};
	virtual void				RemovePlayerFromList	(zCCSPlayer* csplayer)							{XCALL(0x0041A7A0)};
	virtual void				LibCheckLoaded			(int flags = zLIB_LOAD_ASCII | zLIB_LOAD_BIN)	{XCALL(0x0041BD80)};	
	virtual void				Archive					(zCArchiver &arc)								{XCALL(0x0041B250)};
	virtual void				Unarchive				(zCArchiver &arc)								{XCALL(0x0041B4A0)};
	virtual zCCSPoolItem*		PoolFindItem			(zSTRING & csname)								{XCALL(0x0041AD50)};
	virtual void				PoolInsertItem			(zCCSPoolItem* item)							{XCALL(0x0041AC70)};

	//[AST]
	void						LibStore_AST				(int flags = zLIB_STORE_ASCII | zLIB_STORE_BIN);
	void						LibLoad_AST					(int flags = zLIB_LOAD_ASCII | zLIB_LOAD_BIN);
	//[/AST]
};