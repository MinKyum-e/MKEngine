#pragma once
#include "mkComponent.h"
namespace mk
{
	class Transform : public Component
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}
		float GetX() { return mX; }
		float GetY() { return mY; }

	private:
		float mX;
		float mY;
	};

}
