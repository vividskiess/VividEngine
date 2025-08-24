#include <Vivid.h>

class Sandbox : public Vivid::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Vivid::Application* Vivid::CreateApplication()
{
	return new Sandbox();
}