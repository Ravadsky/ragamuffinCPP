#pragma once
#include "CoreMinimal.h"
#include "AssetManager.h"
#include <vector>
#include "Collision.h"
#include "USpriteComponent.h"


class AActor : public UObject
{

protected:
	Vector2f ObjLocation = { 0.f, 0.f };
	std::shared_ptr<USpriteComponent> SpriteComponent;
	int ID;
	std::vector<UActorComponent*> ActorComponents;

public:
	static inline std::vector<AActor*> AActors;
	CollisionType CollisionPreset;

	AActor(int id);
	AActor();

	void Draw(sf::RenderWindow& window);

	inline int GetID() { return ID; };
	inline USpriteComponent* GetSpriteComponent() {return SpriteComponent.get(); }


	virtual void Update() override;

	void SetLocation(sf::Vector2f Location);
	void AddLocation(sf::Vector2f Location);
	Vector2f GetLocation() const;

};

