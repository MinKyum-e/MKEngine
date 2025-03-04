#include "mkPlayer.h"
#include "mkSpriteRenderer.h"

namespace mk
{

	Player::Player()
	{
	}

	Player::~Player()
	{
		
	}

	void Player::Initialize()
	{
		GameObject::Initialize();
		AddComponent<SpriteRenderer>();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
