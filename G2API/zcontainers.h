#pragma once


#include "ztypes.h"
#include <stdlib.h>
#include <windows.h>
#include <WinNT.h>
#include <crtdbg.h>



class zCMemPoolBase
{
public:
	void Free(void *)
	{
		XCALL(0x00566680);
	};

	void*Alloc(void)
	{
		XCALL(0x005664E0);
	};

	static void SetMemDebug(char const *,char const *,int)
	{
		XCALL(0x00566A80);
	};
};

#define zMEMPOOL_DECLARATION_TEMPLATE( classname , poolname)                                        \
public:                                                                                             \
    void *operator new   (size_t s){                                                                \
        return poolname->Alloc();                                                                   \
    }                                                                                               \
                                                                                                    \
    void  operator delete(void *p) { poolname->Free(p);}                                            \
                                                                                                    \
    void* operator new	 (unsigned int size,const char *classn,const char *file,int l){             \
        zCMemPoolBase::SetMemDebug(classn,file,l);                                                  \
        return operator new(size);                                                                  \
    }                                                                                               \
                                                                                                    \
    void  operator delete(void *ptr,const char *classn,const char *file,int line){                  \
        operator delete(ptr);                                                                       \
    }                                                                                               \
                                                                                                    \
    static void PreAlloc(size_t num, BOOL force_oneblock=FALSE){                                    \
        poolname->PreAlloc(num,force_oneblock);                                                     \
    }


inline void InsertionSort(void* pArray, size_t nNumElements, size_t nElementSize, int (*fCompare)(void const*, void const*), bool bIterate);

#pragma warning(disable : 4786)








const int zARRAY_START_ALLOC = 16;

