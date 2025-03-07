#include "mkPlayerScript.h"
#include "..\\MKEngine_SOURCE\\mkInput.h"
#include "..\\MKEngine_SOURCE\\Commoninclude.h"
#include "..\\MKEngine_SOURCE\\mkTransform.h"
#include "..\\MKEngine_SOURCE\\mkGameObject.h"

namespace mk
{
	PlayerScript::PlayerScript()
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::Update()
	{
		if (Input::GetKeyPressed(eKeyCode::RIGHT))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			tr->SetPosition(Vector2(pos.x + 0.2f, pos.y));
		}

		if (Input::GetKeyPressed(eKeyCode::LEFT))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			tr->SetPosition(Vector2(pos.x - 0.2f, pos.y));
		}
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
}