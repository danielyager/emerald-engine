#pragma once

#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Emerald {

	class Shader {
	public:
		unsigned int m_ShaderProgramID;

	public:
		Shader(const char* vertexFilePath, const char* fragmentFilePath);

		void UseShaderProgram();

		// utility uniform functions
		void setBool(const std::string& name, bool value) const;
		void setInt(const std::string& name, int value) const;
		void setFloat(const std::string& name, float value) const;

		const char* GetVertexShader();
		const char* GetFragmentShader();

	private:
		unsigned int m_VertexShaderID;
		unsigned int m_FragmentShaderID;
		const char* m_VertShader;
		const char* m_FragShader;
		std::string m_VertString;
		std::string m_FragString;

	private:
		void CompileVertexShader();
		void CompileFragmentShader();
	};
}

#endif