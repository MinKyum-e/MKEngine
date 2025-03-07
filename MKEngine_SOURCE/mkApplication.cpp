#include "mkApplication.h"
#include "mkSceneManager.h"

namespace mk
{
	Application::Application()
		:mHwnd(nullptr)
		, mHdc(nullptr)
		, mHeight(0)
		, mWidth(0)
		, mBackHdc(nullptr)
		, mBackBitBap(nullptr)
		, mUpdateTime({})
		, mLateUpdateTime({})
		, mRenderTime({})
	{
	}
	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd, const UINT width, const UINT height)
	{
		adjectWindowRect(hwnd, width, height);
		createBuffer(mWidth, mHeight);
		initializeEtc();

		SceneManager::Initialize();
	}


	/// <summary>
	/// Just adjust it according to the actual window size excluding the toolbar
	/// </summary>
	/// <param name="hwnd">window handler</param>
	/// <param name="width">wanted width </param>
	/// <param name="height">wanted height</param>
	void Application::adjectWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;


		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		//윈도우 해상도에 맞는 백 버퍼
		mBackBitBap = CreateCompatibleBitmap(mHdc, width, height);

		//백버퍼를 가리킬 DC생성
		mBackHdc = CreateCompatibleDC(mHdc);

		//새로운 backhdc에 defualt로 들어있는 bit맵과 해상도에 맞는 백 버퍼bit와 체인지하면서 default를 지워줌
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitBap);
		DeleteObject(oldBitmap);
	}

	void Application::initializeEtc()
	{
		Input::Initialize();
		Time::Initialize();
	}

	void Application::Run()
	{
		Time::TIMER timer;

		Time::StartTimer(&timer);
		Update();
		Time::EndTimer(&timer);
		mUpdateTime.QuadPart = timer.QuadPart;

		Time::StartTimer(&timer);
		LateUpdate();
		Time::EndTimer(&timer);
		mLateUpdateTime.QuadPart = timer.QuadPart;

		Time::StartTimer(&timer);
		Render();
		Time::EndTimer(&timer);
		mRenderTime.QuadPart = timer.QuadPart;
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();
		SceneManager::Update();
		
	}
	void Application::LateUpdate()
	{
		Input::LateUpdate();
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		clearRenderTarget();
		
		SceneManager::Render(mBackHdc);

		renderTimers(mBackHdc);
		Time::Render(mBackHdc);

		copyRenderTarget(mBackHdc, mHdc);
	}

	void Application::renderTimers(HDC hdc)
	{
		Time::RenderTimer(hdc, mUpdateTime, L"UpdateTime", 400, 0, 40);
		Time::RenderTimer(hdc, mLateUpdateTime, L"LateUpdateTime", 800, 0, 40);
		Time::RenderTimer(hdc, mRenderTime, L"RenderTime", 1200, 0, 40);
	}

	void Application::clearRenderTarget()
	{
		Rectangle(mBackHdc, -1, -1, mWidth + 1, mHeight + 1);

	}

	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}
}