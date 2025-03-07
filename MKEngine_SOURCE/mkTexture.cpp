#include "mkTexture.h"
#include "mkApplication.h"


extern mk::Application application; // 해당 전역변수가 외부에 존재함을 알려준다.(extern 키워드)

namespace mk::graphics
{
	Texture::Texture()
		:Resource(enums::eResourceType::Texture)
		, mType(eTextureType::None)
		, mImage(nullptr)
		, mBitmap(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)

	{
	}

	Texture::~Texture()
	{
	}
	HRESULT Texture::Load(const std::wstring& path)
	{
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);
		//bmp일때

		if (ext == L"bmp")
		{
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP) LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP,
				0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);//클래스의 주소에서 실제 이름만 가져오기
			
			if (mBitmap == nullptr)
				return S_FALSE;

			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info);
			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			HDC mainDC = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDC);
			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
			DeleteObject(oldBitmap);
		}
		//png일때
		else if (ext == L"png")
		{
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str());

			if (mImage->GetLastStatus() != Gdiplus::Ok)
				return S_FALSE;
			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();
			
		}



		return S_OK;
	}
}


