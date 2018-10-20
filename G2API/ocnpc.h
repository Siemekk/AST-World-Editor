#pragma once

#include "ztypes.h"
#include "zcparser.h"
#include "ocnpcinventory.h"
#include "ocspell.h"
#include "ocanictrl_human.h"
#include "zcwaynet.h"
#include "oCVisFx.h"
#include "ocmob.h"

class zCParticleFX;
class oCInfo;
class oCNews;
class oCNpc;
class oCRtnEntry;
class oCSpell;
class oCVisualFX;
class zCPlayerGroup;
class zCRoute;
class zCModel;
class oCMob;
class oCMsgDamage;
class oCMsgUseItem;
class oCMsgState;
class oCMsgAttack;
class oCMsgMagic;
class oCMsgMovement;
class oCMsgConversation;
class oCMsgWeapon;
class oCMsgManipulate;
class oCNpcMessage;





const int NPC_ATR_HITPOINTS				=  0;	
const int NPC_ATR_HITPOINTSMAX			=  1;	
const int NPC_ATR_MANA					=  2;	
const int NPC_ATR_MANAMAX				=  3;	

const int NPC_ATR_STRENGTH				=  4;	
const int NPC_ATR_DEXTERITY				=  5;	
const int NPC_ATR_REGENERATEHP			=  6;	
const int NPC_ATR_REGENERATEMANA		=  7;   

const int NPC_ATR_MAX					=  8;

const int NPC_TAL_FIGHT_USED			=  0x00000FFF;
const int NPC_TAL_FIGHT_MAX				=  12;
const int NPC_TAL_USED					=  0x0000024D;
const int NPC_TAL_MAX					=  17;


const int NPC_HITCHANCE_1H				=  1;
const int NPC_HITCHANCE_2H				=  2;
const int NPC_HITCHANCE_BOW				=  3;
const int NPC_HITCHANCE_CROSSBOW		=  4;
const int NPC_HITCHANCE_MAX				=  5;


enum 
{
	NPC_GAME_NORMAL,
	NPC_GAME_PLUNDER,
	NPC_GAME_STEAL
};

enum
{  
	BS_INT_OVERRIDE_NONE = 0,
	BS_INT_OVERRIDE_ALL = 1,
	BS_INT_OVERRIDE_STUMBLE_ONLY = 2
};


const zSTRING	PLAYER_MOB_MISSING_KEY				=	"PLAYER_MOB_MISSING_KEY";
const zSTRING	PLAYER_MOB_MISSING_LOCKPICK			=	"PLAYER_MOB_MISSING_LOCKPICK";
const zSTRING	PLAYER_MOB_MISSING_KEY_OR_LOCKPICK	=	"PLAYER_MOB_MISSING_KEY_OR_LOCKPICK";
const zSTRING	PLAYER_MOB_NEVER_OPEN				=	"PLAYER_MOB_NEVER_OPEN";
const zSTRING	PLAYER_MOB_TOO_FAR_AWAY				=	"PLAYER_MOB_TOO_FAR_AWAY";
const zSTRING	PLAYER_MOB_WRONG_SIDE				=	"PLAYER_MOB_WRONG_SIDE";

const zSTRING	PLAYER_MOB_MISSING_ITEM				=	"PLAYER_MOB_MISSING_ITEM";
const zSTRING	PLAYER_MOB_ANOTHER_IS_USING			=	"PLAYER_MOB_ANOTHER_IS_USING";


const zSTRING	PLAYER_PLUNDER_IS_EMPTY				=	"PLAYER_PLUNDER_IS_EMPTY";


const zSTRING	PLAYER_RANGED_NO_AMMO				=	"PLAYER_RANGED_NO_AMMO";

class oCNpcTalent :  public zCObject
{
public:
	enum oTEnumNpcTalent
	{
		NPC_TAL_UNKNOWN,
		
		NPC_TAL_1H,
		NPC_TAL_2H,
		NPC_TAL_BOW,
		NPC_TAL_CROSSBOW,
		NPC_TAL_PICKLOCK,
		NPC_TAL_PICKPOCKET,
		NPC_TAL_MAGE,
		
		NPC_TAL_SNEAK,
		NPC_TAL_REGENERATE,
		NPC_TAL_FIREMASTER,
		NPC_TAL_ACROBAT,
		NPC_TALENT_PICKPOCKET,
		NPC_TAL_SMITH,
		NPC_TAL_RUNES,
		NPC_TAL_ALCHEMY	,
		NPC_TAL_TAKEANIMALTROPHY,
		NPC_TAL_A,
		NPC_TAL_B,
		NPC_TAL_C,
		NPC_TAL_D,
		NPC_TAL_E,
		NPC_TAL_MAX
	};

	static BOOL	IsFightTalent(int nr)
	{ 
		return (nr>oTEnumNpcTalent::NPC_TAL_UNKNOWN) && (nr<=oTEnumNpcTalent::NPC_TAL_CROSSBOW);
	};		

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0072C4B0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0072C7B0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0072C7F0);
	};

	virtual ~oCNpcTalent()
	{
		XCALL(0x0072C660);
	};

	void oNpcTalent(void)
	{
		XCALL(0x0072C4C0);
	};

	oCNpcTalent(void)
	{
		oNpcTalent();
	};

	static void CreateTalentList(zCArray<oCNpcTalent*>*)
	{
		XCALL(0x0072C670);
	};	
private:
	oTEnumNpcTalent	m_talent;
	int				m_skill;
	int				m_value;
public:
	oTEnumNpcTalent	GetTalent		()						{ return m_talent;	};
	int				GetTalentValue	()						{ return m_value;	};
	int				GetTalentSkill	()						{ return m_skill;	};

	BOOL			IsFightTalent	()						{ return IsFightTalent(m_talent);}	
		
	void			SetTalent		(oTEnumNpcTalent talent){ m_talent=talent;m_skill=0;m_value=0;};	
	void			SetTalentValue	(int value)				{ m_value=value;}
	void			SetTalentSkill	(int skill)				{ m_skill=skill;}
};

enum oHEROSTATUS
{
	oHERO_STATUS_STD,
	oHERO_STATUS_THR,
	oHERO_STATUS_FGT
};

const int NPC_FLAG_NFOCUS			=	1<<18;




const int BS_STAND					=	0;
const int BS_WALK					=	1;
const int BS_SNEAK					=	2;
const int BS_RUN					=	3;
const int BS_SPRINT					=	4;
const int BS_SWIM					=	5;
const int BS_CRAWL					=	6;
const int BS_DIVE					=	7;
const int BS_JUMP					=	8;
const int BS_CLIMB					=	9;
const int BS_FALL					=  10;
const int BS_SIT					=  11;
const int BS_LIE					=  12;	
const int BS_INVENTORY				=  13;
const int BS_ITEMINTERACT			=  14;
const int BS_MOBINTERACT			=  15;
const int BS_MOBINTERACT_INTERRUPT	=  16;

const int BS_TAKEITEM				=  17;
const int BS_DROPITEM				=  18;
const int BS_THROWITEM				=  19;
const int BS_PICKPOCKET				=  20;

const int BS_STUMBLE				=  21;
const int BS_UNCONSCIOUS			=  22;
const int BS_DEAD					=  23;

const int BS_AIMNEAR				=  24;
const int BS_AIMFAR					=  25;
const int BS_HIT					=  26;
const int BS_PARADE					=  27;


const int BS_CASTING				=  28;
const int BS_PETRIFIED				=  29;
const int BS_CONTROLLING			=  30;

const int BS_MAX					=  31;


const int BS_MOD_HIDDEN				=    128;
const int BS_MOD_DRUNK				=	 256;
const int BS_MOD_NUTS				=	 512;
const int BS_MOD_BURNING			=   1024;
const int BS_MOD_CONTROLLED			=   2048;
const int BS_MOD_TRANSFORMED		=	4096;
const int BS_MOD_CONTROLLING		=   8192;


const int BS_FLAG_INTERRUPTABLE		=  32768;
const int BS_FLAG_FREEHANDS			=  65536;


const int BS_ONLY_STATE				=	BS_MOD_HIDDEN - 1;
const int BS_MOD_ACTIVE				=	BS_MOD_HIDDEN | BS_MOD_DRUNK | BS_MOD_NUTS | BS_MOD_BURNING | BS_MOD_CONTROLLED | BS_MOD_TRANSFORMED | BS_MOD_CONTROLLING;

const zSTRING NPC_TALK_ANI	= "VISEME";

const zSTRING BS_NAMES[BS_MAX] =
{
	"BS_STAND",						"BS_WALK",			"BS_SNEAK",			"BS_RUN",				"BS_SPRINT",			"BS_SWIM",
	"BS_CRAWL",						"BS_DIVE",			"BS_JUMP",			"BS_CLIMB",				"BS_FALL",
	"BS_SIT",						"BS_LIE",			"BS_INVENTORY",		"BS_ITEMINTERACT",		"BS_MOBINTERACT",
	"BS_MOBINTERACT_INTERRUPT",		"BS_TAKEITEM",		"BS_DROPITEM",		"BS_THROWITEM",			"BS_PICKPOCKET"	,				
	"BS_STUMBLE",					"BS_UNCONSCIOUS",	"BS_DEAD",			"BS_AIMNEAR",			"BS_AIMFAR",
	"BS_HIT",						"BS_PARADE",
	"BS_CASTING",					"BS_PETRIFIED",		"BS_CONTROLLING" 
};

const zSTRING BS_MOD_NAMES[6] =
{
	"BS_MOD_HIDDEN",
	"BS_MOD_DRUNK",
	"BS_MOD_NUTS",
	"BS_MOD_BURNING",
	"BS_MOD_CONTROLLED",
	"BS_MOD_TRANSFORMED"
};


const int NPC_ATT_MAX		= 4;
enum
{
	NPC_ATT_HOSTILE		= 0,
	NPC_ATT_ANGRY		= 1,
	NPC_ATT_NEUTRAL		= 2,
	NPC_ATT_FRIENDLY	= 3
};


const int NPC_NAME_MAX				=  5;
const int NPC_MIS_MAX				=  5;


const int NPC_FLAG_FRIENDS			=	1 << 0;   
const int NPC_FLAG_IMMORTAL			=	1 << 1;   
const int NPC_FLAG_GHOST			=	1 << 2;   
const int NPC_FLAG_PROTECTED		=	1 << 10;  


enum
{
	NPC_WEAPON_NONE =  0, 
	NPC_WEAPON_FIST =  1,
	NPC_WEAPON_DAG  =  2,
	NPC_WEAPON_1HS	=  3,
	NPC_WEAPON_2HS  =  4, 
	NPC_WEAPON_BOW	=  5,
	NPC_WEAPON_CBOW =  6,
	NPC_WEAPON_MAG	=  7,
	NPC_WEAPON_MAX  =  8
};


const int NPC_SENSE_SEE		= 1 << 0;
const int NPC_SENSE_HEAR	= 1 << 1;
const int NPC_SENSE_SMELL	= 1 << 2;

const float NPC_TURNVELOCITY		= 150.0f;

const zSTRING NPC_NODE_RIGHTHAND	= "ZS_RIGHTHAND";
const zSTRING NPC_NODE_LEFTHAND		= "ZS_LEFTHAND";
const zSTRING NPC_NODE_SWORD		= "ZS_SWORD";
const zSTRING NPC_NODE_LONGSWORD	= "ZS_LONGSWORD";
const zSTRING NPC_NODE_BOW			= "ZS_BOW";
const zSTRING NPC_NODE_CROSSBOW		= "ZS_CROSSBOW";
const zSTRING NPC_NODE_SHIELD		= "ZS_SHIELD";
const zSTRING NPC_NODE_HELMET		= "ZS_HELMET";
const zSTRING NPC_NODE_JAWS			= "ZS_JAWS";
const zSTRING NPC_NODE_TORSO		= "ZS_TORSO";
const zSTRING NPC_NODE_LEFTARM		= "ZS_LEFTARM";

enum 
{	
		NPC_PERC_ASSESSPLAYER			=	1,	NPC_PERC_ASSESSENEMY			=   2,	
		NPC_PERC_ASSESSFIGHTER			=   3,	NPC_PERC_ASSESSBODY				=   4,	
		NPC_PERC_ASSESSITEM				=   5,	
		
		NPC_PERC_ASSESSMURDER			=	6,	NPC_PERC_ASSESSDEFEAT			=	7,
		NPC_PERC_ASSESSDAMAGE			=	8,	NPC_PERC_ASSESSOTHERSDAMAGE		=	9,
		NPC_PERC_ASSESSTHREAT			=  10,	NPC_PERC_ASSESSREMOVEWEAPON		=  11,
		NPC_PERC_OBSERVEINTRUDER		=  12,	NPC_PERC_ASSESSFIGHTSOUND		=  13,
		NPC_PERC_ASSESSQUIETSOUND		=  14,	NPC_PERC_ASSESSWARN				=  15,
		NPC_PERC_CATCHTHIEF				=  16,	NPC_PERC_ASSESSTHEFT			=  17,
		NPC_PERC_ASSESSCALL				=  18,	NPC_PERC_ASSESSTALK				=  19,
		NPC_PERC_ASSESSGIVENITEM		=  20,	NPC_PERC_ASSESSFAKEGUILD		=  21,	
		NPC_PERC_MOVEMOB				=  22,	NPC_PERC_MOVENPC				=  23,	
		NPC_PERC_DRAWWEAPON				=  24,	NPC_PERC_OBSERVESUSPECT			=  25,	
		NPC_PERC_NPCCOMMAND				=  26,	NPC_PERC_ASSESSMAGIC			=  27,  
		NPC_PERC_ASSESSSTOPMAGIC		=  28,	NPC_PERC_ASSESSCASTER			=  29,	
		NPC_PERC_ASSESSSURPRISE			=  30,	NPC_PERC_ASSESSENTERROOM		=  31,
		NPC_PERC_ASSESSUSEMOB			=  32,
		
		NPC_PERC_MAX					=  33
};

enum
{
	NPCTYPE_AMBIENT			= 0,	
	NPCTYPE_MAIN			= 1,
	NPCTYPE_GUARD			= 2,
	NPCTYPE_FRIEND			= 3,
	NPCTYPE_MINE_AMBIENT	= 4,
	NPCTYPE_MINE_GUARD		= 5,
	NPCTYPE_OW_AMBIENT		= 6,
	NPCTYPE_OW_GUARD		= 7
};


typedef struct TNpcSlot {

	TNpcSlot		() { vob=NULL; };

	zSTRING			name;
	zBOOL			inInventory;
	zBOOL			tmpLevel;
	zSTRING			itemName;

    oCVob *         Vob(){return vob;}

	void            SetVob(oCVob *vob){XCALL(0x0072C860);};
	void            ClearVob() {XCALL(0x0072C910);};

	~TNpcSlot		() { ClearVob(); }
 private:
	oCVob*			vob;
    zBOOL           wasVobTreeWhenInserted:1;	
} TNpcSlot;

typedef struct TNpcPerc
{
	int				percID;
	int				percFunc;
} TNpcPerc;


