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
		Time::TIMER timer;
		

		Time::StartTimer(&timer);
		if (mTexture == nullptr) // 텍스쳐 세팅 해주세요!
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
		
		Time::EndTimer(&timer);
		Time::RenderTimer(hdc,timer, L"SpriteRenderTimer : ", 1200, 20, 50);
	}

}