#pragma once


namespace mk::enums
{
	enum class eComponentType 
	{
		Trandform,
		SpriteRenderer,
		Script,
		Camera,
		End,
	};
	enum class eLayerTpye
	{
		None,
		Background,
		Player,
		Max=16
	};

	enum class eResourceType
	{
		Texture,
		Audio,
		
	};
}