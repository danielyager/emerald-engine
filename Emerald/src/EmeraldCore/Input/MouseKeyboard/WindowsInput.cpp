#include "emeraldpch.h"
#include "WindowsInput.h"

Emerald::WindowsInput::WindowsInput(GLFWwindow* inputWindow) {
	m_InputWindow = inputWindow;
}

Emerald::WindowsInput::~WindowsInput() {
}

bool Emerald::WindowsInput::IsKeyPressed(int keyCode) {
	//GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
	return glfwGetKey(m_InputWindow, keyCode) == GLFW_PRESS;
}

bool Emerald::WindowsInput::IsMouseButtonPressed(int keyCode) {
	//GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
	return glfwGetMouseButton(m_InputWindow, keyCode) == GLFW_PRESS;
}

std::pair<float, float> Emerald::WindowsInput::GetMousePosition() {
	double xPosition;
	double yPosition;
	//GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
	glfwGetCursorPos(m_InputWindow, &xPosition, &yPosition);
	return std::pair<float, float>((float)xPosition, (float)yPosition);
}

float Emerald::WindowsInput::GetMouseX() {
	return GetMousePosition().first;
}

float Emerald::WindowsInput::GetMouseY() {
	return GetMousePosition().second;
}
