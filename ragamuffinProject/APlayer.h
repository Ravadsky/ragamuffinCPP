#pragma once
#include "AActor.h"

enum State
{
	Idle,
	Move,
	Interact,
};

class APlayer : public AActor
{
protected:
	State PlayerState = Idle;
	Vector2f PlayerDirection;
	float Speed{ 400.f };

public:
	APlayer();

	void Update() override;
	
	void Move();

	static inline APlayer& GetPlayer() { static APlayer Hero; return Hero; };

	inline void SetDirection(Vector2f vec) { PlayerDirection = vec; };
	inline Vector2f GetDirection() { return PlayerDirection; };

	inline float GetPlayerSpeed() { return Speed; };

	void SetPlayerState(State NewState, bool isLooping);
	State& GetPlayerState();
};

