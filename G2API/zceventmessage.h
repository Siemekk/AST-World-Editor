#pragma once

#include "ztypes.h"
#include "ocnpc.h"

class zCNetVobControl;
class zCCutscene;

class zCEventMessage : public zCObject
{
public:
	zCLASS(zCEventMessage);
	
	enum zTTimeBehavior {TBZero, TBFix, TBUnknown, TBAssembled};

	WORD					subType;
	BOOL					inCutscene;

	WORD GetSubType() const { return subType; };
	static zCClassDef	*classDef;

	void zEventMessage()
	{
		XCALL(0x00413B60);
	};

	zCEventMessage(void)
	{
		zEventMessage();
	};
public:
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00401F30);
	};

	
	virtual BOOL			IsOverlay			() { return FALSE; };
	virtual	BOOL			IsNetRelevant		() { return FALSE; };
	virtual	BOOL			IsHighPriority		() { return FALSE; };
	virtual BOOL			IsJob				() { return FALSE; };
	virtual BOOL			GetIgnoreCutsceneMode(){ return FALSE; };

	
	virtual void			Delete				() { };
	virtual BOOL			IsDeleteable		() { return TRUE;	};
	virtual BOOL			IsDeleted			() { return FALSE;	};

	
	virtual void			SetCutsceneMode		(BOOL on)	{ inCutscene = on;	 };
	virtual BOOL			GetCutsceneMode		()			{ return inCutscene; };

	
	virtual int				MD_GetNumOfSubTypes	()			{ return 0; };
	virtual zSTRING			MD_GetSubTypeString	(int n)		{ return ""; };

	
	virtual zSTRING			MD_GetVobRefName	()			{ return ""; };
	virtual void			MD_SetVobRefName	(const zSTRING & name)	{};
	virtual void			MD_SetVobParam		(zCVob* vob)			{};

	virtual zTTimeBehavior	MD_GetTimeBehavior	()			{ return TBZero; };
	virtual float			MD_GetMinTime		()			{ return 0.0F; };		
	
	virtual void			Pack				(zCBuffer& buffer, zCEventManager* evManContext) {};		
	virtual void			Unpack				(zCBuffer& buffer, zCEventManager* evManContext) {};		
	virtual void Archive(zCArchiver &)
	{
		XCALL(0x006057C0);
	};

	virtual void Unarchive(zCArchiver &)
	{
		XCALL(0x006059C0);
	};
	virtual ~zCEventMessage()
	{
		XCALL(0x004020D0);
	};
};

class oCNpcMessage : public zCEventMessage
{
public:
	zCLASS(oCNpcMessage)
public:
	zSTRING					targetVobName;		
	BOOL					highPriority  :1;
	BOOL					deleted       :1;
	BOOL					inUse         :1;
	static zCClassDef	*classDef;
	
	void oNpcMessage()
	{
		XCALL(0x00764DC0);
	};

	oCNpcMessage(void)
	{
		oNpcMessage();
	};
public:

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x007630F0);
	};

	virtual ~oCNpcMessage()
	{
		XCALL(0x00764EA0);
	};

	
	virtual void			Delete				()				{ deleted	= TRUE;	};
	virtual void			SetInUse			(BOOL in)		{ inUse		= in;	};
	virtual BOOL			IsInUse				()				{ return inUse;		};
	virtual void			SetHighPriority		(BOOL high)	{ highPriority = high; };
	virtual BOOL			GetIgnoreCutsceneMode()				{ return FALSE; };
protected:
	
	virtual BOOL			IsOverlay			()				{ return FALSE;		};
	virtual BOOL			IsJob				()				{ return TRUE;		};
	virtual BOOL			IsDeleted			()				{ return deleted;	};
	virtual BOOL			IsDeleteable		()				{ return TRUE;		};
	virtual BOOL			IsHighPriority		()				{ return highPriority; };

	virtual void Archive(zCArchiver &)
	{
		XCALL(0x00764F00);
	};

	virtual void Unarchive(zCArchiver &)
	{
		XCALL(0x00764F70);
	};
};

class oCMsgAttack : public oCNpcMessage		
{
public:
	zCLASS(oCMsgAttack)
public:
	enum TAttackSubType
	{
		EV_ATTACKFORWARD = 0,
		EV_ATTACKLEFT,
		EV_ATTACKRIGHT,
		EV_ATTACKRUN,
		EV_ATTACKFINISH,
		EV_PARADE,
		EV_AIMAT,
		EV_SHOOTAT,
		EV_STOPAIM,
		EV_DEFEND,
		EV_ATTACKBOW,
		EV_ATTACKMAGIC,
		EV_ATTACK_MAX
	};

	int						combo;
	zCVob*					target;
	zTModelAniID			hitAni;
	float					startFrame;

	BOOL					enableNextHit:1;
	BOOL					reachedTarget:1;
	static zCClassDef	*classDef;
	
	void oMsgAttack()
	{
		XCALL(0x00766F00);
	};
	
	void oMsgAttack(TAttackSubType, int, int)
	{
		XCALL(0x00767060);
	};
	
	void oMsgAttack(TAttackSubType,zCVob *, float)
	{
		XCALL(0x00767130);
	};

	oCMsgAttack()
	{
		oMsgAttack();
	};

	oCMsgAttack(TAttackSubType type, int aniTarget = -1, BOOL combo = TRUE)
	{
		oMsgAttack(type,aniTarget,combo);
	};

	oCMsgAttack(TAttackSubType type, zCVob* pVob, float time = 0)
	{
		oMsgAttack(type,pVob,time);
	};
public:
	
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00763E40);
	};

	virtual BOOL			IsNetRelevant		()	{ return TRUE; };
	virtual BOOL			IsOverlay			()	{ return ((subType == EV_AIMAT) || (subType == EV_DEFEND)); }

	
	virtual int				MD_GetNumOfSubTypes	()												{XCALL(0x007676A0)};
	virtual zSTRING			BOOL	(int n)														{XCALL(0x007676B0)};
	
	
	virtual void			Pack				(zCBuffer& buffer, zCEventManager* evManContext){XCALL(0x007673A0)};
	virtual void			Unpack				(zCBuffer& buffer, zCEventManager* evManContext){XCALL(0x00767530)};

	
	virtual void			Archive				(zCArchiver& arc)								{XCALL(0x00767210)};
	virtual void			Unarchive			(zCArchiver& arc)								{XCALL(0x007672B0)};
};

