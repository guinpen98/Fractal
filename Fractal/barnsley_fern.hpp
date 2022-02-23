#ifndef FRACTAL_BARNSLEY_FERN_HPP
#define FRACTAL_BARNSLEY_FERN_HPP
#include<vector>
#include"random.hpp"
#include"vec2.h"
#include"system.hpp"
namespace fractal {

	void barnsleyFernScene(color_matrix& pixel) {
		//アフィン変換
		auto f1 = [](Vec2 coord) -> Vec2 {return Vec2(0.0, 0.16 * coord.y); };
		auto f2 = [](Vec2 coord) -> Vec2 {return Vec2(0.85 * coord.x + 0.04 * coord.y, -0.04 * coord.x + 0.85 * coord.y + 1.6); };
		auto f3 = [](Vec2 coord) -> Vec2 {return Vec2(0.2 * coord.x - 0.26 * coord.y, 0.23 * coord.x + 0.22 * coord.y + 1.6); };
		auto f4 = [](Vec2 coord) -> Vec2 {return Vec2(-0.15 * coord.x + 0.28 * coord.y, 0.26 * coord.x + 0.24 * coord.y + 0.44); };

		//座標
		Vec2 coord(0.0, 0.0);
		for (int i = 0; i < fern_num; i++) {
			double r = random();
			if (r < 0.01) coord = f1(coord);
			else if (r < 0.86) coord = f2(coord);
			else if (r < 0.93) coord = f3(coord);
			else coord = f4(coord);
			Vec2 icoord(fern_pixel_w / 2 + coord.x * fern_pixel_w / 10, fern_pixel_h - coord.y * fern_pixel_h / 12);
			if (icoord.x < 0 || icoord.x > fern_pixel_w || icoord.y < 0 || icoord.y > fern_pixel_h) continue;
			else pixel[int(icoord.y)][int(icoord.x)] = deep_green;
		}
	}
}

#endif // !FRACTAL_BARNSLEY_FERN_HPP

