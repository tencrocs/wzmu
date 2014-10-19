// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include "stdafx.h"
#include "config.h"

void Msg_PC_Br(){
	MessageBoxA(NULL,"PID-Scan\n\nConteúdo suspeito detectado!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);	
} 

void Msg_PC_En(){
	MessageBoxA(NULL,"PID-Scan\n\nAn illegal choice haas been detected!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);	
} 

	void GetProcId(char* ProcName){
    PROCESSENTRY32 pe32;
    HANDLE hSnapshot = NULL;

	pe32.dwSize = sizeof( PROCESSENTRY32 );
    hSnapshot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );

    if( Process32First( hSnapshot, &pe32 )){
        do{
            if( strcmp( pe32.szExeFile, ProcName ) == 0 )
            {
    if (carrega.Log_Txt_Hack == 1){	
	using namespace std;
    ofstream out("GameGuard/Log.txt", ios::app);
    out << "\n PID -Scan:  ", out << ProcName; 
}
    if (carrega.Message_Warning_En == 1){
    CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_PC_En),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);	
}
    if (carrega.Message_Warning_En == 2){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_PC_Br),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);	
}
	else 
	ExitProcess(0);	

            }
        }while( Process32Next( hSnapshot, &pe32 ) );
    }


    if( hSnapshot != INVALID_HANDLE_VALUE )
        CloseHandle( hSnapshot );   
}


void ClasseCheckPross(){ 
	// PID Detector are Case-sensitive!
	GetProcId("ollydbg.exe*32");
	GetProcId("ollydbg.exe");
	GetProcId("bvkhex.exe");
	GetProcId("HxD.exe");
    GetProcId("cheatengine-x86_64.exe");
	GetProcId("HxD.exe");
	GetProcId("Hide Toolz3.3.3.exe");
	GetProcId("SbieSvc.exe");    // < sandbox 
	GetProcId("SbieSvc*32.exe"); // < sandbox 
	GetProcId("SbieSvc*32.exe"); // < sandbox 
	GetProcId("SbieCtrl.exe");   // < sandbox 
	GetProcId("Start.exe");      // < sandbox 
}

void PC_Scan(){
	again:
    ClasseCheckPross();
    Sleep(33000);
    goto again;
}

void DetectID(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(PC_Scan),NULL,0,0);
	}

