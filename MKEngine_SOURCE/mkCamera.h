#pragma once
#include "mkComponent.h"
#include "mkGameObject.h"
namespace mk
{
	using namespace mk::math;
	class Camera : public Component
	{
	public:
		Vector2 CaluatePosition(Vector2 pos) { return pos - mDistance; };

		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;



	private:
		//std::vector<GameObject*> mGameObjects;

		GameObject* mTarget;
		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;

	};

}

