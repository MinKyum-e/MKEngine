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
		//std::cout << deltaTimeValue << std::endl;
	}

	void Time::Render(HDC hdc)
	{


		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"fps : %f",1.0f/ deltaTimeValue);
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);

	}

	void Time::ShowTimer(HDC hdc, LARGE_INTEGER start, LARGE_INTEGER end, const wchar_t* timer_name, int tx, int ty, int max_length)
	{
		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"%s : %f", timer_name, static_cast<float>(end.QuadPart - start.QuadPart));
		int len = wcsnlen_s(str, 50);
		TextOut(hdc, tx, ty, str, len);
		
	}


}