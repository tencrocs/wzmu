// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include "StdAfx.h"
#include "config.h"

void Msg_L_Br(){ 
	MessageBoxA(NULL, "CRC-Scan\n\nO arquivo [Launcher.exe] foi alterado ou corrompido!\n", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
} 
void Msg_L_En(){ 
	MessageBoxA(NULL, "CRC-Scan\n\n[Launcher.exe] Corrupted or missing file!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING); 
} 

void Msg_P_Br(){
	MessageBoxA(NULL, "CRC-Scan\n\nO arquivo [Player.bmp] foi alterado ou corrompido!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING); 
}

void Msg_P_En(){
	MessageBoxA(NULL, "CRC-Scan\n\n[Player.bmp] Corrupted or missing file!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING); 
}

void Msg_Pro_BMD_Br(){
	MessageBoxA(NULL, "CRC-Scan\n\nO arquivo [Protect.bmd] foi alterado ou corrompido!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}

void Msg_Pro_BMD_En(){
	MessageBoxA(NULL, "CRC-Scan\n\n[Protect.bmd] Corrupted or missing file!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}

void Msg_Logo_Br(){
	MessageBoxA(NULL, "CRC-Scan\n\nO arquivo [Webzenlogo.OZJ] foi alterado ou corrompido!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}
void Msg_Logo_En(){
	MessageBoxA(NULL, "CRC-Scan\n\n[Webzenlogo.OZJ] Corrupted or missing file!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}

void Msg_T1_Br(){
	MessageBoxA(NULL, "CRC-Scan\n\nO arquivo [EncTerrain1.att] foi alterado ou corrompido!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}
void Msg_T1_En(){
	MessageBoxA(NULL, "CRC-Scan\n\n[EncTerrain1.att] Corrupted or missing file!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}

void Msg_T2_Br(){
	MessageBoxA(NULL, "CRC-Scan\n\nO arquivo [EncTerrain2.att] foi alterado ou corrompido!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}
void Msg_T2_En(){
	MessageBoxA(NULL, "CRC-Scan\n\n[EncTerrain2.att] Corrupted or missing file!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}

void Msg_T3_Br(){
	MessageBoxA(NULL, "CRC-Scan\n\nO arquivo [EncTerrain3.att] foi alterado ou corrompido!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}
void Msg_T3_En(){
	MessageBoxA(NULL, "CRC-Scan\n\n[EncTerrain3.att] Corrupted or missing file!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}

void Msg_T4_Br(){
	MessageBoxA(NULL, "CRC-Scan\n\nO arquivo [EncTerrain4.att] foi alterado ou corrompido!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}
void Msg_T4_En(){
	MessageBoxA(NULL, "CRC-Scan\n\n[EncTerrain4.att] Corrupted or missing file!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}

void Msg_T5_Br(){
	MessageBoxA(NULL, "CRC-Scan\n\nO arquivo [EncTerrain5.att] foi alterado ou corrompido!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}
void Msg_T5_En(){
	MessageBoxA(NULL, "CRC-Scan\n\n[EncTerrain5.att] Corrupted or missing file!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}

void Msg_T6_Br(){
	MessageBoxA(NULL, "CRC-Scan\n\nO arquivo [EncTerrain6.att] foi alterado ou corrompido!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}
void Msg_T6_En(){
	MessageBoxA(NULL, "CRC-Scan\n\n[EncTerrain6.att] Corrupted or missing file!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}

void Msg_T7_Br(){
	MessageBoxA(NULL, "CRC-Scan\n\nO arquivo [EncTerrain7.att] foi alterado ou corrompido!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}
void Msg_T7_En(){
	MessageBoxA(NULL, "CRC-Scan\n\n[EncTerrain7.att] Corrupted or missing file!", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
}

////////////////////////////////////////////////

CheckSum Check;
void CheckSum::Arquivos(){
Check.Initialize();


	if( carrega.CRC_Launcher == 1) 
	{
	long Arquivo1 = Check.FileCRC (carrega.Nome_do_Launcher);
	if(Arquivo1 != carrega.CRC_LauncherEXE)
	{
    if (carrega.Log_Txt_Hack == 1){	
	using namespace std;
    ofstream out("GameGuard/Log.txt", ios::app);
    out << "\n CRC-Scan:", out <<  carrega.Nome_do_Launcher;
}
    if (carrega.Message_Warning_En == 1){
    CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_L_En),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);	
}
	if (carrega.Message_Warning_En == 2){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_L_Br),NULL,0,0);
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

////////////////////////////////////////////////
	if(carrega.CRC_Player == 1){
	long Player = Check.FileCRC("Data/Player/player.bmd");
	if(Player != carrega.CRC_PlayerBMD)		{
	if (carrega.Log_Txt_Hack == 1){	
	using namespace std;
    ofstream out("GameGuard/Log.txt", ios::app);
    out << "\n CRC-Scan:", out <<   "Data/Player/player.bmd";
}
    if (carrega.Message_Warning_En == 1){
    CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_P_En),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);	
}
	if (carrega.Message_Warning_En == 2){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_P_Br),NULL,0,0);
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

////////////////////////////////////////////////
	if(carrega.CRC_ProtectBMP == 1){
	long Image = Check.FileCRC("GameGuard/Protect.bmp");
	if(Image != carrega.CRC_Protect){
	if (carrega.Log_Txt_Hack == 1){	
	using namespace std;
    ofstream out("GameGuard/Log.txt", ios::app);
    out << "\n CRC-Scan:", out <<   "GameGuard/Protect.bmp";
}
    if (carrega.Message_Warning_En == 1){
    CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_Pro_BMD_En),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);	
}
	if (carrega.Message_Warning_En == 2){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_Pro_BMD_Br),NULL,0,0);
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

////////////////////////////////////////////////		
	if(carrega.CRC_WebZenLogoOZJ == 1){
	long Image2 = Check.FileCRC("Data/Local/Webzenlogo.OZJ");
	if(Image2 != carrega.CRC_WebLogo){
	if (carrega.Log_Txt_Hack == 1){	
	using namespace std;
    ofstream out("GameGuard/Log.txt", ios::app);
    out << "\n CRC-Scan:", out <<   "Data/Local/Webzenlogo.OZJ";
}
    if (carrega.Message_Warning_En == 1){
    CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_Logo_En),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);	
}
	if (carrega.Message_Warning_En == 2){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_Logo_Br),NULL,0,0);
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
	
////////////////////////////////////////////////
		if(carrega.CRC_7_Terrains == 1)
	    {
		long ter1 = Check.FileCRC("Data/World1/EncTerrain1.att");
		long ter2 = Check.FileCRC("Data/World2/EncTerrain2.att");
		long ter3 = Check.FileCRC("Data/World3/EncTerrain3.att");
		long ter4 = Check.FileCRC("Data/World4/EncTerrain4.att");
		long ter5 = Check.FileCRC("Data/World5/EncTerrain5.att");
		long ter6 = Check.FileCRC("Data/World6/EncTerrain6.att");
		long ter7 = Check.FileCRC("Data/World7/EncTerrain7.att");

////////////////////////////////////////////////
	if(ter1 != carrega.CRC_Terrain1){
	if (carrega.Log_Txt_Hack == 1){	
	using namespace std;
    ofstream out("GameGuard/Log.txt", ios::app);
    out << "\n CRC-Scan:", out <<   "Data/World1/EncTerrain1.att";
}
    if (carrega.Message_Warning_En == 1){
    CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_T1_En),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);	
}
	if (carrega.Message_Warning_En == 2){ 
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_T1_Br),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);
}
	if (carrega.Message_Warning_En == 0){
	ExitProcess(0);	
}
	else
	ExitProcess(0);
}
	
	
////////////////////////////////////////////////
	if(ter2 != carrega.CRC_Terrain2){
	if (carrega.Log_Txt_Hack == 1){	
	using namespace std;
    ofstream out("GameGuard/Log.txt", ios::app);
    out << "\n CRC-Scan:", out <<   "Data/World2/EncTerrain2.att";
}
    if (carrega.Message_Warning_En == 1){
    CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_T2_En),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);	
}
	if (carrega.Message_Warning_En == 2){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_T2_Br),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);
}
	if (carrega.Message_Warning_En == 0){
	ExitProcess(0);	
}
	else
	ExitProcess(0);
}

////////////////////////////////////////////////
	if(ter3 != carrega.CRC_Terrain3){
	if (carrega.Log_Txt_Hack == 1){	
	using namespace std;
    ofstream out("GameGuard/Log.txt", ios::app);
    out << "\n CRC-Scan:", out <<   "Data/World3/EncTerrain3.att";
}
	if (carrega.Message_Warning_En == 1){
    CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_T3_En),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);	
}
	if (carrega.Message_Warning_En == 2){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_T3_Br),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);
	}
	if (carrega.Message_Warning_En == 0){
	ExitProcess(0);
	}
	else
	ExitProcess(0);
}
	
////////////////////////////////////////////////
	if(ter4 != carrega.CRC_Terrain4){
	if (carrega.Log_Txt_Hack == 1){	
	using namespace std;
    ofstream out("GameGuard/Log.txt", ios::app);
    out << "\n CRC-Scan:", out <<   "Data/World4/EncTerrain4.att";
}
    if (carrega.Message_Warning_En == 1){
    CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_T4_En),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);	
}
	if (carrega.Message_Warning_En == 2){ 
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_T4_Br),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);
}
	if (carrega.Message_Warning_En == 0){
	ExitProcess(0);
}
	else
	ExitProcess(0);
}

////////////////////////////////////////////////
	if(ter5 != carrega.CRC_Terrain5){
	if (carrega.Log_Txt_Hack == 1){	
	using namespace std;
    ofstream out("GameGuard/Log.txt", ios::app);
    out << "\n CRC-Scan:", out <<   "Data/World5/EncTerrain5.att";
}
    if (carrega.Message_Warning_En == 1){
    CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_T5_En),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);	
}
	if (carrega.Message_Warning_En == 2){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_T5_Br),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);
}
	if (carrega.Message_Warning_En == 0){
	ExitProcess(0);
}
	else
	ExitProcess(0);
}
	
////////////////////////////////////////////////
	if(ter6 != carrega.CRC_Terrain6){
	if (carrega.Log_Txt_Hack == 1){	
	using namespace std;
    ofstream out("GameGuard/Log.txt", ios::app);
    out << "\n CRC-Scan:", out <<   "Data/World6/EncTerrain6.att";
}
    if (carrega.Message_Warning_En == 1){
    CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_T6_En),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);	
}
	if (carrega.Message_Warning_En == 2){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_T6_Br),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);
	}
	if (carrega.Message_Warning_En == 0){
	ExitProcess(0);
}
	else
	ExitProcess(0);
}

////////////////////////////////////////////////
	if(ter7 != carrega.CRC_Terrain7){
	if (carrega.Log_Txt_Hack == 1){	
	using namespace std;
    ofstream out("GameGuard/Log.txt", ios::app);
    out << "\n CRC-Scan:", out <<   "Data/World7/EncTerrain7.att";
}
    if (carrega.Message_Warning_En == 1){
    CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_T7_En),NULL,0,0);
	Sleep(5000); 
	ExitProcess(0);	
}
	if (carrega.Message_Warning_En == 2){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Msg_T7_Br),NULL,0,0);
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
	}
	
	
void MainThread(void * lpParam)
{	
	 while(true)	{
	  Check.Arquivos();
	  Sleep (60000);   
	}
	_endthread();
}