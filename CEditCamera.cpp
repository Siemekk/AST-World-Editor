#include "AST.h"
#include "CEditCamera.h"
#include "G2API\ocworldtimer.h"

// ToDo:
// Szybkoœæ kamery powinna byæ ustalana za pomoc¹ pola tekstowego
// Tak samo pozycja, rotacja itp. - tak jak w BLENDERZE
// Naprawiæ LookAt
// Blokowaæ input przy rotacji itp. 
CEditCamera::CEditCamera(oCGame* s)
{
	zCCamera*	nCam = s->GetCamera();
	zCVob*		nVob = new zCVob;


	if(nCam->connectedVob) s->world->RemoveVob(nCam->connectedVob);	//Remove old camera vob

	nVob->SetVobName	("EDITOR_CAMERA_VOB");
	nVob->SetSleeping	(TRUE);
	nVob->SetAI			(NULL);		

	nCam->SetFOV		(75);
	nCam->connectedVob = nVob;

	s->world->AddVob(nVob);
	mainCamera = nCam;

	//FOV FIX
	CConsoleExtender::m_pConsole->Evaluate("SET FOV 75");
	s->GetWorldTimer()->SetTime(8, 00);
	multipler = 0.7f;

}


CEditCamera::~CEditCamera(void)
{
}

void CEditCamera::KeyHandler()
{
	float mouse_X, mouse_Y, mouse_Z;
	zinput->GetMousePos(mouse_X, mouse_Y, mouse_Z);

	m_vMotion[0] = mouse_X * ztimer->m_fFrameTime * 0.300000011920929;
	m_vMotion[1] = mouse_Y * ztimer->m_fFrameTime * 0.300000011920929;
	m_vMotion[2] = mouse_Z * ztimer->m_fFrameTime * 0.300000011920929;
	
	CCursor::GetActiveCursor()->GetPixelPos(mouseX, mouseY);
}


void CEditCamera::Zoom()
{
	zCVob* camVob	= mainCamera->connectedVob;
	zMAT4& trafo	= camVob->trafoObjToWorld;
	float zoomStep;	
	float zoomMul = KeyPress(KEY_LSHIFT) ? 2 : 1;
	zVEC3 move(0);

	if(m_vMotion.GetZ())
	{
		if(m_vMotion.GetZ() <= 0)
			zoomStep = -100.f;
		else
			zoomStep = 100.f;

		move = trafo.GetAtVector() * zoomStep * zoomMul;
		camVob->Move(move[0], move[1], move[2]);
	}
}

void CEditCamera::Drag()
{
	zCVob* camVob	= mainCamera->connectedVob;
	zMAT4& trafo	= camVob->trafoObjToWorld;
	zVEC3 vtRight	= trafo.GetRightVector	();
	zVEC3 vtUp		= trafo.GetUpVector		();
	zVEC3 vMove(0);
	
	if(zinput->GetMouseButtonPressedMid())
	{
		float x, y;
		x = -m_vMotion[0];
		y =  m_vMotion[1];

		vMove = (vtRight *  x) + (vtUp * y);

		camVob->MoveWorld(vMove[0], vMove[1], vMove[2]);
	}
}

void CEditCamera::Move()
{
	// Some variables
	zCVob*	camVob	= mainCamera->connectedVob;
	zVEC3	vtDir	= camVob->GetAtVectorWorld();
	zVEC3	vtRight = camVob->GetRightVectorWorld();
	zVEC3	vtUp	= camVob->GetUpVectorWorld();
	zVEC3	vtMove  = 0;


	if(zinput->GetMouseButtonPressedRight())
	{
		camVob->RotateLocalX(m_vMotion[1] * multipler);
		camVob->RotateWorldY(m_vMotion[0] * multipler);		
	}

	if(m_aiTimer(0, 16, zTM_LINEAR))
	{
		if(KeyPress(KEY_LALT)) return;


		if(KeyPress(KEY_W))
			vtMove = vtMove + vtDir;

		if(KeyPress(KEY_S))
			vtMove = vtMove - vtDir;

		if(KeyPress(KEY_A))
			vtMove = vtMove - vtRight;
		
		if(KeyPress(KEY_D))
			vtMove = vtMove + vtRight;

		if(KeyPress(KEY_SPACE))
			vtMove = vtMove + vtUp;

		if(KeyPress(KEY_LCONTROL))
			vtMove = vtMove - vtUp;

		vtMove *= 5.f;
		if(KeyPress(KEY_LSHIFT))
			vtMove *= 3.9f;

		camVob->MoveWorld(vtMove[0], vtMove[1], vtMove[2]);
	}
}

