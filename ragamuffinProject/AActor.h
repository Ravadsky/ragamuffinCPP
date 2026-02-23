#pragma once
#include "CoreMinimal.h"
#include "AssetManager.h"
#include <vector>
#include "Collision.h"



class AActor : public UObject
{

	sf::Sprite ObjSprite;
	sf::Vector2f ObjSize;
	sf::Vector2f ObjLocation;

protected:
	int ID;

public:
	static inline std::vector<AActor*> AActors;
	CollisionType CollisionPreset;

	AActor(int id);
	AActor();

	void Draw(sf::RenderWindow& window);

	inline int GetID() { return ID; };

	virtual void Update() override;

	void SetLocation(sf::Vector2f Location);
	void AddLocation(sf::Vector2f Location);
	sf::Vector2f GetLocation() const;

};

