#pragma once
#include "Commoninclude.h"
#include "GameObject.h"
#include "mkInput.h"

namespace mk
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

	private:
		Input input;
		HWND mHwnd;
		HDC mHdc;

		GameObject obj1;
	};
}


