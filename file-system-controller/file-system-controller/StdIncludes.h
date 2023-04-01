#ifndef STD_INCLUDES_H
#define STD_INCLUDES_H

// standard headers
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cinttypes>
#include <stdio.h>
#include <thread>

// project headers
#include "Singleton.h"

// OS specific includes and defines
#ifdef _WIN32
#include <Windows.h>
#include <direct.h>
#define M_ASSERT(_cond, _msg) \
	if (!(_cond)) { \
		OutputDebugStringA(_msg); std::abort(); \
	}
#define GetCWD _getcwd
#else
#include <unistd.h>
#define GetCWD getcwd
#endif

using namespace std;

#endif// STD_INCLUDES_H
