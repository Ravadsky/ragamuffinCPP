#pragma once

#include "CoreMinimal.h"
#include "USubSystem.h"

const Vector2f FORWARD_DIRECTION = { 0.f, -1.f };
const Vector2f RIGHT_DIRECTION = { 1.f, 0.f };
    
class UInputController : public USubSystem
{
public:
    void GetInput();

    void Update() override;

    static UInputController& GetInputController()
    {
        static UInputController InputController;
        return InputController;
    }

    bool CheckKey(Keyboard::Key Key);
};