class oCMag_Book
{
public:
	zCArray    <oCSpell*>	spells;
	zCArray    <oCItem*>	spellitems;
	zCWorld*	wld;
	zCVob*		owner;
	zCModel*	model;
	int			spellnr;		
	float		MAG_HEIGHT;
	BOOL		active;
	BOOL		remove_all;
	BOOL		in_movement;
	BOOL		show_handsymbol;
	float		step;
	int			action;
	int			fullangle;
	BOOL		open;
	float		open_delay_timer;
	BOOL		show_particles;
	float		targetdir,t1;
	zVEC3		targetpos,startpos;
	int			nextRegister;
	unsigned int keys;
public:
	void oMag_Book(void)
	{
		XCALL(0x004753F0);
	};

	oCMag_Book(void)
	{
		oMag_Book();
	};

	~oCMag_Book(void)
	{
		XCALL(0x004755C0);
	};

	void CheckConsistency(void)
	{
		XCALL(0x00475720);
	};

	void SetOwner(zCVob*)
	{
		XCALL(0x00475A50);
	};

	void SetWorld(zCWorld*)
	{
		XCALL(0x00475AC0);
	};

	int Register(oCSpell *spell, BOOL active = TRUE)
	{
		XCALL(0x00475AD0);
	};

	int Register(oCItem  *item,  BOOL active = TRUE)
	{
		XCALL(0x00475BB0);
	};

	int DeRegister(oCItem  *item)
	{
		XCALL(0x00475CC0);
	};

	int DeRegister(int)
	{
		XCALL(0x00475DA0);
	};

	oCSpell* CreateNewSpell(int)
	{
		XCALL(0x00475E50);
	};

	int Register(int snr, BOOL active = TRUE)
	{
		XCALL(0x00475FE0);
	};

	int IsIn(int)
	{
		XCALL(0x00476220);
	};

	void Spell_Setup(int,oCNpc*,zCVob*)
	{
		XCALL(0x00476260);
	};

	void Spell_Setup(oCNpc*,zCVob*,int)
	{
		XCALL(0x004763A0);
	};

	void Spell_Invest(void)
	{
		XCALL(0x00476530);
	};

	void StartInvestEffect(zCVob*,int,int,int)
	{
		XCALL(0x004766B0);
	};

	void Spell_Cast(void)
	{
		XCALL(0x004767A0);
	};

	void StartCastEffect(zCVob*,zVEC3 const&)
	{
		XCALL(0x00476E60);
	};

	int Spell_InCast(void)
	{
		XCALL(0x00476F50);
	};

	void Open(int)
	{
		XCALL(0x00476F60);
	};

	void Close(int)
	{
		XCALL(0x00477270);
	};

	float Ease(float,float,float)
	{
		XCALL(0x004773E0);
	};

	zVEC3 EasePos(float,zVEC3&,zVEC3&)
	{
		XCALL(0x00477410);
	};

	float GetAngle(zCVob*)
	{
		XCALL(0x00477490);
	};

	int IsInMovement(void)
	{
		XCALL(0x00477760);
	};

	int IsActive(void)
	{
		XCALL(0x00477770);
	};

	oCSpell* GetSelectedSpell(void)
	{
		XCALL(0x00477780);
	};

	int GetSelectedSpellNr(void)
	{
		XCALL(0x004777D0);
	};

	void Spell_Open(int)
	{
		XCALL(0x004777E0);
	};

	void StopSelectedSpell(void)
	{
		XCALL(0x00477910);
	};

	void KillSelectedSpell(void)
	{
		XCALL(0x00477A90);
	};

	void Spell_Stop(int)
	{
		XCALL(0x00477D50);
	};

	void Left(void)
	{
		XCALL(0x00477FC0);
	};

	void Right(void)
	{
		XCALL(0x00478020);
	};

	zVEC3 CalcPos(zCVob*,float)
	{
		XCALL(0x00478070);
	};

	int DoOpen(void)
	{
		XCALL(0x00478460);
	};

	int DoClose(void)
	{
		XCALL(0x004785E0);
	};

	void SetFrontSpell(int)
	{
		XCALL(0x004789C0);
	};

	int DoTurn(void)
	{
		XCALL(0x00478D50);
	};

	void ShowHandSymbol(void)
	{
		XCALL(0x00478E50);
	};

	void SetShowHandSymbol(int)
	{
		XCALL(0x00478FD0);
	};

	void DoPerFrame(void)
	{
		XCALL(0x00479330);
	};

	int GetNoOfSpells(void)
	{
		XCALL(0x00479B60);
	};

	oCSpell* GetSpell(oCItem*,int&)
	{
		XCALL(0x00479B70);
	};

	oCSpell* GetSpell(int)
	{
		XCALL(0x00479BC0);
	};

	oCItem* GetSpellItem(int)
	{
		XCALL(0x00479BE0);
	};

	oCItem* GetSpellItem(oCSpell*)
	{
		XCALL(0x00479C00);
	};

	void NextRegisterAt(int)
	{
		XCALL(0x00479C40);
	};

	oCSpell* GetSpellByKey(int)
	{
		XCALL(0x00479C60);
	};

	oCItem* GetSpellItemByKey(int)
	{
		XCALL(0x00479CA0);
	};

	int GetNoOfSpellByKey(int)
	{
		XCALL(0x00479CE0);
	};

	int GetKeyByItem(oCItem*)
	{
		XCALL(0x00479D30);
	};
	BOOL			IsOpen				() { return open; };
	//AST
	void Spell_Cast_ast();
};




typedef enum oENewsSpreadType
{
	NEWS_DONT_SPREAD							= 0,
	NEWS_SPREAD_NPC_FRIENDLY_TOWARDS_VICTIM		= 1,
	NEWS_SPREAD_NPC_FRIENDLY_TOWARDS_WITNESS	= 2,
	NEWS_SPREAD_NPC_FRIENDLY_TOWARDS_OFFENDER	= 3,		
	NEWS_SPREAD_NPC_SAME_GUILD_VICTIM			= 4		
}
oTNewsSpreadType;

class oCNews
{
public:
private:			
	BOOL				told;				
	float				spread_time;		
	oTNewsSpreadType	spreadType;
	int					news_id;			
	BOOL				gossip;				
	oCNpc*				mNpcWitness;		
	oCNpc*				mNpcOffender;		
	oCNpc*				mNpcVictim;			
	zSTRING				witnessName;
	zSTRING				offenderName;
	zSTRING				victimName;
	BOOL				guildvictim;		
	

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0072AF90);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0072B1F0);
	};

	static int GetRemainingNews(void)
	{
		XCALL(0x0072A370);
	};

	static void CheckRemainingNews(void)
	{
		XCALL(0x0072A380);
	};

	oCNews(void)
	{
		XCALL(0x0072A830);
	};

	oCNews(int,int,oCNpc*,oCNpc*,oCNpc*,int)
	{
		XCALL(0x0072A9D0);
	};

	~oCNews(void)
	{
		XCALL(0x0072AC50);
	};

	int GetID(void)
	{
		XCALL(0x0072ADC0);
	};

	int IsIdentical(int,oCNpc*,oCNpc*)
	{
		XCALL(0x0072ADD0);
	};

	void SetSpreadTime(float)
	{
		XCALL(0x0072AE00);
	};

	float GetSpreadTime(void)
	{
		XCALL(0x0072AE30);
	};

	void SetGossip(int)
	{
		XCALL(0x0072AE40);
	};

	int IsGossip(void)
	{
		XCALL(0x0072AE60);
	};

	int IsGuildVictim(void)
	{
		XCALL(0x0072AE70);
	};

	void GetNewsData(int&,int&,oCNpc*&,oCNpc*&,oCNpc*&)
	{
		XCALL(0x0072AE80);
	};
};

class oCNewsMemory 
{
	zCList <oCNews>		iknow;
public:
	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0072A140);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0072A1C0);
	};

	void oNewsMemory(void)
	{
		XCALL(0x00729580);
	};

	oCNewsMemory(void)
	{
		oNewsMemory();
	};

	~oCNewsMemory(void)
	{
		XCALL(0x007295A0);
	};

	void Insert(oCNews*)
	{
		XCALL(0x007296B0);
	};

	void Remove(oCNews*)
	{
		XCALL(0x00729790);
	};

	oCNews* GetNews(int,oCNpc*,oCNpc*)
	{
		XCALL(0x00729810);
	};

	void CheckSpreadNews(void)
	{
		XCALL(0x00729850);
	};

	int SearchNews(int,oCNpc*,oCNpc*)
	{
		XCALL(0x007298E0);
	};

	void ShowDebugInfos(void)
	{
		XCALL(0x00729960);
	};

	oCNews* GetNewsByNumber(int)
	{
		XCALL(0x00729F60);
	};

	void ClearNews(void)
	{
		XCALL(0x00729F90);
	};

	int DeleteNewsByNumber(int)
	{
		XCALL(0x0072A0A0);
	};
};








enum
{
	NPC_AISTATE_ANSWER		= -2,
	NPC_AISTATE_DEAD		= -3,
	NPC_AISTATE_UNCONSCIOUS = -4,
	NPC_AISTATE_FADEAWAY	= -5,
	NPC_AISTATE_FOLLOW		= -6
};
const int	NPC_AISTATE_PRG_MAX		=  7;

const zSTRING	npcStatesPrg	[NPC_AISTATE_PRG_MAX] = 
{
	"ZS_NONE",
	"ZS_NONE", 
	"ZS_ANSWER",
	"ZS_DEAD",
	"ZS_UNCONSCIOUS",
	"ZS_FADEAWAY",
	"ZS_FOLLOW"
};

struct TNpcAIState 
{
	enum
	{
		AITIME_NO,
		AITIME_ONCE,
		AITIME_TIMED
	};
	int				index;
	int				loop;
	int				end;
	int				timeBehaviour;
	float			restTime;
	int				phase;
	BOOL			valid;
	zSTRING			name;
	float			stateTime;
	int				prgIndex;		
	BOOL			isRtnState;

	void _TNpcAIState(void)
	{
		XCALL(0x0076BAD0);
	};

	TNpcAIState(void)
	{
		_TNpcAIState();
	};

	~TNpcAIState(void)
	{
		XCALL(0x0076BB10);
	};
};

class oCNpc_States 
{
public:
	zSTRING name;
	
	oCNpc*				npc;
	TNpcAIState			curState;
	TNpcAIState			nextState;
	int					lastAIState;
	
	BOOL				hasRoutine;					
	BOOL				rtnChanged;
	oCRtnEntry*			rtnBefore;					
	oCRtnEntry*			rtnNow;						
	zCRoute*			rtnRoute;					
	BOOL				rtnOverlay;					
	int					rtnOverlayCount;			
	int					walkmode_routine;
	BOOL				weaponmode_routine;
	BOOL				startNewRoutine;
	
	int					aiStateDriven;
	zVEC3				aiStatePosition;
	
	oCNpc				*parOther,*parVictim;
	oCItem				*parItem;
	
	int					rntChangeCount;
public:
	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0076EE70);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0076EFF0);
	};

	virtual void PackState(zCBuffer&)
	{
		XCALL(0x0076F530);
	};

	virtual void UnpackState(zCBuffer&)
	{
		XCALL(0x0076F570);
	};

	void oNpc_States(void)
	{
		XCALL(0x0076BB60);
	};

	oCNpc_States(void)
	{
		oNpc_States();
	};

	~oCNpc_States(void)
	{
		XCALL(0x0076BE00);
	};

	void ClearParserReferences(void)
	{
		XCALL(0x0076BF90);
	};

	void SetOwner(oCNpc*)
	{
		XCALL(0x0076C010);
	};

	int GetState(void)
	{
		XCALL(0x0076C020);
	};

	int IsInState(int)
	{
		XCALL(0x0076C040);
	};

	int IsScriptStateActive(void)
	{
		XCALL(0x0076C080);
	};

	int GetStateTime(void)
	{
		XCALL(0x0076C0A0);
	};

	void SetStateTime(int)
	{
		XCALL(0x0076C0D0);
	};

	void SetRoutine(oCRtnEntry*,oCRtnEntry*)
	{
		XCALL(0x0076C0F0);
	};

	int StartRtnState(int)
	{
		XCALL(0x0076C2E0);
	};

	int ActivateRtnState(int)
	{
		XCALL(0x0076C330);
	};

	int StartAIState(zSTRING const&,int,int,float,int)
	{
		XCALL(0x0076C700);
	};

	int StartAIState(int,int,int,float,int)
	{
		XCALL(0x0076C840);
	};

	int CanPlayerUseAIState( TNpcAIState const&)
	{
		XCALL(0x0076CFC0);
	};

	int CanPlayerUseAIState(void)
	{
		XCALL(0x0076D010);
	};

	int DoAIState(void)
	{
		XCALL(0x0076D1A0);
	};

	void ClearAIState(void)
	{
		XCALL(0x0076D6E0);
	};

	void EndCurrentState(void)
	{
		XCALL(0x0076D880);
	};

	int IsInRoutine(void)
	{
		XCALL(0x0076D8A0);
	};

	int IsInCutscene(void)
	{
		XCALL(0x0076D8D0);
	};

	void StartOutputUnit(int)
	{
		XCALL(0x0076D8F0);
	};

	void StartCutscene(zSTRING const&,zSTRING const&)
	{
		XCALL(0x0076D910);
	};

	void CloseCutscenes(void)
	{
		XCALL(0x0076D9E0);
	};

	void SetParserInstanceNpc(int,oCNpc*)
	{
		XCALL(0x0076DAF0);
	};

	void SetParserInstanceItem(oCItem*)
	{
		XCALL(0x0076DBB0);
	};

	void InitRoutine(void)
	{
		XCALL(0x0076DC10);
	};

	void ChangeRoutine(zSTRING const&)
	{
		XCALL(0x0076DD50);
	};

	void ChangeRoutine(int)
	{
		XCALL(0x0076DF60);
	};

	zSTRING GetRoutineName(void)
	{
		XCALL(0x0076E180);
	};

	void BeginInsertOverlayRoutine(void)
	{
		XCALL(0x0076E250);
	};

	void StopInsertOverlayRoutine(void)
	{
		XCALL(0x0076E2C0);
	};

	void RemoveOverlayEntry(oCRtnEntry*)
	{
		XCALL(0x0076E3F0);
	};

	void RemoveOverlay(void)
	{
		XCALL(0x0076E460);
	};

	void InsertRoutine(int,int,int,int,int,zSTRING const&,int)
	{
		XCALL(0x0076E4A0);
	};

	void InsertRoutineCS(zSTRING const&,zSTRING const&)
	{
		XCALL(0x0076E600);
	};

	int GetLastRoutineState(void)
	{
		XCALL(0x0076E890);
	};

	int GetLastState(void)
	{
		XCALL(0x0076E8B0);
	};

	int IsAIStateDriven(void)
	{
		XCALL(0x0076E8C0);
	};

	void InitAIStateDriven(zVEC3 const&)
	{
		XCALL(0x0076E8E0);
	};

	zVEC3 const& GetAIStatePosition(void)
	{
		XCALL(0x0076EA90);
	};

	zSTRING GetStateInfo(void)
	{
		XCALL(0x0076EAA0);
	};

	zSTRING GetLastError(void)
	{
		XCALL(0x0076EE30);
	};
};


const int FOCUS_MAX = 6;
enum
{
	FOCUS_NORMAL		= 0,
	FOCUS_MELEE			= 1,
	FOCUS_RANGED		= 2,
	FOCUS_THROW_ITEM	= 3,
	FOCUS_THROW_MOB		= 4,
	FOCUS_MAGIC			= 5
};

class oCNpcFocus

{
	struct
	{	
		
		float	n_range3;						
		
