#pragma once
#include "mkResource.h"
#include "Commoninclude.h"
namespace mk
{
	/*
		여러 리소스를 관리하기 위함.
		하나의 텍스쳐를 불러오고 그걸 그냥 참조해서 사용함.
	
	*/
	class Resources 
	{
	public:
		template<typename T>
		static T* Find(const std::wstring& key)
		{
			auto iter=mResources.find(key); //맵에서 찾을때는 가독성을 위해 auto를 많이 사용한다.
			if (iter == mResources.end())
			{
				return nullptr;
			}

			return dynamic_cast<T*>(iter->second); //자식으로 형변환해야하므로 다이나믹 캐스트를 사용한다.
		}

		template<typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			T* resource = Resources::Find<T>(key);
			if (resource != nullptr) //존재함 그냥반환
				return resource;


			resource = new T();
			if (FAILED(resource->Load(path)))
				assert(false); // 프로그램 강제종료임
		
			resource->SetName(key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(key, resource));

			return resource;
		}

	private:
		static std::map<std::wstring, Resource*> mResources;//불러오기 쉽게 데이터 영역에 젖아해준다.

	};


}
