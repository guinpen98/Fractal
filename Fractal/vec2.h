#ifndef FRACTAL_VEC2_H
#define FRACTAL_VEC2_H
#include"configuration.h"

namespace fractal {
	struct Vec2
	{
		double x = 0, y = 0;

		Vec2() = default;

		Vec2(const double ix, const double iy)
			:x(ix), y(iy) {}

		Vec2 operator+(const Vec2& coord)const {
			return Vec2(x + coord.x, y + coord.y);
		}
	};

}

#endif // !FRACTAL_VEC2_H