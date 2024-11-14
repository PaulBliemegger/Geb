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

#define BIT(x) (1 << x)
