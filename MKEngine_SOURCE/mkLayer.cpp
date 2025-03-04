#include "mkLayer.h"
#include "mkGameObject.h"


namespace mk
{
	void Layer::Initialize()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			gameObject->Initialize();
		}
	}
	void Layer::Update()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			gameObject->Update();
		}
	}
	void Layer::LateUpdate()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			gameObject->LateUpdate();
		}
	}
	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObject : mGameObjects)
		{
			gameObject->Render(hdc);
		}
	}

	Layer::Layer()
		:mGameObjects({})
	{

	}

	Layer::~Layer()
	{

	}
}