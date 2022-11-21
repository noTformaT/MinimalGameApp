#include "pch.h"
#include "Application.h"
#include "Platform/WIN32/WinEntry.h"

ENTRYAPP(Application)

Application::Application()
{
}

Application::~Application()
{
}

VOID Application::SetupGameSettings()
{
	GameSettings::SetGameName(IDS_GAMENAME);
	GameSettings::SetShortName(IDS_SHORTNAME);
	GameSettings::SetMainIcon(IDI_MAIN_ICON);
}

VOID Application::Initialize()
{
	Logger::PrintDebugSeparator();
	Logger::PrintLog(L"Application Starting");
	Logger::PrintLog(L"Game Name: %s", GameSettings::GetName());
	Logger::PrintLog(L"Boot Time: %s", Time::GetDateTimeString().c_str());
	Logger::PrintDebugSeparator();
}

VOID Application::Update()
{
	
}
