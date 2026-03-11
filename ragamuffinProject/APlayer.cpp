#include "APlayer.h"
#include "FLibrary.h"
#include <ranges>
#include "Collision.h"
#include "UAnimatedSpriteComponent.h"
#include "UAudioSubSystem.h"

APlayer::APlayer() : AActor(1001)
{
	ActorData* ObjectData = AssetManager::GetAssetManager()->GetActorData(1001);

	SpriteComponent = std::make_shared<UAnimatedSpriteComponent>(this, ObjectData->DTexture);;
};

// Обновление позиции игрока
void APlayer::Update() 
{
	auto AnimComponent = std::static_pointer_cast<UAnimatedSpriteComponent>(SpriteComponent);
	if (AnimComponent->AnimEnd)
	{
		SetPlayerState(State::Idle, true);
		AnimComponent->AnimEnd = false;
	}
}

// покадровое передвижение с фильтром блок коллизии
void APlayer::Move(Vector2f Direction)
{
	SetDirection(Direction);

	if (Direction.x || Direction.y) { SetPlayerState(State::Move, true); }
	else { SetPlayerState(State::Idle, true); return; }
	//автоматическое присваивание переменной Actors тип объекта AActor::AActors
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

void APlayer::Interact()
{
	SetPlayerState(State::Interact, false);
	UAudioSubSystem::GetUAudioSubSystem().CreateNewSound("Sound");

}

void APlayer::SetPlayerState(State NewState, bool isLooping)
{
	PlayerState = NewState;
	SpriteComponent->SetComponentState(isLooping);
}

State& APlayer::GetPlayerState()
{
	return PlayerState;
}

bool APlayer::CanPlayerAction()
{
	auto _state = GetPlayerState();
	return  (_state == State::Idle) || (_state == State::Move);
}
