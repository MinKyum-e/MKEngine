#include "mkGameObject.h"
#include "mkInput.h"
#include "mkTime.h"
#include "mkTransform.h"

namespace mk
{
	GameObject::GameObject()
		:mComponents({})
	{
		InitializeTransform();
	}


	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			delete comp;
		}
	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			comp->Update();
		}
	
	}



	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			comp->LateUpdate();
		}
	}


	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			comp->Render(hdc);
		}
		
	}

	void GameObject::InitializeTransform()
	{
		AddComponent < Transform>();
	}
}

