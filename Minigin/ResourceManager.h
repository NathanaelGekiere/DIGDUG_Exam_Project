#pragma once
#include <filesystem>
#include <string>
#include <memory>
#include <map>
#include "Singleton.h"

#include "Texture2D.h"
#include "Font.h"

class ResourceManager final : public Singleton<ResourceManager>
{
public:
	void Init(const std::filesystem::path& data);
	Texture2D* LoadTexture(const std::string& file);
	Font* LoadFont(const std::string& file, uint8_t size);
private:
	friend class Singleton<ResourceManager>;
	ResourceManager() = default;
	std::filesystem::path m_dataPath;

	void UnloadUnusedResources();

	std::map<std::string, std::shared_ptr<Texture2D>> m_loadedTextures;
	std::map<std::pair<std::string, uint8_t>, std::shared_ptr<Font>> m_loadedFonts;

};

