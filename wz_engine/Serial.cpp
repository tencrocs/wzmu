// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include "StdAfx.h"

void Serial_e_Etc()
{
	DWORD* Serial = (DWORD*)(0x00692174); // Serial Offset, in this case, mxmain Version 1.01E are = 692174 
	memset(&Serial[0],0x00,16);           // Max digits (16)
	memcpy(&Serial[0],carrega.Serial,16); 

	DWORD* Versao = (DWORD*)(0x0069216C); // Version Offset, in this case, mxmain Version 1.01E are = 69216C
	memset(&Versao[0],0x00,5);            // Max digits (5)
	memcpy(&Versao[0],carrega.Versao,5);  

    DWORD* Ip = (DWORD*)(0x006915D4);     // IP Offset 
	memset(&Ip[0],0x00,15);               // Max digits (15)
    memcpy(&Ip[0],carrega.IP,15);         
		
};


//This subscribe mxmain.exe entrypoint with memset, so, without dll, mxmain.exe load FAIL. 
void MemorySet()
{
	DWORD* Jump_asm = (DWORD*)(0x0066D65D);   
	memset(&Jump_asm[0],0x00,12);
	memcpy(&Jump_asm[0],carrega.Jump_asm,12);  // Max digits (12)
/*
// OUTRO TESTE de menset em bytes específicos da memória (Tudo testado e funcionando Ok!, descomente e use)      
#define serial_offset           0x00692174  // (TESTE NO SERIAL) Offset serial = UK4l3 = 55 4B 34 6C 33
	*(BYTE*)(serial_offset)		= 0x55;
	*(BYTE*)(serial_offset+1)	= 0x4B;
	*(BYTE*)(serial_offset+2)	= 0x34;
	*(BYTE*)(serial_offset+3)	= 0x6C;
	*(BYTE*)(serial_offset+4)	= 0x33;
*/
}
