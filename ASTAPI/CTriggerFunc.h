#pragma once

enum zTTriggerType
{
	zTT_CYCLINEAR,
	zTT_CYCFORCE
};

class CTriggerFunc
{
	static zCArray<CTriggerFunc*> arrFuncs;
	static CTimer m_mTimer;

	ASTAPI CTriggerFunc();
	ASTAPI ~CTriggerFunc();

public:

	//  Callfunc
	LPVOID m_mFunc;
	//  Delay
	int	m_nDelay;
	//  Workmode
	zTTimerMode m_nMode;
	//  Linear or force method
	zTTriggerType m_nType;
	//  Remove this object
	ASTAPI void Destroy();
	//  init new trigger func
	ASTAPI static CTriggerFunc* RegisterFunc(LPVOID, int = 100, zTTimerMode = zTM_LINEAR, zTTriggerType = zTT_CYCLINEAR);
	//  Remove trigger func
	ASTAPI static BOOL	RemoveFunc(LPVOID);
	//  Connect func to main game loop
	ASTAPI static void	Attach();
};