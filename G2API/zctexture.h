#pragma once

#include "zcresource.h"

class zCTextureExchange;
class zCTexture;
class zFILE;

class zCTextureFileFormat : public zCObject
{
public:
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x005F0D70);
	};

	virtual ~zCTextureFileFormat(void)
	{
		XCALL(0x005F0DB0);
	};
};

enum zTRnd_TextureFormat
{
	
	zTEX_FORMAT_B8G8R8A8,

	
	zTEX_FORMAT_R8G8B8A8,

	
	zTEX_FORMAT_A8B8G8R8,

	
	zTEX_FORMAT_A8R8G8B8,

	
	zTEX_FORMAT_B8G8R8,

	
	zTEX_FORMAT_R8G8B8,

	
	zTEX_FORMAT_A4R4G4B4,

	
	zTEX_FORMAT_A1R5G5B5,

	
	zTEX_FORMAT_R5G6B5,

	
	zTEX_FORMAT_P8,

	
	zTEX_FORMAT_DXT1,

	
	zTEX_FORMAT_DXT2,

	
	zTEX_FORMAT_DXT3,

	
	zTEX_FORMAT_DXT4,

	
	zTEX_FORMAT_DXT5,

	
	zTEX_FORMAT_15,

	
	zTEX_FORMAT_16
};

struct zCTextureInfo		
{
	zTRnd_TextureFormat	texFormat;
	int					sizeX;			
	int					sizeY;			
	int					numMipMap;

	
	int					refSizeX;
	int					refSizeY;

	
	zCOLOR				averageColor;
	zCTextureInfo()		{ memset (this, 0, sizeof(*this)); };
};





enum zTTexScaleSize
{
	zTEX_SIZE_0,
	zTEX_SIZE_1,
	zTEX_SIZE_2,
	zTEX_SIZE_3,
	zTEX_SIZE_4,
	zTEX_SIZE_5,
	zTEX_SIZE_6,
	zTEX_SIZE_7
};

enum zTTexScaleBPP
{
	zTEX_SCALE_BPP_0,
	zTEX_SCALE_BPP_1,
	zTEX_SCALE_BPP_2
};



struct zTexScaleSize		
{
	int		m_nScaleSize;		
	BOOL	m_bEveryCtr;		
	BOOL	m_bNoDesiredBPP;	
};

struct zTTexPalette		
{
	BYTE	blue;		
	BYTE	green;		
	BYTE	red;		
};


class zCTextureExchange				
{
public:												
	zVEC4 GetRGBAAtTexel(float, float)
	{
		XCALL(0x005F8340);
	};

	static int CopyContents(zCTextureExchange*,zCTextureExchange*)
	{
		XCALL(0x005F8180);
	};

	int GetMemSizeBytes(void)
	{
		XCALL(0x005F8290);
	};

	zVEC4 GetRGBAAtPtr(unsigned char*, zTTexPalette*,zTRnd_TextureFormat)
	{
		XCALL(0x005F88A0);
	};
};

class zCTexture : public zCResource, public zCTextureExchange			
{
public:
	enum zTTexFileDesiredBPP
	{
		zTEX_BPP_NONE,	
		zTEX_BPP_8BIT,	
		zTEX_BPP_16BIT,	
		zTEX_BPP_32BIT	
	};
	struct BIT_FLAGS
	{
		int			tAlpha:1;	
		int			tMulti:1;	
		int			tDynamic:1;	
		int			tTile:1;	
	};
	
