#pragma once
#include "UObject.h"
#include "CoreMinimal.h"

class AActor;

class UActorComponent : public UObject
{
protected:
	AActor* ActorOwner;

public:
	static inline std::vector<UActorComponent*> AllComponents;

	UActorComponent(AActor* Owner);
	UActorComponent() = delete;
	~UActorComponent();

	virtual void Update() = 0;
};

