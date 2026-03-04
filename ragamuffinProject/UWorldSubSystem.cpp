#include "UWorldSubSystem.h"
#include "AActor.h"
#include "APlayer.h"
#include "ARoom.h"

void UWorldSubSystem::Update()
{
}
// тайм апдейт
void UWorldSubSystem::UpdateTime()
{
	DeltaTimer = GameClock.restart();
	DeltaTime = DeltaTimer.asSeconds();
}
//костыльная  отрисовка комнаты 
UWorldSubSystem::UWorldSubSystem()
{
	for (int i = 0; i < WORLD_SIZE; i++)
	{
		for (int j = 0; j < WORLD_SIZE; j++)
		{
			if (i == 0 || i == WORLD_SIZE-1 ||
				j == 0 || j == WORLD_SIZE - 1) new ARoom(i, j, 3);
			else if (i == 4 && j == 4) new ARoom(i, j, 0);
			else new ARoom(i, j);
		}
	}
		//	количество комнат * размер комнаты / 2 
	const float WorldCenter{ WORLD_SIZE * (SPRITE_GAME_SIZE * ROOM_SIZE) / 2 };
	APlayer::GetPlayer().SetLocation({ WorldCenter, WorldCenter });
}

// обновление(переопределение?) акторов
void UWorldSubSystem::UpdateEntities()
{
	for (AActor* Actor : AActor::AActors)
	{
		Actor->Update();
	}

}
