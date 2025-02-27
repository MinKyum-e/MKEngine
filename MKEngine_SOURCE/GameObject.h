#pragma once
#include "Commoninclude.h"

namespace mk
{
	class GameObject
	{
	public:
		GameObject();
		GameObject(int team);
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hwnd);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}
		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }

	private:
		float mX;
		float mY;
		int team;

	};
}


