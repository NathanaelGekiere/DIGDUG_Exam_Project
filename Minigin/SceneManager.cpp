#include "SceneManager.h"
#include "Scene.h"

void SceneManager::Update()
{
	for (auto& scene : m_scenes)
	{
		scene->Update();
	}
}

void SceneManager::FixedUpdate()
{
	for (auto& scene : m_scenes)
	{
		scene->Update();// fixed_Time_Step);
	}
}

void SceneManager::Render()
{
	for (const auto& scene : m_scenes)
	{
		scene->Render();
	}
}

Scene& SceneManager::CreateScene(const std::string& name)
{
	const auto& scene = std::shared_ptr<Scene>(new Scene(name));
	m_scenes.push_back(scene);
	return *scene;
}
