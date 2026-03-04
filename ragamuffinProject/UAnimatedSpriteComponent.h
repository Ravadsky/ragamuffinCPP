#pragma once
#include "USpriteComponent.h"

class UAnimatedSpriteComponent : public USpriteComponent
{
private:
	int SpriteSheetOffset = 0;

public:
	bool isLooping = true;
	bool isDone = true;
	float ElapsedTime = 0.f;
	int CurrentFrame = 0;
	const float ANIM_DELTA_TIME = 1 / (ANIM_FRAMES_COUNT * ANIM_SPEED);
	UAnimatedSpriteComponent(AActor* Owner, sf::Texture* tex);
	UAnimatedSpriteComponent();

	void Update() override;

	void AddFrame(int& FrameCounter);

};

