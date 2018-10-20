#pragma once

#include "ztypes.h"
#include "zcaiplayer.h"

enum {	ANI_WALKMODE_RUN		,ANI_WALKMODE_WALK	,ANI_WALKMODE_SNEAK	,
		ANI_WALKMODE_WATER		,ANI_WALKMODE_SWIM	,ANI_WALKMODE_DIVE	};

enum {  ANI_ACTION_STAND		,ANI_ACTION_WALK	,ANI_ACTION_SNEAK	,ANI_ACTION_RUN,
		ANI_ACTION_WATERWALK	,ANI_ACTION_SWIM	,ANI_ACTION_DIVE	,ANI_ACTION_CHOOSEWEAPON
	 };

enum { ANI_HITTYPE_NONE			,ANI_HITTYPE_FORWARD };

const int		WMODE_NONE				= 1;
const int		WMODE_CHOOSE			= 2;
const int		WMODE_STAND				= 3;

const int		ANI_NUM					= 10;
const int		ANI_HITLIMB_MAX			= 4;
const int		ANI_TURN_LAYER			= 20;

const int		ANI_MAX_HIT				= 10;
const zREAL		ANI_TIME_INFINITE		= -1000000.0f;	

// extern
extern zBOOL	ANI_ENABLE_TURN;

class oCMobInter;
enum oHEROSTATUS;
class zCCSCamera;

class oCAniCtrl_Human : public zCAIPlayer
{
public:
	zCLASS(oCAniCtrl_Human)
	float				angle_slide1;
	float				angle_slide2;
	float				angle_heading;
	float				angle_horiz;
	float				angle_ground;
	oCNpc*				npc;
	zCVob*				targetVob;			
	zCVob*				stopTurnVob;
	int					stopTurnVobSign;
	
	zCModelNodeInst*	hitlimb[ANI_HITLIMB_MAX];

	int					actionMode;
	
	
	int					wmode;
	int					wmode_last;
	int					wmode_selected;
	BOOL				changeweapon;	

	
	int					walkmode;
	int					nextwalkmode;		
	int					lastRunWalkSneak;
	BOOL				always_walk;
	BOOL				do_jump;
	int					defaultSurfaceAlign;
	float				autoRollDirection;

	float				lookTargetx, lookTargety;

	
	int					distance;
	zVEC3				hitpos;
	zSTRING				limbname;
	float				paradeBeginFrame, paradeEndFrame;

	struct
	{
		UINT8			canEnableNextCombo				: 1;
		UINT8			endCombo						: 1;
		UINT8			comboCanHit						: 1;
		UINT8			hitPosUsed						: 1;
		UINT8			hitGraphical					: 1;
		UINT8			canDoCollisionFX				: 1;
	};	
	
	int					comboNr;
	int					comboMax;
	float				lastHitAniFrame;
	zTModelAniID		hitAniID;
	zCVob*				hitTarget;

	typedef struct
	{
		zTModelAniID	hitAni;								
		int				hitOptFrame;
		int				hitEndFrame;
		int				comboStartFrame;
		int				comboEndFrame;
		int				comboDir;
	} oTComboInfo;
	
	oTComboInfo			comboInfo[ANI_MAX_HIT];

	float				anioffset_lastper;
	float				anioffset_thisper;
	float				anioffset;
	zTModelAniID		anioffset_ani;

	

	
	zTModelAniID		s_dead1, s_dead2;
	zTModelAniID		s_hang,  t_hang_2_stand;

	
	zTModelAniID		s_run				[ANI_NUM],t_run_2_runl			[ANI_NUM],	t_runl_2_run	[ANI_NUM],
						s_runl				[ANI_NUM],t_runl_2_runr			[ANI_NUM],	t_runr_2_runl	[ANI_NUM],
						s_runr				[ANI_NUM],t_runr_2_run			[ANI_NUM],
						t_runturnl			[ANI_NUM],t_runturnr			[ANI_NUM],
						t_runstrafel		[ANI_NUM],t_runstrafer			[ANI_NUM];
	
	
	zTModelAniID		t_run_2_runbl		[ANI_NUM],t_runbl_2_run			[ANI_NUM],
						s_runbl				[ANI_NUM],t_runbl_2_runbr		[ANI_NUM],	t_runbr_2_runbl	[ANI_NUM],
						s_runbr				[ANI_NUM],t_runbr_2_run			[ANI_NUM];


