#pragma once

#include "EmeraldCore/Core.h"

namespace Emerald {

	class EMERALD_API IInput {
	public:
		virtual bool IsKeyPressed(int keyCode) = 0;
		virtual bool IsMouseButtonPressed(int keyCode) = 0;

		virtual std::pair<float, float> GetMousePosition() = 0;
		virtual float GetMouseX() = 0;
		virtual float GetMouseY() = 0;
	};
}