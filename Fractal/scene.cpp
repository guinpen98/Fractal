#include "scene.h"

namespace fractal {

	void scene() {
		sceneE current_scene = sceneE::barnsley_fernE;
		//ピクセルの配列
		color_matrix pixel(window_h, color_array(window_w, white));
		while (fractal::update()) {
			fill(white,pixel);
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
	}
}
