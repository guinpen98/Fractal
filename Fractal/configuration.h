#ifndef FRACTAL_CONFIGURATION
#define FRACTAL_CONFIGURATION

namespace fractal {
	using namespace std;
	//windowサイズ
	constexpr int window_w = 960;
	constexpr int window_h = 960;
	//マンデルブロ集合の設定
	constexpr int coefficient = 240;
	constexpr int complex_plane_w = window_w / coefficient;
	constexpr int complex_plane_h = window_h / coefficient;
	constexpr int max_it = 256;
	//バーンスレイのシダの設定
	constexpr int pixel_size = 3;
	constexpr int pixel_w = window_w / pixel_size;
	constexpr int pixel_h = window_h / pixel_size;
	constexpr int num = 50000;

	enum sceneE :int {
		mandelbrot_setE
		,barnsley_fernE
		,tailE
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