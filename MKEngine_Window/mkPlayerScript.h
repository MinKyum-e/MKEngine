#pragma once
#include "..\\MKEngine_SOURCE\\mkScript.h"

namespace mk
{
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};
}


