#pragma once
#include "USubSystem.h"
#include "CoreMinimal.h"

const sf::Vector2f FORWARD_DIRECTION = { 0.f, -1.f };
const sf::Vector2f RIGHT_DIRECTION = { 1.f, 0.f };

class UInputController :
    public USubSystem
{
public:
    void GetInput();

    virtual void Update() override;

    static UInputController& GetInputController()
    {
        static UInputController InputController;
        return InputController;
    }
};

