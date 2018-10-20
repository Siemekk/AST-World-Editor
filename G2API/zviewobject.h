#pragma once

#include "zCObject.h"
#include "zCView.h"

enum zTViewFX_Mode
{
	zTFX_NONE,		
	zTFX_ZOOM,		
	zTFX_FADE		
};

class zCViewObject;
typedef zCListSort< zCViewObject > zCListViewObject;

class zCViewFont
{
public:
	zTRnd_AlphaBlendFunc	FuncAlphaBlend	;
	zCFont*					Font			;
	zCOLOR					Color			;
	int						Alpha			;
	BOOL					EnabledBlend	;
	zCViewFont(zCFont*,zCOLOR&,int,zTRnd_AlphaBlendFunc)
	{
		XCALL(0x00694C40);
	};

	zCViewFont(zCFont*,zCOLOR&)
	{
		XCALL(0x00694C70);
	};

	zCViewFont(zCFont*)
	{
		XCALL(0x00694CA0);
	};

	zCViewFont()
	{
		XCALL(0x00694CE0);
	};

	~zCViewFont()
	{
		XCALL(0x00694D20);
	};

public:
	void					__fastcall	EnableBlend			( BOOL bEnable = TRUE					)	{ this->EnabledBlend	= bEnable		; }
	void					__fastcall	SetFont				( zSTRING& strFont						)	;
	void					__fastcall	SetFont				( zCFont* pFont							)	{ this->Font			= pFont			; }
	void					__fastcall	SetColor			( zCOLOR& color							)	{ this->Color			= color			; }
	void					__fastcall	SetAlpha			( int nAlpha							)	{ this->Alpha			= nAlpha		; }
	void					__fastcall	SetAlphaBlendFunc	( zTRnd_AlphaBlendFunc funcAlphaBlend	)	{ this->FuncAlphaBlend	= funcAlphaBlend; }

	BOOL					__fastcall	IsEnabledBlend		( void )									{ return this->EnabledBlend		; }
	zCFont*					__fastcall	GetFont				( void )									{ return this->Font				; }
	zCOLOR&					__fastcall	GetColor			( void )									{ return this->Color			; }
	int						__fastcall	GetAlpha			( void )									{ return this->Alpha			; }
	zTRnd_AlphaBlendFunc	__fastcall	GetAlphaBlendFunc	( void )									{ return this->FuncAlphaBlend	; }
};

typedef
class zCPosition
{
public:
	INT32 X;
	INT32 Y;

	zCPosition()						{ X = 0l; Y = 0l ; } 
	zCPosition( UINT32 x, UINT32 y )	{ X = x ; Y = y  ; } 

	zCPosition& operator += ( zCPosition& ptOther ) { X += ptOther.X ; Y += ptOther.Y; return (*this); }
	zCPosition& operator -= ( zCPosition& ptOther ) { X -= ptOther.X ; Y -= ptOther.Y; return (*this); }
}
zPOS;





class zCViewText2						
{
	friend class zCViewDialogChoice;
	friend class zCViewPrint;

	BOOL		EnabledColor	;
	BOOL		EnabledTimer	;

	zPOS		PixelPosition	;
	float		Timer			;
	zSTRING		Text			;
	zCViewFont	ViewFont		;
public:

	zCViewText2(zSTRING&,zCPosition&,zCOLOR&,float,zCFont*,int,zTRnd_AlphaBlendFunc)
	{
		XCALL(0x006943D0);
	};

	zCViewText2(zSTRING&,zCPosition&,zCOLOR&,zCFont*,int,zTRnd_AlphaBlendFunc)
	{
		XCALL(0x006944B0);
	};

	zCViewText2(zSTRING&,zCPosition&,zCOLOR&,float,zCFont*)
	{
		XCALL(0x00694590);
	};

	zCViewText2(zSTRING&,zCPosition&,zCOLOR&,zCFont*)
	{
		XCALL(0x00694680);
	};

	zCViewText2(zSTRING&,zCPosition&,zCOLOR&)
	{
		XCALL(0x00694760);
	};

	zCViewText2(zSTRING&,zCPosition&,float,zCFont*)
	{
		XCALL(0x00694840);
	};

	zCViewText2(zSTRING&,zCPosition&,zCFont*)
	{
		XCALL(0x00694930);
	};

	zCViewText2(zSTRING&,zCPosition&,float)
	{
		XCALL(0x00694A20);
	};

