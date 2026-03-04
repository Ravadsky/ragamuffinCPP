#include "AActor.h"
#include "AssetManager.h"
#include "UInputController.h"
#include "APlayer.h"

AActor::AActor() : AActor(2001) {};

// получение актора дл€ установки его текстуры, коллизии и тд
AActor::AActor(int id)
{
	ID = id;
	ActorData* ObjectData = AssetManager::GetAssetManager()->GetActorData(id);
	SpriteComponent = std::make_shared<USpriteComponent>(this, ObjectData->DTexture);
	//Type принимает тип объекта - статический/динамический/виджет, обраща€сь к полю объекта DObjectType
	Type = ObjectData->DObjectType;
	//CollisionPreset принимает значение типа коллизии объекта
	CollisionPreset = ObjectData->DCollisionType;
	// «аписываем актора в вектор
	AActors.push_back(this);
}

//отрисовка камеры
void AActor::Draw(sf::RenderWindow& window)
{
	//нахождение смещени€ относительно игрока?
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

// методы работы с векторами?
//установка позиции
void AActor::SetLocation(sf::Vector2f NewLocation)
{
	this->ObjLocation = NewLocation;
}
//смена локации?
void AActor::AddLocation(sf::Vector2f Location)
{
	this->ObjLocation += Location;
}
//ѕолучение локации
sf::Vector2f AActor::GetLocation() const
{
	return ObjLocation;
}

