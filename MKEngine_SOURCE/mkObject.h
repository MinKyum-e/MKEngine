#pragma once
#include "Commoninclude.h"
#include "mkGameObject.h"
#include "mkTransform.h"
#include "mkScene.h"
#include "mkSceneManager.h"

namespace mk::object
{
	template<typename T>
	T* Instantiate(enums::eLayertpye type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		activeScene->AddGameObject(gameObject, type);
		return gameObject;
	}


	template<typename T>
	T* Instantiate(enums::eLayertpye type, Vector2 pos)
	{
		T* gameObject = new T();
		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(pos);
		Scene* activeScene = SceneManager::GetActiveScene();
		activeScene->AddGameObject(gameObject, type);
		return gameObject;
	}


}