		float	n_range1,n_range2;				
		float	n_azi;
		float	n_elev1,n_elev2;				
		int		n_prio;							
		
		float	i_range1,i_range2;				
		float	i_azi;
		float	i_elev1,i_elev2;				
		int		i_prio;							
		
		float	m_range1,m_range2;				
		float	m_azi;
		float	m_elev1,m_elev2;				
		int		m_prio;							
		
		float	max_range;
	};
public:
	static oCNpcFocus*& focus;
	static int s_bHighlightInteractFocus;
	static oCNpcFocus**& focuslist;
	static int s_iHightlightMeleeFocus;
	static oCVisualFX*& highLightFX;
	static int isHighLighted;
	

	static void InitFocusModes(void)
	{
		XCALL(0x006BEA80);
	};

	static void ExitFocusModes(void)
	{
		XCALL(0x006BEBB0);
	};

	static void SetFocusMode(int)
	{
		XCALL(0x006BEC20);
	};

	static zSTRING GetFocusName(void)
	{
		XCALL(0x006BED00);
	};

	void oNpcFocus(void)
	{
		XCALL(0x006BEDD0);
	};

	oCNpcFocus(void)
	{
		oNpcFocus();
	};

	~oCNpcFocus(void)
	{
		XCALL(0x006BEDF0);
	};

	void Init(zSTRING&)
	{
		XCALL(0x006BEE40);
	};

	void Init(int)
	{
		XCALL(0x006BEE70);
	};

	int IsValid(int)
	{
		XCALL(0x006BEF20);
	};

	float GetMaxRange(void)
	{
		XCALL(0x006BEF70);
	};

	float GetRange2(void)
	{
		XCALL(0x006BEF80);
	};

	float GetItemThrowRange(void)
	{
		XCALL(0x006BEF90);
	};

	float GetMobThrowRange(void)
	{
		XCALL(0x006BEFA0);
	};

	int HasLowerPriority(int,int)
	{
		XCALL(0x006BEFB0);
	};

	int GetPriority(int)
	{
		XCALL(0x006BF030);
	};

	int IsInRange(int,float)
	{
		XCALL(0x006BF070);
	};

	int IsInAngle(int,float,float)
	{
		XCALL(0x006BF100);
	};

	int IsNpcInRange(float)
	{
		XCALL(0x006BF1E0);
	};

	int IsNpcInAngle(float,float)
	{
		XCALL(0x006BF230);
	};

	int IsItemInRange(float)
	{
		XCALL(0x006BF280);
	};

	int IsItemInAngle(float,float)
	{
		XCALL(0x006BF2B0);
	};

	int IsMobInRange(float)
	{
		XCALL(0x006BF300);
	};

	int IsMobInAngle(float,float)
	{
		XCALL(0x006BF330);
	};

	float GetAzi(void)
	{
		XCALL(0x006BF380);
	};

	static void StartHighlightningFX(oCNpc*)
	{
		XCALL(0x006BF390);
	};

	static void StopHighlightningFX(void)
	{
		XCALL(0x006BF4C0);
	};
};

class oCMagFrontier 
{
	oCVisualFX	*warningFX;
	oCVisualFX	*shootFX;
	oCNpc		*npc;
	UINT8		isWarning	: 1;
	UINT8		isShooting	: 1;
public:
	void oMagFrontier(void)
	{
		XCALL(0x004736A0);
	};

	oCMagFrontier(void)
	{
		oMagFrontier();
	};

	~oCMagFrontier(void)
	{
		XCALL(0x004736C0);
	};

	void SetNPC(oCNpc*)
	{
		XCALL(0x00473730);
	};

	void DoCheck(void)
	{
		XCALL(0x00473740);
	};

	float GetDistanceNewWorld(zVEC3 const&,float&,zVEC3&)
	{
		XCALL(0x00473F20);
	};

	float GetDistanceDragonIsland(zVEC3 const&,float&,zVEC3&)
	{
		XCALL(0x00474460);
	};

	float GetDistanceAddonWorld(zVEC3 const&,float&,zVEC3&)
	{
		XCALL(0x00474620);
	};

	void StartLightningAtPos(zVEC3&,zVEC3&)
	{
		XCALL(0x00474750);
	};

	void DoWarningFX(int)
	{
		XCALL(0x00474CB0);
	};

	void DisposeWarningFX(void)
	{
		XCALL(0x00474E70);
	};

	void DoShootFX(zVEC3 const&)
	{
		XCALL(0x00474EB0);
	};

	void DisposeShootFX(void)
	{
		XCALL(0x004751A0);
	};

};

class sNpcAIVar
{
public:

	int m_nVariables[1000];
	sNpcAIVar()
	{
		for (int i = 0; i < 1000; i++)
		{
			m_nVariables[i] = 0;
		}
	};
};




typedef
enum	oEIndexDamage
{
	oEDamageIndex_Barrier				= 0									,
	oEDamageIndex_Blunt						,
	oEDamageIndex_Edge						,
	oEDamageIndex_Fire						,
	oEDamageIndex_Fly						,
	oEDamageIndex_Magic						,
	oEDamageIndex_Point						,
	oEDamageIndex_Fall						,
	oEDamageIndex_MAX						,
}
oEDamageIndex, oEProtectionIndex;




typedef
enum	oETypeDamage
{
	oEDamageType_Unknown				= 0									,
	oEDamageType_Barrier				= 1									,
	oEDamageType_Blunt					= oEDamageType_Barrier	<< 1		,
	oEDamageType_Edge					= oEDamageType_Blunt	<< 1		,
	oEDamageType_Fire					= oEDamageType_Edge		<< 1		,
	oEDamageType_Fly					= oEDamageType_Fire		<< 1		,
	oEDamageType_Magic					= oEDamageType_Fly		<< 1		,
	oEDamageType_Point					= oEDamageType_Magic	<< 1		,
	oEDamageType_Fall					= oEDamageType_Point	<< 1		,
	oEDamageType_ForceDWORD				= 0xffffffff				
}										
oEDamageType;




typedef									
enum	oETypeWeapon					
{										
	oETypeWeapon_Unknown				= 0									,
	oETypeWeapon_Fist					= 1									,
	oETypeWeapon_Melee					= oETypeWeapon_Fist		<< 1		,
	oETypeWeapon_Range					= oETypeWeapon_Melee	<< 1		,
	oETypeWeapon_Magic					= oETypeWeapon_Range	<< 1		,
	oETypeWeapon_Special				= oETypeWeapon_Magic	<< 1		,
	oETypeWeapon_ForceDWORD				= 0xffffffff				
}										
oEWeaponType;




typedef	DWORD oTModeDamage, oTDamageMode;
typedef	DWORD oTModeWeapon, oTWeaponMode;


class oCNpc : public oCVob
{
public:
	zCLASS(oCNpc);
	
	
	class oCNpcTimedOverlay
	{
		friend class oCNpc;

		zSTRING		mdsOverlayName;
		float		timer;
	public:
		zSTRING GetMdsName(void)
		{
			XCALL(0x0073E8D0);
		};

		~oCNpcTimedOverlay(void)
		{
			XCALL(0x0073E930);
		};

		int Process(void)
		{
			XCALL(0x0075F4A0);
		};
	};
	
public:
    
    class TActiveInfo{
    public:
        
        BOOL       modified:1;                 

        BOOL       putTorchBackInHand:1;       

        BOOL       changeTorchAni    :1;       
        BOOL       changeTorchAniTo  :1;       

        TActiveInfo           (const oCNpc *npc)
		{
			XCALL(0x0072C960);
		}

        ~TActiveInfo          ()
		{
			XCALL(0x0072C970);
		}

        BOOL       DontDelete()                 {return modified;}
    };
	
	int							m_nID;
	zSTRING						m_sNameNpc;
	
	int							var[25];
	
	zSTRING						m_sEffect;
	int							m_NpcType;
	DWORD						m_dwFlags;
	int							m_nAttribute[8];
	int							m_nHitChance[5];
	int							m_nProtection[8];
	int							m_nDamages[8];
	int							m_nDamageTypes;
	int							m_nGuild;
	int							m_nLevel;
	int							m_pfnMission[5];
	int							m_nFightTactic;
	int							fmode;
	int							m_nVoice;
	int							m_nVoicePitch;
	int							m_nBodymass;
	int							m_pfnDailyRoutine;
	int							m_pfnStartAiState;
	zSTRING						m_sRespawnPoint;
	int							m_nRespawnTime;
	int							m_nSenses;
	int							m_nSensesRange;
	int							m_nAivar[100];
	zSTRING						m_sWp;
	int							m_nExpPoints;
	int							m_nExpNext;	
	int							m_nLearnPoints;
	int							bodyStateInterruptableOverride;
	int							m_bNoFocus; 
	
	int*						m_pAIVAR;
	

public:
	
	
	
	enum oEBloodMode
	{
		oEBloodMode_None			,
		oEBloodMode_Particles		,
		oEBloodMode_Decals			,
		oEBloodMode_Trails			,
		oEBloodMode_Amplification	
	};

	enum { FA_MAX_SITUATIONS	= 19	};
	enum { FA_MAX_ENTRY			= 6		};

	

	typedef
	enum oEFightAction {

		NPC_FIGHTMOVE_NOTINITIALISED	=	 0,		
		NPC_FIGHTMOVE_RUN				=	 1,
		NPC_FIGHTMOVE_RUNBACK			=	 2,
		NPC_FIGHTMOVE_JUMPBACK			=	 3,
		NPC_FIGHTMOVE_TURN				=	 4,
		NPC_FIGHTMOVE_STRAFE			=	 5,
		NPC_FIGHTMOVE_ATTACK			=	 6,
		NPC_FIGHTMOVE_SIDEATTACK		=	 7,
		NPC_FIGHTMOVE_FRONTATTACK		=	 8,
		NPC_FIGHTMOVE_TRIPLEATTACK		=	 9,
		NPC_FIGHTMOVE_WHIRLATTACK		=	10,
		NPC_FIGHTMOVE_MASTERATTACK		=	11,
		NPC_FIGHTMOVE_PREHIT			=	12,
		NPC_FIGHTMOVE_COMBOZONE			=	13,
		NPC_FIGHTMOVE_POSTHIT			=	14,
		NPC_FIGHTMOVE_TURNTOHIT			=	15,
		NPC_FIGHTMOVE_STORMPREHIT		=	16,
		NPC_FIGHTMOVE_PARADE			=	17,
		NPC_FIGHTMOVE_STANDUP			=	18,
		NPC_FIGHTMOVE_WAIT				=	19,
		NPC_FIGHTMOVE_ONGROUND			=	20,
		NPC_FIGHTMOVE_STUMBLE			=	21,
		NPC_FIGHTMOVE_SKIP				=	22,
		NPC_FIGHTMOVE_WAIT_LONG			=	23,
		NPC_FIGHTMOVE_WAIT_EXT			=	24,

		NPC_FIGHTMOVE_MAX				
	}
	TFAction;

typedef
	struct oSActionBlock 
	{
		
		int ownaction	[FA_MAX_ENTRY];
		int max;

		void		InitBlock		(zCParser* par, int sitNr, int faiNr)
		{
			XCALL(0x0067C170);
		};

		int			GetOwnAction	(int quality)
		{
			XCALL(0x0067C390);
		};
	}
	TActionBlock;

	
	
	
	typedef
	struct oSFightAI 
	{
		TActionBlock myactions[FA_MAX_SITUATIONS];
		
		void		Init			(zCParser* par, int aiNumber)
		{
			XCALL(0x0067C3C0);
		};
		int			GetOwnAction	(int situationNr)
		{
			XCALL(0x0067C3F0);
		};
		
	}
	TFightAI;

	typedef oCNpc::oSFightAI TFightAI;
	
	int 			bloodEnabled;	
	int 			bloodDistance;	
	int				bloodAmount;	
	int 			bloodFlow;	
	zSTRING			bloodEmitter;	
	zSTRING			bloodTexture;	
	BOOL			didHit;
	BOOL			didParade;
	BOOL			didShoot;
	BOOL			hasLockedEnemy;
	BOOL			isDefending;
	BOOL			wasAiming;
	TFAction		lastAction;
	oCNpc*			enemy;
	
	
	
	
public:
	
	
	
	typedef
	enum	oEFlagsDamageDescriptor
	{
											
		oEDamageDescFlag_Attacker			= 1										 ,
		oEDamageDescFlag_Npc				= oEDamageDescFlag_Attacker			<< 1 ,
		oEDamageDescFlag_Inflictor			= oEDamageDescFlag_Npc				<< 1 ,
		oEDamageDescFlag_Weapon				= oEDamageDescFlag_Inflictor		<< 1 ,
		oEDamageDescFlag_VisualFX			= oEDamageDescFlag_Weapon			<< 1 ,
		oEDamageDescFlag_SpellID			= oEDamageDescFlag_VisualFX			<< 1 ,
		oEDamageDescFlag_SpellLevel			= oEDamageDescFlag_SpellID			<< 1 ,
		oEDamageDescFlag_DamageType			= oEDamageDescFlag_SpellLevel		<< 1 ,
		oEDamageDescFlag_WeaponType			= oEDamageDescFlag_DamageType		<< 1 ,
		oEDamageDescFlag_Damage				= oEDamageDescFlag_WeaponType		<< 1 ,
		oEDamageDescFlag_HitLocation		= oEDamageDescFlag_Damage			<< 1 ,
		oEDamageDescFlag_FlyDirection		= oEDamageDescFlag_HitLocation		<< 1 ,
		oEDamageDescFlag_OverlayActivate	= oEDamageDescFlag_FlyDirection		<< 1 ,
		oEDamageDescFlag_OverlayInterval	= oEDamageDescFlag_OverlayActivate	<< 1 ,
		oEDamageDescFlag_OverlayDuration	= oEDamageDescFlag_OverlayInterval	<< 1 ,
		oEDamageDescFlag_OverlayDamage		= oEDamageDescFlag_OverlayDuration	<< 1 ,
		oEDamageDescFlag_ForceDWORD			= 0xffffffff				
	}	
	oEDescDamageFlags,
	oEFlagsDamageDesc;

	
	
	
	typedef
	struct	oSDamageDescriptor
	{
		friend class oCNpc												;
																		
		
		
		
	public:																
			DWORD			 dwFieldsValid								;		
																		
			
			
			
			zCVob			*pVobAttacker								;
			oCNpc			*pNpcAttacker								;
			zCVob			*pVobHit									;
			oCVisualFX		*pFXHit;
			oCItem			*pItemWeapon								;
			UINT32			 nSpellID									;
			UINT32			 nSpellCat									;
			UINT32			 nSpellLevel								;
			oTDamageMode	 enuModeDamage								;
			oTWeaponMode	 enuModeWeapon								;
			UINT32			 aryDamage			[ oEDamageIndex_MAX ]	;
			float			 fDamageTotal								;
			float			 fDamageMultiplier							;
			zVEC3			 vecLocationHit								;
			zVEC3			 vecDirectionFly							;
			zSTRING			 strVisualFX								;
			float			 fTimeDuration								;
			float			 fTimeInterval								;
			float			 fDamagePerInterval							;
			BOOL			 bDamageDontKill							;

		
		
		
	protected:
		struct 
		{					 
			UINT32			 bOnce				: 1						;		
			UINT32			 bFinished			: 1						;		
			UINT32			 bIsDead			: 1						;		
			UINT32			 bIsUnconscious		: 1						;		
			UINT32			 lReserved			: 28					;		
		};																
		float			 fAzimuth										;
		float			 fElevation										;
		float			 fTimeCurrent									;
		float			 fDamageReal									;
		float			 fDamageEffective								;
		UINT32			 aryDamageEffective	[ oEDamageIndex_MAX ]		;
		zCVob			*pVobParticleFX									;
		zCParticleFX	*pParticleFX									; 
		oCVisualFX		*pVisualFX										; 
	public:
		oSDamageDescriptor()
		{
			::memset( this, 0, sizeof( *this ) );
			this->fDamageMultiplier = 1.0f;
		}

