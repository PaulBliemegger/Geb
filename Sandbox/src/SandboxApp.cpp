#include <Geb.h>

class Sandbox : public Geb::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Geb::Application* Geb::CreateApplication()
{
	return new Sandbox();
}