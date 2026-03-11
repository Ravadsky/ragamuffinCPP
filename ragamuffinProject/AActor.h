#pragma once
#include <vector>

#include "CoreMinimal.h"
#include "AssetManager.h"
#include "Collision.h"
#include "USpriteComponent.h"


class AActor : public UObject
{
private:
	int ID;

protected:
	std::vector<UActorComponent*> ActorComponents;

	Vector2f ObjLocation = { 0.f, 0.f };
	std::shared_ptr<USpriteComponent> SpriteComponent;

public:
	static inline std::vector<AActor*> AActors;
	CollisionType CollisionPreset;

	AActor();
	AActor(int id);

	void Update() override;

	void Draw(RenderWindow& window);

	inline int GetID() { return ID; };

	inline USpriteComponent* GetSpriteComponent() {return SpriteComponent.get(); }

	Vector2f GetLocation() const;
	void SetLocation(Vector2f Location);
	void AddLocation(Vector2f Location);

};

