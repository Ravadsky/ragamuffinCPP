#pragma once
#include "USubSystem.h"
#include "CoreMinimal.h"

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

