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

		Input::Initialize();
		Time::Initialize();
		
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
		Time::Update();
		obj1.Update();
		
	}
	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		Time::Render(mHdc);
		obj1.Render(mHdc);
	}
}