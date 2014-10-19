// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include "StdAfx.h"
#include "config.h"

CARREGAR carrega;

void Msg_Nomes_En(){
	MessageBoxA(NULL, "Warning! \n\nInvalid file name detected!", "Anti-Hack - Files", MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
   }	

void Msg_nomes_Br(){
MessageBoxA(NULL, "Alteração detectada! \n\nAtenção! Não modifique o nome dos arquivos do server!", "Anti-Hack - Arquivos", MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
   }	

	
void Nome_Scanner(){ 	
	char * Nome = carrega.Nome_do_Main;
	WIN32_FILE_ATTRIBUTE_DATA wfad;
	if(GetFileAttributesEx(Nome,GetFileExInfoStandard,&wfad) == 0){

if (carrega.Log_Txt_Hack == 1){	
using namespace std;
ofstream out("GameGuard/Log.txt", ios::app);
out << "\n F-Scan:  File Not Found!  ", out <<  Nome;
}
    if (carrega.Message_Warning_En == 1){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_Nomes_En),NULL,0,0);
Sleep (5000);	   
ExitProcess(0);
}
	if (carrega.Message_Warning_En == 2){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_nomes_Br),NULL,0,0);
Sleep (5000);	   
ExitProcess(0);
}
	if (carrega.Message_Warning_En == 0){
	ExitProcess(0);	
	}
else
ExitProcess(0);
}
}

  
void Nome_Scanner2(){ 
	char * Nome2 = carrega.Nome_do_Launcher;
	WIN32_FILE_ATTRIBUTE_DATA wfad;
   	if(GetFileAttributesEx(Nome2,GetFileExInfoStandard,&wfad) == 0){

if (carrega.Log_Txt_Hack == 1){	
using namespace std;
ofstream out("GameGuard/Log.txt", ios::app);
out << "\n F-Scan:  File Not Found!  ", out <<  Nome2;
}
    if (carrega.Message_Warning_En == 1){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_Nomes_En),NULL,0,0);
Sleep (5000);	   
ExitProcess(0);
}
	if (carrega.Message_Warning_En == 2){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_nomes_Br),NULL,0,0);
Sleep (5000);	   
ExitProcess(0);
}
	if (carrega.Message_Warning_En == 0){
	ExitProcess(0);	
	}
else
ExitProcess(0);
}
}

	
void Nome_Scan(){
again:
	Nome_Scanner();
	Nome_Scanner2();   
    Sleep(30000); 
    goto again;
}

void Nomes(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Nome_Scan),NULL,0,0);	
}








/*

void MainThread(void * lpParam)
{
while(true){
Check.Arquivos();
}
	_endthread();
}
*/