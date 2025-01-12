#include "Emerald.h"


class Sandbox : public Emerald::Application {
public:
	Sandbox() {
		PushLayer(new Emerald::ImGuiLayer());
	}

	~Sandbox() {

	}
};

Emerald::Application* Emerald::CreateApplication() {
	return new Sandbox();
}