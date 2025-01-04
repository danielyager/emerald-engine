#pragma once
#include "EmeraldCore/Window.h"

#include <GLFW/glfw3.h>

namespace Emerald {

	class GLWindow : public IWindow {
	public:
		GLWindow();
		GLWindow(const unsigned int width, const unsigned int  height, const std::string title);
		~GLWindow();
		void OnUpdate() override;
		void Shutdown();
		unsigned int GetWidth() const override;
		unsigned int GetHeight() const override;
		bool ShouldClose();

		void ProcessInput();

		void RunRenderTest();

		virtual void* GetNativeWindow() const;
	private:
		GLFWwindow* m_GLFWwindow;

		void Initialize(const unsigned int width, const unsigned int  height, const std::string title);
	};
}