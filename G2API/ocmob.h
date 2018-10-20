#pragma once

#include "ztypes.h"
#include "ocnpc.h"

class oCWorld;

typedef struct
{						
	zMAT4	trafo;
	BOOL	distance;
	oCNpc*	npc;		
	zSTRING	nodeName;
} TMobOptPos;

class oCMob : public oCVob
{
public:
	zCLASS(oCMob);
	
	zSTRING			name;				
	int				hitp            :12;				
	int				damage          :12;
	BOOL			isDestroyed     :1;
	BOOL			moveable        :1;			
	BOOL			takeable        :1;
	BOOL			focusOverride   :1;
	oTSndMaterial	sndMat          :3;
	zSTRING			visualDestroyed;
	zSTRING			ownerStr;
	zSTRING			ownerGuildStr;
	int				owner;
	int				ownerGuild;
	int				focusNameIndex;
	zCList<zCVob>	ignoreVobList;
	static zCClassDef			*classDef;
public:

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0071BA20);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0071C560);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0071C6A0);
	};

	virtual ~oCMob()
	{
		XCALL(0x0071BA60);
	};

	virtual void OnTrigger(zCVob*,zCVob*)
	{
		XCALL(0x005FE170);
	};

	virtual void OnUntrigger(zCVob*,zCVob*)
	{
		XCALL(0x005FE180);
	};

	virtual void OnTouch(zCVob*)
	{
		XCALL(0x005FE190);
	};

	virtual void OnUntouch(zCVob*)
	{
		XCALL(0x005FE1A0);
	};

	virtual void OnTouchLevel(void)
	{
		XCALL(0x005FE1B0);
	};

	virtual void OnDamage(zCVob*,zCVob*,float,int,zVEC3 const&)
	{
		XCALL(0x0071BEC0);
	};

	virtual void OnMessage(zCEventMessage*,zCVob*)
	{
		XCALL(0x0071BED0);
	};

	virtual void OnTick(void)
	{
		XCALL(0x00404270);
	};

	virtual void OnTimer(void)
	{
		XCALL(0x0043CCC0);
	};

	virtual void PostLoad(void)
	{
		XCALL(0x00404280);
	};

	virtual zTVobCharClass GetCharacterClass(void)
	{
		XCALL(0x00404290);
	};

	virtual void SetSleepingMode(const zTVobSleepingMode smode)
	{
		XCALL(0x00602960);
	};

	virtual void EndMovement(const BOOL a_bHintTrafoChanged=TRUE)
	{
		XCALL(0x0061E0D0);
	};

	virtual int CanThisCollideWith(zCVob*)
	{
		XCALL(0x0071C520);
	};

	virtual int __fastcall Render( zTRenderContext&)
	{
		XCALL(0x0077D3B0);
	};

	virtual void SetVisual(zSTRING const&)
	{
		XCALL(0x00602680);
	};

	virtual void SetVisual(zCVisual*)
	{
		XCALL(0x0071BBF0);
	};

	virtual int GetScriptInstance(zSTRING*&,int&)
	{
		XCALL(0x004042B0);
	};

	virtual int SetByScriptInstance(const zSTRING* scriptInstanceName, const int scriptInstanceIndex)
	{
		XCALL(0x004042D0);
	};

	virtual int GetCSStateFlags(void)
	{
		XCALL(0x00711400);
	};

	virtual int TraceRay(const zVEC3&rayOrigin,const zVEC3&ray, const int traceFlags, zTTraceRayReport&report)
	{
		XCALL(0x005FFE40);
	};

	virtual zSTRING const* GetTriggerTarget(const int i=0)const 
	{
		XCALL(0x0043CCD0);
	};

	virtual void ThisVobAddedToWorld(zCWorld*)
	{
		XCALL(0x00601C80);
	};

	virtual void ThisVobRemovedFromWorld(zCWorld*)
	{
		XCALL(0x00601CA0);
	};

	virtual void Init(void)
	{
		XCALL(0x0077B720);
	};

	virtual void ShowDebugInfo(zCCamera*)
	{
		XCALL(0x0077B8D0);
	};

	virtual int GetInstance(void)
	{
		XCALL(0x0077D2E0);
	};

	virtual zSTRING GetInstanceName(void)
	{
		XCALL(0x0077D2F0);
	};

	virtual int IsOwnedByGuild(int)
	{
		XCALL(0x0071C190);
	};

	virtual int IsOwnedByNpc(int)
	{
		XCALL(0x0071C1B0);
	};

	virtual int DoFocusCheckBBox(void)
	{
		XCALL(0x007113E0);
	};

	virtual oCAIVobMove* GetAIVobMove(void)
	{
		XCALL(0x0077D5F0);
	};

	virtual void GetSoundMaterial_AM(int&,oTSndMaterial&,int)
	{
		XCALL(0x0071BF60);
	};

	virtual void SetSoundMaterial(oTSndMaterial)
	{
		XCALL(0x0071BF30);
	};

	virtual oTSndMaterial GetSoundMaterial(void)
	{
		XCALL(0x0071BF50);
	};

	virtual void SetName(zSTRING const&)
	{
		XCALL(0x0071BC10);
	};

	virtual zSTRING GetName(void)
	{
		XCALL(0x0071BC30);
	};

	virtual zCModel* GetModel(void)
	{
		XCALL(0x0071BEE0);
	};

	virtual zSTRING GetScemeName(void)
	{
		XCALL(0x0071BD00);
	};

	virtual void Destroy(void)
	{
		XCALL(0x0071C230);
	};

	virtual int AllowDiscardingOfSubtree(void)
	{
		XCALL(0x0071CCC0);
	};

	void oMob(void)
	{
		XCALL(0x0071B8F0);
	};

	oCMob(void)
	{
		oMob();
	};

	void SetMoveable(int)
	{
		XCALL(0x0071BF00);
	};

	int IsMoveable(void)
	{
		XCALL(0x0071BF20);
	};

	void SetOwner(zSTRING const&,zSTRING const&)
	{
		XCALL(0x0071BF80);
	};

	void SetOwner(int,int)
	{
		XCALL(0x0071C170);
	};

	int IsOwner(oCNpc*)
	{
		XCALL(0x0071C1D0);
	};

	void Hit(int)
	{
		XCALL(0x0071C220);
	};

	void InsertInIgnoreList(zCVob*)
	{
		XCALL(0x0071C490);
	};

	void RemoveFromIgnoreList(zCVob*)
	{
		XCALL(0x0071C4C0);
	};
};

