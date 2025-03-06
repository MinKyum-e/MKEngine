#pragma once
#include "mkComponent.h"
#include "Commoninclude.h"
#include "mkTexture.h"

namespace mk
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(graphics::Texture* texture)
		{
			mTexture = texture;
		}

	private:
		graphics::Texture* mTexture;


	};


}
