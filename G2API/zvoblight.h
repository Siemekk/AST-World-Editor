#pragma once

#include "zcvob.h"

enum zTVobLightType
{
	zVOBLIGHT_TYPE_POINT	= 0	,
	zVOBLIGHT_TYPE_SPOT			,
	zVOBLIGHT_TYPE_DIR			,	
	zVOBLIGHT_TYPE_AMBIENT			
	
};

enum zTVobLightQuality
{
	zVOBLIGHT_QUAL_HI		= 0	,
	zVOBLIGHT_QUAL_MID			,
	zVOBLIGHT_QUAL_FASTEST			
	
};

class zCVobLightData
{
public:
	zCArray<float>		rangeAniScaleList;
	zCArray<zCOLOR>		colorAniList;
	int					lensFlareFXNo;
	zCLensFlareFX		*lensFlareFX;

	
	zCOLOR				lightColor;						
	float				range;							
	float				rangeInv;						
	float				rangeBackup;					

	
	
	float				rangeAniActFrame;
	float				rangeAniFPS;

	
	float				colorAniActFrame;
	float				colorAniFPS;

	
	float				spotConeAngleDeg;

	struct
	{
		UINT8			isStatic		: 1;
		UINT8			rangeAniSmooth	: 1;
		UINT8			rangeAniLoop	: 1;
		UINT8			colorAniSmooth	: 1;
		UINT8			colorAniLoop	: 1;
		UINT8			isTurnedOn		: 1;
		UINT8			lightQuality	: 4;
		UINT8			lightType		: 4;
		UINT8			m_bCanMove		: 1;
	};

	int SetLensFlareFXByName(zSTRING const&)
	{
		XCALL(0x00609970);
	};

	zSTRING const& GetLensFlareFXName(void)const 
	{
		XCALL(0x00609A70);
	};

	void Archive(zCArchiver&)
	{
		XCALL(0x00609A90);
	};

	void Unarchive(zCArchiver&)
	{
		XCALL(0x00609FA0);
	};

	void zVobLightData(void)
	{
		XCALL(0x0060A970);
	};

	zCVobLightData(void)
	{
		zVobLightData();
	};

	~zCVobLightData(void)
	{
		XCALL(0x0060A9F0);
	};

	void SetRange(float,int)
	{
		XCALL(0x0060AA60);
	};
};




template < class ELEMENT > 
inline 
unsigned long g_GetHashValue( const ELEMENT& a_Element )
{
	return ( (unsigned long) (void*) (unsigned long) a_Element ) >> 4;
}





template < class KEY, class ELEMENT >
class zTRayTurboValMap
{
protected:


	
	
	
	
	
public:											
	struct zSNode									
	{												
		KEY				m_Key		;				
		ELEMENT			m_Element	;				
		unsigned long	m_u32Hash	;				
		zSNode*			m_pNext		;				
	};																														

protected:									
	
	
	
	
	
	zCArray<zSNode*>				m_arrNodes;

public:											
	
	
	
	
	
	BOOL						IsEmpty				( void	) const
	{
		return ( 0 == this->GetCount() );
	}
	
	BOOL						IsValidKey			( const	KEY& a_Key	) const
	{
		unsigned long u32Hash;
		const zSNode* pNode	=	this->GetNode( a_Key, u32Hash );

		if (NULL == pNode)
			return FALSE;

		return TRUE;
	}

	BOOL						Contains			( const ELEMENT& a_Element	) const
	{
		return ( -1 != this->GetIndex( a_Element ) );
	}

public:											
		
		
	void						Clear				( void	)
	{
		this->RemoveAll();
	}

public:											
	
	
	
	
	
	const	zCArray<zSNode*>&	GetData				( void )	const
	{
		return this->m_arrNodes;
	}

protected:										
	
	
	
	
	
	zSNode*						AccessNode			( const KEY& a_Key, unsigned long& a_u32Hash	)
	{
		a_u32Hash	=	::g_GetHashValue< KEY >(a_Key) % this->m_arrNodes.GetNum();
		int iIndex	=	static_cast< int > (a_u32Hash);

		if ( this->m_arrNodes.IsEmpty() )
			return NULL;

		zSNode* pNode	=	this->m_arrNodes[iIndex];

		while( NULL != pNode )
		{
			if ( a_Key == pNode->m_Key )
				return pNode;

			pNode = pNode->m_pNext;
		}
		return NULL;
	}

