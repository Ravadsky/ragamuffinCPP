#pragma once
#include "USpriteComponent.h"

class UAnimatedSpriteComponent : public USpriteComponent
{
private:
	int SpriteSheetOffset = 0;

public:
	bool isLooping = true;
	bool AnimEnd = false;
	float ElapsedTime = 0.f;
	int CurrentFrame = 0;

	UAnimatedSpriteComponent(AActor* Owner, sf::Texture* tex);
	UAnimatedSpriteComponent() = delete;

	void Update() override;

	void SetComponentState(bool param) override;

	void AddFrame(int& FrameCounter);

};

