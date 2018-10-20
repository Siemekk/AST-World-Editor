class CListBase
{
protected:

	void32		data;
	CListBase*	next;

public:	
	
	ASTAPI CListBase					();
	ASTAPI CListBase*	GetNext			();
	ASTAPI void32		GetData			();
	ASTAPI void			Insert			(void32 obj);
	ASTAPI void			Remove			(void32 obj);
	ASTAPI BOOL			IsInList		(void32 obj);
	ASTAPI CListBase*	GetAt			(const uint32& idx);
	ASTAPI CListBase&	operator []		(const uint32& idx);
	ASTAPI uint32		GetNumInList	();
	ASTAPI operator		void32			() const;
	ASTAPI void			DeleteList		();
	ASTAPI void			DeleteListDatas ();
	ASTAPI ~CListBase					();
};