class oCMsgWeapon : public oCNpcMessage
{
public:
	zCLASS(oCMsgWeapon)
public:
	enum TWeaponSubType
	{
		EV_DRAWWEAPON = 0,
		EV_DRAWWEAPON1,
		EV_DRAWWEAPON2,
		EV_REMOVEWEAPON,
		EV_REMOVEWEAPON1,
		EV_REMOVEWEAPON2,
		EV_CHOOSEWEAPON,
		EV_FORCEREMOVEWEAPON,
		EV_ATTACK,
		EV_EQUIPBESTWEAPON,
		EV_EQUIPBESTARMOR,
		EV_UNEQUIPWEAPONS,
		EV_UNEQUIPARMOR,
		EV_EQUIPARMOR,
		EV_WEAPON_MAX
	};

	int						targetMode;
	BOOL					duringRun       :1;
	BOOL					initDone        :1;
	BOOL					firstTime       :1;
	BOOL					useFist         :1;
	BOOL					showMagicCircle :1;

	zTModelAniID			ani;
	static zCClassDef	*classDef;


	void oMsgWeapon()
	{
		XCALL(0x00766710);
	};
	
	void oMsgWeapon(TWeaponSubType, int, int)
	{
		XCALL(0x007667D0);
	};
	
	oCMsgWeapon()
	{
		oMsgWeapon();
	};

	oCMsgWeapon(TWeaponSubType type, int mode = 0, BOOL bFist = FALSE)
	{
		oMsgWeapon(type,mode,bFist);
	};

public:

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x007637D0);
	};

	virtual ~oCMsgWeapon()
	{
		XCALL(0x00763810);
	};
	virtual int				MD_GetNumOfSubTypes	(){XCALL(0x00766AC0)};
	virtual zSTRING			MD_GetSubTypeString	(int n){XCALL(0x00766AD0)};
	
	virtual zTTimeBehavior	MD_GetTimeBehavior	(){XCALL(0x00766EE0)};
	virtual float			MD_GetMinTime		(){XCALL(0x00766EF0)};
	virtual void Archive(zCArchiver &)
	{
		XCALL(0x007668B0);
	};
	virtual void Unarchive(zCArchiver &)
	{
		XCALL(0x00766980);
	};
};

class oCMsgManipulate : public oCNpcMessage
{
public:
	zCLASS(oCMsgManipulate)
public:
	enum TManipulateSubType
	{
		EV_TAKEVOB	= 0,
		EV_DROPVOB,
		EV_THROWVOB,
		EV_EXCHANGE,
		EV_USEMOB,
		EV_USEITEM,
		EV_INSERTINTERACTITEM,		
		EV_REMOVEINTERACTITEM,		
		EV_CREATEINTERACTITEM,		
		EV_DESTROYINTERACTITEM,		
		EV_PLACEINTERACTITEM,		
		EV_EXCHANGEINTERACTITEM,	
		EV_USEMOBWITHITEM,			
		EV_CALLSCRIPT,				
		EV_EQUIPITEM,				
		
		EV_USEITEMTOSTATE,
		EV_TAKEMOB,
		EV_DROPMOB,
		EV_MANIP_MAX
	};

	zSTRING	name;
	zSTRING slot;
	zCVob*	targetVob;
	BOOL	flag;				
	float	aniCombY;
	union
	{
		int				npcSlot;
		int				targetState;
		zTModelAniID	aniID;
	};
	static zCClassDef	*classDef;


	void oMsgManipulate(TManipulateSubType)
	{
		XCALL(0x00768870);
	};

	void oMsgManipulate(TManipulateSubType,zCVob*)
	{
		XCALL(0x00768940);
	};

	void oMsgManipulate(TManipulateSubType,int)
	{
		XCALL(0x00768A10);
	};

	void oMsgManipulate(TManipulateSubType,zSTRING const&,int)
	{
		XCALL(0x00768AE0);
	};

	void oMsgManipulate(TManipulateSubType,zCVob*,int)
	{
		XCALL(0x00768CB0);
	};

	void oMsgManipulate(TManipulateSubType,zSTRING const&,zSTRING const&)
	{
		XCALL(0x00768D80);
	};
	
	oCMsgManipulate(TManipulateSubType type)
	{
		oMsgManipulate(type);
	};
	oCMsgManipulate(TManipulateSubType type,zCVob* pVob)
	{
		oMsgManipulate(type,pVob);
	};
	oCMsgManipulate(TManipulateSubType type,int n)
	{
		oMsgManipulate(type,n);
	};
	oCMsgManipulate(TManipulateSubType type,zSTRING const& str,int n)
	{
		oMsgManipulate(type,str,n);
	};
	oCMsgManipulate(TManipulateSubType type,zCVob* pVob,int n)
	{
		oMsgManipulate(type,pVob,n);
	};
	oCMsgManipulate(TManipulateSubType type,zSTRING const& str0,zSTRING const& str1)
	{
		oMsgManipulate(type,str0,str1);
	};
public:

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00764780);
	};
	virtual ~oCMsgManipulate()
	{
		XCALL(0x00768840);
	};

	
	virtual int				MD_GetNumOfSubTypes	(){XCALL(0x00769540)};
	virtual zSTRING			MD_GetSubTypeString	(int n){XCALL(0x00769550)};

	
	virtual zSTRING			MD_GetVobRefName	()						{XCALL(0x00769A00)};
	virtual void			MD_SetVobRefName	(const zSTRING & name){XCALL(0x00769AB0)};
	virtual void			MD_SetVobParam		(zCVob* vob){XCALL(0x00769BF0)};

	
	virtual zTTimeBehavior	MD_GetTimeBehavior	(){XCALL(0x007699B0)};
	virtual float			MD_GetMinTime		(){XCALL(0x007699F0)};

	virtual BOOL			IsNetRelevant		()		{ return ((GetSubType()>=EV_INSERTINTERACTITEM) && (GetSubType()<=EV_EQUIPITEM)); };

	
	virtual void			Archive				(zCArchiver& arc){XCALL(0x00769040)};
	virtual void			Unarchive			(zCArchiver& arc){XCALL(0x00769120)};

	
	virtual void			Pack				(zCBuffer& buffer, zCEventManager* evManContext){XCALL(0x00769240)};
	virtual void			Unpack				(zCBuffer& buffer, zCEventManager* evManContext){XCALL(0x00769330)};
};

