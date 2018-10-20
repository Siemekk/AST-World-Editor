enum tGizmoMode
{
	MOVE	= 0,
	ROTATE,
	SCALE
};

enum tGizmoFlag
{
	NONE	= 0,
	AXIS_X	= 1 << 0,
	AXIS_Y	= 1 << 1,
	AXIS_Z	= 1 << 2
};

class CGizmo
{
public:
	CGizmo();
	tGizmoMode		mode;
	tGizmoFlag		flags;
	zBOOL bLookAtDirection;
	zBOOL bIsLineSelect;

	void DrawLine	(CLine, zCView*, zVec2D, zCOLOR);
	void DrawMarker	(zCVob*);
	void DrawMove	(zCVob*);
};