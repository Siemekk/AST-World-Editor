#pragma once
#include "ztypes.h"
#include "zcview.h"
#include "zcvob.h"

const int MAX_ITEMS			= 150;
const int MAX_EVENTS		= 10;
const int MAX_SEL_ACTIONS	= 5;
const int MAX_USERVARS		= 4;
const int MAX_USERSTRINGS	= 10;

enum zTMenuItem {
	MENU_ITEM_UNDEF			= 0,
	MENU_ITEM_TEXT			= 1,
	MENU_ITEM_SLIDER		= 2,
	MENU_ITEM_INPUT			= 3,
	MENU_ITEM_CURSOR		= 4,
	MENU_ITEM_CHOICEBOX		= 5,
	MENU_ITEM_BUTTON		= 6,	
	MENU_ITEM_LISTBOX		= 7	
};

enum zTMenuItemFlags {
	IT_UNDEF			= 0,
	IT_CHROMAKEYED		= 1,
	IT_TRANSPARENT		= 2,
	IT_SELECTABLE		= 4,
	IT_MOVEABLE			= 8,
	IT_TXT_CENTER		= 16,
	IT_DISABLED			= 32,
	IT_FADE				= 64,	

	IT_EFFECTS_NEXT		= 128,	
	IT_ONLY_OUT_GAME	= 256,
	IT_ONLY_IN_GAME		= 512,
	IT_PERF_OPTION		= 1024,
	IT_MULTILINE		= 2048,
	IT_NEEDS_APPLY		= 4096,
	IT_NEEDS_RESTART	= 8192,
	IT_EXTENDED_MENU	= 16384
};

enum zTMenuItemEvent{
	MENU_EVENT_UNDEF	= 0,
	MENU_EVENT_EXECUTE	= 1,
	MENU_EVENT_CHANGED	= 2,
	MENU_EVENT_LEAVE	= 3,
	MENU_EVENT_TIMER	= 4,
	MENU_EVENT_CLOSE	= 5,
	MENU_EVENT_INIT		= 6,
	MENU_EVENT_SEL_PREV	= 7,
	MENU_EVENT_SEL_NEXT	= 8,
	MENU_EVENT_MAX		= 9
};
enum zTMenuItemSelAction {
	SEL_ACTION_UNDEF			= 0,
	SEL_ACTION_BACK				= 1,
	SEL_ACTION_STARTMENU		= 2,
	SEL_ACTION_STARTITEM		= 3,
	SEL_ACTION_CLOSE			= 4,
	SEL_ACTION_CONCOMMANDS		= 5,
	SEL_ACTION_PLAY_SOUND		= 6,
	SEL_ACTION_EXECCOMMANDS		= 7	
};






class zCMenuItem : public zCView {


	friend class zCMenu;

public:

	zCMenuItem(const zSTRING &name){XCALL(0x004DEE20)};

	static		zCMenuItem*		GetByName(const zSTRING &name){XCALL(0x004DE5F0)}; 
	static		zCMenuItem*		Create	 (const zSTRING &name){XCALL(0x004DE7C0)};

	void		AddRef()	{ 
								m_iRefCtr++;
							};

	void		Release()	{ 
								m_iRefCtr--;
								if (m_iRefCtr<=0 && !IsRegisteredCPP()) 
									delete this; 
							};

	int			GetRef()	{ 
								return m_iRefCtr;
							};

	void				SetByScript		(zSTRING &id){XCALL(0x004DF790)};

	virtual	void		InitMenuItem	(){XCALL(0x004E01F0)};

	zTMenuItem			GetType			(){XCALL(0x004E0460)};
	
	zTMenuItemFlags		GetMenuItemFlags()			{ return (zTMenuItemFlags)m_parItemFlags; };
	void				SetMenuItemFlags(int flags)	{ m_parItemFlags=flags; };

	zSTRING&			GetName			(){XCALL(0x004E0680)};
	void				SetName			(const zSTRING &name){XCALL(0x004E0540)};
	void				GetCoords		(int &x0, int &y0, int &x1, int &y1){XCALL(0x004E0690)};  
	void				SetName			(zSTRING &name){XCALL(0x004E06D0)};
	void				SetIsSelectable (zBOOL b){XCALL(0x004E1D10)};
	zBOOL				GetIsSelectable	(){XCALL(0x004E1D60)};
	void				SetIsDisabled	(zBOOL b){XCALL(0x004E1DE0)};
	zBOOL				GetIsDisabled	(){XCALL(0x004E1DF0)};
	void				SetIsVisible	(zBOOL b){XCALL(0x004E1E30)};
	zBOOL				GetIsVisible	(){XCALL(0x004E1E40)};
	void				SetReallyDoNotRender(const zBOOL b) { m_bDontRender = b;	};
	zBOOL				GetReallyDoNotRender()const			{ return m_bDontRender;	};
	
