#include "APlayer.h"
#include "FLibrary.h"
#include <ranges>
#include "Collision.h"

APlayer::APlayer() : AActor(1001) {};

void APlayer::Update()
{
	Move();
}

void APlayer::Move()
{
	auto Actors = AActor::AActors
		| std::views::filter([](AActor* Actor) {return Actor->CollisionPreset == CollisionType::Block; });
	for (AActor* Actor : Actors)
	{
		if (Actor != this)	SetDirection(CheckCollision(*this, *Actor, 128));
	}

	AddLocation((PlayerDirection * Speed) * GetWorldDeltaTime());

	APlayer::GetPlayer().SetDirection({ 0.f, 0.f });
}