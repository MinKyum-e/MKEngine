#include "mkSpriteRenderer.h"
#include "mkTransform.h"
#include "Commoninclude.h"
#include "mkGameObject.h"
#include<fstream>


namespace mk
{
	SpriteRenderer::SpriteRenderer()
		:mImage(nullptr)
		, mWidth(0)
		, mHeight(0)
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
		graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
	}
	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		std::wifstream file(path);
		if (!file)
		{
			// 파일이 존재하지 않거나 경로가 틀림
			std::cout << "file does not exists";
			
		}
		mImage = Gdiplus::Image::FromFile(path.c_str());
		Gdiplus::Status status = mImage->GetLastStatus();
		if (status != Gdiplus::Ok)
		{
			// status 값을 출력해서 구체적인 에러 원인 확인
			std::wcout << L"Gdiplus::Image::FromFile failed with status: " << status << std::endl;
		}
		mWidth = mImage->GetWidth();
		mHeight = mImage->GetHeight();
	}
}