void CEditCamera::Oversee()
{
	zCVob*		camVob	= mainCamera->connectedVob;
	zCWorld*	world	= ogame->GetWorld();
	static zVEC3 vtRotatePoint;
	static zBOOL bAltPress = FALSE;
	if(KeyPress(KEY_LALT))
	{
		if(m_vMotion[0] || m_vMotion[1])
		{
			if(!bAltPress){
				vtRotatePoint 	= camVob->GetPositionWorld() + camVob->GetAtVectorWorld() * 500;
				bAltPress = TRUE;
			}
			zVEC3 vtRight	= camVob->GetRightVectorWorld() * m_vMotion[0] * multipler;
			zVEC3 vtUp		= camVob->GetUpVectorWorld()	* m_vMotion[1] * multipler;
			zVEC3 vtMove =  camVob->GetPositionWorld() + vtUp + vtRight;
	
			zVEC3 vtPos = camVob->GetPositionWorld();
			zVEC3 vTraceDir = vtRotatePoint;

			float angle = vtPos.GetAngleXZ();
			vTraceDir = vTraceDir.RotateXZ(-angle);
			vTraceDir = vTraceDir.RotateYZ((-m_vMotion[1] * multipler) / DEGREE);
			vTraceDir = vTraceDir.RotateXZ((multipler * m_vMotion[0]) / DEGREE + angle);

			vtMove = vtPos + vtRotatePoint - vTraceDir;

			camVob->SetPositionWorld(vtMove);
			
			
			return;


			// ToDo: Wymaga implementacji - kwestia paru minutek :D 
			//camVob->trafoObjToWorld.LookAt(vtRotatePoint + zVEC3(0, 50, 0));
			vtMove = vtMove.RotateXZ(RAD * 2) * 1;//(camVob->GetPositionWorld().Distance(vtRotatePoint) / 400);
			camVob->SetPositionWorld(vtMove);
		}
	}
	else bAltPress = FALSE;


	if(KeyClick(KEY_NUMPADPLUS))
		multipler += 0.1f;
	else if (KeyClick(KEY_NUMPADMINUS))
		multipler -= 0.1f;

	if(multipler < 0.1)
		multipler = 0.1;

	screen->Print(6000, 200, "Camera factor: " + zSTRING(multipler, 2));
}

zTTraceRayReport* CEditCamera::CamTraceRay(zVEC3 pos, zVEC3 dir, float length)
{
	zCVob*	camVob = ogame->GetCameraVob();
	zCWorld* world = ogame->GetWorld();
	zVEC3 vtDir = dir * length;

	if(world->TraceRayNearestHit(pos, dir, (zCVob*)NULL, 1))
		return &world->traceRayReport;

	return NULL;
}

int CEditCamera::GetProjection(zVEC3 v, int& x, int& y)
{
	// result flags
	BYTE projectResult = zTLg_Normal | zTLg_CanSee | zTLg_InSight;

	zREAL		fPixelPosX	= FLT_MAX;					// projection at x
	zREAL		fPixelPosY	= FLT_MAX;					// projection at y
	zCCamera*	pCamera		= ogame->GetCamera();		// game cam
	zVEC3		vNormVector = pCamera->camMatrix * v;	// cam normal vector

	// recalc projection matrix
	pCamera->Project(&vNormVector, fPixelPosX, fPixelPosY);

	// convert ptojections to relative coordinates
	x = screen->anx(fPixelPosX);
	y = screen->any(fPixelPosY);

	// behind camera
	if (vNormVector[2] <= 0)
		projectResult ^= zTLg_CanSee;

	// if goes beyond screen
	if (x < 0 || x > 8192 || y < 0 || y > 8192) 
		projectResult ^= zTLg_InSight;

	// return flags result
	return projectResult;
}

void CEditCamera::ComeTo()
{
	zVEC3 camNewPos(0);
	if(CamRay(mouseX, mouseY, camNewPos))	
		mainCamera->connectedVob->SetPositionWorld(camNewPos - (mainCamera->connectedVob->GetAtVectorWorld() * 300));
}

zBOOL CEditCamera::CamRay(int x, int y, zVEC3& vtPoint)
{
	if(ogame->world->PickScene(*mainCamera, x, y, 150000))
	{
		vtPoint = ogame->world->traceRayReport.m_vIntersect;
		return true;
	}
	return false;
}