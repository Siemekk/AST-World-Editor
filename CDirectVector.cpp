#include "AST.h"
#include "CDirectVector.h"

CDirectVector::CDirectVector()
{
	vtRight = 0;
	vtPos	= 0;
	vtAt	= 0;
	vtUp	= 0;
}

CDirectVector::CDirectVector(zCVob* vob)
{
	vtPos		= vob->GetPositionWorld		();
	vtRight		= vob->GetRightVectorWorld	();
	vtUp		= vob->GetUpVectorWorld		();
	vtAt		= vob->GetAtVectorWorld		();
}

/*
	operator [] 0 - vtAt, 1 - vtUp, 2 - vtRight, 3 - vtPos
*/
zVEC3& CDirectVector::operator[](int i)
{
	if(i == 0)
		return vtAt;
	else if(i == 1)
		return vtUp;
	else if(i == 2)
		return vtRight;
	else
		return vtPos;
}