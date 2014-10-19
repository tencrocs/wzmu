// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include <windows.h>
#include <tlhelp32.h>
#include <process.h>
#include <fstream>
#include "winsock.h"

#include "config.h"
#include "Classe.h"
#include "CRC.h"
#include "Dump.h"

extern  "C"  __declspec(dllexport) void __cdecl wz_init(); //API (init da dll)