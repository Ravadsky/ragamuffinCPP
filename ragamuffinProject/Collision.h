#pragma once
#include "CoreMinimal.h"

class AActor; class APlayer;

enum class CollisionType{ Block, Overlap, Ignore };

sf::Vector2f absolute(sf::Vector2f && Vec);
sf::Vector2f CheckCollision(APlayer& Player, AActor& Actor, float Distance);

