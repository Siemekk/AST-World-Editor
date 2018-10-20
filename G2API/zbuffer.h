
#ifndef _ZBUFFER
#define _ZBUFFER

#include "ztypes.h"

class zSTRING;
class zCObject;

enum zTBufferMode
{
	zTBUF_READ,		
	zTBUF_WRITE,	
	zTBUF_NONE		
};

class zCBuffer				
{
	friend BOOL operator==(zCBuffer const&, zCBuffer const&);
	zTBufferMode	mode;

	
	BYTE*			buffer;	

	
	DWORD			pos_byte;
	DWORD			pos_bit;

	
	DWORD			maxsize_byte;
	DWORD			maxsize_bit;

	
	DWORD			size_byte;
	DWORD			size_bit;	

	BYTE			vobNr;
	bool			allocated;	
	bool			bits_written;	
	bool			buffer_error;
public:
	void zBuffer(zCBuffer const&)
	{
		XCALL(0x00441AF0);
	};

	zCBuffer(zCBuffer const& buf)
	{
		zBuffer(buf);
	};

	void zBuffer(void)
	{
		XCALL(0x00440AF0);
	};

	zCBuffer(void)
	{
		zBuffer();
	};

	void zBuffer(unsigned long const&)
	{
		XCALL(0x00440B70);
	};

	zCBuffer(unsigned long const& size)
	{
		zBuffer(size);
	};

	void zBuffer(void*,unsigned long const& )
	{
		XCALL(0x00440BF0);
	};

	zCBuffer(void* ptr,unsigned long const& size)
	{
		zBuffer(ptr,size);
	};

	void Init(void)
	{
		XCALL(0x00440C40);
	};

	zTBufferMode SetMode(zTBufferMode)
	{
		XCALL(0x00440CA0);
	};

	void Reset(void)
	{
		XCALL(0x00440CB0);
	};

	void Resize(unsigned long)
	{
		XCALL(0x00440CD0);
	};

	unsigned long Write(void const*,unsigned long)
	{
		XCALL(0x00440D60);
	};

	unsigned long WriteBits(void const*,unsigned long)
	{
		XCALL(0x00440D80);
	};

	unsigned long WriteBool(int,int)
	{
		XCALL(0x00440F00);
	};

	unsigned long WriteByte(unsigned char,int)
	{
		XCALL(0x00440F20);
	};

	unsigned long WriteWord(unsigned short,int)
	{
		XCALL(0x00440F40);
	};

	unsigned long WriteDWord(unsigned long,int)
	{
		XCALL(0x00440F60);
	};

	unsigned long WriteReal(float,int)
	{
		XCALL(0x00440F80);
	};

	unsigned long WriteInt(int,int)
	{
		XCALL(0x00440FA0);
	};

	unsigned long WriteFloat(float,int)
	{
		XCALL(0x00440FC0);
	};

	unsigned long WriteFloatPacked0_16(float)
	{
		XCALL(0x00440FE0);
	};

	unsigned long WriteFloatPacked0_8(float)
	{
		XCALL(0x00441010);
	};

	unsigned long WriteFloatPacked8_8(float)
	{
		XCALL(0x00441040);
	};

	unsigned long WriteString(zSTRING)
	{
		XCALL(0x004410B0);
	};

	void CompleteByte(void)
	{
		XCALL(0x00441130);
	};

	unsigned long Read(void*,unsigned long)
	{
		XCALL(0x00441160);
	};

	unsigned long ReadBits(void*,unsigned long)
	{
		XCALL(0x00441180);
	};

	int ReadBool(int)
	{
		XCALL(0x00441240);
	};

	unsigned char ReadByte(int)
	{
		XCALL(0x00441260);
	};

	unsigned short ReadWord(int)
	{
		XCALL(0x00441280);
	};

	unsigned long ReadDWord(int)
	{
		XCALL(0x004412B0);
	};

	float ReadReal(int)
	{
		XCALL(0x004412E0);
	};

	int ReadInt(int)
	{
		XCALL(0x00441300);
	};

	float ReadFloat(int)
	{
		XCALL(0x00441320);
	};

	float ReadFloatPacked0_16(void)
	{
		XCALL(0x00441340);
	};

	float ReadFloatPacked0_8(void)
	{
		XCALL(0x00441370);
	};

	float ReadFloatPacked8_8(void)
	{
		XCALL(0x004413A0);
	};

	zSTRING ReadString(void)
	{
		XCALL(0x004413D0);
	};

	void SetPos(unsigned long const&)
	{
		XCALL(0x004415B0);
	};

	void SetBitPos(unsigned long const&)
	{
		XCALL(0x004415D0);
	};

	unsigned long SetPosRel(int)
	{
		XCALL(0x004415F0);
	};

	unsigned long SetBitPosRel(int)
	{
		XCALL(0x00441610);
	};

	void SetPosBegin(void)
	{
		XCALL(0x00441630);
	};

	void SetPosEnd(void)
	{
		XCALL(0x00441640);
	};

	unsigned long GetPos(void)const 
	{
		XCALL(0x00441660);
	};

	unsigned long GetBitPos(void)const 
	{
		XCALL(0x00441670);
	};

	unsigned long GetMaxSize(void)const 
	{
		XCALL(0x00441680);
	};

	unsigned long GetBitMaxSize(void)const 
	{
		XCALL(0x00441690);
	};

	unsigned long GetSize(void)const 
	{
		XCALL(0x004416A0);
	};

	unsigned long GetBitSize(void)const 
	{
		XCALL(0x004416B0);
	};

	unsigned long GetRestSize(void)const 
	{
		XCALL(0x004416C0);
	};

	unsigned long GetBitRestSize(void)const 
	{
		XCALL(0x004416D0);
	};

	unsigned char* GetBuffer(void)const 
	{
		XCALL(0x004416E0);
	};

	unsigned char* GetCursor(void)const 
	{
		XCALL(0x004416F0);
	};

	void SkipByte(void)
	{
		XCALL(0x00441700);
	};

	int GetBitSizeToNextByte(void)const 
	{
		XCALL(0x00441730);
	};

	bool HasError(void)const 
	{
		XCALL(0x00441740);
	};

	unsigned long WriteObject(zCObject*&)
	{
		XCALL(0x00441780);
	};

	unsigned long ReadObject(zCObject*&)
	{
		XCALL(0x00441900);
	};

	zCBuffer& operator=(zCBuffer const&)
	{
		XCALL(0x00441B40);
	};

	void CopyFrom(zCBuffer const&)
	{
		XCALL(0x00441B60);
	};

	static void ByteFreq_Reset(void)
	{
		XCALL(0x00441BE0);
	};

	void ByteFreq_Analyse(void)
	{
		XCALL(0x00441C00);
	};

	static void ByteFreq_Print(void)
	{
		XCALL(0x00441C30);
	};

	virtual ~zCBuffer()
	{
		XCALL(0x00440C70);
	};
};

#endif
