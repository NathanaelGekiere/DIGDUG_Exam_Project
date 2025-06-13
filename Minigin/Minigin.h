#pragma once
#include <string>
#include <functional>
#include <filesystem>


class Minigin
{
public:
	explicit Minigin(const std::filesystem::path& dataPath);
	~Minigin();
	void Run(const std::function<void()>& load);

	Minigin(const Minigin& other) = delete;
	Minigin(Minigin&& other) = delete;
	Minigin& operator=(const Minigin& other) = delete;
	Minigin& operator=(Minigin&& other) = delete;
private:
	int m_MsPerFrame;
	float m_Fixed_Time_Step;
};
