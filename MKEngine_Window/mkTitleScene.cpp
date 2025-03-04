#include "mkTitleScene.h"
#include "mkPlayer.h"
#include "mkTransform.h"
#include "mkSpriteRenderer.h"
#include "mkInput.h"
#include "mkSceneManager.h"
#include "mkLayer.h"

namespace mk
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		{
			Player* bg = new Player();
			Transform* tr = bg->AddComponent<Transform>();
			tr->SetName(L"TR");

			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"Sr");

			sr->ImageLoad(L"C:\\study\\MKEngine\\Resources\\background.png");

			AddGameObject(bg, enums::eLayertpye::Background);
		}
	}
	void TitleScene::Update()
	{
		Scene::Update();
	}
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}

	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		const wchar_t str[12] = L"Title Scene";
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}
	void TitleScene::OnEnter()
	{
		Scene::OnEnter();
	}
	void TitleScene::OnExit()
	{
		Scene::OnExit();
		//for (Layer* gameObj : Scene::mLayers)
		//{
		//	Transform* tr = gameObj->GetComponent<Transform>();
		//	tr->SetPosition(Vector2(0.0f, 0.0f));

		//}
	}
}