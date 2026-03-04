#include "UAnimatedSpriteComponent.h"
#include "FLibrary.h"
#include "APlayer.h"

UAnimatedSpriteComponent::UAnimatedSpriteComponent(AActor* Owner, sf::Texture* tex) : USpriteComponent(Owner, tex)
{
	ComponentSprite.setTextureRect({ CurrentFrame * SPRITE_RAW_SIZE, 0, SPRITE_RAW_SIZE, SPRITE_RAW_SIZE });;
}

UAnimatedSpriteComponent::UAnimatedSpriteComponent()
{
}

void UAnimatedSpriteComponent::Update()
{
	ElapsedTime = ElapsedTime + GetWorldDeltaTime();
	while (ElapsedTime >= ANIM_DELTA_TIME)
	{
		ElapsedTime -= ANIM_DELTA_TIME;
		AddFrame(CurrentFrame);
	}
	APlayer* Pawn = dynamic_cast<APlayer*>(ActorOwner);
	if (Pawn != nullptr)
	{
		SpriteSheetOffset = Pawn->GetPlayerState();
	}
	else
	{
		SpriteSheetOffset = 0;
	}

	ComponentSprite.setTextureRect({ CurrentFrame * SPRITE_RAW_SIZE, SpriteSheetOffset * SPRITE_RAW_SIZE, SPRITE_RAW_SIZE, SPRITE_RAW_SIZE });
}

void UAnimatedSpriteComponent::AddFrame(int& FrameCounter)
{
	{
		if (FrameCounter < (ANIM_FRAMES_COUNT - 1))
		{
			FrameCounter++;
		}
		else
		{
			if (isLooping) FrameCounter = 0;
			else isDone = true;
		}
	}
}
