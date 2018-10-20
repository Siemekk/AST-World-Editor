#pragma once

#include "zcview.h"




class zCViewStatusBar : public zCView
{
    float			m_fMaxRangeL;
	float			m_fMaxRangeH;
    float			m_fRangeL;
	float			m_fRangeH;
    float			m_fValue;
    float			m_fCurValue;
};



class oCViewStatusBar : public zCViewStatusBar
{
	float			m_fScaleValue;
	zCView*			m_pTempPane;
	zCView*			m_pActivPane;
	zSTRING			m_sBackTexure;
	zSTRING			m_sTempTexure;
	zSTRING			m_sActivTexure;
public:
	
	void Init(int pA, int pB, float pC)
	{
		XCALL(0x0043D620);
	};
	
	void SetTextures(zSTRING & pA, zSTRING & pB, zSTRING & pC, zSTRING & pD)
	{
		XCALL(0x0043D7B0);
	};
	
	void SetValue(float pA)
	{
		XCALL(0x0043DD90);
	};
	
	void SetRange(float pA, float pB)
	{
		XCALL(0x0043DCB0);
	};
	
	void SetMaxRange(float pA, float pB)
	{
		XCALL(0x0043DBA0);
	};
	
	oCViewStatusBar(void)
	{
		oViewStatusBar();
	};
	
	void oViewStatusBar(void)
	{
		XCALL(0x0043D410);
	};
};

