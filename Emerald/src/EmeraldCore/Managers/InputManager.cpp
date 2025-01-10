#include "emeraldpch.h"
#include "InputManager.h"
#include "EmeraldCore/Application.h"
#include "EmeraldCore/Util/KeyCodes.h"

namespace Emerald {

	InputManager::InputManager() {
		m_GLWindow = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		m_DesktopInput = std::make_unique<WindowsInput>(m_GLWindow);
	}

	InputManager::~InputManager() { /* Do Nothing. */ }

	InputManager& Emerald::InputManager::StartUp() {
		LOG_TRACE("Starting up the InputManager.");
		static InputManager singletonInputManager;
		return singletonInputManager;
	}

	void InputManager::ShutDown() {
		// TODO: Setup shutdown functionality for this when needed.
	}
	void InputManager::ProcessInput() {
		if (m_DesktopInput->IsKeyPressed(Key::A)) {
			LOG_TRACE("We're pressing the \"A\" key!");
		}
	}
}