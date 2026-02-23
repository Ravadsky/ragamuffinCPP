#include "UInputController.h"
#include "APlayer.h"

using namespace sf;

void UInputController::GetInput()
{
	sf::Vector2f Direction;
	if (Keyboard::isKeyPressed(Keyboard::S)) { Direction += {0.f, 1.f}; }
	if (Keyboard::isKeyPressed(Keyboard::W)) { Direction += {0.f, -1.f}; }
	if (Keyboard::isKeyPressed(Keyboard::D)) { Direction += {1.f, 0.f}; }
	if (Keyboard::isKeyPressed(Keyboard::A)) { Direction += {-1.f, 0.f};;}
	APlayer::GetPlayer().SetDirection(Direction);
}

void UInputController::Update()
{

}