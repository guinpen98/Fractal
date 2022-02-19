#include"scene.h"



int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    DxLib::SetOutApplicationLogValidFlag(FALSE);
    DxLib::ChangeWindowMode(TRUE);
    DxLib::SetGraphMode(fractal::window_w, fractal::window_h, 32);
    DxLib::SetMainWindowText("Fractal");
    if (DxLib::DxLib_Init() == -1) return -1;
    DxLib::SetDrawScreen(DX_SCREEN_BACK);
    //main関数呼び出し
    fractal::scene();
    return DxLib::DxLib_End();
}