#pragma once
class GameObject;

class BaseComponent
{
public:
	BaseComponent(GameObject* pOwner);
	virtual ~BaseComponent() = default;

	BaseComponent(const BaseComponent& other) = delete;
	BaseComponent(BaseComponent&& other) = delete;
	BaseComponent& operator=(const BaseComponent& other) = delete;
	BaseComponent& operator=(BaseComponent&& other) = delete;

	void Update();
	void FixedUpdate();
	void Render() const;

private:
	GameObject* m_pOwner;
};

