#include "mandelbrot_set.h"

namespace fractal {

	void mandelbrot(vector<vector<colorE>>& arr) {
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
				if (flag) arr[ky][kx] = whiteE;
				else {
					if (cnt <= 1) arr[ky][kx] = blackE;
					else if (cnt <= 3) arr[ky][kx] = deep_blueE;
					else if (cnt <= 5) arr[ky][kx] = blueE;
					else arr[ky][kx] = light_blueE;
				}
			}
		}
	}
	void drawMandelbrotSet(const vector<vector<colorE>>& arr) {
		unsigned int cr = GetColor(0, 0, 0);
		for(int y = 0; y < window_h; y++)
			for (int x = 0; x < window_w; x++) {
				switch (arr[y][x])
				{
				case whiteE:
					cr = GetColor(255, 255, 255);
					break;
				case light_blueE:
					cr = GetColor(0, 0, 60);
					break;
				case blueE:
					cr = GetColor(0, 0, 150);
					break;
				case deep_blueE:
					cr = GetColor(0, 0, 255);
					break;
				case blackE:
					cr = GetColor(0, 0, 0);
					break;
				default:
					break;
				}
				DrawPixel(x, y, cr);
			}
	}
	void mandelbrotSetScene(sceneE& current_scene) {
		//ピクセルの配列
		vector<vector<colorE>> pixel(window_h,vector<colorE>(window_w));
		//key入力
		char key_state[256];
		mandelbrot(pixel);
		while (current_scene == mandelbrot_setE && update()) {
			GetHitKeyStateAll(key_state);
			if (key_state[KEY_INPUT_SPACE]) moveScene(current_scene);
			drawMandelbrotSet(pixel);
		}
	}
}