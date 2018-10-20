#pragma once


#include "ztypes.h"
#include "zcinputcallback.h"

#define VIEW_VXMAX 8192
#define VIEW_VYMAX 8192

class zCTexture;
class zCFont
{
public:
	int			GetFontY			()								{ XCALL(0x007894E0); };
	zCTexture * GetFontTexture		()								{ XCALL(0x0078A3F0); };
	int			GetLetterDistance	()								{ XCALL(0x00789530); };
	int			GetWidth			(char)							{ XCALL(0x00789520); };
	int			GetFontData			(UCHAR, int&, zVEC2&, zVEC2&)	{ XCALL(0x0078A390); };
};

class zCViewText
{
	int				m_nPosX;		
	int				m_nPosY;		
	zSTRING			m_sText;		
	zCFont*			m_pFont;		
	float			m_fTime;		
	BOOL			m_bMultiLine;	
	zCOLOR			m_clrFont;		
	BOOL			m_bTimed;		
	BOOL			m_bColored;		
public:
	virtual ~zCViewText()
	{
		XCALL(0x007AC700);
	};

	void zViewText(int,int,zSTRING const&)
	{
		XCALL(0x007AC220);
	};

	zCViewText(int x, int y, zSTRING const& text)
	{
		zViewText(x,y,text);
	};

	void zViewText(int,int,zSTRING const&,float&,zCOLOR&, BOOL, BOOL)
	{
		XCALL(0x007AC3E0);
	};

	zCViewText(int x, int y, zSTRING const& text, float& time, zCOLOR& color, BOOL bTimed, BOOL bColored)
	{
		zViewText(x,y,text,time,color,bTimed,bColored);
	};

	void Create(int,int,zSTRING const&,float&,zCOLOR&,int,int)
	{
		XCALL(0x007AC580);
	};
};




enum zTviewID 
{
	VIEW_SCREEN,
	VIEW_VIEWPORT,
	VIEW_ITEM
};	


enum zTViewFX
{
	VIEW_FX_NONE,
	VIEW_FX_ZOOM,
	VIEW_FX_MAX	
};



struct zTProgressRange
{
	int			m_nIndex;
	float		m_fBoundL;
	float		m_fBoundH;
};


enum zTRnd_AlphaBlendFunc  ;


const int VIEW_GROUNDED		=    1<<3;	
const int VIEW_MODAL		=    1<<6;	
const int VIEW_AUTOSCROLL	=    1<<8;
const int VIEW_TXT_CENTER	=    1<<9;
const int VIEW_TXT_AUTO		=	 1<<10;
const int VIEW_STAYONTOP	=	 1<<11;

const int VIEW_I_TEXT		= 1;		



class zCViewBase
{							
public:
	virtual int					anx			( int x )																	{ return 0; }
	virtual int					any			( int y )																	{ return 0; }
	virtual int					nax			( int x )																	{ return 0; }
	virtual int					nay			( int y )																	{ return 0; }																											
	virtual int					ClipLine	( int &x0, int &y0, int &x1, int &y1 )										{ return 0; }
	virtual void				Line		( int  x1, int  y1, int  x2, int  y2, const zCOLOR& color )					{ ; }
	virtual void	__fastcall	GetViewport	( int &xmin, int &ymin , int &xdim, int &ydim)								{ ; };			
	virtual void				FillZBuffer	( void )																	{ XCALL(0x0068DF80); };	
	virtual int					GetCode		( int x, int y )															{ return 0; };		
	~zCViewBase(){};
};

typedef zCViewBase	*LPCViewBase,	*LPCVIEWBASE;

class zCView : public zCViewBase, public zCInputCallback
{
public:
	
	
	
	typedef
	enum zEViewFX
	{
		VIEW_FX_NONE,
		VIEW_FX_ZOOM,
		VIEW_FX_MAX	
	}
	zTViewFX;
	
	
	
