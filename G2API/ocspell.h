#pragma once

#include "ztypes.h"

class oCVisualFX;


enum
{
	SPL_STATUS_DONTINVEST	= 0,
	SPL_STATUS_CANINVEST	= 1, 
	SPL_STATUS_CAST			= 2,
	SPL_STATUS_STOP			= 3,
	SPL_STATUS_NEXTLEVEL	= 4,
	SPL_STATUS_CANINVEST_NO_MANADEC	= 8,
	SPL_STATUS_FORCEINVEST  = 1<<16
};






const int SPL_PALLIGHT				= 0;                                                              
const int SPL_PALLIGHTHEAL			= 1;
const int SPL_PALHOLYBOLT			= 2;
const int SPL_PALMEDIUMHEAL			= 3;
const int SPL_PALREPELEVIL			= 4;
const int SPL_PALFULLHEAL			= 5;
const int SPL_PALDESTROYEVIL		= 6;

const int SPL_PALTELEPORTSECRET		= 7;
const int SPL_TELEPORTSEAPORT		= 8;
const int SPL_TELEPORTMONASTERY		= 9;
const int SPL_TELEPORTFARM			= 10;
const int SPL_TELEPORTXARDAS		= 11;
const int SPL_TELEPORTPASSNW		= 12;
const int SPL_TELEPORTPASSOW		= 13;
const int SPL_TELEPORTOC			= 14;
const int SPL_TELEPORT_1			= 15;
const int SPL_TELEPORT_2			= 16;
const int SPL_TELEPORT_3			= 17;

const int SPL_LIGHT					= 18;
const int SPL_FIREBOLT				= 19;

const int SPL_ICEBOLT				= 20;

const int SPL_LIGHTHEAL				= 21;
const int SPL_SUMMONGOBLINSKELETON	= 22;

const int SPL_INSTANTFIREBALL		= 23;

const int SPL_ZAP					= 24;

const int SPL_SUMMONWOLF			= 25;
const int SPL_WINDFIST				= 26;
const int SPL_SLEEP					= 27;

const int SPL_MEDIUMHEAL			= 28;
const int SPL_LIGHTNINGFLASH		= 29;  
const int SPL_CHARGEFIREBALL		= 30;
const int SPL_SUMMONSKELETON		= 31;
const int SPL_FEAR					= 32;
const int SPL_ICECUBE				= 33;

const int SPL_THUNDERBALL			= 34;
const int SPL_SUMMONGOLEM			= 35;
const int SPL_DESTROYUNDEAD			= 36;
const int SPL_PYROKINESIS			= 37;

const int SPL_FIRESTORM				= 38;
const int SPL_ICEWAVE				= 39;
const int SPL_SUMMONDEMON			= 40;
const int SPL_FULLHEAL				= 41;

const int SPL_FIRERAIN				= 42;
const int SPL_BREATHOFDEATH			= 43;
const int SPL_MASSDEATH				= 44;
const int SPL_ARMYOFDARKNESS		= 45;
const int SPL_SHRINK				= 46;

const int SPL_TRFSHEEP				= 47;
const int SPL_TRFSCAVENGER			= 48;
const int SPL_TRFGIANTRAT			= 49;
const int SPL_TRFGIANTBUG			= 50;
const int SPL_TRFWOLF				= 51;
const int SPL_TRFWARAN				= 52;
const int SPL_TRFSNAPPER			= 53;
const int SPL_TRFWARG				= 54;
const int SPL_TRFFIREWARAN			= 55;
const int SPL_TRFLURKER				= 56;
const int SPL_TRFSHADOWBEAST		= 57;
const int SPL_TRFDRAGONSNAPPER		= 58;
const int SPL_CHARM					= 59;

const int SPL_MASTEROFDESASTER		= 60;	

const int SPL_DEATHBOLT				= 61;	
const int SPL_DEATHBALL				= 62;	
const int SPL_CONCUSSIONBOLT		= 63;	
const int SPL_RESERVED_64			= 64;	
const int SPL_RESERVED_65		    = 65;	
const int SPL_RESERVED_66	        = 66;	
const int SPL_RESERVED_67	        = 67;	
const int SPL_RESERVED_68	        = 68;
const int SPL_RESERVED_69		    = 69;

const int SPL_THUNDERSTORM			= 70;	
const int SPL_WHIRLWIND				= 71;	
const int SPL_WATERFIST				= 72;	
const int SPL_ICELANCE				= 73;	
const int SPL_INFLATE				= 74;	
const int SPL_GEYSER				= 75;	
const int SPL_WATERWALL				= 76;	
const int SPL_RESERVED_77	        = 77;
const int SPL_RESERVED_78	        = 78;
const int SPL_RESERVED_79	        = 79;

const int SPL_PLAGUE				= 80;	
const int SPL_SUMMONSWARM			= 81;	
const int SPL_GREENTENTACLE			= 82;	
const int SPL_EARTHQUAKE			= 83;	
const int SPL_SUMMONGUARDIAN		= 84;	
const int SPL_BELIARSRAGE		    = 85;	
const int SPL_SUCKENERGY	        = 86;	
const int SPL_SKULL			        = 87;	
const int SPL_SUMMONZOMBIE	        = 88;	
const int SPL_RESERVED_89		    = 89;

