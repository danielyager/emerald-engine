#include "emeraldpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Logger.h"

namespace Emerald {

	Application::Application() {
	}

	Application::~Application() {
	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		LOG_TRACE(0, e.ToString());
		while (true);
	}

}