#pragma once

#include "ocnpcinventory.h"
#include "zViewObject.h"

//
//	VIEW
//
class oCViewDialogInventory : public zCViewDialog
{
public:
	zCLASS(oCViewDialogInventory);
	// *********************************************************************************
	// **							ENUMS & STRUCTURES
	// *********************************************************************************
public:
	static zCClassDef*				classDef;
	enum oEInventoryAlignment
	{
		oEInventoryAlignment_Left	,
		oEInventoryAlignment_Right	
	}
	oTInventoryAlignment, oTAlignmentInventory;
	// *********************************************************************************
	// **								ATTRIBUTES
	// *********************************************************************************
protected:
	oCNpcInventory*			Inventory			;
	oEInventoryAlignment	Alignment			;

	// *********************************************************************************
	// **								 METHODS
	// *********************************************************************************

	//
	//	GET/SET
	//
public:
	virtual zCClassDef* _GetClassDef(void)const														{XCALL(0x00689010)};
	virtual void 			__fastcall	Activate			( zBOOL bActive  )						{XCALL(0x006890B0)};
															
	void					__fastcall	SetInventory		( oCNpcInventory* pInventory		)	{XCALL(0x006890D0)};
	void					__fastcall	SetAlignment		( oEInventoryAlignment enuAlignment )	{XCALL(0x00689100)};
															
	oCNpcInventory*			__fastcall	GetInventory		( void )								{ return this->Inventory; }	
	oEInventoryAlignment	__fastcall	GetAlignment		( void )								{ return this->Alignment; }	

	oCItem*					__fastcall	GetSelectedItem		( void )								{XCALL(0x00689110)};
	int						__fastcall	GetSelectedItemCount( void )								{XCALL(0x00689130)};
	oCItem*					__fastcall	RemoveSelectedItem	( void )								{XCALL(0x00689150)};
	void					__fastcall	InsertItem			( oCItem* pItem	)						{XCALL(0x006891E0)};
																									
	//														
	//	INTERACTION											
	//														
public:														
	virtual void 			__fastcall	StartSelection		( void )								{XCALL(0x00689270)};
	virtual void 			__fastcall	StopSelection		( void )								{XCALL(0x006892D0)};

	//																							
	//	EVENTS																					
	//																							
public:																							
	virtual zBOOL			HandleEvent						( int nKey )							{XCALL(0x00689220)};		
																								
	zBOOL					__fastcall	CanHandleLeft		( void )								{XCALL(0x00689200)};
	zBOOL					__fastcall	CanHandleRight		( void )								{XCALL(0x00689210)};
															
	//
	//	CON-/DESTRUCTION
	//
public:
	void oViewDialogInventory(void){XCALL(0x00689020)};
	oCViewDialogInventory(){oViewDialogInventory();};
	virtual ~oCViewDialogInventory(){XCALL(0x00689090)};
};

typedef oCViewDialogInventory	*LPCViewDialogInventory,	*LPCVIEWDIALOGINVENTORY;


//
//	VIEW
//
class oCViewDialogStealContainer : public zCViewDialog
{
public:
	zCLASS(oCViewDialogStealContainer);
	// *********************************************************************************
	// **							ENUMS & STRUCTURES
	// *********************************************************************************
public:
	static zCClassDef*				classDef;
	enum oEStealContainerAlignment
	{
		oEStealContainerAlignment_Left	,
		oEStealContainerAlignment_Right	
	}
	oTStealContainerAlignment, oTAlignmentStealContainer;
	// *********************************************************************************
	// **								ATTRIBUTES
	// *********************************************************************************
protected:
	oCStealContainer*			StealContainer	;
	oEStealContainerAlignment	Alignment		;
	zUINT32						Value			;
	zREAL						ValueMultiplier	;

	// *********************************************************************************
	// **								 METHODS
	// *********************************************************************************

