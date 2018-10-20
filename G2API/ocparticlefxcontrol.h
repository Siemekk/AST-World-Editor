#pragma once

#include "ztypes.h"


class oCParticleControl
{
public:
	
	
	oCParticleControl(zCWorld *)
	{
		XCALL(0x00770040);
	};
	
	
	void CreateNewPFX(zSTRING &)
	{
		XCALL(0x00771700);
	};
};

