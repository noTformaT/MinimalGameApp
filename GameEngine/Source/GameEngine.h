#pragma once

#ifdef WIN32
#include <Windows.h>
#endif

#ifdef BUILD_DLL
	#define ENGINE_API __declspec(dllexport)
#else
	#define ENGINE_API __declspec(dllimport)
#endif // BUILD_DLL

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)

#include "Common/Time.h"
#include "Common/Logger.h"
#include "Core/GameSettings.h"