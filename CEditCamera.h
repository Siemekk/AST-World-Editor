#pragma once
class CEditCamera
{
public:

	CTimer		m_aiTimer;
	zVEC3		m_vMotion;
	float		multipler;
	zCCamera*	mainCamera;
	int mouseX, mouseY;

	void KeyHandler	();
	void Zoom		();
	void Drag		();
	void Move		();
	void Oversee	();
	void ComeTo		();


	static int GetProjection(zVEC3, int&, int&);
	zBOOL	CamRay(int, int, zVEC3&);
	CEditCamera(oCGame*);
	~CEditCamera(void);
	
	static zTTraceRayReport* CamTraceRay(zVEC3, zVEC3, float);
};

