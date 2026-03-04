#include "ARoom.h"
#include <fstream>
#include <sstream>
#include <string>
#include "FLibrary.h"

ARoom::ARoom(int x, int y) : ARoom(x, y, GetRandomInt(0, ROOM_COUNT - 1)) {};

ARoom::ARoom(int x, int y, int RoomIndex)
{
	Type = ObjectType::NonDrawable;

	std::ifstream RoomFile(RESOURCES_PATH + "Rooms");
	std::string Line;
	char Symbol;

	while (Line != RoomNames[RoomIndex]) std::getline(RoomFile, Line);


	for (int i = 0; i < ROOM_SIZE; i++)
	{
		std::getline(RoomFile, Line);

		auto RemoveSpaces = [](unsigned char ch) { return ch == ' ' || ch == ','; };
		Line.erase(std::remove_if(Line.begin(), Line.end(), RemoveSpaces), Line.end());

		std::istringstream StringStream(Line);

		for (int j = 0; j < ROOM_SIZE; j++)
		{
			StringStream >> Symbol;

			AActor* Actor = new AActor(KeySymbols[Symbol]);
			sf::Vector2f RelativeLocation = { (float)j * SPRITE_GAME_SIZE, (float)i * SPRITE_GAME_SIZE };
			sf::Vector2f Offset = { (float)x * SPRITE_GAME_SIZE * ROOM_SIZE, (float)y * SPRITE_GAME_SIZE * ROOM_SIZE };
			Actor->SetLocation(RelativeLocation + Offset);
		}
	}
}

void ARoom::Update()
{
}
