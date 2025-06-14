#pragma once
#include <memory>
#include "Transform.h"
#include "BaseComponent.h"

#include <iostream>
#include <vector>


	//class Texture2D;
	class BaseComponent;

	// todo: this should become final.
	class GameObject final
	{
	public:
		void Update();
		//void FixedUpdate();
		void Render() const;

		void SetPosition(float x, float y);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		Transform GetTransformComponent() { return m_Transform; };

		template<typename ObjectComp>
		void AddObjectComponent()
		{
			static_assert(std::is_base_of<BaseComponent, ObjectComp>::value, "Argument is not derived from BaseComponent");
			std::unique_ptr<ObjectComp> ObjectComponent = std::make_unique<ObjectComp>(this);
			m_ObjectComponents.push_back(std::move(ObjectComponent));
		}

		template<typename ObjectComp>
		ObjectComp* GetObjectComponent()
		{
			static_assert(std::is_base_of<BaseComponent, ObjectComp>::value, "Argument is not derived from BaseComponent");

			for (const auto& objectComponent : m_ObjectComponents)
			{
				;
				if (ObjectComp* AskedComp = dynamic_cast<ObjectComp*>(objectComponent.get()))
				{
					return AskedComp;
				}

			}
			return nullptr;
		}

	private:
		Transform m_Transform{};
		std::vector<std::unique_ptr<BaseComponent>> m_ObjectComponents;
	};
