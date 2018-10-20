#pragma once

#include "ztypes.h"
#include "zcview.h"
class zCWorld;
class zCParser;

enum 
{ 
	zCON_TYPE_INT,
	zCON_TYPE_FLOAT,
	zCON_TYPE_STRING,
	zCON_TYPE_STRINGP
};

const int zCON_MAX_EVAL = 15;

class zCConDat
{
public:
	zCConDat						(const zSTRING &h, const zSTRING &s, int t, void *adr, int ele = 1)
	{
		XCALL(0x00781990);
	};

	zCConDat						(const zSTRING &h, const zSTRING &s, int param)
	{
		XCALL(0x00781BB0);
	};
	
	zSTRING hint;
	zSTRING name;
	int		type;
	void*	adr;
	int		ele;
	BOOL	var;
public:
	zCConDat *next;
};


class zCConsole : public zCInputCallback
{
private:
	zSTRING				id;
	zSTRING				instr;
	zSTRING				savemsg;
	zCArray<zSTRING>	lastcommand;
	int					lastCommandPos;
	int					px,py;
	int					lx,ly;
	int					showmax,skip;
	BOOL				dynsize,var;
	BOOL				autocomplete;
	zList <zCConDat>	list;
	zCView *			conview;
	zCWorld*			world;
	zCParser*			cparser;
	int					edit_index;
	void*				edit_adr;

public:
	
	
	zCWorld* GetWorld() { XCALL(0x007823E0); };

	
	
	zCParser* GetParser(void) { XCALL(0x00782400); };

	
	
	int IsVisible(void) { XCALL(0x00783890); };

	
	
	void Toggle(void) { XCALL(0x007837A0); };

	
	
	void SetDim(int, int)
	{
		XCALL(0x00784F50);
	};
	
	
	void Hide(void) { XCALL(0x007836B0); };

	
	
	void Show(void) { XCALL(0x00783460); };

	
	
	int	Evaluate(const zSTRING& in) { XCALL(0x00784860); };

	
	
	void Eval(const zSTRING& in) { XCALL(0x007844B0); };



	
	
	void Update(void) { XCALL(0x007838E0); };

	
	
	void AddEvalFunc(int (__cdecl *)(zSTRING& zCommand, zSTRING& zReturn)) { XCALL(0x00784F80); };

	
	
	int AutoCompletion(zSTRING& str) { XCALL(0x00782C00); };

	
	
	void Register(const zSTRING& zCommand, const zSTRING& zDesc) { XCALL(0x00782AE0); };
};