class oCMsgMagic : public oCNpcMessage		
{
public:
	zCLASS(oCMsgMagic)
public:
	enum TConversationSubType
	{
		EV_OPEN		= 0,		
		EV_CLOSE,
		EV_MOVE,
		EV_INVEST,
		EV_CAST,
		EV_SETLEVEL,
		EV_SHOWSYMBOL,
		EV_SETFRONTSPELL,
		EV_CASTSPELL,
		EV_READY,
		EV_UNREADY,
		EV_MAGIC_MAX
	};

	int		what;			
	int		level;			
	BOOL	removeSymbol;
	int		manaInvested;
	int		energyLeft;
	zCVob*	target;
	zVEC3	targetPos;
	int		activeSpell;	
	static zCClassDef	*classDef;
	
	void oMsgMagic(TConversationSubType, int, BOOL)
	{
		XCALL(0x0076B1B0);
	};
	
	void oMsgMagic(TConversationSubType type)
	{
		XCALL(0x0076B100);
	};
	void oMsgMagic()
	{
		XCALL(0x0076B030);
	};
	
	oCMsgMagic()
	{
		oMsgMagic();
	}

	oCMsgMagic(TConversationSubType type)
	{
		oMsgMagic(type);
	}

	oCMsgMagic(TConversationSubType type, int what, BOOL bRemove)
	{
		oMsgMagic(type,what,bRemove);
	}
public:
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00764D80);
	};

	virtual ~oCMsgMagic()
	{
		XCALL(0x0076B260);
	};

	virtual BOOL			IsJob				()		{ return (GetSubType()==EV_CASTSPELL); };
	virtual BOOL			IsHighPriority		()		{ return (GetSubType()!=EV_CASTSPELL);  };
	virtual BOOL			IsNetRelevant		()		{ return FALSE;	};

	
	virtual int				MD_GetNumOfSubTypes	(){XCALL(0x0076B420)};
	virtual zSTRING			MD_GetSubTypeString	(int n){XCALL(0x0076B430)};

	
	virtual void			Archive				(zCArchiver& arc){XCALL(0x0076B5E0)};
	virtual void			Unarchive			(zCArchiver& arc){XCALL(0x0076B680)};

	
	virtual void			Pack				(zCBuffer& buffer, zCEventManager* evManContext){XCALL(0x0076B2C0)};
	virtual void			Unpack				(zCBuffer& buffer, zCEventManager* evManContext){XCALL(0x0076B360)};
}; 

class oCMsgMovement : public oCNpcMessage	
{
public:
	zCLASS(oCMsgMovement)
public:
	enum TMovementSubType
	{
		EV_ROBUSTTRACE = 0,
		EV_GOTOPOS,
		EV_GOTOVOB,
		EV_GOROUTE,
		EV_TURN,
		EV_TURNTOPOS,
		EV_TURNTOVOB,
		EV_TURNAWAY,
		EV_JUMP,
		EV_SETWALKMODE,
		EV_WHIRLAROUND,
		EV_STANDUP,
		EV_CANSEENPC,
		EV_STRAFE,
		EV_GOTOFP,
		EV_DODGE,
		EV_BEAMTO,
		EV_ALIGNTOFP,
		EV_MOVE_MAX
	};
	zSTRING					targetName;
	zCRoute*				route;
	zCVob*					targetVob;
	zVEC3					targetPos;
	float					angle;
	float					timer;
	int						targetMode;
	zTModelAniID			ani;
	static zCClassDef	*classDef;
	
	void oMsgMovement()
	{
		XCALL(0x00765650);
	};
	void oMsgMovement(TMovementSubType type, zSTRING const& wp)
	{
		XCALL(0x00765750);
	};
	void oMsgMovement(TMovementSubType type, zCVob* pVob)
	{
		XCALL(0x00765930);
	};
	void oMsgMovement(TMovementSubType, zVEC3 const &)
	{
		XCALL(0x00765A30);
	};
	void oMsgMovement(TMovementSubType type, float azimuth)
	{
		XCALL(0x00765B20);
	};
	void oMsgMovement(TMovementSubType type, int mode)
	{
		XCALL(0x00765C00);
	};
	
	oCMsgMovement()
	{
		oMsgMovement();
	}

	oCMsgMovement(TMovementSubType type, zSTRING const& wp)
	{
		oMsgMovement(type,wp);
	}

	oCMsgMovement(TMovementSubType type, zCVob* pVob)
	{
		oMsgMovement(type,pVob);
	}

	oCMsgMovement(TMovementSubType type, zVEC3 const& pos)
	{
		oMsgMovement(type,pos);
	}

	oCMsgMovement(TMovementSubType type, float azimuth)
	{
		oMsgMovement(type,azimuth);
	}

