#include <malloc.h>
#include <new.h>



// ===========================================
// чистый динамический массив, построенный
// на безусловной работе с памятью. использовать
// только dll вариантом с template оберткой
// ===========================================



class CArrayBase
{
protected:
	void32		vector			;	// выделенная память
	uint32		unMalloc		;	// сколько выделено
	uint32		unSize			;	// количество элементов
	uint32		unSizeof		;	// размер элемента
	uint32		unReserveRatio	;	// коэф. резервирования

private:
	// выделяет +1*ratio памяти
	ASTAPI void AllocDelta ();

public:
	// строит пустой массив
	ASTAPI CArrayBase (const uint32& unitSize);
	// строит массив из вектора
	ASTAPI CArrayBase (const uint32& unitSize, const void32 dst);

protected:
	// вставляет элемент в конец вектора
	ASTAPI void InsertEnd (const void32 obj);
	// вставляет элемент в конец вектора
	ASTAPI void Insert (const void32 obj);
	// вставляет элемент в определенную позицию
	ASTAPI void InsertAt (const uint32& idx, const void32 obj);
	// вставляет объект в начало вектора
	ASTAPI void InsertFront (const void32 obj);
	// удаляет элемент из вектора
	ASTAPI void Remove (const void32 obj);
	// удаляет указанный элемент из вектора
	ASTAPI void RemoveAt (const uint32& idx);
	// удаляет элемент вектора не сортируя
	ASTAPI void FastRemove (const void32 obj);
	// удаляет определенный элемент вектора не сортируя
	ASTAPI void FastRemoveAt (const uint32& idx);

public:
	// удаляет все элементы в указанном радиусе
	ASTAPI void RemoveAtBounds (const uint32& idx, const uint32& length);

protected:
	// определяет индекс объекта в векторе
	ASTAPI long Search (const void32 obj);
	// создает копию данных на основе указанных элементов вектора
	ASTAPI void32 CopyAtBounds (const uint32& idx, const uint32& length);
	// возвращает указанный элемент
	ASTAPI void32 operator [] (const uint32& idx);
	// константно возвращает указанный элемент
	ASTAPI const void32 operator [] (const uint32& idx) const;

public:
	// возвращает количество элементов вектора
	ASTAPI uint32 GetNum ();
	// устанавливает коэффициент увеличения выделяемой памяти
	ASTAPI void SetReserveRatio (const uint32& val);
	// сживаем неиспользуемые участки памяти
	ASTAPI void CompressAllocator ();
	// возвращает полный размер выделенной памяти
	ASTAPI const uint32 GetRealSizeof ();
	// возвращает используемый размер выделенной памяти
	ASTAPI const uint32 GetUsedSizeof ();
	// очищает список
	ASTAPI void Clear ();
	// удаляет все объекты
	ASTAPI void Delete ();
	// проверяет принадлежит ли объект вектору
	ASTAPI BOOL IsIn (const void32 obj);
	// виртуальный деструктор
	ASTAPI virtual ~CArrayBase ();
};
