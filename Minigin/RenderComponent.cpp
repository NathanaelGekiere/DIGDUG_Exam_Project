#include "RenderComponent.h"
#include "Renderer.h"
#include "ResourceManager.h"



RenderComponent::RenderComponent(GameObject* pOwner)
	:BaseComponent{ pOwner }
	,m_Texture{}
{
}

void RenderComponent::AddTexture(const std::string& filePath)
{
	m_Texture = ResourceManager::GetInstance().LoadTexture(filePath);
}

void RenderComponent::Render() const
{
	const auto& pos = GetCompOwner()->GetTransformComponent().GetPosition();
	Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
}

