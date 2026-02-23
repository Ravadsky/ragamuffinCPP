#pragma once
#include "USubSystem.h"
#include "CoreMinimal.h"

class URenderSubSystem : public USubSystem
{
    virtual void Update() override;
    URenderSubSystem();

public:

    void DrawEntities(sf::RenderWindow& window);

    static  URenderSubSystem& GetRenderSubSystem()
    {
        static URenderSubSystem RenderSubSystem;
        return RenderSubSystem;
    }
};
