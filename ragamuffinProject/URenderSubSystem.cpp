#include "URenderSubSystem.h"
#include "AActor.h"
#include <ranges>

void URenderSubSystem::Update()
{
}
URenderSubSystem::URenderSubSystem()
{}
void URenderSubSystem::DrawEntities(sf::RenderWindow& window)
{
	window.clear();
	auto statics = AActor::AActors
					| std::views::filter([](AActor* Actor) {return Actor->Type == ObjectType::Static; } );

	for (AActor* Actor : statics) { Actor->Draw(window); }

	auto dynamics = AActor::AActors
					| std::views::filter([](AActor* Actor) {return Actor->Type == ObjectType::Dynamic; });

	for (AActor* Actor : dynamics) { Actor->Draw(window); }

	window.display();
}