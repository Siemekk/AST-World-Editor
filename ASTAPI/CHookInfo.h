#pragma once

typedef void	*HFUNC;
typedef int		PROTECT;

struct CHookInfo
{
	HFUNC	Pointer;
	HFUNC	Detour;
	HFUNC	Original;
	PROTECT Protected;
};