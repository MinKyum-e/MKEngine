#include "mkPlayScene.h"
#include "mkGameObject.h"
#include "mkPlayer.h"
#include "mkSpriteRenderer.h"
#include "mkTransform.h"

namespace mk
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		{
			Player* player = new Player();
			Transform* tr = player->AddComponent<Transform>();
			tr->SetName(L"TR");
			SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			tr->SetPosition(100, 100);

			AddGameObject(player);

		}

		{
			Player* player = new Player();
			Transform* tr = player->AddComponent<Transform>();
			tr->SetName(L"TR");
			SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			tr->SetPosition(1000, 100);

			AddGameObject(player);

		}

	}

	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}