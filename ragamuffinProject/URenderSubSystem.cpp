#include "URenderSubSystem.h"
#include "AActor.h"
#include <ranges>

void URenderSubSystem::Update()
{
}
// отрисовка окна
URenderSubSystem::URenderSubSystem()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIGHT, WINDOW_HEIGHT), "ragamuffin");
}
// фильтр для отрисовки статических и динамических объектов
void URenderSubSystem::DrawEntities(sf::RenderWindow& window)
{
	//очищаем окно :О
	window.clear();
	//функтор на статические объекты
	auto statics = AActor::AActors
					| std::views::filter([](AActor* Actor) {return Actor->Type == ObjectType::Static; } );
	//отрисовка статиков
	for (AActor* Actor : statics) { Actor->Draw(window); }
	//функтор на динамические объекты
	auto dynamics = AActor::AActors
					| std::views::filter([](AActor* Actor) {return Actor->Type == ObjectType::Dynamic; });
	//отрисовка динамиков
	for (AActor* Actor : dynamics) { Actor->Draw(window); }
	//вывод окошка
	window.display();
}