	//
	//	GET/SET
	//
public:
	virtual zCClassDef* _GetClassDef(void)const {XCALL(0x0068A2F0)};
	virtual void 				__fastcall	Activate			( zBOOL bActive  )									{XCALL(0x0068A3A0)};
																												
	void						__fastcall	SetStealContainer	( oCStealContainer*			pStealContainer		)	{XCALL(0x0068A3C0)};
	void						__fastcall	SetAlignment		( oEStealContainerAlignment	enuAlignment		)	{XCALL(0x0068A3F0)};
	void						__fastcall	SetValueMultiplier	( zREAL						fValueMultiplier	)	{ this->ValueMultiplier = fValueMultiplier	; }
																												
	oCStealContainer*			__fastcall	GetStealContainer	( void )											{ return this->StealContainer				; }	
	oEStealContainerAlignment	__fastcall	GetAlignment		( void )											{ return this->Alignment					; }	
	zUINT32						__fastcall	GetValue			( void )											{ return this->Value						; }	
	zREAL						__fastcall	GetValueMultiplier	( void )											{ return this->ValueMultiplier				; }	
																												
	oCItem*						__fastcall	GetSelectedItem		( void )											{XCALL(0x0068A400)};
	int							__fastcall	GetSelectedItemCount( void )											{XCALL(0x0068A420)};
	oCItem*						__fastcall	RemoveSelectedItem	( void )											{XCALL(0x0068A440)};
	void						__fastcall	InsertItem			( oCItem*					pItem				)	{XCALL(0x0068A500)};
	void						__fastcall	TransferAllItemsTo	( oCNpcInventory*			pInventory			)	{XCALL(0x0068A5B0)};
																												
protected:																										
	void						__fastcall	RemoveItem			( oCItem*					pItem				)	{XCALL(0x0068A550)};
	void						__fastcall UpdateValue			( void )											{XCALL(0x0068A6B0)};
																												
	//																											
	//	INTERACTION																								
	//																											
public:																											
	virtual void 				__fastcall	StartSelection		( void )											{XCALL(0x0068A7C0)};
	virtual void 				__fastcall	StopSelection		( void )											{XCALL(0x0068A820)};
																													
	//																												
	//	EVENTS																										
	//																												
public:																												
	virtual zBOOL				HandleEvent						( int nKey )										{XCALL(0x0068A770)};		
																													
	zBOOL						__fastcall	CanHandleLeft		( void )											{XCALL(0x0068A750)};
	zBOOL						__fastcall	CanHandleRight		( void )											{XCALL(0x0068A760)};
																												
	//
	//	CON-/DESTRUCTION
	//
public:
	void oViewDialogStealContainer(void){XCALL(0x0068A300);};

	oCViewDialogStealContainer(void){oViewDialogStealContainer();};
	virtual ~oCViewDialogStealContainer(){XCALL(0x0068A380)};
};

typedef oCViewDialogStealContainer	*LPCViewDialogStealContainer,	*LPCVIEWDIALOGSTEALCONTAINER;


//
//	VIEW
//
class oCViewDialogTrade : public zCViewDialog
{
public:
	virtual zCClassDef* _GetClassDef(void)const {XCALL(0x0068B010)};
	zCLASS(oCViewDialogTrade);
	// *********************************************************************************
	// **							ENUMS & STRUCTURES
	// *********************************************************************************
//protected:
public:
	typedef 
	enum zETradeDialogSection
	{
		TRADE_SECTION_LEFT_INVENTORY	,
		TRADE_SECTION_RIGHT_INVENTORY		
	}
	zTTradeSection;

	// *********************************************************************************
	// **								ATTRIBUTES
	// *********************************************************************************
//protected:
public:
	oCViewDialogStealContainer*	DlgInventoryNpc		;
	oCViewDialogInventory*		DlgInventoryPlayer	;
	zTTradeSection				SectionTrade		;
	oCNpc*						NpcLeft				;
	oCNpc*						NpcRight			;

	zINT						TransferCount		;

	// *********************************************************************************
	// **								 METHODS
	// *********************************************************************************
																				
