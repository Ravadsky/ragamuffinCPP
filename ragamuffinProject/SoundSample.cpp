#include "SoundSample.h"
#include "UAudioSubSystem.h"

SoundSample::SoundSample(std::string SoundName, float Volume)
{
	soundbuffer.loadFromFile(RESOURCES_PATH + SoundName + ".wav");
	sound.setBuffer(soundbuffer);
	sound.setVolume(Volume);
	sound.play();
}

bool SoundSample::isContinues()
{
	return sound.getStatus() == sf::SoundSource::Playing;
}
