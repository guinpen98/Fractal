#ifndef FRACTAL_SCENE_HPP
#define FRACTAL_SCENE_HPP
#include"tree.hpp"
#include"branch.hpp"
#include"ammonite.hpp"
#include"ssangyong.hpp"
#include"barnsley_fern.hpp"
#include"mandelbrot_set.hpp"
#include"gumowski_mira_attractor.hpp"
namespace fractal {
	void scene() {
		sceneE current_scene = sceneE::mandelbrot_setE;
		color_matrix pixel(window_h, color_array(window_w, white));
		mandelbrotScene(pixel);
		int pixel_size = mandelbrot_pixel_size;
		for (int y = 0; y < window_h / pixel_size; y++)
			for (int x = 0; x < window_w / pixel_size; x++)
				DrawBox(x * pixel_size, y * pixel_size, (x + 1) * pixel_size, (y + 1) * pixel_size, pixel[y][x], TRUE);
		//key“ü—Í
		bool is_key_down = false;

		while (fractal::update()) {
			if (CheckHitKey(KEY_INPUT_SPACE) == 0) {
				is_key_down = false;
				continue;
			}
			else if (is_key_down) continue;

			fill(white, pixel);
			is_key_down = true;
			moveScene(current_scene);
			switch (current_scene)
			{
			case sceneE::mandelbrot_setE:
				mandelbrotScene(pixel);
				pixel_size = mandelbrot_pixel_size;
				break;
			case sceneE::barnsley_fernE:
				barnsleyFernScene(pixel);
				pixel_size = fern_pixel_size;
				break;
			case sceneE::ssangyongE:
				ssangyongScene(pixel);
				pixel_size = ssangyong_pixel_size;
				break;
			case sceneE::branchE:
				branchScene(pixel);
				pixel_size = branch_pixel_size;
				break;
			case sceneE::ammoniteE:
				ammoniteScene(pixel);
				pixel_size = ammonite_pixel_size;
				break;
			case sceneE::treeE:
				treeScene(pixel);
				pixel_size = tree_pixel_size;
				break;
			case sceneE::gumowski_mira_attractorE:
				gumowskiMiraAttractorScene(pixel);
			default:
				break;
			}
			for (int y = 0; y < window_h / pixel_size; y++)
				for (int x = 0; x < window_w / pixel_size; x++)
					DrawBox(x * pixel_size, y * pixel_size, (x + 1) * pixel_size, (y + 1) * pixel_size, pixel[y][x], TRUE);
		}
	}
}

#endif // !FRACTAL_SCENE_HPP


