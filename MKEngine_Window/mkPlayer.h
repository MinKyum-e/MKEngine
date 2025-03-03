#pragma once
#include "..\\MKEngine_SOURCE\\mkGameObject.h"
namespace mk
{
	class Player : public GameObject
	{
	public:
		Player();
		~Player();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;


	};


}
