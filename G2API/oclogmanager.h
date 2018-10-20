#pragma once


class oCLogEntry
{
	zSTRING		m_sDescription;
public:
	void Archive(zCArchiver&)
	{
		XCALL(0x00663D10);
	};

	void Unarchive(zCArchiver&)
	{
		XCALL(0x00663D30);
	};

	~oCLogEntry(void)
	{
		XCALL(0x00663DF0);
	};
};


class oCLogTopic	
{
	friend int extGetTopicStatus();
	zSTRING				m_sTopic;
	int					m_nSection;	
	int					m_nStatus;	
	zCList<oCLogEntry>	m_lstEntry;	
public:
	
	~oCLogTopic(void)
	{
		XCALL(0x00663550);
	};

	void __fastcall AddEntry(zSTRING const&)
	{
		XCALL(0x00663870);
	};

	void __fastcall Archive(zCArchiver&)
	{
		XCALL(0x00663A80);
	};

	void __fastcall Unarchive(zCArchiver&)
	{
		XCALL(0x00663B40);
	};
};


class oCLogManager
{
	friend int extGetTopicStatus();
	zCList<oCLogTopic>	m_lstTopic;
	
public:
	static oCLogManager& GetLogManager(void)
	{
		XCALL(0x00663370);
	};

	oCLogManager& operator=(oCLogManager const&)
	{
		XCALL(0x006633C0);
	};

	oCLogManager(oCLogManager const&)
	{
		XCALL(0x006633D0);
	};

	void oLogManager(void)
	{
		XCALL(0x006633F0);
	};

	oCLogManager(void)
	{
		oLogManager();
	};

	~oCLogManager(void)
	{
		XCALL(0x00663400);
	};

	void __fastcall Clear(void)
	{
		XCALL(0x006634E0);
	};

	void __fastcall Archive(zCArchiver&)
	{
		XCALL(0x00663640);
	};

	void __fastcall Unarchive(zCArchiver&)
	{
		XCALL(0x006636B0);
	};
};

