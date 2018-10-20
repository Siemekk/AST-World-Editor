#pragma once

class CQuiver
{
	static zSTRING   sSlots[2];
	static zCVisual* GetVisual (zSTRING);

public:

	ASTAPI static zVOID InitAll			();
	ASTAPI static zVOID Reload			(oCNpc*);
	ASTAPI static zVOID Call				(oCNpc*);
	ASTAPI static zVOID SetBowSlot		(zSTRING);
	ASTAPI static zVOID SetCrossBowSlot	(zSTRING);
};