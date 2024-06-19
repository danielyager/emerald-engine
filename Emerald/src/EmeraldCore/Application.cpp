#include "emeraldpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "EmeraldCore/Platform/OpenGL/GLWindow.h"

namespace Emerald {

	Application::Application() {
	}

	Application::~Application() {
	}

	void Application::Run() {
		GLWindow glWindow = GLWindow(800, 600, "Testing out the window class!");

		while (!glWindow.ShouldClose()) {
			glWindow.ProcessInput();
			glWindow.RunRenderTest();
		}
		glWindow.Shutdown();
	}
}