#pragma once

#ifdef VV_PLATFORM_WINDOWS
	#ifdef VV_BUILD_DLL
		#define VIVID_API _declspec(dllexport)
	#else 
		#define VIVID_API _declspec(dllimport)
	#endif
#else 
	#error Vivid only support Windows!
#endif

#ifdef VV_ENABLE_ASSERTS
	#define VV_ASSERT(x, ...) { if(!(x)) { VV_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define VV_CORE_ASSERT(x, ...) { if(!(x)) { VV_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define VV_ASSERT(x, ...)
	#define VV_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)