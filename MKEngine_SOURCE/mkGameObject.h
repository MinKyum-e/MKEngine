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
			component->Initialize();
			component->SetOwner(this);

			mComponents[(UINT)component->GetType()] = component;
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
		void InitializeTransform();

	private:
		std::vector<Component* > mComponents;
	};
}


