#pragma once

#ifdef VV_PLATFORM_WINDOWS
	
extern Vivid::Application* Vivid::CreateApplication();

int main(int argc, char** argv)
{
	//printf("Vivid Engine");
	auto app = Vivid::CreateApplication();
	app->Run();
	delete app;
}

#endif