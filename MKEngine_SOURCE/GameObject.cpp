#include "GameObject.h"

namespace mk
{
	GameObject::GameObject()
		:mX(0.0f)
		, mY(0.0f)
		, team(0)
	{
	}

	GameObject::GameObject(int team)
		:mX(500.0f)
		, mY(500.0f)
		, team(team)
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		if (team == 0)
		{
			if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			{
				mX -= 0.01f;
			}

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			{
				mX += 0.01f;
			}

			if (GetAsyncKeyState(VK_UP) & 0x8000)
			{
				mY -= 0.01f;
			}

			if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			{
				mY += 0.01f;
			}
		}
		else
		{
			if (GetAsyncKeyState('A') & 0x8000)
			{
				mX -= 0.01f;
			}

			if (GetAsyncKeyState('D') & 0x8000)
			{
				mX += 0.01f;
			}

			if (GetAsyncKeyState('W') & 0x8000)
			{
				mY -= 0.01f;
			}

			if (GetAsyncKeyState('S') & 0x8000)
			{
				mY += 0.01f;
			}
		}
	
	}



	void GameObject::LateUpdate()
	{

	}


	void GameObject::Render(HDC hdc)
	{
		
		if (team == 0)
		{

			HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
			HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);
			Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
			SelectObject(hdc, oldBrush);
			DeleteObject(blueBrush);
		}
		else
		{
			HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
			HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, redBrush);
			Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
			SelectObject(hdc, oldBrush);
			DeleteObject(redBrush);
		}

		
		
	}

	
}

