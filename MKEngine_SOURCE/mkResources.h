#pragma once
#include "mkResource.h"
#include "Commoninclude.h"
namespace mk
{
	/*
		���� ���ҽ��� �����ϱ� ����.
		�ϳ��� �ؽ��ĸ� �ҷ����� �װ� �׳� �����ؼ� �����.
	
	*/
	class Resources 
	{
	public:
		template<typename T>
		static T* Find(const std::wstring& key)
		{
			auto iter=mResources.find(key); //�ʿ��� ã������ �������� ���� auto�� ���� ����Ѵ�.
			if (iter == mResources.end())
			{
				return nullptr;
			}

			return dynamic_cast<T*>(iter->second); //�ڽ����� ����ȯ�ؾ��ϹǷ� ���̳��� ĳ��Ʈ�� ����Ѵ�.
		}

		template<typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			T* resource = Resources::Find<T>(key);
			if (resource != nullptr) //������ �׳ɹ�ȯ
				return resource;


			resource = new T();
			if (FAILED(resource->Load(path)))
				assert(false); // ���α׷� ����������
		
			resource->SetName(key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(key, resource));

			return resource;
		}

	private:
		static std::map<std::wstring, Resource*> mResources;//�ҷ����� ���� ������ ������ �������ش�.

	};


}
