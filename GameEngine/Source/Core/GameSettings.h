#pragma once


class ENGINE_API GameSettings
{
private:
	static GameSettings* inst;

public:
	static GameSettings* Instance() { return inst; }

public:
	GameSettings();
	~GameSettings();

private:
	WCHAR m_GameName[MAX_NAME_STRING];
	WCHAR m_ShortName[MAX_NAME_STRING];
	HICON m_MainIcon;
	WCHAR m_BootTime[MAX_NAME_STRING];

public:
	static WCHAR* GetName();
	static VOID SetGameName(UINT id);

	static WCHAR* ShortName();
	static VOID SetShortName(UINT id);

	static HICON MainIcon();
	static VOID SetMainIcon(UINT id);

	static WCHAR* BootTime();
};