template <class T> class zCArray
{
protected:
	T		*parray;
	int		numAlloc;
	int		numInArray;
public:
	zCArray() {
		numInArray	= 0;
		numAlloc	= 0;
		parray		= 0;
	};
	zCArray(const int startSize) 
	{
		numInArray	= 0;
		numAlloc	= startSize;
		parray		= 0;
		if (startSize>0)
		parray		= new T [startSize];
	};
	zCArray (const zCArray<T>& array2)
	{
		
		numInArray	= 0;
		numAlloc	= 0;
		parray		= 0;
		AllocDelta	(array2.GetNumInList());
		numInArray	= array2.numInArray;
		for (int i=0; i<array2.GetNumInList(); i++)
			parray[i]	= array2.parray[i];
	};
	~zCArray()
	{
		delete[] parray;
		parray=0; 
	};
	T*	 GetArray	() const	{ return parray; };
	void ZeroFill	()			{ if (parray) memset (parray, 0, sizeof (T)*numAlloc); };
	void AllocDelta (const int numDelta)
	{
		if (numDelta<=0) return;
		T *newArray = new T [numAlloc+numDelta];
		if (numInArray>0)
		{
			for (int i=0; i<numInArray; i++)
				newArray[i] = parray[i];		

		};
		delete[] parray;
		parray		=  newArray;
		numAlloc	+= numDelta;
	};
	void AllocAbs (const int size)
	{
		if (numAlloc>=size) return;
		AllocDelta (size-numAlloc);
	};
	void MarkNumAllocUsed () {
		numInArray = numAlloc;
	};
	void ShrinkToFit ()
	{
		if (numInArray<=0) { DeleteList(); return; };
		if (numAlloc>numInArray) {
			T *newArray = new T [numInArray];
			for (int i=0; i<numInArray; i++)
				newArray[i] = parray[i];		
    
			delete[] parray;
			parray		= newArray;
			numAlloc	= numInArray;
		};
	};
	void operator = (const zCArray<T>& array2)
	{
		EmptyList	();
		AllocAbs	(array2.GetNumInList());
		numInArray	= array2.numInArray;
		for (int i=0; i<array2.GetNumInList(); i++)
			parray[i]	= array2.parray[i];
	};
	const T& operator [] (const int nr) const
	{
		return parray[nr];
	};
	T& operator [] (const int nr)
	{
		return parray[nr];
	};

	T& GetSafe (int nr) const
	{
		if (numInArray <=0)	zerr->Fatal ("D: zTree(zCArray::GetSafe): numInArray<=0");
		if (numAlloc   <=0)	zerr->Fatal ("D: zTree(zCArray::GetSafe): numAlloc  <=0");
		if (nr<0          ) nr = 0; else
		if (nr>=numInArray) nr = numInArray-1;
		return parray[nr];
	};
	
	void InsertEnd (const T& ins )
	{
		if (numAlloc<numInArray+1)
		{
			if (numAlloc<zARRAY_START_ALLOC)	AllocDelta (zARRAY_START_ALLOC);
			else								AllocDelta (numAlloc / 2);
		};
		parray[numInArray++] = ins;
	};
	
	void InsertFront	(const T& ins )		{	InsertAtPos (ins, 0);	};
	
	void Insert			(const T& ins )		{	InsertEnd (ins);		};
	
	void InsertAtPos	(const T& ins, int pos)
	{
		if (numAlloc<numInArray+1)
		{
			if (numAlloc<zARRAY_START_ALLOC)	AllocDelta (zARRAY_START_ALLOC);
			else								AllocDelta (numAlloc / 2);
		};
		
		memmove(&parray[pos+1],&parray[pos],sizeof(T) * (numInArray - pos));
		parray[pos] = ins;
		numInArray++;
	};
	
	void Remove (const T& rem)
	{
		if (numInArray==0) return;
		for (int i=0; i<numInArray; i++)
		{
			if (parray[i]==rem)
			{
				numInArray--;
				if (i!=numInArray) parray[i] = parray[numInArray];
				return;
			};
		};
	}
	
	void RemoveIndex (const int index)
	{
		if (numInArray<=0) return;
		numInArray--;
		if (index!=numInArray) parray[index] = parray[numInArray];
	}
	
	void RemoveOrder (const T& rem)
	{
		for (int i=0; i<numInArray; i++)
		{
			if (parray[i]==rem) {
				RemoveOrderIndex (i);
				return;
			};
		};
	};
	
	void RemoveOrderIndex (const int index)
	{
		if (index>=numInArray) return;
		if (index!=numInArray-1) 
			for (int j=index; j<numInArray-1; j++) parray[j] = parray[j+1];
		numInArray--;
		return;
	};
	void DeleteList() {
		delete[] parray;
		parray		= 0;
		numAlloc	= 0;
		numInArray	= 0;
	};
	void EmptyList () { numInArray = 0; };
	int  Search (const T& data)	const
	{ 
		if (numInArray>0)
		{
			for (int i=0; i<numInArray; i++) if (parray[i]==data) return i;
		};
		return -1;
	};
	int IsInList (const T& data) const
	{
		if (numInArray>0)
		{
			for (int i=0; i<numInArray; i++) if (parray[i]==data) return TRUE;
		};
		return FALSE;
	};
	int GetNumInList() const { return numInArray; };
	int GetNum		() const { return numInArray; };
	BOOL IsEmpty	() const { return (numInArray<=0); };
	
	void InsertArray	(const zCArray<T>& other)
	{
		AllocAbs (other.GetNumInList()+GetNumInList());
		for (int i=0; i<other.GetNumInList(); i++)
			parray[numInArray++] = other[i];
	};
	BOOL CheckDoubles ()
	{
		for (int i=0; i<GetNumInList()-1; i++)
			for (int j=i+1; j<GetNumInList(); j++)
				if (parray[i]==parray[j]) return TRUE;
		return FALSE;
	};
	void RemoveDoubles ()
	{
		for (int i=0; i<GetNumInList()-1; i++)
			for (int j=i+1; j<GetNumInList(); j++)
				if (parray[i]==parray[j])
				{
					parray[j]=parray[numInArray-1];
					numInArray--;
					j--;
				};
		return FALSE;
	};
	void DeleteListDatas()
	{
		for( int i = 0; i != numInArray; ++i )
			SAFE_DELETE( parray[i] );
		DeleteList();
	}
};


template <class T>
static inline DWORD CalcArraySize (zCArray<T> array)
{
	return sizeof(T) * array.GetNum();
}

inline void insertionsort(void *data, size_t num, size_t size, int (__cdecl *compare)(const void *, const void *),
                    bool fallbacktoqs);

