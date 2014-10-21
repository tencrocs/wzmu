// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include "StdAfx.h"
HANDLE m_DllModule;

extern  "C"  __declspec(dllexport) void __cdecl wz_init()  // Função API (init) da dll
{

// ATENÇÃO! (1) LIGA / (0) DESLIGA  (Alguns precisam ser CONFIGURADOS, ative 1 à 1, sempre testando ou a dll não vai deixar ativar o main.exe...)

	//SPLASH screen
	carrega.Splash_Screen				= 1; // On/Off Load splash image (/GameGuard/Protect.bmd)
	carrega.Message_Warning_En          = 1; // Hack detect splash message:  0 = silent, 1 = Engish, 2 = Portuguese
	carrega.Nome_das_Janelas			= "WarZone MU"; // Server name
	
	//Log.txt
	carrega.Log_Txt_Hack                = 1; // On/Off Create hack log ( "GameGuard/Log.txt" ) Enable it only for configuration and disable later, cheaters don't need to know what are happening...

	//File names changed
	carrega.Verifica_Nome 	            = 0; // On/Off = Search [mxmain.exe], [Launcher.exe] file name inside folder. Are NON case-sensitive
	carrega.Nome_do_Main				= "main.exe";       
	carrega.Nome_do_Launcher			= "Mu.exe";  
	
	//Verify if Launcher.exe is alwais ON, it uses: FindWindowA (window name)
	carrega.Launcher_Ativo              = 1;   // On/Off Launcher alwais active, need configure launcher window name below
	carrega.Launcher_Window			    = "mu"; // Launcher window name, find this at [windows task manager] (ctrl+alt+del)
	
	//Detectors
	carrega.ATIVA_TESTE                 = 0; // JUST TOR TESTS
	carrega.Detecta_Dump				= 1; // On/Off Detect application entrypoint and first 16 HexDump
	carrega.Detecta_Window				= 0; // On/Off Detect window name
	carrega.Detecta_ClassName           = 0; // On/Off Detect classeName
	carrega.Detecta_Heuristica			= 0; // On/Off Detect bad Words
	carrega.Detecta_Inject				= 1; // On/Off Detect dll inject (by dll {name.extension}) 
	carrega.Detecta_PID			     	= 1; // On/Off Detect application by {name.extension}	
/*  Detector ANTI-KILL, this one need some extra configuration. So, lets do it!
    1 - Inside: Liga_Desliga.cpp file > {carrega.Nome_do_Main = "mxmain.exe";}  << Need be exact as your mxmain.exe name, becouse detector are case-sensitive.
	2 - Turn ON: Detecta_Kill, turn OFF: Dont_kill_yet. > Start mxmain.exe and use: [ThreadCounter.exe, Process Explorer or Process Hacker] to get [mxmain.exe] [carrega.Minimum_thread] number.
	3 - Configure [carrega.Minimum_thread], turn ON [carrega.Dont_kill_yet] and try to kill some Threads.
	4 - Remember or consider [Minimizer.dll] attached... */
	carrega.Detecta_Kill                = 0;  // On/Off Detect active codex.dll tread count, this prevent desactivate dll's antihack-threads whit process explorer, process hacker etc... 
	carrega.Dont_kill_yet               = 0;  // ON/Off 1 = Turn ON Anti-kill splash (ExitProcess) / 0 = Turn OFF Anti-kill splash (ExitProcess)
	carrega.Minimum_thread			    = 10; // Minimum thread running whitout splash. 

	//NEED CONFIGURE [ Serial_Versao.cpp ] In this case: the mxmain.exe are version 1.01e
	carrega.Carrega_serial_versao		= 0; // On/Off Menset Ip/Serial/Version, without codex.dll mxmain dont make any autentication funciton.
	carrega.Serial						= "k1Pk2jcET48mxL3b";	// (16) server serial  
	carrega.Versao						= "10404";				// (5) server version
    carrega.IP						    = "74.123.190.212";	    // server Ip
	////Brake mxmain.exe entrypoint with memeryset, find mxmain entripoint. 
	carrega.Entrypoint_Memset           = 0;
	carrega.Jump_asm					= "wzìxÿh°†h.wz";       // (12) allow destyroy mxmain.exe entrypoint, the real value are load inside dll memeryset.
    
	//Configure CRCs files,  use [Igorware hasher] to get CRC
	carrega.Ativa_CRC_Geral             = 0;          // On/Off CRC files check [alwais ON]
	
	carrega.CRC_Launcher			    = 0;          // On/Off CRC Do Launcher
	carrega.CRC_LauncherEXE	    		= 0x3c7e1293; // Launcher

	carrega.CRC_ProtectBMP		    	= 0;          // On/Off CRC da Protect.bmd 
	carrega.CRC_Protect  				= 0x4e6ca14f; // Protect.BMP

	carrega.CRC_Player					= 0;          // On/Off CRC Player.bmd 
	carrega.CRC_PlayerBMD				= 0xd77eb164; // Player.BMD 

	carrega.CRC_WebZenLogoOZJ			= 0;          // On/Off Splash image 
	carrega.CRC_WebLogo                 = 0xacdd7f2e; // WebZenlogo.OZJ 
	
	carrega.CRC_7_Terrains				= 0;          // On/Off 7 first Terrain ("Data/WorldX/EncTerrainX.att") 
	carrega.CRC_Terrain1				= 0x5339965e;			// Terrain 1
	carrega.CRC_Terrain2				= 0xc3e83648;			// Terrain 2 
	carrega.CRC_Terrain3				= 0x0847c665;			// Terrain 3 
	carrega.CRC_Terrain4				= 0x7cc0297c;			// Terrain 4 
	carrega.CRC_Terrain5				= 0x76487ad9;			// Terrain 5 
	carrega.CRC_Terrain6				= 0xb3b0cf70;			// Terrain 6 
	carrega.CRC_Terrain7				= 0x98fb5fca;           // Terrain 7 

	//Carregar Glow.dll (Mu Online)
	carrega.GlowDLL						= 0; // On/Off Carrega Glow.dll inside gameguard folder. (Glow.dll not included). only works in v97
	
	//Carregar Minimizer / autoclick .dll
	carrega.MinimizerDLL    			= 0; // Start some dll by name (in Gameguard folder), use it for start some Minimizer, autoclick...
	carrega.Nome_da_DLL		         	= "GameGuard/Minimizer.dll";  
	
	carrega.Detecta_Speed = 1; // speed hack detect

}
BOOL APIENTRY DllMain( HMODULE hModule,
					  DWORD ul_reason_for_call,
					  LPVOID lpReserved ) {

						      switch (ul_reason_for_call)
						      {
						      case DLL_PROCESS_ATTACH:
							  m_DllModule = hModule;
							 					  	
							  wz_init(); //API funciton	

							  if(carrega.Splash_Screen == 1)
							  {
							  SplashShow();
							  }	

							  if(carrega.Verifica_Nome == 1)
							  {
							  Nomes();
							  }	  				 

							  if(carrega.MinimizerDLL == 1)
							  {
							  LoadLibraryA(carrega.Nome_da_DLL);
							  } 

							  if(carrega.Ativa_CRC_Geral == 1) 
							  {							 			 	 
							  _beginthread( MainThread, 0, NULL  );
							   }

							  if(carrega.GlowDLL == 1)
							  {
							  LoadLibraryA("Glow.dll");
							  } 							  

							  if(carrega.ATIVA_TESTE == 1)
							  {
							  TESTE();
							  }

							  if(carrega.Detecta_Speed == 1)
							  {
							  DetectSpeed();
							  }

							  if(carrega.Detecta_PID == 1)
							  {
							  DetectID();
							  }

							  if(carrega.Detecta_Dump == 1)
							  {
							  ProtectionMain();
							  } 

							  if(carrega.Detecta_Window == 1)
							  {
							  TitleCheckWindow();
							  YProtectionMain();
							  }

							  if(carrega.Detecta_Heuristica == 1)
							  {
							  TxtCheckWindow();
							  XProtectionMain();
							  }

							  if(carrega.Detecta_ClassName == 1)
							  {
							  ClasseCheckWindow();
							  ZProtectionMain();
							  }			 

							  if(carrega.Launcher_Ativo == 1)
							  {
							  LA_On_byName();
							  }
							  				  				  		
							  if(carrega.Detecta_Inject == 1)		                    	
		                      {
	                          Dll_Inject();
	                          }							 

							  if (carrega.Detecta_Kill == 1)						
							  {
							  AntiKill1();  
							  AntiKill2();
							  AntiKill3();
							  AntiKill4();  
							  AntiKill5();
							  AntiKill6();
							  AntiKill7();  
							  AntiKill8();
							  AntiKill9();
							  AntiKill10();
							  }

							  if (carrega.Dont_kill_yet == 0 && carrega.Detecta_Kill == 1)
							  {
							  MessageBoxA(NULL,"K-Scan\n\nWARNING! Anti-Kill detector PAUSED!\n\nThread counting process allowed", carrega.Nome_das_Janelas, MB_SERVICE_NOTIFICATION | MB_ICONWARNING);
							  }
							 
							  if(carrega.Carrega_serial_versao == 1)
							  {
							  Serial_e_Etc();
							  }

							  if(carrega.Entrypoint_Memset == 1)
							  {
							  MemorySet();
							  }
							  							  				
						  break;
					      case DLL_THREAD_ATTACH:
						  case DLL_THREAD_DETACH:
						  case DLL_PROCESS_DETACH:
						  break;
						  }
						  return TRUE;
}




