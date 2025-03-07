#pragma once
#include "Commoninclude.h"

namespace mk
{
	class Time
	{

	public:
		typedef LARGE_INTEGER TIMER;

	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return deltaTimeValue; }
		static LARGE_INTEGER GetCurrFrequency() { return currFrequency; }

		//Timer Functions
		static void StartTimer(LARGE_INTEGER* timer);
		static void EndTimer(LARGE_INTEGER* timer);

		//Render Time
		static void RenderTimer(HDC hdc, LARGE_INTEGER time, const wchar_t* timer_name, int tx, int ty, int max_length);
	
	private:
		static void renderFps(HDC hdc, int x, int y);

	private:

		static LARGE_INTEGER cpuFrequency;
		static LARGE_INTEGER prevFrequency;
		static LARGE_INTEGER currFrequency;
		static float deltaTimeValue;
	};


}
