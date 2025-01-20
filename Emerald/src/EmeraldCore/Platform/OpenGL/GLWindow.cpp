#include "emeraldpch.h"
#include "GLWindow.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

namespace Emerald {

	const char* vertexShaderSource = "#version 430 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 aColor;\n"
		"out vec3 ourColor;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos, 1.0);\n"
		"	ourColor = aColor;\n"
		"}\0";

	const char* fragmentShaderSource = "#version 430 core\n"
		"in vec3 ourColor;\n"
		"out vec4 FragColor;\n"
		"void main() {\n"
		"	FragColor = vec4(ourColor, 1.0);\n"
		"}\0";

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
		//glfwSwapBuffers(m_GLFWwindow);
		//glfwPollEvents();

		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		/////////////////////////////////////////
		/////// Preparing the Vertex Data ///////
		/////////////////////////////////////////
		float vertices[] = {
			// positions         // colors
			-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
			 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
			 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
		};
		/*
		float vertices[] = {
			 0.5f,  0.5f, 0.0f,  // top right
			 0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f,  // bottom left
			-0.5f,  0.5f, 0.0f   // top left 
		};
		*/
		unsigned int indices[] = {  // note that we start from 0!
			0, 1, 2
		};

		unsigned int VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		// Create element buffer object.
		unsigned int EBO;
		glGenBuffers(1, &EBO);

		// Copy indixes into the buffer.
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


		/////////////////////////////////
		/////// The Vertex Shader ///////
		/////////////////////////////////
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		// Check if there were any errors compiling the shader.
		int  success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}


		///////////////////////////////////
		/////// The Fragment Shader ///////
		///////////////////////////////////
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		// Check if there were any errors compiling the shader.
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}


		/////////////////////////////////////////////////////
		/////// Linking Shaders Into a Shader Program ///////
		/////////////////////////////////////////////////////
		unsigned int shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);

		// Check if there were any errors linking the shader.
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::Linking::COMPILATION_FAILED\n" << infoLog << std::endl;
		}


		//float timeValue = glfwGetTime();
		//float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
		//int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");


		// Activate shader program for all shader and rendering calls to use the linked shaders.
		glUseProgram(shaderProgram);


		// Set the value of the uniform variable in the fragment shader for color value.
		//glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);


		// Delete shader objects after linking them into the program object.
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		
		//////////////////////////////////////////
		/////// Create Vertex Array Object ///////
		//////////////////////////////////////////
		unsigned int VAO;
		glGenVertexArrays(1, &VAO);

		// 1. bind Vertex Array Object
		glBindVertexArray(VAO);
		// 2. copy our vertices array in a vertex buffer for OpenGL to use
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		// 3. copy our index array in a element buffer for OpenGL to use
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
		// 4. then set our vertex attributes pointers / link vertex attributes
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		

		///////////////////////////////
		/////// Draw the Object ///////
		///////////////////////////////
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
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