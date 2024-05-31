#pragma once

#ifdef EMERALD_PLATFORM_WINDOWS

extern Emerald::Application* Emerald::CreateApplication();

int main(int argc, char** argv) {
	auto app = Emerald::CreateApplication();
	app->Run();
	delete app;
}

#endif