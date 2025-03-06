#pragma once
#include "mkResource.h"

namespace mk::graphics
{
	class Texture : public Resource
	{
	public:
		enum class eTextureType
		{
			Bmp,
			Png,
			None,
		};


		Texture();
		~Texture();


		HRESULT Load(const std::wstring& path) override;

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		HDC GetHdc() { return mHdc; }
		eTextureType GetTextureType() { return mType; }
		Gdiplus::Image* GetImage() { return mImage; }


	private:
		eTextureType mType;
		Gdiplus::Image* mImage;
		HBITMAP mBitmap;
		HDC mHdc;// 이것도 마찬가지로 비트맵에 사용하는 HDC를 만들어줘야한다.

		UINT mWidth;
		UINT mHeight;
		
	};

}

