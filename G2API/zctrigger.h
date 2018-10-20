#pragma once

#include "ztypes.h"
#include "zcvob.h"
#include "zceventmessage.h"

class zCSoundFX;
class zCModel;

enum zTMoverState
{
	zTMOVER_OPEN_FINISH,	
	zTMOVER_MOVE_FORWARD,	
	zTMOVER_CLOSE_FINISH,	
	zTMOVER_MOVE_BACKWARD	
};

enum zTMoverBehavior
{
	z2STATE_TOGGLE,			
	z2STATE_TRIGGER_CTRL,	
	z2STATE_OPEN_TIME,		
	zNSTATE_LOOP,			
	zNSTATE_SINGLE_KEYS		
};

enum zTMoverPosLerpType
{
	zLINEAR,				
	zCURVE					
};

enum zTMoverSpeedType
{
	zSPEED_CONST,				
	zSPEED_SLOW_START_END,		
	zSPEED_SLOW_START,			
	zSPEED_SLOW_END,			
	zSPEED_SEG_SLOW_START_END,	
	zSPEED_SEG_SLOW_START,		
	zSPEED_SEG_SLOW_END			
};

enum zTTouchBehavior
{ 
	TB_TOGGLE,
	TB_WAIT
};

enum zTPosLerpType       
{   
	PL_LINEAR, 
	PL_CURVE 
};

enum zTSpeedType     
{ 
	ST_CONST, 
	ST_SLOW_START_END, 
	ST_SLOW_START,
	ST_SLOW_END,
	ST_SEG_SLOW_START_END, 
	ST_SEG_SLOW_START, 
	ST_SEG_SLOW_END 
};

class zCTriggerBase : public zCVob		
{
public:
	zSTRING			m_sTriggerTarget;	

	static zCClassDef classDef;
	void zTriggerBase(void)
	{
		XCALL(0x0060FAF0);
	};

	zCTriggerBase(void)
	{
		zTriggerBase();
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0060B8D0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0060FE40);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0060FE70);
	};

	virtual ~zCTriggerBase()
	{
		XCALL(0x0060C110);
	};

	virtual void OnTrigger(zCVob*,zCVob*)
	{
		XCALL(0x0060FD00);
	};

	virtual void OnUntrigger(zCVob*,zCVob*)
	{
		XCALL(0x0060FDA0);
	};

	virtual void OnTouch(zCVob*)
	{
		XCALL(0x0060FBC0);
	};

	virtual void OnUntouch(zCVob*)
	{
		XCALL(0x0060FC60);
	};

	virtual zSTRING const* GetTriggerTarget(const int i=0)const 
	{
		XCALL(0x004042F0);
	};
};

class zCTrigger : public zCTriggerBase
{
public:
	struct BIT_ARRAY
	{
		BYTE		tReactToOnTrigger:1;	
		BYTE		tReactToOnTouch:1;		
		BYTE		tReactToOnDamage:1;		
		BYTE		tRespondToObject:1;		
		BYTE		tRespondToPC:1;			
		BYTE		tRespondToNPC:1;		
	};
	struct BIT_ACTION
	{
		BYTE		tStartEnabled:1;		
		BYTE		tEventEnable:1;			
		BYTE		tSendUntrigger:1;		
	};
	union
	{
		unsigned short	m_dbFilterFlags;		
		BIT_ARRAY	f;
	};
	union
	{
		unsigned short	m_dbFlags;				
		BIT_ACTION	act;
	};
	zSTRING			m_sRespondToVobName;	
	WORD			m_nNumCanBeActivated;	
	float			m_fRetriggerWaitSec;	
	float			m_fDamageThreshold;		
	float			m_fFireDelaySec;		
	float			m_fNextTimeTriggerable;	
	zCVob*			m_pSavedOtherVob;		
	WORD			m_nCountCanBeActivated;	
	static zCClassDef *classDef;
public:
	zSTRING GetTriggerTarget(void)const 
	{
		XCALL(0x004049A0);
	};

	void zTrigger(void)
	{
		XCALL(0x0060FEA0);
	};

	zCTrigger(void)
	{
		zTrigger();
	};

	void ClearStateInternals(void)
	{
		XCALL(0x006100D0);
	};

	void TriggerTargetPost(void)
	{
		XCALL(0x006104A0);
	};

	void ActivateTrigger(zCVob*)
	{
		XCALL(0x006104D0);
	};

