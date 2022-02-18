#ifndef FRACTAL_BRANCH_H
#define FRACTAL_BRANCH_H
#include<vector>
#include"random.h"
#include"vec2.h"
#include"system.h"
namespace fractal {

	void branchScene(sceneE& current_scene);
	void drawBranch(const vector<vector<int>>& pixel);
}

#endif // !FRACTAL_BRANCH_H