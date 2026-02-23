#pragma once
#include "CoreMinimal.h"
#include "CorePhysics.h"
#include "unordered_map"
#include <string>

struct ActorData
{
	sf::Texture* DTexture;
	CollisionType DCollisionType;
	ObjectType DObjectType;
};

class AssetManager
{

public:

	sf::Texture PlayerTexture;
	sf::Texture GrassTexture;
	std::unordered_map<int, ActorData> DActors;

	ActorData* GetActorData(int ID);

	void AddActorData(int id, std::string Resource, CollisionType DCollision, ObjectType DObjType);

	AssetManager();	

	//синглтонится челик
	static inline AssetManager* GetAssetManager()
	{
		static AssetManager Instance;
		return &Instance;
	};
};

