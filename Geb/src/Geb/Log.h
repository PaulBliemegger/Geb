#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Geb
{
	class GEB_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;  }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		 
	};
}

// Core log macros
#define GB_CORE_TRACE(...)	::Geb::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GB_CORE_INFO(...)	::Geb::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GB_CORE_WARN(...)	::Geb::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GB_CORE_ERROR(...)	::Geb::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GB_CORE_FATAL(...)	::Geb::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define GB_TRACE(...)	::Geb::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GB_INFO(...)	::Geb::Log::GetClientLogger()->info(__VA_ARGS__)
#define GB_WARN(...)	::Geb::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GB_ERROR(...)	::Geb::Log::GetClientLogger()->error(__VA_ARGS__)
#define GB_FATAL(...)	::Geb::Log::GetClientLogger()->fatal(__VA_ARGS__)