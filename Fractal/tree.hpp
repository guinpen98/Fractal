#ifndef FRACTAL_TREE_HPP
#define FRACTAL_TREE_HPP
#include<vector>
#include"random.hpp"
#include"vec2.h"
#include"system.hpp"
namespace fractal {

	void treeScene(color_matrix& pixel) {
		//アフィン変換
		auto f1 = [](Vec2 coord) -> Vec2 {return Vec2(0.05 * coord.x, 0.6 * coord.y); };
		auto f2 = [](Vec2 coord) -> Vec2 {return Vec2(0.05 * coord.x, -0.5 * coord.y + 1.0); };
		auto f3 = [](Vec2 coord) -> Vec2 {return Vec2(0.46 * coord.x - 0.32 * coord.y, 0.39 * coord.x + 0.5 * coord.y + 0.6); };
		auto f4 = [](Vec2 coord) -> Vec2 {return Vec2(0.47 * coord.x - 0.15 * coord.y, 0.17 * coord.x + 0.42 * coord.y + 1.1); };
		auto f5 = [](Vec2 coord) -> Vec2 {return Vec2(0.43 * coord.x + 0.28 * coord.y, -0.25 * coord.x + 0.45 * coord.y + 1.0); };
		auto f6 = [](Vec2 coord) -> Vec2 {return Vec2(0.42 * coord.x + 0.26 * coord.y, -0.35 * coord.x + 0.31 * coord.y + 0.7); };

		//座標
		Vec2 coord(0.0, 0.0);
		for (int i = 0; i < tree_num; i++) {
			double r = random();
			if (r < 0.1) coord = f1(coord);
			else if (r < 0.3) coord = f2(coord);
			else if (r < 0.5) coord = f3(coord);
			else if (r < 0.7) coord = f4(coord);
			else if (r < 0.9) coord = f5(coord);
			else coord = f6(coord);
			Vec2 icoord(coord.x * tree_pixel_w / 2 + tree_pixel_w / 2, tree_pixel_h - coord.y * tree_pixel_h / 2);
			if (icoord.x < 0 || icoord.x >= window_w || icoord.y < 0 || icoord.y >= window_h) continue;
			else pixel[int(icoord.y)][int(icoord.x)] = black;
		}
	}
}

#endif // !FRACTAL_TREE_HPP