	void DeactivateTrigger(zCVob*)
	{
		XCALL(0x006105B0);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00610090);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x006107E0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00610A60);
	};

	virtual ~zCTrigger()
	{
		XCALL(0x00610120);
	};

	virtual void OnTrigger(zCVob*,zCVob*)
	{
		XCALL(0x006105E0);
	};

	virtual void OnUntrigger(zCVob*,zCVob*)
	{
		XCALL(0x00610600);
	};

	virtual void OnTouch(zCVob*)
	{
		XCALL(0x00610640);
	};

	virtual void OnUntouch(zCVob*)
	{
		XCALL(0x00610660);
	};

	virtual void OnDamage(zCVob*,zCVob*,float,int,zVEC3 const&)
	{
		XCALL(0x006106A0);
	};

	virtual void OnMessage(zCEventMessage*,zCVob*)
	{
		XCALL(0x006106E0);
	};

	virtual void OnTimer(void)
	{
		XCALL(0x00610750);
	};

	virtual void TriggerTarget(zCVob*)
	{
		XCALL(0x00610340);
	};

	virtual void UntriggerTarget(zCVob*)
	{
		XCALL(0x006103F0);
	};

	virtual int CanBeActivatedNow(zCVob*)
	{
		XCALL(0x00610220);
	};
};

class oCCSTrigger : public zCTrigger	
{
public:
	static zCClassDef *classDef;
	oCCSTrigger() {};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00404330);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00404C30);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00404C40);
	};

	virtual ~oCCSTrigger()
	{
		XCALL(0x00404370);
	};

	virtual void TriggerTarget(zCVob*)
	{
		XCALL(0x00404380);
	};

	virtual void UntriggerTarget(zCVob*)
	{
		XCALL(0x004049F0);
	};

};

class oCTriggerScript : public zCTrigger
{
public:
	zSTRING			m_sScriptFunc;	
	static zCClassDef *classDef;
	void oTriggerScript(void)
	{
		XCALL(0x0043C3F0);
	};

	oCTriggerScript(void)
	{
		oTriggerScript();
	};

	void SetScriptFunc(zSTRING const&,int)
	{
		XCALL(0x0043CAB0);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0043BCE0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0043CC00);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0043CC30);
	};

	virtual ~oCTriggerScript()
	{
		XCALL(0x0043C460);
	};

	virtual void TriggerTarget(zCVob*)
	{
		XCALL(0x0043C4C0);
	};

	virtual void UntriggerTarget(zCVob*)
	{
		XCALL(0x0043C820);
	};
};

class oCTriggerChangeLevel : public zCTrigger 
{
public:
	zSTRING			m_sLevelName;		
	zSTRING			m_sStartVobName;	
	static zCClassDef *classDef;
	oCTriggerChangeLevel(void)
	{
		XCALL(0x0043BCF0);
	};

	void SetLevelName(zSTRING const&,zSTRING const&)
	{
		XCALL(0x0043C140);
	};

	static void* operator new(unsigned int)
	{
		XCALL(0x006D0050);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0043BA20);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0043C370);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0043C3B0);
	};

	virtual ~oCTriggerChangeLevel()
	{
		XCALL(0x0043BD80);
	};

	virtual void TriggerTarget(zCVob*)
	{
		XCALL(0x0043BE20);
	};

	virtual void UntriggerTarget(zCVob*)
	{
		XCALL(0x0043C130);
	};
};

class zCMover : public zCTrigger
{
public:
	zCLASS(zCMover);
	struct zTMov_Keyframe			
	{
		zVEC3		m_vPosition;	
		zCQuat		m_qtRotations;	
	};
	zCArray<zTMov_Keyframe>	m_arrKeyFrames;			
	zVEC3					m_vActKeyPosDelta;		
	float					m_fActKeyFrame;			
	int						m_nActKeyFrame;			
	int						m_nNextKeyFrame;		
	float					m_fMoveSpeedUnit;		
	float					m_fAdvanceDir;			
	zTMoverState			m_MoverState;			
	int						m_nNumTriggerEvents;	
	float					m_fStayOpenTimeDest;	
	zCModel*				m_pModelMover;			
	int						m_nSndMovingHandle;		
	zCSoundFX*				m_pSoundMoving;			
	float					m_fMoveSpeed;			
	float					m_fStayOpenTimeSec;		
	float					m_fTouchBlockerDamage;	
	bool					m_bMoverLocked;			
	bool					m_bAutoLinkEnabled;		
	BOOL					m_bIsModelVisual;		
	zTMoverBehavior			m_MoverBehavior;		
	int						us1A4;
	zTMoverPosLerpType		m_PosLerpType;			
	zTMoverSpeedType		m_SpeedType;			
	zSTRING					m_sSfxOpenStart;		
	zSTRING					m_sSfxOpenEnd;			
	zSTRING					m_sSfxMoving;			
	zSTRING					m_sSfxCloseStart;		
	zSTRING					m_sSfxCloseEnd;			
	zSTRING					m_sSfxLock;				
	zSTRING					m_sSfxUnlock;			
	zSTRING					m_sSfxUseLocked;		
	static zCClassDef		*classDef;
public:
	void zMover(void)
	{
		XCALL(0x00610D20);
	};

