#pragma once
#include "mkPlayScene.h"
#include "mkEndScene.h"
#include "mkTitleScene.h"
#include "..\\MKEngine_SOURCE\\mkSceneManager.h"

namespace mk
{


	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<EndScene>(L"EndScene");
		SceneManager::LoadScene(L"TitleScene");
	}
}