		~oSDamageDescriptor()
		{
			XCALL(0x004962F0);
		};

		oSDamageDescriptor( const oSDamageDescriptor& o)
		{
			XCALL(0x00664250);
		};

		oSDamageDescriptor& operator=( const oSDamageDescriptor& o)
		{
			XCALL(0x00664310);
		};

		void SetVisualFX(oCVisualFX* fx)
		{
			XCALL(0x00664210);
		};

		void SetFXHit(oCVisualFX* fx)
		{
			XCALL(0x006641C0);
		};

		void Release()
		{
			XCALL(0x00664170);
		};

	}
	oSDescDamage,
	DAMAGE_DESC;
	
	
	
	typedef struct oSDirectionInfo {
	
		zVEC3			checkDirection;
		UINT8			checkForChasm			: 1 ;	
		UINT8			checkForSmallObject		: 1 ;	
		UINT8			checkIfClimbable		: 1 ;	

	} oTDirectionInfo;

	struct oTRobustTrace {

		struct {
			UINT8			stand					: 1	;	
			UINT8			dirChoosed				: 1	;	
			UINT8			exactPosition			: 1	;	
			UINT8			targetReached			: 1	;	
			UINT8			standIfTargetReached	: 1	;	
			UINT8			waiting					: 1	;	
			UINT8			isObstVobSmall			: 1 ;	
			UINT8			targetVisible			: 1	;	
			UINT8			useChasmChecks			: 1 ;
		};													
		
		zVEC3							targetPos					;
		zCVob*							targetVob					;
		zCVob*							obstVob						;
		float							targetDist					;
		float							lastTargetDist				;
		float							maxTargetDist				;
		float							dirTurn						;
		float							timer						;			
		zVEC3							dirFirst					;
		float							dirLastAngle				;
		zCArray	< oTDirectionInfo* >	lastDirections				;
		int								frameCtr					;
		
		
		zVEC3							targetPosArray				[5];
		int								targetPosCounter			;
		int								targetPosIndex				;
        float							checkVisibilityTime			;
		float							positionUpdateTime			;
		float							failurePossibility			;

		oTRobustTrace(){};
	};

	float						speedTurn;
	BOOL						foundFleePoint;
	BOOL						reachedFleePoint;
	zVEC3						vecFlee;
	zVEC3						posFlee;
	zCWaypoint*					waypointFlee;
	oTRobustTrace				rbt;
	zCList<oCNpcTimedOverlay>	timedOverlays;
	zCArray<oCNpcTalent*>		talents;
	int							spellMana;
	oCMagFrontier				magFrontier;
	oCNpc_States				state;
	oCNpcInventory				inventory2;
	oCItemContainer*			trader;
	oCNpc*						tradeNpc;
	
	
	float						rangeToPlayer;
	zCArray<zTSoundHandle>		listOfVoiceHandles;
	int							voiceIndex;			
	zCArray<oCVisualFX*>		effectList;
public:
	
	BOOL						showaidebug        :1;
	BOOL						showNews           :1;
	BOOL						csAllowedAsRole    :1;

	BOOL						isSummoned         :1;
	BOOL						respawnOn          :1;
	BOOL						movlock            :1;
	BOOL						drunk              :1;
	BOOL						mad                :1;
	BOOL						overlay_wounded    :1;
	BOOL						inOnDamage         :1;
	BOOL						autoremoveweapon   :1;
	BOOL						openinventory      :1;
	BOOL						askroutine         :1;
	BOOL						spawnInRange       :1;
    
	int							body_TexVarNr      :16;	    		
	int							body_TexColorNr    :16;				
	int							head_TexVarNr      :16;				
	int							teeth_TexVarNr     :16; 			
	int							guildTrue          :8;				
	int							drunk_heal         :8;				
	int							mad_heal           :8;  			
	int							spells             :8;
	int							bodyState          :19;
	int							m_bAniMessageRunning:1;
	
	int							instance;
	
	
	
	
	zSTRING				mds_name;
	zSTRING				body_visualName;
	zSTRING				head_visualName;

    zVEC3               model_scale;
    float               model_fatness;

	
	int					namenr;
	float				hpHeal;
	float				manaHeal;
	float				swimtime,	divetime;
	float				divectr;
	zCVob*				fireVob;
	int					fireDamage;
	float				fireDamageTimer;

	
	int					attitude;	
	int					tmp_attitude;						
	float				attTimer;
	int					knowsPlayer;

	
	TNpcPerc			percList		[NPC_PERC_MAX];
	int					percActive;
	float				percActiveTime;
	float				percActiveDelta;

	
public:
	BOOL				overrideFallDownHeight;
	float				fallDownHeight;					
	int					fallDownDamage;					
		
	
	oCMag_Book*			mag_book;
	zCList<oCSpell>		activeSpells;
	int					lastHitSpellID;
	int					lastHitSpellCat;

    
	zCArray<zSTRING>	activeOverlays;

	
	void*				askbox;							
	int					askYes,askNo;					
	float				canTalk;	
	oCNpc*				talkOther;

	oCInfo*				info;							
	oCNews*				news;							
	void*				curMission;						

	
	oCNewsMemory		knownNews;						

	
	zCVob*				carry_vob;	
	oCMobInter*			interactMob;
	oCItem*				interactItem;
	int					interactItemCurrentState;
	int					interactItemTargetState;
	
	
	int					script_aiprio;
	int					old_script_state;
	oCAIHuman*			human_ai;
	oCAniCtrl_Human*	anictrl;
	zCRoute*			route;							
	float				damageMul;

	
	oCNpcMessage*		csg;
	oCNpcMessage*		lastLookMsg;
	oCNpcMessage*		lastPointMsg;
	
	
	zCArray<zCVob*>		vobList;
	float				vobcheck_time;
	float				pickvobdelay;
	zCVob*				focus_vob;
	
	
	zCArray<TNpcSlot*>	invSlot;
	zCArray<TNpcSlot*>  tmpSlotList;

	
	float				fadeAwayTime;
	float				respawnTime;

	
	float				selfDist;
	int					fightRangeBase;
	int					fightRangeFist;
	int					fightRangeG;
	
	float				fight_waitTime;
	zTModelAniID		fight_waitForAniEnd;
	float				fight_lastStrafeFrame;

	
	int					soundType;
	zCVob*				soundVob;
	zVEC3				soundPosition;

	
	zCPlayerGroup*		playerGroup;
public:
	static zCClassDef			*classDef;
	static oCNpc::oEBloodMode oCNpc::modeBlood;
	static int oCNpc::ai_baseEnabled;
	static int oCNpc::isEnabledTalkBox;
	static int oCNpc::isEnabledTalkBoxPlayer;
	static int oCNpc::angle_near;
	static int oCNpc::angle_far_up;
	static int oCNpc::angle_far_side;
	static int oCNpc::isEnabledDamageDebug;
	static zSTRING*& oCNpc::FightAIInstances;
	static int*& oCNpc::bodyStateList;
	static int oCNpc::godmode;
	static int oCNpc::ai_disabled;
	static float oCNpc::ai_messagesSkip;
	static float oCNpc::ai_messagesSkipTimer;
	static float oCNpc::ai_scriptStateSkip;
	static float oCNpc::ai_scriptStateSkipTimer;
	static int oCNpc::isEnabledTalkBoxAmbient;
	static int oCNpc::isEnabledTalkBoxNoise;
	static int oCNpc::s_bTargetLocked;
	static int oCNpc::s_bEnabledDialogCamStop;
	static oCNpc*& oCNpc::dontArchiveThisNpc;
	static zMAT4 oCNpc::s_playerPositionMatrix;
	static int oCNpc::game_mode;
	static oCStealContainer*& oCNpc::stealcontainer;
	virtual zCClassDef* _GetClassDef			(void)const																					{XCALL(0x0072E370)};
	virtual void	SetWeaponMode				( int fm )																					{XCALL(0x00739940)};
	virtual void	SetWeaponMode2				( int fm )																					{XCALL(0x00738E80)};
	
	
	
	virtual void	DoDie						( oCNpc* attacker = NULL )																	{XCALL(0x00736760)};
	virtual	oCItem*	DoInsertMunition			( const zSTRING& slotName )																	{XCALL(0x00744190)};
	virtual void	DoRemoveMunition			( void )																					{XCALL(0x00744470)};	
	virtual BOOL	DoSetToFightMode			( oCItem *item)																				{XCALL(0x00745350)};
	virtual BOOL	DoShootArrow				( BOOL autoaim = FALSE )																	{XCALL(0x007446B0)};
	
	
	
	virtual	void	OnDamage					( zCVob* otherVob, zCVob* inflictorVob, float dmg, int dmgType, const zVEC3& hitLocation )	{XCALL(0x0067B860)};
	virtual	void	OnDamage					( oSDamageDescriptor& desc )																{XCALL(0x006660E0)};
	virtual	void	ResetPos					( zVEC3 &pos							)													{XCALL(0x006824D0)};
	virtual void	EmergencyResetPos			( zVEC3 &p								)													{XCALL(0x006827D0)};
	virtual void	SetVisual					(zCVisual* v)																				{XCALL(0x0072E3F0)};
	virtual void	InitByScript				(int nr,BOOL reload = FALSE)																{XCALL(0x0072EE70)};
	int				GetInstance					()																							{XCALL(0x0072E380)};
	zSTRING			GetInstanceName				()																							{XCALL(0x00745880)};
	virtual BOOL	GetScriptInstance			(zSTRING* &scriptInstanceName, int &scriptInstanceIndex)									{XCALL(0x007458C0)};		
	virtual BOOL	SetByScriptInstance			(const zSTRING* scriptInstanceName, const int scriptInstanceIndex)							{XCALL(0x007458F0)};	
	
	virtual zTVobCharClass GetCharacterClass	()																							{XCALL(0x0074ACB0)};
	
	virtual void	Disable						()																							{XCALL(0x00745A20)};
	
	virtual void	Enable						(zVEC3& pos)																				{XCALL(0x00745D40)};
		
	virtual void	InitHumanAI					()																							{XCALL(0x0072F5B0);};
	virtual	BOOL	IsMoreImportant				(zCVob* vob1, zCVob* vob2)																	{XCALL(0x0075D6E0)};
	
	virtual void	OnTouch						(zCVob* otherVob)																			{XCALL(0x0074AF20)};
	virtual void	OnMessage					(zCEventMessage *eventMessage, zCVob* sourceVob)											{XCALL(0x0074B020)};
	virtual BOOL	DoDoAniEvents				()																							{XCALL(0x00742A20)};
	virtual BOOL	DoModelSwapMesh				(const zSTRING &n1, const zSTRING &n2)														{XCALL(0x00743DC0)};
	virtual BOOL	DoTakeVob					(zCVob *vob)																				{XCALL(0x007449C0)};
	virtual BOOL	DoDropVob					(zCVob *vob)																				{XCALL(0x00744DD0)};
	virtual BOOL	DoRemoveFromInventory		(oCItem *item)																				{XCALL(0x00745300)};
	virtual BOOL	DoPutInInventory			(oCItem *item)																				{XCALL(0x007452E0)};
	virtual BOOL	DoThrowVob					(zCVob *vob, float dist)																	{XCALL(0x007450B0)};
	virtual BOOL	DoExchangeTorch				()																							{XCALL(0x00745370)};

	
	virtual void	GetSoundMaterial_MA			( int &med1, oTSndMaterial &mat1, const zSTRING s = "")	{XCALL(0x0073EA10)};
	virtual void	GetSoundMaterial_AM			( int &med2, oTSndMaterial &mat2, int damage)				{XCALL(0x0073EB80)};
	virtual void	GetSoundMaterial_MH_HM		( int &med2, oTSndMaterial &mat2)							{XCALL(0x0073EC50)};

	
	virtual BOOL	IsAPlayer					()																							{XCALL(0x007425A0)};
	virtual BOOL	IsSelfPlayer				()																							{XCALL(0x007425B0)};
	virtual void	SetAsPlayer					()																							{XCALL(0x007426A0)};
	virtual BOOL	IsMonster					()																							{XCALL(0x00742600)};
	virtual BOOL	IsHuman						()																							{XCALL(0x00742640)};
	virtual BOOL	IsGoblin					()																							{XCALL(0x00742650)};
	virtual BOOL	IsOrc						()																							{XCALL(0x00742670)};
	virtual BOOL	IsSkeleton					()																							{XCALL(0x00742680)};
	virtual int		GetPlayerNumber				()																							{XCALL(0x007425C0)};
	virtual BOOL	IsAniMessageRunning			()																							{XCALL(0x0072E390)};
	virtual int		GetCSStateFlags				()																							{XCALL(0x00732A10)};
	
	virtual void	ProcessNpc					()																							{XCALL(0x0073E480)};					
	
	virtual void	ShowDebugInfo				(zCCamera *camera)																			{XCALL(0x0075F0F0)};
	virtual			~oCNpc						()																							{XCALL(0x0072E6A0)};
	
	
	
	virtual void		ThisVobAddedToWorld		(zCWorld *homeWorld)																		{XCALL(0x0073DFA0)};		
	virtual void		ThisVobRemovedFromWorld	(zCWorld *homeWorld)																		{XCALL(0x0073E170)};		
	
	
	
	virtual void		Archive					(zCArchiver &arc)																			{XCALL(0x00746470)};
	virtual void		Unarchive				(zCArchiver &arc)																			{XCALL(0x00747230)};
	virtual BOOL        AllowDiscardingOfSubtree()																							{XCALL(0x00748DE0)};

	
	BOOL IsVictimAwareOfTheft_ast(BOOL&);
	void OnDamage_Hit_ast(oSDamageDescriptor&);



	void SetWeaponMode_ast(int);

	oCNpc* GetPlayer() {return *(oCNpc**)0x00AB2684;};


	void SetInractNpc(oCNpc* pNpc);
	void RelaxBow();
	void SwapSlot(zSTRING const & from, zSTRING const & to);

	void RemoveOverlayMds(const zSTRING& mds)
	{
		RemoveOverlay(mds);
		if(GetAnictrl())
			GetAnictrl()->InitAnimations();
	};
	
	void ApplyOverlayMds(const zSTRING& mds)
	{
		ApplyOverlay(mds);
		if(GetAnictrl())
			GetAnictrl()->InitAnimations();
	};
	
	inline zSTRING GetSlotByItem(oCItem* pItem)
	{
		for(int i=0;i<invSlot.GetNum();i++)
			if(GetSlotItem(invSlot[i]->name) == pItem)
				return invSlot[i]->name;
		return "";
	};
	
	oCVob* DropFromSlot_ast(zSTRING const& slot)
	{
		UnequipItem(GetSlotItem(slot));
		return DropFromSlot(slot);
	};
	
