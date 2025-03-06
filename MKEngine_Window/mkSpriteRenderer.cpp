#include "mkSpriteRenderer.h"
#include "mkTransform.h"
#include "Commoninclude.h"
#include "mkGameObject.h"
#include<fstream>


namespace mk
{
	SpriteRenderer::SpriteRenderer()
		:mTexture(nullptr)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
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
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(mTexture->GetImage(), Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth(), mTexture->GetHeight()));
	}

}