#pragma once

#include "zViewObject.h"


class oCViewDocumentMap;



class oCViewDocument : public zCViewDialog		
{
public:
	void _oCViewDocument()												{ XCALL(0x0068C620) };
	oCViewDocument()													{ _oCViewDocument();};

	void _oCViewDocument(zSTRING &)										{ XCALL(0x0068C2C0) };
	oCViewDocument(zSTRING & name)										{ _oCViewDocument(name);};
public:
	void __fastcall SetPages(int)										{ XCALL(0x0068C6A0) };
	void __fastcall SetMargins(int, zCPosition  &, zCPosition  &,int)	{ XCALL(0x0068C7F0) };
	void __fastcall SetFont(int, zSTRING  &)							{ XCALL(0x0068CAF0) };
	void __fastcall PrintLine(int, zSTRING  &)							{ XCALL(0x0068CBB0) };
	void __fastcall PrintLines(int, zSTRING  &)							{ XCALL(0x0068CC70) };
	void __fastcall SetTexture( zSTRING  &,int)							{ XCALL(0x0068CD30) };
	void					__fastcall	SetPosition						( zPOS& ptPosition										)			{			this->SetVirtualPosition( ptPosition )	; }
	void					__fastcall	SetSize							( zPOS& ptSize											)			{			this->SetVirtualSize	( ptSize )		; }
																																	
	const zPOS&				__fastcall	GetVirtualPosition				( void													)	const	{ return	this->VirtualPosition					; }
	const zPOS&				__fastcall	GetVirtualSize					( void													)			{ return	this->VirtualSize						; }
																																				
	const zPOS&				__fastcall	GetPixelPosition				( void													)	const	{ return	this->PixelPosition						; }
	const zPOS&				__fastcall	GetPixelSize					( void													)			{ return	this->PixelSize							; }
																																				
	const zPOS&				__fastcall	GetPosition						( void													)	const	{ return	this->GetVirtualPosition()				; }
	const zPOS&				__fastcall	GetSize							( void													)			{ return	this->GetVirtualSize	()				; }
	/* Virtual methods */
	virtual oCViewDocument * __fastcall SetPage(int, zSTRING  &,int)	{ XCALL(0x0068C970) };
	virtual ~oCViewDocument()											{ XCALL(0x0068C650) };

protected:
	void __fastcall AlignPageToParent()									{ XCALL(0x0068CDA0) };
	void __fastcall Center()											{ XCALL(0x0068CF30) };
	void __fastcall SizeToContent()										{ XCALL(0x0068CFA0) };
	void __fastcall SizeToParent()										{ XCALL(0x0068D050) };
	void __fastcall ScaleToParent()										{ XCALL(0x0068D090) };
	oCViewDocument * __fastcall GetPage(int)							{ XCALL(0x0068C670) };
};





typedef zCListSort< oCViewDocument > zCListDocuments;

class oCDocumentManager : public zCInputCallback
{
	zCListDocuments*	ListDocuments	;
	zCViewDialog*		DlgDocumentMain	;
public:
	
	static oCDocumentManager & GetDocumentManager(void)
	{
		XCALL(0x0065EA40);
	};
	
	void __fastcall Show(int)
	{
		XCALL(0x0065F300);
	};
	
	int __fastcall CreateMap(void)
	{
		XCALL(0x0065EEF0);
	};
	
	void __fastcall SetPage(int,int nPage, const zSTRING& sTexture, BOOL bScaleTexture)
	{
		XCALL(0x0065F100);
	};
	
	void __fastcall SetLevel(int, zSTRING const &)
	{
		XCALL(0x0065F1D0);
	};

	
	void __fastcall SetLevelCoords(int, int, int, int, int)
	{
		XCALL(0x0065F220);
	};

	
	oCViewDocument * __fastcall GetDocumentView(int)
	{
		XCALL(0x0065F3D0);
	};
	
	void __fastcall SetPages(int, int)
	{
		XCALL(0x0065F0C0);
	};
	//
	//	EVENTS
	//
public:
	virtual zBOOL	HandleEvent	( int nKey	);
};

class oCViewDocumentMap : public oCViewDocument
{
private:
	typedef
	enum zEHeading
	{
		HEADING_NORTH		,
		HEADING_NORTHEAST	,	
		HEADING_EAST		,	
		HEADING_SOUTHEAST	,	
		HEADING_SOUTH		,	
		HEADING_SOUTHWEST	,	
		HEADING_WEST		,	
		HEADING_NORTHWEST
	}
	zTHeading;

	// *********************************************************************************
	// **								ATTRIBUTES
	// *********************************************************************************
protected:
	oCViewDocument		ViewArrow	;
	oCViewDocument*		ViewPageMap	;
	zSTRING				Level		;
	zVEC4				LevelCoords	;  // VX=left, VY=top, VZ=right, VW=bottom

	// *********************************************************************************
	// **								 METHODS
	// *********************************************************************************
public:
	virtual oCViewDocument*	__fastcall	SetPage				( int nPage, zSTRING& strTexture, zBOOL bScale ){XCALL(0x0068D520)};
			void			__fastcall	SetLevel			( const zSTRING& strLevel ){XCALL(0x0068D610)};
			void			__fastcall	SetLevelCoords		( int left, int top, int right, int bottom ){XCALL(0x0068D770)};
			void			__fastcall	UpdatePosition		( void ){XCALL(0x0068D7B0)};

protected:											

	//
	//	CON-/DESTRUCTION
	//
public:
	void oCViewDocumentMap_(void){XCALL(0x0068D340);};
	oCViewDocumentMap(){oCViewDocumentMap_();};
	virtual ~oCViewDocumentMap(){XCALL(0x0068D470);};
 };