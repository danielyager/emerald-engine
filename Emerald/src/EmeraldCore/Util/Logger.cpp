#include "emeraldpch.h"
#include "Logger.h"

namespace Emerald {

	std::shared_ptr<spdlog::logger> Logger::s_ELogger;
	Logger::Verbosity Logger::verbosity;

	void Logger::Init() {
		spdlog::set_pattern("%^[%T]: %v%$");
		s_ELogger = spdlog::stdout_color_mt("EMERALD LOGGER");
		SetVerbosity(Logger::Verbosity::Trace);
	}

	void Logger::SetVerbosity(Logger::Verbosity newVerbosity) {
		verbosity = newVerbosity;
		switch (verbosity) {
			case Verbosity::Trace:
				s_ELogger->set_level(spdlog::level::trace);
				break;
			case Verbosity::Debug:
				s_ELogger->set_level(spdlog::level::debug);
				break;
			case Verbosity::Info:
				s_ELogger->set_level(spdlog::level::info);
				break;
			case Verbosity::Warn:
				s_ELogger->set_level(spdlog::level::warn);
				break;
			case Verbosity::Error:
				s_ELogger->set_level(spdlog::level::err);
				break;
			case Verbosity::Critical:
				s_ELogger->set_level(spdlog::level::critical);
				break;
			case Verbosity::Off:
				s_ELogger->set_level(spdlog::level::off);
				break;
			default:
				s_ELogger->set_level(spdlog::level::trace);
				break;
		}
	}
}