// Video tutorial: http://www.youtube.com/user/vertexbrasil
#define _CRT_SECURE_NO_DEPRECATE  // < this line disable: warning C4996: 'fopen': This function or variable may be unsafe. 
#include "StdAfx.h"

void Msg_I_Br()
{
MessageBoxA(NULL,"I-Scan\n\nA integridade do processo foi corrompida!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}
void Msg_I_En()
{
MessageBoxA(NULL,"I-Scan\n\nFile integrity violated!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}

int file_exists(const char *filename)
{
  FILE *arquivo;
  if(arquivo = fopen(filename, "r"))
  {	 
    fclose(arquivo);	
	return 1;	
  }
    return 0;
}


void Injetado(){

if (carrega.Log_Txt_Hack == 1){
using namespace std;
ofstream out("GameGuard/Log.txt", ios::app);
out << "\n I-Scan:  ", out << "File integrity violated!";
}
    if (carrega.Message_Warning_En == 1){
    CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_I_En),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);	
}
    if (carrega.Message_Warning_En == 2){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_I_Br),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);	
	}
	if (carrega.Message_Warning_En == 0){
	ExitProcess(0);
	}
	else
	ExitProcess(0);
}


void I_loop(){ 
     // [NAME.extension] Are NON case-sensitive.
	 if (GetModuleHandle("speedhack.dll")    || 
		(GetModuleHandle("speed-hack.dll"))  ||
		(GetModuleHandle("speed-hack.dll"))  ||
		(GetModuleHandle("speed_hack.dll"))  ||
		(GetModuleHandle("hack_speed.dll"))  ||
		(GetModuleHandle("hack-speed.dll"))  ||
		(GetModuleHandle("hackspeed.dll"))   ||
		(GetModuleHandle("hack.dll"))        ||
	    (GetModuleHandle("wpepro.dll"))      ||
		(GetModuleHandle("Cr4ck3r.dll"))     ||
		(GetModuleHandle("wpeprospy.dll"))   ||
        (GetModuleHandle("engine.dll"))      || 
		(GetModuleHandle("CheatEngine.dll")) || 
		(GetModuleHandle("c.e.dll"))         || 
		(GetModuleHandle("cheat.dll"))       || 
      //(GetModuleHandle("FoxAnti.dll"))     ||  // To tests
        (GetModuleHandle("smoll.dll"))        )
	{
     Injetado();
	 }
	 else
	 Sleep(100);
	 }

void I_Scan(){
	again:
    I_loop();
    Sleep(58000);
    goto again;
}

void Dll_Inject(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(I_Scan),NULL,0,0);
}



/*
Another option:
 HANDLE Dll = LoadLibraryA("FoxAnti.dll");
 if(Dll != NULL)
 Msg_I();
}
*/