#include "GameEngine.h"
#include <ctime>
#include <sstream>
#include <iomanip>

std::wstring ENGINE_API Time::GetTime(bool stripped)
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	std::wstringstream wws;
	wws << std::put_time(&ltm, L"%T");

	std::wstring timeString = wws.str();

	if (stripped)
	{
		std::wstring chars = L":";
		for (WCHAR c : chars)
		{
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
		}
	}

	return timeString;
}

std::wstring ENGINE_API Time::GetDate(bool stripped)
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	std::wstringstream wws;
	wws << std::put_time(&ltm, L"%d/%m/%y");

	std::wstring timeString = wws.str();

	if (stripped)
	{
		std::wstring chars = L"/";
		for (WCHAR c : chars)
		{
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
		}
	}

	return timeString;
}

std::wstring ENGINE_API Time::GetDateTimeString(bool stripped)
{
	std::wstring timeString = GetDate(stripped) + L" " + GetTime(stripped);

	if (stripped)
	{
		std::wstring chars = L" ";
		for (WCHAR c : chars)
		{
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
		}
	}

	return timeString;
}
