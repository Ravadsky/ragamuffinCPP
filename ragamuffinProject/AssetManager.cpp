#include "AssetManager.h"

// Шаблон для загрузки данных по акторам

void AssetManager::AddActorData(int id, std::string Resource, CollisionType DCollision, ObjectType DObjType)
{
	//создаем динамический объект в памяти
	DActors[id] = { new sf::Texture, DCollision, DObjType };
	//загрузка текстуры в виде пнгшки
	DActors[id].DTexture->loadFromFile(RESOURCES_PATH + Resource + ".png");
}

ActorData* AssetManager::GetActorData(int ID) { return &DActors[ID]; }
// Хэш таблица
AssetManager::AssetManager()
{
	AddActorData(1001, "Player", CollisionType::Block, ObjectType::Dynamic);
	AddActorData(2001, "Grass", CollisionType::Ignore, ObjectType::Static);
	AddActorData(2002, "Stone", CollisionType::Block, ObjectType::Static);
	AddActorData(3001, "Chest", CollisionType::Block, ObjectType::Static);
}