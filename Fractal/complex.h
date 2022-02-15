#ifndef FRACTAL_COMPLEX_H
#define FRACTAL_COMPLEX_H
namespace fractal {
	struct Complex {
		double x = 0.0, iy = 0.0;

		Complex() = default;

		Complex(const double n_x, const double n_iy)
			:x(n_x), iy(n_iy) {}
		
		Complex operator+(const Complex& coord)const {
			return Complex(x + coord.x, iy + coord.iy);
		}

		Complex operator*(const Complex& coord)const {
			return Complex(x * coord.x - iy * coord.iy, iy * coord.x + x * coord.iy);
		}

		double square_of_abs()const {
			return x * x + iy * iy;
		}
	};
}

#endif // !FRACTAL_COMPLEX_H