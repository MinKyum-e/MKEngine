#pragma once
#include "Commoninclude.h"
#include "mkGameObject.h"
#include "mkInput.h"
#include "mktime.h"
#include "mkScene.h"

namespace mk
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, const UINT width, const UINT height);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

		HDC GetHdc() { return mHdc; }

	private:
		void adjectWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT heigth);
		void initializeEtc();
		
		void renderTimers(HDC hdc);
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);


		
	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitBap;

		
		UINT mWidth;
		UINT mHeight;

		std::vector<Scene* > mScenes;
		Time::TIMER mUpdateTime;
		Time::TIMER mLateUpdateTime;
		Time::TIMER mRenderTime;
	};
}


