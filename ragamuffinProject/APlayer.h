#pragma once
#include "AActor.h"

class APlayer : public AActor
{
	sf::Vector2f PlayerDirection;
public:
	APlayer();
	float Speed{ 400.f };

	inline void SetDirection(sf::Vector2f vec) { PlayerDirection = vec; };

	inline sf::Vector2f GetDirection() { return PlayerDirection; };

	void Update() override;


	static inline APlayer& GetPlayer() {static APlayer Hero; return Hero; };

	void Move();
};

