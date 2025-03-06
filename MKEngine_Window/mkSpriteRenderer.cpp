#include "mkSpriteRenderer.h"
#include "mkTransform.h"
#include "Commoninclude.h"
#include "mkGameObject.h"
#include<fstream>
#include "mkTime.h"

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
		LARGE_INTEGER start = LARGE_INTEGER();
		LARGE_INTEGER end = LARGE_INTEGER();
		

		Time::StartTimer(&start);
		if (mTexture == nullptr) // �ؽ��� ���� ���ּ���!
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();


		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			
		}
		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage(), Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth(), mTexture->GetHeight()));
		}
		
		Time::EndTimer(&end);
		Time::ShowTimer(hdc, start, end, L"SpriteRenderTimer : ", 1000, 200, 50);
	}

}