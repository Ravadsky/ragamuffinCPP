#include "UWorldSubSystem.h"
#include "AActor.h"
#include "APlayer.h"

void UWorldSubSystem::Update()
{
}

void UWorldSubSystem::UpdateTime()
{
	DeltaTimer = GameClock.restart();
	DeltaTime = DeltaTimer.asSeconds();
}
UWorldSubSystem::UWorldSubSystem()
{

	int id = 0;
	for (int i = 0; i < 5; i++)
	{
		int counter = 0;

		for (char& code : Room[i])
		{
			switch (code)
			{
			case '1': id = 2001;
				break;
			case '2': id = 2002;
				break;
			case '3': id = 3001;
				break;
			};
			AActor* Actor = new AActor(id);
			Actor->SetLocation({ counter * 128.f, i*128.f });
			counter++;
	}
	}
	APlayer::GetPlayer().SetLocation({ 256.f, 256.f });

}


void UWorldSubSystem::UpdateEntities()
{
	for (AActor* Actor : AActor::AActors)
	{
		Actor->Update();
	}

}
