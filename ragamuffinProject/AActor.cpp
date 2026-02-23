#include "AActor.h"
#include "AssetManager.h"
#include "UInputController.h"
#include "APlayer.h"

AActor::AActor() : AActor(2001) {};

AActor::AActor(int id)
{
	ActorData* DataPtr = AssetManager::GetAssetManager()->GetActorData(id);

	ID = id;
	ObjSprite.setTexture(*DataPtr->DTexture);
	Type = DataPtr->DObjectType;
	CollisionPreset = DataPtr->DCollisionType;

	AActors.push_back(this);

	ObjSize = { SPRITE_GAME_SIZE, SPRITE_GAME_SIZE };
	ObjSprite.setScale(ObjSize);
	ObjSprite.setOrigin({ 4.f, 4.f });
	ObjLocation = { 0, 0 };
}

void AActor::Draw(sf::RenderWindow& window)
{
	sf::Vector2f TempVector = this->ObjLocation - APlayer::GetPlayer().ObjLocation;
	sf::Vector2f CameraPivot = { WINDOW_WIGHT / 2, WINDOW_HEIGHT / 2 };
	ObjSprite.setPosition(TempVector + CameraPivot);
	window.draw(ObjSprite);
}



void AActor::Update()
{

}

void AActor::SetLocation(sf::Vector2f NewLocation)
{
	this->ObjLocation = NewLocation;
}

void AActor::AddLocation(sf::Vector2f Location)
{
	this->ObjLocation += Location;
}

sf::Vector2f AActor::GetLocation() const
{
	return ObjLocation;
}