	zCTexture*		m_NextTextureInChannel[3];		
	zCTexture*		m_PrevTextureInChannel[3];		
	int				m_nCurrentIndexInChannel[3];	
	int				m_nNumTexturesInChannel[3];		
	union
	{
		int			m_dwFlags;						
		BIT_FLAGS	ft;
	};
	static zCClassDef*		classDef;
	static char s_useDefaultTex;
	static char s_globalLoadTextures;
	static zTTexScaleSize s_texScaleSize;
	static zTTexScaleBPP s_texScaleBPP;
	static float s_texRefRAM;
	static zTTexFileDesiredBPP s_texRefBPP;
	static zTRnd_TextureFormat*& s_texDesiredBPPDefault;
	static zSTRING zTEX_DEFAULT_TEXTURE_FILE;
	static zSTRING* s_texDesiredBPPSuffix;
	static unsigned long s_texSupportedFormats;
	static unsigned long s_texMaxPixelSize;
public:
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x005F3400);
	};

	virtual ~zCTexture(void)
	{
		XCALL(0x005F34A0);
	};

	virtual int LoadResourceData(void)
	{
		XCALL(0x005F54D0);
	};

	virtual int ReleaseResourceData(void)
	{
		XCALL(0x005F5530);
	};

	virtual unsigned long GetResSizeBytes(void)
	{
		XCALL(0x005F5590);
	};

	virtual void GetCacheConfig(unsigned long&,unsigned long&)
	{
		XCALL(0x005F5720);
	};

	virtual int GetChromaKeyingEnabled(void)const 
	{
		XCALL(0x005F3420);
	};

	virtual void SetChromaKeyingEnabled(int)
	{
		XCALL(0x005F3430);
	};

	void zTexture(void)
	{
		XCALL(0x005F3390);
	};

	zCTexture(void)
	{
		zTexture();
	};

	void InitValues(void)
	{
		XCALL(0x005F3470);
	};

	static zCTexture* SearchName(zSTRING&)
	{
		XCALL(0x005F3550);
	};

	int IsLightmap(void)const 
	{
		XCALL(0x005F3570);
	};

	zCTexture* GetAniTexture(void)
	{
		XCALL(0x005F35C0);
	};

	void AddAniTex(int,zCTexture*)
	{
		XCALL(0x005F3620);
	};

	void PrecacheTexAniFrames(float)
	{
		XCALL(0x005F3660);
	};

	static zCTexture* Load(zSTRING&,int)
	{
		XCALL(0x005F36A0);
	};

	static zCTexture* LoadSingle(zSTRING&,int)
	{
		XCALL(0x005F4360);
	};

	static int Exists(zSTRING&)
	{
		XCALL(0x005F4510);
	};

	static void AutoDetectRendererTexScale(void)
	{
		XCALL(0x005F46E0);
	};

	static void RefreshTexMaxSize(int)
	{
		XCALL(0x005F4EA0);
	};

	static int ConvertTexture(zSTRING const&)
	{
		XCALL(0x005F59F0);
	};

	void ForceConvertAndReloadTexture(void)
	{
		XCALL(0x005F6170);
	};

	static zTRnd_TextureFormat CalcNextBestTexFormat(zTRnd_TextureFormat)
	{
		XCALL(0x005F6240);
	};

	static void CalcDesiredBPP(zSTRING const*,zCTexture::zTTexFileDesiredBPP&,zTRnd_TextureFormat&,int&)
	{
		XCALL(0x005F6340);
	};

	int LoadAndConvertInternal(zFILE&)
	{
		XCALL(0x005F64C0);
	};

	int SaveAndConvertInternal(zFILE&)
	{
		XCALL(0x005F6840);
	};

	int CacheInNamed(zSTRING const*)
	{
		XCALL(0x005F69E0);
	};

	int IsTextureTileBaseSlice(void)const 
	{
		XCALL(0x005F73F0);
	};

	int CreateTextureTile(zCTextureExchange*)
	{
		XCALL(0x005F7420);
	};

	void GetPixelSize(int&,int&)
	{
		XCALL(0x005F7C10);
	};

	static void ScanConvertTextures(zSTRING)
	{
		XCALL(0x005F7F40);
	};
};