	zCViewText2(zSTRING&,zCPosition&)
	{
		XCALL(0x00694B10);
	};

	~zCViewText2()
	{
		XCALL(0x00694BF0);
	};
};

class zCViewObject : public zCObject, public zCViewBase		
{
public:
	zCLASS(zCViewObject);
	zPOS				VirtualPosition		;
	zPOS				VirtualSize			;
	zPOS				PixelPosition		;
	zPOS				PixelSize			;
	UINT32				ID					;
									
	zCViewObject*		ViewParent			;
	zCListViewObject	ListChildren		;
	static zCClassDef*	classDef;

protected:
	void _zCViewObject() { XCALL(0x006918B0) };		
	zCViewObject() { _zCViewObject(); };
		/* Methods */
public:
	static int Compare( zCViewObject  *, zCViewObject  *) { XCALL(0x006919A0) };
	void		__fastcall AddChild( zCViewObject  *) { XCALL(0x00691B00) };
	void		__fastcall AddChild( zCViewObject  &) { XCALL(0x00691B20) };
	void		__fastcall AddChildren( zCListSort < zCViewObject > &) { XCALL(0x00691B40) };
	void		__fastcall RemoveChild( zCViewObject  *) { XCALL(0x00691BB0) };
	void		__fastcall RemoveChild( zCViewObject  &) { XCALL(0x00691C30) };
	void		__fastcall RemoveAllChildren() { XCALL(0x00691CB0) };
	zCViewObject const * __fastcall GetChild(zDWORD) { XCALL(0x00691D80) };
	void		__fastcall SetVirtualPosition( zCPosition  &) { XCALL(0x00691DE0) };
	void		__fastcall SetPixelPosition( zCPosition  &) { XCALL(0x00691EA0) };
	void		__fastcall SetVirtualSize( zCPosition  &) { XCALL(0x00691F60) };
	void		__fastcall SetPixelSize( zCPosition  &) { XCALL(0x00692160) };
protected:
	void		__fastcall EvaluatePixelPosition( zCPosition  &) { XCALL(0x00692360) };
	void		__fastcall EvaluatePixelSize( zCPosition  &) { XCALL(0x006923C0) };
	void		__fastcall UpdatePixelPosition() { XCALL(0x00692460) };
	void		__fastcall UpdatePixelSize() { XCALL(0x00692510) };
	void		__fastcall UpdatePixelPositionChildren() { XCALL(0x00692600) };
	void		__fastcall UpdatePixelSizeChildren() { XCALL(0x006926C0) };
	void		__fastcall UpdatePixelDimensionsChildren() { XCALL(0x006927B0) };
	zCPosition __fastcall ConvertPositionVirtualToPixel( zCPosition  &) { XCALL(0x00692950) };
	zCPosition __fastcall ConvertSizeVirtualToPixel( zCPosition  &) { XCALL(0x00692990) };
	zCPosition __fastcall ConvertPositionPixelToVirtual( zCPosition  &) { XCALL(0x006929D0) };
	zCPosition __fastcall ConvertSizePixelToVirtual( zCPosition  &) { XCALL(0x00692A20) };
	zCPosition __fastcall ConvertToPixel( zCPosition  &) { XCALL(0x00692A70) };
	zCPosition __fastcall ConvertToPixelLocal( zCPosition  &) { XCALL(0x00692AD0) };
	zCPosition __fastcall ConvertToVirtualLocal( zCPosition  &) { XCALL(0x00692B10) };

		/* Virtual methods */
private:
	virtual zCClassDef * _GetClassDef()const { XCALL(0x00691990) };
public:
	virtual int anx(int) { XCALL(0x00692BA0) };
	virtual int any(int) { XCALL(0x00692BC0) };
	virtual int nax(int) { XCALL(0x00692B60) };
	virtual int nay(int) { XCALL(0x00692B80) };
	virtual int ClipLine(int &,int &,int &,int &) { XCALL(0x00692BE0) };
	virtual void Line(int,int,int,int, zCOLOR  const &) { XCALL(0x00692D90) };
	virtual void __fastcall GetViewport(int &,int &,int &,int &) { XCALL(0x00692330) };
protected:
	virtual int GetCode(int,int) { XCALL(0x00692E40) };
public:
	virtual ~zCViewObject() { XCALL(0x006919E0) };
};

