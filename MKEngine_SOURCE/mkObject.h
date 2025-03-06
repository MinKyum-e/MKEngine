#pragma once
#include "Commoninclude.h"
#include "mkGameObject.h"
#include "mkTransform.h"
#include "mkScene.h"
#include "mkSceneManager.h"

namespace mk::object
{
	template<typename T>
	T* Instantiate(enums::eLayerTpye type)
	{
		T* gameObject = new T();
		gameObject->Initialize();
		Scene* activeScene = SceneManager::GetActiveScene();
		activeScene->AddGameObject(gameObject, type);
		return gameObject;
	}


	template<typename T>
	T* Instantiate(enums::eLayerTpye type, Vector2 pos)
	{
		T* gameObject = new T();
		gameObject->Initialize();
		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(pos);
		tr->SetName(L"TR");
		Scene* activeScene = SceneManager::GetActiveScene();
		activeScene->AddGameObject(gameObject, type);
		return gameObject;
	}


}