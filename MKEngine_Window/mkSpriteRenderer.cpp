#include "mkSpriteRenderer.h"
#include "mkTransform.h"
#include "Commoninclude.h"
#include "mkGameObject.h"



namespace mk
{
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		float x = tr->GetX(), y = tr->GetY();

		Rectangle(hdc, x, y , x + 100 , y + 100 );
		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
	}
}