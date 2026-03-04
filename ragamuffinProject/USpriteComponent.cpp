#include "USpriteComponent.h"

void USpriteComponent::Update()
{
}

USpriteComponent::USpriteComponent(AActor* Owner, sf::Texture* tex) : UActorComponent(Owner)
{
	ComponentSprite.setOrigin({ SPRITE_RAW_SIZE / 2, SPRITE_RAW_SIZE / 2 });
	ComponentSprite.setScale(OBJECT_SIZE);
	ComponentSprite.setTexture(*tex);
}

USpriteComponent::USpriteComponent()
{
}