	oCVob* DropFromSlot1_ast(zSTRING const& slot)
	{
		if(GetSlotItem(slot))
			GetSlotItem(slot)->ClearFlag(0x40000000);
		return DropFromSlot(slot);
	};
	
	int GetAmountInInv(int nItemInstance)
	{
		return inventory2.GetAmount(nItemInstance);
	}
	
	int GetAmountInInv(zSTRING sItemInstanceName)
	{
		return this->GetInventory()->GetAmount(zCParser::GetParser()->GetIndex(sItemInstanceName));
	}
	
	zSTRING& GetName()
	{
		return m_sNameNpc;
	};
	
	void SetName(const zSTRING& Name)
	{
		m_sNameNpc.Clear();
		m_sNameNpc.Insert(0, Name);
	};
	
	oCNpcInventory* GetInventory()
	{
		return &inventory2;
	};

	
	static void EnableDamageDebugOutput(int)
	{
		XCALL(0x006643C0);
	};

	static void NotifyDamageToSpy(zSTRING&)
	{
		XCALL(0x006643D0);
	};

	void InitDamage(void)
	{
		XCALL(0x00664490);
	};

	int EV_DamageOnce(oCMsgDamage*)
	{
		XCALL(0x00664660);
	};

	int EV_DamagePerFrame(oCMsgDamage*)
	{
		XCALL(0x006649A0);
	};

	void OnDamage_Hit(oCNpc::oSDamageDescriptor&)
	{
		XCALL(0x00666610);
	};

	void OnDamage_Condition(oCNpc::oSDamageDescriptor&)
	{
		XCALL(0x0066CF30);
	};

	void OnDamage_Script( oCNpc::oSDamageDescriptor&)
	{
		XCALL(0x0066E220);
	};

	void OnDamage_Effects( oCNpc::oSDamageDescriptor&)
	{
		XCALL(0x0066EAF0);
	};

	void OnDamage_Effects_Start( oCNpc::oSDamageDescriptor&)
	{
		XCALL(0x0066EE40);
	};

	void OnDamage_Effects_End( oCNpc::oSDamageDescriptor&)
	{
		XCALL(0x00674300);
	};

	void OnDamage_Anim( oCNpc::oSDamageDescriptor&)
	{
		XCALL(0x00675BD0);
	};

	void OnDamage_Sound( oCNpc::oSDamageDescriptor&)
	{
		XCALL(0x0067A8A0);
	};

	void OnDamage_Events( oCNpc::oSDamageDescriptor&)
	{
		XCALL(0x0067ABE0);
	};

	void OnDamage_State( oCNpc::oSDamageDescriptor&)
	{
		XCALL(0x0067B7E0);
	};

	int HasFlag(unsigned long,unsigned long)
	{
		XCALL(0x0067BD20);
	};

	static void InitFightAI(void)
	{
		XCALL(0x0067C420);
	};

	static void ExitFightAI(void)
	{
		XCALL(0x0067C770);
	};

	int IsNpcBetweenMeAndTarget(zCVob*)
	{
		XCALL(0x0067C7D0);
	};

	int IsInDoubleFightRange(zCVob*,float&)
	{
		XCALL(0x0067C9A0);
	};

	int IsInFightRange(zCVob*,float&)
	{
		XCALL(0x0067CB60);
	};

	int GetFightRange(void)
	{
		XCALL(0x0067CD80);
	};

	void SetFightRangeBase(int)
	{
		XCALL(0x0067CDB0);
	};

	int GetFightRangeBase(void)
	{
		XCALL(0x0067CDC0);
	};

	int GetFightRangeDynamic(void)
	{
		XCALL(0x0067CDD0);
	};

	int GetFightRangeFist(void)
	{
		XCALL(0x0067CDF0);
	};

	int GetFightRangeG(void)
	{
		XCALL(0x0067CE00);
	};

	void SetFightRangeFist(int)
	{
		XCALL(0x0067CE10);
	};

	void SetFightRangeG(int)
	{
		XCALL(0x0067CE20);
	};

	int GetFightActionFromTable(int)
	{
		XCALL(0x0067CE30);
	};

	int GetCurrentFightMove(void)
	{
		XCALL(0x0067CE70);
	};

	int FindNextFightAction(void)
	{
		XCALL(0x0067D680);
	};

	int ThinkNextFightAction(void)
	{
		XCALL(0x0067E350);
	};

	int FightAttackMelee(int)
	{
		XCALL(0x0067EEC0);
	};

	int FightAttackBow(void)
	{
		XCALL(0x0067F700);
	};

	int EV_AttackBow(oCMsgAttack*)
	{
		XCALL(0x0067F7E0);
	};

	int FightAttackMagic(void)
	{
		XCALL(0x0067FA60);
	};

	int EV_AttackMagic(oCMsgAttack*)
	{
		XCALL(0x0067FB10);
	};

	int EV_CastSpell(oCMsgMagic*)
	{
		XCALL(0x0067FB20);
	};

	void CheckRunningFightAnis(void)
	{
		XCALL(0x0067FE10);
	};

	void GotoFightPosition(void)
	{
		XCALL(0x0067FFC0);
	};

	void Fighting(void)
	{
		XCALL(0x006800B0);
	};

	oCItem* GetSpellItem(int)
	{
		XCALL(0x00680270);
	};

	int ReadySpell(int,int)
	{
		XCALL(0x006802E0);
	};

	int UnreadySpell(void)
	{
		XCALL(0x00680480);
	};

	int HasRangedWeaponAndAmmo(void)
	{
		XCALL(0x00680510);
	};

	int CanDrawWeapon(void)
	{
		XCALL(0x006805C0);
	};

	int CanDive(void)
	{
		XCALL(0x00680900);
	};

	int CanSwim(void)
	{
		XCALL(0x00680930);
	};

	float GetClimbRange(void)
	{
		XCALL(0x00680960);
	};

	float GetTurnSpeed(void)
	{
		XCALL(0x00680970);
	};

	float GetJumpRange(void)
	{
		XCALL(0x00680990);
	};

	int RbtChooseChasmAction(zVEC3 const&,zVEC3 const&)
	{
		XCALL(0x006809A0);
	};

	int CanGo(float,zVEC3&)
	{
		XCALL(0x00680B30);
	};

	float GetAngle(zCVob*)
	{
		XCALL(0x006811C0);
	};

	void GetAngles(zVEC3&,float&,float&)
	{
		XCALL(0x006812B0);
	};

	void GetAngles(zCVob*,float&,float&)
	{
		XCALL(0x00681680);
	};

	float GetDistanceToPos2(zVEC3&,int)
	{
		XCALL(0x006816C0);
	};

	float GetFallDownHeight(void)
	{
		XCALL(0x00681790);
	};

	zCVob* GetRbtObstacleVob(void)
	{
		XCALL(0x006817B0);
	};

	zVEC3 GetVecNormalFromBBox(zCVob*,zVEC3&)
	{
		XCALL(0x006817C0);
	};

	void SetFallDownDamage(int)
	{
		XCALL(0x00681D50);
	};

	void SetFallDownHeight(float)
	{
		XCALL(0x00681D60);
	};

	void SetRoute(zCRoute*)
	{
		XCALL(0x00681D70);
	};

	void CreateFallDamage(float)
	{
		XCALL(0x00681DA0);
	};

	void Fleeing(void)
	{
		XCALL(0x006820C0);
	};

	int ThinkNextFleeAction(void)
	{
		XCALL(0x006820D0);
	};

	void Follow(void)
	{
		XCALL(0x006824C0);
	};

	void StandUp(int,int)
	{
		XCALL(0x00682B40);
	};

	float Turn(zVEC3&)
	{
		XCALL(0x00683000);
	};

	float Turning(zVEC3&)
	{
		XCALL(0x00683120);
	};

	void AI_Flee(oCNpc*)
	{
		XCALL(0x00683210);
	};

	void AI_Follow(oCNpc*)
	{
		XCALL(0x00683220);
	};

	int EV_AlignToFP(oCMsgMovement*)
	{
		XCALL(0x00683230);
	};

	int EV_CanSeeNpc(oCMsgMovement*)
	{
		XCALL(0x00683480);
	};

	int EV_GoRoute(oCMsgMovement*)
	{
		XCALL(0x006834D0);
	};

	int EV_Jump(oCMsgMovement*)
	{
		XCALL(0x00683C20);
	};

	int EV_RobustTrace(oCMsgMovement*)
	{
		XCALL(0x00683C80);
	};

	int EV_StandUp(oCMsgMovement*)
	{
		XCALL(0x00683CE0);
	};

	int EV_Strafe(oCMsgMovement*)
	{
		XCALL(0x00683DE0);
	};

	int EV_WhirlAround(oCMsgMovement*)
	{
		XCALL(0x00684BF0);
	};

	int EV_Dodge(oCMsgMovement*)
	{
		XCALL(0x00685290);
	};

	int EV_GotoPos(oCMsgMovement*)
	{
		XCALL(0x006854C0);
	};

	int EV_GotoVob(oCMsgMovement*)
	{
		XCALL(0x00685580);
	};

	int EV_GotoFP(oCMsgMovement*)
	{
		XCALL(0x00685700);
	};

	int EV_SetWalkMode(oCMsgMovement*)
	{
		XCALL(0x006859F0);
	};

	int EV_Turn(oCMsgMovement*)
	{
		XCALL(0x00685DE0);
	};

	int EV_TurnAway(oCMsgMovement*)
	{
		XCALL(0x00685EC0);
	};

	int EV_TurnToPos(oCMsgMovement*)
	{
		XCALL(0x00686070);
	};

	int EV_TurnToVob(oCMsgMovement*)
	{
		XCALL(0x00686160);
	};

	void ForceRotation(float)
	{
		XCALL(0x006863F0);
	};

	int RbtCheckForSolution(zVEC3,zVEC3)
	{
		XCALL(0x00686430);
	};

	void RbtReset(void)
	{
		XCALL(0x00686560);
	};

	void RbtInit(zVEC3&,zCVob*)
	{
		XCALL(0x00686670);
	};

	void RbtUpdate(zVEC3&,zCVob*)
	{
		XCALL(0x00686690);
	};

	int RbtMoveToExactPosition(void)
	{
		XCALL(0x00686880);
	};

	int RobustTrace(void)
	{
		XCALL(0x00686960);
	};

	float RbtCalcTurnDirection(zVEC3 const&,float,int)
	{
		XCALL(0x00686CA0);
	};

	int RbtIsObjectObstacle(zCVob*,zVEC3 const&,zVEC3 const&,zVEC3&)
	{
		XCALL(0x00687080);
	};

	int RbtGetObstacle(zVEC3 const&,zVEC3 const&,zCVob*&,zVEC3&)
	{
		XCALL(0x006872E0);
	};

	int RbtGetSmallObstacle(zVEC3 const&,zCVob*&,zVEC3&)
	{
		XCALL(0x00687490);
	};

	int RbtAvoidObstacles(void)
	{
		XCALL(0x006875E0);
	};

	int RbtIsDirectionValid(zVEC3 const&)
	{
		XCALL(0x00687C80);
	};

	oSDirectionInfo* RbtInsertDirection(zVEC3)
	{
		XCALL(0x00687D00);
	};

	int RbtCheckLastDirection(float)
	{
		XCALL(0x00687F60);
	};

	int RbtCheckIfTargetVisible(void)
	{
		XCALL(0x00688240);
	};

	int RbtGotoFollowPosition(void)
	{
		XCALL(0x00688450);
	};

	int CanStrafe(int,int)
	{
		XCALL(0x00688670);
	};

	int CanJumpBack(int)
	{
		XCALL(0x006888D0);
	};

	void SetWalkStopChasm(int)
	{
		XCALL(0x00688A70);
	};

	int GetWalkStopChasm(void)
	{
		XCALL(0x00688AB0);
	};

	int IsWaitingForAnswer(void)
	{
		XCALL(0x006BC730);
	};

	int SetCurrentAnswer(int,int,oCNpc*)
	{
		XCALL(0x006BC780);
	};

	int EV_Ask(oCMsgConversation*)
	{
		XCALL(0x006BCCA0);
	};

	int EV_WaitForQuestion(oCMsgConversation*)
	{
		XCALL(0x006BCD20);
	};

	int CanTalk(void)
	{
		XCALL(0x006BCEF0);
	};

	void SetCanTalk(int)
	{
		XCALL(0x006BCF10);
	};

	void SetTalkingWith(oCNpc*,int)
	{
		XCALL(0x006BCF30);
	};

	oCNpc* GetTalkingWith(void)
	{
		XCALL(0x006BCF60);
	};

	void StartTalkingWith(oCNpc*)
	{
		XCALL(0x006BCF70);
	};

	void StopTalkingWith(void)
	{
		XCALL(0x006BCF90);
	};

	zCEventMessage* GetTalkingWithMessage(oCNpc*)
	{
		XCALL(0x006BCFB0);
	};

	int CanBeTalkedTo(void)
	{
		XCALL(0x006BD060);
	};

	void StopRunningOU(void)
	{
		XCALL(0x006BD240);
	};

	int AssessGivenItem(oCItem*,oCNpc*)
	{
		XCALL(0x006BD3B0);
	};

	oCNpc* GetTradeNpc(void)
	{
		XCALL(0x006BD550);
	};

	void SetTradeNpc(oCNpc*)
	{
		XCALL(0x006BD560);
	};

	oCItem* GetTradeItem(void)
	{
		XCALL(0x006BD570);
	};

	void OpenTradeContainer(oCItem*,oCNpc*,int)
	{
		XCALL(0x006BD590);
	};

	void CloseTradeContainer(void)
	{
		XCALL(0x006BD770);
	};

	void OpenTradeOffer(oCNpc*)
	{
		XCALL(0x006BD820);
	};

	int CheckItemReactModule(oCNpc*,oCItem*)
	{
		XCALL(0x006BD940);
	};

	void ExchangeTradeModules(oCNpc*)
	{
		XCALL(0x006BDAC0);
	};

	zSTRING GetBloodTexture(void)
	{
		XCALL(0x006D38B0);
	};

	TActiveInfo* GetActiveInfo() const
	{
		XCALL(0x0072C9B0);
	};

	TActiveInfo* GetActiveInfoWritable() const
	{
		XCALL(0x0072C9D0);
	};

	void Shrink(void)
	{
		XCALL(0x0072CA20);
	};

	void UnShrink(void)
	{
		XCALL(0x0072CBA0);
	};

	void AvoidShrink(int)
	{
		XCALL(0x0072D250);
	};

	int ApplyOverlay(zSTRING const&)
	{
		XCALL(0x0072D2C0);
	};

	void RemoveOverlay(zSTRING const&)
	{
		XCALL(0x0072D5C0);
	};

	void SetModelScale(zVEC3 const&)
	{
		XCALL(0x0072D7B0);
	};

	void SetFatness(float)
	{
		XCALL(0x0072D8A0);
	};

	void oNpc(void)
	{
		XCALL(0x0072D950);
	};

	oCNpc(void)
	{
		oNpc();
	};

	void CleanUp(void)
	{
		XCALL(0x0072E410);
	};

	void DeleteHumanAI(void)
	{
		XCALL(0x0072F650);
	};

	zSTRING GetGuildName(void)
	{
		XCALL(0x0072F690);
	};

	zSTRING GetName(int)
	{
		XCALL(0x0072F820);
	};