	zTModelAniID		t_jumpb				[ANI_NUM];

	
	
	

	
	zTModelAniID		t_run_2_walk		[ANI_NUM],t_walk_2_run			[ANI_NUM],
						t_run_2_sneak		[ANI_NUM],t_sneak_2_run			[ANI_NUM];

	zTModelAniID		s_walk				[ANI_NUM],t_walk_2_walkl		[ANI_NUM],	t_walkl_2_walk		[ANI_NUM],
						s_walkl				[ANI_NUM],t_walkl_2_walkr		[ANI_NUM],	t_walkr_2_walkl		[ANI_NUM],
						s_walkr				[ANI_NUM],t_walkr_2_walk		[ANI_NUM],
						t_walkturnl			[ANI_NUM],t_walkturnr			[ANI_NUM],
						t_walkstrafel		[ANI_NUM],t_walkstrafer			[ANI_NUM];

	
	zTModelAniID		t_walk_2_walkbl		[ANI_NUM],t_walkbl_2_walk		[ANI_NUM],
						s_walkbl			[ANI_NUM],t_walkbl_2_walkbr		[ANI_NUM],	t_walkbr_2_walkbl	[ANI_NUM],
						s_walkbr			[ANI_NUM],t_walkbr_2_walk		[ANI_NUM];

	
	zTModelAniID		t_runl_2_jump		[ANI_NUM],t_runr_2_jump			[ANI_NUM],
						t_jump_2_runl		[ANI_NUM];

	
	zTModelAniID		t_stand_2_jumpuplow, s_jumpuplow, t_jumpuplow_2_stand,
						t_stand_2_jumpupmid, s_jumpupmid, t_jumpupmid_2_stand;

	zTModelAniID		s_sneak				[ANI_NUM],	t_sneak_2_sneakl	[ANI_NUM],	t_sneakl_2_sneak	[ANI_NUM],
						s_sneakl			[ANI_NUM],	t_sneakl_2_sneakr	[ANI_NUM],	t_sneakr_2_sneakl	[ANI_NUM],
						s_sneakr			[ANI_NUM],	t_sneakr_2_sneak	[ANI_NUM],
						t_sneakturnl		[ANI_NUM],	t_sneakturnr		[ANI_NUM],
						t_sneakstrafel		[ANI_NUM],	t_sneakstrafer		[ANI_NUM];

	
	zTModelAniID		t_sneak_2_sneakbl	[ANI_NUM],	t_sneakbl_2_sneak	[ANI_NUM],
						s_sneakbl			[ANI_NUM],	t_sneakbl_2_sneakbr	[ANI_NUM],	t_sneakbr_2_sneakbl	[ANI_NUM],
						s_sneakbr			[ANI_NUM],	t_sneakbr_2_sneak	[ANI_NUM];

	
	zTModelAniID		t_walkl_2_aim		[ANI_NUM],	t_walkr_2_aim		[ANI_NUM],
						t_walk_2_aim		[ANI_NUM],	s_aim				[ANI_NUM],	t_aim_2_walk		[ANI_NUM],
						t_hitl				[ANI_NUM],	t_hitr				[ANI_NUM],	t_hitback			[ANI_NUM],
						t_hitf				[ANI_NUM],	s_hitf				[ANI_NUM],
						t_aim_2_defend		[ANI_NUM],	s_defend			[ANI_NUM],	t_defend_2_aim		[ANI_NUM],
						t_paradeL			[ANI_NUM],	t_paradeM			[ANI_NUM],	t_paradeS			[ANI_NUM],
						t_hitfrun			[ANI_NUM];

	
	zTModelAniID		t_stumble,	t_stumbleb,	t_fallen_2_stand, t_fallenb_2_stand;

	
	zTModelAniID		t_walk_2_walkwl		,t_walkwl_2_walk		,
						s_walkwl			,t_walkwl_2_walkwr		,	t_walkwr_2_walkwl,
						s_walkwr			,t_walkwr_2_walk;

	
	zTModelAniID		t_walk_2_walkwbl	,t_walkwbl_2_walk		,
						s_walkwbl			,t_walkwbl_2_walkwbr	,	t_walkwbr_2_walkwbl,
						s_walkwbr			,t_walkwbr_2_walk;