	const	zSNode*				GetNode				( const KEY& a_Key, unsigned long& a_u32Hash	) const
	{
		a_u32Hash	=	::g_GetHashValue< KEY >( a_Key ) % this->m_arrNodes.GetNum();
		int	iIndex	=	static_cast< int > (a_u32Hash);

		if ( this->m_arrNodes.IsEmpty() )
			return NULL;

		zSNode* pNode	=	this->m_arrNodes[ iIndex ];

		while( NULL != pNode )
		{
			if ( a_Key == pNode->m_Key )
				return pNode;

			pNode = pNode->m_pNext;
		}

		return NULL;
	}

public:											
	ELEMENT&					AccessAt			( const KEY& a_Key	)
	{
		unsigned long	 u32Hash;
		zSNode* pNode	=	this->AccessNode( a_Key, u32Hash );

		if ( NULL != pNode )
			return pNode->m_Element;

		pNode	=	new zSNode;

		pNode->m_Key		= a_Key ;
		pNode->m_u32Hash	= u32Hash;
		pNode->m_pNext		= this->m_arrNodes[ u32Hash ];

		this->m_arrNodes[ u32Hash ]		=	pNode;

		return pNode->m_Element;
	}

	
	const ELEMENT&				GetAt				( const KEY& a_Key	) const
	{
		unsigned long	u32Hash;
		const zSNode* pNode  =	this->GetNode( a_Key, u32Hash );

		return pNode->m_Element;
	}
	
	BOOL						GetAt				( const KEY& a_Key, ELEMENT& a_Element ) const
	{
		unsigned long	 u32Hash;
		const zSNode* pNode  =	this->GetNode( a_Key, u32Hash );

		if ( NULL != pNode )
		{
			a_Element	=	pNode->m_Element;
			return TRUE;
		}

		return FALSE;
	}

	void						SetAt				( const KEY& a_Key, const ELEMENT& a_Element	)
	{
		this->AccessAt( a_Key )		=	a_Element;
	}

	BOOL						RemoveAt			( const KEY& a_Key	)
	{
		unsigned long	u32Hash	=	::g_GetHashValue< KEY >( a_Key ) % this->m_arrNodes.GetNum();
		int				iIndex	=	static_cast< int > (u32Hash);

		if (TRUE == this->m_arrNodes.IsEmpty())
			return GEFalse;

		zSNode* pNode			=	this->m_arrNodes[ iIndex ];

		if ( a_Key == pNode->m_Key )
		{
			this->m_arrNodes[ iIndex ]	=	pNode->m_pNext;
			delete pNode;

			return TRUE;
		}

		while( NULL != pNode->m_pNext )
		{
			if ( a_Key == pNode->m_pNext->m_Key )
			{
				zSNode* pOldNode	=	pNode->m_pNext;
				pNode->m_pNext		=	pNode->m_pNext->m_pNext;

				delete pOldNode;
				return TRUE;
			}

			pNode = pNode->m_pNext;
		}

		return FALSE;
	}

	void						DeleteAll			( void	)
	{
		int iIndex = 0;
		for ( iIndex = 0; iIndex < this->m_arrNodes.GetNum(); iIndex++ )
		{
			zSNode* pNode	=	this->m_arrNodes[ iIndex ];
			zSNode* pNext	=	NULL;

			while( NULL != pNode )
			{
				pNext	=	pNode->m_pNext;
				delete pNode->m_Element;
				delete pNode;

				pNode	=	pNext;
			}
		}

		this->m_arrNodes.EmptyList();
		this->Init();
	}

	void						RemoveAll			( void	)
	{
		int iIndex = 0;
		for ( iIndex = 0; iIndex < this->m_arrNodes.GetNum(); iIndex++ )
		{
			zSNode* pNode	=	this->m_arrNodes[ iIndex ];
			zSNode* pNext	=	NULL;

			while( NULL != pNode )
			{
				pNext	=	pNode->m_pNext;
				delete pNode;
				pNode	=	pNext;
			}
		}

		this->m_arrNodes.EmptyList();
		this->Init();
	}

	
	
	
	
	
public:												
	const	ELEMENT&			operator []			( const KEY& a_Key ) const
	{
		return this->GetAt( a_Key );
	}
	
	ELEMENT&					operator []			( const KEY& a_Key )
	{
		return this->AccessAt( a_Key );
	}

	
	
	
	
	
protected:											
	void						Init				( void )
	{
		this->InitHashTable ( 97 );
	}
public:																		
	void						InitHashTable		( unsigned long a_u32HashCount	)
	{
		
		
		
		this->m_arrNodes.DeleteList();
		this->m_arrNodes.AllocAbs  ( a_u32HashCount );

		
		
		
		for ( int iNode = 0; iNode < static_cast< int > (a_u32HashCount); iNode++ )
		{
			zSNode* pDummyNode	=	NULL;
			this->m_arrNodes.Insert( pDummyNode );
		}
	}

	
	
	
	
	
private:
	zTRayTurboValMap								( const zTRayTurboValMap< KEY, ELEMENT >&	a_Source	) {}
public:											
	 zTRayTurboValMap								( void	)
	 {
		this->Init();
	 }
	
