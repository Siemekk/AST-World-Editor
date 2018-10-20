#pragma once

#include "ztypes.h"


class zCTimer
{
public:
	float m_fScale;        
	float m_fFrameTime;      
	float m_fTimer;      
	float frameTimeFloatSecs;  
	float totalTimeFloatSecs;  
	DWORD lastTimer;           
	DWORD frameTime;           
	DWORD totalTime;           
	DWORD minFrameTime;        
	DWORD forcedMaxFrameTime;  
	float	GetFrameTimeF	() const { return m_fFrameTime;	};
	
	zCTimer(void)
	{
		XCALL(0x005F9680);
	}
	
	void SetMotionFactor(float p1)
	{
		XCALL(0x006370B0);
	}
	
	void LimitFPS(int p1)
	{
		XCALL(0x005F9920);
	}
	
	void ResetTimer(void)
	{
		XCALL(0x005F96B0);
	}
	
	void SetFrameTime(float p1)
	{
		XCALL(0x005F9800);
	}
	
	void SetMaxFPS(DWORD p1)
	{
		XCALL(0x005F9890);
	}
	
	int GetFrameTime(){return frameTime;};
	
	static zCTimer* GetTimer()
	{
		return (zCTimer*)0x0099B3D4;
	};
	static void FrameUpdate()
	{
		XCALL(0x005F98A0);
	};
};

#undef __G2EXT_API_HEADER


