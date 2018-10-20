#pragma once
#pragma warning(disable:4731) 

#define XCALL(uAddr)			\
	__asm { mov esp, ebp	}	\
	__asm { pop ebp			}	\
	__asm { mov eax, uAddr	}	\
	__asm { jmp eax			}

#define XSTACK(uAddr)			\
	__asm { mov eax, [ebp+8] }	\
	__asm { mov uAddr, eax	 }


#define zLog(type,mess,level) zerr->Report(type, 0, mess, level, 0, __LINE__, __FILE__, NULL);

#define SAFE_DELETE(p)  do { if(p) { delete p; p = NULL;}} while(FALSE)

#define SAFE_DELETE_ARRAY(p)  do { if(p) { delete[] p; p = NULL; }} while(FALSE)

#define zADDREF(obj)			{(obj)->AddRef(); }
#define zRELEASE(obj) { if (obj) { obj->Release(); obj=0; }; };
#define zRELEASE_NONULL(obj)	{(obj)->Release(); }

#define THIS_OFFSET(x) (((char *)this) + (x))
#define PTR_OFFSET(This,x) (((char *)This) + (x))

#define INST_NOP 0x90

#define REPLACE_OP(addr, op) {unsigned char* a = (unsigned char*)addr; *a = op;}
#define REPLACE_CALL(addr, op) {REPLACE_OP(addr, op); \
	REPLACE_OP(addr+1, op); \
	REPLACE_OP(addr+2, op); \
	REPLACE_OP(addr+3, op); \
	REPLACE_OP(addr+4, op); }



#define REPLACE_RANGE(start, end_incl, op) {for(int i=start; i<=end_incl;i++){REPLACE_OP(i, op);}}



#define zCLASS(CLASSNAME)					\
	static void* operator new(size_t nSize) \
	{										\
		void* p = ::operator new(nSize);	\
		zCClassDef::ObjectCreated(			\
		(CLASSNAME*)p, classDef);			\
		return p;							\
	}										\
											\
	static void operator delete(void* p)	\
	{										\
		zCClassDef::ObjectDeleted(			\
		(CLASSNAME*)p, classDef);			\
		::operator delete(p);				\
	}										\