	void				SetIsActive		(zBOOL b){XCALL(0x004E1C00)};
	
	int					GetEventFunc		(const zTMenuItemEvent evNr){XCALL(0x004E1BF0)};
	zTMenuItemSelAction GetSelActionType	(const int num){XCALL(0x004E06A0)};
	zSTRING&			GetSelActionString	(const int num){XCALL(0x004E06B0)};
	zCMenuItem*			GetSelItem			(){XCALL(0x004DE780)};
	void				InitView			(){XCALL(0x004E0280)};

	virtual	zBOOL		ToggleValue		(int step, zBOOL loop=FALSE){XCALL(0x004E0430)};

	virtual		zBOOL	Run				(){XCALL(0x004E14F0)};
	
	virtual zSTRING		GetText			(const int num = 0){XCALL(0x004E0470)};
	virtual void		SetText			(const zSTRING &txt, const int line = 0, zBOOL draw_now = FALSE){XCALL(0x004E0BB0)};
	virtual void		SetText			(const zCArray <zSTRING> lines, zBOOL draw_now = FALSE){XCALL(0x004E12D0)};
	virtual	void		SetMinValue		(float min)			{};
	virtual	void		SetMaxValue		(float max)			{};
	virtual	void		Enter			(){XCALL(0x004E1490)};
	virtual	void		Leave			(){XCALL(0x004E14A0)};	
	virtual	void		Draw			(){XCALL(0x004E18C0)};
	virtual	void		DrawFront		(){XCALL(0x004E18E0)};
	virtual zBOOL		Show			(){XCALL(0x004E0360)};
	virtual zBOOL		Hide			(){XCALL(0x004E03A0)};	
	
	virtual zBOOL		HasBeenCanceled()	{ return FALSE; };

	

	zSTRING m_parFontName;
	zSTRING m_parText			[MAX_USERSTRINGS];
	zSTRING m_parBackPic;
	zSTRING m_parAlphaMode;	
	int		m_parAlpha;
	int		m_parType;
	int		m_parOnSelAction	[MAX_SEL_ACTIONS]	 ;	
	zSTRING m_parOnSelAction_S	[MAX_SEL_ACTIONS];
	zSTRING m_parOnChgSetOption;
	zSTRING m_parOnChgSetOptionSection;	
	int		m_parOnEventAction	[MAX_EVENTS];
	int		m_parPosX;
	int		m_parPosY;
	int		m_parDimX;
	int		m_parDimY;	
	float	m_parSizeStartScale;
	int		m_parItemFlags;
	float	m_parOpenDelayTime;
	float	m_parOpenDuration;
	float   m_parUserFloat		[MAX_USERVARS];
	zSTRING m_parUserString		[MAX_USERVARS];
	int		m_parFrameSizeX;
	int		m_parFrameSizeY;
	zSTRING	m_parHideIfOptionSectionSet;
	zSTRING	m_parHideIfOptionSet;
	int	    m_parHideOnValue;
	
		

	static int  CompareNames( const void *e1 ,const void *e2){XCALL(0x004DE400)};
	static void Startup		(){XCALL(0x004DE470)};
	static void Shutdown    (){XCALL(0x004DE4E0)};


protected:
	zCMenuItem(){XCALL(0x004DF030)};
	virtual ~zCMenuItem(){XCALL(0x004DF1E0)};

	int					GetDimX				(int _dimx){XCALL(0x004E0090)};
	int					GetDimY				(int _dimy){XCALL(0x004E0190)};
	
	virtual void		DrawItems			(){XCALL(0x004E1A20)};
	void				Register			(){XCALL(0x004E0830)};
	void				Unregister			(){XCALL(0x004E09E0)};

public:
	
	void				RegisterByName	(const zSTRING &name)				{ Unregister(); id = name; id.Upper(); Register(); };

protected:

	zBOOL				IsRegistered		(){XCALL(0x004E0B10)};
	void				RegisterCPP			()						{ registeredCPP = TRUE; };
	zBOOL				IsRegisteredCPP		()						{ return registeredCPP; };
	zBOOL				IsInserted			()						{ return inserted; };
	zBOOL				Changed				()						{ return changed;  };