inline int zArraySortDefaultCompare (const void* ele1,const void* ele2);

template <class T> class zCArraySort
{
protected:
	T		*array;
	int		numAlloc;
	int		numInArray;
	
	int		(*Compare)(const void* ele1,const void* ele2);
public:
	zCArraySort ( )
	{
		numInArray	= 0;
		numAlloc	= 0;
		array		= 0;
		SetCompare (zArraySortDefaultCompare);
	};
	zCArraySort(const int startSize)
	{
		numInArray	= 0;
		numAlloc	= startSize;
		array		= 0;
		if (startSize>0)
		array		= new T() [startSize];
		SetCompare (zArraySortDefaultCompare);
	};
	zCArraySort (const zCArraySort<T>& array2)
	{
		
		numInArray	= 0;
		numAlloc	= 0;
		array		= 0;
		AllocDelta	(array2.GetNumInList());
		numInArray	= array2.numInArray;
		for (int i=0; i<array2.GetNumInList(); i++)
			array[i]	= array2.array[i];
		SetCompare	(array2.Compare);
	};
	~zCArraySort()
	{
		delete[] array;
		array=0; 
	};
	T* GetArray() const { return array; };
	
	void SetCompare ( int (*Cmp)(const void* ele1, const void* ele2) )	{ Compare = Cmp; };
	void AllocDelta (const int numDelta) {
		if (numDelta<=0) return;
		T *newArray = new T [numAlloc+numDelta];
		if (numInArray>0)
		{
			for (int i=0; i<numInArray; i++)
				newArray[i] = array[i];		

		};
		delete[] array;
		array		=  newArray;
		numAlloc	+= numDelta;
	};
	void AllocAbs (const int size)
	{
		if (numAlloc>=size) return;
		AllocDelta (size-numAlloc);
	};
	void ShrinkToFit ()
	{
		if (numInArray<=0)
		{ DeleteList(); return; };
		if (numAlloc>numInArray)
		{
			T *newArray = new T() [numInArray];
			for (int i=0; i<numInArray; i++)
				newArray[i] = array[i];		

			delete[] array;
			array		= newArray;
			numAlloc	= numInArray;
		};
	};
	void operator = (const zCArraySort<T>& array2)
	{
		EmptyList	();
		AllocAbs	(array2.GetNumInList());
		numInArray	= array2.numInArray;
		for (int i=0; i<array2.GetNumInList(); i++)
			array[i]	= array2.array[i];
	};
	const T& operator [] (const int nr) const
	{
		return array[nr];
	};
	T& operator [] (const int nr)
	{
		return array[nr];
	};
	T& GetSafe (int nr) const
	{
		if (numInArray <=0)	zerr->Fatal ("D: zTree(zCArraySort::GetSafe): numInArray<=0");
		if (numAlloc   <=0)	zerr->Fatal ("D: zTree(zCArraySort::GetSafe): numAlloc  <=0");
		if (nr<0          ) nr = 0; else
		if (nr>=numInArray) nr = numInArray-1;
		return array[nr];
	};
	T& Get (const int nr) const
	{
		return array[nr];
	};
	
	void InsertEnd (const T& ins )
	{
		if (numAlloc<numInArray+1)
		{
			if (numAlloc<zARRAY_START_ALLOC)	AllocDelta (zARRAY_START_ALLOC);
			else								AllocDelta (numAlloc / 2);
		};
		array[numInArray++] = ins;
	};

	void Insert (const T& ins )		{ InsertEnd (ins);	};
	
	void InsertAtPos (const T& ins, int pos)
	{
		if (numAlloc<numInArray+1)
		{
			if (numAlloc<zARRAY_START_ALLOC)	AllocDelta (zARRAY_START_ALLOC);
			else								AllocDelta (numAlloc / 2);
		};
		
		memmove(&array[pos+1],&array[pos],sizeof(T) * (numInArray - pos));
		array[pos] = ins;
		numInArray++;
	};
	
	void InsertSort (const T& ins )
	{
		if (numAlloc<numInArray+1)
		{
			if (numAlloc<zARRAY_START_ALLOC)	AllocDelta (zARRAY_START_ALLOC);
			else								AllocDelta (numAlloc / 2);
		};

		
		int ind_low	= 0;
		int ind_high= numInArray-1;
		int index	= ( ind_low + ind_high ) / 2;
		int erg;

		do {
			if (ind_high <= ind_low)
			{

				if (index >= numInArray)
				{
					array[index] = ins;
					numInArray++;
					return;
				} else
				{
					erg = Compare ( &ins, &(array[index]) );
					if (erg > 0) index++; 
				};
				
				
				memmove(&array[index+1],&array[index],sizeof(T) * (numInArray - index));
				array[index] = ins;
				numInArray++;
				return;
			}
	
			erg = Compare ( &ins, &(array[index]) );
		
			if (erg>0) 	ind_low	= index + 1; 
			else		ind_high= index - 1; 
			
			index = ( ind_low + ind_high ) / 2;
		} while ( 1 ); 
	};

	int Search (const T& ins ) const
	{
		if (numInArray<=0) return -1;
		
		
		int ind_low	= 0;
		int ind_high= numInArray-1;
		int index	= ( ind_low + ind_high ) / 2;
		int erg;

		do {
			erg = Compare ( &ins, &(array[index]) );
			if (ind_high <= ind_low)
			{
				if (erg==0) return index;
				return -1;
			}
	
			if (erg>0) 	ind_low	= index + 1; else
			if (erg<0)  ind_high= index - 1; else
			return index;

			index = ( ind_low + ind_high ) / 2;
		} while (1);
	};

	
	void RemoveIndex (const int index)
	{
		if (numInArray<=0) return;
		numInArray--;
		if (index!=numInArray) array[index] = array[numInArray];
	}
	
	void Remove (const T& rem)
	{
		if (numInArray==0) return;
		for (int i=0; i<numInArray; i++)
		{
			if (array[i]==rem)
			{
				numInArray--;
				if (i!=numInArray) array[i] = array[numInArray];
				return;
			};
		};
	}
	
	void RemoveOrder (const T& rem)
	{
		int i = Search (rem);
		if (i!=-1) RemoveOrderIndex (i);

	};
	
	void RemoveOrderIndex (const int index)
	{
		if (index>=numInArray) return;
		if (index!=numInArray-1) 
			for (int j=index; j<numInArray-1; j++) array[j] = array[j+1];
		numInArray--;
		return;
	};
	void DeleteList()
	{
		delete[] array;
		array		= 0;
		numAlloc	= 0;
		numInArray	= 0;
	};
	void EmptyList () { numInArray = 0; };
	
	int	IsInList (const T& data) const
	{
		
		int i = Search (data);
		if (i==-1)	return FALSE;
		else		return TRUE;

	};
	void MarkNumAllocUsed ()
	{
		numInArray = numAlloc;
	};
	int	  GetNumInList	() const	{ return numInArray; };
	int	  GetNum		() const	{ return numInArray; };
	BOOL IsEmpty		() const	{ return (numInArray<=0); };
	void  QuickSort		()			{ qsort (array, GetNumInList(), sizeof(T), Compare);	};
	void  InsertionSort ()			{ insertionsort (array, GetNumInList(), sizeof(T), Compare,false);	};
	void  BestSort      ()			{ insertionsort (array, GetNumInList(), sizeof(T), Compare,true);	};
};




