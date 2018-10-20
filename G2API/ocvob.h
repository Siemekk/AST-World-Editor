#pragma once

#include "zcvob.h"

enum oTSndMaterial;
class oCAIVobMove;




enum oTSndMaterial
{
	SND_MAT_WOOD,
	SND_MAT_STONE,
	SND_MAT_METAL, 
	SND_MAT_LEATHER,
	SND_MAT_CLAY,
	SND_MAT_GLAS 
};

const zSTRING SndMaterialName[6] =
{
	"WOOD",
	"STONE",
	"METAL",
	"LEATHER",
	"CLAY",
	"GLAS"	
};

class oCVob : public zCVob
{
public:
	zCLASS(oCVob);
	static zCClassDef			*classDef;
public:
	virtual zCClassDef* _GetClassDef				(void)const			{XCALL(0x0077B6C0);};
	virtual void			Init					()					{XCALL(0x0077B720);};

	virtual void			ShowDebugInfo			(zCCamera *camera)	{XCALL(0x0077B8D0);};
	virtual int				GetInstance				()					{XCALL(0x0077D2E0);};
	virtual zSTRING			GetInstanceName			()					{XCALL(0x0077D2F0);};

	virtual BOOL			IsOwnedByGuild			(int guild)			{ return FALSE; };
	virtual BOOL			IsOwnedByNpc			(int instance)		{ return FALSE;	};

	virtual BOOL			DoFocusCheckBBox		()					{ return FALSE; };

	virtual oCAIVobMove*	GetAIVobMove			()					{XCALL(0x0077D5F0);};

	
	
	
	virtual void			GetSoundMaterial_AM		(int &med2, oTSndMaterial &mat2, int damage) {};
	virtual	void			SetSoundMaterial		(oTSndMaterial mat)	{};
	virtual oTSndMaterial	GetSoundMaterial		()					{ return SND_MAT_WOOD; };

	
	
	

	virtual	void			Archive					(zCArchiver &arc)	{XCALL(0x0077D380);};
	virtual	void			Unarchive				(zCArchiver &arc)	{XCALL(0x0077D390);};

	
	
	
	virtual int				GetCSStateFlags			()					{ XCALL(0x00711400) };
	virtual ~oCVob									()					{XCALL(0x0077B710);};
public:
	void oVob(void)
	{
		XCALL(0x0077B6A0);
	};

	oCVob(void)
	{
		oVob();
	};

	static void ClearDebugList(void)
	{
		XCALL(0x0077B730);
	};

	static void ShowVobDebugInfo(zCCamera*)
	{
		XCALL(0x0077B770);
	};

	int GetShowDebug(void)
	{
		XCALL(0x0077B7A0);
	};

	void ToggleShowDebug(void)
	{
		XCALL(0x0077B7D0);
	};

	void SetShowDebug(int)
	{
		XCALL(0x0077B850);
	};

	int HasNpcEnoughSpace(zVEC3&)
	{
		XCALL(0x0077C3C0);
	};

	int HasEnoughSpace(zVEC3&)
	{
		XCALL(0x0077C6B0);
	};

	int SearchNpcPosition(zVEC3&)
	{
		XCALL(0x0077C860);
	};

	int SearchFreePosition(zVEC3&,zCVob*)
	{
		XCALL(0x0077CCB0);
	};

	void SetOnFloor(zVEC3&)
	{
		XCALL(0x0077D0E0);
	};

	int GetFloorPosition(zVEC3&)
	{
		XCALL(0x0077D130);
	};

	int GetFloorPositionWithVob(zVEC3&,zCVob*&)
	{
		XCALL(0x0077D200);
	};

	void StartParticleEffects(zCTree<zCVob>*)
	{
		XCALL(0x0077D3A0);
	};
	// [AST]
	int SearchNpcPosition_AST(zVEC3&/*, BOOL*/);
	// [/AST]
};

