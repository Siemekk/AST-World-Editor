#pragma once

#include "ztypes.h"
#include "macros.h"

struct zTProgressRange
{
	int			m_nIndex;
	float		m_fBoundL;
	float		m_fBoundH;
};



class oCViewProgressBar : public zCView
{
public:
	zCView*					m_pBar;			
	int						m_nDelta;		
	int						m_nCurrentPos;	
	zSTRING					m_sText;		

	zCList<zTProgressRange>	m_lstRange;		

public:
	
	void Draw(void)
	{
		XCALL(0x0046F300);
	};
	
	void HandleChange(void)
	{
		XCALL(0x0046F190);
	};
	
	void Init(void)
	{
		XCALL(0x0046ED40);
	};
	
	void ResetRange(void)
	{
		XCALL(0x0046ED40);
	};
	
	void ResetRange(int pA, zSTRING & pB)
	{
		XCALL(0x0046EEC0);
	};
	
	void ResetRange(int pA, int pB)
	{
		XCALL(0x0046F340);
	};
	
	oCViewProgressBar(int x1, int y1, int x2, int y2, zTviewID ItemID = VIEW_ITEM)
	{
		XCALL(0x0046E9D0);
	};
};
