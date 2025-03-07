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
		GameObject::LateUpdate();
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