	zTModelAniID		_s_walk				,_t_walk_2_walkl		,	_t_walkl_2_walk,
						_s_walkl			,_t_walkl_2_walkr		,	_t_walkr_2_walkl,
						_s_walkr			,_t_walkr_2_walk		,
						_t_turnl			,_t_turnr				,
						_t_strafel			,_t_strafer;		

	
	zTModelAniID		_t_walk_2_walkbl	,_t_walkbl_2_walk		,
						_s_walkbl			,_t_walkbl_2_walkbr		,	_t_walkbr_2_walkbl,
						_s_walkbr			,_t_walkbr_2_walk;					
					
	
	zTModelAniID		s_jumpstand			,t_stand_2_jumpstand	,	t_jumpstand_2_stand,
						_t_jumpb			,
						_t_stand_2_jump		,_s_jump				,	t_jump_2_stand,
						_t_stand_2_jumpup	,_s_jumpup;
	
	
	zTModelAniID		_t_jumpup_2_falldn	,_t_jump_2_falldn;

	
	zTModelAniID		t_walkwl_2_swimf	,s_swimf				,t_swimf_2_walkwl,
						t_walkwbl_2_swimb	,s_swimb				,t_swimb_2_walkwbl,
						t_swimf_2_swim		,s_swim					,t_swim_2_swimf,
						t_swim_2_swimb		,t_swimb_2_swim			,t_warn,
						t_swim_2_dive		,s_dive					,t_divef_2_swim,
						t_dive_2_divef		,s_divef				,t_divef_2_dive,
						t_dive_2_drowned	,s_drowned				,
						t_swimturnl			,t_swimturnr			,
						t_diveturnl			,t_diveturnr;				

	
	zTModelAniID		_t_walkl_2_aim		,_t_walkr_2_aim			,
						_t_walk_2_aim		,_s_aim					,_t_aim_2_walk,
						_t_hitl				,_t_hitr				,_t_hitback,
						_t_hitf				,_t_hitfstep			,_s_hitf,
						_t_aim_2_defend		,_s_defend				,_t_defend_2_aim,
						_t_paradeL			,_t_paradeM				,_t_paradeS,
						_t_hitfrun;
					
	
	zTModelAniID		t_stand_2_iaim		,s_iaim					,t_iaim_2_stand;
	
	zTModelAniID		t_iaim_2_idrop		,s_idrop				,t_idrop_2_stand;
	
	zTModelAniID		t_iaim_2_ithrow		,s_ithrow				,t_ithrow_2_stand;
	
	zTModelAniID		t_stand_2_iget		,s_iget					,t_iget_2_stand;
	zTModelAniID		s_oget;

	
	zTModelAniID		_t_stand_2_torch	,_s_torch				,_t_torch_2_stand;

	
	zTModelAniID		hitani;

	
	zTModelAniID		help,help1,help2;
	zTModelAniID		s_fall			,s_fallb			, s_fallen			,s_fallenb,		s_falldn;
	zTModelAniID		_t_runl_2_jump	,_t_runr_2_jump		,_t_jump_2_runl;
	zTModelAniID		s_look,s_point;
	zTModelAniID		dummy1,dummy2,dummy3,dummy4;
	zTModelAniID		s_weapon[ANI_NUM];
	zTModelAniID		togglewalk;

	
	zTModelAniID		t_stand_2_cast;
	zTModelAniID		s_cast;	
	zTModelAniID		t_cast_2_shoot;
	zTModelAniID		t_cast_2_stand;
	zTModelAniID		s_shoot;
	zTModelAniID		t_shoot_2_stand;
	
