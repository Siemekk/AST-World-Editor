#pragma once

#include "ocitem.h"
class oCNpc;
class oCItem;

//	INVENTORY CATEGORIES
#define	zINV_USER		0
#define zINV_WEAPON		1
#define zINV_ARMOR		2
#define zINV_RUNE		3
#define zINV_MAGIC		4
#define zINV_FOOD		5
#define zINV_POTION		6
#define zINV_DOC		7
#define zINV_MISC		8
#define zINV_CAT_MAX	9

class oCStealContainer : public oCItemContainer
{
public:
	oCNpc*				owner;
	virtual	~oCStealContainer			(){XCALL(0x0070AC30)};
	// Methods
	virtual zBOOL	HandleEvent			(int key){XCALL(0x0070B090)};
	// New
	virtual void	SetOwner			(oCNpc* npc){XCALL(0x0070ADB0)};
	virtual oCNpc*	GetOwner			(){XCALL(0x0070ADD0)};
	virtual void	CreateList			(){XCALL(0x0070ADE0)};
	float CalcChanceOfStealItem(oCItem* pItem);
	void oStealConstainer()
	{
		XCALL(0x0070ABF0);
	};

	oCStealContainer(void)
	{
		oStealConstainer();
	};
};




class oCNpcContainer : public oCStealContainer
{
public:
	void oNpcContainer()
	{
		XCALL(0x0070B3C0);
	}

	oCNpcContainer()
	{
		oNpcContainer();
	};
	virtual			~oCNpcContainer		(){XCALL(0x0070B400)};
	// Methods
	virtual zBOOL	HandleEvent			(int key){XCALL(0x0070B6F0)};
	// New
	virtual void	CreateList			(){XCALL(0x0070B570)};
	virtual oCItem*	Insert				(oCItem* item){XCALL(0x0070B9F0)};
	virtual void	Remove				(oCItem* item){XCALL(0x0070BA30)};
	//virtual BOOL FilterItem(oCItem* pItem);
};

class oCNpcInventory : public oCItemContainer
{
public:
	oCNpc*				owner;
	zBOOL				packAbility;			// Item pack/unpack mechanism on/off
	zCListSort<oCItem>	inventory;	
	zSTRING				packString;
	int					maxSlots;
public:
	virtual ~oCNpcInventory						(){XCALL(0x0070BC00)};
												
	void			Open						(int x, int y, int mode){XCALL(0x0070BF10)};
	void			Close						(){XCALL(0x0070C2F0)};
												
	// **** Insert / Remove						
	virtual oCItem*	Insert						(oCItem* item){XCALL(0x0070C730)};
	virtual void	Remove						(oCItem* item){XCALL(0x0070CBE0)};											
	virtual oCItem*	IsIn						(oCItem* item,			int anz = 1){XCALL(0x0070CA80)};
	virtual oCItem*	IsIn						(int instance,			int anz = 1){XCALL(0x0070CAF0)};
	virtual oCItem*	IsIn						(const zSTRING& name,	int anz = 1){XCALL(0x0070CAC0)};
	virtual oCItem*	Remove						(oCItem* item,			int anz){XCALL(0x0070CE20)};
	virtual oCItem*	RemoveByPtr					(oCItem* item,			int anz){XCALL(0x0070CC70)};
	virtual oCItem*	Remove						(int instance,			int anz = 1){XCALL(0x0070D080)};
	virtual oCItem*	Remove						(const zSTRING& name,	int anz = 1){XCALL(0x0070D170)};
												
												
	// [BENDLIN] Addon Patch - Added IgnoreActive
	virtual zBOOL	IsEmpty						(zBOOL bIgnoreArmor = FALSE, zBOOL bIgnoreActive = FALSE){XCALL(0x0070D1A0)};
												
	// **** Control								
	virtual zBOOL	HandleEvent					(int key){XCALL(0x0070E040)};
	// **** Specials

	// **** Archive
	void			Archive					(zCArchiver &arc){XCALL(0x0070D210)};
	void			Unarchive				(zCArchiver &arc){XCALL(0x0070D550)};

	virtual void	Draw					(){XCALL(0x0070C310)};
	virtual void	DrawCategory			(){XCALL(0x0070DBD0)};

	void oNpcInventory(void)
	{
		XCALL(0x0070BAF0);
	};

	oCNpcInventory(void)
	{
		oNpcInventory();
	};

	void ClearInventory(void)
	{
		XCALL(0x0070BDB0);
	};

	void SetOwner(oCNpc*)
	{
		XCALL(0x0070C320);
	};

	oCNpc* GetOwner(void)
	{
		XCALL(0x0070C330);
	};

	int GetNumItemsInCategory(void)
	{
		XCALL(0x0070C340);
	};

	oCItem* GetItem(int)
	{
		XCALL(0x0070C450);
	};

	int GetCategory(oCItem*)
	{
		XCALL(0x0070C690);
	};

	int GetAmount(int)
	{
		XCALL(0x0070C970);
	};

	int HandleTrade(int)
	{
		XCALL(0x0070DE00);
	};

	void CheckForEquippedItems(int)
	{
		XCALL(0x0070F390);
	};

	int CanCarry(oCItem*)
	{
		XCALL(0x0070F4D0);
	};

	void SetPackAbility(int)
	{
		XCALL(0x0070F600);
	};

	void UnpackCategory(void)
	{
		XCALL(0x0070F620);
	};

	int GetNumItemsInPackString(void)
	{
		XCALL(0x0070F630);
	};

	int GetPackedItemBySlot(int,zSTRING&)
	{
		XCALL(0x0070F720);
	};

	oCItem* CreateFromPackString(zSTRING const&)
	{
		XCALL(0x0070F860);
	};

	int GetPackedItemInfo(zSTRING const&,int,int&,int&)
	{
		XCALL(0x0070F8F0);
	};

	int PackSingleItem(oCItem*)
	{
		XCALL(0x0070FCB0);
	};

	void PackAllItems(int)
	{
		XCALL(0x00710020);
	};

	void UnpackAllItems(void)
	{
		XCALL(0x00710030);
	};

	void PackItemsInCategory(int)
	{
		XCALL(0x00710040);
	};

	void UnpackItemsInCategory(void)
	{
		XCALL(0x00710A20);
	};
};
