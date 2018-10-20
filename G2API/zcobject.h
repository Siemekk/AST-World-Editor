#pragma once

#include "ztypes.h"

class zCArchiver;
class zCObject;
class zCObject;
class zCArchiver;
class zCWorld;
class zCCSManager;
class zCGameInfo;
class zCEventManager;
class zCWay;
class oCVob;
class oCWorld;
class zCPlayerInfo;
class zFILE;
class zCWaypoint;
class zCSession;


enum zTClassFlags {
	zCLASS_FLAG_SHARED_OBJECTS		= 1<<0,				
	zCLASS_FLAG_TRANSIENT			= 1<<1,				
	zCLASS_FLAG_RESOURCE			= 1<<2,				
};

class zCClassDef
{
public:
	zSTRING						className;
	zSTRING						baseClassName;
	zSTRING						scriptClassName;
	zCClassDef					*baseClassDef;
	zCObject*					( *createNewInstance )( void );
	zCObject*					( *createNewInstanceBackup )( void );
	DWORD						classFlags;
	DWORD						classSize;
	int							numLivingObjects;
	int							numCtorCalled;
	zCObject					**hashTable;
	zCArray<zCObject*>			objectList;			
	WORD						archiveVersion;
	WORD						archiveVersionSum;
	static BOOL					startupFinished;
	static BOOL					showedDialog;
	static zCArraySort<zCClassDef*>*& classDefList;
	static zCClassDef*			classDefSearchDummy;
public:
	static int CompareClassDefNames(void const*,void const*)
	{
		XCALL(0x005A9F80);
	};

	static zCClassDef* GetClassDef(zSTRING const&)
	{
		XCALL(0x005A9FE0);
	};

	static zCClassDef* GetClassDefTypeInsensitive(zSTRING const&)
	{
		XCALL(0x005AA100);
	};

	void Init(void)
	{
		XCALL(0x005AA470);
	};

	~zCClassDef(void)
	{
		XCALL(0x005AA620);
	};

	static void EndStartup(void)
	{
		XCALL(0x005AA7A0);
	};

	zCObject* CreateNewInstance(void)const 
	{
		XCALL(0x005AAB80);
	};

	void OverwriteCreateNewInstance(zCClassDef*)
	{
		XCALL(0x005AAC40);
	};

	void ResetCreateNewInstance(void)
	{
		XCALL(0x005AAC60);
	};

	unsigned short GetClassID(void)
	{
		XCALL(0x005AAC70);
	};

	static zCObject* CreateNewInstanceID(unsigned short)
	{
		XCALL(0x005AACE0);
	};

	unsigned long GetHashIndex(zSTRING const&)
	{
		XCALL(0x005AAD00);
	};

	unsigned long GetHashIndex(zCObject*)
	{
		XCALL(0x005AAD30);
	};

	void InsertHashTable(zCObject*)
	{
		XCALL(0x005AAD60);
	};

	void RemoveHashTable(zCObject*)
	{
		XCALL(0x005AADA0);
	};

	zCObject* SearchHashTable(zSTRING const&)
	{
		XCALL(0x005AADE0);
	};

	float CalcHashTableSpread(void)
	{
		XCALL(0x005AAE70);
	};

	static void ObjectCreated(zCObject*,zCClassDef*)
	{
		XCALL(0x005AAEB0);
	};

	static void ObjectDeleted(zCObject*,zCClassDef*)
	{
		XCALL(0x005AAFD0);
	};

	static void ObjectCreated(zCObject*,int,zCClassDef*)
	{
		XCALL(0x005AB070);
	};

	static void ObjectDeleted(zCObject*,int,zCClassDef*)
	{
		XCALL(0x005AB0B0);
	};

	void ReportLeaks(void)
	{
		XCALL(0x005AB170);
	};

	static void GetLivingObjectsState(int&)
	{
		XCALL(0x005AB590);
	};

	static void CompareLivingObjectsState(int const&)
	{
		XCALL(0x005AB630);
	};

	static void ObjectCreated(zCObject*,zCClassDef*,char const*,int)
	{
		XCALL(0x0065DD10);
	};
	
	static int CompareClassDefNames(zCClassDef* const* t1, zCClassDef* const* t2)
	{
		XCALL(0x005A9F80);
	};

	zSTRING GetName()
	{
		return className;
	};

	void zClassDef(const zSTRING& className, const zSTRING& baseClassName, zCObject* ( *_CreateNewInstance )(), const DWORD classSize, const DWORD classFlags, const WORD arcVers, const zSTRING& scriptClassName="" )
	{
		XCALL(0x005AA8E0);
	};

