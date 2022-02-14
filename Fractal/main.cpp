#include "main.h"

namespace fractal {
	bool Update() { return (DxLib::ScreenFlip() != -1 && DxLib::ClearDrawScreen() != -1 && DxLib::ProcessMessage() != -1); }

	void Main() {

	}
}
