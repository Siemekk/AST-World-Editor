#include <malloc.h>
#include <new.h>



// ===========================================
// ������ ������������ ������, �����������
// �� ����������� ������ � �������. ������������
// ������ dll ��������� � template ��������
// ===========================================



class CArrayBase
{
protected:
	void32		vector			;	// ���������� ������
	uint32		unMalloc		;	// ������� ��������
	uint32		unSize			;	// ���������� ���������
	uint32		unSizeof		;	// ������ ��������
	uint32		unReserveRatio	;	// ����. ��������������

private:
	// �������� +1*ratio ������
	ASTAPI void AllocDelta ();

public:
	// ������ ������ ������
	ASTAPI CArrayBase (const uint32& unitSize);
	// ������ ������ �� �������
	ASTAPI CArrayBase (const uint32& unitSize, const void32 dst);

protected:
	// ��������� ������� � ����� �������
	ASTAPI void InsertEnd (const void32 obj);
	// ��������� ������� � ����� �������
	ASTAPI void Insert (const void32 obj);
	// ��������� ������� � ������������ �������
	ASTAPI void InsertAt (const uint32& idx, const void32 obj);
	// ��������� ������ � ������ �������
	ASTAPI void InsertFront (const void32 obj);
	// ������� ������� �� �������
	ASTAPI void Remove (const void32 obj);
	// ������� ��������� ������� �� �������
	ASTAPI void RemoveAt (const uint32& idx);
	// ������� ������� ������� �� ��������
	ASTAPI void FastRemove (const void32 obj);
	// ������� ������������ ������� ������� �� ��������
	ASTAPI void FastRemoveAt (const uint32& idx);

public:
	// ������� ��� �������� � ��������� �������
	ASTAPI void RemoveAtBounds (const uint32& idx, const uint32& length);

protected:
	// ���������� ������ ������� � �������
	ASTAPI long Search (const void32 obj);
	// ������� ����� ������ �� ������ ��������� ��������� �������
	ASTAPI void32 CopyAtBounds (const uint32& idx, const uint32& length);
	// ���������� ��������� �������
	ASTAPI void32 operator [] (const uint32& idx);
	// ���������� ���������� ��������� �������
	ASTAPI const void32 operator [] (const uint32& idx) const;

public:
	// ���������� ���������� ��������� �������
	ASTAPI uint32 GetNum ();
	// ������������� ����������� ���������� ���������� ������
	ASTAPI void SetReserveRatio (const uint32& val);
	// ������� �������������� ������� ������
	ASTAPI void CompressAllocator ();
	// ���������� ������ ������ ���������� ������
	ASTAPI const uint32 GetRealSizeof ();
	// ���������� ������������ ������ ���������� ������
	ASTAPI const uint32 GetUsedSizeof ();
	// ������� ������
	ASTAPI void Clear ();
	// ������� ��� �������
	ASTAPI void Delete ();
	// ��������� ����������� �� ������ �������
	ASTAPI BOOL IsIn (const void32 obj);
	// ����������� ����������
	ASTAPI virtual ~CArrayBase ();
};