class oCMobInter : public oCMob
{
	enum TMobInterDirection
	{
		MOBINTER_DIRECTION_NONE = 0,
		MOBINTER_DIRECTION_UP,
		MOBINTER_DIRECTION_DOWN
	};
public:
	zCLASS(oCMobInter);
	
	zCList<TMobOptPos>	optimalPosList;		
	zSTRING				triggerTarget;		
	zSTRING				useWithItem;		
	zSTRING				sceme;				
	zSTRING				conditionFunc;		
	zSTRING				onStateFuncName;	
	int					state;				
	int					state_num;			
	int					state_target;		
	BOOL				rewind;
	zTModelAniID		mobStateAni;
	zTModelAniID		npcStateAni;
	
	int					npcsMax     :8;
	int					npcsNeeded  :8;
	int					npcsCurrent :8;
	int					tmpState	:8;
	BOOL				tmpStateChanged;
	TMobInterDirection	Direction;			

public:
	BOOL				onInterruptReturnToSlotPos:1;
	static zCClassDef	*classDef;
public:

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0071D190);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00722310);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x007223B0);
	};

	virtual ~oCMobInter()
	{
		XCALL(0x0071D1D0);
	};

	virtual void OnTrigger(zCVob*,zCVob*)
	{
		XCALL(0x0071E7D0);
	};

	virtual void OnUntrigger(zCVob*,zCVob*)
	{
		XCALL(0x0071EAC0);
	};

	virtual void OnTouch(zCVob*)
	{
		XCALL(0x005FE190);
	};

	virtual void OnUntouch(zCVob*)
	{
		XCALL(0x005FE1A0);
	};

	virtual void OnTouchLevel(void)
	{
		XCALL(0x005FE1B0);
	};

	virtual void OnDamage(zCVob*,zCVob*,float,int,zVEC3 const&)
	{
		XCALL(0x0071D940);
	};

	virtual void OnMessage(zCEventMessage*,zCVob*)
	{
		XCALL(0x0071D950);
	};

	virtual void OnTick(void)
	{
		XCALL(0x0071E750);
	};

	virtual void OnTimer(void)
	{
		XCALL(0x0043CCC0);
	};

	virtual void PostLoad(void)
	{
		XCALL(0x00404280);
	};

	virtual zTVobCharClass GetCharacterClass(void)
	{
		XCALL(0x00404290);
	};

	virtual void SetSleepingMode(const zTVobSleepingMode smode)
	{
		XCALL(0x00602960);
	};

	virtual void EndMovement(const BOOL a_bHintTrafoChanged=TRUE)
	{
		XCALL(0x0061E0D0);
	};

	virtual int CanThisCollideWith(zCVob*)
	{
		XCALL(0x0071C520);
	};

	virtual int __fastcall Render( zTRenderContext&)
	{
		XCALL(0x0077D3B0);
	};

	virtual void SetVisual(zSTRING const&)
	{
		XCALL(0x00602680);
	};

	virtual void SetVisual(zCVisual*)
	{
		XCALL(0x0071D3C0);
	};

	virtual int GetScriptInstance(zSTRING*&,int&)
	{
		XCALL(0x004042B0);
	};

	virtual int SetByScriptInstance(const zSTRING* scriptInstanceName, const int scriptInstanceIndex)
	{
		XCALL(0x004042D0);
	};

	virtual int GetCSStateFlags(void)
	{
		XCALL(0x00711400);
	};

	virtual int TraceRay(const zVEC3&rayOrigin,const zVEC3&ray, const int traceFlags, zTTraceRayReport&report)
	{
		XCALL(0x005FFE40);
	};

	virtual zSTRING const* GetTriggerTarget(const int i=0)const 
	{
		XCALL(0x00718CE0);
	};

	virtual void ThisVobAddedToWorld(zCWorld*)
	{
		XCALL(0x00601C80);
	};

	virtual void ThisVobRemovedFromWorld(zCWorld*)
	{
		XCALL(0x00601CA0);
	};

	virtual void Init(void)
	{
		XCALL(0x0077B720);
	};

	virtual void ShowDebugInfo(zCCamera*)
	{
		XCALL(0x0077B8D0);
	};

	virtual int GetInstance(void)
	{
		XCALL(0x0077D2E0);
	};

	virtual zSTRING GetInstanceName(void)
	{
		XCALL(0x0077D2F0);
	};

	virtual int IsOwnedByGuild(int)
	{
		XCALL(0x0071C190);
	};

	virtual int IsOwnedByNpc(int)
	{
		XCALL(0x0071C1B0);
	};

	virtual int DoFocusCheckBBox(void)
	{
		XCALL(0x007113E0);
	};

	virtual oCAIVobMove* GetAIVobMove(void)
	{
		XCALL(0x0077D5F0);
	};

	virtual void GetSoundMaterial_AM(int&,oTSndMaterial&,int)
	{
		XCALL(0x0071BF60);
	};

	virtual void SetSoundMaterial(oTSndMaterial)
	{
		XCALL(0x0071BF30);
	};

	virtual oTSndMaterial GetSoundMaterial(void)
	{
		XCALL(0x0071BF50);
	};

	virtual void SetName(zSTRING const&)
	{
		XCALL(0x0071BC10);
	};

	virtual zSTRING GetName(void)
	{
		XCALL(0x0071BC30);
	};

	virtual zCModel* GetModel(void)
	{
		XCALL(0x0071BEE0);
	};

	virtual zSTRING GetScemeName(void)
	{
		XCALL(0x0071DBE0);
	};

	virtual void Destroy(void)
	{
		XCALL(0x0071C230);
	};

	virtual int AllowDiscardingOfSubtree(void)
	{
		XCALL(0x0071CCC0);
	};

	virtual int GetState(void)
	{
		XCALL(0x00718C80);
	};

	virtual int GetStateNum(void)
	{
		XCALL(0x00718C90);
	};

	virtual TMobInterDirection GetDirection(void)
	{
		XCALL(0x00718CA0);
	};

	virtual void SetDirection(TMobInterDirection)
	{
		XCALL(0x00718CB0);
	};

	virtual void SetUseWithItem(zSTRING const&)
	{
		XCALL(0x0071DA00);
	};

	virtual int GetUseWithItem(void)
	{
		XCALL(0x0071DB40);
	};

	virtual void Reset(void)
	{
		XCALL(0x0071E490);
	};

	virtual void Interact(oCNpc*,int,int,int,int,int)
	{
		XCALL(0x0071F210);
	};

	virtual void EndInteraction(oCNpc*,int)
	{
		XCALL(0x00721950);
	};

	virtual void InterruptInteraction(oCNpc*)
	{
		XCALL(0x00720CE0);
	};

	virtual void StopInteraction(oCNpc*)
	{
		XCALL(0x00721C20);
	};

	virtual int CanInteractWith(oCNpc*)
	{
		XCALL(0x00720F40);
	};

	virtual int IsInteractingWith(oCNpc*)
	{
		XCALL(0x00721550);
	};

	virtual int IsOccupied(void)
	{
		XCALL(0x00718CC0);
	};

	virtual int AI_UseMobToState(oCNpc*,int)
	{
		XCALL(0x00721F00);
	};

	virtual int IsIn(int)
	{
		XCALL(0x00718CD0);
	};

	virtual int IsInState(oCNpc*,int)
	{
		XCALL(0x0071FB00);
	};

	virtual void StartInteraction(oCNpc*)
	{
		XCALL(0x00721580);
	};

	virtual void StartStateChange(oCNpc*,int,int)
	{
		XCALL(0x0071FEA0);
	};

	virtual void CheckStateChange(oCNpc*)
	{
		XCALL(0x00720440);
	};

	virtual int CanChangeState(oCNpc*,int,int)
	{
		XCALL(0x0071FC40);
	};

	virtual void GetTransitionNames(int,int,zSTRING&,zSTRING&)
	{
		XCALL(0x0071F5E0);
	};

	virtual void OnBeginStateChange(oCNpc*,int,int)
	{
		XCALL(0x00720C70);
	};

	virtual void OnEndStateChange(oCNpc*,int,int)
	{
		XCALL(0x00720C80);
	};

	virtual void CallOnStateFunc(oCNpc*,int)
	{
		XCALL(0x00720870);
	};

	virtual void SendCallOnStateFunc(oCNpc*,int)
	{
		XCALL(0x00720AD0);
	};

	virtual  TMobOptPos* SearchFreePosition(oCNpc*,float)
	{
		XCALL(0x0071DFC0);
	};

	static int SetAllMobsToState(oCWorld*,zSTRING const&,int)
	{
		XCALL(0x0071CCD0);
	};

	static void TraverseMobs(zCTree<zCVob>*,zSTRING const&,int,int*)
	{
		XCALL(0x0071CD00);
	};

	static void TriggerAllMobsToTmpState(zCWorld*)
	{
		XCALL(0x0071CE90);
	};

	static void TraverseTriggerMobs(zCTree<zCVob>*)
	{
		XCALL(0x0071CF50);
	};

	void oMobInter(void)
	{
		XCALL(0x0071D010);
	};

	oCMobInter(void)
	{
		oMobInter();
	};

	void SetTempState(int)
	{
		XCALL(0x0071D540);
	};

	int IsTempStateChanged(void)
	{
		XCALL(0x0071D580);
	};

	void SetStateToTempState(void)
	{
		XCALL(0x0071D590);
	};

	void SetMobBodyState(oCNpc*)
	{
		XCALL(0x0071D610);
	};

	int HasUseWithItem(oCNpc*)
	{
		XCALL(0x0071DB60);
	};

	void ScanIdealPositions(void)
	{
		XCALL(0x0071DC30);
	};

	int GetFreePosition(oCNpc*,zVEC3&)
	{
		XCALL(0x0071DF50);
	};

	void SetHeading(oCNpc*)
	{
		XCALL(0x0071E1F0);
	};

	void SetIdealPosition(oCNpc*)
	{
		XCALL(0x0071E240);
	};

	void SendStateChange(int,int)
	{
		XCALL(0x0071ED90);
	};

	void SendEndInteraction(oCNpc*,int,int)
	{
		XCALL(0x0071F080);
	};

	void StartTransitionAniNpc(oCNpc*,zSTRING const&)
	{
		XCALL(0x00720150);
	};

	int IsMultiMob(void)
	{
		XCALL(0x00720EB0);
	};

	int IsAvailable(oCNpc*)
	{
		XCALL(0x00720EC0);
	};

	void MarkAsUsed(float,zCVob*)
	{
		XCALL(0x00720F20);
	};
};

