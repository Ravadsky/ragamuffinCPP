#include "UAudioSubSystem.h"

UAudioSubSystem::UAudioSubSystem()
{
	StartNewMusic("Music", 10.f);
}

void UAudioSubSystem::StartNewMusic(std::string FileName, float Volume)
{
	BackgroundMusic.openFromFile(RESOURCES_PATH + FileName + ".wav");
	BackgroundMusic.setLoop(true);
	BackgroundMusic.setVolume(Volume);
	BackgroundMusic.play();
}

void UAudioSubSystem::Update()
{

	AllSamples.erase(
		std::remove_if(AllSamples.begin(), AllSamples.end(),
			[](const auto& sample) {return !sample->isContinues(); }), AllSamples.end());
}

void UAudioSubSystem::CreateNewSound(std::string SoundName)
{
	AllSamples.emplace_back(std::make_unique<SoundSample>(SoundName));
}
