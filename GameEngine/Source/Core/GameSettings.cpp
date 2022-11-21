#include "GameEngine.h"

GameSettings* GameSettings::inst;

GameSettings::GameSettings()
{
	inst = this;

	wcscpy_s(inst->m_GameName, L"undefined");
	wcscpy_s(inst->m_ShortName, L"undefined");
	wcscpy_s(inst->m_BootTime, Time::GetDateTimeString(true).c_str());
}

GameSettings::~GameSettings()
{
}

WCHAR* GameSettings::GetName()
{
	return inst->m_GameName;
}

VOID GameSettings::SetGameName(UINT id)
{
	LoadString(HInstance(), id, inst->m_GameName, MAX_NAME_STRING);
}

WCHAR* GameSettings::ShortName()
{
	return inst->m_ShortName;
}

VOID GameSettings::SetShortName(UINT id)
{
	LoadString(HInstance(), id, inst->m_ShortName, MAX_NAME_STRING);
}

HICON GameSettings::MainIcon()
{
	return inst->m_MainIcon;
}

VOID GameSettings::SetMainIcon(UINT id)
{
	LoadIcon(HInstance(), MAKEINTRESOURCE(id));
}

WCHAR* GameSettings::BootTime()
{
	return inst->m_BootTime;
}
