#include "random.h"

namespace fractal {
	double random() {
		using namespace std;
		//ランダム
		random_device rd;
		default_random_engine eng(rd());
		uniform_real_distribution<double> distr(0, 1);
		return distr(eng);
	}
}