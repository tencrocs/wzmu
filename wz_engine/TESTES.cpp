// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include "stdafx.h"
#include "config.h"


void Msg_TESTE(){
	MessageBoxA(NULL,"Teste-Scan\n\nTESTES! Administrador este é o SISTEMA DE TESTES!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
	}

void DOWN_TESTE(){
//////////////////








}
//////////////////
void UP_TESTE(){
	again:
    DOWN_TESTE();
    Sleep(1000);
    goto again;
}

void TESTE(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(UP_TESTE),NULL,0,0);	
}