class zCTextureConvert : public zCTextureExchange
{
public:
	zCTextureInfo	m_TexInfo;			
	BYTE*			m_pTextureBuf;		
	zTTexPalette	m_PaletteBuf[256];	
	int				unusedData;			
	int				m_bHasAlpha;		
	zCOLOR			unusedData2;		
	int				m_LockMode;			
	BOOL			m_bAccessLocked;	
	BOOL			m_bGreyDetails;		
public:
	zCOLOR GetAverageColor(void)
	{
		XCALL(0x0065B6E0);
	};

	int Lock(int)
	{
		XCALL(0x0065B840);
	};

	int Unlock(void)
	{
		XCALL(0x0065B860);
	};

	int SetTextureInfo(zCTextureInfo const&)
	{
		XCALL(0x0065B1C0);
	};

	zTTexPalette* GetPaletteBuffer(void)
	{
		XCALL(0x0065B290);
	};

	int GetTextureBuffer(int,void*&,int&)
	{
		XCALL(0x0065B2B0);
	};

	zCTextureInfo GetTextureInfo(void)
	{
		XCALL(0x0065B270);
	};

	int CopyPaletteDataTo(void*)
	{
		XCALL(0x0065B6B0);
	};

	int CopyTextureDataTo(int,void*,int)
	{
		XCALL(0x0065B480);
	};

	int HasAlpha(void)
	{
		XCALL(0x0065B6F0);
	};

	zVEC4 GetRGBAAtTexel(float,float)
	{
		XCALL(0x005F8340);
	};

	int ConvertTextureFormat(zCTextureInfo const&)
	{
		XCALL(0x006598E0);
	};

	void SetDetailTextureMode(int)
	{
		XCALL(0x0065B7A0);
	};
	int LoadFromFileFormat(zSTRING const&)
	{
		XCALL(0x005F4F30);
	};

	int SaveToFileFormat(zSTRING const&)
	{
		XCALL(0x005F5010);
	};

	int LoadFromFileFormat(zFILE&,zCTextureFileFormat*)
	{
		XCALL(0x005F50F0);
	};

	int SaveToFileFormat(zFILE&,zCTextureFileFormat*)
	{
		XCALL(0x005F5120);
	};

	int SaveInternal(zFILE&)
	{
		XCALL(0x005F5150);
	};

	int LoadInternal(zFILE&)
	{
		XCALL(0x005F51E0);
	};

	void ConvertToNewFormat(zTRnd_TextureFormat const&)
	{
		XCALL(0x005F5270);
	};

	void ConvertToNewSize(int,int)
	{
		XCALL(0x005F52A0);
	};

	void GenerateMipMaps(void)
	{
		XCALL(0x005F5390);
	};

	static int CalcNumMipMaps(unsigned long,unsigned long)
	{
		XCALL(0x005F53E0);
	};

	static void CorrectAspectRatio(int&,int&)
	{
		XCALL(0x005F5410);
	};

	static void CorrectPow2(int&,int&)
	{
		XCALL(0x005F5490);
	};
};


class zCLightMap : public zCObject		
{
public:
	zVEC3				m_vPosition;	
	zVEC3				m_vUpVector;	
	zVEC3				m_vRightVector;	
	zCTexture*			m_pTexture;		
	static zCClassDef			*classDef;
	void zLightMap(void)
	{
		XCALL(0x005F8EA0);
	};

	zCLightMap(void)
	{
		zLightMap();
	};

	void SetTexture(zCTexture*)
	{
		XCALL(0x005F8FD0);
	};

	void CalcLightmapOriginUpRight(zVEC3 const&,zVEC3 const&,zVEC3 const&)
	{
		XCALL(0x005F9010);
	};

	virtual ~zCLightMap()
	{
		XCALL(0x005F8F60);
	};
};

