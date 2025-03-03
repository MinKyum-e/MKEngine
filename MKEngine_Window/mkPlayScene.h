#pragma once
#include "..\\MKEngine_SOURCE\\mkScene.h"

namespace mk
{
	class PlayScene :public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};

}

