#include "AST.h"
#include "CEditCamera.h"
#include "CEditor.h"
CEditor* editor = NULL;

CEditor::CEditor()
{
	// Czyszczenie listy zaznaczonych obiektów
	// Tworzenie wskaŸnika do GIZMO
	
	session = gameMan->GetGame();
	world	= session->world;
	camera	= NULL;
	zCInputCallback::zCInputCallback();
	SetEnableHandleEvent(TRUE);
	SetHandleEventTop();
}


CEditor::~CEditor()
{
}


void CEditor::InitCamera()
{
	if(camera)	delete camera;
	camera = NULL;
	camera = new CEditCamera(session);
}

	 
void CEditor::LoadWorld	(zSTRING name, zCWorld::zTWorldLoadMode mode)
{
	session->world->DisposeWorld	();
	gameMan->InitScreen_Close		();	
	session->OpenLoadscreen(false, "OldWorld.zen");
	if(session->progressBar)		session->progressBar->SetPercent(0, "");
	session->LoadWorld				(name, zCWorld::zTWorldLoadMode::zWLD_LOAD_EDITOR_COMPILED);
	session->EnterWorld				(NULL, TRUE, "");
	if(session->progressBar)		session->progressBar->SetPercent(100, "");
	session->spawnman->DeleteNpc	(player);
	session->SetShowPlayerStatus	(0);
	session->EnvironmentInit		();

	InitCamera();
	CCursor::GetActiveCursor()->Show();
}


int CEditor::HandleEvent(int key)
{
	return TRUE;
}

void CEditor::MouseLeft()
{
	static zBOOL	bDoubleClick	= FALSE;
	static uint32	bNowTime		= CTimer::GetTime();

	if(KeyClick(KEY_MOUSELEFT))
	{
		if(!bDoubleClick)
		{
			if(!gizmo.flags)		// Pick new Vob, only if gizmo is off
				PickVob			();

			bDoubleClick	= TRUE;
			bNowTime		= CTimer::GetTime();
		}
		else
		{
			camera->ComeTo();
			bDoubleClick = FALSE;
		}
	}

	if(CTimer::GetTime() - bNowTime > 250 && bDoubleClick)  
		bDoubleClick = FALSE;
}

void CEditor::PickVob()
{
	int mouseX, mouseY;
	CCursor::GetActiveCursor()->GetPixelPos(mouseX, mouseY);
	zCWorld* wld = session->GetWorld();
	if(wld->PickScene(*zCCamera::activeCam, mouseX, mouseY, 15000))
	{
		zCVob* v = 	wld->traceRayReport.m_pVob; 
		if(v)		voblist.PickVob(v);
	}
}

void CEditor::Attach()
{
	if(camera)	{
		camera->m_aiTimer.Attach();
		camera->KeyHandler();
		camera->Zoom();
		camera->Drag();
		camera->Move();
		//camera->ComeTo();
		camera->Oversee();
	}

	if(KeyClick(KEY_TAB))
		voblist.Clear();

	voblist.Process	(gizmo);
	MouseLeft();
}