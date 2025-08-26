#include "Application.h"

#include "Vivid/Events/ApplicationEvent.h"
#include "Vivid/Log.h"

namespace Vivid {

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
		VV_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			VV_TRACE(e.ToString());
		}
		while (true);
	}

}
