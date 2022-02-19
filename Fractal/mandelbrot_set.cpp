#include "mandelbrot_set.h"

namespace fractal {

	void mandelbrot(color_matrix& pixel) {
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
	void drawMandelbrotSet(const color_matrix& pixel) {
		for(int y = 0; y < window_h; y++)
			for (int x = 0; x < window_w; x++) {
				DrawPixel(x, y, pixel[y][x]);
			}
	}
	void mandelbrotSetScene(sceneE& current_scene, color_matrix& pixel) {
		//key入力
		char key_state[256];
		mandelbrot(pixel);
		while (current_scene == sceneE::mandelbrot_setE && update()) {
			GetHitKeyStateAll(key_state);
			if (key_state[KEY_INPUT_SPACE]) moveScene(current_scene);
			drawMandelbrotSet(pixel);
		}
	}
}