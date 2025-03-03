#pragma once
#include"Commoninclude.h"

namespace mk
{
	class Entity
	{
	public:
		Entity()
			;
		virtual ~Entity();

		std::wstring& GetName() { return mName; }
		void	SetName(const std::wstring& name) { mName = name; }

	private:
		std::wstring mName;

	};


}
