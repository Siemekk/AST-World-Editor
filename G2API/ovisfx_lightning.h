#pragma once

#include "ztypes.h"
#include "zcvob.h"
#include "zcmesh.h"
#include "zcmodel.h"
#include "zcmaterial.h"
#include "oCVisFx.h"

class zCVob;
class oCVisualFX;
class oCVisFX_Lightning;

class oCFXScanner		
{
	BOOL			m_bEnabled;			
	BYTE			m_nAlpha;			
	zCVob*			m_pInitVob;			
	zCVob*			m_ScannerVobs[3];	
public:
	oCFXScanner();
	~oCFXScanner();
	void Initialize(oCVisFX_Lightning* pFXLightning);
	BOOL Initialized();
	void Enable(zCVob* pInitVob);
	void Disable();
	BOOL Enabled();
	void Run();
};


class oCVisFX_Lightning : public oCVisualFX
{
	int							m_nPhase;
	float						m_fLightRange;
	BOOL						m_bShowScanner;
	BOOL						m_bInvestedNext;
	BOOL						m_bCastOnSelf;
	int							us5DC;
	zCModelNodeInst*			m_pTargetNode;
	zCArray<zCVob*>				m_arrBurnVobs;
	zCArray<zCModelNodeInst*>	m_arrBurnNodes;
	zCArray<zCVob*>				m_arrDecalVobs;
	zCArray<oCVisualFX*>		m_arrElectricFX;
	oCFXScanner					m_Scanner;
	BOOL CheckDeletion();
	void UpdateBurnVobs();
	BOOL UpdateBurnVobsInvestNext();
	void Draw();
	void CreateScanner(zCVob*);
	void UpdateScanner();
	void DeleteScanner();
	static zCClassDef classDef;
	static zCObject* _CreateNewInstance();
	virtual zCClassDef* _GetClassDef() const;								
protected:
	virtual void Archive(zCArchiver& ar);									
	virtual void Unarchive(zCArchiver& ar);									
public:
	oCVisFX_Lightning();
	static void* operator new(size_t);
	static void operator delete(void*);
	virtual ~oCVisFX_Lightning();											
	virtual void OnTick();													
	virtual void Open();													
	virtual void Init(zCArray<zCVob*> const&);								
	virtual void InvestNext();												
	virtual void Cast(const BOOL killAfterDone = TRUE);												
	virtual void Stop(const BOOL killAfterDone = TRUE);												
};


inline void* oCVisFX_Lightning::operator new(size_t nSize)
{
	void* p = ::operator new(nSize);
	zCClassDef::ObjectCreated((zCObject*)p, &classDef);
	return p;
}

inline void oCVisFX_Lightning::operator delete(void* p)
{
	zCClassDef::ObjectDeleted((zCObject*)p, &classDef);
	::operator delete(p);
}