	zCClassDef(const zSTRING& className, const zSTRING& baseClassName, zCObject* ( *_CreateNewInstance )(), const DWORD classSize, const DWORD classFlags, const WORD arcVers, const zSTRING& scriptClassName="" )
	{
		zClassDef(className,baseClassName,_CreateNewInstance,classSize,classFlags,arcVers,scriptClassName);
	};

	void zClassDef(void)
	{
		XCALL(0x005AA2E0);
	};

	zCClassDef(void)
	{
		zClassDef();
	};
};



#define zCLASS_DECLARATION( className )		\
public: \
	static	zCClassDef*		className::GetStaticClassDef	(void)			{ return &(className::classDef); }; \
	void*					className::operator new			(size_t size)	{ void* ptr = ::operator new(size); zCClassDef::ObjectCreated ((zCObject*)ptr, &className::classDef);	return ptr; }; \
	void					className::operator delete		(void* ptr)		{ zCClassDef::ObjectDeleted ((zCObject*)ptr, &className::classDef); ::operator delete(ptr); }; \
private:									\
	static	zCClassDef		className::classDef;		\
	static	zCObject*		className::_CreateNewInstance	( void );			\
	virtual	zCClassDef*		className::_GetClassDef			( void ) const { return &(className::classDef); };



#define zCLASS_DEFINITION( className, baseClassName, classFlags, archiveVersion ) \
	zCClassDef				className::classDef				( #className, #baseClassName, className::_CreateNewInstance, sizeof(className), classFlags, archiveVersion ); \
	zCObject*				className::_CreateNewInstance	( void )	{ return new className; }



class zCObject
{
public:
	int					refCtr;
	WORD				m_nHashIndex;
	zCObject*			m_pNext;
	zSTRING				m_sNameObj;
	static zCClassDef*	classDef;
public:
	virtual zCClassDef * _GetClassDef(void)const
	{
		XCALL(0x00401EC0);
	};
	virtual void Archive (zCArchiver& arc) {};
	virtual void Unarchive (zCArchiver& arc) {};
	virtual ~zCObject(void)
	{
		XCALL(0x005A8C50);
	};

	void zObject(void)
	{
		XCALL(0x00401D60);
	};
	
	zCObject(void)
	{
		zObject();
	};

	static int CheckInheritance(zCClassDef const*,zCClassDef const*)
	{
		XCALL(0x00476E30);
	};

	static int CheckInheritance(zCObject const*,zCObject const*)
	{
		XCALL(0x005A8E00);
	};

	static int CheckInheritance(zSTRING const&,zSTRING const&)
	{
		XCALL(0x005A8E40);
	};

	static zCObject* CreateNewInstance(zSTRING const&)
	{
		XCALL(0x005A8F70);
	};

	zCObject* CreateCopy(void)
	{
		XCALL(0x005A90A0);
	};

	static void PrintClassHierarchy(int,zCClassDef*,int,int);
	
	
	

	static void GetMemStats(int&,int&,zCClassDef*)
	{
		XCALL(0x005A9C60);
	};

	zSTRING const& GetObjectName(void)const 
	{
		XCALL(0x005A9CD0);
	};

	int SetObjectName(zSTRING const&)
	{
		XCALL(0x005A9CE0);
	};

	int Release(void)
	{
		_ASSERT( refCtr != 0 );
		if(!--refCtr)
			delete this;
		return 0;
	};
	
	int Release2(void)
	{
		XCALL(0x0040C310);
	};
	int						Release3				() { 
														const int tmp=--refCtr;  if (tmp<=0) delete this; return tmp;	
	};
	void AddRef()
	{
		++refCtr;
	};
	int						GetRefCtr			() const { return refCtr; };
};

inline zSTRING ToHex(int val)
{
	zSTRING str = "";
	char buf[32];
	sprintf_s(buf,32 ,"%02x", val);
	str = buf;
	str.Upper();
	str.Insert(0,"0x");
	return str;
};



template<class T>
zSTRING GetClassSize()
{
	int size = sizeof(T);
	return zSTRING("Sizeof: ") + T::classDef->m_sClassName + " =  " + ToHex(size) + " bytes";
};


template<class T>
T* zDYNAMIC_CAST(zCObject const* pObject)
{
	if(!pObject)
		return NULL;
	zCClassDef* pDef = pObject->_GetClassDef();
	if(zCObject::CheckInheritance(T::classDef, pDef))
		return (T*) pObject;
	return NULL;
}