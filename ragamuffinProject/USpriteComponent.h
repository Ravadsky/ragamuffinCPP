#pragma once
#include "UActorComponent.h"

class USpriteComponent : public UActorComponent
{
public:
	sf::Sprite ComponentSprite;
	void Update() override;
	USpriteComponent(AActor* Owner, sf::Texture* tex);
	USpriteComponent();
};

