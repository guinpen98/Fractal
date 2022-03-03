#ifndef FRACTAL_AMMONITE_HPP
#define FRACTAL_AMMONITE_HPP
#include<vector>
#include"random.hpp"
#include"vec2.h"
#include"system.hpp"
namespace fractal {

	void ammoniteScene(color_matrix& pixel) {
		//アフィン変換
		auto f1 = [](Vec2 coord) -> Vec2 {return Vec2(-0.29 * coord.x - 0.0013 * coord.y + 0.59, 0.002 * coord.x - 0.2 * coord.y - 0.32); };
		auto f2 = [](Vec2 coord) -> Vec2 {return Vec2(-0.073 * coord.x - 0.025 * coord.y + 0.79, -0.006 * coord.x + 0.29 * coord.y - 0.057); };
		auto f3 = [](Vec2 coord) -> Vec2 {return Vec2(0.94 * coord.x - 0.22 * coord.y - 0.047, 0.21 * coord.x + 0.96 * coord.y - 0.01); };

		//座標
		Vec2 coord(0.0, 0.0);
		for (int i = 0; i < ammonite_num; i++) {
			double r = random();
			if (r < 0.05) coord = f1(coord);
			else if (r < 0.12) coord = f2(coord);
			else coord = f3(coord);
			Vec2 icoord(coord.x * ammonite_pixel_w / 2 + ammonite_pixel_w / 2, ammonite_pixel_h / 2 - coord.y * ammonite_pixel_h / 2);
			if (icoord.x < 0 || icoord.x >= window_w || icoord.y < 0 || icoord.y >= window_h) continue;
			else pixel[int(icoord.y)][int(icoord.x)] = black;
		}
	}
}

#endif // !FRACTAL_AMMONITE_HPP