#ifndef FRACTAL_SYSTEM_H
#define FRACTAL_SYSTEM_H
#include<DxLib.h>
#include"configuration.h"
namespace fractal {
	bool update();
	void moveScene(sceneE& current_scene);
	void fill(const color fill_color, color_matrix& pixel);
	const color white = GetColor(255, 255, 255);
	const color black = GetColor(0, 0, 0);
	const color light_blue = GetColor(0, 0, 60);
	const color blue = GetColor(0, 0, 150);
	const color deep_blue = GetColor(0, 0, 255);
	const color deep_green = GetColor(0, 50, 0);
}

#endif // !FRACTAL_SYSTEM_H

