#include "AST.h"

HINSTANCE hModule;
zBOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch( fdwReason )
	{
		case DLL_PROCESS_ATTACH:
			{
				hModule = hinstDLL;
				return TRUE;
			}
	}
	return FALSE;
}
