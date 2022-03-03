#ifndef FRACTAL_MANDELBROT_SET_HPP
#define FRACTAL_MANDELBROT_SET_HPP
#include<vector>
#include"system.hpp"
#include"complex.h"
namespace fractal {

	void mandelbrotScene(color_matrix& pixel) {
		for (int ky = 0; ky < window_h; ky++) {
			double cy = (double(window_h - ky) / coefficient) - (complex_plane_h / 2);
			for (int kx = 0; kx < window_w; kx++) {
				double cx = (double(kx) / coefficient) - (complex_plane_w / 2);
				Complex c = Complex(cx, cy), z = Complex(0.0, 0.0);
				bool flag = true;
				int cnt = 0;
				for (int i = 0; i < max_it; i++) {
					cnt = i;
					z = z * z + c;
					if (z.square_of_abs() > 4.0) {
						flag = false;
						break;
					}
				}
				if (flag) pixel[ky][kx] = white;
				else {
					if (cnt <= 1) pixel[ky][kx] = black;
					else if (cnt <= 3) pixel[ky][kx] = deep_blue;
					else if (cnt <= 5) pixel[ky][kx] = blue;
					else pixel[ky][kx] = light_blue;
				}
			}
		}
	}
}

#endif // !FRACTAL_MANDELBROT_SET_HPP