#pragma once

#include "EmeraldCore/Platform/WindowsInput.h"

namespace Emerald {

	class EMERALD_API InputManager {
	public:
		InputManager(const InputManager&) = delete;
		~InputManager();

		static InputManager& StartUp();
		void ShutDown();

		void ProcessInput();

	private:
		InputManager();

		GLFWwindow* m_GLWindow;
		std::unique_ptr<WindowsInput> m_DesktopInput;
	};
}
