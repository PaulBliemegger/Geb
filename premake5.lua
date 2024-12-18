workspace "Geb"
	architecture "x64"
	startproject "Sandbox"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Geb/vendor/GLFW/include"
include "Geb/vendor/GLFW"


project "Geb"
	location "Geb"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	pchheader "gbpch.h"
	pchsource "Geb/src/gbpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links 
	{ 
		"GLFW",
		"opengl32.lib"
	}


	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"
		defines
		{
			"GB_PLATFORM_WINDOWS",
			"GB_BUILD_DLL"
		}
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}
	filter "configurations:Debug"
		defines "GB_DEBUG"
		symbols "On"
		buildoptions { "/utf-8" }
	filter "configurations:Release"
		defines "GB_RELEASE"
		optimize "On"
		buildoptions { "/utf-8" }
	filter "configurations:Dist"
		defines "GB_DIST"
		optimize "On"
		buildoptions { "/utf-8" }

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"Geb/vendor/spdlog/include",
		"Geb/src"
	}
	links
	{
		"Geb"
	}
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"
		defines
		{
			"GB_PLATFORM_WINDOWS"
		}
	filter "configurations:Debug"
		defines "GB_DEBUG"
		symbols "On"
		buildoptions { "/utf-8" }
	filter "configurations:Release"
		defines "GB_RELEASE"
		optimize "On"
		buildoptions { "/utf-8" }
	filter "configurations:Dist"
		defines "GB_DIST"
		optimize "On"
		buildoptions { "/utf-8" }