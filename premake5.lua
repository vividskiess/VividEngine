workspace "Vivid"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Vivid"
	location "Vivid"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"VV_PLATFORM_WINDOWS",
			"VV_BUILD_DLL",
		}

		postbuildcommands
		{
			"{RMDIR} ../bin/" .. outputdir .. "/Sandbox",
			"{MKDIR} ../bin/" .. outputdir .. "/Sandbox",

			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/")
		}

	filter "configurations:Debug"
		defines "VV_DEBUG"
		symbols "On"
		buildoptions "/utf-8"


	filter "configurations:Release"
		defines "VV_RELEASE"
		symbols "On"
		buildoptions "/utf-8"

	filter "configurations:Dist"
		defines "VV_DIST"
		symbols "On"
		buildoptions "/utf-8"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Vivid/vendor/spdlog/include",
		"Vivid/src"
	}

	links 
	{
		"Vivid"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"VV_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "VV_DEBUG"
		symbols "On"
		buildoptions "/utf-8"

	filter "configurations:Release"
		defines "VV_RELEASE"
		symbols "On"
		buildoptions "/utf-8"


	filter "configurations:Dist"
		defines "VV_DIST"
		symbols "On"
		buildoptions "/utf-8"
