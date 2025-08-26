#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Vivid {

	class VIVID_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define VV_CORE_TRACE(...)     ::Vivid::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VV_CORE_INFO(...)      ::Vivid::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VV_CORE_WARN(...)      ::Vivid::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VV_CORE_ERROR(...)     ::Vivid::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VV_CORE_FATAL(...)     ::Vivid::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define VV_TRACE(...)          ::Vivid::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VV_INFO(...)           ::Vivid::Log::GetClientLogger()->info(__VA_ARGS__)
#define VV_WARN(...)           ::Vivid::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VV_ERROR(...)          ::Vivid::Log::GetClientLogger()->error(__VA_ARGS__)
#define VV_FATAL(...)          ::Vivid::Log::GetClientLogger()->fatal(__VA_ARGS__)