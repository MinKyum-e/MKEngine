#include "mkSpriteRenderer.h"
#include "mkTransform.h"
#include "Commoninclude.h"
#include "mkGameObject.h"
#include<fstream>
#include "mkTime.h"

namespace mk
{
	SpriteRenderer::SpriteRenderer()
		:Component(enums::eComponentType::SpriteRenderer)
		,mTexture(nullptr)
		, mSize(Vector2::One)
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
			//BMP : doesn't have alpha 
			//x origin pos => Location of the desired partial image
			//transparent => remove bg pixel
			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y
				, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage(), Gdiplus::Rect(pos.x * mSize.x, pos.y * mSize.y, mTexture->GetWidth(), mTexture->GetHeight()));
		}
		
		Time::EndTimer(&timer);
		Time::RenderTimer(hdc,timer, L"SpriteRenderTimer : ", 1200, 20, 50);
	}

}