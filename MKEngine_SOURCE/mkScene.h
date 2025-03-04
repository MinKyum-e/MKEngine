#pragma once
#include "Commoninclude.h"
#include "mkEntity.h"
#include "mkLayer.h"

namespace mk
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		void AddGameObject(GameObject* gameObject, eLayertpye layerType);

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);


		virtual void OnEnter();
		virtual void OnExit();

	private:
		void createLayers();

	private:
		std::vector<Layer* > mLayers;
	};


}