template <class T> class zCArrayAdapt {
protected:
	T		*array;
	int		numInArray;
public:
	 zCArrayAdapt()									{ numInArray= 0; array = 0;	};
	~zCArrayAdapt()									{ array=0;					};
	T*		GetArray		() const				{ return array;				};
	DWORD	GetSizeBytes	() const				{ return sizeof(T)*numInArray; };
	DWORD	SetArray		(void* ptr, const int num){ array=(T*)ptr; numInArray=num; return sizeof(T)*numInArray; };
	void	SetNumInArray	(const int num)			{ numInArray=num;			};
	void	EmptyList		()						{ numInArray = 0;			};
	int		GetNum			() const				{ return numInArray;		};
	BOOL	IsEmpty			() const				{ return (numInArray<=0);	};
	const T& operator [] (const int nr) const
	{
		return array[nr];
	};
	T& operator [] (const int nr)
	{
		return array[nr];
	};
	T& GetSafe (int nr) const
	{
		if (numInArray <=0)	zERR_FATAL ("D: (zCArrayAdapt::GetSafe): numInArray<=0");
		if (nr<0          ) nr = 0; else
		if (nr>=numInArray) nr = numInArray-1;
		return array[nr];
	};
	
	void InsertEnd (const T& ins )			{	array[numInArray++] = ins;	};
	
	void InsertFront	(const T& ins )		{	InsertAtPos (ins, 0);	};
	
	void Insert			(const T& ins )		{	InsertEnd (ins);		};
	
	void InsertAtPos	(const T& ins, int pos)
	{
		
		memmove(&array[pos+1],&array[pos],sizeof(T) * (numInArray - pos));
		array[pos] = ins;
		numInArray++;
	};
	
	void Remove (const T& rem)
	{
		if (numInArray==0) return;
		for (int i=0; i<numInArray; i++)
		{
			if (array[i]==rem) {
				numInArray--;
				if (i!=numInArray) array[i] = array[numInArray];
				return;
			};
		};
	}
	
	void RemoveIndex (const int index)
	{
		if (numInArray<=0) return;
		numInArray--;
		if (index!=numInArray) array[index] = array[numInArray];
	}
	
	void RemoveOrder (const T& rem)
	{
		for (int i=0; i<numInArray; i++)
		{
			if (array[i]==rem) {
				RemoveOrderIndex (i);
				return;
			};
		};
	};
	
	void RemoveOrderIndex (const int index)
	{
		if (index>=numInArray)		return;
		if (index!=numInArray-1)	for (int j=index; j<numInArray-1; j++) array[j] = array[j+1];
		numInArray--;
		return;
	};
	int  Search (const T& data)	const
	{ 
		if (numInArray>0)	for (int i=0; i<numInArray; i++) if (array[i]==data) return i;
		return -1;
	};
	int IsInList (const T& data) const
	{
		if (numInArray>0)	for (int i=0; i<numInArray; i++) if (array[i]==data) return TRUE;
		return FALSE;
	};
};

