#ifndef FRACTAL_CONFIGURATION
#define FRACTAL_CONFIGURATION

namespace fractal {

	constexpr int window_w = 960;
	constexpr int window_h = 960;
	constexpr int coefficient = 480;
	constexpr int complex_plane_w = window_w / coefficient;
	constexpr int complex_plane_h = window_h / coefficient;

	enum scene :int {
		mandelbrot_setE
		,endE
	};

}

#endif // !FRACTAL_CONFIGURATION