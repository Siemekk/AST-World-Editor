#pragma once

#include "ocvob.h"
#include "zcinputcallback.h"

class oCNpc;
class zCView;
class zCViewBase;
class zCWorld;
class oCVisualFX;
class oCMobContainer;


enum oEIndexDamage;
enum oETypeDamage;


// Kategorien (mainflag)
const int ITM_CAT_NONE			= 1<<0;		// Sonstiges
const int ITM_CAT_NF			= 1<<1;		// Alle Nahkampfwaffen
const int ITM_CAT_FF			= 1<<2;		// Alle Fernkampfwaffen
const int ITM_CAT_MUN			= 1<<3;		// Jede Art von Munition
const int ITM_CAT_ARMOR			= 1<<4;		// Rüstungen und Schilde
const int ITM_CAT_FOOD			= 1<<5;		// Alle Nahrungsmittel
const int ITM_CAT_DOCS			= 1<<6;		// Alle Dokumente
const int ITM_CAT_POTION		= 1<<7;		// Alle Schlüssel
const int ITM_CAT_LIGHT			= 1<<8;		// Alle Lichtquellen
const int ITM_CAT_RUNE			= 1<<9;
const int ITM_CAT_MAGIC			= 1<<31;
// Waffen (flag)
const int ITM_FLAG_DAG			= 1<<13;	// Waffe wird wie ein Dolch behandelt
const int ITM_FLAG_SWD			= 1<<14;	// Waffe wird wie ein Schwert behandelt
const int ITM_FLAG_AXE			= 1<<15;	// Waffe wird wie eine Axt behandelt
const int ITM_FLAG_2HD_SWD		= 1<<16;	// Waffe wird wie ein Zweihänder behandelt
const int ITM_FLAG_2HD_AXE		= 1<<17;	// Waffe wird wie eine Streitaxt behandelt
const int ITM_FLAG_SHIELD		= 1<<18;	// Waffe wird wie ein Schild behandelt
const int ITM_FLAG_BOW			= 1<<19;	// Waffe wird wie ein Bogen behandelt
const int ITM_FLAG_CROSSBOW		= 1<<20;	// Waffe wird wie eine Armbrust behandelt
// Magie (flag)
const int ITM_FLAG_RING			= 1<<11;	// Ring
const int ITM_FLAG_AMULET		= 1<<22;	// Amulett
const int ITM_FLAG_BELT			= 1<<24;	// Guertel
// Flags (flag)
const int ITM_FLAG_DROPPED		= 1<<10;	// (intern) Dropped
const int ITM_FLAG_MI			= 1<<12;	// Missionsgegenstand	
const int ITM_FLAG_MULTI		= 1<<21;	// Multi-Item-Slot
const int ITM_FLAG_NFOCUS		= 1<<23;	// (intern) Item im Focus ignorieren ?
const int ITM_FLAG_CREATEAMMO	= 1<<25;	// Waffe erzeugt benötigte Ammo selbst (magisch)
const int ITM_FLAG_NSPLIT		= 1<<26;	// SplitSlot deaktiviert (Waffe als Interact-Item)
const int ITM_FLAG_DRINK		= 1<<27;	// ein Trank
const int ITM_FLAG_TORCH		= 1<<28;	// Wie eine fackel behandeln
const int ITM_FLAG_THROW		= 1<<29;	// Kann Gegenstand geworfen werden ?
const int ITM_FLAG_ACTIVE		= 1<<30;	// Item in Inventory aktiviert


//	ARMOR FLAGS
// Koerperstellen, wo Gegenstaende getragen werden koennen
enum {	ITM_WEAR_NO				= 0			};		// Kann nicht getragen werden
enum {	ITM_WEAR_TORSO			= 1			};		// Oberkoerper
enum {	ITM_WEAR_HEAD			= 2			};		// Kopf
enum {	ITM_WEAR_LIGHT			= 8			};		// Sonderslot Lichtquelle = 8  = NPC_SLOT_LIGHT

