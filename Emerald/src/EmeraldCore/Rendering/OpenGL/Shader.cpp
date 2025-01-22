#include "emeraldpch.h"
#include "Shader.h"
#include <filesystem>

namespace Emerald {

	Shader::Shader(const char* vertexFilePath, const char* fragmentFilePath) {
		std::ifstream vertFile;
		std::ifstream fragFile;

		// ensure ifstream objects can throw exceptions:
		vertFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fragFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try {
			// open files
			vertFile.open((std::filesystem::current_path().string()) + "\\Assets\\Shaders\\OpenGL\\" + vertexFilePath);
			fragFile.open((std::filesystem::current_path().string()) + "\\Assets\\Shaders\\OpenGL\\" + fragmentFilePath);
			std::stringstream vertStream;
			std::stringstream fragStream;

			// read files into stream
			vertStream << vertFile.rdbuf();
			fragStream << fragFile.rdbuf();

			// close files
			vertFile.close();
			fragFile.close();

			// create strings from the streams
			m_VertString = vertStream.str();
			m_FragString = fragStream.str();
		} catch (std::ifstream::failure e) {
			//LOG_ERROR("Failed to read shader files in shader!");
			#pragma warning(suppress : 4996)
			LOG_ERROR("File Read Error: {0}", strerror(errno));
			return;
		}

		// create C strings from the Cpp strings
		m_VertShader = m_VertString.c_str();
		m_FragShader = m_FragString.c_str();


		// compile shaders
		CompileVertexShader();
		CompileFragmentShader();


		// shader program
		m_ShaderProgramID = glCreateProgram();
		glAttachShader(m_ShaderProgramID, m_VertexShaderID);
		glAttachShader(m_ShaderProgramID, m_FragmentShaderID);
		glLinkProgram(m_ShaderProgramID);

		// print any errors
		int success;
		char infoLog[512];
		glGetProgramiv(m_ShaderProgramID, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(m_ShaderProgramID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		// delete shaders since they're linked into the program and no longer necessary
		glDeleteShader(m_VertexShaderID);
		glDeleteShader(m_FragmentShaderID);
	}

	void Shader::UseShaderProgram() {
		glUseProgram(m_ShaderProgramID);
	}

	void Shader::setBool(const std::string& name, bool value) const {
		// TODO: Add code for setting uniform values here.
	}

	void Shader::setInt(const std::string& name, int value) const {
		// TODO: Add code for setting uniform values here.
	}

	void Shader::setFloat(const std::string& name, float value) const {
		// TODO: Add code for setting uniform values here.
	}

	const char* Shader::GetVertexShader() {
		return m_VertShader;
	}

	const char* Shader::GetFragmentShader() {
		return m_FragShader;
	}

	void Shader::CompileVertexShader() {
		m_VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(m_VertexShaderID, 1, &m_VertShader, NULL);
		glCompileShader(m_VertexShaderID);

		// Check if there were any errors compiling the shader.
		int  success;
		char infoLog[512];
		glGetShaderiv(m_VertexShaderID, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(m_VertexShaderID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}

	void Shader::CompileFragmentShader() {
		m_FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(m_FragmentShaderID, 1, &m_FragShader, NULL);
		glCompileShader(m_FragmentShaderID);

		// Check if there were any errors compiling the shader.
		int  success;
		char infoLog[512];
		glGetShaderiv(m_FragmentShaderID, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(m_FragmentShaderID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}
}