	//																		
	//	HELPERS
	//																		
protected:
	void			__fastcall	AllDialogsDisable	( void						)	{XCALL(0x0068B160)};
	void			__fastcall	AllDialogsStop		( void						)	{XCALL(0x0068B140)};
	//																			
	//	GET/SET																	
	//																			
public:
	void			__fastcall	SetNpcLeft			( oCNpc*	pNpc			)	{XCALL(0x0068B180)};
	void			__fastcall	SetNpcRight			( oCNpc*	pNpc			)	{XCALL(0x0068B290)};
																				
	//																			
	//	SELECTION																
	//																			
	virtual void	__fastcall	StartSelection		( void						)	{XCALL(0x0068B340)};
																				
	//
	//  GET/ SET
	//
	virtual zINT	GetTransferCount				()						{ return TransferCount; }	;
	virtual void	SetTransferCount				(const zINT count)		{ TransferCount = count; }	;
	virtual void	IncTransferCount				(const zINT count)		{ TransferCount += count; }	;

	//																			
	//	EVENTS																	
	//																			
public:
	virtual zBOOL				HandleEvent			( int nKey					)	{XCALL(0x0068B3E0)};
	void			__fastcall	Update				( void						)	{XCALL(0x0068B750)};
																					
protected:																			
	zBOOL			__fastcall	OnKeyEnter			( void						)	{XCALL(0x0068B770)};
	zBOOL			__fastcall	OnKeyEsc			( void						)	{XCALL(0x0068B780)};
																					
	zBOOL			__fastcall	OnMoveLeft			( void						)	{XCALL(0x0068B790)};
	zBOOL			__fastcall	OnMoveRight			( void						)	{XCALL(0x0068BA60)};
																					
	zBOOL			__fastcall	OnTransferLeft		( zINT	amount )				{XCALL(0x0068B840)};
	zBOOL			__fastcall	OnTransferRight		( zINT	amount )				{XCALL(0x0068BB10)};
																					
	zBOOL			__fastcall	OnSectionPrevious	( void						)	{XCALL(0x0068BEA0)};
	zBOOL			__fastcall	OnSectionNext		( void						)	{XCALL(0x0068BF20)};
	void			__fastcall	OnSection			( zTTradeSection enuSection )	{XCALL(0x0068BFA0)};
	void			__fastcall	OnExit				( void						)	{XCALL(0x0068C000)};

	//
	//	CON-/DESTRUCTION
	//
public:
	void oViewDialogTrade							(void)						{XCALL(0x0068ADB0)};
	oCViewDialogTrade								()							{oViewDialogTrade();};
	virtual ~oCViewDialogTrade						()							{XCALL(0x0068B080)};

	void UpdateViewSettings							()							{XCALL(0x0068AD10)};

	static zCClassDef*				classDef;
public:
	zBOOL			__fastcall	OnTransferLeft_AST		( zINT	amount );
	zBOOL			__fastcall	OnTransferRight_AST		( zINT	amount );
};

typedef oCViewDialogTrade	*LPCViewDialogTrade,	*LPCVIEWDIALOGTRADE;


//
//	VIEW
//
class oCViewDialogItem : public zCViewDialog
{
public:
	zCLASS(oCViewDialogItem);
	static zCClassDef*	classDef;
	virtual zCClassDef* _GetClassDef(void)const	{XCALL(0x00689600)};
	// *********************************************************************************
	// **							ENUMS & STRUCTURES
	// *********************************************************************************

	// *********************************************************************************
	// **								ATTRIBUTES
	// *********************************************************************************
protected:
	oCItem*	Item;

	// *********************************************************************************
	// **								 METHODS
	// *********************************************************************************
public:
	void			__fastcall	SetItem	( oCItem* pItem )	{XCALL(0x00689700)};
	oCItem*			__fastcall	GetItem	( void			)	{ return this->Item; }

protected:
	virtual void	__fastcall	Blit	( void )			{XCALL(0x00689740)};
	//
	//	CON-/DESTRUCTION
	//
public:
	oCViewDialogItem(){oViewDialogItem();};
	void oViewDialogItem(void){XCALL(0x00689610)}
	virtual ~oCViewDialogItem(){XCALL(0x00689670)};
};