	virtual void		Open				(){XCALL(0x004E03E0)};
	void				Close				(){XCALL(0x004E0410)};
	zBOOL				Opened				()						{ return opened;	};
	zBOOL				Closed				()						{ return closed;	};
	zBOOL				DoesAutoClose		()						{ return (m_parOpenDuration != -1); };	

	
	virtual		zBOOL	HandleEvent			(int key){XCALL(0x004E14B0)};	
	virtual		zBOOL	Input				(int len, zSTRING &ls){XCALL(0x004E1550)};		

	virtual		void	InsertInWin			(zCView *orgWindow){XCALL(0x004DFA90)};
	virtual	    void	RemoveFromWin		(){XCALL(0x004E0030)};
	
	virtual     void	UpdateContent		(){XCALL(0x004E1A50)};	
	virtual     void	UpdateFX			(){XCALL(0x004E1A60)};	
				void	UpdateSize			(){XCALL(0x004E1200)};	

	int				m_iRefCtr;
	zCView*			m_pInnerWindow;	
	zCFont*			m_pFont;
	zCFont*			m_pFontHi;					
	zCFont*			m_pFontSel;
	zCFont*			m_pFontDis;					
	zBOOL			m_bViewInitialized;	
	zBOOL			m_bLeaveItem;
	zBOOL			m_bVisible;
	zBOOL			m_bDontRender;
	zCArray<zSTRING>m_listLines;

	zSTRING			id;
	zBOOL			inserted;
	zBOOL			changed;
	zBOOL			active;
	zBOOL			open;
	zBOOL			close;
	zBOOL			opened;
	zBOOL			closed;
	zBOOL			disabled;
	zCView*			orgWin;
	float			fxTimer;
	float			openDelayTimer;		

	static  zCArraySort <zCMenuItem*> itemList; 

private:

	void	Init	(){XCALL(0x004DF410)};
	
	static  zCMenuItem	*tmp; 
	float	activeTimer;
	zBOOL	registeredCPP;
	zBOOL	firstTimeInserted;

};






class zCMenuItemInput: public zCMenuItem
{	
public:
	zCMenuItemInput(const zSTRING& itemID) {XCALL(0x004E1E80);};
	virtual ~zCMenuItemInput(){XCALL(0x004E2030)};

	virtual	void InitMenuItem(){XCALL(0x004E2180)};

	void	SetValue		(zSTRING _value){XCALL(0x004E20E0)};
	zSTRING GetValue		(){XCALL(0x004E2160)};
	
	virtual void Enter		()			{ zCMenuItem::Enter();canceled=FALSE; };
	virtual void Leave		()			{ zCMenuItem::Leave(); };

	zBOOL	HandleEvent		(int key)	{ return TRUE; };

	zBOOL	HasBeenCanceled	()			{ return canceled; };

	zBOOL	Run				(){XCALL(0x004E2360)};

protected:	

	virtual void InsertInWin(zCView *orgWindow){XCALL(0x004E2330)};

protected:

	zSTRING	value;
	WORD	curPos;
	zBOOL	canceled;
};











class zCMenuItemText: public zCMenuItem
{
public:
	zCMenuItemText(const zSTRING& itemID){XCALL(0x004E26D0)};
	virtual ~zCMenuItemText(){XCALL(0x004E27A0)};	

	virtual	void	InitMenuItem(){XCALL(0x004E3000)};

	virtual void	SetText		(const zSTRING &txt, const int line = 0, zBOOL draw_now = FALSE){XCALL(0x004E34F0)};
	virtual void	SetText		(const zCArray <zSTRING> lines, zBOOL draw_now = FALSE){XCALL(0x004E37B0)};	

	virtual	void	SetEnum		(const zSTRING& enumeration){XCALL(0x004E31C0)};	

	virtual	zBOOL	HandleEvent	(int key){XCALL(0x004E3340)};	

	virtual void	DrawFront	(){XCALL(0x004E2810)};	

protected:	

	void	DrawMultiline(){XCALL(0x004E2BE0)};
	void	FormatMultiline(){XCALL(0x004E2860)};

protected:

	enum { MODE_SIMPLE, MODE_ENUM, MODE_MULTILINE } m_mode;

	zSTRING	m_fullText;		
	int		m_numOptions;	

	int		m_topLine;
	int		m_viewLines;
	int		m_numLines;
	zBOOL	m_unformated;	
};






