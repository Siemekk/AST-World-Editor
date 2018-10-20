#pragma once

class CScabbard
{
	struct CDummy
	{	CDummy(){}
		CDummy(int,zSTRING);
		int		nFlag;
		zSTRING sSlot;
	};	

	static zCArray<CDummy> arrDummy;
	static zCVisual* GetVisual		(zSTRING);
	static zSTRING	 GetActualSlot	(oCNpc*,oCItem*);

public:

	ASTAPI static void	InitAll			();
	ASTAPI static void	Call			(oCNpc*);
	ASTAPI static void	AddDummy		(int,zSTRING);
	ASTAPI static void	RemoveDummy		(int,zSTRING);
	ASTAPI static void	ClearAllDummy	();
};