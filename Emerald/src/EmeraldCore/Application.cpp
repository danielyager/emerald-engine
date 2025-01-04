#include "emeraldpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "EmeraldCore/Platform/OpenGL/GLWindow.h"
#include "EmeraldCore/Platform/WindowsInput.h"
#include "EmeraldCore/Util/KeyCodes.h"

namespace Emerald {

	Application::Application() {
		m_Window = nullptr;
	}

	Application::~Application() {}

	void Application::Run() {
		GLWindow win = GLWindow(800, 600, "Testing out the window class!");
		m_Window = &win;
		WindowsInput input = WindowsInput(static_cast<GLFWwindow*>(m_Window->GetNativeWindow()));

		if (!m_Window) {
			LOG_ERROR(0, "Our GL Window is null!");
		}

		while (m_Window && !m_Window->ShouldClose()) {
			m_Window->ProcessInput();
			m_Window->RunRenderTest();

			if (input.IsKeyPressed(Key::A)) {
				LOG_TRACE(0, "We're pressing the \"A\" key!");
			}

			//std::pair<float, float> mousePosition = input.GetMousePosition();
			//LOG_TRACE(0, "Current Mouse Position: {0}, {1}", mousePosition.first, mousePosition.second);
		}
		m_Window->Shutdown();
	}
}