class zCMenuItemSlider : public zCMenuItem
{
public:
	zCMenuItemSlider(const zSTRING& itemID){XCALL(0x004E3810)};
	virtual ~zCMenuItemSlider(){XCALL(0x004E38B0)};

	virtual	void	InitMenuItem	(){XCALL(0x004E3C50)};

	zCViewWindow*	slider;
	int				slideStep;
	float			sliderValue;		

	int				sliderDimX;

	virtual void	SetIsActive		(zBOOL b)			{ zCMenuItem::SetIsActive(b);SetEnableHandleEvent(b); };	

	void			SetValue		(float value){XCALL(0x004E3F70)};
	float			GetValue		(){XCALL(0x004E3FF0)};

	virtual zBOOL	HandleEvent		(int key)			{ return TRUE; };	
	virtual	zBOOL	ToggleValue		(int step, zBOOL loop=FALSE){XCALL(0x004E38D0)};	

protected:	

	virtual void	InsertInWin		(zCView *orgWindow){XCALL(0x004E3D10)};
	virtual void	RemoveFromWin	(){XCALL(0x004E3EE0)};	

	int sliderPos;				
};






class zCMenuItemButton : public zCMenuItem
{
public:
	zSTRING pic;
	zBOOL   active;

	zCMenuItemButton(const zSTRING& itemID){XCALL(0x004E52D0)};
	virtual ~zCMenuItemButton(){XCALL(0x004E5480)};

	virtual	void	InitMenuItem	(){XCALL(0x004E5530)};

	void			Toggle			(){XCALL(0x004E5700)};
	zBOOL			Run				(){XCALL(0x004E5900)};		

protected:	
	virtual void	InsertInWin		(zCView *orgWindow){XCALL(0x004E5B70)};
	virtual void	RemoveFromWin	(){XCALL(0x004E5BB0)};
};








class zCMenuItemChoice : public zCMenuItem
{
public:
	zCMenuItemChoice(const zSTRING& itemID){XCALL(0x004E4000)};
	virtual ~zCMenuItemChoice(){XCALL(0x004E4060)};

	virtual	void	InitMenuItem	(){XCALL(0x004E51B0)};

	virtual void	InsertInWin		(zCView *orgWindow){XCALL(0x004E48E0)};
	virtual void	RemoveFromWin	(){XCALL(0x004E4AA0)};
	virtual void	Draw			(){XCALL(0x004E4C00)};
	virtual void	DrawFront		(){XCALL(0x004E4C20)};		

	virtual zBOOL ToggleValue(int step, zBOOL loop=FALSE){XCALL(0x004E4080)};


	zCView *winCursor;
	int		option;
	int		optionStart;
	int		curStep;
protected:

	int			SetOptionByString(zSTRING value){XCALL(0x004E4310)};
	zSTRING		GetStringByOption(){XCALL(0x004E4750)};

private:
	int			GetNumOptions	(){XCALL(0x004E4E50)};
	void		Resize			(){XCALL(0x004E4B30)};
	zSTRING		GetText			(const int num){XCALL(0x004E5030)};
	
};

struct zTMenuItemListElement
{
	zSTRING		title;	
	zSTRING		content;		
	zCMenuItem*	contentViewer;

	zTMenuItemListElement() { contentViewer=0; };
};

class zCMenuItemList : public zCMenuItem
{	
public:	

	zCMenuItemList(const zSTRING& itemID){XCALL(0x004E5C70)};
	virtual ~zCMenuItemList(){XCALL(0x004E5CF0)};

	virtual	void	InitMenuItem	(){XCALL(0x004E5E20)};

	virtual zBOOL	Run			(){XCALL(0x004E5D90)};
	virtual zBOOL	Show		(){XCALL(0x004E5E30)};
	virtual zBOOL	Hide		(){XCALL(0x004E5E80)};	
	virtual	void	DrawFront	(){XCALL(0x004E6550)};

	void	DeleteContent(){XCALL(0x004E5EC0)};
	void	InsertEnd	(zTMenuItemListElement& element){XCALL(0x004E5F10)};
	void	InsertFront	(zTMenuItemListElement& element){XCALL(0x004E6120)};	
	
	void	ShowContent			(){XCALL(0x004E6AB0)};

	virtual	void	Enter		(){XCALL(0x004E6520)};
	virtual	void	Leave		(){XCALL(0x004E6530)};

protected:

	virtual void	UpdateContent(){XCALL(0x004E6540)};	

private:

