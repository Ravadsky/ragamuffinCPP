#include "Collision.h"
#include "AActor.h"
#include "APlayer.h"
#include "FLibrary.h"

using Vector = sf::Vector2f;
// модуль по векторам
sf::Vector2f absolute(sf::Vector2f && Vec)
{
	return { abs(Vec.x), abs(Vec.y) };
}
// Проверка на коллизию 
sf::Vector2f CheckCollision(APlayer & Player, AActor & Actor, float Distance)
{
	//получаем направление игрока
	Vector Direction = Player.GetDirection();
	//находим смещение игрока
	Vector PlayerOffset = (Direction * Player.Speed) * GetWorldDeltaTime();
	//рассчет передвижения игрока??
	Vector Delta = absolute((Player.GetLocation() + PlayerOffset) - Actor.GetLocation());
	// откат шага
	if (Delta.x < Distance && Delta.y < Distance)
	{
		//проверка по Х
		Vector PlayerOfssetX = { PlayerOffset.x, 0};
		Delta = absolute( (Player.GetLocation() + PlayerOfssetX) - Actor.GetLocation() );
		if (Delta.x < Distance && Delta.y < Distance) Direction.x = 0;

		//проверка по Y
		Vector PlayerOffsetY = { 0, PlayerOffset.y };
		Delta = absolute( (Player.GetLocation() + PlayerOffsetY) - Actor.GetLocation() );
		if (Delta.x < Distance && Delta.y < Distance) Direction.y = 0;

	}
	return Direction;
}