	zCMover(void)
	{
		zMover();
	};

	void ClearStateInternals(void)
	{
		XCALL(0x00610F40);
	};

	void UpdateInternals(void)
	{
		XCALL(0x00611270);
	};

	static zTMov_Keyframe GetKeyframe(zCVob*)
	{
		XCALL(0x006112F0);
	};

	void AdvanceKeyframe_KF(void)
	{
		XCALL(0x006113D0);
	};

	void SetToKeyframe_KF(float)
	{
		XCALL(0x00611400);
	};

	void InterpolateKeyframes_KF(void)
	{
		XCALL(0x00611900);
	};

	void AdvanceMover(void)
	{
		XCALL(0x00611D90);
	};

	void SetToKeyframe(float,float)
	{
		XCALL(0x00612090);
	};

	void InvertMovement(void)
	{
		XCALL(0x00612300);
	};

	void StartMovingSound(void)
	{
		XCALL(0x00612560);
	};

	void MoveToKeyframe(int)
	{
		XCALL(0x006125D0);
	};

	void DoOpen(void)
	{
		XCALL(0x00612640);
	};

	void FinishedOpening(void)
	{
		XCALL(0x006126F0);
	};

	void DoClose(void)
	{
		XCALL(0x00612770);
	};

	void FinishedClosing(void)
	{
		XCALL(0x00612830);
	};

	void Unlock(zCVob*)
	{
		XCALL(0x00612880);
	};

	void Lock(zCVob*)
	{
		XCALL(0x00612A50);
	};

	int IsKeyToThisMover(zCVob*)
	{
		XCALL(0x00612C20);
	};

	void TriggerMover(zCVob*)
	{
		XCALL(0x00612CB0);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00610F00);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x006137E0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00613AA0);
	};

	virtual ~zCMover()
	{
		XCALL(0x00611000);
	};

	virtual void OnTrigger(zCVob*,zCVob*)
	{
		XCALL(0x00613080);
	};

	virtual void OnUntrigger(zCVob*,zCVob*)
	{
		XCALL(0x00613170);
	};

	virtual void OnTouch(zCVob*)
	{
		XCALL(0x00613340);
	};

	virtual void OnDamage(zCVob*,zCVob*,float,int,zVEC3 const&)
	{
		XCALL(0x00613400);
	};

	virtual void OnMessage(zCEventMessage*,zCVob*)
	{
		XCALL(0x00613450);
	};

	virtual void OnTick(void)
	{
		XCALL(0x00612F80);
	};

	virtual void PostLoad(void)
	{
		XCALL(0x006137D0);
	};

	virtual int CanThisCollideWith(zCVob*)
	{
		XCALL(0x006111F0);
	};

	virtual void SetVisual(zCVisual*)
	{
		XCALL(0x006123A0);
	};
};

enum zTListProcess
{
	zLP_ALL,			
	zLP_NEXT_ONE,		
	zLP_RAND_ONE		
};

class zCTriggerList : public zCTrigger
{
	zSTRING			m_sTriggerTarget[6];	
	float			m_fFireDelay[6];		
	zTListProcess	m_ListProcess;			
	int				m_nActTarget;			
	BOOL			m_bSendOnTrigger;		
public:
	static zCClassDef *classDef;

	void zTriggerList(void)
	{
		XCALL(0x00614B50);
	};

	zCTriggerList(void)
	{
		zTriggerList();
	};

	void Init(void)
	{
		XCALL(0x00614E00);
	};

	void TriggerActTarget(zCVob*)
	{
		XCALL(0x00614F30);
	};

	int ProcessActTarget(zCVob*)
	{
		XCALL(0x00615000);
	};

	void FinishActivation(void)
	{
		XCALL(0x00615090);
	};

	void DoTriggering(zCVob*)
	{
		XCALL(0x00615190);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0060CE80);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00615490);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00615770);
	};

	virtual ~zCTriggerList()
	{
		XCALL(0x00614CF0);
	};

	virtual void OnTimer(void)
	{
		XCALL(0x00615100);
	};

	virtual zSTRING const* GetTriggerTarget(const int i=0)const 
	{
		XCALL(0x00614F10);
	};

	virtual void TriggerTarget(zCVob*)
	{
		XCALL(0x00615460);
	};

	virtual void UntriggerTarget(zCVob*)
	{
		XCALL(0x00615470);
	};
};

