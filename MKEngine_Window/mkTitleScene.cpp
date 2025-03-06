#include "mkTitleScene.h"
#include "mkPlayer.h"
#include "mkTransform.h"
#include "mkSpriteRenderer.h"
#include "mkInput.h"
#include "mkSceneManager.h"
#include "mkLayer.h"
#include "mkResources.h"
#include "mkTexture.h"
#include "mkObject.h"
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
		//게임오브젝트 만들기 전에 리소스들을 모두 Load해두자
		{
			Player* bg = object::Instantiate<Player>(enums::eLayerTpye::Background);
			SpriteRenderer* sr = bg->GetComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->SetTexture(Resources::Find<graphics::Texture>(L"TitleBackGround"));
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