	BOOL					m_bFillZ;
	zCView*					next;
	zTviewID				viewID;
	int						flags;				
	int						intflags;			
	BOOL					ondesk;				

	
	zTRnd_AlphaBlendFunc	alphafunc;
	zCOLOR					color;
	int						alpha;

	
	zList <zCView>			childs;
	zCView*					owner;
	zCTexture*				backTex;

	
	int						vposx,vposy;
	int						vsizex,vsizey;
	
	int						pposx,pposy;
	int						psizex,psizey;

	
	zCFont*					font;	
	zCOLOR					fontColor;
	
	
	int						px1,py1,px2,py2;	
	int						winx,winy;			
	zCList <zCViewText>		textLines;			
	float					scrollMaxTime;		
	float					scrollTimer;		

	
	
	
	zTViewFX				fxOpen		 ;
	zTViewFX				fxClose		 ;
	float					timeDialog	 ;		
	float					timeOpen	 ;		
	float					timeClose	 ;
	float					speedOpen	 ;
	float					speedClose	 ;
	BOOL					isOpen		 ;
	BOOL					isClosed	 ;
	BOOL					continueOpen ;
	BOOL					continueClose;
	BOOL					removeOnClose;
	BOOL					resizeOnOpen ;
	int						maxTextLength;
	zSTRING					textMaxLength;
	zVEC2					posCurrent	 [2];
	zVEC2					posOpenClose [2];
	
	
	
public:
	virtual ~zCView()											{XCALL(0x007A56E0);};
	virtual BOOL ClipLine(int&, int&, int&, int&)				{XCALL(0x007AC060);};						
	virtual void Line(int, int, int, int, zCOLOR const&)		{XCALL(0x007ABF70);};	
	
	virtual int				anx					(int x)			{XCALL(0x007A5E80);};
	virtual int				any					(int y)			{XCALL(0x007A5EC0);};
	virtual int				nax					(int x)			{XCALL(0x007A5E00);};
	virtual int				nay					(int y)			{XCALL(0x007A5E40);};


	virtual void __fastcall GetViewport(int &xmin,int &ymin,int &xdim,int &ydim)	{XCALL(0x0043D4F0);};
	virtual void			Blit				()				{XCALL(0x007A63C0);};
	virtual void			DrawItems			()				{XCALL(0x007A6750);};
	virtual int				GetCode				(int x,int y)	{XCALL(0x007AC020);};

	zCView()
	{
		zView();
	};

	void zView()
	{
		XCALL(0x007A5640);
	};

	void zView(int, int, int, int, zTviewID pE = VIEW_ITEM)
	{
		XCALL(0x007A5700);
	};

	zCView(int pA, int pB, int pC, int pD, zTviewID pE = VIEW_ITEM)
	{
		zView(pA,pB,pC,pD,pE);
	};
	
	void Close(void)
	{
		XCALL(0x007A6E30);
	};
	
	void ClrPrintwin(void)
	{
		XCALL(0x007AA140);
	};
	
	void Create(zSTRING& background, zTViewFX fx0, zTViewFX fx1, float unk0, int unk1)
	{
		XCALL(0x007A6810);
	};
	
	void Dialog(int x, int y, zSTRING& text_, float time, zCOLOR* color)
	{
		XCALL(0x007A8D40);
	};
	
	void DialogCX(int y, zSTRING& text_, float time, zCOLOR* color)
	{
		XCALL(0x007A8E10);
	};
	
	void DialogCXY(zSTRING& text_, float time, zCOLOR* color)
	{
		XCALL(0x007A8F60);
	};
	
	void DialogCY(int x, zSTRING& text_, float time, zCOLOR* color)
	{
		XCALL(0x007A8E70);
	};
	
	void DialogMessage(zSTRING& headline, zSTRING& text_, float time, zCOLOR* color)
	{
		XCALL(0x007A8FB0);
	};
	
