#include "scene.h"

namespace fractal {

	void scene() {
		sceneE current_scene = mandelbrot_setE;
		while (update()) {
			switch (current_scene)
			{
			case mandelbrot_setE:
				mandelbrotSetScene(current_scene);
				break;
			case barnsley_fernE:
				barnsleyFernScene(current_scene);
				break;
			case ssangyongE:
				ssangyongScene(current_scene);
				break;
			case branchE:
				branchScene(current_scene);
				break;
			default:
				break;
			}
		}
	}
}