class oCMobBed : public oCMobInter			
{
public:
	zCLASS(oCMobBed);
	zSTRING addName;
	static zCClassDef *classDef;
	void oMobBed(void)
	{
		XCALL(0x00722E50);
	};

	oCMobBed(void)
	{
		oMobBed();
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00718D20);
	};

	virtual ~oCMobBed()
	{
		XCALL(0x00723010);
	};

	virtual zSTRING GetScemeName(void)
	{
		XCALL(0x007232A0);
	};

	virtual void StartInteraction(oCNpc*)
	{
		XCALL(0x00723220);
	};

	virtual void OnBeginStateChange(oCNpc*,int,int)
	{
		XCALL(0x00723230);
	};

	virtual void OnEndStateChange(oCNpc*,int,int)
	{
		XCALL(0x00723240);
	};

	virtual  TMobOptPos* SearchFreePosition(oCNpc*,float)
	{
		XCALL(0x00723350);
	};
};

class oCMobFire : public oCMobInter
{
public:
	zCLASS(oCMobFire);
	zSTRING				fireSlot;		
	zSTRING				fireVobtreeName;
	zCVob*				fireVobtree;
public:
	static zCClassDef *classDef;
	void oMobFire(void)
	{
		XCALL(0x00722460);
	};

	oCMobFire(void)
	{
		oMobFire();
	};

