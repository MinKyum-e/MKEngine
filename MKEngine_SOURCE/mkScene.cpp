#include "mkScene.h"

namespace mk
{
	Scene::Scene()
		:mGameObjects({})
	{

	}
	Scene::~Scene()
	{

	}

	void Scene::AddGameObject(GameObject* gameObject)
	{
		if(gameObject)
			mGameObjects.push_back(gameObject);
	}


	void Scene::Initialize()
	{
		
	}
	void Scene::Update()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Render(hdc);
		}
	}
}