#include "branch.h"

namespace fractal {

	void branchScene(sceneE& current_scene, color_matrix& pixel) {
		//アフィン変換
		auto f1 = [](Vec2 coord) -> Vec2 {return Vec2(0.5 * coord.x + 0.3 * coord.y + 0.4, 0.3 * coord.x - 0.5 * coord.y + 0.1); };
		auto f2 = [](Vec2 coord) -> Vec2 {return Vec2(0.66 * coord.x, - 0.66 * coord.y); };

		//座標
		Vec2 coord(0.0, 0.0);
		for (int i = 0; i < branch_num; i++) {
			double r = random();
			if (r < 0.6) coord = f1(coord);
			else coord = f2(coord);
			Vec2 icoord(coord.x * branch_pixel_w + branch_pixel_w / 40, branch_pixel_h / 2 - coord.y * branch_pixel_h);
			if (icoord.x < 0 || icoord.x > branch_pixel_w || icoord.y < 0 || icoord.y > branch_pixel_h) continue;
			pixel[int(icoord.y)][int(icoord.x)] = black;
		}

	}
}