#include "CListBase.h"


#define REINTERPRET_CAST(T,O) reinterpret_cast<T*>(O)

template <class T> 
class CList : CListBase
{
public:
	CList*		GetNext ();
	T*			GetData ();
	void		Insert (T* obj);
	void		Remove (T* obj);
	CList*		GetAt (const uint32& idx);
	CList&		operator [] (const uint32& idx);
};

template <class T> 
CList<T>* CList<T>::GetNext () {
	return REINTERPRET_CAST(CList<T>, next);
}

template <class T> 
T* CList<T>::GetData () {
	return REINTERPRET_CAST(T, data);
}

template <class T> 
void CList<T>::Insert (T* obj) {
	CListBase::Insert(obj);
}

template <class T> 
void CList<T>::Remove (T* obj) {
	CListBase::Remove(obj);
}

template <class T> // safe
CList<T>* CList<T>::GetAt (const uint32& idx)
{
	return REINTERPRET_CAST(CList<T>, CListBase::GetAt(idx));
}

template <class T> // Unsafe
CList<T>& CList<T>::operator[] (const uint32& idx)
{
	return *REINTERPRET_CAST(CList<T>, CListBase::GetAt(idx));
}