#include "AST.h"
#include "CDirectVector.h"
#include "CEditCamera.h"
#include "CGizmo.h"
zCOLOR gzmColor[3] = 
{ 
	zCOLOR(180, 20, 20, 255), 
	zCOLOR(20, 180, 20, 255), 
	zCOLOR(20, 20, 180, 255)
};
zCOLOR gzm_sColor(220, 220, 75, 255);	// Selected color

CGizmo::CGizmo()
{
	flags = NONE;
	mode = MOVE;
	bLookAtDirection	= FALSE;
	bIsLineSelect		= FALSE;
}

void CGizmo::DrawMarker(zCVob* vob)
{
	int projectionResult;
	int x, y;							
	zVec2D	pos2D;							// Pozycja voba wzglêdem ekranu
	zVec2D	vRight2D;						// Marker right line
	zVec2D  vAt2D;							// Marker forward line
	zVec2D  vUp2D;							// Marker up line
	zVEC3 vt;								// Calculate
	CDirectVector dir(vob);
	
	CEditCamera::GetProjection(dir.vtPos, x, y);
	pos2D = zVec2D(x, y);

	// Calculate Right marker
	vt = dir.vtPos + (dir.vtRight * 50);
	CEditCamera::GetProjection(vt, x, y);
	vRight2D = zVec2D(x, y);
	
	// Calculate up marker
	vt = dir.vtPos + (dir.vtUp * 50);
	CEditCamera::GetProjection(vt, x, y);
	vUp2D = zVec2D(x, y);

	// Calculate forward marker
	vt = dir.vtPos + (dir.vtAt * 50);
	projectionResult = CEditCamera::GetProjection(vt, x, y);
	vAt2D = zVec2D(x, y);

	if(projectionResult & 1)
	{
		screen->Line(pos2D[0], pos2D[1], vRight2D[0], vRight2D[1],	zCOLOR(126, 255, 212, 255));
		screen->Line(pos2D[0], pos2D[1], vUp2D[0], vUp2D[1],		zCOLOR(126, 255, 212, 255));
		screen->Line(pos2D[0], pos2D[1], vAt2D[0], vAt2D[1],		zCOLOR(126, 255, 212, 255));
	}
}

void CGizmo::DrawMove(zCVob* vob)
{
	int mouseX, mouseY;
	int mouseSizeX, mouseSizeY;
	int projectResult;
	int px, py;														// Hlp for projection
	zCVob* camVob		= ogame->GetCamera()->connectedVob;			// Camera connected vob
	zVEC3 direct 		= vob->GetPositionWorld			();			// voblist.GetDirectVectorLocal	();
	zVEC3 camPos 		= camVob->GetPositionWorld		();			// Camera position world
	float camDistance 	= camPos.Distance				(direct);	// Distance between camera and direction
	zBOOL bInvertAxis	[3];	
	CLine gzmLine		[3];	
	zVec2D vobPos_2D;
	projectResult = CEditCamera::GetProjection(direct, px, py);
	vobPos_2D = zVec2D(px, py);
	zVec2D intersecx, intersecy, intersecz;

	for(int i = 0; i < 3; i++)
	{
		static zCView* dot = NULL;
		if(!dot) {
			dot = new zCView;
			dot->SetSize	(zpixelx(15), zpixely(15));
			dot->InsertBack ("circle");
		}

		zVEC3 vtdir;
		if(i == 0) vtdir = vob->GetAtVectorWorld();
		if(i == 1) vtdir = vob->GetUpVectorWorld();
		if(i == 2) vtdir = vob->GetRightVectorWorld();

		
		zVEC3 vtinvertAxis = (vob->GetPositionWorld() + vtdir);
		float vdistx = vtinvertAxis.Distance(camPos);

		bInvertAxis[i] = 0;
		if(camDistance < vdistx)
			bInvertAxis[i] = 1;
		
		float bDist = 0.2f;
		if(bInvertAxis[i])
			bDist = -0.2f;
		
		bDist *= camDistance;
		
		CEditCamera::GetProjection(direct + (vtdir * bDist), px, py);
		zVec2D vtPoint(px, py);
		gzmLine[i] = CLine(vobPos_2D,  vtPoint);	
			
		//Draw dot
		if(dot)
		{
			screen->InsertItem	(dot);
			dot->SetColor		(gzmColor[i]);
			dot->SetPosByCentre	(vtPoint);
			dot->Render			();	
			screen->RemoveItem	(dot);
		}
		
	}

	CCursor::GetActiveCursor()->GetSize(mouseSizeX, mouseSizeY);
	CCursor::GetActiveCursor()->GetPos(mouseX, mouseY);

	if(projectResult & zTLg_CanSee)
	{
		for(int i = 0; i < 3; i++)
			gzmLine[i].Draw(gzmColor[i]);

		CLine cursorLine(mouseX, mouseY, mouseX + mouseSizeX, mouseY + mouseSizeY);
		cursorLine.Draw(zCOLOR(255, 255, 0, 255));

		// Nastêpny krok - sprawdzaæ, czy punkt nale¿y do p³aszczyzny
		if(gzmLine[0].TraceRay(cursorLine, intersecx, 20))
		{
			screen->PrintCX(100, "X: " + intersecx.ToString());
			screen->Print(intersecx[0], intersecx[1], "X");

			
		}
		if(gzmLine[1].TraceRay(cursorLine, intersecx, 20))
		{
			screen->PrintCX(300, "Y: " + intersecx.ToString());
			screen->Print(intersecx[0], intersecx[1], "Y");

		}
		if(gzmLine[2].TraceRay(cursorLine, intersecx, 20))
		{
		
			screen->PrintCX(600, "Z: " + intersecx.ToString());
			screen->Print(intersecx[0], intersecx[1], "Z");

		}
	
	
	
	
	
	
	}
}

void CGizmo::DrawLine(CLine line, zCView* view, zVec2D vPos, zCOLOR color)
{
	screen->InsertItem	(view);
	view->SetPosByCentre(vPos);
	view->Render		();
	screen->RemoveItem	(view);
	line.Draw(color);
}


void CLine::Draw(zCOLOR col)
{
	screen->Line(	coord[0][0], coord[0][1], 
					coord[1][0], coord[1][1], col);
}
