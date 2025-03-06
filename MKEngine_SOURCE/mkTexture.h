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
		HDC mHdc;// �̰͵� ���������� ��Ʈ�ʿ� ����ϴ� HDC�� ���������Ѵ�.

		UINT mWidth;
		UINT mHeight;
		
	};

}

