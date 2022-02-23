#ifndef FRACTAL_RANDOM_HPP
#define FRACTAL_RANDOM_HPP
#include<random>
namespace fractal {
	double random() {
		using namespace std;
		//�����_��
		random_device rd;
		default_random_engine eng(rd());
		uniform_real_distribution<double> distr(0, 1);
		return distr(eng);
	}
}

#endif // !FRACTAL_RANDOM_HPP