	virtual void	InsertInWin		(zCView *orgWindow){XCALL(0x004E6310)};
	virtual void	RemoveFromWin	(){XCALL(0x004E6470)};
	virtual	zBOOL	HandleEvent		(int key){XCALL(0x004E6860)};	

	void	JumpToNextEntry		(){XCALL(0x004E6C60)};
	void	JumpToPrevEntry		(){XCALL(0x004E6C80)};
	void	JumpToTopEntry		(){XCALL(0x004E6CA0)};
	void	JumpToLastEntry		(){XCALL(0x004E6CC0)};

	zCArray<zTMenuItemListElement> m_list;

	int		m_cur_element;
	int		m_top_element;	
		
	zCView*	m_pInnerWindow2;
	zCView*	m_pViewArrowUp;
	zCView*	m_pViewArrowDn;	
};









enum zTMenuFlags {
	MN_UNDEF			= 0,
	MN_OVERTOP			= 1,
	MN_EXCLUSIVE		= 2,
	MN_NO_ANI			= 4,
	MN_DONTSCALE_DIM	= 8,
	MN_DONTSCALE_POS	= 16,
	MN_ALIGN_CENTER		= 32,
	MN_SHOW_INFO		= 64
};

class zCTimer;
class zCParser;
class zCSoundFX;
class zCMusicTheme;






class zCMenu : public zCInputCallback
{	
	friend class zCMenuItem;
    friend class CGameManager; 

public:
	zCMenu(const zSTRING &name){XCALL(0x004DA610)};		

	
	static	int			CompareNames	( const void *e1 ,const void *e2){XCALL(0x004D9EA0)};

	static	void		SetIsInGame		(zBOOL inGame)		{ inGameMenu = inGame; }; 
	static	zBOOL		IsInGame		()					{ return inGameMenu; };
	

	
	static  zCMenu*		GetActive		(){XCALL(0x004DDD60)};
	static  zCTimer*	GetTimer		()						{ return timer;						};
	static  void		CreateParser	(){XCALL(0x004D9F10)};
	static  zCParser*	GetParser		(){XCALL(0x004DB130)};
	static  void		Startup			(){XCALL(0x004D9F90)};
	static  void		Shutdown		(){XCALL(0x004DA380)};
	static  void		DefineExternal	( zSTRING &s, zBOOL (*Proc)(), int type, int args... ){XCALL(0x004DABB0)};
	static  zCMenu*		Create			(const zSTRING &name){XCALL(0x004DABE0)};	
	static	zCMenu*	    GetByName		(const zSTRING &name){XCALL(0x004DB140)}; 
	
	static  zCCamera*	GetCamera		()						{ return camera;	};
	static  zCWorld *	GetWorld		()						{ return world;		};
	static  void		SetCamera		(zCCamera *cam)			{ camera = cam;		};
	static  void		SetWorld		(zCWorld  *wrld)		{ world  = wrld;	};

	static	void		RegisterFrameCB	( void (*FCB)() )		{ FrameCallback = FCB; };
	static	void		RegisterEnterCB	( void (*ECB)() )		{ EnterCallback = ECB; };
	static  void		RegisterLeaveCB ( void (*LCB)() )		{ LeaveCallback = LCB; };

	
	virtual zBOOL HandleEvent(int key){XCALL(0x004DBB70)};	
	virtual zBOOL HandleEnterItem(zCMenuItem* item){XCALL(0x004DE0D0)};
	virtual zBOOL HandleLeaveItem(zCMenuItem* item){XCALL(0x004DE0E0)};
	virtual zBOOL HandleActivateItem(zCMenuItem* item){XCALL(0x004DE0F0)};
	
	
	virtual zBOOL Run	(){XCALL(0x004DB9A0)};
	virtual	void  Enter	(){XCALL(0x004DB780)};
	virtual	void  Leave	(){XCALL(0x004DB910)};

	void		PrintInformation(zSTRING s){XCALL(0x004DCD00)};

	void		SetBackground	(zSTRING &file)		{ backPic = file;					};
	zBOOL		IsExclusive		()					{ return (flags & MN_EXCLUSIVE);	}; 

	void		RestartMusicTheme(){XCALL(0x004DB760)};

	zCMenuItem*	GetActiveItem	(){XCALL(0x004DDD80)};
	zBOOL		SetActiveItem	(zCMenuItem *item){XCALL(0x004DDE00)};
	int			GetNumberOfActiveItem(){XCALL(0x004DDD90)};
	zSTRING&	GetBackWorld	(){XCALL(0x004DDD10)};
	zSTRING&	GetBackDatFile	(){XCALL(0x004DDD50)};
	zSTRING&	GetName			(){XCALL(0x004DDF60)};