class zCViewDraw : public zCViewObject		
{
public:
	zCLASS(zCViewDraw);
protected:
	zTRnd_AlphaBlendFunc	TextureFuncAlpha	;
	zCTexture*				Texture				;
	zCOLOR					TextureColor		;
	int						TextureAlpha		;
	zVEC2					TexturePosition	[2]	;		
	/* Properties */
private:
	static zCClassDef* classDef;

	/* Methods */
public:
	void _zCViewDraw()																{ XCALL(0x0068FD20) };
	zCViewDraw()																{ _zCViewDraw();	};
	virtual ~zCViewDraw()														{ XCALL(0x0068FDE0) };
	void __fastcall RemoveChild( zSTRING  &)										{ XCALL(0x0068FE60) };
	void __fastcall SetTextureAlphaBlendFunc( zTRnd_AlphaBlendFunc  const &)		{ XCALL(0x0068FF50) };
	void __fastcall SetTexture( zSTRING  const &)									{ XCALL(0x0068FF60) };
	void __fastcall SetTexture( zCTexture  *)										{ XCALL(0x00690040) };
	void __fastcall SetTextureColor( zCOLOR  const &)								{ XCALL(0x00690080) };
	void __fastcall SetTextureAlpha(int)											{ XCALL(0x00690090) };
	void __fastcall TextureCacheIn(float)											{ XCALL(0x006900A0) };
	void __fastcall Render()													{ XCALL(0x006900E0) };
protected:
	void __fastcall Draw()														{ XCALL(0x006901F0) };
	void __fastcall DrawChildren()												{ XCALL(0x00690300) };
public:
	static zCViewDraw & GetScreen()												{ XCALL(0x006905C0) };
	static void CleanupScreen()													{ XCALL(0x006906F0) };

		/* Virtual methods */
private:
	virtual zCClassDef * _GetClassDef()const									{ XCALL(0x0068FD10) };
protected:
	virtual void __fastcall EvaluateTexturePosition()							{ XCALL(0x00690540) };
	virtual void __fastcall BlitTexture()										{ XCALL(0x00690490) };
	virtual void __fastcall Blit()												{ XCALL(0x00690430) };
};




class zCViewFX : public zCViewDraw
{
	// *********************************************************************************
	// **							ENUMS & STRUCTURES
	// *********************************************************************************
public:
	typedef
	enum zEViewFX
	{
		VIEW_FX_NONE		= 0,
		VIEW_FX_ZOOM		= 1,
		VIEW_FX_FADE		= VIEW_FX_ZOOM << 1,
		VIEW_FX_BOUNCE		= VIEW_FX_FADE << 1,

		VIEW_FX_FORCE_DWORD	= 0xffffffff
	}
	zTViewFX;
protected:
	zBOOL		HasOpened		;																			//  indicates completed opening process
	zBOOL		HasClosed		;																			//  indicates completed closing process
	zREAL		TimeOpen		;																			//	elapsed time during opening process
	zREAL		TimeClose		;																			//	elapsed time during closing process
	zREAL		DurationOpen	;																			//	time opening process will take to finish
	zREAL		DurationClose	;																			//	time closing process will take to finish
	zDWORD		ModeOpen		;																			//	fx that will be applied during opening process
	zDWORD		ModeClose		;																			//	fx that will be applied during closing process
	zVEC2		TextureOffset[2];																			//	offset to be added to texture coordinates
public:
	void _zCViewFX()						{ XCALL(0x00690A60) };
	zCViewFX() { _zCViewFX(); };
	

	/* Properties */
private:
	static zCClassDef *classDef;

	/* Methods */
public:

	void __fastcall Init(	zCViewObject*	pParent			= NULL			,
															zBOOL			bOpened			= TRUE			,
															zDWORD			enuFXOpen		= VIEW_FX_NONE	,
															zDWORD			enuFXClose		= VIEW_FX_NONE	,
															zREAL			fDurationOpen	= 500.0f		,
															zREAL			fDurationClose	= 500.0f		,
															zSTRING&		strTexture		= zSTRING( "" )	
														)	{ XCALL(0x00690B60) };
	void __fastcall Open()								{ XCALL(0x00690BE0) };
	void __fastcall OpenSafe()							{ XCALL(0x00690C10) };
protected:
	void __fastcall OpenImmediately()					{ XCALL(0x00690C90) };
public:
	void __fastcall Close()								{ XCALL(0x00690CB0) };
	void __fastcall CloseSafe()							{ XCALL(0x00690D00) };
protected:
	void __fastcall CloseImmediately()					{ XCALL(0x00690D90) };
	void __fastcall ApplyOpenCloseFX()					{ XCALL(0x00690DB0) };
	void __fastcall ApplyOpenFX()						{ XCALL(0x00691060) };
	void __fastcall ApplyCloseFX()						{ XCALL(0x006911A0) };
	void __fastcall ApplyOpenFade()						{ XCALL(0x006912E0) };
	void __fastcall ApplyOpenZoom()						{ XCALL(0x00691330) };
	void __fastcall ApplyCloseFade()					{ XCALL(0x006913C0) };
	void __fastcall ApplyCloseZoom()					{ XCALL(0x00691420) };