	oCMsgMovement(TMovementSubType type, int mode)
	{
		oMsgMovement(type,mode);
	}
public:

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00763B50);
	};

	virtual ~oCMsgMovement						(){XCALL(0x00765720)};		

	virtual void			Delete				(){XCALL(0x007666B0)};

	
	virtual int				MD_GetNumOfSubTypes	(){XCALL(0x00766090)};
	virtual zSTRING			MD_GetSubTypeString	(int n){XCALL(0x007660A0)};

	
	virtual zSTRING			MD_GetVobRefName	(){XCALL(0x007664E0)};
	virtual void			MD_SetVobRefName	(const zSTRING & name){XCALL(0x00766560)};
	virtual void			MD_SetVobParam		(zCVob* vob){XCALL(0x007666A0)};

	
	virtual zTTimeBehavior	MD_GetTimeBehavior	(){XCALL(0x007666C0)};
	virtual float			MD_GetMinTime		(){XCALL(0x00766700)};
	
	virtual void			Archive				(zCArchiver& arc){XCALL(0x00765E00)};
	virtual void			Unarchive			(zCArchiver& arc){XCALL(0x00765F20)};
};

class oCMsgConversation : public oCNpcMessage
{
public:
	zCLASS(oCMsgConversation)
public:
	enum TConversationSubType
	{
		EV_PLAYANISOUND = 0,		
		EV_PLAYANI,
		EV_PLAYSOUND,
		EV_LOOKAT,
		EV_OUTPUT,
		EV_OUTPUTSVM,
		EV_CUTSCENE,
		EV_WAITTILLEND,
		EV_ASK,
		EV_WAITFORQUESTION,
		EV_STOPLOOKAT,
		EV_STOPPOINTAT,
		
		EV_POINTAT,
		EV_QUICKLOOK,
		EV_PLAYANI_NOOVERLAY,
		EV_PLAYANI_FACE,

		EV_PROCESSINFOS,
		EV_STOPPROCESSINFOS,
		EV_OUTPUTSVM_OVERLAY,
		EV_SNDPLAY,
		EV_SNDPLAY3D,
		EV_PRINTSCREEN,
		EV_STARTFX,
		EV_STOPFX,
		EV_CONV_MAX
	};
	zSTRING					text;		
	zSTRING					name;		
	zCVob*					target;		
	zVEC3					targetPos;
	zTModelAniID			ani;
	union
	{
		zCModelAni*			cAni;			
		zCEventMessage*		watchMsg;
	};
	zTSoundHandle			handle;
	float					timer;
	int						number;
	int						f_no;
	int						f_yes;
	static zCClassDef	*classDef;

	void oMsgConversation()
	{
		XCALL(0x00769C00);
	};
	void oMsgConversation(TConversationSubType type)
	{
		XCALL(0x00769D00);
	};
	void oMsgConversation(TConversationSubType,zSTRING const &)
	{
		XCALL(0x00769DE0);
	};
	void oMsgConversation(TConversationSubType type, zSTRING const& block, zSTRING const& text)
	{
		XCALL(0x00769FD0);
	};
	void oMsgConversation(TConversationSubType type, zCVob* pVob)
	{
		XCALL(0x0076A1E0);
	};
	void oMsgConversation(TConversationSubType type, int pVob)
	{
		XCALL(0x0076A2C0);
	};
	void oMsgConversation(TConversationSubType type, int funcYes, int funcNo, float waitTime)
	{
		XCALL(0x0076A3A0);
	};
	
	oCMsgConversation()
	{
		oMsgConversation();
	};

	oCMsgConversation(TConversationSubType type)
	{
		oMsgConversation(type);
	};

	oCMsgConversation(TConversationSubType type, zSTRING const& block)
	{
		oMsgConversation(type,block);
	};

	oCMsgConversation(TConversationSubType type, zSTRING const& block, zSTRING const& text)
	{
		oMsgConversation(type,block,text);
	};

	oCMsgConversation(TConversationSubType type, zCVob* pVob)
	{
		oMsgConversation(type,pVob);
	};

	oCMsgConversation(TConversationSubType type, int n)
	{
		oMsgConversation(type,n);
	};

	oCMsgConversation(TConversationSubType type, int funcYes, int funcNo, float waitTime)
	{
		oMsgConversation(type,funcYes,funcNo,waitTime);
	};
public:

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00764AB0);
	};

	virtual ~oCMsgConversation					(){XCALL(0x0076A4A0)};

	virtual BOOL			IsOverlay			(){XCALL(0x0076AB00)};				
	virtual	void			Delete				(){XCALL(0x0076A910)};

		
	virtual int				MD_GetNumOfSubTypes	(){XCALL(0x0076A900)};
	virtual zSTRING			MD_GetSubTypeString	(int n){XCALL(0x0076AB60)};

	
	virtual zSTRING			MD_GetVobRefName	(){XCALL(0x0076AD60)};
	virtual void			MD_SetVobRefName	(const zSTRING & name){XCALL(0x0076ADB0)};
	virtual void			MD_SetVobParam		(zCVob* vob){XCALL(0x0076AEF0)};

	
	virtual zTTimeBehavior	MD_GetTimeBehavior	(){XCALL(0x0076AF00)};
	virtual float			MD_GetMinTime		(){XCALL(0x0076AF50)};
	
	virtual void			Archive				(zCArchiver& arc){XCALL(0x0076A570)};
	virtual void			Unarchive			(zCArchiver& arc){XCALL(0x0076A660)};
};

class zCEventManager : public zCObject
{
public:
	zCLASS(zCEventManager)
public:
	
	BOOL					cleared;			
	BOOL					active;				
	zCCutscene*				cutscene;			
	zCArray<zCEventMessage*>messageList;
	zCVob*					hostVob;
	static zCClassDef		*classDef;
	void zEventManager()
	{
		XCALL(0x00785FB0);
	};
	void zEventManager(zCVob* pVob)
	{
		XCALL(0x00786100);
	};
	zCEventManager()
	{
		zEventManager();
	};
	zCEventManager(zCVob* pVob)
	{
		zEventManager(pVob);
	};
public:
	virtual zCClassDef*		_GetClassDef		(void)const											{XCALL(0x00785F00)};
	virtual					~zCEventManager		()													{XCALL(0x007860D0)};
	virtual	void			OnTrigger			(zCVob* otherVob, zCVob *vobInstigator)				{XCALL(0x007879F0)}; 
	virtual	void			OnUntrigger			(zCVob* otherVob, zCVob *vobInstigator)				{XCALL(0x00787AB0)}; 
	virtual void			OnTouch				(zCVob* otherVob)									{XCALL(0x00787860)}; 
	virtual void			OnUntouch			(zCVob* otherVob)									{XCALL(0x00787920)}; 
	virtual void			OnTouchLevel		()													{XCALL(0x007879E0)}; 
	virtual void			OnDamage			(zCVob*			otherVob, 
												 zCVob*			inflictorVob, 
												 float			damage,  
												 int			damageType, 
												 const zVEC3&	hitLocation)						{XCALL(0x00787B70)}; 
	virtual void			OnMessage			(zCEventMessage *eventMessage, zCVob* sourceVob)	{XCALL(0x00786380)};
	virtual void			Clear				()													{XCALL(0x00787580)};	
			void			KillMessages		()													{XCALL(0x00786320)};
	virtual BOOL			IsEmpty				(BOOL ignoreOverlays=FALSE)							{XCALL(0x00787780)};	
	
