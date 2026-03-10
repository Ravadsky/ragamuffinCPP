#include "UInputController.h"
#include "APlayer.h"
#include "UAnimatedSpriteComponent.h"

void UInputController::GetInput()
{
	APlayer& Player = APlayer::GetPlayer();

	if (Player.CanPlayerAction())
	{
		//Interact при нажатии Е
		if (CheckKey(Keyboard::E)) { Player.Interact(); };
	}

	if (Player.CanPlayerAction())
	{
		Vector2f _direction;
		//Движение по Х
		if (CheckKey(Keyboard::W)) { _direction += FORWARD_DIRECTION; }
		if (CheckKey(Keyboard::S)) { _direction -= FORWARD_DIRECTION; }
		//Движение по Y
		if (CheckKey(Keyboard::D)) { _direction += RIGHT_DIRECTION; }
		if (CheckKey(Keyboard::A)) { _direction -= RIGHT_DIRECTION; }
		
		Player.Move(_direction);
	}
}
// абстрактный класс?
void UInputController::Update()
{

}

bool UInputController::CheckKey(Keyboard::Key Key)
{
	return Keyboard::isKeyPressed(Key);
}
