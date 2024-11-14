#include "gbpch.h"
#include "Application.h"

#include "Events/Event.h"
#include "Geb/Events/ApplicationEvent.h"
#include "Geb/Log.h"


namespace Geb {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			GB_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			GB_TRACE(e.ToString());
		}

		while (true);
	}
}