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
		deltaTimeValue = diff_frequency / static_cast<float>(cpuFrequency.QuadPart);
		prevFrequency.QuadPart = currFrequency.QuadPart;
		//std::cout << deltaTimeValue << std::endl;
	}

	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += deltaTimeValue;

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %f", time);
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);

	}


}