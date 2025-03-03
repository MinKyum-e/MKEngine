#pragma once
#include "mkPlayScene.h"
#include "..\\MKEngine_SOURCE\\mkSceneManager.h"

namespace mk
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");


		SceneManager::LoadScene(L"PlayScene");
	}
}

