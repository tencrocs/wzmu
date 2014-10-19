// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include "stdafx.h"
#include "config.h"

void Msg_La_Br(){
	MessageBoxA(NULL,"L-Scan\n\nO Launcher deve permanecer ativo durante a execução do jogo!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
	}
void Msg_La_En(){
	MessageBoxA(NULL,"L-Scan\n\nLauncher not found!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
	}


void Fecha_ativa(){
	if (carrega.Log_Txt_Hack == 1){	
	using namespace std;
    ofstream out("GameGuard/Log.txt", ios::app);
    out << "\n L-Scan:  Need start:", out <<   carrega.Launcher_Window;
	}

    if (carrega.Message_Warning_En == 1){
    //CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_La_En),NULL,0,0);
	//Sleep(1000);
	WinExec(carrega.Nome_do_Launcher, SW_SHOWNORMAL); 
	ExitProcess(0);	
}
    if (carrega.Message_Warning_En == 2){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_La_Br),NULL,0,0);
	Sleep(5000);
	WinExec(carrega.Nome_do_Launcher, SW_SHOWNORMAL);  
	ExitProcess(0);	
}
	if (carrega.Message_Warning_En == 0){
	ExitProcess(0);
	}
	else
	ExitProcess(0);
}

void Launcher_Name(){
	HWND WinTitle = FindWindowA(NULL, carrega.Launcher_Window);
	if( WinTitle == 0){
		Fecha_ativa();
}
}

void LA_Name(){
	again:
    Launcher_Name();
    Sleep(30000);
    goto again;
}

void LA_On_byName(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(LA_Name),NULL,0,0);	
}