template <class T>
static inline void SetAndCopyArrayAdapt (BYTE* &dataWalk, zCArrayAdapt<T> &arrayDest, const zCArray<T> &arraySrc) 
{
	dataWalk	+= arrayDest.SetArray (dataWalk, arraySrc.GetNum());
	memcpy		(arrayDest.GetArray(), arraySrc.GetArray(), sizeof(T) * arrayDest.GetNum());
};

template <class obj> class zList
{
	int (*Compare)(obj *ele1,obj *ele2);
	int count;
	obj *last;
public:
	obj *wurzel;
	
	zList () 
	{ 
		last   = 0;
		wurzel = NULL; 
		count  = 0;
	}

	
	void SetCompare( int (*Cmp)(obj *ele1,obj *ele2) )
	{
		Compare = Cmp;
	}

	
	void Clear() 
	{
		obj *ele,*help;
		ele = wurzel;
		while (ele!=NULL)
		{
			help = ele;
			ele  = ele->next;
			delete(help);
		}
		last   = NULL;
		wurzel = NULL;
		count  = 0;
	};
	
	
	void Insert( obj *ins ) 
	{
		if (IsIn(ins))
		{
			return;
		}
		if (wurzel==NULL) last = ins;

		ins -> next = wurzel;
		wurzel      = ins;
		count++;
	}

	
	void InsertLast ( obj *ins )
	{
		if (IsIn(ins))
		{
			return;
		}
		count++;
		ins -> next = NULL;
		if (wurzel==NULL)
		{
			last   = ins;
			wurzel = ins;
		} else
		{
			last->next = ins;
			ins ->next = NULL;
			last	   = ins;
		}
	}		

	
	BOOL InsertAsNext (obj* object, obj* ins)
	{
		if (IsIn(ins))
		{
			return FALSE;
		}

		if ((!object) || (!ins)) return FALSE;
		ins		-> next = object -> next;
		object	-> next = ins;

		count++;
		return TRUE;
	}

	
	BOOL InsertAsPrevious (obj* ins, obj* object)
	{
		if (IsIn(ins))
		{
			return FALSE;
		}

		if ((!object) || (!ins)) return FALSE;
		if (wurzel == object)
		{
			ins -> next = wurzel;
			wurzel		= ins;
			count++;
			return TRUE;
		}
		
		obj* ele = wurzel;
		while (ele!=NULL)
		{
			if (ele -> next == object)
			{
				ins -> next = object;
				ele -> next = ins;
				count++;
				return TRUE;
			}
			ele = ele->next;
		}
		return FALSE;
	}

	
	void InsertSort (obj *ins)
	{
		obj *ele;
	
		if (IsIn(ins)) {
			return;
		}

		if ((wurzel==NULL) || (Compare(ins,wurzel)<0)) {
			
			ins->next = wurzel;
			wurzel    = ins;
			count++;
		} else {
			ele = wurzel;
			while (ele->next != NULL)
			{
				if (Compare(ins,ele->next)<=0)
				{
					ins->next = ele->next;
					ele->next = ins;
					count++;
					return;
				}
				ele = ele->next;
			}
			ele -> next = ins;
			ins -> next = NULL;
			last        = ins;
			count++;
		}
	}

	
	void Remove( obj *rem )
	{
		obj *ele = wurzel;
		
		if (ele==NULL) return;
		if (ele==rem)
		{
			wurzel = ele->next;
			if (wurzel==NULL) last = NULL;
			count--;
			if (count<0)
				zERR_FAULT("U: LIST: Count is less than 0");
		} else
		{
			while (ele->next!=NULL)
			{
				if (ele->next==rem)
				{
					if (rem->next==NULL) last = ele;
					ele->next = rem->next;
					count--;
					if (count<0)
						zERR_FAULT("U: LIST: Count is less than 0");
					return;
				}
				
				if (ele==ele->next) ele->next = NULL;
				else ele = ele->next;
			}
		}
	}
		
	
	void Delete( obj *rem )
	{
		obj *ele = wurzel;
		
		if (ele==NULL) return;
		if (ele==rem)
		{
			wurzel = ele->next;
			if (wurzel == NULL) last = NULL;
			delete(ele);
			count--;
			if (count<0)
				zERR_FAULT("U: LIST: Count is less than 0");
		} else
		{
			while (ele->next!=NULL)
			{
				if (ele->next==rem)
				{
					if (rem->next==NULL) last = ele;
					ele->next = rem->next;
					delete(rem);
					count--;
					if (count<0)
						zERR_FAULT("U: LIST: Count is less than 0");
					return;
				}
				ele = ele->next;
			}
		}
	}

	
	obj* Get( int nr )
	{
		obj *ele = wurzel;
		int c = 0;

		while (ele!=NULL)
		{
			c++;
			if (c==nr) return(ele);
			ele = ele->next;
		}
		return NULL;
	}

	obj *GetLast()
	{
		return last;
	}

	
	BOOL IsIn(obj *ele2)
	{
		obj *ele = wurzel;

		while (ele!=NULL)
		{
			if (ele==ele2) return TRUE;
			ele = ele->next;
		}
		return FALSE;
	}
	
	
	int Count()
	{
		return count;
	}
};