	virtual BOOL			GetCutsceneMode		()													{XCALL(0x00787570)};

	virtual void			SetCutscene			(zCCutscene* context)								{XCALL(0x007874F0)};	
	virtual zCCutscene*		GetCutscene			()													{XCALL(0x00787560)};

	virtual BOOL			IsRunning			(zCEventMessage* eventMessage)						{XCALL(0x007877E0)};
	virtual void			SetActive			(BOOL active)										{XCALL(0x00787110)};

	
	virtual	int				GetNumMessages		()													{ return messageList.GetNumInList(); };
	virtual zCEventMessage*	GetEventMessage		(int nr)											{XCALL(0x00787C40)};
	virtual zCEventMessage* GetActiveMessage	()													{XCALL(0x00787810)};

	
	virtual void			ShowList			(int x, int y)										{XCALL(0x00787C50)};

	
	virtual zCNetVobControl*GetNetVobControl	(BOOL dontCreateIfNotPresent = FALSE)				{ return NULL; };
	virtual void			RemoveFromList		(zCEventMessage* eventMessage)						{XCALL(0x007872B0)};
	virtual void			InsertInList		(zCEventMessage* eventMessage)						{XCALL(0x00787300)};
	virtual void			ProcessMessageList	()													{XCALL(0x00787000)};
	virtual void			SendMessageToHost	(zCEventMessage* msg, zCVob* hostVob, zCVob* srcVob){XCALL(0x00786C60)};
	
	virtual void			Delete				(zCEventMessage* event)								{XCALL(0x00787270)};

	
	virtual void			Archive				(zCArchiver& arc)									{XCALL(0x00787F00)};
	virtual void			Unarchive			(zCArchiver& arc)									{XCALL(0x00787F40)};
};

class oCMobMsg : public zCEventMessage
{
public:
	zCLASS(oCMobMsg)
public:
	enum TMobMsgSubType
	{
		EV_STARTINTERACTION = 0,
		EV_STARTSTATECHANGE,
		EV_ENDINTERACTION,
		EV_UNLOCK,
		EV_LOCK,
		EV_CALLSCRIPT
	};
public:
	void oMobMsg(oCMobMsg::TMobMsgSubType,oCNpc*)
	{
		XCALL(0x0071B220);
	};

	void oMobMsg(void)
	{
		XCALL(0x0071B3A0);
	};

	void oMobMsg(oCMobMsg::TMobMsgSubType,oCNpc*,int)
	{
		XCALL(0x0071B4D0);
	};

	oCMobMsg(oCMobMsg::TMobMsgSubType type,oCNpc* pNpc)
	{
		oMobMsg(type,pNpc);
	};

	oCMobMsg(void)
	{
		oMobMsg();
	};

	oCMobMsg(oCMobMsg::TMobMsgSubType type,oCNpc* pNpc,int state)
	{
		oMobMsg(type,pNpc,state);
	};

	virtual zCClassDef* _GetClassDef		(void)const										{XCALL(0x0071B200)};

	virtual BOOL		IsNetRelevant		()												{ return TRUE; };

	virtual int			MD_GetNumOfSubTypes	()												{XCALL(0x0071B740)};
	virtual zSTRING		MD_GetSubTypeString	(int n)											{XCALL(0x0071B750)};

protected:
	
	virtual void		Pack				(zCBuffer& buffer, zCEventManager* evManContext){XCALL(0x0071B620)};
	virtual void		Unpack				(zCBuffer& buffer, zCEventManager* evManContext){XCALL(0x0071B6A0)};
private:
	oCNpc*				npc;
	int					from;
	int					to     :31;
	BOOL				playAni:1;
	static zCClassDef *classDef;
};

class oCMsgDamage : public oCNpcMessage
{
public:
	zCLASS(oCMsgDamage)
	friend class oCNpc;
public:
	enum TDamageSubType 
	{
		EV_DAMAGE_ONCE		= 0	,
		EV_DAMAGE_PER_FRAME		,	
		EV_DAMAGE_MAX
	};
	virtual zCClassDef*		_GetClassDef(void)const					{XCALL(0x007634B0)};
	virtual BOOL			IsNetRelevant		()					{ return TRUE; };
	virtual BOOL			IsOverlay			()					{ return ( this->subType == EV_DAMAGE_PER_FRAME ); }
	virtual BOOL			IsDeleteable		()					{ return FALSE; };
	virtual BOOL			IsHighPriority		()					{ return (this->highPriority = TRUE); };

	virtual int				MD_GetNumOfSubTypes	()					{XCALL(0x007653B0)};
	virtual zSTRING			MD_GetSubTypeString	( int nSubType )	{XCALL(0x007653C0)};
	
	
	
	oCNpc::oSDamageDescriptor	descDamage	;
	virtual	~oCMsgDamage						()					{XCALL(0x007652D0)};
	
	virtual void			Pack				( zCBuffer& buffer, zCEventManager* evManContext ){XCALL(0x007654F0)};
	virtual void			Unpack				( zCBuffer& buffer, zCEventManager* evManContext ){XCALL(0x00765500)};
	
