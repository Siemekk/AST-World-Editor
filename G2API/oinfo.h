#pragma once

#include "ztypes.h"

// Forwards
class zCParser;

class oCNpc;
class oCInfo;

const int INF_ANSWER_MAX	= 6;

enum
{	
		INF_ANSWER_DEFAULT	= 0, 
		INF_ANSWER_HERO		= 1, 
		INF_ANSWER_FIGHTER	= 2,
		INF_ANSWER_MAGE		= 3,
		INF_ANSWER_THIEF	= 4,
		INF_ANSWER_PSIONIC	= 5
};

class oCInfoChoice
{
public:
	zSTRING Text	;
	int		Function;

	oCInfoChoice( zSTRING& strText, int nFunc )
	{
		this->Text		= strText;
		this->Function	= nFunc	 ; 
	}

	~oCInfoChoice() {;}
};

class oCInfoManager;
typedef zCList< oCInfoChoice > zCListInfoChoices;
class oCInfo {
	friend class oCInfoManager;
public:
	void _oCInfo								()									{ XCALL(0x007033B0) };
	oCInfo										()									{ _oCInfo();		};
	~oCInfo										()									{ XCALL(0x00703420) };
												
	void				SetInstance				(int instance)						{ XCALL(0x00703540) };
	int					GetInstance				()									{ XCALL(0x007036E0) };
												
	int					GetNpcID				()									{ XCALL(0x007038E0) };
	int					GetConditionFunc		()									{ XCALL(0x007038F0) };
	zBOOL				WasTold					()									{ XCALL(0x00703900) };
	void				SetTold					(zBOOL f)							{ XCALL(0x00703910) };
	zBOOL				IsImportant				()									{ return pd.important;	}
	zBOOL				IsTrade					()									{ return pd.trade	 ;	}
	zBOOL				IsPermanent				()									{ return pd.permanent;	}
												
	zBOOL				DoCheck					()									{ XCALL(0x007036F0) };		// Selfcheck (data) -> TRUE : ok
	int					GetDataSize				()									{ XCALL(0x00703920) };
	void*				GetDataAdr				()									{ XCALL(0x00703930) };
	zSTRING&			GetText					()									{ XCALL(0x00703940) };
												
	zBOOL				InfoConditions			()									{ XCALL(0x00703950) };
	void				Info					()									{ XCALL(0x00703970) };
												
	void				AddChoice				( zSTRING strText, int nFunc )		{ XCALL(0x00703B20) };
	void				RemoveChoice			( zSTRING strText )					{ XCALL(0x00703C20) };
	void				RemoveAllChoices		()									{ XCALL(0x00703D70) };
	zCListInfoChoices&	GetChoices				()									{ return listChoices;					}
	int					GetChoiceCount			()									{ return listChoices.GetNumInList();	}

	oCInfo*				next;
	zSTRING				name		;

	virtual void		Archive					( zCArchiver &arc )					{ XCALL(0x00703990) };
	virtual void		Unarchive				( zCArchiver &arc )					{ XCALL(0x007039D0) };
	virtual void		RestoreParserInstance	()									{ XCALL(0x00703B00) };
private:		
	#pragma pack(push,1)
	struct Tpd
	{										// Parserdata
		int				npc			;		// Npc - Instance 
		int				nr			;		// ID
		zBOOL			important	;		// Is it an important Info
		int				conditions	;		// Condition
		int				information	;		// function to be executed 
		zSTRING			description	;		// text that will be displaye by informationmanager
		zBOOL			trade		;		// Info will cause infomanmager to start trademanager
		zBOOL			permanent	;		// Indicates that info will not be deleted after being told
	} pd;
	#pragma pack(pop)

	zBOOL				told		;		// already told -> delete ?	
	int					instance	;		// InstanceNr of Info
	zCListInfoChoices	listChoices	;
};

typedef zCListSort< oCInfo > zCListInfos;

class oCInfoManager
{
	
public:
	void _oCInfoManager(zCParser* p)																{ XCALL(0x007023F0) };
	oCInfoManager								( zCParser* p )										{ _oCInfoManager(p);};
	~oCInfoManager								( )													{ XCALL(0x00702720) };
												
	// Get next matching Information			
	oCInfo*		GetInformation					( int infoInstance  )								{ XCALL(0x00702910) };
	oCInfo*		GetInformation					( oCNpc* ask, oCNpc* npc, zBOOL important = FALSE )	{ XCALL(0x007027B0) };
	int			GetInfoCount					( oCNpc* pNpcAsker, oCNpc* pNpcAsked )				{ XCALL(0x00702940) };
	int			GetInfoCountImportant			( oCNpc* pNpcAsker, oCNpc* pNpcAsked )				{ XCALL(0x00702AA0) };
	int			GetInfoCountUnimportant			( oCNpc* pNpcAsker, oCNpc* pNpcAsked )				{ XCALL(0x00702C00) };
	oCInfo*		GetInfo							( oCNpc* pNpcAsker, oCNpc* pNpcAsked, int nInfo )	{ XCALL(0x00702D60) };
	oCInfo*		GetInfoImportant				( oCNpc* pNpcAsker, oCNpc* pNpcAsked, int nInfo )	{ XCALL(0x00702EC0) };
	oCInfo*		GetInfoUnimportant				( oCNpc* pNpcAsker, oCNpc* pNpcAsked, int nInfo )	{ XCALL(0x00703030) };
	zBOOL		InformationTold					( int infoInstance )								{ XCALL(0x007031A0) };
												
	virtual void		Archive					(zCArchiver &arc)									{ XCALL(0x007031E0) };
	virtual void		Unarchive				(zCArchiver &arc)									{ XCALL(0x00703240) };
	virtual void		RestoreParserInstances	()													{ XCALL(0x00703390) };
private:
	static int CompareInfos( oCInfo* pInfoLeft, oCInfo* pInfoRight )	{	if		( ( ! pInfoLeft )  || ( ! pInfoRight )	)	return  0;
																			if		( pInfoLeft->pd.nr  > pInfoRight->pd.nr )	return  1;
																			else if ( pInfoLeft->pd.nr == pInfoRight->pd.nr )	return  0;
																			else												return -1;	}
	// List of all (relevant) Infos
	zCListInfos infoList;	
	// Inits and handles all scripted Infos
	zCParser *p;
	// Statics
	//static zBOOL size_checked;
};
