#ifndef FRACTAL_GUMOWSKI_MIRA_ATTRACTOR_HPP
#define FRACTAL_GUMOWSKI_MIRA_ATTRACTOR_HPP
#include<vector>
#include"random.hpp"
#include"vec2.h"
#include"system.hpp"
namespace fractal {

	double calcX(const double x, const double y){
		return y + alpha * y * (1 - sigma * y * y) + mu * x + 2 * (1 - mu) * x * x / (1 + x * x);
	}

	double calcY(const double x_b, const double x) {
		return -x_b + mu * x + 2 * (1 - mu) * x * x / (1 + x * x);
	}

	void gumowskiMiraAttractorScene(color_matrix& pixel) {

		//ç¿ïW
		double x_next = 0.03, x = 0.03, y_next = 0.03, y = 0.03;
		for (int i = 0; i < gumowski_mira_attractor_num; i++) {
			x_next = calcX(x, y);
			y_next = calcY(x, x_next);
			pixel[(x_next + 19) * gu_coefficient][(y_next + 20) * gu_coefficient] = 1;
			x = x_next, y = y_next;
		}
	}
}

#endif // !FRACTAL_GUMOWSKI_MIRA_ATTRACTOR_HPP