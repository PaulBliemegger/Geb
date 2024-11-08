#pragma once


/* Note to self
This is called by the client(in this case SandboxApp, but could be any other game).
This way the engine defines how entry points look like, but clients call them.
Allows for configuration on both sides??
*/ 

#ifdef GB_PLATFORM_WINDOWS

extern Geb::Application* Geb::CreateApplication();

int main(int argc, char** argv)
{
	Geb::Log::Init();
	GB_CORE_WARN("Initialized Log!");
	int a = 5;
	GB_INFO("Hello! Var={0}", a);

	auto app = Geb::CreateApplication();
	app->Run();
	delete app;
}

#endif