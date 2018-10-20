#pragma once

#include "zcinputcallback.h"
#include "zcworld.h"


class zCCamera;
class zCAICamera;
class zCVob;
class zCView;




class zCSession : public zCInputCallback
{
public:

	zCCSManager				*csMan;
	zCWorld					*world;
	zCCamera				*camera;
	zCAICamera				*aiCam;
	zCVob					*camVob;
	zCView					*viewport;
	zCSession(void)
	{
		XCALL(0x005DE750);
	};

	virtual int HandleEvent(int)
	{
		XCALL(0x0043D4E0);
	};

	virtual ~zCSession()
	{
		XCALL(0x005DE800);
	};

	virtual void Init(void)
	{
		XCALL(0x005DE910);
	};

	virtual void Done(void)
	{
		XCALL(0x005DE850);
	};

	virtual void Render(void)
	{
		XCALL(0x005DEA10);
	};

	virtual void RenderBlit(void)
	{
		XCALL(0x005DEA60);
	};

	virtual void CamInit(zCVob*,zCCamera*)
	{
		XCALL(0x005DEC80);
	};

	virtual void CamInit(void)
	{
		XCALL(0x005DEA80);
	};

	virtual void SetCamera(zCCamera*)
	{
		XCALL(0x005DE780);
	};

	virtual zCCamera* GetCamera(void)const 
	{
		XCALL(0x005DE790);
	};

	virtual zCAICamera* GetCameraAI(void)const 
	{
		XCALL(0x005DE7A0);
	};

	virtual zCVob* GetCameraVob(void)const 
	{
		XCALL(0x005DE7B0);
	};

	virtual zCView* GetViewport(void)const 
	{
		XCALL(0x005DE7C0);
	};

	virtual zCWorld* GetWorld(void)
	{
		XCALL(0x005DECF0);
	};

	virtual void SaveWorld(zSTRING const&,zCWorld::zTWorldSaveMode,int,int)
	{
		XCALL(0x005DED00);
	};

	virtual int LoadWorld(zSTRING const&,zCWorld::zTWorldLoadMode)
	{
		XCALL(0x005DED10);
	};

	virtual zCCSManager* GetCutsceneManager(void)
	{
		XCALL(0x005DE7D0);
	};

	virtual void SetTime(int,int,int)
	{
		XCALL(0x005DED20);
	};

	virtual void GetTime(int&,int&,int&)
	{
		XCALL(0x005DED30);
	};

	virtual void SetWorld(zCWorld*)
	{
		XCALL(0x005DED40);
	};

	virtual void DesktopInit(void)
	{
		XCALL(0x005DE950);
	};

	virtual void CutsceneSystemInit(void)
	{
		XCALL(0x005DE9E0);
	};

};

