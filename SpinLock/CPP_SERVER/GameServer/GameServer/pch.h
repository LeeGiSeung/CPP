#pragma once
#define WIN32_LEAN_AND_MEAN

#include "CorePch.h"
#ifdef  _DEBUG
#pragma comment(lib, "Debug\\ServerCore.lib")
#else
#pragma comment(lib, "Release\\ServerCore.lib")
#endif //  _DEBUG

