#ifndef FRACTAL_CONFIGURATION
#define FRACTAL_CONFIGURATION

namespace fractal {
	using namespace std;

	constexpr int window_w = 960;
	constexpr int window_h = 960;
	constexpr int coefficient = 240;
	constexpr int complex_plane_w = window_w / coefficient;
	constexpr int complex_plane_h = window_h / coefficient;

	constexpr int max_it = 256;

	enum sceneE :int {
		mandelbrot_setE
	};

	enum colorE :int {
		whiteE
		,light_blueE
		,blueE
		,deep_blueE
		,blackE
	};

}

#endif // !FRACTAL_CONFIGURATION