#pragma once
#include "..\\MKEngine_SOURCE\\mkScene.h"

namespace mk
{
	class EndScene :public Scene
	{
	public:
		EndScene();
		~EndScene();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};

}

