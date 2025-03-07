#include "mkTime.h"


namespace mk
{
	LARGE_INTEGER Time::cpuFrequency = {};
	LARGE_INTEGER Time::prevFrequency = {};
	LARGE_INTEGER Time::currFrequency = {};
	float Time::deltaTimeValue = 0.0f;


	void Time::Initialize()
	{
		//cpu 고유 frequency 
		QueryPerformanceFrequency(&cpuFrequency);
		//cpu 현재 frequency
		QueryPerformanceCounter(&prevFrequency);
		

	}

	void Time::Update()
	{
		QueryPerformanceCounter(&currFrequency);
		float diff_frequency = static_cast<float>(currFrequency.QuadPart - prevFrequency.QuadPart);
		deltaTimeValue = diff_frequency / cpuFrequency.QuadPart;
		prevFrequency.QuadPart = currFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		renderFps(hdc, 0, 0);
	}


	void Time::StartTimer(LARGE_INTEGER* timer)
	{
		QueryPerformanceCounter(timer); 
	}

	void Time::EndTimer(LARGE_INTEGER* timer)
	{
		LARGE_INTEGER curr;
		QueryPerformanceCounter(&curr);
		timer->QuadPart = curr.QuadPart - timer->QuadPart;
	}

	void Time::RenderTimer(HDC hdc, LARGE_INTEGER time, const wchar_t* str, int tx, int ty, int max_length)
	{
		wchar_t full_str[50] = L"";
		swprintf_s(full_str, 50, L"%s : %f", str, static_cast<float>(time.QuadPart));
		int len = wcsnlen_s(full_str, 50);
		TextOut(hdc, tx, ty, full_str, len);
		
	}

	void Time::renderFps(HDC hdc, int x, int y)
	{
		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"fps : %f", 1.0f / deltaTimeValue);
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, x, y, str, len);
	}


}