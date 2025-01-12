#include "emeraldpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "EmeraldCore/Platform/OpenGL/GLWindow.h"
#include "EmeraldCore/Platform/WindowsInput.h"
#include "EmeraldCore/Util/KeyCodes.h"

namespace Emerald {

	Application* Application::s_Instance = nullptr;

	Application::Application() {
		s_Instance = this;
		m_Window = std::make_unique<GLWindow>(1600, 850, "Emerald Engine");
		g_InputManager = &InputManager::StartUp();
	}

	Application::~Application() {}

	Application& Application::Get() {
		return *s_Instance;
	}

	GLWindow& Application::GetWindow() {
		return *m_Window;
	}

	void Application::Run() {
		if (!m_Window) {
			LOG_ERROR("Our GL Window is null!");
		}
		if (!g_InputManager) {
			LOG_ERROR("g_InputManager is NULL in Application Run!");
		}


		while (m_Window && !m_Window->ShouldClose()) {
			m_Window->ProcessInput();

			m_Window->ClearBuffer();
			m_LayerStack.UpdateLayersAndOverlays();
			m_Window->SwapBuffer();

			if (g_InputManager) {
				g_InputManager->ProcessInput();
			}
		}

		m_LayerStack.DetachLayersAndOverlays();
		g_InputManager->ShutDown();
		m_Window->Shutdown();
	}

	void Application::OnEvent(Event& e) {
		// Lots of work to do here! Let's revisit this later.
	}


	void Application::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
	}


	void Application::PushOverlay(Layer* layer) {
		m_LayerStack.PushOverlay(layer);
	}
}