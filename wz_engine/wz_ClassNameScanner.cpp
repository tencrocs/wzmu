// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include "stdafx.h"
#include "config.h"

void Msg_CN_Br(){
	MessageBoxA(NULL,"CN-Scan\n\nConteúdo suspeito detectado!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);	
} 

void Msg_CN_En(){
	MessageBoxA(NULL,"CN-Scan\n\nAn illegal choice haas been detected!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);	
} 

void ClasseWindow(LPCSTR WindowClasse){
	HWND WinClasse = FindWindowExA(NULL,NULL,WindowClasse,NULL);
	if( WinClasse > 0)
	{
	if (carrega.Log_Txt_Hack == 1){
    using namespace std;
    ofstream out("GameGuard/Log.txt", ios::app);
    out << "\n CN-Scan: ", out <<   WindowClasse;
}
    if (carrega.Message_Warning_En == 1){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_CN_En),NULL,0,0);
  	Sleep(5000); 
	ExitProcess(0);	
}
	if (carrega.Message_Warning_En == 2){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_CN_Br),NULL,0,0);
  	Sleep(5000); 
	ExitProcess(0);	 
}
	if (carrega.Message_Warning_En == 0){
	ExitProcess(0);
	}
	else
	ExitProcess(0);
}
}
 
// Use = Handler 1.5 (by Oliver Bock) para encontrar a Classname das janelas 
// Non case sensitive

void ClasseCheckWindow(){    
	//ClasseWindow("ConsoleWindowClass");  // Prompt de comando 
	//ClasseWindow("ThunderRT6FormDC");    //autoclic Klic0r
	ClasseWindow("PROCEXPL");             // Process explorer
	ClasseWindow("TreeListWindowClass");  // Process explorer (Process windows)
	ClasseWindow("ProcessHacker");        // Process Hacker	
	ClasseWindow("PhTreeNew");            // Process Hakcer (Process windows)
	ClasseWindow("RegEdit_RegEdit");      // Regedit
	ClasseWindow("0x150114 (1376532)");   // Win 7 - System configuration
	ClasseWindow("SysListView32");        // Lista de processos do process explorer
	ClasseWindow("Tmb");
	ClasseWindow("TformSettings");
	ClasseWindow("Afx:400000:8:10011:0:20575");
	ClasseWindow("TWildProxyMain");
	ClasseWindow("TUserdefinedform");
	ClasseWindow("TformAddressChange");
	ClasseWindow("TMemoryBrowser");
	ClasseWindow("TFoundCodeDialog");
	}

void CN_Scan(){
	again:
    ClasseCheckWindow();
    Sleep(30000);
    goto again;
}

void ZProtectionMain(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(CN_Scan),NULL,0,0);
}


