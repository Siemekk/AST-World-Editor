// ������� �������� �������� �������������
#define RGBA(r,g,b,a)			((zUINT32)(zUINT8)(r)|(zUINT32)(zUINT8)(g)<<8|(zUINT32)(zUINT8)(b)<<16|(zUINT32)(zUINT8)(a)<<24)
// ��������� ������� �����
#define EXTRACT_R(rgba)			(rgba		& 0xff)
// ��������� ������� �����
#define EXTRACT_G(rgba)			(rgba >> 8	& 0xff)
// ��������� ����� �����
#define EXTRACT_B(rgba)			(rgba >> 16 & 0xff)
// ��������� ����� �����
#define EXTRACT_A(rgba)			(rgba >> 24 & 0xff)
// ������������������ ������������� �����
#define zSinCos(a, s, c) s = sinf(a); c = cosf(a);

// �������� ����������� ������ � �������� ������������ ��������
#define zpixelx					screen->anx
#define zpixely					screen->any

// ������� ������ ���������� ��� �������� ��������
#define VID_MAX_XDIM GetSystemMetrics(SM_CXSCREEN)
#define VID_MAX_YDIM GetSystemMetrics(SM_CYSCREEN)

// ��������� ����
#define untyped_ptr			...
// �������� ����������� ������������ �����
#define GetSizeArray(a)			(sizeof(a) / sizeof(a[0]))
// �������� ������� ����� � �������� ������
#define sqrA(a)					a*abs(a)

// ��������� ������ �� ������
#define KeyPress(a)				zinput->KeyPressed(a)
// ��������� ����������� ������� �� ������
#define KeyClick(a)				zinput->KeyToggled(a)
// ��������� ������ �� ���������� ������
#define LogicPress(logic)		zinput->GetState(logic)
// ��������� ����������� ������� �� ���������� ������
#define LogicClick(logic)		zinput->IsBindedToggled(logic, zinput->GetKey())
// �������� ���������� �������� ������� ��������� ������
#define AsyncKeyPress(a)		GetAsyncKeyState(a)
// ������� ����� �� �����
#define DrawLineAS(a,b,c,d)		zCLineCache::GetLine()->Line3D(a,b,c,d)
// ���������� ����������� �� 2� �����
#define __MinVal(val, min)		(val < min ? min : val)
// ���������� ������������ �� 2� �����
#define __MaxVal(val, max)		(val > max ? max : val)
// ������������ ����������� ������ ������
#define SCREEN_MAX				8192
// ������� ����������� ������ ������
#define SCREEN_MID				4096


// ����������� � ������� �����
#define __minimize	if (ogame) {														\
						zTRnd_ScreenMode game_scrm = zrenderer->Vid_GetScreenMode();	\
						if(game_scrm == zRND_SCRMODE_FULLSCREEN)						\
							game_scrm = zRND_SCRMODE_WINDOWED;							\
						zrenderer->Vid_SetScreenMode(game_scrm); }
					
// ������������� �� ������ �����
#define __maximize	if (ogame) {														\
						zTRnd_ScreenMode game_scrm = zrenderer->Vid_GetScreenMode();	\
						if(game_scrm == zRND_SCRMODE_WINDOWED)							\
							game_scrm = zRND_SCRMODE_FULLSCREEN;						\
						zrenderer->Vid_SetScreenMode(game_scrm); }

#include "G2API\ztypes.h"

zCOLOR GFX_COLOR[];

const int GFX_WHITE			=	0; 	//
const int GFX_YELLOW		=	1; 	//
const int GFX_LYELLOW		=	2; 	//
const int GFX_GOLD			=	3; 	//
const int GFX_ORANGE		=	4; 	//
const int GFX_DORANGE		=	5; 	//
const int GFX_CARROT		=	6; 	//
const int GFX_RED			=	7; 	//
const int GFX_DRED			=	8; 	//
const int GFX_PINK			=	9; 	//
const int GFX_LPINK			=	10; //
const int GFX_DPINK			=	11; //
const int GFX_MAGENTA		=	12; //
const int GFX_ORCHID		=	13; //
const int GFX_PURPLE		=	14; //
const int GFX_VIOLET		=	15; //
const int GFX_CYAN			=	16; //
const int GFX_AQUA			=	17; //
const int GFX_GREEN			=	18; //
const int GFX_DGREEN		=	19; //
const int GFX_PALEGREEN		=	20; //
const int GFX_OLIVE			=	21; //
const int GFX_BLUE			=	22; //
const int GFX_LBLUE			=	23; //
const int GFX_MBLUE			=	24; //
const int GFX_INDIGO		=	25; //
const int GFX_DBLUE			=	26; //
const int GFX_SKY			=	27; //
const int GFX_STEEL			=	28; //
const int GFX_BROWN			=	29; //
const int GFX_OCHRE			=	30; //
const int GFX_DOCHRE		=	31; //
const int GFX_BEIGE			=	32; //
const int GFX_FLESH			=	33; //
const int GFX_KHAKI			=	34; //
const int GFX_GREY			=	35; //
const int GFX_LGREY			=	36; //
const int GFX_COLDGREY		=	37; //
const int GFX_WARMGREY		=	38; //
const int GFX_BLACK			=	39; //
const int GFX_IVORY			=	40; //

enum zTLgReport
{
	zTLg_Normal		= 0,
	zTLg_CanSee		= 1 << 0,
	zTLg_InSight	= 1 << 1
};