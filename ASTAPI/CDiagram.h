#pragma once

class CDiagram
{
	static bool bVisible;
	static bool bEnabled;
	struct cGF
	{
		cGF(int,int*,zSTRING,zCOLOR);

		int*	nVal;
		int		nDelay;
		float	fLim;
		zSTRING sName;
		zCOLOR  mColor;

		struct UNIT
		{
			UNIT(int,int);
			int nTime;
			int nVal;
		};

		int nPass;
		zCArray<UNIT*> arrUnits;

		CTimer T;
		int  GetPoint(int);
		void Attach();
		void Draw();
	};

	static zCArray<cGF*> ff;
	static void Draw();

public:
	
	ASTAPI	static void Register(int,int*,zSTRING,zCOLOR);
			static void Attach();

	ASTAPI	static int SwitchEnable();
	ASTAPI	static int SwitchVisible();
};