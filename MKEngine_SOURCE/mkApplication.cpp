#include "mkApplication.h"


namespace mk
{
	Application::Application()
		:mHwnd(nullptr)
		, mHdc(nullptr)
	{
		obj1 = GameObject();
	}
	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		input.Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		obj1.Update();
		
	}
	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{

		obj1.Render(mHdc);
	}
}