inline zCMemPoolBase* Get_ListSortPool()
{
	return (zCMemPoolBase*)0x008D83B4;
};

inline zCMemPoolBase* Get_ListPool()
{
	return (zCMemPoolBase*)0x008D8398;
};

inline zCMemPoolBase* Get_TreePool()
{
	return (zCMemPoolBase*)0x008D837C;
};

template <class T> class zCList
{
	zMEMPOOL_DECLARATION_TEMPLATE(zCList,Get_ListPool());

	T			*data;
	zCList		*next;
public:

	
	zCList ()
	{ 
		next	= 0; 
		data	= 0;
	}

	~zCList ()
	{ 

		if (next)
		{
			delete next;
			next = 0;
		};
		data=0;
	};

	
	void DeleteList()
	{
		if (next)
		{
			delete next;
			next = 0;
		};
	};

	
	void DeleteListDatas()
	{
		if (data)
		{
			delete data;
			data = 0;
		};

		if (next)
		{
			next->DeleteListDatas();
            delete next; 
			next = 0;
		};
	};

	void Replace ( T *ins ) { data  = ins; };

	
	void Insert ( T *ins )
	{
		zCList *newItem  = new zCList();
		newItem->data	 = ins;
		newItem->next	 = next;
		next			 = newItem;
	};

	void InsertFront ( T *ins )
	{
		zCList *newItem  = new zCList();
		newItem->data	 = ins;
		newItem->next	 = next;
		next			 = newItem;
	};

	
	void Remove( T *rem )
	{
		zCList *item = this;
		
		while (item->next!=0)
		{
			if (item->next->data==rem)
			{
				zCList *tmp	= item->next;
				item->next	= item->next->next;
				tmp ->next	= 0;
				delete tmp;
				return;
			}
			item = item->next;
		}
	}
	
	
	T* Get (const int nr) const
	{
		zCList *item	= next;
		int		c		= 0;
		while (item)
		{
			if (c==nr) return item->data;
			item = item->next;
			c++;
		}
		return 0;
	};

	T* operator [] (const int nr) const { return Get (nr);	};

	zCList*		GetNextInList	() const { return next; };
	T*			GetData			() const { return data; };

	
	BOOL InList (T *data) const
	{
		zCList *item = next;
		while (item!=0)
		{
			if (item->data==data) return TRUE;
			item = item->next;
		}
		return FALSE;
	}
	BOOL IsInList (T *data) const
	{
		zCList *item = next;
		while (item!=0)
		{
			if (item->data==data) return TRUE;
			item = item->next;
		}
		return FALSE;
	}
	
	
	int GetNumInList() const
	{ 
		int count = 0;
		zCList *item = next;
		while (item!=0)
		{
			count++;
			item = item->next;
		}
		return count;
	};
	int GetNum() const { return GetNumInList(); };
};

