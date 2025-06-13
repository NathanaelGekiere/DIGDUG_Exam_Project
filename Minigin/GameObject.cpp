#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

GameObject::~GameObject() = default;

//void dae::GameObject::AddComponent(std::unique_ptr<BaseComponent> component)
//{
//	if (component != nullptr)
//	{
//		m_ObjectComponents.push_back(std::move(component));
//	}
//}

//bool dae::GameObject::HasComponent(BaseComponent* desiredComponent)
//{
//	for (auto& component: m_ObjectComponents)
//		if (component == desiredComponent )
//}

void GameObject::Update()
{
	for (auto& objectComponent : m_ObjectComponents)
	{
		objectComponent->Render();
	}
}

void GameObject::Render() const
{
	for (auto& objectComponent : m_ObjectComponents)
	{
		objectComponent->Render();
	}
}

void GameObject::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}
