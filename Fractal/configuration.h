#ifndef FRACTAL_CONFIGURATION_H
#define FRACTAL_CONFIGURATION_H
#include<vector>

namespace fractal {

	using color = unsigned int;
	using color_array = std::vector<color>;
	using color_matrix = std::vector<color_array>;

	//windowサイズ
	constexpr int window_w = 960;
	constexpr int window_h = 960;
	//マンデルブロ集合の設定
	constexpr int coefficient = 240;
	constexpr int complex_plane_w = window_w / coefficient;
	constexpr int complex_plane_h = window_h / coefficient;
	constexpr int max_it = 256;
	//バーンスレイのシダの設定
	constexpr int fern_pixel_size = 1;
	constexpr int fern_pixel_w = window_w / fern_pixel_size;
	constexpr int fern_pixel_h = window_h / fern_pixel_size;
	constexpr int fern_num = 200000;
	//双龍形の設定
	constexpr int ssangyong_pixel_size = 1;
	constexpr int ssangyong_pixel_w = window_w / ssangyong_pixel_size;
	constexpr int ssangyong_pixel_h = window_h / ssangyong_pixel_size;
	constexpr int ssangyong_num = 200000;
	//枝の設定
	constexpr int branch_pixel_size = 1;
	constexpr int branch_pixel_w = window_w / branch_pixel_size;
	constexpr int branch_pixel_h = window_h / branch_pixel_size;
	constexpr int branch_num = 100000;
	//アンモナイトの設定
	constexpr int ammonite_pixel_size = 1;
	constexpr int ammonite_pixel_w = window_w / ammonite_pixel_size;
	constexpr int ammonite_pixel_h = window_h / ammonite_pixel_size;
	constexpr int ammonite_num = 300000;
	//樹木の設定
	constexpr int tree_pixel_size = 1;
	constexpr int tree_pixel_w = window_w / tree_pixel_size;
	constexpr int tree_pixel_h = window_h / tree_pixel_size;
	constexpr int tree_num = 500000;

	enum class sceneE :int {
		mandelbrot_setE
		,barnsley_fernE
		,ssangyongE
		,branchE
		,ammoniteE
		,treeE
		,tailE
	};


}

#endif // !FRACTAL_CONFIGURATION_H