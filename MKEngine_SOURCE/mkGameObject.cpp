#include "mkGameObject.h"
#include "mkInput.h"
#include "mkTime.h"

namespace mk
{
	GameObject::GameObject()
		:mX(0.0f)
		, mY(0.0f)
	{
	}

	GameObject::GameObject(wchar_t name)
		:mX(0.0f)
		, mY(0.0f) 
	{
	}


	GameObject::~GameObject()
	{
	}



	void GameObject::Update()
	{
		const int speed = 100.0f;
		if ( Input::GetKeyPressed(eKeyCode::A) || Input::GetKeyPressed(eKeyCode::LEFT))
		{
			mX -= speed * Time::DeltaTime();
		}

		if (Input::GetKeyPressed(eKeyCode::D) || Input::GetKeyPressed(eKeyCode::RIGHT))
		{
			mX += speed * Time::DeltaTime();
		}

		if (Input::GetKeyPressed(eKeyCode::W) || Input::GetKeyPressed(eKeyCode::UP))
		{
			mY -= speed * Time::DeltaTime();
		}

		if (Input::GetKeyPressed(eKeyCode::S) || Input::GetKeyPressed(eKeyCode::DOWN))
		{
			mY += speed * Time::DeltaTime();
		}
	
	}



	void GameObject::LateUpdate()
	{

	}


	void GameObject::Render(HDC hdc)
	{
		
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);
		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		
		
		
	}

	
}

