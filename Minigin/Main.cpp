#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextObject.h"
#include "Scene.h"

#include "RenderComponent.h"

#include <filesystem>
namespace fs = std::filesystem;

void load()
{
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	auto go = std::make_unique<GameObject>();
	go->AddObjectComponent<RenderComponent>();
	go->GetObjectComponent<RenderComponent>()->AddTexture("background.tga");
	scene.Add(std::move(go));
	//
	//go = std::make_shared<dae::GameObject>();
	//go->AddComponent(std::make_unique<dae::RenderComponent>("logo.tga", *go));
	//go->SetPosition(216, 180);
	//scene.Add(std::move(go));

	//auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	//auto to = std::make_shared<dae::TextObject>("Programming 4 Assignment", font);
	//to->SetPosition(80, 20);
	//scene.Add(to);
}

int main(int, char* []) {
	fs::path data_location = "./Data/";
	if (!fs::exists(data_location))
		data_location = "../Data/";
	Minigin engine(data_location);
	engine.Run(load);
	return 0;
}