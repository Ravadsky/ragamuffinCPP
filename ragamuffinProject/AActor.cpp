#include "AActor.h"
#include "AssetManager.h"
#include "UInputController.h"
#include "APlayer.h"

AActor::AActor() : AActor(2001) {};

// получение актора для установки его текстуры, коллизии и тд
AActor::AActor(int id)
{
	//Переменная DataPtr указатель на объект типа ActorData. метод GetAssetManager() указывает на поле GetActorData(id), 
	// где параметр id идентификатор объекта
	ActorData* DataPtr = AssetManager::GetAssetManager()->GetActorData(id);
	//ЛОкальая переменная ID
	ID = id;
	//Обращение ObjSprite к методу setTexture, который принимает в качестве параметра указатель на текстуру создаваемого объекта
	ObjSprite.setTexture(*DataPtr->DTexture);
	//Type принимает тип объекта - статический/динамический/виджет, обращаясь к полю объекта DObjectType
	Type = DataPtr->DObjectType;
	//CollisionPreset принимает значение типа коллизии объекта
	CollisionPreset = DataPtr->DCollisionType;
	// Записываем актора в вектор
	AActors.push_back(this);
	// Размер объекта
	ObjSize = { SPRITE_GAME_SIZE / SPRITE_RAW_SIZE, SPRITE_GAME_SIZE / SPRITE_RAW_SIZE };
	//масштаб объекта берется по его размеру
	ObjSprite.setScale(ObjSize);
	// ТОчка привязки объекта?
	ObjSprite.setOrigin({ SPRITE_RAW_SIZE / 2, SPRITE_RAW_SIZE / 2 });
	//установка точки появления объекта
	ObjLocation = { 0, 0 };
}

//отрисовка камеры
void AActor::Draw(sf::RenderWindow& window)
{
	//нахождение смещения относительно игрока?
	sf::Vector2f Offset = this->ObjLocation - APlayer::GetPlayer().ObjLocation + CAMERA_PIVOT;
	if (Offset.x + SPRITE_GAME_SIZE < 0 || Offset.x - SPRITE_GAME_SIZE > WINDOW_WIGHT ||
		Offset.y + SPRITE_GAME_SIZE < 0 || Offset.y - SPRITE_GAME_SIZE > WINDOW_HEIGHT)
	{
		return;
	}
	//Установка позиции для спрайта
	ObjSprite.setPosition(Offset);
	window.draw(ObjSprite);
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
//Получение локации
sf::Vector2f AActor::GetLocation() const
{
	return ObjLocation;
}

