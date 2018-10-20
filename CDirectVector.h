class CDirectVector
{
public:
	zVEC3 vtAt;		// X
	zVEC3 vtUp;		// Y
	zVEC3 vtRight;	// Z
	zVEC3 vtPos;	// XYZ



	zVEC3& operator[](int);

	CDirectVector();
	CDirectVector(zCVob*);





};

extern CDirectVector* GetDirectVectorLocal(zCVob*);

/*
	[0]		[1 ]	[2 ]	-- AtVector
	[3]		[4 ]	[5 ]	-- UpVector
	[6]		[7 ]	[8 ]	-- RightVector
	[9]		[10]	[11]	-- Translation
*/
