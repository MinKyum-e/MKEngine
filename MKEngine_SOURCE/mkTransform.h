#pragma once
#include "mkComponent.h"
namespace mk
{
	using namespace math;
	class Transform : public Component
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPosition(Vector2 pos)
		{
			mPosition.x = pos.x;
			mPosition.y = pos.y;
		}
		Vector2 GetPosition() { return mPosition; }

	private:
		Vector2 mPosition;
	};

}
