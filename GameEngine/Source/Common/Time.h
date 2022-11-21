#pragma once
#include <string>

namespace Time
{
	/* Get current time in string format */
	std::wstring ENGINE_API GetTime(bool stripped = false);

	/* Get current date in string format */
	std::wstring ENGINE_API GetDate(bool stripped = false);

	/* Get current date and time in string format */
	std::wstring ENGINE_API GetDateTimeString(bool stripped = false);
}