class zCTriggerTeleport : public zCTrigger
{
	zSTRING			m_sSfxTeleport;
	zCSoundFX*		m_pSfxTeleport;
public:
	static zCClassDef *classDef;

	void zTriggerTeleport(void)
	{
		XCALL(0x00614120);
	};

	zCTriggerTeleport(void)
	{
		zTriggerTeleport();
	};

	void DoTeleport(zCVob*)
	{
		XCALL(0x00614440);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0060D470);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x006146C0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x006146F0);
	};

	virtual ~zCTriggerTeleport()
	{
		XCALL(0x006142D0);
	};

	virtual void OnTrigger(zCVob*,zCVob*)
	{
		XCALL(0x006146A0);
	};

	virtual void OnUntrigger(zCVob*,zCVob*)
	{
		XCALL(0x006146B0);
	};

	virtual void OnTouch(zCVob*)
	{
		XCALL(0x00614690);
	};
};

class zCCodeMaster : public zCTriggerBase
{
public:
	struct BIT_ARRAY
	{
		BYTE		tOrderRelevant:1;		
		BYTE		tUntriggerCancels:1;	
		BYTE		tFirstFalseIsFailure:1;	
	};
	zSTRING			m_sSlaveVobNames[6];		
	zSTRING			m_sTriggerTargetFailure;	
	union
	{
		BYTE		m_dbFlags;					
		BIT_ARRAY	f;
	};
	zCVob*			m_pSlaveTriggered[6];		
	int				m_nNumSlavesTriggered;		
	static zCClassDef *classDef;

	void zCodeMaster(void)
	{
		XCALL(0x00618B80);
	};

	zCCodeMaster(void)
	{
		zCodeMaster();
	};

	void Init(void)
	{
		XCALL(0x00618EC0);
	};

	void Reset(void)
	{
		XCALL(0x00619040);
	};

	void FireTriggerSuccess(zCVob*)
	{
		XCALL(0x00619090);
	};

	void FireTriggerFailure(zCVob*)
	{
		XCALL(0x00619170);
	};

	int GetSlaveNr(zCVob*)
	{
		XCALL(0x00619250);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0060C0E0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00619670);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00619A80);
	};

	virtual ~zCCodeMaster()
	{
		XCALL(0x00618D60);
	};

	virtual void OnTrigger(zCVob*,zCVob*)
	{
		XCALL(0x00619300);
	};

	virtual void OnUntrigger(zCVob*,zCVob*)
	{
		XCALL(0x00619500);
	};

	virtual void OnTouch(zCVob*)
	{
		XCALL(0x0060C100);
	};

	virtual void OnUntouch(zCVob*)
	{
		XCALL(0x0060C0F0);
	};

	virtual void OnMessage(zCEventMessage*,zCVob*)
	{
		XCALL(0x00619600);
	};

	virtual zSTRING const* GetTriggerTarget(const int i=0)const 
	{
		XCALL(0x00619E40);
	};
};

class zCMoverControler : public zCTriggerBase
{
public:
	zCEventMover::zTEventMoverSubType	m_MoverMessage;		
	int									m_nGotoFixedKey;	
	static zCClassDef *classDef;
	void zMoverControler(void)
	{
		XCALL(0x00619E70);
	};

	zCMoverControler(void)
	{
		zMoverControler();
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0060C470);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0061A0D0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0061A340);
	};

	virtual ~zCMoverControler(void)
	{
		XCALL(0x00619F60);
	};

	virtual void OnTrigger(zCVob*,zCVob*)
	{
		XCALL(0x00619FC0);
	};

	virtual void OnUntrigger(zCVob*,zCVob*)
	{
		XCALL(0x0060C480);
	};

	virtual void OnTouch(zCVob*)
	{
		XCALL(0x0060C4A0);
	};

	virtual void OnUntouch(zCVob*)
	{
		XCALL(0x0060C490);
	};
};

class zCTriggerUntouch : public zCTriggerBase
{
public:
	static zCClassDef *classDef;
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0060B900);
	};

	virtual ~zCTriggerUntouch(void)
	{
		XCALL(0x0060B970);
	};

	virtual void OnTrigger(zCVob*,zCVob*)
	{
		XCALL(0x0060B920);
	};

	virtual void OnUntrigger(zCVob*,zCVob*)
	{
		XCALL(0x0060B930);
	};

	virtual void OnTouch(zCVob*)
	{
		XCALL(0x0060B910);
	};

	virtual void OnUntouch(zCVob*)
	{
		XCALL(0x00618A50);
	};
};