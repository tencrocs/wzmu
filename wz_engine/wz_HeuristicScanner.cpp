// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include "stdafx.h"
#include "config.h"

void Msg_H_Br(){	
	MessageBoxA(NULL,"H-Scan\n\nConteúdo suspeito detectado!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
	}
void Msg_H_En(){	
	MessageBoxA(NULL,"Antihack: Illegal operation detected!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
	}

void TxtCheckWindow(){
	POINT p;
	HWND DebugerFound = 0;
	for ( int qy = 0 ; qy < 100 ; qy++)	{
	for ( int qx = 0 ; qx < 100 ; qx++)	{
	p.x = qx * 20;
	p.y = qy * 20;	
	DebugerFound = WindowFromPoint(p);
	char t[255];
	GetWindowTextA( DebugerFound , t , 225); 
	
if (strstr(t,"Acelera")		||
	strstr(t,"acelera")  	||
	strstr(t,"Acelerador")	||	
	strstr(t,"acelerador")	||
	strstr(t,"BYPASS")	    ||
	strstr(t,"ByPass")		||
	strstr(t,"byPass")		||
	strstr(t,"Bypass")		||
	strstr(t,"CAPOTE")	    ||
	strstr(t,"Capote")	    ||
	strstr(t,"capote")	    ||	
	strstr(t,"CATASTROPHE")	||
	strstr(t,"Catastrophe")	||
	strstr(t,"catastrophe")	||
	strstr(t,"CHEAT")	    ||
	strstr(t,"Cheat")	    ||
	strstr(t,"cheat")	    ||
	strstr(t,"CHEATER")	    ||
	strstr(t,"Cheater")	    ||
	strstr(t,"cheater")	    ||
	strstr(t,"CHEATS")      ||
	strstr(t,"Cheats")      ||
	strstr(t,"cheats")      ||
	strstr(t,"DUPAR")		||
	strstr(t,"Dupar")		||
	strstr(t,"dupar")		||
	strstr(t,"DUPER")		||
	strstr(t,"Duper")		||
	strstr(t,"duper")		||
	strstr(t,"ENGINE")	    ||
	strstr(t,"Engine")	    ||
	strstr(t,"engine")	    ||
	strstr(t,"EXPLORER")	||
	strstr(t,"Explorer")	||
	strstr(t,"explorer")	||
	strstr(t,"PROCESS")	    ||
	strstr(t,"Process")	    ||
	strstr(t,"process")    	||
	strstr(t,"FREEZE")		||
	strstr(t,"Freeze")		||
	strstr(t,"freeze")		||
	strstr(t,"SPEED")       ||
	strstr(t,"Speed")       ||
	strstr(t,"Speed")       ||
	strstr(t,"HACK")		||
	strstr(t,"Hack")		||
	strstr(t,"hack")		||
	strstr(t,"HACKER")		||
	strstr(t,"Hacker")		||
	strstr(t,"hacker")		||
	strstr(t,"HIDE")		||
	strstr(t,"Hide")		||
	strstr(t,"hide")		||
	strstr(t,"TOOLZ")		||
	strstr(t,"Toolz")		||
	strstr(t,"toolz")		||
	strstr(t,"INJECT")	    ||
	strstr(t,"Inject")	    ||
	strstr(t,"inject")	    ||
	strstr(t,"INJECTOR")	||
	strstr(t,"Injector")	||
	strstr(t,"injector")	||
	strstr(t,"KILL")	    ||
	strstr(t,"Kill")		||
	strstr(t,"kill")		||
	strstr(t,"MUPIE")		||
	strstr(t,"MuPie")		||
	strstr(t,"MuPie")		||
	strstr(t,"OLLY")		||
	strstr(t,"Olly")		||
	strstr(t,"olly")		||
	strstr(t,"PACKAGER")	||
	strstr(t,"Packager")	||
	strstr(t,"Packager")	||
	strstr(t,"PACOTES")	    ||
	strstr(t,"Pacotes")	    ||
	strstr(t,"Pacotes")	    ||
	strstr(t,"SUSPEND")		||
	strstr(t,"Suspend")		||
	strstr(t,"suspend")		||
	strstr(t,"WILDPROXY")	||
	strstr(t,"Wildproxy")	||
	strstr(t,"wildproxy")	||
	strstr(t,"WPE PRO")		||
	strstr(t,"Wpe Pro")		||
	strstr(t,"wpe pro")		||
	strstr(t,"XELERATOR")	||
	strstr(t,"Xelerator")	||
	strstr(t,"xelerator")	||	
	strstr(t,"XTRAP")	    ||
	strstr(t,"XTrap")	    ||
	strstr(t,"xtrap")	    ||
	strstr(t,"XSPEED")	    ||
	strstr(t,"XSpeed")	    ||
	strstr(t,"xSpeed")	    ||
	strstr(t,"xspeed")	    ||	
	strstr(t,"FUNNYZHYPER")	||
	strstr(t,"FunnyZhyper")	||
	strstr(t,"funnyzhyper")	||
    strstr(t,"AUTOSKILL")	||
	strstr(t,"AutoSkill")	||
	strstr(t,"autoskill")	||
	strstr(t,"AUTOKILL")	||
	strstr(t,"Autokill")	||
	strstr(t,"autokill")	||
	strstr(t,"AGILITY")		||
	strstr(t,"Agility")		||
	strstr(t,"agility")		||
	strstr(t,"TRADE")	    ||
	strstr(t,"Trade")	    ||
	strstr(t,"trade")	    ||
	strstr(t,"PACKET")	    ||
	strstr(t,"Packet")	    ||
	strstr(t,"packet")	    ||
	strstr(t,"AUTOIT")	    ||
	strstr(t,"AutoIt")	    ||
	strstr(t,"autoit")	    ||
	strstr(t,"AUTOKEYBOARD") ||
	strstr(t,"AutoKeyboard") ||
	strstr(t,"autokeyboard") ||	
	strstr(t,"SMOLL")    	||
	strstr(t,"Smoll")    	||
	strstr(t,"smoll")    	||	
	strstr(t,"SANDBOX")     ||
	strstr(t,"Sandbox")     ||
	strstr(t,"sandbox")     ||
	strstr(t,"SANDBOXED")   ||
	strstr(t,"Sandboxed")   ||
	strstr(t,"sandboxed")   ||
	strstr(t,"DEFALTBOX")   ||
	strstr(t,"DefaltBox")   ||
	strstr(t,"defaltbox")   ||
	strstr(t,"HXD")         ||
	strstr(t,"HxD")         ||
	strstr(t,"hxd")         ||
	strstr(t,"BVKHEX")      ||
	strstr(t,"Bvkhex")      ||
	strstr(t,"bvkhex")      ||
	strstr(t,"DEBUG")      ||
	strstr(t,"Debug")      ||
	strstr(t,"debug"))     {

	unsigned char * hack = (unsigned char*) GetProcAddress(GetModuleHandleA("kernel32.dll"), "OpenProcess");
	if ( *(hack+6) == 0xEA ){ 
	}
	
if (carrega.Log_Txt_Hack == 1){
using namespace std;
ofstream out("GameGuard/Log.txt", ios::app);
out << "\n H-Scan:  ", out <<   (t);
}
    if (carrega.Message_Warning_En == 1){
    CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_H_En),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);	
}
    if (carrega.Message_Warning_En == 2){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_H_Br),NULL,0,0);
	Sleep(500); 
	ExitProcess(0);	
}
	if (carrega.Message_Warning_En == 0){
	ExitProcess(0);	
	}
	else
	ExitProcess(0);
	}
    }
	}
	}
	

void H_Scan(){
	again:
    TxtCheckWindow();
    Sleep(1000);
    goto again;
}

void XProtectionMain(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(H_Scan),NULL,0,0);
	}