	int					dummyLastVar;

public:
	static zCClassDef *classDef;

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x006A3C40);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x006B7270);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x006B7320);
	};

	virtual ~oCAniCtrl_Human()
	{
		XCALL(0x006A3C80);
	};

	virtual void DoAI(zCVob*,int&)
	{
		XCALL(0x0050E980);
	};

	virtual int CanThisCollideWith(zCVob*)
	{
		XCALL(0x0048BD30);
	};

	virtual void ReportCollisionToAI(zCCollisionReport const&)
	{
		XCALL(0x0048BDF0);
	};

	virtual int HasAIDetectedCollision(void)
	{
		XCALL(0x0048BD40);
	};

	virtual void AICollisionResponseSelfDetected(zVEC3 const&,int&)
	{
		XCALL(0x0048BD50);
	};

	virtual void HostVobRemovedFromWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0050CA60);
	};

	virtual void HostVobAddedToWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BE00);
	};

	virtual int GetIsProjectile(void)
	{
		XCALL(0x0048BE10);
	};

	virtual void StartStandAni(void)
	{
		XCALL(0x006A5060);
	};

	virtual void StartFallDownAni(void)
	{
		XCALL(0x006B5220);
	};

	virtual void Init(oCNpc*)
	{
		XCALL(0x006A3D60);
	};

	BOOL IsAniActive(int ani)
	{
		return model->IsAniActive(model->GetAniFromAniID(ani));
	};

	int GetActionMode(void)const 
	{
		XCALL(0x0067A890);
	};

	void oAniCtrl_Human(void)
	{
		XCALL(0x006A3AF0);
	};

	oCAniCtrl_Human(void)
	{
		oAniCtrl_Human();
	};

	int StartAni(int,int)
	{
		XCALL(0x006A3DC0);
	};

	void SetNextAni(int,int)
	{
		XCALL(0x006A3FA0);
	};

	void InitAnimations(void)
	{
		XCALL(0x006A4010);
	};

	void SearchStandAni(BOOL forceStartAni = FALSE)
	{
		XCALL(0x006A4D20);
	};

	void Reset(void)
	{
		XCALL(0x006A5080);
	};

	void InitAngleValuesForConsole(void)
	{
		XCALL(0x006A50C0);
	};

	void SetScriptValues(void)
	{
		XCALL(0x006A5110);
	};

	void SetInterruptFollowAni(int)
	{
		XCALL(0x006A5A40);
	};

	void InitAllAnis(void)
	{
		XCALL(0x006A5BF0);
	};

	void SetWalkMode(int)
	{
		XCALL(0x006A9820);
	};
	int	GetWalkMode() const
	{
		return walkmode;
	};
	void InitFightAnis(int)
	{
		XCALL(0x006AA0B0);
	};

	void SetFightAnis(int)
	{
		XCALL(0x006AAA40);
	};

	void StartAniWithOffset(int,float)
	{
		XCALL(0x006AAB60);
	};

	void DoAniWithOffset(void)
	{
		XCALL(0x006AAB70);
	};

	void CorrectFightPosition(void)
	{
		XCALL(0x006AAB80);
	};

	zSTRING GetWalkModeString(void)
	{
		XCALL(0x006AAE40);
	};

	void CorrectAniStates(void)
	{
		XCALL(0x006AAFA0);
	};

	int CheckWaterLevel(void)
	{
		XCALL(0x006AB130);
	};

	void SetAlwaysWalk(int)
	{
		XCALL(0x006ABDB0);
	};

	int IsAlwaysWalk(void)
	{
		XCALL(0x006ABF80);
	};

	int CanToggleWalkModeTo(int)
	{
		XCALL(0x006ABFB0);
	};

	int CanToggleWalkMode(void)
	{
		XCALL(0x006ACC10);
	};

	void ToggleWalkMode(int)
	{
		XCALL(0x006AD500);
	};

	int IsDead(void)
	{
		XCALL(0x006AD540);
	};

	int IsFallen(void)
	{
		XCALL(0x006ADC30);
	};

	int IsAiming(void)
	{
		XCALL(0x006ADD40);
	};

	int IsStateAniActive(int)
	{
		XCALL(0x006ADE10);
	};

	int IsStateAniActive(zCModelAni*)
	{
		XCALL(0x006ADE90);
	};

	int IsStanding(void)
	{
		XCALL(0x006ADEE0);
	};

	int IsJumpStanding(void)
	{
		XCALL(0x006AE080);
	};

	int IsWalking(void)
	{
		XCALL(0x006AE0E0);
	};

	int IsRunning(void)
	{
		XCALL(0x006AE200);
	};

	int IsWalkingBackward(void)
	{
		XCALL(0x006AE410);
	};

	void StopTurnAnis(void)
	{
		XCALL(0x006AE530);
	};

	float Turn(float,int)
	{
		XCALL(0x006AE540);
	};

	void DoAutoRoll(void)
	{
		XCALL(0x006AEA40);
	};

	void TurnDegrees(float,int)
	{
		XCALL(0x006AEB10);
	};

	int WallInFront(float)
	{
		XCALL(0x006AEBF0);
	};

	static zSTRING GetWeaponString(int)
	{
		XCALL(0x006AEC60);
	};

	static zSTRING GetWeaponHitString(int)
	{
		XCALL(0x006AEEF0);
	};

	int IsDefending(void)
	{
		XCALL(0x006AF180);
	};

	void GetFightLimbs(void)
	{
		XCALL(0x006AF1E0);
	};

	void DoSparks(zVEC3&,zSTRING const&)
	{
		XCALL(0x006AFC50);
	};

	zCModelAniActive* GetLayerAni(int)
	{
		XCALL(0x006AFD80);
	};

	int CheckLayerAni(int,zSTRING const&)
	{
		XCALL(0x006AFDB0);
	};

	int CheckLimbHit(zSTRING const&,zCList<zCModelNodeInst>&)
	{
		XCALL(0x006AFDF0);
	};

	void ShowWeaponTrail(void)
	{
		XCALL(0x006AFE70);
	};

	void StartHitCombo(int,zCVob*)
	{
		XCALL(0x006B00C0);
	};

	void SetComboHitTarget(zCVob const*)
	{
		XCALL(0x006B0120);
	};

	void StartHitGraphical(int,zCVob*)
	{
		XCALL(0x006B0130);
	};

	int GetStopTurnVobSign(void)
	{
		XCALL(0x006B0200);
	};

	int HitCombo(int)
	{
		XCALL(0x006B0260);
	};

	zCVob* CheckHitTarget(void)
	{
		XCALL(0x006B05C0);
	};

	void CreateHit(zCVob*)
	{
		XCALL(0x006B0830);
	};

	int CheckMeleeWeaponHitsLevel(oCItem*)
	{
		XCALL(0x006B0CD0);
	};

	void HitInterrupt(void)
	{
		XCALL(0x006B11A0);
	};

	int HitGraphical(void)
	{
		XCALL(0x006B11E0);
	};

	int IsInPreHit(void)
	{
		XCALL(0x006B1350);
	};

	int IsInPostHit(void)
	{
		XCALL(0x006B13A0);
	};

	int IsInCombo(void)
	{
		XCALL(0x006B1430);
	};

	void FirstPersonDrawWeapon(void)
	{
		XCALL(0x006B1480);
	};

	zSTRING GetHitDirection(void)
	{
		XCALL(0x006B1490);
	};

	zCModelAniActive* IsParadeRunning(void)
	{
		XCALL(0x006B1550);
	};

	int CanParade(oCNpc*)
	{
		XCALL(0x006B15B0);
	};

	void StartParadeEffects(oCNpc*)
	{
		XCALL(0x006B16F0);
	};

	void StrafeLeft(void)
	{
		XCALL(0x006B1B40);
	};

	void StrafeRight(void)
	{
		XCALL(0x006B1B80);
	};

	int GetFootPos(void)
	{
		XCALL(0x006B1BC0);
	};

	void PC_GoForward(void)
	{
		XCALL(0x006B1D70);
	};

	void PC_GoBackward(void)
	{
		XCALL(0x006B1DC0);
	};

	void PC_JumpForward(void)
	{
		XCALL(0x006B1E00);
	};

	int CanJump(int)
	{
		XCALL(0x006B1FE0);
	};

	int CanJumpLedge(void)
	{
		XCALL(0x006B2050);
	};

	int JumpForward(void)
	{
		XCALL(0x006B21E0);
	};

	int Swim_CanClimbLedge(void)
	{
		XCALL(0x006B2400);
	};

	void Swim_ClimbLedge(void)
	{
		XCALL(0x006B2440);
	};

	int CanWalkOnPoly(zVEC3 const&)
	{
		XCALL(0x006B25A0);
	};

	int DrawWeapon1(int,int,int)
	{
		XCALL(0x006B2610);
	};

	int ChooseNextWeapon2(int)
	{
		XCALL(0x006B2900);
	};

	int DrawWeapon2(void)
	{
		XCALL(0x006B2CF0);
	};

	int RemoveWeapon1(void)
	{
		XCALL(0x006B3040);
	};

	int RemoveWeapon2(void)
	{
		XCALL(0x006B33B0);
	};

	void StartUp(zCVob*)
	{
		XCALL(0x006B3660);
	};

	void LerpFeetToTarget(int,int,zVEC3 const&)
	{
		XCALL(0x006B3670);
	};

	void RelaxHandToTarget(zVEC3 const&,zVEC3 const&,int,float)
	{
		XCALL(0x006B39B0);
	};

	void CheckSpecialStates(void)
	{
		XCALL(0x006B4290);
	};

	void CheckJump(void)
	{
		XCALL(0x006B4FE0);
	};

	void HackNPCToSwim(void)
	{
		XCALL(0x006B5500);
	};

	void CheckFallStates(void)
	{
		XCALL(0x006B5810);
	};

	float CombineAniLerp(float,float,float,float)
	{
		XCALL(0x006B6110);
	};

	int InterpolateCombineAni(float,float,int)
	{
		XCALL(0x006B6170);
	};

	void LookAtTarget(void)
	{
		XCALL(0x006B62F0);
	};

	void SetLookAtTarget(float,float)
	{
		XCALL(0x006B6310);
	};

	void SetLookAtTarget(zVEC3&)
	{
		XCALL(0x006B6360);
	};

	void SetLookAtTarget(zCVob*)
	{
		XCALL(0x006B6490);
	};

	void StopLookAtTarget(void)
	{
		XCALL(0x006B6640);
	};

	void StartCombineAni(zVEC3&,int,float,float)
	{
		XCALL(0x006B67F0);
	};

	void StartCombineAni(zCVob*,int,float,float)
	{
		XCALL(0x006B6930);
	};

	void StopCombineAni(int)
	{
		XCALL(0x006B6A80);
	};

	int DetectChasm(zVEC3 const&,zVEC3 const&,float&,zVEC3&)
	{
		XCALL(0x006B6A90);
	};

	int IsInCriticalAni(void)
	{
		XCALL(0x006B6C10);
	};

	void SetActionMode(int)
	{
		XCALL(0x006B7410);
	};

	void _Stand(void)
	{
		XCALL(0x006B7490);
	};

	void _Forward(void)
	{
		XCALL(0x006B7900);
	};

	void _Backward(void)
	{
		XCALL(0x006B7BC0);
	};

	void SetAnimations(int,zSTRING const&)
	{
		XCALL(0x006B7EA0);
	};

	int TransitionToInvest(void)
	{
		XCALL(0x006B8350);
	};

	int TransitionToCast(void)
	{
		XCALL(0x006B84A0);
	};

	int TransitionToStand(void)
	{
		XCALL(0x006B86A0);
	};

	int IsInCastAni(void)
	{
		XCALL(0x006B8860);
	};

	int IsInWeaponChoose(void)
	{
		XCALL(0x006B8930);
	};

	int GetWaterLevel(void)
	{
		XCALL(0x006B89D0);
	};

	int IsInWater(void)
	{
		XCALL(0x006B8A40);
	};
};

