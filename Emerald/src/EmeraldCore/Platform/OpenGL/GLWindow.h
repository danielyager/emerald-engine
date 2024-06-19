#pragma once
#include "EmeraldCore/Window.h"

namespace Emerald {

	class GLWindow : public IWindow {
	public:
		GLWindow(const unsigned int width, const unsigned int  height, const std::string title);
		~GLWindow();
		void OnUpdate() override;
		void Shutdown();
		unsigned int GetWidth() const override;
		unsigned int GetHeight() const override;
		bool ShouldClose();

		void ProcessInput();

		void RunRenderTest();
	private:
		GLFWwindow* m_Window;

		void Initialize(const unsigned int width, const unsigned int  height, const std::string title);
	};
}