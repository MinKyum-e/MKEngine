#pragma once
#include "Commoninclude.h"
#include "mkEntity.h"
namespace mk
{
	class GameObject : public Entity
	{
	public:
		GameObject();
		GameObject(wchar_t name);
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

	};
}


