#include "Collision.h"
#include "AActor.h"
#include "APlayer.h"
#include "FLibrary.h"

// модуль по векторам
Vector2f absolute(sf::Vector2f && Vec)
{
	return { abs(Vec.x), abs(Vec.y) };
}
// Проверка на коллизию 
sf::Vector2f CheckCollision(APlayer & Player, AActor & Actor, float Distance)
{
	//получаем направление игрока
	Vector2f Direction = Player.GetDirection();
	//находим смещение игрока
	Vector2f PlayerOffset = (Direction * Player.GetPlayerSpeed()) * GetWorldDeltaTime();
	//рассчет передвижения игрока??
	Vector2f Delta = absolute((Player.GetLocation() + PlayerOffset) - Actor.GetLocation());
	// откат шага
	if (Delta.x < Distance && Delta.y < Distance)
	{
		//проверка по Х
		Vector2f PlayerOfssetX = { PlayerOffset.x, 0};
		Delta = absolute( (Player.GetLocation() + PlayerOfssetX) - Actor.GetLocation() );
		if (Delta.x < Distance && Delta.y < Distance) Direction.x = 0;

		//проверка по Y
		Vector2f PlayerOffsetY = { 0, PlayerOffset.y };
		Delta = absolute( (Player.GetLocation() + PlayerOffsetY) - Actor.GetLocation() );
		if (Delta.x < Distance && Delta.y < Distance) Direction.y = 0;

	}
	return Direction;
}