	void DeleteEffects(void)
	{
		XCALL(0x00722850);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0071A850);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00722C60);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00722D70);
	};

	virtual ~oCMobFire()
	{
		XCALL(0x00722670);
	};

	virtual void OnTrigger(zCVob*,zCVob*)
	{
		XCALL(0x00722980);
	};

	virtual void OnUntrigger(zCVob*,zCVob*)
	{
		XCALL(0x00722B90);
	};

	virtual void OnDamage(zCVob*,zCVob*,float,int,zVEC3 const&)
	{
		XCALL(0x007228A0);
	};

	virtual void OnEndStateChange(oCNpc*,int,int)
	{
		XCALL(0x007228F0);
	};

	virtual void PreSave(void)
	{
		XCALL(0x00722C00);
	};

	virtual void PostSave(void)
	{
		XCALL(0x00722D40);
	};
};

class oCMobItemSlot : public oCMobInter
{
public:
	zCLASS(oCMobItemSlot);
	oCItem*				insertedItem;
	BOOL				removeable;

	static zCClassDef *classDef;

	void oMobItemSlot(void)
	{
		XCALL(0x00727E80);
	};

	oCMobItemSlot(void)
	{
		oMobItemSlot();
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0071AB00);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00728430);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00728500);
	};

	virtual ~oCMobItemSlot()
	{
		XCALL(0x00727ED0);
	};

	virtual int GetUseWithItem(void)
	{
		XCALL(0x007280B0);
	};

	virtual int CanInteractWith(oCNpc*)
	{
		XCALL(0x007280F0);
	};

	virtual int IsIn(int)
	{
		XCALL(0x00728400);
	};

	virtual oCItem* GetInsertedItem(void)
	{
		XCALL(0x00728110);
	};

	virtual int PlaceItem(oCItem*)
	{
		XCALL(0x00728120);
	};

	virtual oCItem* RemoveItem(void)
	{
		XCALL(0x007283C0);
	};
};