	 ~zTRayTurboValMap								( void	)
	 {
		this->RemoveAll();
	 }

};


class zCVobLight : public zCVob			
{
public:
	zCVobLightData						lightData;
	zTRayTurboValMap<zCPolygon*, int>	affectedPolyMap;
	zSTRING								lightPresetInUse;

public:
	static zCClassDef*		classDef;

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00607E00);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x006090B0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00609100);
	};

	virtual ~zCVobLight()
	{
		XCALL(0x00607E40);
	};

	virtual void OnTrigger(zCVob*,zCVob*)
	{
		XCALL(0x00608050);
	};

	virtual void OnUntrigger(zCVob*,zCVob*)
	{
		XCALL(0x00608120);
	};

	virtual void OnTouch(zCVob*)
	{
		XCALL(0x005FE190);
	};

	virtual void OnUntouch(zCVob*)
	{
		XCALL(0x005FE1A0);
	};

	virtual void OnTouchLevel(void)
	{
		XCALL(0x005FE1B0);
	};

	virtual void OnDamage(zCVob*,zCVob*,float,int,zVEC3 const&)
	{
		XCALL(0x005FE1C0);
	};

	virtual void OnMessage(zCEventMessage*,zCVob*)
	{
		XCALL(0x005FE1D0);
	};

	virtual void OnTick(void)
	{
		XCALL(0x00404270);
	};

	virtual void OnTimer(void)
	{
		XCALL(0x0043CCC0);
	};

	virtual void PostLoad(void)
	{
		XCALL(0x00404280);
	};

	virtual zTVobCharClass GetCharacterClass(void)
	{
		XCALL(0x00404290);
	};

	virtual void SetSleepingMode(const zTVobSleepingMode smode)
	{
		XCALL(0x00602960);
	};

	virtual void EndMovement(const BOOL a_bHintTrafoChanged=TRUE)
	{
		XCALL(0x006092B0);
	};

	virtual int CanThisCollideWith(zCVob*)
	{
		XCALL(0x004042A0);
	};

	virtual int __fastcall Render(zTRenderContext&)
	{
		XCALL(0x006015D0);
	};

	virtual void SetVisual(zSTRING const&)
	{
		XCALL(0x00602680);
	};

	virtual void SetVisual(zCVisual*)
	{
		XCALL(0x006024F0);
	};

	virtual int GetScriptInstance(zSTRING*&,int&)
	{
		XCALL(0x004042B0);
	};

	virtual int SetByScriptInstance(const zSTRING* scriptInstanceName, const int scriptInstanceIndex)
	{
		XCALL(0x004042D0);
	};

	virtual int GetCSStateFlags(void)
	{
		XCALL(0x004042E0);
	};

	virtual int TraceRay(const zVEC3&rayOrigin,const zVEC3&ray, const int traceFlags, zTTraceRayReport&report)
	{
		XCALL(0x005FFE40);
	};

	virtual zSTRING const* GetTriggerTarget(const int i=0)const 
	{
		XCALL(0x0043CCD0);
	};

	virtual void ThisVobAddedToWorld(zCWorld*)
	{
		XCALL(0x00609530);
	};

	virtual void ThisVobRemovedFromWorld(zCWorld*)
	{
		XCALL(0x00601CA0);
	};

	
	void zVobLight(void)
	{
		XCALL(0x00607D10);
	};

	zCVobLight(void)
	{
		zVobLight();
	};

	static void CleanupVobLight(void)
	{
		XCALL(0x00607FE0);
	};

	void DoAnimation(void)
	{
		XCALL(0x006081C0);
	};

	void SetRange(float,int)
	{
		XCALL(0x00608320);
	};

	static zCOLOR SumLightsAtPositionWS(zCArray<zCVobLight*> const&,zVEC3 const&,int)
	{
		XCALL(0x00608410);
	};

	static void LoadLightPresets(void)
	{
		XCALL(0x00608690);
	};

	static void SaveLightPresets(void)
	{
		XCALL(0x006087E0);
	};

	void AddThisToPresetList(zSTRING const&)const 
	{
		XCALL(0x00608910);
	};

	int SetByPreset(zSTRING const&)
	{
		XCALL(0x00608BE0);
	};

	int SetByPresetInUse(void)
	{
		XCALL(0x00608E60);
	};
};

class zCVobLightPreset : public zCObject	
{
	zCVobLightData			m_VobData;		
	zSTRING					m_sName;		
public:
	static zCClassDef*		classDef;

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x005FD690);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00609790);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x006097C0);
	};

	virtual ~zCVobLightPreset()
	{
		XCALL(0x005FD6D0);
	};

};