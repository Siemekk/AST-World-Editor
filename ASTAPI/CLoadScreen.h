#pragma once

class CLoadScreen
{
	static zCArray <CLoadScreen*>	m_arrLoadScreen;
	static zSTRING					m_sBackTexture;

	zSTRING wldName;
	zCArray <zSTRING> m_arrScreenName;
	zCArray <zSTRING> m_arrHint;

	 CLoadScreen (zSTRING wldName);
	~CLoadScreen ();

	static zINT32 GetWorldIndex (zSTRING worldName);

public:

	ASTAPI static zVOID SetBackTexture	(zSTRING texName);
	ASTAPI static zVOID AddLoadScreen	(zSTRING worldName, zSTRING texName);
	ASTAPI static zVOID AddHint			(zSTRING worldName, zSTRING hintText);
	ASTAPI static zVOID ClearDatas		();
};
