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

	void Application::adjectWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;


		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		//������ �ػ󵵿� �´� �� ����
		mBackBitBap = CreateCompatibleBitmap(mHdc, width, height);

		//����۸� ����ų DC����
		mBackHdc = CreateCompatibleDC(mHdc);

		//���ο� backhdc�� defualt�� ����ִ� bit�ʰ� �ػ󵵿� �´� �� ����bit�� ü�����ϸ鼭 default�� ������
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
		Update();
		LateUpdate();
		Render();
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

		Time::Render(mBackHdc);
		SceneManager::Render(mBackHdc);
		copyRenderTarget(mBackHdc, mHdc);

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