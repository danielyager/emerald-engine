#pragma once
#include "Core.h"
#include "EmeraldCore/Platform/OpenGL/GLWindow.h"
#include "EmeraldCore/LayerStack.h"
#include "EmeraldCore/Managers/InputManager.h"

namespace Emerald {

	class EMERALD_API Application {

	public:
		Application();
		virtual ~Application();

		static Application& Get();

		GLWindow& GetWindow();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		static Application* s_Instance;

		std::unique_ptr<GLWindow> m_Window;
		LayerStack m_LayerStack;

		InputManager* g_InputManager;
	};

	// To be defined in Client.
	Application* CreateApplication();

}