typedef oCViewDialogItem	*LPCViewDialogItem,	*LPCVIEWDIALOGITEM;


//
//	VIEW
//
class oCViewDialogItemContainer : public zCViewDialog
{
public:
	zCLASS(oCViewDialogItemContainer);
	static zCClassDef*				classDef;
	virtual zCClassDef* _GetClassDef(void)const {XCALL(0x00689A40)};
	// *********************************************************************************
	// **							ENUMS & STRUCTURES
	// *********************************************************************************
public:
	enum oEItemContainerAlignment
	{
		oEItemContainerAlignment_Left	,
		oEItemContainerAlignment_Right	
	}
	oTItemContainerAlignment, oTAlignmentItemContainer;
	// *********************************************************************************
	// **								ATTRIBUTES
	// *********************************************************************************
protected:
	oCItemContainer*			ItemContainer	;
	oEItemContainerAlignment	Alignment		;
	zUINT32						Value			;
	zREAL						ValueMultiplier	;

	// *********************************************************************************
	// **								 METHODS
	// *********************************************************************************

	//
	//	GET/SET
	//
public:	
	virtual void 				__fastcall	Activate			( zBOOL bActive  )									{XCALL(0x00689AF0)};
																												
	void						__fastcall	SetItemContainer	( oCItemContainer*			pItemContainer		)	{XCALL(0x00689B10)};
	void						__fastcall	SetAlignment		( oEItemContainerAlignment	enuAlignment		)	{XCALL(0x00689B40)};
	void						__fastcall	SetValueMultiplier	( zREAL						fValueMultiplier	)	{ this->ValueMultiplier = fValueMultiplier	; }
																												
	oCItemContainer*			__fastcall	GetItemContainer	( void )											{ return this->ItemContainer				; }	
	oEItemContainerAlignment	__fastcall	GetAlignment		( void )											{ return this->Alignment					; }	
	zUINT32						__fastcall	GetValue			( void )											{ return this->Value						; }	
	zREAL						__fastcall	GetValueMultiplier	( void )											{ return this->ValueMultiplier				; }	
																												
	oCItem*						__fastcall	GetSelectedItem		( void )											{XCALL(0x00689B50)};
	int							__fastcall	GetSelectedItemCount( void )											{XCALL(0x00689B70)};
	oCItem*						__fastcall	RemoveSelectedItem	( void )											{XCALL(0x00689B90)};
	void						__fastcall	InsertItem			( oCItem*					pItem				)	{XCALL(0x00689C00)};
	void						__fastcall	TransferAllItemsTo	( oCNpcInventory*			pInventory			)	{XCALL(0x00689C40)};
																												
protected:																										
	void						__fastcall	RemoveItem			( oCItem*					pItem				)	{XCALL(0x00689C20)};
	void						__fastcall UpdateValue			( void )											{XCALL(0x00689D10)};
																												
	//																											
	//	INTERACTION																								
	//																											
public:																											
	virtual void 				__fastcall	StartSelection		( void )											{XCALL(0x00689D90)};
	virtual void 				__fastcall	StopSelection		( void )											{XCALL(0x00689DF0)};
																													
	//																												
	//	EVENTS																										
	//																												
public:																												
	virtual zBOOL				HandleEvent						( int nKey )										{XCALL(0x00689D40)};		
																													
	zBOOL						__fastcall	CanHandleLeft		( void )											{XCALL(0x00689D20)};
	zBOOL						__fastcall	CanHandleRight		( void )											{XCALL(0x00689D30)};
																												
