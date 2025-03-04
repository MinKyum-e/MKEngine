#pragma once
#include "mkGameObject.h"
#include "Commoninclude.h"

namespace mk
{
	class Layer
	{
	public:
		Layer();
		~Layer();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject)
		{
			mGameObjects.push_back(gameObject);
		}

	private:
		std::vector<GameObject*> mGameObjects;
	};

}

