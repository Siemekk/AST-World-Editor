#pragma once
#include "CEditCamera.h"
#include "CVobList.h"
class CEditor : public zCInputCallback
{
public:

	zCWorld*		world;
	oCGame*			session;
	CEditCamera*	camera;

	CVobList		voblist;
	CGizmo			gizmo;

	CEditor();
	~CEditor();


	void InitCamera	();
	void LoadWorld	(zSTRING, zCWorld::zTWorldLoadMode);
	CEditCamera* GetCamera() { return camera; };

	void PickVob		();
	void Attach			();
	virtual int HandleEvent		(int);
	void MouseLeft		();
};

extern CEditor* editor;