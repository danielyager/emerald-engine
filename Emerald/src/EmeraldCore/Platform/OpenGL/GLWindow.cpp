#include "emeraldpch.h"
#include "GLWindow.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

namespace Emerald {

	void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	GLWindow::GLWindow() { m_GLFWwindow = nullptr; }

	GLWindow::GLWindow(const unsigned int width, const unsigned int height, const std::string title) {
		Initialize(width, height, title);
	}

	GLWindow::~GLWindow() {
		Shutdown();
	}

	void GLWindow::OnUpdate() {
	}

	void GLWindow::Shutdown() {
		glfwTerminate();
	}

	unsigned int GLWindow::GetWidth() const {
		return m_Width;
	}

	unsigned int GLWindow::GetHeight() const {
		return m_Height;
	}

	bool GLWindow::ShouldClose() {
		if (!m_GLFWwindow) {
			LOG_ERROR("Window in GLWindow is NULL!");
			return true;
		}
		//LOG_TRACE("Window in GLWindow should close now!");
		return glfwWindowShouldClose(m_GLFWwindow);
	}

	void GLWindow::ProcessInput() {
		glfwPollEvents();
		if (glfwGetKey(m_GLFWwindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(m_GLFWwindow, true);
		}
	}

	void GLWindow::ClearBuffer() {
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void GLWindow::SwapBuffer() {
		glfwSwapBuffers(m_GLFWwindow);

	}

	void GLWindow::RunRenderTest() {
		// Check and call events and swap the buffers
		glfwSwapBuffers(m_GLFWwindow);
		glfwPollEvents();
	}

	void* GLWindow::GetNativeWindow() const {
		return m_GLFWwindow;
	}

	void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		// make sure the viewport matches the new window dimensions; note that width and 
		// height will be significantly larger than specified on retina displays.
		glViewport(0, 0, width, height);
	}

	void GLWindow::Initialize(const unsigned int width, const unsigned int height, const std::string title) {
		m_Width = width;
		m_Height = height;
		m_Title = title;

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);    // For MAC OS only

		m_GLFWwindow = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);

		if (!m_GLFWwindow) {
			LOG_ERROR("Failed to create OpenGL Window. Window is NULL!");
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(m_GLFWwindow);
		glfwSetFramebufferSizeCallback(m_GLFWwindow, framebuffer_size_callback);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			LOG_ERROR("Failed to initialize GLAD.");
			return;
		}

		glViewport(0, 0, m_Width, m_Height);
		LOG_SUCCESS("Successfully initialized the OpenGL window! Size = [{0} x {1}]", m_Width, m_Height);
		glfwGetWindowUserPointer(m_GLFWwindow);
	}

}