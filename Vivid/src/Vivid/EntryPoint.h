#pragma once

#ifdef VV_PLATFORM_WINDOWS
	
extern Vivid::Application* Vivid::CreateApplication();

int main(int argc, char** argv)
{
	Vivid::Log::Init();
	VV_CORE_WARN("Initialised Log!");
	int a = 5;
	VV_INFO("Hello Var={0}", a);
	//printf("Vivid Engine");

	auto app = Vivid::CreateApplication();
	app->Run();
	delete app;
}

#endif