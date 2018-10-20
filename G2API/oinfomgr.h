#pragma once
#include "ztypes.h"
#include "oviewtrade.h"
#include "oinfo.h"

class oCInformationManager 
{
	// *********************************************************************************
	// **							ENUMS & STRUCTURES
	// *********************************************************************************
protected:
	typedef
	enum zEInformationManagerMode
	{
		INFO_MGR_MODE_IMPORTANT	,
		INFO_MGR_MODE_INFO		,
		INFO_MGR_MODE_CHOICE	,
		INFO_MGR_MODE_TRADE
	}
	zTInfoMgrMode;

	// *********************************************************************************
	// **								ATTRIBUTES
	// *********************************************************************************
protected:
	zSTRING					LastMethod				;
	zCViewDialogChoice*		DlgStatus				;
	oCViewDialogTrade*		DlgTrade				;
	zCViewDialogChoice*		DlgChoice				;
	oCNpc*					Npc						;
	oCNpc*					Player					;
	oCInfo*					Info					;
	zBOOL					IsDone					;
	zBOOL					IsWaitingForEnd			;
	zBOOL					IsWaitingForScript		;
	zBOOL					IsWaitingForOpen		;
	zBOOL					IsWaitingForClose		;
	zBOOL					IsWaitingForSelection	;
	zBOOL					MustOpen				;
	int						IndexBye				;
	int						ImportantCurrent		;
	int						ImportantMax			;
	zTInfoMgrMode			Mode					;

	// *********************************************************************************
	// **								 METHODS
	// *********************************************************************************
public:
	void	__fastcall	SetNpc				( oCNpc* pNpc			)	{ XCALL(0x006609F0) };
	zBOOL	__fastcall	HasFinished			( void					)	{ XCALL(0x006609D0) };
	zBOOL	__fastcall	WaitingForEnd		( void					)	{ XCALL(0x006609E0) };
	void	__fastcall	Update				( void					)	{ XCALL(0x00660BB0) };
	void	__fastcall	Exit				( void					)	{ XCALL(0x00661240) };
	void	__fastcall	ToggleStatus		( void					)	{ XCALL(0x0065FF20) };

	void	UpdateViewSettings				( void					)	{ XCALL(0x0065F7E0) };
																			
protected:																	
	void	__fastcall	CollectInfos		( void					)	{ XCALL(0x00661AA0) };
	zBOOL	__fastcall	CollectChoices		( oCInfo* pInfo			)	{ XCALL(0x00661CD0) };
	void	__fastcall	ProcessImportant	( void					)	{ XCALL(0x006615B0) };
	void	__fastcall	ProcessNextImportant( void					)	{ XCALL(0x006617B0) };
	void	__fastcall	InfoWaitForEnd		( void					)	{ XCALL(0x00661990) };

	void	__fastcall	CameraStart			( void					)	{ XCALL(0x006613A0) };
	void	__fastcall	CameraStop			( void					)	{ XCALL(0x00661520) };
	void	__fastcall	CameraRefresh		( void					)	{ XCALL(0x00661590) };

	void	__fastcall	PrintStatus			( void					)	{ XCALL(0x0065FF70) };

	//
	//	EVENTS
	//
	void	__fastcall	OnImportantBegin	( void					)	{ XCALL(0x00661DB0) };
	void	__fastcall	OnImportantEnd		( void					)	{ XCALL(0x00661E90) };
	void	__fastcall	OnInfoBegin			( void					)	{ XCALL(0x00661FF0) };
	void	__fastcall	OnInfo				( int			nInfo	)	{ XCALL(0x006620B0) };
	void	__fastcall	OnInfo				( oCInfo*		pInfo	)	{ XCALL(0x00662290) };
	void	__fastcall	OnChoiceBegin		( void					)	{ XCALL(0x00662570) };
	void	__fastcall	OnChoice			( int nChoice			)	{ XCALL(0x00662780) };
	void	__fastcall	OnChoice			( oCInfoChoice*	pChoice	)	{ XCALL(0x006629A0) };
	void	__fastcall	OnChoiceEnd			( void					)	{ XCALL(0x00662B90) };
	void	__fastcall	OnInfoEnd			( void					)	{ XCALL(0x00662CF0) };
																			
	void	__fastcall	OnTradeBegin		( void					)	{ XCALL(0x00662E60) };
	void	__fastcall	OnTradeEnd			( void					)	{ XCALL(0x00662F60) };
																			
	void	__fastcall	OnExit				( void					)	{ XCALL(0x006630D0) };
	void	__fastcall	OnTermination		( void					)	{ XCALL(0x006631A0) };

public:
	static oCInformationManager& GetInformationManager( void ){ XCALL(0x0065F790) };

protected:	 
			void _oCInformationManager()	{ XCALL(0x0065F930)			};
			 oCInformationManager()			{ _oCInformationManager();	};
public:		~oCInformationManager()			{ XCALL(0x0065FDD0)			};
};
