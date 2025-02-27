#include "mkApplication.h"


namespace mk
{
	Application::Application()
		:mHwnd(nullptr)
		, mHdc(nullptr)
	{
		obj1 = GameObject();
		obj2 = GameObject(1);
	}
	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		obj1.Update();
		obj2.Update();
		
	}
	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{

		obj1.Render(mHdc);
		obj2.Render(mHdc);
	}
}