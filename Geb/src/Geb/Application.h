#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Geb/Events/ApplicationEvent.h"
#include "Window.h"


namespace Geb {

	class GEB_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClosed(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in the client
	Application* CreateApplication();
}
