#pragma once
#include "mkComponent.h"
#include "Commoninclude.h"

namespace mk
{
	class SpriteRenderer : public Component
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:


	};


}
