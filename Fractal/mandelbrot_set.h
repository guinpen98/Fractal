#ifndef FRACTAL_MANDELBROT_SET_H
#define FRACTAL_MANDELBROT_SET_H
#include<vector>
#include"system.h"
#include"complex.h"
namespace fractal {

	void mandelbrot(color_matrix& pixel);
	void drawMandelbrotSet(const color_matrix& pixel);
	void mandelbrotSetScene(sceneE& current_scene, color_matrix& pixel);
}

#endif // !FRACTAL_MANDELBROT_SET_H