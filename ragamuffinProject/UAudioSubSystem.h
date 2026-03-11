#pragma once
#include "USubSystem.h"
#include "SoundSample.h"

class UAudioSubSystem : public USubSystem
{
private:
	Music BackgroundMusic;
    std::vector < std::unique_ptr<SoundSample> > AllSamples;

public:
    UAudioSubSystem();

    void StartNewMusic(std::string FileName, float Volume);
    void Update() override;
    static inline UAudioSubSystem& GetUAudioSubSystem()
    {
        static UAudioSubSystem AudioSubSystem;
        return AudioSubSystem;
    }

    void CreateNewSound(std::string SoundName);
};

