#include "mkPlayScene.h"
#include "mkGameObject.h"
#include "mkPlayer.h"
#include "mkSpriteRenderer.h"
#include "mkTransform.h"
#include "mkInput.h"
#include "mkSceneManager.h"
#include "mkObject.h"
#include "math.h"
#include "mkSpriteRenderer.h"
#include "mkTexture.h"
#include "mkResources.h"

namespace mk
{
	PlayScene::PlayScene()
		:Scene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		
		float x = 800, y= 450;
		float num = 10;
		float pi = 3.141592;
		float r = 400;
		for (int i = 0; i < num; i++)
		{
			Vector2 pos = Vector2(x + r * cos(pi*2 / num * i), y + r * sin(pi*2 / num * i));
			Player* pl = object::Instantiate<Player>(enums::eLayerTpye::Player, pos);
			SpriteRenderer* sr = pl->GetComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->SetTexture(Resources::Find<graphics::Texture>(L"TitleBackGround"));
			int a = 1;
		}
		Scene::Initialize();


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