const int SPL_RESERVED_90	        = 90;
const int SPL_RESERVED_91	        = 91;
const int SPL_RESERVED_92	        = 92;
const int SPL_RESERVED_93	        = 93;
const int SPL_RESERVED_94	        = 94;
const int SPL_RESERVED_95		    = 95;
const int SPL_RESERVED_96	        = 96;
const int SPL_RESERVED_97	        = 97;
const int SPL_RESERVED_98	        = 98;
const int SPL_RESERVED_99		    = 99;
 
const int SPL_MAX_SPELL				= 100;   


class oCNpc;
class oCVisualFX;

enum
{ 
	SPL_CAT_GOOD		= 0, 
	SPL_CAT_NEUTRAL		= 1, 
	SPL_CAT_BAD			= 2 
};

enum
{ 
	TARGET_COLLECT_NONE					= 0, 
	TARGET_COLLECT_CASTER				= 1, 
	TARGET_COLLECT_FOCUS				= 2, 
	TARGET_COLLECT_ALL					= 3, 
	TARGET_COLLECT_FOCUS_FALLBACK_NONE	= 4, 
	TARGET_COLLECT_FOCUS_FALLBACK_CASTER= 5, 
	TARGET_COLLECT_ALL_FALLBACK_NONE	= 6, 
	TARGET_COLLECT_ALL_FALLBACK_CASTER	= 7  
};

enum
{
	TARGET_FLAG_NONE				= 0,	
	TARGET_FLAG_ALL					= 1,
	TARGET_FLAG_ITEMS				= 2,
	TARGET_FLAG_NPCS				= 4,
	TARGET_FLAG_ORCS				= 8,
	TARGET_FLAG_HUMANS				= 16,
	TARGET_FLAG_UNDEAD				= 32,
	TARGET_FLAG_LIVING				= 64
};

const int NUM_TARGET_TYPES			= 7;

class oCSpell : public zCObject
{
public:
	zCLASS(oCSpell);
	int					keyNo;				
	oCVisualFX*			effect;
	oCVisualFX*			controlWarnFX;
	zCVob*				spellCaster;
	oCNpc*				spellCasterNpc;
	zCVob*				spellTarget;
	oCNpc*				spellTargetNpc;
	oCNpc*				saveNpc;
	float				manaTimer;
	int					manaInvested;
	int					spellLevel;
	int					spellStatus;
	int					spellID;
	int					spellInfo;
	BOOL				spellEnabled;
	BOOL				spellInitDone;
	BOOL				timerEffect;		
	BOOL				canBeDeleted;
	float				up;
	float				hoverY;
	float				hoverOld;
	float				hoverDir;
	int					spellEnergy;
	struct
	{
		float			manaInvestTime;			
		int				damagePerLevel;			
		int				damageType;				
		int				spellType;				
		int				canTurnDuringInvest;
		int				canChangeTargetDuringInvest;
		int				isMultiEffect;			
		int				targetCollectAlgo;
		int				targetCollectType;
		int				targetCollectRange;
		int				targetCollectAzi;
		int				targetCollectElev;
	};
public:

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00483D90);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00487340);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00487350);
	};

	virtual ~oCSpell()
	{
		XCALL(0x00483F50);
	};
	
	void oSpell(int)
	{
		XCALL(0x00483C20);
	};

	oCSpell(int n)
	{
		oSpell(n);
	};

	void InitValues(int)
	{
		XCALL(0x00484020);
	};

	zSTRING GetSpellInstanceName(int)const 
	{
		XCALL(0x00484150);
	};

	oCVisualFX* CreateEffect(void)
	{
		XCALL(0x004842E0);
	};

	void InitByScript(zSTRING const&)
	{
		XCALL(0x00484550);
	};

	void SetEnabled(int)
	{
		XCALL(0x004847F0);
	};

	int GetEnabled(void)
	{
		XCALL(0x00484920);
	};

	void Setup(zCVob*,zCVob*,int)
	{
		XCALL(0x00484930);
	};

	int Invest(void)
	{
		XCALL(0x004850D0);
	};

	int Cast(void)
	{
		XCALL(0x00485360);
	};

	int Stop(void)
	{
		XCALL(0x00485510);
	};

	int Kill(void)
	{
		XCALL(0x00485700);
	};

	void Open(void)
	{
		XCALL(0x004858A0);
	};

	void Close(void)
	{
		XCALL(0x004859A0);
	};

	void Reset(void)
	{
		XCALL(0x00485B00);
	};

	void StopTargetEffects(zCVob*)
	{
		XCALL(0x00485C40);
	};

	void CallScriptInvestedMana(void)
	{
		XCALL(0x00485D30);
	};

	static int IsTargetTypeValid(zCVob*,int)
	{
		XCALL(0x00485FC0);
	};

	int IsValidTarget(zCVob*)
	{
		XCALL(0x004861D0);
	};

	zCVob* GetVob(void)
	{
		XCALL(0x00486470);
	};

	int GetSpellID(void)
	{
		XCALL(0x00486480);
	};

	int GetEnergyType(void)
	{
		XCALL(0x00486490);
	};

	int GetCategory(void)
	{
		XCALL(0x004864A0);
	};

	zSTRING GetName(void)
	{
		XCALL(0x004864B0);
	};

	int GetLevel(void)
	{
		XCALL(0x00486620);
	};

	int IsInvestSpell(void)
	{
		XCALL(0x00486630);
	};

	void SetInvestedMana(int)
	{
		XCALL(0x00486640);
	};

	int GetSpellStatus(void)
	{
		XCALL(0x00486660);
	};

	void SetReleaseStatus(void)
	{
		XCALL(0x00486670);
	};

	void SetSpellInfo(int)
	{
		XCALL(0x00486940);
	};

	void DoLogicInvestEffect(void)
	{
		XCALL(0x00486950);
	};

	int CastSpecificSpell(void)
	{
		XCALL(0x00486960);
	};

	void EndTimedEffect(void)
	{
		XCALL(0x00486E10);
	};

	void DoTimedEffect(void)
	{
		XCALL(0x00487280);
	};

	int CanBeDeleted(void)
	{
		XCALL(0x00487310);
	};

	int DeleteCaster(void)
	{
		XCALL(0x00487320);
	};
	// [AST]
	void Setup_AST(zCVob*,zCVob*,int);
	int Cast_AST();
	// [/AST]
};





