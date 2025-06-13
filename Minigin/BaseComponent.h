#pragma once
class GameObject;

class BaseComponent
{
public:
	BaseComponent() = default;
	BaseComponent(GameObject* pOwner) :m_pOwner{ pOwner } {};
	virtual ~BaseComponent() = default;

	BaseComponent(const BaseComponent&) = delete;
	BaseComponent(BaseComponent&&) = delete;
	BaseComponent& operator=(const BaseComponent&) = delete;
	BaseComponent& operator=(BaseComponent&&) = delete;

	virtual void Update();
	virtual void FixedUpdate();
	virtual void Render() const;

	GameObject* GetCompOwner() const {
		return m_pOwner;
	}

private:
	GameObject* m_pOwner = nullptr;
};

