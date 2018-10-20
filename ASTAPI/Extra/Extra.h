#define NULLSTR		""
#define NOT_FOUND	-1
#define _swap(a, b) { auto c = a; a = b; b = c; }
#define memsize(dst) _msize(dst)

// строковые операции над памятью
#define _memcpy_s(dst, src, sz)						memcpy		(dst, src, (sz)+1)
#define _memmove_s(dst, src, sz)					memmove		(dst, src, (sz)+1)
#define _malloc_s(sz)			static_cast<char*>  (malloc		(sz+1))
#define _realloc_s(dst, sz)		static_cast<char*>  (realloc	(dst, (sz)+1))
#define _free_s(dst)								free		(dst)
#define _memsize_s(dst)								_msize		(dst)-1
#define _to_int_s(dst)								atoi		(dst)
#define _to_float_s(dst)		static_cast<float>  (atof		(dst))
#define _to_double_s(dst)							atof		(dst)


#include "CMemPool.h"
#include "CArray.h"
#include "CList.h"
#include "CString.h"