	virtual void			Archive				( zCArchiver& arc )	{XCALL(0x00765510)};
	virtual void			Unarchive			( zCArchiver& arc )	{XCALL(0x00765590)};
	static zCClassDef *classDef;
	void oMsgDamage(void)
	{
		XCALL(0x00765010);
	};

	oCMsgDamage(void)
	{
		oMsgDamage();
	};

	void oMsgDamage(oCMsgDamage::TDamageSubType)
	{
		XCALL(0x00765110);
	};

	oCMsgDamage(oCMsgDamage::TDamageSubType type)
	{
		oMsgDamage(type);
	};

	void oMsgDamage(oCMsgDamage::TDamageSubType, oCNpc::oSDamageDescriptor const&)
	{
		XCALL(0x007651E0);
	};

	oCMsgDamage(oCMsgDamage::TDamageSubType type, oCNpc::oSDamageDescriptor const& desc)
	{
		oMsgDamage(type,desc);
	};
};

class oCMsgState : public oCNpcMessage		
{
public:
	zCLASS(oCMsgState)
	friend class oCNpc;
public:
	enum TStateSubType
	{
		EV_STARTSTATE = 0,
		EV_WAIT,
		EV_SETNPCSTOSTATE,
		EV_SETTIME,
		EV_APPLYTIMEDOVERLAY,
		EV_STATE_MAX
	};
private:
	int						function;
	int						minutes;
	int						instance;
	zSTRING					wp;
	float					timer;
	oCNpc					*other,*victim;

	BOOL					endOldState    :1;
	BOOL					inRoutine      :1;
public:
	static zCClassDef* classDef;

	void oMsgState(void)
	{
		XCALL(0x00767E00);
	};

	oCMsgState(void)
	{
		oMsgState();
	};	

	void oMsgState(oCMsgState::TStateSubType,float)
	{
		XCALL(0x00767F00);
	};

	oCMsgState(oCMsgState::TStateSubType type,float time)
	{
		oMsgState(type,time);
	};

	void oMsgState(oCMsgState::TStateSubType,int)
	{
		XCALL(0x00767FE0);
	};

	oCMsgState(oCMsgState::TStateSubType type,int state)
	{
		oMsgState(type,state);
	};

	void oMsgState(oCMsgState::TStateSubType,int,int,zSTRING const&)
	{
		XCALL(0x007680C0);
	};

	oCMsgState(oCMsgState::TStateSubType type, int state, BOOL behaviour, zSTRING const& nameWp)
	{
		oMsgState(type,state,behaviour,nameWp);
	};

	virtual zCClassDef* _GetClassDef(void)const								{XCALL(0x00764470)};
	virtual ~oCMsgState()													{XCALL(0x007682B0)};
	int						MD_GetNumOfSubTypes	()							{XCALL(0x007684E0)};
	zSTRING					MD_GetSubTypeString	(int n)						{XCALL(0x007684F0)};
	zTTimeBehavior			MD_GetTimeBehavior	()							{XCALL(0x00768720)};
	float					MD_GetMinTime		()							{XCALL(0x00768730)};
	virtual BOOL			IsOverlay			()							{ return ( subType == EV_APPLYTIMEDOVERLAY ); }
	
	virtual void			Archive				(zCArchiver& arc)			{XCALL(0x00768340)};
	virtual void			Unarchive			(zCArchiver& arc)			{XCALL(0x007683F0)};
};

class oCMsgUseItem : public oCNpcMessage		
{
public:
	zCLASS(oCMsgUseItem)
	friend class oCNpc;
public:
	enum TUseItemSubType
	{
		EV_DRINK = 0,
		EV_EQUIPITEM,
		EV_UNEQUIPITEM,
		EV_USEITEM_MAX
	};
private:
	zCVob*					vob;
	zTModelAniID			ani;
	int						state;
public:
	static zCClassDef *classDef;
	void oMsgUseItem(void)
	{
		XCALL(0x00767A20);
	};

	oCMsgUseItem(void)
	{
		oMsgUseItem();
	};

	void oMsgUseItem(oCMsgUseItem::TUseItemSubType,zCVob*)
	{
		XCALL(0x00767B10);
	};

	oCMsgUseItem(oCMsgUseItem::TUseItemSubType type,zCVob* pVob)
	{
		oMsgUseItem(type,pVob);
	};

	virtual zCClassDef* _GetClassDef(void)const													{XCALL(0x00764170)};
	virtual ~oCMsgUseItem						()												{XCALL(0x00767BD0)};
	virtual BOOL			IsNetRelevant		()												{ return TRUE; };
	
	virtual void			Pack				(zCBuffer& buffer, zCEventManager* evManContext){XCALL(0x00767C30)};
	virtual void			Unpack				(zCBuffer& buffer, zCEventManager* evManContext){XCALL(0x00767C80)};
	
	virtual void			Archive				(zCArchiver& arc)								{XCALL(0x00767CD0)};
	virtual void			Unarchive			(zCArchiver& arc)								{XCALL(0x00767D50)};
};

class zCEvMsgCutscene : public zCEventMessage	
{
public:
	zCLASS(zCEvMsgCutscene)
	friend class oCNpc;
	friend class zCCutscene;
public:
	enum TCutsceneSubType
	{
		EV_CS_STARTPLAY	= 0,
		EV_CS_STOP,		
		EV_CS_INTERRUPT,
		EV_CS_RESUME,		
		EV_CS_MAX
	};
private:
	zSTRING csName;
	BOOL	isOutputUnit;
	BOOL	isGlobalCutscene;
	BOOL	isMainRole;
	BOOL	deleted;
public:
	static zCClassDef *classDef;

	void zEvMsgCutscene(zCEvMsgCutscene::TCutsceneSubType)
	{
		XCALL(0x0040C4F0);
	};

	zCEvMsgCutscene(zCEvMsgCutscene::TCutsceneSubType type)
	{
		zEvMsgCutscene(type);
	};

	virtual zCClassDef* _GetClassDef(void)const		{XCALL(0x0040B870)};
	virtual ~zCEvMsgCutscene()						{XCALL(0x0040C640)};