class oSpell : public zCObject
{
public:
	static BOOL		IsTargetTypeValid	(zCVob *v, int targetType);
	oSpell									();
	oSpell									(int spellID);

	void				Setup				(zCVob* caster, zCVob* target, const BOOL a_bIgnoreCastState=FALSE);
	BOOL				Invest				();
	BOOL				Cast				();		
	int					Stop				();
	int					Kill				();
	void				Open				();
	void				Close				();
	void				Reset				();

	oCNpc*				GetSpellTargetNpc	()					{ return this->spellTargetNpc;		}
	int					GetSpellID			();
	void				SetSpellStatus		(int status)		{ spellStatus = status;				}
	int					GetSpellStatus		();
	int					GetEnergyType		();
	int					GetCategory			();
	oCVisualFX*			GetEffect			()					{ return effect;					}
	zCVob*				GetVob				();
	zSTRING				GetName				();
	BOOL				GetEnabled			();
	BOOL				IsValidTarget		(zCVob *v);
	void				SetEnabled			(BOOL enable);
	void				SetReleaseStatus	();

	void				SetSpellInfo		(int infoValue);
	BOOL				CastSpecificSpell	();

	void				DoTimedEffect		();
	void				EndTimedEffect		();
	BOOL				CanBeDeleted		();
	BOOL				CanChangeTarget		()									{ return canChangeTargetDuringInvest;	};
	BOOL				CanTurnDuringInvest	()									{ return canTurnDuringInvest;			};
	BOOL				DeleteCaster		();
	int					GetInvestedMana		()									{ return manaInvested;		}
	int					GetLevel			();
	BOOL				IsInvestSpell		();
	void				SetInvestedMana		( int nManaInvested );
	oCNpc*				GetSpellCasterNPC	()					{ return spellCasterNpc;			};
	oCNpc*				GetSpellTargetNPC	()					{ return spellTargetNpc;			};

	int					keyNo;

private:
	virtual				~oSpell			();

	oCVisualFX*			CreateEffect		();
	void				InitValues			(int _spellID);
	void				InitByScript		(const zSTRING& name);
	void				StopTargetEffects	(zCVob* vob);
	void				CallScriptInvestedMana();

	void				DoLogicInvestEffect	();

	virtual void		Archive				(zCArchiver &arc);
	virtual void		Unarchive			(zCArchiver &arc);

	zSTRING				GetSpellInstanceName(const int _spellID) const;

	
	oCVisualFX*			effect;
	oCVisualFX*			controlWarnFX;
	zCVob*				spellCaster;
	oCNpc*				spellCasterNpc;
	zCVob*				spellTarget;
	oCNpc*				spellTargetNpc;
	oCNpc*				saveNpc;
	float				manaTimer;
	int					manaInvested;
	int					spellLevel;
	int					spellStatus;
	int					spellID;
	int					spellInfo;
	BOOL				spellEnabled;
	BOOL				spellInitDone;

	BOOL				timerEffect;		
	BOOL				canBeDeleted;

	float				up;
	float				hoverY;
	float				hoverOld;
	float				hoverDir;

	int					spellEnergy;
	
	
	struct
	{
		float			manaInvestTime;			
		int				damagePerLevel;			
		int				damageType;				
		int				spellType;				
		int				canTurnDuringInvest;
		int				canChangeTargetDuringInvest;
		int				isMultiEffect;			
		int				targetCollectAlgo;
		int				targetCollectType;
		int				targetCollectRange;
		int				targetCollectAzi;
		int				targetCollectElev;
	};
};

