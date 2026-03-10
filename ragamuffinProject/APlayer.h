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
private:
	State PlayerState = Idle;

protected:
	Vector2f PlayerDirection;
	float Speed = PLAYER_SPEED;

public:
	APlayer();

	void Update() override;
	
	static inline APlayer& GetPlayer() { static APlayer Hero; return Hero; };

	void Move(Vector2f Direction);

	void Interact();

	inline void SetDirection(Vector2f vec) { PlayerDirection = vec; };
	inline Vector2f GetDirection() { return PlayerDirection; };

	inline float GetPlayerSpeed() { return Speed; };

	void SetPlayerState(State NewState, bool isLooping);
	State& GetPlayerState();

	bool CanPlayerAction();
};

