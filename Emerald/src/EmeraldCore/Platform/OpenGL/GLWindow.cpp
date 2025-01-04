#include "emeraldpch.h"
#include "GLWindow.h"

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
			LOG_ERROR(0, "Window in GLWindow is NULL!");
			return true;
		}
		//LOG_TRACE(0, "Window in GLWindow should close now!");
		return glfwWindowShouldClose(m_GLFWwindow);
	}

	void GLWindow::ProcessInput() {
		if (glfwGetKey(m_GLFWwindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(m_GLFWwindow, true);
		}
	}

	void GLWindow::RunRenderTest() {
		// Rendering commands
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

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
			LOG_ERROR(0, "Failed to create OpenGL Window. Window is NULL!");
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(m_GLFWwindow);
		glfwSetFramebufferSizeCallback(m_GLFWwindow, framebuffer_size_callback);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			LOG_ERROR(0, "Failed to initialize GLAD.");
			return;
		}

		glViewport(0, 0, m_Width, m_Height);
		LOG_SUCCESS(0, "Successfully initialized the OpenGL window! Size = [{0} x {1}]", m_Width, m_Height);
	}

}