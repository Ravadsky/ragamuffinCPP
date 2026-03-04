#include "UActorComponent.h"

UActorComponent::UActorComponent(AActor* Owner)
{
	ActorOwner = Owner;
	AllComponents.push_back(this);
}

UActorComponent::UActorComponent()
{
}

UActorComponent::~UActorComponent()
{
	auto _iterator = std::find(AllComponents.begin(), AllComponents.end(), this);
	if (_iterator != AllComponents.end()) AllComponents.erase(_iterator);
}
