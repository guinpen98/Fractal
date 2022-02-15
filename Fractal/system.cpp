#include "system.h"
namespace fractal {
	bool update() { return (DxLib::ScreenFlip() != -1 && DxLib::ClearDrawScreen() != -1 && DxLib::ProcessMessage() != -1); }

	void moveScene(sceneE& current_scene) {
		current_scene = sceneE(current_scene + 1);
		if (current_scene == tailE) current_scene = mandelbrot_setE;
	}
}
