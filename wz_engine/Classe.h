// Video tutorial: http://www.youtube.com/user/vertexbrasil
class CARREGAR
{
public:
	void MainThread(void * lpParam);
	void Nomes();
	char * Nome_do_Main;
	char * Nome_do_Launcher;
	char * Nome_da_DLL;
	char * Launcher_Window;
	char * Nome_das_Janelas;
	char * Nome;	
	char * Nome2;
	char * Serial;
	char * Versao;
	char * IP;
	char * Jump_asm;
	
	int ATIVA_TESTE; 
	int Minimum_thread; 
	int Dont_kill_yet; 
	int Carrega_serial_versao;
	int Entrypoint_Memset;
	int Verifica_Nome;
	int Splash_Screen;
	int Ativa_CRC_Geral;
	int CRC_7_Terrains;
	int CRC_Player;
	int CRC_ProtectBMP;	
	int CRC_WebZenLogoOZJ;
	int CRC_Launcher;
	int Detecta_Inject;
	int GlowDLL;
	int MinimizerDLL;
	int Detecta_Dump;
	int Launcher_Ativo;
	int Detecta_Kill;
	int Log_Txt_Hack;
	int Message_Warning_En;
	int Detecta_Hide;
	int Detecta_Speed;
	int Detecta_PID;
	int Detecta_Window;
	int Detecta_Heuristica;
	int Detecta_ClassName ;
	
	long CRC_LauncherEXE;
	long CRC_PlayerBMD;
	long CRC_Protect;
	long CRC_WebLogo;
	long CRC_Terrain1;
	long CRC_Terrain2;
	long CRC_Terrain3;
	long CRC_Terrain4;
	long CRC_Terrain5;
	long CRC_Terrain6;
	long CRC_Terrain7;
};
extern CARREGAR carrega;