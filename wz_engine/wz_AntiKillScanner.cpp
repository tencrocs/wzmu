// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include "stdafx.h"
#include "config.h"

#define Exe_Name PROCESSENTRY32 *pe32 = GetProcessInfo (carrega.Nome_do_Main) 
#define Threads (pe32->cntThreads)
#define Ativa_DC (carrega.Dont_kill_yet)    
#define NumeroMinimo (carrega.Minimum_thread) 

void Msg_K_Br(){
	MessageBoxA(NULL,"K-Scan\n\nA integridade do processo foi corrompida!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
	}
void Msg_K_En(){
	MessageBoxA(NULL,"K-Scan\n\nFile Integrity violated!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
	}

void DC(){
	 if (carrega.Log_Txt_Hack == 1){
using namespace std;
ofstream out("GameGuard/Log.txt", ios::app);
out << "\n K-Scan:  ", out <<   "Thread attack!";
}
    if (carrega.Message_Warning_En == 1){
    CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_K_En),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);	
}
    if (carrega.Message_Warning_En == 2){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_K_Br),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);	
	}
	if (carrega.Message_Warning_En == 0){
	ExitProcess(0);
	}
	else
	ExitProcess(0);
}

 
PROCESSENTRY32 *GetProcessInfo(char *szExeFile)
{
	PROCESSENTRY32  *pe32 = new PROCESSENTRY32 
	[sizeof(PROCESSENTRY32)];
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if(hSnapshot == INVALID_HANDLE_VALUE)
    return NULL;	 
    if(!Process32First(hSnapshot, pe32)) 
	{
        CloseHandle(hSnapshot);
        return NULL;        
    }
    while(Process32Next( hSnapshot, pe32 ))
	{
		if( strcmp(szExeFile, pe32->szExeFile) == 0) 
		{		
			CloseHandle(hSnapshot);
			return pe32;
		}
    } 
	return NULL;
	}

//A 1///////////////////////////////////////////////////////////////////

void k1(){	          
	Exe_Name;
	if ((Ativa_DC == 1) && (Threads == NumeroMinimo -1))
	DC();
	}


	void A1(){	    
    again:
	Sleep (20000);
    k1();
    goto again;
	}

void AntiKill1(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(A1),NULL,0,0);
}
//A 2///////////////////////////////////////////////////////////////////
void k2(){	             
	Exe_Name;	
	if ((Ativa_DC == 1) && (Threads == NumeroMinimo -1))
	DC();
	}

	void A2(){	    
    again:
	Sleep (22100);
    k2();
    goto again;
	}
void AntiKill2(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(A2),NULL,0,0);
}
//A 3///////////////////////////////////////////////////////////////////
void k3(){	             
	Exe_Name;	
	if (Ativa_DC == 1)
	if ((Ativa_DC == 1) && (Threads == NumeroMinimo -1))
	DC();
	}

	void A3(){	    
    again:
	Sleep (24200);
    k3();
    goto again;
	}
void AntiKill3(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(A3),NULL,0,0);
}
//A 4///////////////////////////////////////////////////////////////////
void k4(){	             
	Exe_Name;	
	if ((Ativa_DC == 1) && (Threads == NumeroMinimo -1))
	DC();
	}

	void A4(){	    
    again:
	Sleep (26300);
    k4();
    goto again;
	}
void AntiKill4(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(A4),NULL,0,0);
}
//A 5///////////////////////////////////////////////////////////////////
void k5(){	             
	Exe_Name;	
	if ((Ativa_DC == 1) && (Threads == NumeroMinimo -1))
	DC();
	}

	void A5(){	    
    again:
	Sleep (28400);
    k5();
    goto again;
	}
void AntiKill5(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(A5),NULL,0,0);
}
//A 6///////////////////////////////////////////////////////////////////
void k6(){	             
	Exe_Name;		
	if ((Ativa_DC == 1) && (Threads == NumeroMinimo -1))
	DC();
	}

	void A6(){	    
    again:
	Sleep (30500);
    k6();
    goto again;
	}
void AntiKill6(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(A6),NULL,0,0);
}
//A 7///////////////////////////////////////////////////////////////////
void k7(){	             
	Exe_Name;	
	if ((Ativa_DC == 1) && (Threads == NumeroMinimo -1)) 
	DC();
	}

	void A7(){	    
    again:
	Sleep (32600);
    k7();
    goto again;
	}
void AntiKill7(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(A7),NULL,0,0);
}
//A 8///////////////////////////////////////////////////////////////////
void k8(){	             
	Exe_Name;	
	if ((Ativa_DC == 1) && (Threads == NumeroMinimo -1))
	DC();
	}

	void A8(){	    
    again:
	Sleep (34700);
    k8();
    goto again;
	}
void AntiKill8(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(A8),NULL,0,0);
}
//A 9///////////////////////////////////////////////////////////////////
void k9(){	             
	Exe_Name;	
	if ((Ativa_DC == 1) && (Threads == NumeroMinimo -1))
	DC();
	}

	void A9(){	    
    again:
	Sleep (36800);
    k9();
    goto again;
	}
void AntiKill9(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(A9),NULL,0,0);
}

//A 10///////////////////////////////////////////////////////////////////
void k10 (){	             
	Exe_Name;	
	if ((Ativa_DC == 1) && (Threads == NumeroMinimo -1))
	DC();
	}

	void A10(){	    
    again:
	Sleep (38900);
    k10();
    goto again;
	}
void AntiKill10(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(A10),NULL,0,0);
}


