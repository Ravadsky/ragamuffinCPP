#pragma once
#include "CoreMinimal.h"
#include "CorePhysics.h"
#include "unordered_map"
#include <string>

struct ActorData
{
	Texture* DTexture;
	CollisionType DCollisionType;
	ObjectType DObjectType;
};

class AssetManager
{

public:
	std::unordered_map<int, ActorData> DActors;

	AssetManager();

	ActorData* GetActorData(int ID);
	void AddActorData(int id, std::string Resource, CollisionType DCollision, ObjectType DObjType);

	static inline AssetManager* GetAssetManager()
	{
		static AssetManager Instance;
		return &Instance;
	};
};