class zCTextureFileFormatInternal : public zCTextureFileFormat	
{
	zCTextureInfo			m_TexInfo;		
	int						m_nScaleSize;	
	ULONG					m_nMaxPixelSize;
	BOOL					m_bMessage;		
	static zCClassDef *classDef;
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x005F0BF0);
	};

	virtual ~zCTextureFileFormatInternal()
	{
		XCALL(0x005F2500);
	};

	virtual int LoadTexture(zFILE&,zCTextureExchange*)
	{
		XCALL(0x005F2840);
	};

	virtual int LoadTexture(zSTRING const&,zCTextureExchange*)
	{
		XCALL(0x005F28C0);
	};

	virtual int SaveTexture(zFILE&,zCTextureExchange*)
	{
		XCALL(0x005F2BC0);
	};

	virtual int SaveTexture(zSTRING const&,zCTextureExchange*)
	{
		XCALL(0x005F2C80);
	};

	virtual zSTRING const& GetFileExtension(void)const 
	{
		XCALL(0x005F2510);
	};

	virtual int CanSave(void)const 
	{
		XCALL(0x005F0C00);
	};

	virtual int CanLoad(void)const 
	{
		XCALL(0x005F0C10);
	};
};



struct zTHeaderTGA		
{
	BYTE				m_nAlphaBits;	
	bool				m_bColorMap;	
	BYTE				m_FormatTGA;	
	WORD				m_nStartMap;	
	WORD				m_nEntriesMap;	
	BYTE				m_nDepth;		
	int					us8;
	WORD				m_nWidth;		
	WORD				m_nHeight;		
	BYTE				m_nBPP;			
	BYTE				m_nAlphaDepth;	
};



class zCTextureFileFormatTGA : public zCTextureFileFormat	
{

	friend class zCTexture;
	zTHeaderTGA			m_Tga;			
	zTRnd_TextureFormat	m_TexFormat;	
	zCTextureInfo		m_Info;			
	BYTE*				m_pPaletteBuf;	
	BYTE*				m_pTextureBuf;	
	BYTE*				m_pDataBuf;		
	int					m_nSizeTexture;	
	BOOL				m_bRlePixel;	
	int					m_nBuferized;	
	int					m_nPixelBlock;	
	DWORD				m_PixelBuf[4];	
public:
	static zCClassDef *classDef;
	void zTextureFileFormatTGA(void)
	{
		XCALL(0x005F0C20);
	};

	zCTextureFileFormatTGA(void)
	{
		zTextureFileFormatTGA();
	};

	int ReadTGAHeader(zFILE*)
	{
		XCALL(0x005F0E10);
	};

	int ReadTGAColorMap(zFILE*)
	{
		XCALL(0x005F14F0);
	};

	int ReadTGARLEPixel(zFILE*,unsigned char*,int)
	{
		XCALL(0x005F1A70);
	};

	int ReadTGASpan(zFILE*,unsigned char*,int,int)
	{
		XCALL(0x005F1CE0);
	};

	int ReadTGAData(zFILE*)
	{
		XCALL(0x005F1DF0);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x005F08A0);
	};

	virtual ~zCTextureFileFormatTGA()
	{
		XCALL(0x005F0D50);
	};

	virtual int LoadTexture(zFILE&,zCTextureExchange*)
	{
		XCALL(0x005F2050);
	};

	virtual int LoadTexture(zSTRING const&,zCTextureExchange*)
	{
		XCALL(0x005F21C0);
	};

	virtual int SaveTexture(zFILE&,zCTextureExchange*)
	{
		XCALL(0x005F08C0);
	};

	virtual int SaveTexture(zSTRING const&,zCTextureExchange*)
	{
		XCALL(0x005F08B0);
	};

	virtual zSTRING const& GetFileExtension(void)const 
	{
		XCALL(0x005F0DC0);
	};

	virtual int CanSave(void)const 
	{
		XCALL(0x005F08D0);
	};

	virtual int CanLoad(void)const 
	{
		XCALL(0x005F08E0);
	};
};
