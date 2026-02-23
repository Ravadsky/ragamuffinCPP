#pragma once
#include "USubSystem.h"
class UWorldSubSystem : public USubSystem
{
    char Room[5][5]{
        { '2', '2', '1', '2', '2' },
        { '2', '1', '1', '1', '1' },
        { '1', '1', '1', '1', '1' },
        { '2', '1', '1', '3', '2' },
        { '2', '2', '1', '2', '2' }
    };

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

