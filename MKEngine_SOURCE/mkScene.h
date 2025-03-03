#pragma once
#include "Commoninclude.h"
#include "mkGameObject.h"
#include "mkEntity.h"

namespace mk
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		void AddGameObject(GameObject* gameObject);

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
	private:
		std::vector<GameObject*> mGameObjects;
	};


}
