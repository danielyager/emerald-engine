#pragma once

#include "EmeraldCore/Input/Input.h"
#include <GLFW/glfw3.h>

namespace Emerald {

	class WindowsInput : public IInput {
	public:
		WindowsInput(GLFWwindow* inputWindow);
		~WindowsInput();

		virtual bool IsKeyPressed(int keyCode) override;
		virtual bool IsMouseButtonPressed(int keyCode) override;

		virtual std::pair<float, float> GetMousePosition() override;
		virtual float GetMouseX() override;
		virtual float GetMouseY() override;

	private:
		GLFWwindow* m_InputWindow;
	};
}