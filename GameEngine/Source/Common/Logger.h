#pragma once

#include <string>

class ENGINE_API Logger
{
private:
	static Logger* inst;

public:
	static Logger* Instance() { return inst; }

public:
	Logger();
	
	~Logger();

	static VOID PrintLog(const WCHAR* fmt, ...);
	
	static std::wstring LogDirectory();
	
	static std::wstring LogFile();

	static void PrintDebugSeparator();

	static bool IsMTailRunning();

	static void StartMTail();
};