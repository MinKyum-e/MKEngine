#include "mkEndScene.h"
#include "mkInput.h"
#include "mkSceneManager.h"
#include "mkPlayer.h"
#include "mkObject.h"
#include "mkResources.h"
#include "mkSpriteRenderer.h"

namespace mk
{
	EndScene::EndScene()
	{
	}

	EndScene::~EndScene()
	{
	}

	void EndScene::Initialize()
	{
		//���ӿ�����Ʈ ����� ���� ���ҽ����� ��� Load�ص���
		{
			Player* bg = object::Instantiate<Player>(enums::eLayerTpye::Background);
			SpriteRenderer* sr = bg->GetComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->SetTexture(Resources::Find<graphics::Texture>(L"TitleBackGround"));
		}
	}

	void EndScene::Update()
	{
		Scene::Update();
	}

	void EndScene::LateUpdate()
	{
		Scene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	void EndScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		const wchar_t str[10] = L"End Scene";
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}

}
