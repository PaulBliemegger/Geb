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
project "Geb"
	location "Geb"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.19041.0"
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
		systemversion "10.0.19041.0"
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