	void DialogMessageCXY(zSTRING& headline, zSTRING& text_, float time, zCOLOR* color)
	{
		XCALL(0x007A9240);
	};
	
	int FontSize(zSTRING & pA)
	{
		XCALL(0x007A9A10);
	};
	
	int FontY(void)
	{
		XCALL(0x007A99F0);
	};
	
	void Init(int pA, int pB, int pC, int pD, zTviewID pE = VIEW_ITEM)
	{
		XCALL(0x007A5B20);
	};
	
	void Init(int pA, int pB, zSTRING & pD, zTviewID pE)
	{
		XCALL(0x007A5B20);
	};
	
	void Init(void)
	{
		XCALL(0x007A5990);
	};
	
	void InsertBack(zSTRING const & pA)
	{
		XCALL(0x007A6130);
	};
	
	void InsertBack(zCTexture*)
	{
		XCALL(0x007A60F0);
	};
	
	void InsertItem(zCView* item, int StayOnTop = FALSE)
	{
		if(!childs.IsIn(item))
			InsertItm(item,StayOnTop);
	};
	
	void InsertItm(void* Element, int StayOnTop = FALSE)
	{
		XCALL(0x007ABAD0);
	};
	
	zCOLOR GetColor(void)
	{
		XCALL(0x007A6090);
	};
	
	void GetExtends(int & x, int & y, int & cx, int & cy)
	{
		XCALL(0x007A7860);
	};
	
	void GetPixelExtends(float & x, float & y, float & cx, float & cy)
	{
		XCALL(0x007A7910);
	};
	
	void GetPixelPos(int & x, int & y)
	{
		XCALL(0x007A76C0);
	};
	
	void GetPixelSize(int & x, int & y)
	{
		XCALL(0x007A7830);
	};
	
	void GetPos(int & x, int & y)
	{
		XCALL(0x007A7660);
	};
	
	void GetScreenExtends(int & x, int & y, int & cx, int & cy)
	{
		XCALL(0x007A78A0);
	};
	
	void GetSize(int & x, int & y)
	{
		XCALL(0x007A7810);
	};
	
	void Move(int pA, int pB)
	{
		XCALL(0x007A76E0);
	};
	
	void Open(void)
	{
		XCALL(0x007A6C00);
	};
	
	void Print(int p1, int p2, const zSTRING & p3)
	{
		XCALL(0x007A9A40);
	};
	
	void PrintCX(int pA, const zSTRING & pB)
	{
		XCALL(0x007A9E50);
	};
	
	void PrintCXY(zSTRING const & pA)
	{
		XCALL(0x007AA030);
	};
	
	void PrintCY(int pA, const zSTRING & pB)
	{
		XCALL(0x007A9F40);
	};
	
	void PrintMessage( const zSTRING & pA, const zSTRING & pB, float pC, zCOLOR & pD)
	{
		XCALL(0x007A8140);
	};
	
	void PrintMessageCXY(const zSTRING & pA, const zSTRING & pB, float pC, zCOLOR & pD)
	{
		XCALL(0x007A8450);
	};
	
	void PrintWin(const zSTRING & text)
	{
		XCALL(0x007AA8D0)
	};
	
	void PrintTimed(int x, int y, const zSTRING & text, float time, zCOLOR* color)
	{
		XCALL(0x007A7D20)
	};
	
	void PrintTimedCX(int y, const zSTRING & text, float time, zCOLOR* color)
	{
		XCALL(0x007A7DB0)
	};
	
	void PrintTimedCY(int x, const zSTRING & text, float time, zCOLOR* color)
	{
		XCALL(0x007A7F00)
	};
	
	void PrintTimedCXY(const zSTRING & text, float time, zCOLOR* color)
	{
		XCALL(0x007A7FC0)
	};
	
	void RemoveItem(zCView* item)
	{
		if(childs.IsIn(item))
			RemoveItm(item);
	};
	
	void RemoveItm(void* Element)
	{
		XCALL(0x007ABD10);
	};
	
