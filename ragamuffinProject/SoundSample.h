#pragma once
#include "CoreMinimal.h"

class SoundSample
{
private:
	Sound sound;
	SoundBuffer soundbuffer;

public:
	SoundSample(std::string SoundName, float Volume = 10.f);
	bool isContinues();
};

