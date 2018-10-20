#pragma once


#include "ztypes3d.h"

class zCFileBIN;
class zCMesh;
class zCPolygon;


struct zTBSphere3D 
{
	zVEC3 center;
	float radius;

	int IsIntersecting(zVEC3 const&,zVEC3 const&)const 
	{
		XCALL(0x00543FD0);
	};

	int IsIntersecting( zTBSphere3D const&)const 
	{
		XCALL(0x005440E0);
	};

	int ClassifyPlane( zTPlane)const 
	{
		XCALL(0x005441A0);
	};

	void Draw( zCOLOR const&)const 
	{
		XCALL(0x005441F0);
	};
};

struct zTBBox2D
{
	zVEC2		vMin;
	zVEC2		vMax;

	zTBBox2D(void)
	{
		XCALL(0x00537950);
	};

	int Classify( zTBBox2D const&)const 
	{
		XCALL(0x00546B10);
	};

	void ClipToBBox2D( zTBBox2D const&)
	{
		XCALL(0x00546BC0);
	};

	void Draw(void)const 
	{
		XCALL(0x00546C10);
	};
};


struct zTBBox3D 
{
	zVEC3		mins;	
	zVEC3		maxs;	


	void AddPoint(zVEC3 const&)
	{
		XCALL(0x0052CD90);
	};

	zTBBox3D( zTBBox3D const&)
	{
		XCALL(0x0052F6B0);
	};

	void Init(void)
	{
		XCALL(0x0053AB70);
	};

	zTBBox3D(void)
	{
		XCALL(0x00540E50);
	};

	void SetMaximumBox(void)
	{
		XCALL(0x00544510);
	};

	float GetVolume(void)const 
	{
		XCALL(0x00544530);
	};

	void CalcGreaterBBox3D( zTBBox3D const&)
	{
		XCALL(0x00544550);
	};

	void ClipToBBox3D( zTBBox3D const&)
	{
		XCALL(0x005445B0);
	};

	zSTRING GetDescription(void)const 
	{
		XCALL(0x00544630);
	};

	void SetByDescription(zSTRING&)
	{
		XCALL(0x00544C40);
	};

	void Transform(zMAT4 const&, zTBBox3D&)const 
	{
		XCALL(0x00544F10);
	};

	void UnTransform(zMAT4 const&, zTBBox3D&)const 
	{
		XCALL(0x00545020);
	};

	int IsIntersecting(zVEC3 const&,zVEC3 const&,float&,float&)const 
	{
		XCALL(0x00545370);
	};

	int IsIntersectingSweep(zVEC3 const&, zTBBox3D const&,float&)const 
	{
		XCALL(0x005454E0);
	};

	int IsIntersectingSweep( zTBBox3D const&, zTBBox3D const&, zTBBox3D const&,float&)const 
	{
		XCALL(0x00545680);
	};

	int IsTrivIn( zTBBox3D const&)const 
	{
		XCALL(0x00545700);
	};

	int IsTrivInLine(zVEC3 const&,zVEC3 const&)const 
	{
		XCALL(0x00545760);
	};

	int Classify( zTBBox3D const&)const 
	{
		XCALL(0x00545840);
	};

	zVEC3 GetNearestPoint( zTPlane const* const)const 
	{
		XCALL(0x00545900);
	};

	void Scale(float)
	{
		XCALL(0x00545BF0);
	};

	void Scale(zVEC3 const&)
	{
		XCALL(0x00545C30);
	};

	float GetMinExtent(void)const 
	{
		XCALL(0x00545C80);
	};

	zTBSphere3D GetSphere3D(void)const 
	{
		XCALL(0x00545CC0);
	};

	int TraceRay(zVEC3 const&,zVEC3 const&,zVEC3&)const 
	{
		XCALL(0x00545D40);
	};

	void Draw( zCOLOR const&)const 
	{
		XCALL(0x00545EE0);
	};

	void GetCornerPoints(zVEC3*)const 
	{
		XCALL(0x00546240);
	};

	float GetScreenSize(void)const 
	{
		XCALL(0x005463B0);
	};

	zTPlaneClass ClassifyToPlane( zTPlane const&)const 
	{
		XCALL(0x005464D0);
	};

	zTPlaneClass ClassifyToPlane( zTPlane const&,int)const 
	{
		XCALL(0x005465C0);
	};

	int ClassifyToPlaneSides( zTPlane const&)const 
	{
		XCALL(0x005467E0);
	};

	int ClassifyToPlaneSides( zTPlane const&,int)const 
	{
		XCALL(0x005468B0);
	};

	void SaveBIN(zCFileBIN&)
	{
		XCALL(0x00546AD0);
	};

	void LoadBIN(zCFileBIN&)
	{
		XCALL(0x00546AF0);
	};

	zVEC3 GetCenterFloor(void)const 
	{
		XCALL(0x0054E040);
	};

	zVEC3 GetCenter(void)const 
	{
		XCALL(0x0054E7A0);
	};

	void InitZero(void)
	{
		XCALL(0x0055F3D0);
	};

	int IsIntersecting( zTBSphere3D const&)const 
	{
		XCALL(0x005D4F70);
	};

	int IsIntersecting( zTBBox3D const&)const 
	{
		XCALL(0x006039C0);
	};
};


class zCOBBox3D
{
public:
	zVEC3				m_vCenter;		
	zVEC3				m_vAxisX;		
	zVEC3				m_vAxisY;		
	zVEC3				m_vAxisZ;		
	zVEC3				m_vExtent;		
	zCList<zCOBBox3D>	m_lstHierarchy;	
	static zMAT4 trafoB2ToThis;
	
	~zCOBBox3D(void)
	{
		XCALL(0x00546CE0);
	};

	void Draw(int, zCOLOR)
	{
		XCALL(0x00546D70);
	};

	void BuildOBB(int,zCPolygon**,int)
	{
		XCALL(0x005479C0);
	};

	void BuildRec(int,zCPolygon**,int)
	{
		XCALL(0x005483F0);
	};

	void BuildOBBTree(zCMesh*,int)
	{
		XCALL(0x00548720);
	};

	void BuildOBBTree(int,zCPolygon**,int)
	{
		XCALL(0x00548760);
	};

	int TestIntersectionOBB(zCOBBox3D const*)const 
	{
		XCALL(0x00548770);
	};

	int TestIntersectionTreeRec(zCOBBox3D const*)const 
	{
		XCALL(0x00549010);
	};

	int TestIntersectionTree(zCOBBox3D const*,zMAT4 const&)const 
	{
		XCALL(0x005490F0);
	};

	int TraceRay(zVEC3 const&,zVEC3 const&,zVEC3&)const 
	{
		XCALL(0x00549120);
	};

	int CheckOBBPolyIntersection(zCPolygon*,zMAT4 const&)const 
	{
		XCALL(0x005492F0);
	};

	zTBBox3D GetBBox3D(void)const 
	{
		XCALL(0x00549590);
	};

	void SetByBBox3D( zTBBox3D const&)
	{
		XCALL(0x00549790);
	};

	void Transform(zMAT4 const&)
	{
		XCALL(0x00549890);
	};

	zCOBBox3D& operator=(zCOBBox3D const&)
	{
		XCALL(0x005499F0);
	};

	void SaveBIN(zCFileBIN&)
	{
		XCALL(0x00549B40);
	};

	void LoadBIN(zCFileBIN&)
	{
		XCALL(0x00549BD0);
	};
};