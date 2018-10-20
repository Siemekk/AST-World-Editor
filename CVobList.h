#pragma once
#include "CGizmo.h"

class CVobList
{
public:
	zCArray<zCVob*> m_arrVobs;
	CVobList();
	void PickVob	(zCVob*);
	
	void Process	(CGizmo);


	void Clear();
};