class oCMobLadder : public oCMobInter
{
public:
	zCLASS(oCMobLadder);
	BOOL				Interacting;	
	BOOL				PrevAction;		
	static zCClassDef *classDef;
	void oMobLadder(void)
	{
		XCALL(0x007274C0);
	};

	oCMobLadder(void)
	{
		oMobLadder();
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0071A040);
	};

	virtual ~oCMobLadder()
	{
		XCALL(0x00727600);
	};

	virtual int DoFocusCheckBBox(void)
	{
		XCALL(0x0071A050);
	};

	virtual void Interact(oCNpc*,int,int,int,int,int)
	{
		XCALL(0x00727A60);
	};

	virtual void EndInteraction(oCNpc*,int)
	{
		XCALL(0x00727E60);
	};

	virtual int CanInteractWith(oCNpc*)
	{
		XCALL(0x007279E0);
	};

	virtual void StartInteraction(oCNpc*)
	{
		XCALL(0x007277D0);
	};

	virtual int CanChangeState(oCNpc*,int,int)
	{
		XCALL(0x00727990);
	};
};

class oCMobLockable : public oCMobInter
{
public:
	zCLASS(oCMobLockable);
	BOOL				locked    :1;	
	BOOL				autoOpen  :1;			
	int					pickLockNr:30;			

