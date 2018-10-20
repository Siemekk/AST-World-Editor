//
//	Ќаследу€ эту структуру, класс начнет резервировать пам€ть под свои экземпл€ры, 
//	где размер пула указываетс€ исход€ из количества необходимых €чеек.  ак только 
//	место в пуле заканчиваетс€, создаетс€ новый. Ёто может значительно ускорить процесс 
//	работы с динамической пам€тью, а так же полезно дл€ фрагментации данных.
//
//																		- Gratt.
//



template <unsigned __int64 __size_l, typename __type>
struct allocator64 
{
	struct mem_pool {
		typedef struct mem_page {
			uint64 ufree;
			uint64 uorder [__size_l];
			void64 page;
			__void init ();
		} PAGE, *HPAGE, **HPAGELIST;

		HPAGELIST	hpagelist;
		uint64		ucount;

		mem_pool ();
		void64 hold_mem (__void);
		__void free_mem (void64);
		
	} static pool;

	void64 operator new		(size_t _Size);
	__void operator delete	(void64 _Dst );
};


template <unsigned __int64 __size_l, typename __type>
inline void64 allocator64<__size_l, __type>::operator new (size_t _Size) { 
	return pool.hold_mem ();
};

template <unsigned __int64 __size_l, typename __type>
inline __void allocator64<__size_l, __type>::operator delete (void64 _Dst ) { 
	pool.free_mem (_Dst);
};

template <unsigned __int64 __size_l, typename __type>
inline __void allocator64<__size_l, __type>::mem_pool::mem_page::init ()
{
	ufree = __size_l;
	uint64 usize = sizeof (__type);
	for (uint64 i = 0; i < __size_l; i++)
		uorder [i] = i * usize;
	page = malloc (__size_l * usize);
}

template <unsigned __int64 __size_l, typename __type>
inline allocator64<__size_l, __type>::mem_pool::mem_pool ()
{
	hpagelist	= reinterpret_cast<HPAGELIST>(malloc (0));
	ucount		= 0;
}

template <unsigned __int64 __size_l, typename __type>
inline void64 allocator64<__size_l, __type>::mem_pool::hold_mem ()
{
	for (uint64 i = 0; i < ucount; i++) {
		if (hpagelist[i]->ufree > 0) {
			HPAGE& hpage  = hpagelist[i];
			uint64 offset = hpage->uorder[--hpage->ufree];
			return (void64)((uint64)(hpage->page) +offset);
		}
	}

	hpagelist			 = reinterpret_cast<HPAGELIST>	(realloc (hpagelist, ++ucount * 4));
	hpagelist [ucount-1] = reinterpret_cast<HPAGE>		(malloc (sizeof (PAGE)));
	hpagelist [ucount-1]->init ();

	return hold_mem ();
}

template <unsigned __int64 __size_l, typename __type>
inline __void allocator64<__size_l, __type>::mem_pool::free_mem (void64 _Dst)
{
	for (uint64 i = 0; i < ucount; i++) {
		uint64 uidx = ((uint64)_Dst - (uint64)(hpagelist[i]->page)) / sizeof (__type);
		if (uidx >= 0 && uidx < __size_l) {
			hpagelist[i]->uorder[hpagelist[i]->ufree] = uidx;
			if (--hpagelist[i]->ufree <= 0) {
				free (hpagelist[i]->page);
				free (hpagelist[i]);
				if (i != ucount)
					hpagelist[i] = hpagelist[--ucount];
			}
			break;
		}
	}
}