	int IsHostile(oCNpc*)
	{
		XCALL(0x0072F870);
	};

	int IsFriendly(oCNpc*)
	{
		XCALL(0x0072F900);
	};

	int IsNeutral(oCNpc*)
	{
		XCALL(0x0072F990);
	};

	int IsAngry(oCNpc*)
	{
		XCALL(0x0072FA20);
	};

	int GetAttitude(oCNpc*)
	{
		XCALL(0x0072FAB0);
	};

	int GetPermAttitude(oCNpc*)
	{
		XCALL(0x0072FB30);
	};

	void SetAttitude(int)
	{
		XCALL(0x0072FB80);
	};

	void SetTmpAttitude(int)
	{
		XCALL(0x0072FBD0);
	};

	int GetProtectionByIndex(oEIndexDamage)
	{
		XCALL(0x0072FC20);
	};

	int GetProtectionByType(oETypeDamage)
	{
		XCALL(0x0072FC30);
	};

	int GetProtectionByMode(unsigned long)
	{
		XCALL(0x0072FCD0);
	};

	int GetFullProtection(void)
	{
		XCALL(0x0072FD60);
	};

	void SetProtectionByIndex(oEIndexDamage,int)
	{
		XCALL(0x0072FD80);
	};

	int GetDamageByIndex(oEIndexDamage)
	{
		XCALL(0x0072FDA0);
	};

	int GetDamageByType(oETypeDamage)
	{
		XCALL(0x0072FDB0);
	};

	int GetDamageByMode(unsigned long)
	{
		XCALL(0x0072FE50);
	};

	int GetFullDamage(void)
	{
		XCALL(0x0072FEE0);
	};

	void SetDamages(int*)
	{
		XCALL(0x0072FF00);
	};

	int GetAttribute(int)
	{
		XCALL(0x0072FF20);
	};

	int GetHitChance(int)
	{
		XCALL(0x0072FF30);
	};

	void SetHitChance(int,int)
	{
		XCALL(0x0072FF40);
	};

	void ChangeAttribute(int,int)
	{
		XCALL(0x0072FF60);
	};

	void SetAttribute(int,int)
	{
		XCALL(0x0072FFF0);
	};

	int GetOverlay(zSTRING&)
	{
		XCALL(0x00730010);
	};

	void CheckModelOverlays(void)
	{
		XCALL(0x007301D0);
	};

	void SetToMad(float)
	{
		XCALL(0x007303F0);
	};

	void HealFromMad(void)
	{
		XCALL(0x00730530);
	};

	void SetToDrunk(float)
	{
		XCALL(0x00730650);
	};

	void HealFromDrunk(void)
	{
		XCALL(0x00730660);
	};

	void CheckAngryTime(void)
	{
		XCALL(0x00730670);
	};

	int CanRecruitSC(void)
	{
		XCALL(0x00730720);
	};

	int IsDisguised(void)
	{
		XCALL(0x00730730);
	};

	int GetGuild(void)
	{
		XCALL(0x00730750);
	};

	void SetGuild(int)
	{
		XCALL(0x00730760);
	};

	int GetTrueGuild(void)
	{
		XCALL(0x00730770);
	};

	void SetTrueGuild(int)
	{
		XCALL(0x00730780);
	};

	int GetCamp(void)
	{
		XCALL(0x00730790);
	};

	int IsGuildFriendly(int)
	{
		XCALL(0x007307A0);
	};

	int GetGuildAttitude(int)
	{
		XCALL(0x007307D0);
	};

	void CreateItems(int,int)
	{
		XCALL(0x00730800);
	};

	void SetFlag(int)
	{
		XCALL(0x007309C0);
	};

	int HasFlag(int)
	{
		XCALL(0x007309E0);
	};

	oCNpcTalent* GetTalent(int,int)
	{
		XCALL(0x00730A00);
	};

	void SetTalentValue(int,int)
	{
		XCALL(0x00730BE0);
	};

	int GetTalentValue(int)
	{
		XCALL(0x00730DC0);
	};

	void SetTalentSkill(int,int)
	{
		XCALL(0x00730F60);
	};

	int GetTalentSkill(int)
	{
		XCALL(0x007317F0);
	};

	int HasTalent(int,int)
	{
		XCALL(0x00731990);
	};

	int CanUse(oCItem*)
	{
		XCALL(0x007319B0);
	};

	void DisplayCannotUse(void)
	{
		XCALL(0x00731CB0);
	};

	void CheckAllCanUse(void)
	{
		XCALL(0x00731DE0);
	};

	oCVob* GetSlotVob(zSTRING const&)
	{
		XCALL(0x00731EF0);
	};

	oCItem* GetSlotItem(zSTRING const&)
	{
		XCALL(0x00731F90);
	};

	oCItem* GetItem(int,int)
	{
		XCALL(0x00732030);
	};

	oCNpc* GetSlotNpc(zSTRING const&)
	{
		XCALL(0x00732050);
	};

	void AddItemEffects(oCItem*)
	{
		XCALL(0x007320F0);
	};

	void RemoveItemEffects(oCItem*)
	{
		XCALL(0x00732270);
	};

	void EquipItem(oCItem*)
	{
		XCALL(0x007323C0);
	};

	void UnequipItem(oCItem*)
	{
		XCALL(0x007326C0);
	};

	int GetCutsceneDistance(void)
	{
		XCALL(0x007329A0);
	};

	void SetCSEnabled(int)
	{
		XCALL(0x007329F0);
	};

	void SetFocusVob(zCVob*)
	{
		XCALL(0x00732B60);
	};

	zCVob* GetFocusVob(void)
	{
		XCALL(0x00732BB0);
	};

	void ClearFocusVob(void)
	{
		XCALL(0x00732BC0);
	};

	oCNpc* GetFocusNpc(void)
	{
		XCALL(0x00732BF0);
	};

	oCNpc* GetNearestFightNpcLeft(void)
	{
		XCALL(0x00732C20);
	};

	oCNpc* GetNearestFightNpcRight(void)
	{
		XCALL(0x00732DB0);
	};

	int FocusCheckBBox(zCVob const*,int,int,float,float&)
	{
		XCALL(0x00732F40);
	};

	int FocusCheck(zCVob const*,int,int,float,float&)
	{
		XCALL(0x007331C0);
	};

	void ToggleFocusVob(int)
	{
		XCALL(0x007335B0);
	};

	void CollectFocusVob(int)
	{
		XCALL(0x00733A10);
	};

	void GetNearestValidVob(float)
	{
		XCALL(0x007344F0);
	};

	void GetNearestVob(float)
	{
		XCALL(0x00734860);
	};

	oCAniCtrl_Human* GetAnictrl(void)
	{
		XCALL(0x00734B40);
	};

	void ResetToHumanAI(void)
	{
		XCALL(0x00734B50);
	};

	void SetEnemy(oCNpc*)
	{
		XCALL(0x00734BC0);
	};

	oCNpc* GetNextEnemy(void)
	{
		XCALL(0x00734E30);
	};

	int IsConditionValid(void)
	{
		XCALL(0x00735130);
	};

	int IsInFightFocus(zCVob*)
	{
		XCALL(0x00735290);
	};

	oCItem* HasEquippedStolenItem(oCNpc*)
	{
		XCALL(0x00735300);
	};

	void Burn(int,float)
	{
		XCALL(0x00735520);
	};

	void StopBurn(void)
	{
		XCALL(0x007357A0);
	};

	void Interrupt(int,int)
	{
		XCALL(0x00735AB0);
	};

	int GetWeaponDamage(oCItem*)
	{
		XCALL(0x00735E30);
	};

	int GetBluntDamage(oCItem*)
	{
		XCALL(0x00735E80);
	};

	void DropUnconscious(float,oCNpc*)
	{
		XCALL(0x00735EB0);
	};

	void CheckUnconscious(void)
	{
		XCALL(0x00736230);
	};

	zSTRING GetInterruptPrefix(void)
	{
		XCALL(0x00736680);
	};

	void CompleteHeal(void)
	{
		XCALL(0x00736720);
	};

	int IsDead(void)
	{
		XCALL(0x00736740);
	};

	int IsUnconscious(void)
	{
		XCALL(0x00736750);
	};

	void StartFadeAway(void)
	{
		XCALL(0x00736D40);
	};

	int IsFadingAway(void)
	{
		XCALL(0x00736E30);
	};

	int FadeAway(void)
	{
		XCALL(0x00736E40);
	};

	int BeamTo(zSTRING const&)
	{
		XCALL(0x00736EE0);
	};

	void DropInventory(void)
	{
		XCALL(0x00737350);
	};

	int HasInHand(int)
	{
		XCALL(0x00737360);
	};

	int HasInHand(zCVob*)
	{
		XCALL(0x007374B0);
	};

	void DropAllInHand(void)
	{
		XCALL(0x007375E0);
	};

	oCItem* GetWeapon(void)
	{
		XCALL(0x007377A0);
	};

	oCItem* GetEquippedMeleeWeapon(void)
	{
		XCALL(0x00737930);
	};

	oCItem* GetEquippedRangedWeapon(void)
	{
		XCALL(0x00737A40);
	};

	oCItem* GetEquippedArmor(void)
	{
		XCALL(0x00737B50);
	};

	int IsSameHeight(zCVob*)
	{
		XCALL(0x00737BE0);
	};

	void TurnToEnemy(void)
	{
		XCALL(0x00737CD0);
	};

	int ShieldEquipped(void)
	{
		XCALL(0x00737E50);
	};

	int GetWeaponDamage(void)
	{
		XCALL(0x00737F20);
	};

	void SetMovLock(int)
	{
		XCALL(0x007380B0);
	};

	int IsMovLock(void)
	{
		XCALL(0x007380E0);
	};

	void SetHead(void)
	{
		XCALL(0x007380F0);
	};

	void SetAdditionalVisuals(zSTRING&,int,int,zSTRING&,int,int,int)
	{
		XCALL(0x00738350);
	};

	void InitModel(void)
	{
		XCALL(0x00738480);
	};

	zCModel* GetModel(void)
	{
		XCALL(0x00738720);
	};

	zSTRING GetVisualBody(void)
	{
		XCALL(0x007387C0);
	};

	zSTRING GetVisualHead(void)
	{
		XCALL(0x00738810);
	};

	int StartFaceAni(zSTRING const&,float,float)
	{
		XCALL(0x00738860);
	};

	int StartStdFaceAni(int)
	{
		XCALL(0x00738960);
	};

	int StopFaceAni(zSTRING const&)
	{
		XCALL(0x00738B50);
	};

	int GetWeaponMode(void)
	{
		XCALL(0x00738C40);
	};

	void SetWeaponMode2(zSTRING const&)
	{
		XCALL(0x00738C60);
	};

	int GetNextWeaponMode(int,int,int)
	{
		XCALL(0x00739A30);
	};

	void Equip(oCItem*)
	{
		XCALL(0x00739C90);
	};

	void EquipWeapon(oCItem*)
	{
		XCALL(0x0073A030);
	};

	void EquipFarWeapon(oCItem*)
	{
		XCALL(0x0073A310);
	};

	void EquipArmor(oCItem*)
	{
		XCALL(0x0073A490);
	};

	void SetToFightMode(oCItem*,int)
	{
		XCALL(0x0073A740);
	};

	void SetToFistMode(void)
	{
		XCALL(0x0073A940);
	};

	void Activate(int,int)
	{
		XCALL(0x0073AB40);
	};

	oCVob* GetRightHand(void)
	{
		XCALL(0x0073AB50);
	};

	oCVob* GetLeftHand(void)
	{
		XCALL(0x0073ABE0);
	};

	void DropVob(oCVob*,zVEC3&)
	{
		XCALL(0x0073AC70);
	};

	void SetCarryVob(zCVob*)
	{
		XCALL(0x0073AE00);
	};

	zCVob* GetCarryVob(void)
	{
		XCALL(0x0073B0B0);
	};

	void SetLeftHand(oCVob*)
	{
		XCALL(0x0073B0C0);
	};

	void SetRightHand(oCVob*)
	{
		XCALL(0x0073B1C0);
	};

	int HasTorch(void)
	{
		XCALL(0x0073B2C0);
	};

	void ExchangeTorch(void)
	{
		XCALL(0x0073B400);
	};

	void SetTorchAni(int,int)
	{
		XCALL(0x0073B410);
	};

	void CheckSetTorchAni(void)
	{
		XCALL(0x0073B6D0);
	};

	void CheckPutbackTorch(void)
	{
		XCALL(0x0073B940);
	};

	int UseItem(oCItem*)
	{
		XCALL(0x0073BC10);
	};

	float GetThrowSpeed(float,float)
	{
		XCALL(0x0073C230);
	};

	int HasArrowInHand(void)
	{
		XCALL(0x0073C260);
	};

	int HasArrowInInv(void)
	{
		XCALL(0x0073C3B0);
	};

	int HasBoltInInv(void)
	{
		XCALL(0x0073C4A0);
	};

	int HasBoltInHand(void)
	{
		XCALL(0x0073C590);
	};

	int IsMunitionAvailable(oCItem*)
	{
		XCALL(0x0073C6E0);
	};

	void GetTalentInfo(int,zSTRING&,zSTRING&,zSTRING&)
	{
		XCALL(0x0073C860);
	};

	void GetSpellInfo(int,zSTRING&,zSTRING&)
	{
		XCALL(0x0073CA90);
	};

	void GetAttribInfo(int,zSTRING&,zSTRING&)
	{
		XCALL(0x0073CC80);
	};

	void CreateSpell(int)
	{
		XCALL(0x0073CE20);
	};

	void LearnSpell(int)
	{
		XCALL(0x0073CE80);
	};

	int HasSpell(int)
	{
		XCALL(0x0073CEC0);
	};

	void DestroySpell(int)
	{
		XCALL(0x0073CEE0);
	};

	void SetActiveSpellInfo(int)
	{
		XCALL(0x0073CF20);
	};

	int GetActiveSpellNr(void)
	{
		XCALL(0x0073CF60);
	};

	int GetActiveSpellCategory(void)
	{
		XCALL(0x0073CFA0);
	};

	int GetActiveSpellLevel(void)
	{
		XCALL(0x0073CFE0);
	};

	int GetActiveSpellIsScroll(void)
	{
		XCALL(0x0073D020);
	};

	void InsertActiveSpell(oCSpell*)
	{
		XCALL(0x0073D070);
	};

	void RemoveActiveSpell(oCSpell*)
	{
		XCALL(0x0073D090);
	};

	void RemoveActiveSpell(int)
	{
		XCALL(0x0073D120);
	};

	int DoActiveSpells(void)
	{
		XCALL(0x0073D1D0);
	};

	void KillActiveSpells(void)
	{
		XCALL(0x0073D2B0);
	};

	oCSpell* IsSpellActive(int)
	{
		XCALL(0x0073D340);
	};

	int HasMagic(void)
	{
		XCALL(0x0073D380);
	};

	int GetNumberOfSpells(void)
	{
		XCALL(0x0073D3B0);
	};

	void CopyTransformSpellInvariantValuesTo(oCNpc*)
	{
		XCALL(0x0073D3D0);
	};

	void OpenScreen_Help(void)
	{
		XCALL(0x0073D5B0);
	};

	void OpenScreen_Log(void)
	{
		XCALL(0x0073D5C0);
	};

	void OpenScreen_Map(int)
	{
		XCALL(0x0073D8D0);
	};