template <class T> class zCListSort
{
	zMEMPOOL_DECLARATION_TEMPLATE(zCListSort,Get_ListSortPool());
public:
	int (*Compare)(T *ele1,T *ele2);
	T			*data;
	zCListSort	*next;
public:

	
	zCListSort ()
	{ 
		next	= 0; 
		data	= 0;
	}

	~zCListSort ()
	{ 
		
		
		if (next)
		{
			delete next;
			next = 0;
		};
	};

	
	void DeleteList()
	{
		if (next)
		{
			
			delete next;
			next = 0;
		};
	};

	
	void DeleteListDatas()
	{
		if (data)
		{
			data->Release();
			data = 0;
		};
		
		if (next)
		{
			next->DeleteListDatas();
			delete next;
			next = 0;
		};
	};

	void Replace		( T *ins ) { data  = ins; };

	
	void Insert			( T *ins )
	{
		zCListSort *newItem = new zCListSort();
		newItem->data		= ins;
		newItem->next		= next;
		next				= newItem;
	}
	
	void InsertSort		( T *ins )
	{
 		zCListSort* newItem = new zCListSort();
		newItem->data		= ins;
		newItem->next		= next;
		
		zCListSort* ele		= this;
		while (ele->next)
		{
			if (Compare(ins,ele->next->data)<0)
			{
				
				newItem -> next = ele->next;
				ele	-> next		= newItem;
				return;
			}
			ele = ele->next;
		}
		
		newItem -> next = NULL;
		ele -> next		= newItem;
	};
	
	void Remove			( T *rem )
	{
		zCListSort *item = this;
		
		while (item->next!=0)
		{
			if (item->next->data==rem)
			{
				zCListSort *tmp	= item->next;
				item->next	= item->next->next;
				tmp ->next	= 0;
				delete tmp;
				return;
			}
			item = item->next;
		}
	};
		
	
	
	T* Get (int nr) const
	{
		zCListSort *item = next;
		int c = 0;
		while (item!=0)
		{
			if (c==nr) return(item->data);
			item = item->next;
			c++;
		}
		return 0;
	};

	T* operator [] (int nr) const
	{
		return Get (nr);
	};

	zCListSort*	GetNextInList	() const { return next; };
	T*			GetData			() const { return data; };

	
	BOOL InList (T *data) const
	{
		zCListSort *item = next;
		while (item!=0)
		{
			if (item->data==data) return TRUE;
			item = item->next;
		}
		return FALSE;
	}
	BOOL IsInList (T *data) const
	{
		zCListSort *item = next;
		while (item!=0)
		{
			if (item->data==data) return TRUE;
			item = item->next;
		}
		return FALSE;
	}
	
	
	int GetNumInList() const
	{ 
		int count = 0;
		zCListSort *item = next;
		while (item!=0)
		{
			count++;
			item = item->next;
		}
		return count;
	};

	
	void SetCompare( int (*Cmp)(T *ele1,T *ele2) )
	{
		Compare = Cmp;
	};
};

