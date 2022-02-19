#include "branch.h"

namespace fractal {

	void branchScene(sceneE& current_scene, color_matrix& pixel) {
		//アフィン変換
		auto f1 = [](Vec2 coord) -> Vec2 {return Vec2(0.5 * coord.x + 0.3 * coord.y + 0.4, 0.3 * coord.x - 0.5 * coord.y + 0.1); };
		auto f2 = [](Vec2 coord) -> Vec2 {return Vec2(0.66 * coord.x, - 0.66 * coord.y); };

		//key入力
		char key_state[256];
		//座標
		Vec2 coord(0.0, 0.0);
		for (int i = 0; i < branch_num; i++) {
			double r = random();
			if (r < 0.6) coord = f1(coord);
			else coord = f2(coord);
			Vec2 icoord(coord.x * branch_pixel_w + branch_pixel_w / 40, branch_pixel_h / 2 - coord.y * branch_pixel_h);
			if (icoord.x < 0 || icoord.x > branch_pixel_w || icoord.y < 0 || icoord.y > branch_pixel_h) continue;
			pixel[int(icoord.y)][int(icoord.x)] = 1;
		}
		while (current_scene == sceneE::branchE && update()) {
			GetHitKeyStateAll(key_state);
			if (key_state[KEY_INPUT_SPACE]) moveScene(current_scene);
			drawBranch(pixel);
		}

	}
	void drawBranch(const color_matrix& pixel) {
		for (int y = 0; y < branch_pixel_h; y++)
			for (int x = 0; x < branch_pixel_w; x++) {
				if (pixel[y][x] == 1)
					DrawBox(x * branch_pixel_size, y * branch_pixel_size, (x + 1) * branch_pixel_size, (y + 1) * branch_pixel_size, GetColor(0, 50, 0), TRUE);
				else
					DrawBox(x * branch_pixel_size, y * branch_pixel_size, (x + 1) * branch_pixel_size, (y + 1) * branch_pixel_size, GetColor(255, 255, 255), TRUE);
			}
	}

}