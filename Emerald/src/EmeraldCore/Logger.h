#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Emerald {

	class EMERALD_API Logger {

	public:
		enum Verbosity : int {
			Trace = 0,
			Debug = 1,
			Info = 2,
			Warn = 3,
			Error = 4,
			Critical = 5,
			Off = 6
		};

		static void Init();

		inline static Verbosity GetVerbosity() { return verbosity; }
		static void SetVerbosity(Verbosity newVerbosity);

		template<typename T, typename... Args>
		static void Log(int logType, int channel, T message, Args... args);

	private:
		static std::shared_ptr<spdlog::logger> s_ELogger;
		static Verbosity verbosity;
	};

	template<typename T, typename ...Args>
	inline void Logger::Log(int logType, int channel, T message, Args ...args) {
		std::string newMessage = "";
		if (logType == 0) {
			s_ELogger->trace(newMessage + "[TRACE]  " + message, args...);
		} else if (logType == 2) {
			s_ELogger->info(newMessage + "[SUCCESS]  " + message, args...);
		} else if (logType == 3) {
			s_ELogger->warn(newMessage + "[WARN]  " + message, args...);
		} else if (logType == 4) {
			s_ELogger->error(newMessage + "[ERROR]  " + message, args...);
		}
	}

}

#define LOG_TRACE(...)		::Emerald::Logger::Log(0, __VA_ARGS__)
#define LOG_SUCCESS(...)	::Emerald::Logger::Log(2, __VA_ARGS__)
#define LOG_WARN(...)		::Emerald::Logger::Log(3, __VA_ARGS__)
#define LOG_ERROR(...)		::Emerald::Logger::Log(4, __VA_ARGS__)

// Add macros that remove logging when this is a distribution build.