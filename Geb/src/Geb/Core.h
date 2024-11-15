#pragma once

#ifdef GB_PLATFORM_WINDOWS
	#ifdef GB_BUILD_DLL
		#define GEB_API __declspec(dllexport)
	#else
		#define GEB_API __declspec(dllimport)
	#endif
#else
	#error Geb only supports Windows!
#endif // GB_BUILD_DLL

#ifdef GB_ENABLE_ASSERTS
#define GB_ASSERT(x, ...) { if(!(x)) { GB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define GB_CORE_ASSERT(x, ...) { if(!(x)) { GB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define GB_ASSERT(x, ...)
#define GB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