template <class T> class zCTree {
protected:
    zMEMPOOL_DECLARATION_TEMPLATE(zCTree, Get_TreePool())

	zCTree* parent;
	zCTree* firstChild;
	zCTree* next;
	zCTree* prev;
	T*		data;

	void RemoveChild ()
	{
		if (firstChild)
		{
			
		};
		if (prev) prev->next	= next;
		if (next) next->prev	= prev;
		if (parent)
		if (this==parent->firstChild)
		{
			parent->firstChild = next;
		};
	};

public:
	zCTree()
	{
		
		
		firstChild	= parent = next = prev = 0;
		data = 0;
	};

	~zCTree()
	{
		data=0;					
		while (firstChild) { delete firstChild; } 
		RemoveChild();
	};

	void DeleteDataSubtree ()
	{
		if (data) {
			delete data;
			data = 0;
		};
		
		zCTree* child = GetFirstChild(); 
		while (child)
		{
			child->DeleteDataSubtree ();
			child = child->GetNextChild();
		};
	};
	void DeleteChilds()
	{
		while (firstChild) { delete firstChild; } 
		RemoveChild();
	};
	
	T**  GetPtrToData	() const 	{ return &data; };
	T*   GetData		() const	{ return data; };
	void SetData		(T* d)		{ data = d; };

	zCTree* AddChild (T* d)
	{
		zCTree* newNode		= new zCTree;
		newNode->parent		= this;
		newNode->prev		= 0;
		newNode->next		= firstChild;
		newNode->data		= d;
		firstChild			= newNode;
		if (newNode->next!=0)
		newNode->next->prev	= newNode;
		return newNode;
	};

	zCTree* AddChild (zCTree* node)
	{
		node->parent		= this;
		node->prev			= 0;
		node->next			= firstChild;
		firstChild			= node;
		if (node->next!=0)
		node->next->prev	= node;
		return node;
	};

	
	zCTree* GetParent	  () { return parent; };
	zCTree* GetFirstChild () { return firstChild; };
	zCTree* GetNextChild  () { return next; };
	zCTree* GetPrevChild  () { return prev; };
	int		GetNumChilds  () {
		int num=0;
		zCTree* child = GetFirstChild();
		while (child!=0)
		{
			num++;
			child=child->GetNextChild();
		};
		return num;
	};

	
	zCTree* Search (T* d)
	{
		
		if (data==d) return this;
		zCTree* child = GetFirstChild();
		while (child!=0)
		{
			zCTree* res = child->Search (d);
			if (res!=0) return res;
			child = child->GetNextChild();
		};
		return 0;								
	};

	
	int Search (const zCTree* node)
	{
		
		if (this==node) return 1;
		zCTree* child = GetFirstChild();
		while (child!=0)
		{
			if (child->Search (node)) return 1;
			child = child->GetNextChild();
		};
		return 0;								
	};

	
	int CountNodes ()
	{
		
		int a,b;
		a=b=0;
		if (firstChild!=0)	a = firstChild->CountNodes ();
		if (next!=0)		b = next->CountNodes ();
		return a+b+1;
	};

	
	void RemoveSubtree ()
	{
		
		if (parent && parent->firstChild==this)
		{
			parent->firstChild = next;
		};
		
		if (prev!=0) prev->next	= next;
		if (next!=0) next->prev	= prev;
		prev=next=0;
	};

	
	void MoveSubtreeTo (zCTree* destParent)
	{
		RemoveSubtree();
		if (destParent) destParent->AddChild (this);
		else			parent=0;
	};
};



#include "zcontainers.inl"

#pragma warning(default : 4786)




