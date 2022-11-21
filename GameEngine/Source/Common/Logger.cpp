#include "GameEngine.h"
#include <fstream>
#include <ShlObj.h>
#include <filesystem>
#include <cstdio>
#include <TlHelp32.h>

Logger* Logger::inst;

Logger::Logger()
{
	inst = this;
}

Logger::~Logger()
{
}

VOID Logger::PrintLog(const WCHAR* fmt, ...)
{
	WCHAR buf[4096];
	va_list args;

	va_start(args, fmt);
	vswprintf_s(buf, fmt, args);
	va_end(args);

	std::wfstream outfile;
	outfile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	if (outfile.is_open())
	{
		std::wstring s = buf;
		s = L"[" + Time::GetDateTimeString() + L"] " + s + L"\n";
		outfile << s;
		outfile.close();
		OutputDebugString(s.c_str());
	}
	else
	{
		MessageBox(nullptr, L"Unable to open log file....", L"Log Error", MB_OK);
	}
}

/* Get and Create Log Director in AppData/$ProjectName/Log */
std::wstring Logger::LogDirectory()
{
	WCHAR Path[1024];
	GetModuleFileNameW(nullptr, Path, 1024);
	std::filesystem::path sPath = std::filesystem::path{ Path }.parent_path() / "";


	std::wstring StringPath = sPath.wstring();
	const WCHAR* AppDataLocal = StringPath.c_str();
	//SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &AppDataLocal);
	wcscpy_s(Path, AppDataLocal);
	//wcscat_s(Path, L"\\");
	//wcscat_s(Path, GameSettings::GetName());
	//CreateDirectory(Path, NULL);
	wcscat_s(Path, L"\\Log");
	CreateDirectory(Path, NULL);
	return Path;
}

std::wstring Logger::LogFile()
{
	WCHAR File[1024];
	wcscpy_s(File, GameSettings::GetName());
	wcscat_s(File, GameSettings::BootTime());
	wcscat_s(File, L".log");
	return File;
}

void Logger::PrintDebugSeparator()
{
	std::wstring s = L"--------------------------------------------------------";
	PrintLog(s.c_str());
}

bool Logger::IsMTailRunning()
{
	bool exists = false;
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry))
	{
		while (Process32Next(snapshot, &entry))
		{
			if (!_wcsicmp(entry.szExeFile, L"mTail.exe"))
			{
				exists = true;
			}
		}
	}

	CloseHandle(snapshot);

	return exists;
}

void Logger::StartMTail()
{
	if (IsMTailRunning())
	{
		Logger::PrintLog(L"--MTail failed to start - Already Running");
		return;
	}

	Logger::PrintLog(L"--Starting MTail");
	WCHAR path[MAX_PATH] = { 0 };
	GetCurrentDirectoryW(MAX_PATH, path);
	std::wstring url = path + std::wstring(L"/mTail.exe");
	std::wstring params = L" \"" + LogDirectory() + L"/" + LogFile() + L"\" /start";
	ShellExecute(0, NULL, url.c_str(), params.c_str(), NULL, SW_SHOWDEFAULT);

}
