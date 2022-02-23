#ifndef FRACTAL_SSANGYONG_HPP
#define FRACTAL_SSANGYONG_HPP
#include<vector>
#include"random.hpp"
#include"vec2.h"
#include"system.hpp"
namespace fractal {

	void ssangyongScene(color_matrix& pixel) {
		//アフィン変換
		auto f1 = [](Vec2 coord) -> Vec2 {return Vec2(0.5 * coord.x + 0.5 * coord.y + 0.125, -0.5 * coord.x + 0.5 * coord.y + 0.625); };
		auto f2 = [](Vec2 coord) -> Vec2 {return Vec2(0.5 * coord.x + 0.5 * coord.y - 0.125, -0.5 * coord.x + 0.5 * coord.y + 0.375); };

		//座標
		Vec2 coord(0.0, 0.0);
		for (int i = 0; i < ssangyong_num; i++) {
			double r = random();
			if (r < 0.5) coord = f1(coord);
			else coord = f2(coord);
			Vec2 icoord(coord.x * ssangyong_pixel_w, ssangyong_pixel_h - coord.y * ssangyong_pixel_h);
			if (icoord.x < 0 || icoord.x > ssangyong_pixel_w || icoord.y < 0 || icoord.y > ssangyong_pixel_h) continue;
			else pixel[int(icoord.y)][int(icoord.x)] = black;
		}
	}
}

#endif // !FRACTAL_SSANGYONG_HPP

