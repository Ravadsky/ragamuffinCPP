#include "AActor.h"
#include "AssetManager.h"
#include "UInputController.h"
#include "APlayer.h"

AActor::AActor() : AActor(0000) {};
AActor::AActor(int id) : ID(id)
{
	AActors.push_back(this);

	ActorData* Data = AssetManager::GetAssetManager()->GetActorData(id);
	SpriteComponent = std::make_shared<USpriteComponent>(this, Data->DTexture);
	//Type принимает тип объекта - статический/динамический/виджет, обращаясь к полю объекта DObjectType
	Type = Data->DObjectType;
	//CollisionPreset принимает значение типа коллизии объекта
	CollisionPreset = Data->DCollisionType;
	// Записываем актора в вектор
}

//отрисовка камеры
void AActor::Draw(sf::RenderWindow& window)
{
	//нахождение смещения относительно игрока?
	Vector2f Offset = this->ObjLocation - APlayer::GetPlayer().ObjLocation + CAMERA_PIVOT;
	if (Offset.x + SPRITE_GAME_SIZE < 0 || Offset.x - SPRITE_GAME_SIZE > WINDOW_WIGHT ||
		Offset.y + SPRITE_GAME_SIZE < 0 || Offset.y - SPRITE_GAME_SIZE > WINDOW_HEIGHT)
	{
		return;
	}
	SpriteComponent->ComponentSprite.setPosition(Offset);
	window.draw(SpriteComponent->ComponentSprite);
}


// переопределение
void AActor::Update()
{

}

Vector2f AActor::GetLocation() const
{
	return ObjLocation;
}
void AActor::SetLocation(Vector2f NewLocation)
{
	this->ObjLocation = NewLocation;
}
void AActor::AddLocation(Vector2f Location)
{
	this->ObjLocation += Location;
}

