#include "mkPlayScene.h"
#include "mkGameObject.h"
#include "mkPlayer.h"
#include "mkSpriteRenderer.h"
#include "mkTransform.h"
#include "mkInput.h"
#include "mkSceneManager.h"

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


	}

	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"EndScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		const wchar_t str[12] = L"Play Scene";
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}
}