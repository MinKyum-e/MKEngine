#include "mkPlayer.h"
#include "mkSpriteRenderer.h"
#include "mkInput.h"
#include "mkTransform.h"
namespace mk
{

	Player::Player()
	{
		AddComponent<SpriteRenderer>();
	}

	Player::~Player()
	{
		
	}

	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{

		if (Input::GetKeyPressed(eKeyCode::D))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
				tr->SetPosition(Vector2(pos.x + 0.2f, pos.y));
		}
		GameObject::LateUpdate();
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