	void OpenScreen_Status(void)
	{
		XCALL(0x0073D980);
	};

	int IsVoiceActive(void)
	{
		XCALL(0x0073E350);
	};

	void StopAllVoices(void)
	{
		XCALL(0x0073E360);
	};

	int UpdateNextVoice(void)
	{
		XCALL(0x0073E3C0);
	};

	void DoSpellBook(void)
	{
		XCALL(0x0073E980);
	};

	void OpenSpellBook(int)
	{
		XCALL(0x0073E990);
	};

	void CloseSpellBook(int)
	{
		XCALL(0x0073E9E0);
	};

	oCMag_Book* GetSpellBook(void)
	{
		XCALL(0x0073EA00);
	};

	int HasSenseHear(void)
	{
		XCALL(0x0073ED20);
	};

	int HasSenseSee(void)
	{
		XCALL(0x0073ED30);
	};

	int HasSenseSmell(void)
	{
		XCALL(0x0073ED40);
	};

	void SetSenses(int)
	{
		XCALL(0x0073ED50);
	};

	void PrintStateCallDebug(zSTRING const&,int,int)
	{
		XCALL(0x0073ED60);
	};

	int GetOldScriptState(void)
	{
		XCALL(0x0073EFD0);
	};

	int GetAIState(void)
	{
		XCALL(0x0073EFE0);
	};

	int GetAIStateTime(void)
	{
		XCALL(0x0073EFF0);
	};

	int IsAIState(int)
	{
		XCALL(0x0073F000);
	};

	void ShowState(int,int)
	{
		XCALL(0x0073F010);
	};

	int IsNear(oCNpc*)
	{
		XCALL(0x0073FCC0);
	};

	oCItem* DetectItem(int,int)
	{
		XCALL(0x0073FD40);
	};

	oCNpc* DetectPlayer(void)
	{
		XCALL(0x0073FE00);
	};

	oCMobInter* FindMobInter(zSTRING const&)
	{
		XCALL(0x0073FE70);
	};

	zCVobSpot* FindSpot(zSTRING const&,int,float)
	{
		XCALL(0x007400E0);
	};

	void ForceVobDetection(zCVob*)
	{
		XCALL(0x00740470);
	};

	int HasVobDetected(zCVob*)
	{
		XCALL(0x007405B0);
	};

	int CheckForOwner(zCVob*)
	{
		XCALL(0x007405F0);
	};

	void AI_ForceDetection(void)
	{
		XCALL(0x00740730);
	};

	int CanSense(zCVob*)
	{
		XCALL(0x00740740);
	};

	void DetectWitnesses(oCNpc*,int)
	{
		XCALL(0x007407E0);
	};

	oCNpc* FindNpc(int,int,int,int)
	{
		XCALL(0x00740A80);
	};

	oCNpc* FindNpcEx(int,int,int,int,int,int)
	{
		XCALL(0x00740B80);
	};

	oCNpc* FindNpcExAtt(int,int,int,int,int,int,int)
	{
		XCALL(0x00740E00);
	};

	int GetComrades(void)
	{
		XCALL(0x007410B0);
	};

	int AreWeStronger(oCNpc*)
	{
		XCALL(0x007412E0);
	};

	oCNpc* IsEnemyBehindFriend(oCNpc*)
	{
		XCALL(0x00741600);
	};

	int InMobInteraction(zSTRING const&,int)
	{
		XCALL(0x00741800);
	};

	int FreeLineOfSight(zCVob*)
	{
		XCALL(0x007418E0);
	};

	int FreeLineOfSight(zVEC3&,zCVob*)
	{
		XCALL(0x00741940);
	};

	int FreeLineOfSight_WP(zVEC3&,zCVob*)
	{
		XCALL(0x00741AA0);
	};

	int CanSee(zCVob*,int)
	{
		XCALL(0x00741C10);
	};

	void SetSwimDiveTime(float,float)
	{
		XCALL(0x00741F70);
	};

	void GetSwimDiveTime(float&,float&,float&)
	{
		XCALL(0x00741FA0);
	};

	void Regenerate(void)
	{
		XCALL(0x00741FD0);
	};

	void RefreshNpc(void)
	{
		XCALL(0x00742110);
	};

	void RenderNpc(zCView*)
	{
		XCALL(0x00742370);
	};

	void SetKnowsPlayer(int)
	{
		XCALL(0x007425D0);
	};

	int KnowsPlayer(oCNpc*)
	{
		XCALL(0x007425E0);
	};

	int KnowsPlayer(int)
	{
		XCALL(0x007425F0);
	};

	int HasMunitionInHand(oCItem*)
	{
		XCALL(0x00744040);
	};

	void Pack(zCBuffer&)
	{
		XCALL(0x007455B0);
	};

	void Unpack(zCBuffer&)
	{
		XCALL(0x00745640);
	};

	int IsInFightMode_S(int)
	{
		XCALL(0x007456E0);
	};

	int IsAiming_S(oCNpc*)
	{
		XCALL(0x00745760);
	};

	static zSTRING GetInstanceByID(int)
	{
		XCALL(0x00745940);
	};

	static int GetIDByInstance(zSTRING const&)
	{
		XCALL(0x007459A0);
	};

	void ClearEM(void)
	{
		XCALL(0x00746400);
	};

	void PreSaveGameProcessing(void)
	{
		XCALL(0x00748880);
	};

	void PostSaveGameProcessing(void)
	{
		XCALL(0x00748B90);
	};

	oCItem* IdentifyMushroom(oCItem*)
	{
		XCALL(0x00748DF0);
	};

	void IdentifyAllMushrooms(void)
	{
		XCALL(0x00748FE0);
	};

	int HasMissionItem(void)
	{
		XCALL(0x00749110);
	};

	oCItem* IsInInv(oCItem*,int)
	{
		XCALL(0x00749160);
	};

	oCItem* GetFromInv(int,int)
	{
		XCALL(0x00749180);
	};

	oCItem* IsInInv(int,int)
	{
		XCALL(0x007491E0);
	};

	oCItem* IsInInv(zSTRING const&,int)
	{
		XCALL(0x00749200);
	};

	int CanCarry(oCItem*)
	{
		XCALL(0x00749220);
	};

	oCItem* PutInInv(oCItem*)
	{
		XCALL(0x00749350);
	};

	oCItem* PutInInv(int,int)
	{
		XCALL(0x007494C0);
	};

	oCItem* PutInInv(zSTRING const&,int)
	{
		XCALL(0x00749570);
	};

	oCItem* RemoveFromInv(oCItem*,int)
	{
		XCALL(0x007495A0);
	};

	oCItem* RemoveFromInv(int,int)
	{
		XCALL(0x007495F0);
	};

	oCItem* RemoveFromInv(zSTRING const&,int)
	{
		XCALL(0x00749640);
	};

	int IsSlotFree(zSTRING const&)
	{
		XCALL(0x00749690);
	};

	int IsSlotFree( TNpcSlot*)
	{
		XCALL(0x00749760);
	};

	void SetToSlotPosition(zCVob*,zSTRING const&)
	{
		XCALL(0x00749780);
	};

	void CreateInvSlot(zSTRING const&)
	{
		XCALL(0x00749800);
	};

	void DeleteInvSlot(zSTRING const&)
	{
		XCALL(0x007499E0);
	};

	TNpcSlot* GetInvSlot(const zSTRING& name)
	{
		XCALL(0x00749AE0);
	};

	TNpcSlot* GetInvSlot(zCVob*)
	{
		XCALL(0x00749BA0);
	};

	int IsInvSlotAvailable(zSTRING const&)
	{
		XCALL(0x00749BE0);
	};

	void PutInSlot(zSTRING const&,oCVob*,int)
	{
		XCALL(0x00749CB0);
	};

	void PutInSlot( TNpcSlot*,oCVob*,int)
	{
		XCALL(0x00749D80);
	};

	void RemoveFromAllSlots(int)
	{
		XCALL(0x0074A230);
	};

	oCVob* RemoveFromSlot(zSTRING const&,int,int)
	{
		XCALL(0x0074A270);
	};

	oCVob* RemoveFromSlot( TNpcSlot*,int,int)
	{
		XCALL(0x0074A340);
	};

	oCVob* DropFromSlot(zSTRING const&)
	{
		XCALL(0x0074A590);
	};

	oCVob* DropFromSlot( TNpcSlot*)
	{
		XCALL(0x0074A660);
	};

	void UpdateSlots(void)
	{
		XCALL(0x0074A9D0);
	};

	void SetInteractMob(oCMobInter*)
	{
		XCALL(0x0074AB00);
	};

	oCMobInter* GetInteractMob(void)
	{
		XCALL(0x0074ACA0);
	};

	void SetInteractItem(oCItem*)
	{
		XCALL(0x0074ACC0);
	};

	int EV_DrawWeapon(oCMsgWeapon*)
	{
		XCALL(0x0074CC10);
	};

	int EV_DrawWeapon1(oCMsgWeapon*)
	{
		XCALL(0x0074D2E0);
	};

	int EV_DrawWeapon2(oCMsgWeapon*)
	{
		XCALL(0x0074D580);
	};

	int EV_RemoveWeapon(oCMsgWeapon*)
	{
		XCALL(0x0074DB20);
	};

	int EV_RemoveWeapon1(oCMsgWeapon*)
	{
		XCALL(0x0074E4B0);
	};

	int EV_RemoveWeapon2(oCMsgWeapon*)
	{
		XCALL(0x0074E630);
	};

	int EV_ChooseWeapon(oCMsgWeapon*)
	{
		XCALL(0x0074E980);
	};

	int EV_ForceRemoveWeapon(oCMsgWeapon*)
	{
		XCALL(0x0074EC40);
	};

	int EV_EquipBestWeapon(oCMsgWeapon*)
	{
		XCALL(0x0074EF10);
	};

	void EquipBestWeapon(int)
	{
		XCALL(0x0074EF30);
	};

	int EV_EquipBestArmor(oCMsgWeapon*)
	{
		XCALL(0x0074F020);
	};

	void EquipBestArmor(void)
	{
		XCALL(0x0074F0B0);
	};

	int EV_UnequipWeapons(oCMsgWeapon*)
	{
		XCALL(0x0074F130);
	};

	int EV_UnequipArmor(oCMsgWeapon*)
	{
		XCALL(0x0074F2F0);
	};

	int EV_EquipArmor(oCMsgWeapon*)
	{
		XCALL(0x0074F3A0);
	};

	int EV_AttackForward(oCMsgAttack*)
	{
		XCALL(0x0074F400);
	};

	int EV_AttackLeft(oCMsgAttack*)
	{
		XCALL(0x00750160);
	};

	int EV_AttackRight(oCMsgAttack*)
	{
		XCALL(0x00750D00);
	};

	int EV_AttackRun(oCMsgAttack*)
	{
		XCALL(0x007517D0);
	};

	int EV_AttackFinish(oCMsgAttack*)
	{
		XCALL(0x00751AF0);
	};

	int EV_Parade(oCMsgAttack*)
	{
		XCALL(0x007522D0);
	};

	int InitAim(oCMsgAttack*,oCNpc**,int*,int*,int)
	{
		XCALL(0x007529A0);
	};

	int TransitionAim(int,int)
	{
		XCALL(0x00752B30);
	};

	int InterpolateAim(oCNpc*)
	{
		XCALL(0x00752CC0);
	};

	int FinalizeAim(int,int)
	{
		XCALL(0x00752E00);
	};

	int EV_StopAim(oCMsgAttack*)
	{
		XCALL(0x00752F20);
	};

	int EV_AimAt(oCMsgAttack*)
	{
		XCALL(0x00752F40);
	};

	int EV_ShootAt(oCMsgAttack*)
	{
		XCALL(0x00753010);
	};

	int EV_Defend(oCMsgAttack*)
	{
		XCALL(0x00753190);
	};

	int EV_Drink(oCMsgUseItem*)
	{
		XCALL(0x007531C0);
	};

	int EV_TakeVob(oCMsgManipulate*)
	{
		XCALL(0x007534E0);
	};

	int EV_DropVob(oCMsgManipulate*)
	{
		XCALL(0x007538C0);
	};

	int EV_ThrowVob(oCMsgManipulate*)
	{
		XCALL(0x00753BB0);
	};

	int EV_Exchange(oCMsgManipulate*)
	{
		XCALL(0x00753E30);
	};

	int EV_DropMob(oCMsgManipulate*)
	{
		XCALL(0x00754130);
	};

	int EV_TakeMob(oCMsgManipulate*)
	{
		XCALL(0x007541F0);
	};

	int EV_UseMob(oCMsgManipulate*)
	{
		XCALL(0x00754290);
	};

	int EV_UseMobWithItem(oCMsgManipulate*)
	{
		XCALL(0x00754490);
	};

	int EV_InsertInteractItem(oCMsgManipulate*)
	{
		XCALL(0x007544E0);
	};

	int EV_ExchangeInteractItem(oCMsgManipulate*)
	{
		XCALL(0x007546F0);
	};

	int EV_RemoveInteractItem(oCMsgManipulate*)
	{
		XCALL(0x00754880);
	};

	int EV_CreateInteractItem(oCMsgManipulate*)
	{
		XCALL(0x00754890);
	};

	int EV_DestroyInteractItem(oCMsgManipulate*)
	{
		XCALL(0x00754B40);
	};

	zCModelAni* InteractItemGetAni(zSTRING const&,int,int)
	{
		XCALL(0x00754D10);
	};

	int EV_PlaceInteractItem(oCMsgManipulate*)
	{
		XCALL(0x00755020);
	};

	int GetInteractItemMaxState(zSTRING const&)
	{
		XCALL(0x00755150);
	};

	int InteractItemIsInState(zSTRING const&,int)
	{
		XCALL(0x00755360);
	};

	int EV_EquipItem(oCMsgManipulate*)
	{
		XCALL(0x00755580);
	};

	int EV_UseItem(oCMsgManipulate*)
	{
		XCALL(0x00755620);
	};

	int EV_UseItemToState(oCMsgManipulate*)
	{
		XCALL(0x007558F0);
	};

	void CallScript(zSTRING const&)
	{
		XCALL(0x007561D0);
	};

	void CallScript(int)
	{
		XCALL(0x00756200);
	};

	int EV_CallScript(oCMsgManipulate*)
	{
		XCALL(0x00756220);
	};

	int EV_Unconscious(oCMsgState*)
	{
		XCALL(0x00756390);
	};

	int EV_DoState(oCMsgState*)
	{
		XCALL(0x00756600);
	};

	int EV_Wait(oCMsgState*)
	{
		XCALL(0x00756820);
	};

	int ApplyTimedOverlayMds(zSTRING const&,float)
	{
		XCALL(0x00756890);
	};

	int EV_OutputSVM_Overlay(oCMsgConversation*)
	{
		XCALL(0x00756A60);
	};

	int EV_OutputSVM(oCMsgConversation*)
	{
		XCALL(0x007571F0);
	};

	int EV_Output(oCMsgConversation*)
	{
		XCALL(0x007576F0);
	};

	int EV_PlayAni(oCMsgConversation*)
	{
		XCALL(0x00757AB0);
	};

	int EV_PlayAniFace(oCMsgConversation*)
	{
		XCALL(0x00757CE0);
	};

	int StartDialogAni(void)
	{
		XCALL(0x00757DE0);
	};

	int EV_PlayAniSound(oCMsgConversation*)
	{
		XCALL(0x00758050);
	};

