#ifndef FRACTAL_MANDELBROT_SET_H
#define FRACTAL_MANDELBROT_SET_H
#include<vector>
#include"system.h"
#include"complex.h"
namespace fractal {

	void mandelbrot(vector<vector<colorE>>& arr);
	void drawMandelbrotSet(const vector<vector<colorE>>& arr);
	void mandelbrotSetScene(sceneE& current_scene);
}

#endif // !FRACTAL_MANDELBROT_SET_H