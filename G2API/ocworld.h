#pragma once

#include "zcworld.h"

class oCNpc;
class oCItem;
class oCVob;

typedef zCListSort<zCVob>		oTVobList;
typedef zCListSort<oCNpc>		oTVobListNpcs;
typedef zCListSort<oCItem>		oTVobListItems;

class oCWorld : public zCWorld
{
public:
	zCLASS(oCWorld)
	
	zSTRING					worldFilename;

	
	zSTRING					worldName;

	oTVobList*				voblist;
	oTVobListNpcs*			voblist_npcs;
	oTVobListItems*			voblist_items;
public:

	virtual zCClassDef* _GetClassDef(void)const																	{XCALL(0x0077EF40)};
	virtual			~oCWorld()																					{XCALL(0x0077EFE0)};

	virtual oCVob*	CreateVob		(const zTVobType type, const int index)										{XCALL(0x0077F3F0)};
	
	
	
	
	virtual void	Archive			(zCArchiver &arc)															{XCALL(0x0077F610)};
	virtual void	Unarchive		(zCArchiver &arc)															{XCALL(0x0077F860)};
	
	virtual BOOL	LoadWorld		(const zSTRING& fileName, const zTWorldLoadMode loadMode)					{XCALL(0x0077FB40)};
	virtual BOOL	SaveWorld		(const zSTRING& fileName, const zTWorldSaveMode saveMode, 
									 const BOOL	writeBinary=FALSE, const BOOL _saveLevelMesh=FALSE)				{XCALL(0x0077FA50)};
	
	
	
	virtual zCTree<zCVob>*	AddVobAsChild		(zCVob *childVob, zCTree<zCVob>* parentVob)						{XCALL(0x0077FE30)};
	virtual void			RemoveVob			(zCVob *vob)													{XCALL(0x007800C0)}; 

	virtual void			InsertVobInWorld	(zCVob *vob)													{XCALL(0x00780330)};

	virtual void			EnableVob			(zCVob* vob, zCVob* papa = NULL)								{XCALL(0x00780340)};
	virtual void			DisableVob			(zCVob* vob)													{XCALL(0x00780460)};

	virtual zCVob*			SearchVob			(zCVob *vob					, zCTree<zCVob>* vobNode=0)			{XCALL(0x00780570)};
	virtual zCVob*			SearchVobByID		(const unsigned long vobID	, zCTree<zCVob>* vobNode=0)			{XCALL(0x007805C0)};
	virtual zCVob*			SearchVobByName		(const zSTRING& vobName)										{XCALL(0x00780610)};
	virtual void			SearchVobListByName	(const zSTRING& vobName	, zCArray<zCVob*>& resultVobList)		{XCALL(0x007806C0)}; 

	virtual void			TraverseVobList		(zCVobCallback &callback, void *callbackData=0)					{XCALL(0x00780830)};

	oTVobList*				GetVobList			()																{ return voblist; };
	oTVobListNpcs*			GetVobListNpcs		()																{ return voblist_npcs; };
	oTVobListItems*			GetVobListItems		()																{ return voblist_items; };			

	virtual void			DisposeWorld		()																{XCALL(0x00780D50)}; 
	virtual void			DisposeVobs			()																{XCALL(0x00780BD0)};

	zSTRING					GetWorldName		(void)															{ return worldName; };
	zSTRING					GetWorldFilename	(void)															{ return worldFilename; };
	
	void					oWorld				(void)															{XCALL(0x0077ED80)};
	oCWorld										(void)															{oWorld();};
	
	oCVob*					CreateVob			(zTVobType,zSTRING const&)										{XCALL(0x0077F240)};
	void					ClearNpcPerceptionVobLists(void)													{XCALL(0x00780870)};
	void __fastcall			InsertInLists		(zCVob*)														{XCALL(0x007808B0)};
	void __fastcall			RemoveFromLists		(zCVob*)														{XCALL(0x00780990)};
};



