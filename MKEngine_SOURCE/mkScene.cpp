#include "mkScene.h"
#include "mkTransform.h"

namespace mk
{
	Scene::Scene()
		:mLayers({})
	{
		createLayers();
	}
	Scene::~Scene()
	{

	}

	void Scene::AddGameObject(GameObject* gameObject, eLayertpye layerType)
	{
		mLayers[UINT(layerType)]->AddGameObject(gameObject);
	}


	void Scene::Initialize()
	{
		for (Layer* layer : mLayers)
		{
			layer->Initialize();
		}
	}
	void Scene::Update()
	{
		for (Layer* layer : mLayers)
		{
			layer->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (Layer* layer : mLayers)
		{
			layer->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : mLayers)
		{
			layer->Render(hdc);
		}
	}


	void Scene::createLayers()
	{
		mLayers.resize((UINT)eLayertpye::Max);
		for (size_t i = 0; i < (UINT)eLayertpye::Max; i++)
		{
			mLayers[i] = new Layer();
		}
	}

	void Scene::OnEnter()
	{

	}
	void Scene::OnExit()
	{
		
	}
}