#ifndef FRACTAL_SYSTEM_HPP
#define FRACTAL_SYSTEM_HPP
#include<DxLib.h>
#include"configuration.h"
namespace fractal {
	bool update() { return (DxLib::ScreenFlip() != -1 && DxLib::ClearDrawScreen() != -1 && DxLib::ProcessMessage() != -1); }

	void moveScene(sceneE& current_scene) {
		current_scene = sceneE(int(current_scene) + 1);
		if (current_scene == sceneE::tailE) current_scene = sceneE::mandelbrot_setE;
	}
	void fill(const color fill_color, color_matrix& pixel) {
		for (int y = 0; y < window_h; y++)
			for (int x = 0; x < window_w; x++)
				pixel[y][x] = fill_color;
	}
	const color white = GetColor(255, 255, 255);
	const color black = GetColor(0, 0, 0);
	const color light_blue = GetColor(0, 0, 60);
	const color blue = GetColor(0, 0, 150);
	const color deep_blue = GetColor(0, 0, 255);
	const color deep_green = GetColor(0, 50, 0);
}

#endif // !FRACTAL_SYSTEM_HPP

