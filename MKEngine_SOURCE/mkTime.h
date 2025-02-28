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

	private:

		static LARGE_INTEGER cpuFrequency;
		static LARGE_INTEGER prevFrequency;
		static LARGE_INTEGER currFrequency;
		static float deltaTimeValue;

	};


}
