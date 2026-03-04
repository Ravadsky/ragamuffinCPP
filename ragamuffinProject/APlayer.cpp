#include "APlayer.h"
#include "FLibrary.h"
#include <ranges>
#include "Collision.h"
#include "UAnimatedSpriteComponent.h"

APlayer::APlayer() : AActor(1001)
{
	ActorData* ObjectData = AssetManager::GetAssetManager()->GetActorData(1001);

	SpriteComponent = std::make_shared<UAnimatedSpriteComponent>(this, ObjectData->DTexture);;
};

// Обновление позиции игрока
void APlayer::Update()
{
	Move();
}

// покадровое передвижение с фильтром блок коллизии
void APlayer::Move()
{//автоматическое присваивание переменной Actors тип объекта AActor::AActors
	auto Actors = AActor::AActors
		//функтор возвращает значение только тех акторов, которые с блок коллизией
		| std::views::filter([](AActor* Actor) {return Actor->CollisionPreset == CollisionType::Block; });
	//для всех акторов кроме себя вызывается проверка на пересечение с коллизиями
	for (AActor* Actor : Actors)
	{
		if (Actor != this)	SetDirection(CheckCollision(*this, *Actor, 128));
	}
	//плавное передвижение игрока 
	AddLocation((PlayerDirection * Speed) * GetWorldDeltaTime());
	//сетит направление в 0, для предотвращения движения
	APlayer::GetPlayer().SetDirection({ 0.f, 0.f });
}

void APlayer::SetPlayerState(State NewState, bool isLooping)
{
	auto AnimComponent = std::static_pointer_cast<UAnimatedSpriteComponent>(SpriteComponent);

	if (AnimComponent->isDone)
	{
		PlayerState = NewState;

		AnimComponent->isLooping = isLooping;
		AnimComponent->isDone = isLooping;

		if (!isLooping) AnimComponent->CurrentFrame = 0;
	}

}

State& APlayer::GetPlayerState()
{
	return PlayerState;
}
