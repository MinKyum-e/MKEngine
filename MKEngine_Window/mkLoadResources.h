#pragma once
#include "..\\MKEngine_SOURCE\\mkResources.h"
#include "..\\MKEngine_SOURCE\\mkTexture.h"

namespace mk
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"TitleBackGround", L"C:\\study\\MKEngine\\Resources\\background.png");
	}
}