	/* Virtual methods */
private:
	virtual zCClassDef * _GetClassDef()const			{ XCALL(0x00690A50) };
protected:
	virtual void __fastcall EvaluateTexturePosition()	{ XCALL(0x006915E0) };
	virtual void __fastcall Blit()						{ XCALL(0x006914B0) };
	virtual ~zCViewFX()									{ XCALL(0x00690B40) };
};

class zCViewPrint : public zCViewFX		
{
	// *********************************************************************************
	// **							ENUMS & STRUCTURES
	// *********************************************************************************
protected:
	typedef zCArray< zCViewText2* > zCListViewText;

	typedef
	enum zEViewAlignment
	{
		VIEW_ALIGN_NONE		,
		VIEW_ALIGN_MAX		,
		VIEW_ALIGN_MIN		,
		VIEW_ALIGN_CENTER	
	}
	zTViewAlign;

protected:
	zCListViewText	ListTextLines	;
	zCViewFont		ViewFont		;
	zPOS			PositionCursor	;
	zPOS			OffsetTextPixel	;
	zPOS			SizeMargin	[2]	;
private:
	static zCClassDef* classDef;
public:
	zCLASS(zCViewPrint);
	zCViewPrint()																	{ _zCViewPrint();   };
	void _zCViewPrint()																	{ XCALL(0x00693200) };
	void __fastcall SizeHeightToContent(int)											{ XCALL(0x00693400) };
	void __fastcall ClearText()														{ XCALL(0x006938E0) };
	void __fastcall Print( zSTRING  &)													{ XCALL(0x00693970) };
	void __fastcall PrintLine( zSTRING  &)												{ XCALL(0x00693A50) };
	void __fastcall PrintLines( zSTRING  &)												{ XCALL(0x00693C00) };
protected:
	void __fastcall AddText( zCViewText2  *)											{ XCALL(0x00694070) };
	void __fastcall RemoveText( zCViewText2  *)											{ XCALL(0x00694180) };
	void __fastcall RemoveAllTexts()												{ XCALL(0x006941E0) };
	void __fastcall GetPixelBorder( zCPosition  &, zCPosition  &)						{ XCALL(0x00693880) };
	/* Virtual methods */
private:
	virtual zCClassDef * _GetClassDef()const										{ XCALL(0x006932D0) };
protected:
	virtual void __fastcall Blit()													{ XCALL(0x006934A0) };
	virtual void __fastcall BlitText()												{ XCALL(0x006934E0) };
	virtual void __fastcall BlitTextLine( zCViewText2  *)								{ XCALL(0x00693590) };
	virtual void __fastcall BlitTextCharacters( zCViewText2  *, zCFont  *, zCOLOR  &)	{ XCALL(0x00693650) };
	virtual ~zCViewPrint()															{ XCALL(0x00693310) };
};


class zCViewDialog : public zCViewPrint, public zCInputCallback		
{
	static zCClassDef* classDef;
public:
	zCLASS(zCViewDialog);
protected:
	zBOOL	IsDone		;
	zBOOL	IsActivated	;
public:
	virtual zBOOL	__fastcall	IsActive		( void )				{ return this->IsActivated		; }
	virtual void 	__fastcall	Activate		( zBOOL bActive  )		{ this->IsActivated = bActive	; }

	virtual zBOOL	__fastcall	HasFinished		( void )				{ return this->IsDone			; }
	virtual void 	__fastcall	StartSelection	( void )				{ this->IsDone = FALSE			; }
	virtual void 	__fastcall	StopSelection	( void )				{ this->IsDone = TRUE			; }

	//
	//	CON-/DESTRUCTION
	//
public:
	zCViewDialog(){XCALL(0x0068E5A0)};
	virtual ~zCViewDialog(){XCALL(0x0068E6E0)};
};