#pragma once

#include "zcview.h"

class oCViewGothicProgressBar : public zCViewProgressBar
{
	int progressbar_sizex;
public:
	oCViewGothicProgressBar(int x1,int y1,int x2,int y2,zTviewID itemid = VIEW_ITEM) : zCViewProgressBar(x1,y1,x2,y2,itemid) {  };

	virtual ~oCViewGothicProgressBar()
	{
		XCALL(0x006C2610);
	};

	virtual void Init(void)
	{
		XCALL(0x0043D2B0);
	};

	virtual void HandleChange(void)
	{
		XCALL(0x0043D2F0);
	};
};

class oCViewProgressBar : public zCViewProgressBar
{
public:
	oCViewProgressBar(int x1,int y1,int x2,int y2,zTviewID itemid = VIEW_ITEM) : zCViewProgressBar(x1,y1,x2,y2,itemid) {  };
	virtual ~oCViewProgressBar() {};
	virtual void Init();
	virtual void HandleChange();		
protected:
	int progressbar_sizex;
};