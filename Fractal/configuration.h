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
	constexpr int fern_pixel_size = 3;
	constexpr int fern_pixel_w = window_w / fern_pixel_size;
	constexpr int fern_pixel_h = window_h / fern_pixel_size;
	constexpr int fern_num = 50000;
	//双龍形の設定
	constexpr int ssangyong_pixel_size = 2;
	constexpr int ssangyong_pixel_w = window_w / ssangyong_pixel_size;
	constexpr int ssangyong_pixel_h = window_h / ssangyong_pixel_size;
	constexpr int ssangyong_num = 50000;
	//枝の設定
	constexpr int branch_pixel_size = 1;
	constexpr int branch_pixel_w = window_w / branch_pixel_size;
	constexpr int branch_pixel_h = window_h / branch_pixel_size;
	constexpr int branch_num = 50000;


	enum sceneE :int {
		mandelbrot_setE
		,barnsley_fernE
		,ssangyongE
		,branchE
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