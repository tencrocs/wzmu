// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include "stdafx.h"
#include "config.h"
#include "Splash.h"

void SplashShow() 
{
    CSplash splash1(TEXT(".\\GameGuard/Protect.bmp"), RGB(128, 128, 128));
    splash1.ShowSplash();
    Sleep(3000);

    splash1.CloseSplash();
}



