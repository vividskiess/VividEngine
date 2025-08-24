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