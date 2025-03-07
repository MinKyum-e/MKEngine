#include "mkTransform.h"


namespace mk
{
	Transform::Transform()
		:Component(enums::eComponentType::Trandform)
		,mPosition(math::Vector2(0.0f, 0.0f))
	{

	}
	Transform::~Transform()
	{
	}
	void Transform::Initialize()
	{
	}

	void Transform::Update()
	{
	}

	void Transform::LateUpdate()
	{
	}

	void Transform::Render(HDC hdc)
	{
	}

}