	void	SetCutsceneName		(zSTRING _csName)	{ csName=_csName;csName.Upper();};
	void	SetIsOutputUnit		(BOOL ou)			{ isOutputUnit = ou;			};
	void	SetIsGlobalCutscene	(BOOL global)		{ isGlobalCutscene = global;	};
	void	SetIsMainRole		(BOOL main)			{ isMainRole = main;			};

	zSTRING	GetCutsceneName	()						{ return csName;				};
	BOOL	IsOutputUnit	()						{ return isOutputUnit;			};
	BOOL	IsGlobalCutscene()						{ return isGlobalCutscene;		};
	BOOL	IsMainRole		()						{ return isMainRole;			};

	virtual	BOOL		IsHighPriority		()		{ return TRUE;					};
	
	virtual void		Delete				()		{ deleted = TRUE;				};
	virtual BOOL		IsDeleted			()		{ return deleted;				};

	virtual int			MD_GetNumOfSubTypes	()		{XCALL(0x0040C6A0)};
	virtual zSTRING		MD_GetSubTypeString	(int n)	{XCALL(0x0040C6B0)};
};

class zCEventCore : public zCEventMessage
{
public:
	zCLASS(zCEventCore)
public:
	enum zTEventCoreSubType
	{
		zEVENT_TRIGGER=0,
		zEVENT_UNTRIGGER,
		zEVENT_TOUCH,
		zEVENT_UNTOUCH,
		zEVENT_TOUCHLEVEL,
		zEVENT_DAMAGE,
		zEVENT_CORE_NUM_SUBTYPES
	};
private:
	zCVob*					otherVob;
	
	zCVob*					vobInstigator;		
	
	float					damage;
	int						damageType;
	zCVob*					inflictorVob;
	zPOINT3					hitLocation;
	static zCClassDef* classDef;
public:
	virtual zCClassDef* _GetClassDef(void)const														{XCALL(0x00402130)};
	
	virtual	int				MD_GetNumOfSubTypes	()													{ return zEVENT_CORE_NUM_SUBTYPES; };
	virtual	zSTRING			MD_GetSubTypeString	(int n)												{XCALL(0x006062F0)};
	virtual	BOOL			IsNetRelevant		()													{ return !((subType>=zEVENT_TOUCH) && (subType<=zEVENT_TOUCHLEVEL)); };
	
	zCVob*					GetOtherVob			() const											{ return otherVob;		};
	
	zCVob*					GetVobInstigator	() const											{ return vobInstigator;};
	
	float					GetDamage			() const											{ return damage;		};
	int						GetDamageType		() const											{ return damageType;	};
	zCVob*					GetInflictorVob		() const											{ return inflictorVob;	};
	zPOINT3					GetHitLocation		() const											{ return hitLocation;	};
	
	virtual void			Pack				(zCBuffer& buffer, zCEventManager* evManContext)	{XCALL(0x00606120)};
	virtual void			Unpack				(zCBuffer& buffer, zCEventManager* evManContext)	{XCALL(0x006061D0)};
	
	virtual void			Archive				(zCArchiver& arc)									{XCALL(0x006064F0)};
	virtual void			Unarchive			(zCArchiver& arc)									{XCALL(0x00606560)};
	virtual					~zCEventCore		()													{XCALL(0x00606100)};			
	void Clear(void)																				{XCALL(0x006060C0)};
};

class zCCSCamera_EventMsg : public zCEventMessage	
{
public:
	zCLASS(zCCSCamera_EventMsg)
	friend class oCCSManager;
	friend class zCAICamera;
	friend class zCCSCamera;
public:
	enum zTCSCam_EvSubType
	{	
		EV_NOTHING = 0,
		EV_PLAY,				
		EV_PAUSE,				
		EV_RESUME,				
		EV_STOP,				
		EV_GOTO_KEY,			
		EV_SET_DURATION,		
		EV_SET_TO_TIME,			
	};
	enum zTCamTrj_KFType
	{	
		KF_UNDEF=0,
		KF_TARGET,
		KF_CAM	
	};
	int	   key;
	float  time;
	BOOL  isDeleted;
	zTCamTrj_KFType kfType;
public:
	static zCClassDef *classDef;

	void zCSCamera_EventMsg(void)
	{
		XCALL(0x004C6C00);
	};

	zCCSCamera_EventMsg(void)
	{
		zCSCamera_EventMsg();
	};

	void zCSCamera_EventMsg(zCCSCamera_EventMsg::zTCSCam_EvSubType type)
	{
		XCALL(0x004C6D70);
	};

	zCCSCamera_EventMsg(zCCSCamera_EventMsg::zTCSCam_EvSubType type)
	{
		zCSCamera_EventMsg(type);
	};

	virtual zCClassDef* _GetClassDef			(void)const						{XCALL(0x004C3A40)};
	virtual ~zCCSCamera_EventMsg				()								{XCALL(0x004C6ED0)};
public:
	int						GetKey				()								{ return key; };
	float					GetTime				()								{ return time;};
	zTCamTrj_KFType			GetKFType			()								{ return kfType; };
	virtual BOOL			IsJob				()								{ if (subType == EV_PLAY || subType == EV_GOTO_KEY ) return TRUE; else return FALSE; };
	virtual	BOOL			IsHighPriority		()								{ return TRUE; };
	virtual BOOL			IsDeleted			()								{ return isDeleted; };
	virtual	void			Delete				()								{ isDeleted = TRUE; };
	
	virtual int				MD_GetNumOfSubTypes	()								{XCALL(0x004C7000)};
	virtual zSTRING			MD_GetSubTypeString	(int n)							{XCALL(0x004C7010)};
	virtual zTTimeBehavior	MD_GetTimeBehavior	()								{ if (subType == EV_PLAY || subType == EV_GOTO_KEY ) return TBFix; else return TBZero; };
	virtual float			MD_GetMinTime		();
	void					Archive				(zCArchiver &arc)				{XCALL(0x004C6EE0)};
	void					Unarchive			(zCArchiver &arc)				{XCALL(0x004C6F70)};
};