	//
	//	CON-/DESTRUCTION
	//
public:
	void oViewDialogItemContainer(void){XCALL(0x00689A50)};
	oCViewDialogItemContainer(){oViewDialogItemContainer();};
	virtual ~oCViewDialogItemContainer(){XCALL(0x00689AD0)};
};

typedef oCViewDialogItemContainer	*LPCViewDialogItemContainer,	*LPCVIEWDIALOGITEMCONTAINER;


//
//	VIEW
//
class zCViewDialogChoice : public zCViewDialog
{
public:
	zCLASS(zCViewDialogChoice);
	static zCClassDef*	classDef;

	virtual zCClassDef* _GetClassDef(void)const {XCALL(0x0068EA50)};
	// *********************************************************************************
	// **								ATTRIBUTES
	// *********************************************************************************
protected:
	zCOLOR	ColorSelected	;
	zCOLOR	ColorGrayed		;
	int		ChoiceSelected	;
	int		Choices			;
	int		LineStart		;

	// *********************************************************************************
	// **								 METHODS
	// *********************************************************************************

	//
	//	GET/SET
	//
public:
	void			__fastcall	SetColorActive			( zCOLOR& colActive )	{ this->ColorSelected	= colActive	; }
	void			__fastcall	SetColorGrayed			( zCOLOR& colGrayed )	{ this->ColorGrayed		= colGrayed	; }

	int				__fastcall	GetSelectedIndex		( void )				{ return this->ChoiceSelected		; }
	zSTRING			__fastcall	GetSelectedText			( void )				{XCALL(0x0068F550)};

protected:																		
	zCViewText2*	__fastcall	GetSelection			( void )				{XCALL(0x0068F540)};

	//
	//	ELEMENTS
	//
public:
	void			__fastcall	AddChoice				( zSTRING& strText, zBOOL bEnumerate = FALSE	)	{XCALL(0x0068F710)};
	void			__fastcall	RemoveChoice			( zSTRING& strText								)	{XCALL(0x0068F9A0)};
	void			__fastcall	RemoveChoice			( int nChoice									)	{XCALL(0x0068F9B0)};
	void			__fastcall	RemoveAllChoices		( void											)	{XCALL(0x0068F9C0)};
																				
	//
	//	INTERACTION
	//
public:
	virtual void 	__fastcall	StartSelection			( void ){XCALL(0x0068EF70)};
	virtual void 	__fastcall	StopSelection			( void ){XCALL(0x0068EFB0)};

	//
	//	EVENTS
	//
public:
	virtual zBOOL				HandleEvent				( int nKey		){XCALL(0x0068EBA0)};		
																		
	//																	
	//	SELECTION														
	//																	
protected:																
	void			__fastcall	SelectPrevious			( void			){XCALL(0x0068F220)};
	void			__fastcall	SelectNext				( void			){XCALL(0x0068F330)};
	void			__fastcall	Select					( int nCoice	){XCALL(0x0068F440)};
																		
	void			__fastcall	HighlightSelected		( void			){XCALL(0x0068F620)};
	void			__fastcall	ShowSelected			( void			){XCALL(0x0068F180)};
	void			__fastcall	ScrollUp				( void			){XCALL(0x0068F050)};
	void			__fastcall	ScrollDown				( void			){XCALL(0x0068F090)};
	zBOOL			__fastcall	IsSelectedOutsideAbove	( void			){XCALL(0x0068F0D0)};
	zBOOL			__fastcall	IsSelectedOutsideBelow	( void			){XCALL(0x0068F0F0)};

	//
	//	RENDER
	//
	virtual void	__fastcall	BlitText				( void			){XCALL(0x0068EFE0)};

	//
	//	CON-/DESTRUCTION
	//
public:
	void zViewDialogChoice(void){XCALL(0x0068EA60)};
			 zCViewDialogChoice(){zViewDialogChoice();};
	virtual ~zCViewDialogChoice(){XCALL(0x0068EAE0)};
};

typedef zCViewDialogChoice	*LPCViewDialogChoice,	*LPCVIEWDIALOGCHOICE;