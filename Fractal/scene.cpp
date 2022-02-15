#include "scene.h"

namespace fractal {

	void scene() {
		sceneE current_scene = mandelbrot_setE;
		switch (mandelbrot_setE)
		{
		case mandelbrot_setE:
			mandelbrotSetScene(current_scene);
			break;
		default:
			break;
		}
	}
}