// Amount of States (Item-Interaction) that are possible
enum {	ITM_STATE_MAX			= 4			};

enum {	ITM_TEXT_MAX			= 6			};


#define zDAM_INVALID	0x00
#define zDAM_BARRIER	0x01
#define zDAM_BLUNT		0x02
#define zDAM_EDGE		0x04
#define zDAM_FIRE		0x08
#define zDAM_FLY		0x10
#define zDAM_MAGIC		0x20
#define zDAM_POINT		0x40
#define zDAM_FALL		0x80

class oCItemContainer;

const int ITM_COND_MAX		= 3;


template <class T> class zCListSortG2;

class oCItem : public oCVob
{
public:
	//zCLASS(oCItem);
// PARSER ON
	struct { 
		//
		//	Für alle Items
		//
		int				idx;									//	Eindeutige ID
		zSTRING			name,nameID;							//	Name des Items		
		int				hitp,max_hitp;							//	Strukturpunkte
		int				mainflag,flags;								
		//int				weight;									//	Gewicht
		oCItemContainer*m_pChest;
		int				value;									//	Wert des Items		
																	
		//															
		//	Für Waffen												
		//															
		int				damageTypes;							//	What Types of Damage
		int				damageTotal;							//	How much Damage alltogether		| these two are mutual exclusive
		int				damage			[8];	//	How much Damage for each Type	| these two are mutual exclusive
																	
		//															
		//	Für Rüstungen											
		//															
		int				wear;									//	Gegenstand kann wo getragen werden ?
		int				protection		[8];	//	
																	
		//															
		//	Für Nahrung												
		//															
		int				nutrition;								//	Heilwert der Nahrung
																	
		//															
		//	Bedingungen, damit Item benutzt werden kann				
		//															
		int				cond_atr		[ ITM_COND_MAX ];		//			
		int				cond_value		[ ITM_COND_MAX ];		//	
																	
		//															
		//	Veränderungen der Attribute, wenn Item benutzt wird		
		//															
		int				change_atr		[ ITM_COND_MAX ];		//	
		int				change_value	[ ITM_COND_MAX ];		//	
																	
		//															
		//	Parserfunktionen											
		//															
		int				magic;									//	Funktion zum "Magie-Header"
		int				on_equip;								//	
		int				on_unequip;								//	
		int				onState			[ ITM_STATE_MAX ];		//	StateEffect !
		int				owner;									//	Skriptinstanz
		int				ownerGuild;								//	gesamte Gilde
		int				disguiseGuild;							//	Zur Schau getragene Gilde durch Verkleidung
		zSTRING			file;									//	Die Grafikdatei
		zSTRING			visual_change;							//	
		zSTRING			effectName;
		int				visual_skin;							//	
		zSTRING			scemeName;								//	
		oTSndMaterial	sndMat;									//	
		int				munition;								//	MunitionInstance
																	
		//															
		//	Magie													
		//															
		int				spell;									//	type of spell
		int				range;									//	range of weapon
		int				mag_circle;								//	magic circle

		//
		//	Beschreibung
		//
		zSTRING			description		;
		zSTRING			text			[ ITM_TEXT_MAX ];
		int				count			[ ITM_TEXT_MAX ];

		// positionierung & orientierung im inventory
		int				inv_zbias;
		int				inv_rotx;
		int				inv_roty;
		int				inv_rotz;
		int				inv_animate;
	};															
	// PARSER OFF	


