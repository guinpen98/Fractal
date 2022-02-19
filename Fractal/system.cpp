#include "system.h"
namespace fractal {
	bool update() { return (DxLib::ScreenFlip() != -1 && DxLib::ClearDrawScreen() != -1 && DxLib::ProcessMessage() != -1); }

	void moveScene(sceneE& current_scene) {
		current_scene = sceneE(int(current_scene) + 1);
		if (current_scene == sceneE::tailE) current_scene = sceneE::mandelbrot_setE;
	}
	void fill(const color fill_color, color_matrix& pixel) {
		for (int y = 0; y < ssangyong_pixel_h; y++)
			for (int x = 0; x < ssangyong_pixel_w; x++)
				pixel[y][x] = fill_color;
	}
}
