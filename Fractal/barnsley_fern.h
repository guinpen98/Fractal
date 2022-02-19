#ifndef FRACTAL_BARNSLEY_FERN_H
#define FRACTAL_BARNSLEY_FERN_H
#include<vector>
#include"random.h"
#include"vec2.h"
#include"system.h"
namespace fractal {

	void barnsleyFernScene(sceneE& current_scene, color_matrix& pixel);
	void drawBarnsleyFern(const color_matrix& pixel);
}

#endif // !FRACTAL_BARNSLEY_FERN_H