	zSTRING				keyInstance;		
	zSTRING				pickLockStr;		
	static zCClassDef		*classDef;
public:
	void oMobLockable(void)
	{
		XCALL(0x00723920);
	};

	oCMobLockable(void)
	{
		oMobLockable();
	};

	int CanOpen(oCNpc*)
	{
		XCALL(0x007244F0);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00719610);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x007253B0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x007254A0);
	};

	virtual ~oCMobLockable()
	{
		XCALL(0x00723B00);
	};

	virtual void OnMessage(zCEventMessage*,zCVob*)
	{
		XCALL(0x007198C0);
	};

	virtual void Interact(oCNpc*,int,int,int,int,int)
	{
		XCALL(0x00723CF0);
	};

	virtual int CanInteractWith(oCNpc*)
	{
		XCALL(0x00723CC0);
	};

	virtual int CanChangeState(oCNpc*,int,int)
	{
		XCALL(0x007242E0);
	};

	virtual void OnEndStateChange(oCNpc*,int,int)
	{
		XCALL(0x00724330);
	};

	virtual void SetLocked(int)
	{
		XCALL(0x00719620);
	};

	virtual void SetKeyInstance(zSTRING const&)
	{
		XCALL(0x00719640);
	};

	virtual void SetPickLockStr(zSTRING const&)
	{
		XCALL(0x00719780);
	};

	virtual void Lock(oCNpc*)
	{
		XCALL(0x007251C0);
	};

	virtual void Unlock(oCNpc*,int)
	{
		XCALL(0x00724A70);
	};

	virtual int PickLock(oCNpc*,char)
	{
		XCALL(0x00724800);
	};
};