	int					amount;									//
	int					instanz;								
	int					c_manipulation;							//
	float				last_manipulation;						
	int					magic_value;							//								
	oCVisualFX*			effectVob;																	
	// Vars														
	oCItem*				next;									// next in list
	static zCClassDef*	classDef;
public:
	// [AST]
	void Archive_AST(zCArchiver&);
	void Unarchive_AST(zCArchiver&);
	void SetVisual_AST(zSTRING);
	// [/AST]
	virtual zCClassDef* _GetClassDef(void)const		{XCALL(0x00711410)};
	virtual void			SetVisual				(zCVisual* v){XCALL(0x00711910)};
	void					Init					(){XCALL(0x00711970)};	
	int						GetInstance				()																		{ return instanz; };
	zSTRING					GetInstanceName			(){XCALL(0x00713D30)};	
	virtual zBOOL			GetScriptInstance		(zSTRING* &scriptInstanceName, int &scriptInstanceIndex){XCALL(0x00713CC0)};				// returns name/index, as available
	virtual zBOOL			SetByScriptInstance		(const zSTRING* scriptInstanceName, const int scriptInstanceIndex){XCALL(0x00713CF0)};		// use 'name' or 'index' exclusively, but not both
	// zCVob interface
	virtual zBOOL __fastcall  Render				(zTRenderContext &renderContext){XCALL(0x00714020)};		// TRUE=visible, FALSE=invisible	[HILDEBRANDT]
	zBOOL					IsOwnedByNpc			(int instance){XCALL(0x007127A0)};															
	zBOOL					IsOwnedByGuild			(int guild){XCALL(0x007127C0)};
	zSTRING					GetSchemeName			()																		{ return scemeName; };
	int						GetAmount				()																		{ return amount; };
	void					SetAmount				(int am)																{ amount = am; };
	void					ChangeAmount			(int delta)																{ amount += delta; };																																																											
	virtual	oCAIVobMove*	GetAIVobMove			(){XCALL(0x00713F40)};																																																
	// Sound																												
	virtual oTSndMaterial	GetSoundMaterial		()																		{ return sndMat; };
	virtual void			GetSoundMaterial_AM		(/*zCSoundManager::zTSndManMedium*/int &med2, oTSndMaterial &mat2, int damage){XCALL(0x00712850)};
	// Archive / Unarchive							
	virtual void			Archive					(zCArchiver &arc){XCALL(0x00713D70)};
	virtual void			Unarchive				(zCArchiver &arc){XCALL(0x00713EB0)};
protected:
	virtual void			ThisVobAddedToWorld		(zCWorld *homeWorld){XCALL(0x00712DF0)};													// called AFTER the actual addition
	virtual void			ThisVobRemovedFromWorld	(zCWorld *homeWorld){XCALL(0x00712EA0)};													// called BEFFORE the actual removal
	virtual					~oCItem					(){XCALL(0x00711730)};
public:
	static void SetLightingSwell(int)
	{
		XCALL(0x00711270);
	};

	static int GetLightingSwell(void)
	{
		XCALL(0x00711280);
	};

	void oItem(void)
	{
		XCALL(0x00711290);
	};

	oCItem(void)
	{
		oItem();
	};

	void oItem(zSTRING&,int)
	{
		XCALL(0x00711470);
	};

	oCItem(zSTRING& instName,int nAmount)
	{
		oItem(instName,nAmount);
	};

	void oItem(int,int)
	{
		XCALL(0x007115D0);
	};

	oCItem(int inst,int nAmount)
	{
		oItem(inst,nAmount);
	};

	void CreateVisual(void)
	{
		XCALL(0x00711930);
	};

	void InitByScript(int,int)
	{
		XCALL(0x00711BD0);
	};

	zSTRING& GetDescription(void)
	{
		XCALL(0x007120E0);
	};

	zSTRING& GetText(int)
	{
		XCALL(0x007120F0);
	};

	int GetCount(int)
	{
		XCALL(0x00712160);
	};

	int GetHealMode(int&)
	{
		XCALL(0x00712180);
	};

	int GetProtectionByIndex(oEIndexDamage)
	{
		XCALL(0x00712200);
	};

	int GetProtectionByType(oETypeDamage)
	{
		XCALL(0x00712210);
	};

	int GetProtectionByMode(unsigned long)
	{
		XCALL(0x007122B0);
	};

	int GetFullProtection(void)
	{
		XCALL(0x00712340);
	};

	void CopyDamage(oCItem*)
	{
		XCALL(0x00712360);
	};

	int GetDamageByIndex(oEIndexDamage)
	{
		XCALL(0x007123A0);
	};