class oCAIHuman : public oCAniCtrl_Human
{
public:
	zCLASS(oCAIHuman)
	zCList<zCVob>		ignoreVobList;
	zCAICamera*			aiCam;
	
	BOOL				forcejump               :1;
	BOOL				lookedAround            :1;
	BOOL				sprintActive            :1;
	BOOL				crawlActive             :1;
	BOOL				showai                  :1;
	BOOL				startObserveIntruder    :1;
	BOOL				dontKnowAniPlayed       :1;
	BOOL				spellReleased           :1;
	BOOL				spellCastedLastFrame    :1;
	BOOL				eyeBlinkActivated       :1;
	BOOL				thirdPersonFallback		:1;

	float				createFlyDamage;

public:
	static zSTRING Cam_Run;
	static zSTRING Cam_Fight;
	static zSTRING Cam_Normal;
	static zCClassDef *classDef;

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00695280);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0069DCC0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0069DCE0);
	};

	virtual ~oCAIHuman()
	{
		XCALL(0x006952C0);
	};

	virtual void DoAI(zCVob*,int&)
	{
		XCALL(0x0069BAB0);
	};

	virtual int CanThisCollideWith(zCVob*)
	{
		XCALL(0x0069D890);
	};

	virtual void ReportCollisionToAI(zCCollisionReport const&)
	{
		XCALL(0x0048BDF0);
	};

	virtual int HasAIDetectedCollision(void)
	{
		XCALL(0x0048BD40);
	};

	virtual void AICollisionResponseSelfDetected(zVEC3 const&,int&)
	{
		XCALL(0x0048BD50);
	};

	virtual void HostVobRemovedFromWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0050CA60);
	};

	virtual void HostVobAddedToWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BE00);
	};

	virtual int GetIsProjectile(void)
	{
		XCALL(0x0048BE10);
	};

	virtual void StartStandAni(void)
	{
		XCALL(0x006A5060);
	};

	virtual void StartFallDownAni(void)
	{
		XCALL(0x006B5220);
	};

	virtual void Init(oCNpc*)
	{
		XCALL(0x00695390);
	};

	virtual void AddIgnoreCD(zCVob*)
	{
		XCALL(0x0069D8D0);
	};

	virtual void SubIgnoreCD(zCVob*)
	{
		XCALL(0x0069D8E0);
	};

	virtual void DoHackSpecials(void)
	{
		XCALL(0x0069C390);
	};
	// [AST]
	void CheckFocusVob_AST(int);
	BOOL BowMode_AST(int);
	// [/AST]


	int CheckActiveSpells(void)
	{
		XCALL(0x00472100);
	};

	int MagicInvestSpell(void)
	{
		XCALL(0x00472160);
	};

	int MagicCheckSpellStates(int)
	{
		XCALL(0x00472770);
	};

	int MagicMode(void)
	{
		XCALL(0x00472FD0);
	};

	oCAIHuman(void)
	{
		XCALL(0x006951A0);
	};

	int DoSimpleAI(void)
	{
		XCALL(0x006953B0);
	};

	int Pressed(int)
	{
		XCALL(0x00695540);
	};

	int Toggled(int)
	{
		XCALL(0x00695560);
	};

	void SetCamModeMob(oCMobInter*)
	{
		XCALL(0x00695570);
	};

	void ChangeCamMode(zSTRING const&)
	{
		XCALL(0x00695780);
	};

	void InitCamModes(int)
	{
		XCALL(0x00695790);
	};

	void SetCamMode(const zSTRING& activateCamMode, BOOL checkSpecial = FALSE)
	{
		XCALL(0x00695A60);
	};

	void WeaponChoose(void)
	{
		XCALL(0x00695A90);
	};

	int BowMode(int)
	{
		XCALL(0x00695F00);
	};

	oHEROSTATUS GetEnemyThreat(void)
	{
		XCALL(0x00696950);
	};

	void CheckFightCamera(void)
	{
		XCALL(0x00696E60);
	};

	int FightMelee(void)
	{
		XCALL(0x00696EC0);
	};

	int CheckMobInteraction(void)
	{
		XCALL(0x006982B0);
	};

	int CheckItemInteraction(void)
	{
		XCALL(0x006986B0);
	};

	int StandActions(void)
	{
		XCALL(0x00698EA0);
	};

	int PC_CheckSpecialStates(void)
	{
		XCALL(0x00699510);
	};

	void PC_Diving(void)
	{
		XCALL(0x00699C60);
	};

	void PC_Turn(float,int)
	{
		XCALL(0x00699DD0);
	};

	int PC_SpecialMove(int)
	{
		XCALL(0x00699DF0);
	};

	int PC_ActionMove(int)
	{
		XCALL(0x00699F60);
	};

	int PC_WeaponMove(int)
	{
		XCALL(0x0069A0E0);
	};

	int PC_SlowMove(int)
	{
		XCALL(0x0069A350);
	};

	int PC_Sneak(int)
	{
		XCALL(0x0069A790);
	};

	void PC_Turnings(int)
	{
		XCALL(0x0069A940);
	};

	int PC_Strafe(int)
	{
		XCALL(0x0069AC80);
	};

	void _WalkCycle(void)
	{
		XCALL(0x0069AE20);
	};

	void ResetObserveSuspectCounter(void)
	{
		XCALL(0x0069B0E0);
	};

	void CreateObserveSuspect(int)
	{
		XCALL(0x0069B0F0);
	};

	void CreateFootStepSound(int)
	{
		XCALL(0x0069B180);
	};

	void ResetAssessUseMobCounter(void)
	{
		XCALL(0x0069B250);
	};

	void CreateAssessUseMob(void)
	{
		XCALL(0x0069B260);
	};

	void SetCrawlMode(int)
	{
		XCALL(0x0069B2F0);
	};

	void SetSprintMode(int)
	{
		XCALL(0x0069B570);
	};

	int MoveCamera(void)
	{
		XCALL(0x0069B780);
	};

	void CamMessages(void)
	{
		XCALL(0x0069B790);
	};

	void CheckFocusVob(int)
	{
		XCALL(0x0069B7A0);
	};

	void Moving(void)
	{
		XCALL(0x0069B9B0);
	};

	void ChangeCamModeBySituation(void)
	{
		XCALL(0x0069CD60);
	};

	void DoMonsterSpecial(void)
	{
		XCALL(0x0069D850);
	};

	void SetShowAI(int)
	{
		XCALL(0x0069D860);
	};

	int GetShowAI(void)
	{
		XCALL(0x0069D880);
	};

	void StartFlyDamage(float,zVEC3&)
	{
		XCALL(0x0069D940);
	};
	BOOL				IsSprintActive			( void ){ return sprintActive; }
};