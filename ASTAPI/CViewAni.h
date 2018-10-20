#pragma once


class CViewAni : public zCView
{
	zCMaterial* m_pMaterial;

public:

	ASTAPI				 CViewAni		();
	ASTAPI				 CViewAni		(int atL, int atU, int atR, int atD, zTviewID id = VIEW_ITEM);
	ASTAPI void			 SetFPS			(const int&);
	ASTAPI void			 SetTexAni		(const zSTRING&);
	ASTAPI zCTexture*	 GetCurrentTex	();
	ASTAPI				 ~CViewAni		();
};