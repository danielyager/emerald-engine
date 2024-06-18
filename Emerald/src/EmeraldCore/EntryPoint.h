#pragma once

#ifdef EMERALD_PLATFORM_WINDOWS

extern Emerald::Application* Emerald::CreateApplication();

int main(int argc, char** argv) {
	Emerald::Logger::Init();
	LOG_ERROR(7, "Testing Error Log. Channel Number = {0}", 7);
	LOG_WARN(7, "This is a warning test!!");
	LOG_SUCCESS(5, "Testing success log here.");
	LOG_TRACE(5, "Testing traces as well.");

	auto app = Emerald::CreateApplication();
	app->Run();
	delete app;
}

#endif