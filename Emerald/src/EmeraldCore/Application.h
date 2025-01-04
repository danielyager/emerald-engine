#pragma once
#include "Core.h"
#include "EmeraldCore/Platform/OpenGL/GLWindow.h"

namespace Emerald {

	class EMERALD_API Application {

	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		static Application* s_Instance;

		GLWindow* m_Window;
	};

	// To be defined in Client.
	Application* CreateApplication();

}