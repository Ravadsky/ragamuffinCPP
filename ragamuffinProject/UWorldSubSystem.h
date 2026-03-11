#pragma once
#include "USubSystem.h"
class UWorldSubSystem : public USubSystem
{
public:
    sf::Clock GameClock;
    sf::Time DeltaTimer;
    float DeltaTime;

    UWorldSubSystem();

    virtual void Update() override;
    void UpdateTime();
    void UpdateEntities();

    static UWorldSubSystem& GetWorldSubSystem()
    {
        static UWorldSubSystem WorldSubSystem;
        return WorldSubSystem;
    }
};