	int GetDamageByType(oETypeDamage)
	{
		XCALL(0x007123B0);
	};

	int GetDamageByMode(unsigned long)
	{
		XCALL(0x00712450);
	};

	void GetDamages(unsigned long*)
	{
		XCALL(0x007124E0);
	};

	int GetFullDamage(void)
	{
		XCALL(0x00712500);
	};

	unsigned long GetDamageTypes(void)
	{
		XCALL(0x00712520);
	};

	int HasDamageType(oETypeDamage)
	{
		XCALL(0x00712530);
	};

	int IsDeadly(void)
	{
		XCALL(0x00712550);
	};

	int IsOneHandWeapon(void)
	{
		XCALL(0x00712570);
	};

	int MultiSlot(void)
	{
		XCALL(0x007125A0);
	};

	int SplitSlot(void)
	{
		XCALL(0x00712610);
	};

	int GetValue(void)
	{
		XCALL(0x00712650);
	};

	int GetWeight(void)
	{
		XCALL(0x007126B0);
	};

	int HasFlag(int)
	{
		XCALL(0x007126D0);
	};

	void ClearFlag(int)
	{
		XCALL(0x007126F0);
	};

	void SetFlag(int)
	{
		XCALL(0x00712710);
	};

	int TwoHanded(void)
	{
		XCALL(0x00712730);
	};

	int IsOwned(int,int)
	{
		XCALL(0x00712760);
	};

	int GetDisguiseGuild(void)
	{
		XCALL(0x007127E0);
	};

	int AddManipulation(void)
	{
		XCALL(0x007127F0);
	};

	void Identify(void)
	{
		XCALL(0x00712870);
	};

	zSTRING GetName(int)
	{
		XCALL(0x00712880);
	};

	zSTRING GetStatus(void)
	{
		XCALL(0x007128D0);
	};

	void UseItem(void)
	{
		XCALL(0x00712A30);
	};

	zSTRING GetVisualChange(void)
	{
		XCALL(0x00712A40);
	};

	zSTRING GetEffectName(void)
	{
		XCALL(0x00712B30);
	};

	int GetStateEffectFunc(int)
	{
		XCALL(0x00712B80);
	};

	oCItem* SplitItem(int)
	{
		XCALL(0x00712BA0);
	};

	void RemoveEffect(void)
	{
		XCALL(0x00712C00);
	};

	void InsertEffect(void)
	{
		XCALL(0x00712C40);
	};

	void RotateForInventory(int)
	{
		XCALL(0x00712F10);
	};

	void RotateInInventory(void)
	{
		XCALL(0x007132E0);
	};

	void RenderItem(int,int)
	{
		XCALL(0x007133C0);
	};

	void RenderItemPlaceCamera(zCCamera*,float)
	{
		XCALL(0x00713800);
	};

	void RenderItem(zCWorld*,zCViewBase*,float)
	{
		XCALL(0x00713AC0);
	};

	BOOL IsMeleeWeapon()
	{
		return ( HasFlag(ITM_FLAG_2HD_AXE) || HasFlag(ITM_FLAG_2HD_SWD) || HasFlag(ITM_FLAG_AXE) || HasFlag(ITM_FLAG_SWD) );
	}

	BOOL IsRangedWeapon()
	{
		return ( HasFlag(ITM_FLAG_BOW) || HasFlag(ITM_FLAG_CROSSBOW) );
	}
};


enum
{
	INV_NONE	= 0,
	INV_COMBAT	= 1,
	INV_ARMOR	= 2,	
	INV_RUNE	= 3,
	INV_MAGIC	= 4,
	INV_FOOD	= 5,
	INV_POTION	= 6,
	INV_DOCS	= 7,
	INV_OTHER	= 8,
	INV_MAX		= 9
};

enum
{
	INV_MODE_DEFAULT	= 0,
	INV_MODE_CONTAINER	= 1,
	INV_MODE_PLUNDER	= 2,
	INV_MODE_STEAL		= 3,
	INV_MODE_BUY		= 4,
	INV_MODE_SELL		= 5,
	INV_MODE_MAX		= 6
};

