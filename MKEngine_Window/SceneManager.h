#pragma once
#include "Commoninclude.h"
#include "mkScene.h"

namespace mk
{
	class SceneManager
	{
	public:
		static void Initialize()
		{
			Scene* initScene = new Scene();
			initScene->AddGameObject();
			mScenes.push_back(initScene);
		}
		static void Update()
		{
			mSelectedScene->Update();
		}
		static void LateUpdate()
		{
			mSelectedScene->LateUpdate();
		}
		static void Render()
		{
			mSelectedScene->Update();
		}

	private:
		static std::vector<Scene* > mScenes;
		static Scene* mSelectedScene;
	};

	std::vector<Scene* > SceneManager::mScenes = {};
	Scene* SceneManager::mSelectedScene = nullptr;
}