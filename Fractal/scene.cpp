#include "scene.h"

namespace fractal {

	void scene() {
		sceneE current_scene = sceneE::barnsley_fernE;
		//ピクセルの配列
		color_matrix pixel(window_h, color_array(window_w, white));
		//key入力
		char key_state[256];
		bool is_key_down =  false;

		int pixel_size;
		while (fractal::update()) {
			GetHitKeyStateAll(key_state);
			if(key_state[KEY_INPUT_SPACE] == 0) is_key_down = false;
			else if (!is_key_down) {
				is_key_down = true;
				moveScene(current_scene);
				fill(white, pixel);
				switch (current_scene)
				{
				case sceneE::mandelbrot_setE:
					mandelbrotSetScene(current_scene, pixel);
					break;
				case sceneE::barnsley_fernE:
					barnsleyFernScene(current_scene, pixel);
					break;
				case sceneE::ssangyongE:
					ssangyongScene(current_scene, pixel);
					break;
				case sceneE::branchE:
					branchScene(current_scene, pixel);
					break;
				default:
					break;
				}
			}		
			switch (current_scene)
			{
			case sceneE::mandelbrot_setE:
				pixel_size = 1;
				break;
			case sceneE::barnsley_fernE:
				pixel_size = fern_pixel_size;
				break;
			case sceneE::ssangyongE:
				pixel_size = ssangyong_pixel_size;
				break;
			case sceneE::branchE:
				pixel_size = branch_pixel_size;
				break;
			default:
				break;
			}
			for (int y = 0; y < window_h / pixel_size; y++)
				for (int x = 0; x < window_w / pixel_size; x++)
					DrawBox(x * pixel_size, y * pixel_size, (x + 1) * pixel_size, (y + 1) * pixel_size, pixel[y][x], TRUE);

		}

	}
}