class oCItemContainer : public zCInputCallback
{
public:
	// Vars
	zCListSort<oCItem>*			contents;		// List of all Items in Container
	oCNpc*						npc;			// Owner
	zSTRING						titleText;		// inventory's name (display)
	int							invMode;		// inventory mode	
	int							selectedItem;	// Current selected Item
	int							offset;			// Current offset in List
	int							maxSlotsCol;	// Maximal Items to be drawn
	int							maxSlotsColScr;	// Maximal Items drawable on screen
	int							maxSlotsRow;	// Maximal Items to be drawn
	int							maxSlotsRowScr;	// Maximal Items drawable on screen
	int							maxSlots;		// Maximal Items to be drawn
	int							marginTop;		// Space on top (screen)
	int							marginLeft;		// Space on left/right (screen)
	BOOL						frame;			// Highlight Selected Item
	BOOL						right;			// Left or Right ?
	BOOL						ownList;		// is it own list ?
	BOOL						prepared;		// Item is prepared for drawing ?
	BOOL						passive;		// passive = only used for display purposes
	signed   short int			TransferCount;	// Number of Items currently transfered within one action
	// Views	
	zCView*						viewTitle;						// title
	zCView*						viewBack;						// slots
	zCView*						viewItem;						// items
	zCView*						viewItemActive;					// items - equipped
	zCView*						viewItemHightlighted;			// items - selected
	zCView*						viewItemActiveHighlighted;		// items - equipped + selected
	zCView*						viewItemInfo;					// infos
	zCView*						viewItemInfoItem;				// infos - item
	zCView*						textView;
	zCView*						viewArrowAtTop;
	zCView*						viewArrowAtBottom;
	zCWorld*					rndWorld;
	int							posx, posy;	
	BOOL						m_bManipulateItemsDisabled;
	BOOL						m_bCanTransferMoreThanOneItem;
public:
	virtual ~oCItemContainer								(){XCALL(0x007062E0)};												
	virtual void				Open						(int x, int y, int mode){XCALL(0x00708550)};
	virtual void				OpenPassive					(int x, int y, int mode){XCALL(0x007086D0)};
	virtual zSTRING				GetName						()				{ return titleText; };
	virtual void				SetName						(zSTRING& name)	{ if (!name.IsEmpty()) titleText = name; return; };
	virtual int					GetMode						()			{ return invMode; };
	virtual void				SetMode						(int mode)	{ if ((mode>=INV_MODE_DEFAULT)&&(mode<INV_MODE_MAX)) invMode = mode; return; };
	virtual void				Close						(){XCALL(0x00708F30)};
	virtual void				Activate					(){XCALL(0x00709230)};
	virtual void				Deactivate					(){XCALL(0x00709290)};
	virtual zBOOL				IsOpen						(){XCALL(0x00709200)};
	virtual zBOOL				IsActive					()	{ return frame;  };
	virtual zBOOL				IsEmpty						(){XCALL(0x00709E10)};
	virtual zBOOL				IsSplitScreen				(){XCALL(0x00709E40)};													
	virtual void				SetContents					(zCListSort<oCItem> *list){XCALL(0x007084F0)};
	virtual zCListSort<oCItem>*	GetContents					(){XCALL(0x00708540)};														
	virtual oCItem*				Insert						(oCItem* item){XCALL(0x00709360)};
	virtual void				Remove						(oCItem* item){XCALL(0x00709430)};
	virtual oCItem*				Remove						(oCItem* item, int anz){XCALL(0x007094E0)};
	virtual oCItem*				RemoveByPtr					(oCItem* item, int anz){XCALL(0x007094D0)};														
	virtual oCItem*				GetSelectedItem				(){XCALL(0x007092C0)};
	virtual int					GetSelectedItemCount		(){XCALL(0x007092F0)};
	virtual void				GetSize						(int &x, int &y){XCALL(0x00706A70)};													
	virtual void				DisableManipulateItems		(zBOOL dis=TRUE)		{ m_bManipulateItemsDisabled = dis;	};
	virtual zBOOL				CanManipulateItems			()						{ return !m_bManipulateItemsDisabled;	};
	virtual void				DisableTransferMoreThanOneItem(zBOOL dis=TRUE)		{ m_bCanTransferMoreThanOneItem = !dis;	};
	virtual zBOOL				CanTransferMoreThanOneItem	()						{ return m_bCanTransferMoreThanOneItem;	};
	virtual zBOOL				IsPassive					(){XCALL(0x00708F20)};
	virtual zINT				GetTransferCount			()						{ return TransferCount; };
	virtual void				SetTransferCount			(const zINT cntAmount)	{ TransferCount = cntAmount; };
	virtual void				IncTransferCount			(const zINT cntAmount)	{ TransferCount += cntAmount; };														
	// Archive												
	virtual void				Archive						(zCArchiver &arc){XCALL(0x0070A270)};
	virtual void				Unarchive					(zCArchiver &arc){XCALL(0x0070A460)};