	void        ForceEvent		(zTMenuItemEvent ev,zSTRING &optionValue) {};
	void		ForceSelAction	(const zTMenuItemSelAction selAction, const zSTRING &selAction_S, zCMenuItem *item = 0){XCALL(0x004DBE20)};
	void		SetCursorEnabled(zBOOL b)			{ cursorEn = b; };
	void		Release			(){XCALL(0x004DAB80)};

	
	
	virtual void	Render		(){XCALL(0x004DDC20)};
	virtual void	RedrawItems	(){XCALL(0x004DCCD0)};
	virtual void    HandleFrame (zBOOL render = TRUE){XCALL(0x004DC1C0)};
	virtual void	Activate	(){XCALL(0x004DBFD0)};
	
	

	zSTRING backPic;
	zSTRING backWorld;
	int		posx,posy;
	int		dimx,dimy;	
	int		alpha;
	zSTRING	musicThemeName;
	int		eventTimerUpdateMSec;
	zSTRING itemID[MAX_ITEMS];
	int		flags;	
	int		defaultOutGame;
	int		defaultInGame;

	

	zCViewWindow* m_pWindow;
	zCViewWindow* m_pInnerWindow;

protected:
	zCMenu(){XCALL(0x004DA470)};	
	virtual ~zCMenu(){XCALL(0x004DA750)};
	
	virtual void ScreenInit(){XCALL(0x004DCDE0)};

	
	virtual void ScreenDone(){XCALL(0x004DD9E0)};
	
	
	virtual zBOOL HandleAction	 () {XCALL(0x004DC250)};
	virtual zBOOL HandleSelAction(const zTMenuItemSelAction selAction,const zSTRING &selAction_S, zCMenuItem *item = 0){XCALL(0x004DC430)};
	
	virtual void  SetByScript(const zSTRING &id){XCALL(0x004DB320)};

	void	UpdateWindowGeometry(){XCALL(0x004DC070)};

	zCMenuItem*				InsertItem		(zSTRING &name);	

	void	SetName			(const zSTRING &id){XCALL(0x004DDF70)};
	void	ClearAllEvents	(){XCALL(0x004DB5A0)};
	
	void	Register		(){XCALL(0x004DAE00)};
	void	Unregister		(){XCALL(0x004DB020)};
	zBOOL	IsRegistered	(){XCALL(0x004DB0C0)};
	void	RegisterCPP		()										{ registeredCPP = TRUE;	};
	zBOOL	IsRegisteredCPP	()										{ return registeredCPP;	};

	void	PreviousOption	(){XCALL(0x004DB5C0)};
	void	NextOption		(){XCALL(0x004DB690)};

	
	virtual zBOOL	ExecCommand(const zSTRING &s){XCALL(0x004DCAC0)};

	

	static zCParser*	menuParser;
	static zCTimer*		timer;
	static zCArraySort <zCMenu*> menuList;
	static zCArray	   <zCMenu*> activeList;

	static zCSoundFX	*browseSnd;
	static zCSoundFX	*selectSnd;
	static zCSoundFX	*escSnd;
	static zCVob		*soundSourceVob;

	enum { NONE, BACK, GO, FINISHED } m_exitState;

	zSTRING			name;

	zCMusicTheme*	m_musicTheme;
	int				m_mainSel;
	zBOOL			m_screenInitDone;

	int				m_use_dimx;
	int				m_use_dimy;
	int				m_use_posx;
	int				m_use_posy;	

	zCView*			m_pViewInfo;	
	zCVob*			cursorVob;	

	
	zBOOL			eventOccured[MENU_EVENT_MAX];
	zBOOL			cursorEn;
	zBOOL			noneSelectable;
	zBOOL			registeredCPP;	
	
	int				updateTimer;
	float			fxTimer;
	
	zTMenuItemSelAction forceSelAction;
	zSTRING				forceSelAction_S;
	zCMenuItem*			forceSelActionItem;
	zBOOL				forcedSelAction;	

	zCArray <zCMenuItem *> m_listItems;	

	static void (*FrameCallback)();
	static void (*EnterCallback)();
	static void (*LeaveCallback)();

private:
	void	InitValues		(){XCALL(0x004DA950)};

	static zCWorld*		world;
	static zCCamera*	camera;

	static zBOOL inGameMenu; 
};
