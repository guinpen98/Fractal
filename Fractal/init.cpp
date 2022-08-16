#include"scene.hpp"



int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
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