	virtual void				Init						(int x, int  y, int mode){XCALL(0x00706870)};
	virtual void				GetPosition					(int &x,int &y){XCALL(0x00706A90)};
	virtual void				LoadGrafix					(){XCALL(0x00706430)};
	virtual void				DeleteContents				(){XCALL(0x00709590)};
															
	virtual zBOOL				HandleEvent					(int key){XCALL(0x0070A640)};
															
	// Movement												
	virtual	void				NextItem					(){XCALL(0x00709740)};
	virtual	void				NextItemLine				(){XCALL(0x007099A0)};
	virtual	void				PrevItem					(){XCALL(0x00709B00)};
	virtual	void				PrevItemLine				(){XCALL(0x00709D30)};
	virtual void				CheckSelectedItem			(){XCALL(0x00709660)};
	virtual	zBOOL				TransferItem				(int dir, int maxAmount){XCALL(0x00709F40)};

	// Draw
	virtual void				Draw						(){XCALL(0x007076B0)};
	virtual void				DrawCategory				(){XCALL(0x00706B60)};
	virtual void				DrawItemInfo				( oCItem* pItem, zCWorld* pWorld ){XCALL(0x00706E40)};

	static int GetInvSplitScreen(void)
	{
		XCALL(0x007045E0);
	};

	static short GetInvMaxColumns(void)
	{
		XCALL(0x00704610);
	};

	static short GetInvMaxRows(void)
	{
		XCALL(0x00704660);
	};

	static short TransferCountToAmount(short)
	{
		XCALL(0x007046B0);
	};

	static float GetValueMultiplier(void)
	{
		XCALL(0x007046F0);
	};

	static zSTRING GetCurrencyInstanceName(void)
	{
		XCALL(0x00704810);
	};

	static int GetCurrencyInstance(void)
	{
		XCALL(0x00704A00);
	};

	static oCItem* CreateCurrencyItem(short)
	{
		XCALL(0x00704AA0);
	};

	static void RemoveCurrencyItem(oCItem*)
	{
		XCALL(0x00704B50);
	};

	static void Container_PrepareDraw(void)
	{
		XCALL(0x00704B80);
	};

	static void Container_Draw(void)
	{
		XCALL(0x00704B90);
	};

	oCItemContainer* GetNextContainerLeft(oCItemContainer*)
	{
		XCALL(0x00704BC0);
	};

	oCItemContainer* GetNextContainerRight(oCItemContainer*)
	{
		XCALL(0x00704C60);
	};

	zCListSort<oCItem>* JumpOffset(int&,int&)
	{
		XCALL(0x00706AB0);
	};

	int ActivateNextContainer(int)
	{
		XCALL(0x0070A150);
	};

	void oItemContainer(void)
	{
		XCALL(0x00704D00);
	};

	oCItemContainer(void)
	{
		oItemContainer();
	};
};