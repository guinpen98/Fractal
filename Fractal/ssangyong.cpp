#include "ssangyong.h"

namespace fractal {

	void ssangyongScene(sceneE& current_scene, color_matrix& pixel) {
		//アフィン変換
		auto f1 = [](Vec2 coord) -> Vec2 {return Vec2(0.5 * coord.x + 0.5 * coord.y + 0.125, -0.5 * coord.x + 0.5 * coord.y + 0.625); };
		auto f2 = [](Vec2 coord) -> Vec2 {return Vec2(0.5 * coord.x + 0.5 * coord.y - 0.125, -0.5 * coord.x + 0.5 * coord.y + 0.375); };

		//key入力
		char key_state[256];
		//座標
		Vec2 coord(0.0, 0.0);
		for (int i = 0; i < ssangyong_num; i++) {
			double r = random();
			if (r < 0.5) coord = f1(coord);
			else coord = f2(coord);
			Vec2 icoord(coord.x * ssangyong_pixel_w, ssangyong_pixel_h - coord.y * ssangyong_pixel_h);
			if (icoord.x < 0 || icoord.x > ssangyong_pixel_w || icoord.y < 0 || icoord.y > ssangyong_pixel_h) continue;
			pixel[int(icoord.y)][int(icoord.x)] = 1;
		}
		while (current_scene == sceneE::ssangyongE && update()) {
			GetHitKeyStateAll(key_state);
			if (key_state[KEY_INPUT_SPACE]) moveScene(current_scene);
			drawSsangyong(pixel);
		}

	}
	void drawSsangyong(const color_matrix& pixel) {
		for (int y = 0; y < ssangyong_pixel_h; y++)
			for (int x = 0; x < ssangyong_pixel_w; x++) {
				if (pixel[y][x] == 1)
					DrawBox(x * ssangyong_pixel_size, y * ssangyong_pixel_size, (x + 1) * ssangyong_pixel_size, (y + 1) * ssangyong_pixel_size, GetColor(0, 50, 0), TRUE);
				else
					DrawBox(x * ssangyong_pixel_size, y * ssangyong_pixel_size, (x + 1) * ssangyong_pixel_size, (y + 1) * ssangyong_pixel_size, GetColor(255, 255, 255), TRUE);
			}
	}

}
