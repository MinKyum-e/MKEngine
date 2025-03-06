#pragma once
#include "Commoninclude.h"

namespace mk
{
	class Time
	{

	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return deltaTimeValue; }
		static LARGE_INTEGER GetCurrFrequency() { return currFrequency; }
		static void StartTimer(LARGE_INTEGER* start) {QueryPerformanceCounter(start);}
		static void EndTimer(LARGE_INTEGER* end) { QueryPerformanceCounter(end); }

		static void ShowTimer(HDC hdc, LARGE_INTEGER start, LARGE_INTEGER end, const wchar_t* timer_name, int tx, int ty, int max_length);
	private:

		static LARGE_INTEGER cpuFrequency;
		static LARGE_INTEGER prevFrequency;
		static LARGE_INTEGER currFrequency;
		static float deltaTimeValue;

	};


}
