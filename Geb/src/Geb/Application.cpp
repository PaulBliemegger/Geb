#include "gbpch.h"
#include "Application.h"

#include "Events/Event.h"
#include "Geb/Events/ApplicationEvent.h"
#include "Geb/Log.h"
#include <GLFW/glfw3.h>

namespace Geb {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running) 
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}