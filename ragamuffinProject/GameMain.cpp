#include "CoreMinimal.h"
#include "AssetManager.h"
#include "UInputController.h"
#include "UWorldSubSystem.h"
#include "URenderSubSystem.h"
#include "FLibrary.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIGHT, WINDOW_HEIGHT), "ragamuffin");

	GetWorldSubSystem();




	while (window.isOpen())
	{
		GetWorldSubSystem().UpdateTime();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//управление
		UInputController::GetInputController().GetInput();
		//игровая логика
		UWorldSubSystem::GetWorldSubSystem().UpdateEntities();
		//рендер
		URenderSubSystem::GetRenderSubSystem().DrawEntities(window);
	}
	return 0;
}