class oCMobContainer : public oCMobLockable	
{
public:
	zCLASS(oCMobContainer);
	zSTRING				contains;			
	oCItemContainer*	items;
	zCListSort<oCItem>	containList;
	static zCClassDef		*classDef;
	
	void oMobContainer()
	{
		XCALL(0x007257E0);
	};
	
	oCMobContainer()
	{
		oMobContainer();
	};
public:
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00719990);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00726680);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00726820);
	};

	virtual ~oCMobContainer()
	{
		XCALL(0x007259A0);
	};

	virtual void OnMessage(zCEventMessage*,zCVob*)
	{
		XCALL(0x00725BB0);
	};

	virtual void Destroy(void)
	{
		XCALL(0x00725CB0);
	};

	virtual void Reset(void)
	{
		XCALL(0x00725E60);
	};

	virtual int IsIn(int)
	{
		XCALL(0x007264C0);
	};

	virtual void Open(oCNpc*)
	{
		XCALL(0x00726500);
	};

	virtual void Close(oCNpc*)
	{
		XCALL(0x00726640);
	};

	virtual void Insert(oCItem*)
	{
		XCALL(0x00725FC0);
	};

	virtual oCItem* Remove(oCItem*,int)
	{
		XCALL(0x00726080);
	};

	virtual void Remove(oCItem*)
	{
		XCALL(0x00725FF0);
	};

	virtual void CreateContents(zSTRING const&)
	{
		XCALL(0x00726190);
	};
	
	inline oCItem* SearchInst(int instance)
	{
		for(int i =0; i < containList.GetNumInList(); i++)
			if(containList.Get(i)->GetInstance() == instance)
				return containList.Get(i);
		return NULL;
	};
	void Open2(oCNpc*);
};

class oCMobDoor : public oCMobLockable			
{
public:
	zCLASS(oCMobDoor);
	zSTRING				addName;			
	static zCClassDef *classDef;

	void oMobDoor(void)
	{
		XCALL(0x007269B0);
	};

	oCMobDoor(void)
	{
		oMobDoor();
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0071A420);
	};

	virtual ~oCMobDoor()
	{
		XCALL(0x00726BB0);
	};

	virtual zSTRING GetScemeName(void)
	{
		XCALL(0x00726D60);
	};

	virtual  TMobOptPos* SearchFreePosition(oCNpc*,float)
	{
		XCALL(0x00726E10);
	};

	virtual void Open(oCNpc*)
	{
		XCALL(0x0071A430);
	};

	virtual void Close(oCNpc*)
	{
		XCALL(0x0071A440);
	};
};

class oCMobSwitch : public oCMobInter		
{
public:
	zCLASS(oCMobSwitch);
	static zCClassDef* classDef;

	void oMobSwitch(void)
	{
		XCALL(0x007234E0);
	};

	oCMobSwitch(void)
	{
		oMobSwitch();
	};
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00719060);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x007237D0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00723870);
	};

	virtual ~oCMobSwitch()
	{
		XCALL(0x00723600);
	};
};

class oCMobWheel : public oCMobInter	
{
public:
	zCLASS(oCMobWheel);
	static zCClassDef* classDef;

	void oMobWheel(void)
	{
		XCALL(0x00726FA0);
	};

	oCMobWheel(void)
	{
		oMobWheel();
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00719CE0);
	};

	virtual ~oCMobWheel()
	{
		XCALL(0x007272F0);
	};

	virtual void OnTrigger(zCVob*,zCVob*)
	{
		XCALL(0x007270D0);
	};

	virtual void OnUntrigger(zCVob*,zCVob*)
	{
		XCALL(0x007271E0);
	};

	virtual void Interact(oCNpc*,int,int,int,int,int)
	{
		XCALL(0x007272E0);
	};
};