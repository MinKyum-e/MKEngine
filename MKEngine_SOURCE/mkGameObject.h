#pragma once
#include "Commoninclude.h"
#include "mkComponent.h"


namespace mk
{
	class GameObject 
	{
	public:
		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hwnd);


		template<typename T>
		T* AddComponent()
		{
			T* component = new T();
			component->SetOwner(this);
			mComponents.push_back(component);
			return component;
		}

		template<typename T>
		T* GetComponent()
		{
			T* component = nullptr;

			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}
			return component;
		}

	private:
		std::vector<Component* > mComponents;
	};
}