class zCCSCamera_EventMsgActivate : public zCEventMessage	
{
public:
	zCLASS(zCCSCamera_EventMsgActivate)
	friend class oCCSManager;
	friend class zCAICamera;
	friend class zCCSCamera;

    enum zTCSCam_ActivateSubType
	{  
		EV_DEACTIVATE = 0,
		EV_SETCAMREFERENCE,
		EV_SETTARGETREFERENCE
	};
    zSTRING                 referenceName;
	BOOL					isDeleted;
	zCVob*                  referenceVob;
	static zCClassDef *classDef;

	void zCSCamera_EventMsgActivate(zCCSCamera_EventMsgActivate::zTCSCam_ActivateSubType)
	{
		XCALL(0x004B4160);
	};

	zCCSCamera_EventMsgActivate(zCCSCamera_EventMsgActivate::zTCSCam_ActivateSubType type)
	{
		zCSCamera_EventMsgActivate(type);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x004021E0);
	};
	virtual ~zCCSCamera_EventMsgActivate			()							{ };
	void                    Archive                 (zCArchiver &arc)			{XCALL(0x004C7240)};
	void                    Unarchive               (zCArchiver &arc)			{XCALL(0x004C7270)};
public:
	virtual	BOOL					IsDeleted			()						{ return isDeleted; };
	virtual	void					Delete				()						{ isDeleted = TRUE; };
        
	virtual int                     MD_GetNumOfSubTypes     ()					{XCALL(0x004C7400)};
	virtual zSTRING                 MD_GetSubTypeString     (int n)				{XCALL(0x004C7410)};

    
	virtual zSTRING                 MD_GetVobRefName        ()					{XCALL(0x004C7530)};
	virtual void                    MD_SetVobRefName        (const zSTRING&name){XCALL(0x004C7580)};
	virtual void                    MD_SetVobParam          (zCVob* vob)		{XCALL(0x004C76C0)};
};

class zCEventCommon : public zCEventMessage	
{
public:
	zCLASS(zCEventCommon)
public:
	enum zTEventCommonSubType
	{
		zEVENT_ENABLE=0,
		zEVENT_DISABLE,
		zEVENT_TOGGLE_ENABLED,
		zEVENT_RESET,
		zEVENT_MISC_NUM_SUBTYPES
	};

	static zCClassDef *classDef;
	zCEventCommon() {};
	virtual zCClassDef* _GetClassDef(void)const			{XCALL(0x0060F0C0)};
	
	virtual	int				MD_GetNumOfSubTypes	()		{ return zEVENT_MISC_NUM_SUBTYPES; };
	virtual	zSTRING			MD_GetSubTypeString	(int n)	{XCALL(0x0060F7E0)};
	virtual	BOOL			IsNetRelevant		()		{ return TRUE; };
};

class zCEventMover : public zCEventMessage	
{
public:
	zCLASS(zCEventMover)
	friend class zCMover;
	friend class zCMoverControler;
public:
	
	enum zTEventMoverSubType
	{
		zEVENT_GOTO_KEY_FIXED_DIRECTLY=0,	
		zEVENT_GOTO_KEY_FIXED_ORDER,		
		zEVENT_GOTO_KEY_NEXT,				
		zEVENT_GOTO_KEY_PREV,				
		zEVENT_MISC_NUM_SUBTYPES
	};
	virtual zCClassDef* _GetClassDef(void)const			{XCALL(0x0060F460)};
	
	virtual	int				MD_GetNumOfSubTypes	()		{ return zEVENT_MISC_NUM_SUBTYPES; };
	virtual	zSTRING			MD_GetSubTypeString	(int n)	{XCALL(0x0060F940)};
	virtual	BOOL			IsNetRelevant		()		{ return TRUE; };
private:
	int						gotoFixedKeyframe;
	static zCClassDef* classDef;
};

class zCEventScreenFX : public zCEventMessage	
{
public:
	zCLASS(zCEventScreenFX)
	friend class oCCSManager;
	friend class zCVobScreenFX;

public:
	enum zTEventScreenFXSubType
	{
		zEVENT_BLEND_FADEIN,
		zEVENT_BLEND_FADEOUT,
		zEVENT_CINEMA_FADEIN,
		zEVENT_CINEMA_FADEOUT,
		zEVENT_FOV_MORPH,
		zEVENT_SCREENFX_COUNT
	};
private:
	float			m_fDuration;	
	zCOLOR			m_Color;		
	float			m_fFovDeg;		
	static zCClassDef *classDef;
	void zEventScreenFX(zCEventScreenFX::zTEventScreenFXSubType,float, zCOLOR,float)
	{
		XCALL(0x00617650);
	};

	zCEventScreenFX(zTEventScreenFXSubType type, float duration, zCOLOR clr, float deg)
	{
		zEventScreenFX(type,duration,clr,deg);
	};

	virtual zCClassDef* _GetClassDef(void)const													{XCALL(0x0060F780)};
	
	int						MD_GetNumOfSubTypes	()												{ return zEVENT_SCREENFX_COUNT; };
	zSTRING					MD_GetSubTypeString	(int n)											{XCALL(0x00617720)};
	zTTimeBehavior			MD_GetTimeBehavior	()												{XCALL(0x00617910)};
	float					MD_GetMinTime		()												{XCALL(0x00617930)};

	zCEventScreenFX () { Clear(); };
	
	void					Pack				(zCBuffer& buffer, zCEventManager* evManContext){XCALL(0x00617940)};
	void					Unpack				(zCBuffer& buffer, zCEventManager* evManContext){XCALL(0x00617980)};
	
	void					Archive				(zCArchiver& arc)								{XCALL(0x006179C0)};
	void					Unarchive			(zCArchiver& arc)								{XCALL(0x00617A10)};
private:
	
	float					duration;
	zCOLOR					color;
	float					fovDeg;
	void					Clear					()											{XCALL(0x006176F0)};
};