	int ActivateDialogCam(float)
	{
		XCALL(0x00758130);
	};

	int DeactivateDialogCam(void)
	{
		XCALL(0x00758360);
	};

	int EV_PlaySound(oCMsgConversation*)
	{
		XCALL(0x007584F0);
	};

	int EV_SndPlay(oCMsgConversation*)
	{
		XCALL(0x007590A0);
	};

	int EV_PrintScreen(oCMsgConversation*)
	{
		XCALL(0x00759270);
	};

	void AddEffect(zSTRING const&,zCVob const*)
	{
		XCALL(0x00759530);
	};

	void RemoveEffect(zSTRING const&)
	{
		XCALL(0x007597D0);
	};

	int EV_StartFX(oCMsgConversation*)
	{
		XCALL(0x007598F0);
	};

	int EV_StopFX(oCMsgConversation*)
	{
		XCALL(0x00759910);
	};

	int EV_LookAt(oCMsgConversation*)
	{
		XCALL(0x00759A40);
	};

	int EV_StopLookAt(oCMsgConversation*)
	{
		XCALL(0x00759E80);
	};

	int EV_PointAt(oCMsgConversation*)
	{
		XCALL(0x00759F40);
	};

	int EV_StopPointAt(oCMsgConversation*)
	{
		XCALL(0x0075A0E0);
	};

	int EV_QuickLook(oCMsgConversation*)
	{
		XCALL(0x0075A130);
	};

	int EV_Cutscene(oCMsgConversation*)
	{
		XCALL(0x0075A3C0);
	};

	int EV_WaitTillEnd(oCMsgConversation*)
	{
		XCALL(0x0075A5B0);
	};

	int EV_StopProcessInfos(oCMsgConversation*)
	{
		XCALL(0x0075A660);
	};

	int EV_ProcessInfos(oCMsgConversation*)
	{
		XCALL(0x0075A680);
	};

	int AssessPlayer_S(oCNpc*)
	{
		XCALL(0x0075A740);
	};

	int AssessEnemy_S(oCNpc*)
	{
		XCALL(0x0075A940);
	};

	int AssessFighter_S(oCNpc*)
	{
		XCALL(0x0075AB40);
	};

	int AssessBody_S(oCNpc*)
	{
		XCALL(0x0075AD40);
	};

	int AssessItem_S(oCItem*)
	{
		XCALL(0x0075AF40);
	};

	void SetNpcsToState(int,int)
	{
		XCALL(0x0075B140);
	};

	void StopCutscenes(void)
	{
		XCALL(0x0075B210);
	};

	void CreatePassivePerception(int percType, zCVob* other=NULL, zCVob* victim=NULL)
	{
		XCALL(0x0075B270);
	};

	static void CreateSoundPerception(int,zCVob*,zVEC3 const&,zCVob*,int)
	{
		XCALL(0x0075BB70);
	};

	int AssessMurder_S(oCNpc*)
	{
		XCALL(0x0075C040);
	};

	int AssessThreat_S(oCNpc*)
	{
		XCALL(0x0075C060);
	};

	int AssessDefeat_S(oCNpc*)
	{
		XCALL(0x0075C260);
	};

	int AssessDamage_S(oCNpc*,int)
	{
		XCALL(0x0075C280);
	};

	int AssessOthersDamage_S(oCNpc*,oCNpc*,int)
	{
		XCALL(0x0075C420);
	};

	int AssessRemoveWeapon_S(oCNpc*)
	{
		XCALL(0x0075C440);
	};

	int ObserveIntruder_S(void)
	{
		XCALL(0x0075C460);
	};

	static int AssessFightSound_S(zCVob*,zVEC3 const&,zCVob*)
	{
		XCALL(0x0075C4A0);
	};

	static int AssessQuietSound_S(zCVob*,zVEC3 const&)
	{
		XCALL(0x0075C4D0);
	};

	int AssessWarn_S(oCNpc*)
	{
		XCALL(0x0075C510);
	};

	int CatchThief_S(oCNpc*)
	{
		XCALL(0x0075C530);
	};

	int AssessTheft_S(oCNpc*)
	{
		XCALL(0x0075C6D0);
	};

	int AssessCall_S(oCNpc*)
	{
		XCALL(0x0075C6F0);
	};

	int AssessTalk_S(oCNpc*)
	{
		XCALL(0x0075C890);
	};

	int AssessGivenItem_S(oCNpc*,oCItem*)
	{
		XCALL(0x0075CA30);
	};

	int AssessMagic_S(oCNpc*,int)
	{
		XCALL(0x0075CC30);
	};

	int AssessStopMagic_S(oCNpc*,int)
	{
		XCALL(0x0075CF30);
	};

	int AssessCaster_S(oCSpell*)
	{
		XCALL(0x0075D200);
	};

	int AssessFakeGuild_S(void)
	{
		XCALL(0x0075D220);
	};

	int MoveMob_S(oCMob*)
	{
		XCALL(0x0075D250);
	};

	int AssessUseMob_S(oCMobInter*)
	{
		XCALL(0x0075D300);
	};

	int MoveNpc_S(oCNpc*)
	{
		XCALL(0x0075D350);
	};

	int AssessEnterRoom_S(void)
	{
		XCALL(0x0075D4F0);
	};

	float GetDistToSound(void)
	{
		XCALL(0x0075D500);
	};

	zCVob* GetSoundSource(void)
	{
		XCALL(0x0075D5C0);
	};

	void SetSoundSource(int,zCVob*,zVEC3&)
	{
		XCALL(0x0075D5D0);
	};

	void ClearPerceptionLists(void)
	{
		XCALL(0x0075D640);
	};

	void CreateVobList(zCArray<zCVob*>&,float)
	{
		XCALL(0x0075D730);
	};

	void ClearVobList(void)
	{
		XCALL(0x0075D7F0);
	};

	void InsertInVobList(zCVob*)
	{
		XCALL(0x0075D870);
	};

	void RemoveFromVobList(zCVob*)
	{
		XCALL(0x0075D9B0);
	};

	void CreateVobList(float)
	{
		XCALL(0x0075DA40);
	};

	void SetPerceptionTime(float)
	{
		XCALL(0x0075DBA0);
	};

	void PerceiveAll(void)
	{
		XCALL(0x0075DBE0);
	};

	void PerceptionCheck(void)
	{
		XCALL(0x0075DD30);
	};

	int PercFilterNpc(oCNpc*)
	{
		XCALL(0x0075E1D0);
	};

	int PercFilterItem(oCItem*)
	{
		XCALL(0x0075E1E0);
	};

	void ClearPerception(void)
	{
		XCALL(0x0075E200);
	};

	void EnablePerception(int,int)
	{
		XCALL(0x0075E220);
	};

	void DisablePerception(int)
	{
		XCALL(0x0075E360);
	};

	int HasPerception(int)
	{
		XCALL(0x0075E3C0);
	};

	int GetPerceptionFunc(int)
	{
		XCALL(0x0075E400);
	};

	static void SetPerceptionRange(int,float)
	{
		XCALL(0x0075E440);
	};

	static int IsInPerceptionRange(int,float)
	{
		XCALL(0x0075E460);
	};

	static int IsInPerceptionRange(int,zCVob*,zCVob*)
	{
		XCALL(0x0075E490);
	};

	static void InitStatics(void)
	{
		XCALL(0x0075E4D0);
	};

	static void ReleaseStatics(void)
	{
		XCALL(0x0075E8B0);
	};

	static void InitBodyStates(void)
	{
		XCALL(0x0075E8C0);
	};

	void SetBodyState(int)
	{
		XCALL(0x0075E920);
	};

	int GetBodyState(void)
	{
		XCALL(0x0075EAE0);
	};

	int GetFullBodyState(void)
	{
		XCALL(0x0075EAF0);
	};

	zSTRING GetBodyStateName(void)
	{
		XCALL(0x0075EB10);
	};

	int HasBodyStateModifier(int)
	{
		XCALL(0x0075EBF0);
	};

	void SetBodyStateModifier(int)
	{
		XCALL(0x0075EC10);
	};

	void ClrBodyStateModifier(int)
	{
		XCALL(0x0075EC40);
	};

	zSTRING GetBodyStateModifierNames(void)
	{
		XCALL(0x0075EC70);
	};

	int ModifyBodyState(int,int)
	{
		XCALL(0x0075EF50);
	};

	int IsBodyStateInterruptable(void)
	{
		XCALL(0x0075EFA0);
	};

	int HasBodyStateFreeHands(void)
	{
		XCALL(0x0075EFD0);
	};

	int IsInGlobalCutscene(void)
	{
		XCALL(0x0075F000);
	};

	void MakeSpellBook(void)
	{
		XCALL(0x0075F040);
	};

	void DestroySpellBook(void)
	{
		XCALL(0x0075F0C0);
	};

	float GetDamageMultiplier(void)
	{
		XCALL(0x0075F2F0);
	};

	void SetDamageMultiplier(float)
	{
		XCALL(0x0075F300);
	};

	static void SetNpcAIDisabled(int)
	{
		XCALL(0x0075F310);
	};

	static void ProcessAITimer(void)
	{
		XCALL(0x0075F360);
	};

	static int IsScriptStateAIEnabled(void)
	{
		XCALL(0x0075F3E0);
	};

	static int IsMessageAIEnabled(void)
	{
		XCALL(0x0075F430);
	};

	void SetShowNews(int)
	{
		XCALL(0x0075F480);
	};

	void UseStandAI(void)
	{
		XCALL(0x0075F4D0);
	};

	void SetItemEffectControledByModel(oCItem*,zCModelNodeInst*,int,int,int)
	{
		XCALL(0x0075F560);
	};

	int IsVictimAwareOfTheft(void)
	{
		XCALL(0x00761EF0);
	};

	void CheckSpecialSituations(void)
	{
		XCALL(0x00761F80);
	};

	void StopTheft(oCNpc*,int)
	{
		XCALL(0x00762160);
	};

	void OpenInventory(int)
	{
		XCALL(0x00762250);
	};

	void CloseInventory(void)
	{
		XCALL(0x00762410);
	};

	int OpenSteal(void)
	{
		XCALL(0x00762430);
	};

	void CloseSteal(void)
	{
		XCALL(0x00762950);
	};

	void OpenDeadNpc(void)
	{
		XCALL(0x00762970);
	};

	void CloseDeadNpc(void)
	{
		XCALL(0x00762B40);
	};


	oCItem* GetReadyRangeWeapon()
	{
		zSTRING s1	 = "ZS_RIGHTHAND";
		zSTRING s2	 = "ZS_LEFTHAND";

		oCItem* pTmp = GetSlotItem(s1);
		if(pTmp)
			if(pTmp->HasFlag(ITM_FLAG_CROSSBOW))
				return pTmp;

		pTmp = GetSlotItem(s2);
		if(pTmp)
			if(pTmp->HasFlag(ITM_FLAG_BOW))
				return pTmp;

		pTmp = GetEquippedRangedWeapon();
		if(pTmp)
			return pTmp;

		return NULL;
	};

	oCItem* GetReadyMeleeWeapon()
	{
		zSTRING s[2] = {"ZS_RIGHTHAND","ZS_LEFTHAND"};

		for(int i=0; i<2; i++)
		{
			oCItem* pTmp = GetSlotItem(s[i]);
			if(pTmp)
				if(pTmp->HasFlag(ITM_FLAG_SWD) || pTmp->HasFlag(ITM_FLAG_AXE) || pTmp->HasFlag(ITM_FLAG_2HD_SWD) || pTmp->HasFlag(ITM_FLAG_2HD_AXE))
					return pTmp;
		}

		oCItem* pTmp = GetEquippedMeleeWeapon();
		if(pTmp)
			return pTmp;

		return NULL;
	};

	BOOL IsEquiped(oCItem* pItem)
	{
		zCArray<TNpcSlot*> arr = invSlot;
			for(int i = 0; i < arr.GetNum(); i ++)
				if( arr[i]->Vob() == pItem )
					return 1;

			return 0;
	};

	zCArray<oCItem*> GetAllMeleeWeapons()
	{
		zCArray<oCItem*> arrMelee;
		zCArray<TNpcSlot*> arr = invSlot;
		for(int i = 0; i < arr.GetNum(); i ++)
		{
			oCItem* pItem = dynamic_cast<oCItem*>(arr[i]->Vob());
			if(pItem)
				if(pItem->HasFlag(ITM_FLAG_AXE) || pItem->HasFlag(ITM_FLAG_SWD) || pItem->HasFlag(ITM_FLAG_2HD_AXE) || pItem->HasFlag(ITM_FLAG_2HD_SWD))
					arrMelee.Insert(pItem);
		}
		return arrMelee;
	};
	// [AST]
	void CollectFocusVob_AST ( zBOOL a_bForce );
	BOOL AccessObjectForFocus( zCVob* );
	int EV_AttackRun_AST(oCMsgAttack*);
	void SetInteractItem_AST(oCItem*);
	void DropAllInHand_AST();
	int EV_AttackBow_AST(oCMsgAttack*);
	int FightAttackBow_AST();
	int EV_TakeVob_AST(oCMsgManipulate*);
	void OnDamage_Hit_AST(oSDamageDescriptor&);
	BOOL IsVictimAwareOfTheft_AST(BOOL&);
	void SetWeaponMode_AST(int);
	void Unarchive_AST(zCArchiver&);
	void Archive_AST(zCArchiver&);
	void InitByScript_ast(int,int);
	void Unarchive_ast(zCArchiver&);
	void Archive_ast(zCArchiver&);
	int oCNpc_ast();
	// [/AST]

};



class aCNpc : public oCNpc
{
public:
	
	int							m_nID;
	zSTRING						m_sNameNpc;
	zSTRING						m_sSlot;
	zSTRING						m_sEffect;
	int							m_NpcType;
	DWORD						m_dwFlags;
	int							m_nAttribute[8];
	int							m_nHitChance[5];
	int							m_nProtection[8];
	int							m_nDamages[8];
	int							m_nDamageTypes;
	int							m_nGuild;
	int							m_nLevel;
	int							m_nFightTactic;
	int							m_nFightMode;
	int							m_nVoice;
	int							m_nVoicePitch;
	int							m_nBodymass;
	int							m_pfnDailyRoutine;
	int							m_pfnStartAiState;
	zSTRING						m_sRespawnPoint;
	int							m_nRespawnTime;
	int							m_nSenses;
	int							m_nSensesRange;
	int							m_nAivar[1000];
	zSTRING						m_sWp;
	int							m_nExpPoints;
	int							m_nExpNext;	
	int							m_nLearnPoints;
	int							bodyStateInterruptableOverride;
	int							m_bNoFocus; 
public:
	static zCClassDef classDef;

	virtual zCClassDef* _GetClassDef()const {return &classDef;};
	virtual void Archive(zCArchiver& ar);
	virtual void Unarchive(zCArchiver& ar);
	virtual ~aCNpc(){};
	void InitByScript_ast(int,int);
	void Reset();
	static void* operator new(size_t nSize) 
	{										
		void* p = ::operator new(nSize);	
		zCClassDef::ObjectCreated(			
			(aCNpc*)p, &classDef);		
		return p;							
	}
	static void operator delete(void* p)	
	{										
		zCClassDef::ObjectDeleted(			
			(aCNpc*)p, &classDef);			
		::operator delete(p);				
	}	
};