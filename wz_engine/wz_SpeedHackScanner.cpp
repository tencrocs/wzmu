// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include "stdafx.h"

void Msg_S_Br(){
	MessageBoxA(NULL,"S-Scan\n\nConteúdo suspeito detectado!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
} 

void Msg_S_En(){
	MessageBoxA(NULL,"S-Scan\n\nAn illegal choice haas been detected!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
} 


void Speed_Scanner(){
    
int time = ::GetTickCount();
Sleep(10000);
int timeElapsed = ::GetTickCount() - time;
 
if ("%d\n", timeElapsed > 10500){ // velocidade máxima (em milisegundos) que não deve ser ultrapassada

if (carrega.Log_Txt_Hack == 1){
using namespace std;
ofstream out("GameGuard/Log.txt", ios::app);
out << "\n S-Scan: ", out <<  "Speed Hack";
}
    if (carrega.Message_Warning_En == 1){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_S_En),NULL,0,0);
  	Sleep(5000); 
	ExitProcess(0);	
}
	if (carrega.Message_Warning_En == 2){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_S_Br),NULL,0,0);
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


void Speed_Scan(){
	again:
    Speed_Scanner();
    Sleep(10000); 
    goto again;
}

void DetectSpeed(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Speed_Scan),NULL,0,0);	
}














