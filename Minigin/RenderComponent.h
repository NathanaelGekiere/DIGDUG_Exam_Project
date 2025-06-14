#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
#include <memory>
#include <string>



class Texture2D;

class RenderComponent final : public BaseComponent
{
public:
	RenderComponent(GameObject* pOwner);
	~RenderComponent() override;

	void AddTexture(const std::string& filePath);

	void Render() const override;
private:
	Texture2D* m_Texture;
};
