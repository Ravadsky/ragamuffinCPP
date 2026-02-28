#pragma once
#include "USubSystem.h"
class UWorldSubSystem : public USubSystem
{


    UWorldSubSystem();

    virtual void Update() override;

public:
    sf::Clock GameClock;
    sf::Time DeltaTimer;
    float DeltaTime;

    void UpdateTime();

    void UpdateEntities();
    static UWorldSubSystem& GetWorldSubSystem()
    {
        static UWorldSubSystem WorldSubSystem;
        return WorldSubSystem;
    }
};

