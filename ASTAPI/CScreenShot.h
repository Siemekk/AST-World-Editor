#pragma once

enum zTFmt_PrtScr
{
	JPEG,
	PNG,
	BMP
};

struct CScreenShot
{
	ASTAPI static void			SetFormat(const zTFmt_PrtScr&);
	ASTAPI static zTFmt_PrtScr	GetFormat();
	ASTAPI static void			Create(zSTRING name = "");
};