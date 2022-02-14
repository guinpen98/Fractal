#include "scene.h"

namespace fractal {

	void Scene() {
		scene current_scene = mandelbrot_setE;
		while (Update()) {
			switch (mandelbrot_setE)
			{
			case mandelbrot_setE:
				break;
			case endE:
				return;
				break;
			default:
				break;
			}
		}
	}
}
