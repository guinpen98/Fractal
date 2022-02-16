#ifndef FRACTAL_BARNSLEY_FERN_H
#define FRACTAL_BARNSLEY_FERN_H
#include<vector>
#include"random.h"
#include"vec2.h"
#include"system.h"
namespace fractal {

	void barnsleyFernScene(sceneE& current_scene);
	void drawMandelbrotSet(const vector<vector<int>>& pixel);
}

#endif // !FRACTAL_BARNSLEY_FERN_H

