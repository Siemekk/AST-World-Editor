#include "CArrayBase.h"



template <class T>
class CArray : public CArrayBase
{
public:
	// ������� ������ ������
	CArray ();
	// ������� ������ �� �������
	CArray (const T* dst);
	// ��������� ������� � ����� �������
	void InsertEnd (const T& obj);
	// ��������� ������� � ����� �������
	void Insert (const T& obj);
	// ��������� ������� � ������������ �������
	void InsertAt (const uint32& idx, const T& obj);
	// ��������� ������ � ������ �������
	void InsertFront (const T& obj);
	// ������� ������� �� �������
	void Remove (const T& obj);
	// ������� ��������� ������� �� �������
	void RemoveAt (const uint32& idx);
	// ������� ������� ������� �� ��������
	void FastRemove (const T& obj);
	// ������� ������������ ������� ������� �� ��������
	void FastRemoveAt (const uint32& idx);
	// ���������� ������ ������� � �������
	long Search (const T& obj);
	// ������� ����� ������ �� ������ ��������� ��������� �������
	T* CopyAtBounds (const uint32& idx, const uint32& length);
	// ���������� ��������� �������
	T& operator [] (uint32 idx);
	// ���������� ���������� ��������� �������
	const T& operator [] (uint32 idx) const;
	// ���������� ��������� �� ������
	T* GetSafe (const uint32& idx);
	// ��������� ����������� �� ������ �������
	BOOL IsIn (const T& obj);
};

// ���������� ������������ ������� � ������������ ����������������� ���������
#define DOUBLE_REINTERPRET_CAST(v) reinterpret_cast<const void32>(reinterpret_cast<uint32>(&v))

template <class T>
CArray<T>::CArray () 
	: CArrayBase (sizeof(T)) {
}

template <class T>
CArray<T>::CArray (const T* dst) 
	: CArrayBase (sizeof(T), dst) {
}

template <class T>
void CArray<T>::InsertEnd (const T& obj) {
	CArrayBase::
		InsertEnd (DOUBLE_REINTERPRET_CAST(obj));
}

template <class T>
void CArray<T>::Insert (const T& obj) {
	CArrayBase::
		Insert (DOUBLE_REINTERPRET_CAST(obj));
}

template <class T>
void CArray<T>::InsertAt (const uint32& idx, const T& obj) {
	CArrayBase::
		InsertAt (idx, DOUBLE_REINTERPRET_CAST(obj));
}

template <class T>
void CArray<T>::Remove (const T& obj) {
	CArrayBase::
		Remove (DOUBLE_REINTERPRET_CAST(obj));
}

template <class T>
void CArray<T>::RemoveAt (const uint32& idx) {
	CArrayBase::
		RemoveAt (idx);
}

template <class T>
void CArray<T>::FastRemove (const T& obj) {
	CArrayBase::
		FastRemove (DOUBLE_REINTERPRET_CAST(obj));
}

template <class T>
void CArray<T>::FastRemoveAt (const uint32& idx) {
	CArrayBase::
		FastRemoveAt (idx);
}

template <class T>
void CArray<T>::InsertFront (const T& obj) {
	CArrayBase::
		InsertAt (0, DOUBLE_REINTERPRET_CAST(obj));
}

template <class T>
long CArray<T>::Search (const T& obj) {
	return CArrayBase::
		Search (DOUBLE_REINTERPRET_CAST(obj));
}

template <class T>
T* CArray<T>::CopyAtBounds (const uint32& idx, const uint32& length) {
	return (T*)CArrayBase::
		CopyAtBounds (idx, length);
}

template <class T>
T& CArray<T>::operator [] (uint32 idx) {
	return *(T*)CArrayBase::
		operator [] (idx);
}

template <class T>
const T& CArray<T>::operator [] (uint32 idx) const {
	return *(T*)CArrayBase::
		operator [] (idx);
}

template <class T>
T* CArray<T>::GetSafe (const uint32& idx) {
	if (idx >= GetNum())
		return (T*)NULL;
	return CArrayBase::
		operator [] (idx);
}

template <class T>
BOOL CArray<T>::IsIn (const T& obj) {
	return CArrayBase::
		Search (DOUBLE_REINTERPRET_CAST(obj)) != -1;
}