	void Render(void)
	{
		XCALL(0x007AC210);
	};
	
	void SetAlphaBlendFunc(const zTRnd_AlphaBlendFunc & p1)
	{
		XCALL(0x007A6070);
	};
	
	void SetAutoScroll(float p1)
	{
		XCALL(0x007A5F20);
	};
	
	void SetColor(const zCOLOR & p1)
	{
		XCALL(0x007A6080);
	};
	
	void SetFont(const zSTRING & p1)
	{
		XCALL(0x007A9920);
	};
	
	void SetFontColor(const zCOLOR & p1)
	{
		XCALL(0x007A9910);
	};
	
	void SetFlags(int p1)
	{
		XCALL(0x007A60A0);
	};
	
	void SetPos(int pA, int pB)
	{
		XCALL(0x007A75B0);
	};
	
	void SetPosByCentre(zVec2D vt)
	{
		SetPos(vt[0] - vsizex / 2, vt[1] - vsizey / 2);
	}

	void SetSize(int pA, int pB)
	{
		XCALL(0x007A77A0);
	};
	
	void SetTransparency(int pA)
	{
		XCALL(0x007A6060);
	};
	
	void Top(void)
	{
		XCALL(0x007A6790);
	};

	static void SetMode(int,int,int,HWND*)
	{
		XCALL(0x007ABDB0);
	};

	// ----------------------- AST -----------------------

	// 0x007A9B10 private: void __thiscall zCView::PrintChars(int,int,class zSTRING const &)
	// 0x007A9A40 public: void __thiscall zCView::Print(int,int,class zSTRING const &)
	// [AST]
	zCViewText*	CreateText_AST	(int x, int y, const zSTRING& s);
	void		PrintChars_AST	(int x, int y, const zSTRING& s);
	void		Print_AST		(int x, int y, const zSTRING& s);
	// [/AST]
};


class oCView : public zCView
{
public:
	oCView()
	{
		zCView::zView();
	};
	oCView(int x, int y, int vx, int vy, zTviewID nID = VIEW_ITEM)
	{
		zCView::zView(x, y, vx, vy, nID);
	};
	virtual ~oCView()
	{

	};
};


class zCViewProgressBar : public zCView	
{
public:
	zCView* bar;

	int		minStep;	
	int		percent;
	
	zSTRING	text;
	time_t 	start_time;
	zCList<zTProgressRange> rangeList;
public:
	
	virtual ~zCViewProgressBar()
	{
		XCALL(0x0046EBE0);
	};

	virtual void Init(void)
	{
		XCALL(0x0046ED40);
	};

	virtual void HandleChange(void)
	{
		XCALL(0x0046F190);
	};

	virtual void Draw(void)
	{
		XCALL(0x0046F300);
	};

	zCViewProgressBar(int x1,int y1,int x2,int y2,zTviewID viewID = VIEW_ITEM)
	{
		zViewProgressBar(x1,y1,x2,y2,VIEW_ITEM);
	};

	void zViewProgressBar(int x1,int y1,int x2,int y2,zTviewID viewID = VIEW_ITEM)
	{
		XCALL(0x46E9D0);
	};

	float CalcPercentOf(float,float,float)
	{
		XCALL(0x0046EEA0);
	};

	void SetPercent(int,zSTRING)
	{
		XCALL(0x0046EEC0);
	};

	void SetRange(int,int)
	{
		XCALL(0x0046F340);
	};

	void ResetRange(void)
	{
		XCALL(0x0046F400);
	};

	void SetMinimumStep(int step)
	{
		minStep = (step>=1 && step<100)?step:1;
	};
};


class zCViewWindow : public zCView
{

public:
	zCViewWindow(int x1,int y1,int x2,int y2,zTviewID itemid = VIEW_ITEM){XCALL(0x00501500)};
	~zCViewWindow(){XCALL(0x005015A0)};
};




