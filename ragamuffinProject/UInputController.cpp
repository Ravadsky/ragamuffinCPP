#include "UInputController.h"
#include "APlayer.h"
#include "UAnimatedSpriteComponent.h"

using namespace sf;
// управление 
void UInputController::GetInput()
{
	sf::Vector2f _direction;
	State _state;
	bool _Looping = true;
	APlayer& Player = APlayer::GetPlayer();

	if (Player.GetPlayerState() == Idle || Player.GetPlayerState() == Move)
	{
		if (Keyboard::isKeyPressed(Keyboard::W)) { _direction += FORWARD_DIRECTION; }
		if (Keyboard::isKeyPressed(Keyboard::S)) { _direction -= FORWARD_DIRECTION; }

		if (Keyboard::isKeyPressed(Keyboard::D)) { _direction += RIGHT_DIRECTION; }
		if (Keyboard::isKeyPressed(Keyboard::A)) { _direction -= RIGHT_DIRECTION; }

		Player.SetDirection(_direction);
	}

	if (_direction.x || _direction.y) _state = State::Move;
	else _state = State::Idle;

		//Interact при нажатии ≈
	if (Keyboard::isKeyPressed(Keyboard::E)) { _state = State::Interact; _Looping = false; };

	Player.SetPlayerState(_state, _Looping);
}
// абстрактный класс?
void UInputController::Update()
{

}