#pragma once
#include "Commoninclude.h"
#include "mkEntity.h"

namespace mk
{
	class Resource : public Entity
	{
	public:
		Resource(enums::eResourceType resourceType);
		
		~Resource();

		virtual HRESULT Load(const std::wstring & path) = 0; //0 or1 (bool 대신에 사용함)


		std::wstring& GetPath() { return mPath; }
		void SetPath(std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mResourceType;
		std::wstring mPath;
	};

}

