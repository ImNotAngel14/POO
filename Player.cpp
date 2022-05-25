#include "Player.h"

Player::Player()
{

}

Player::Player(int atk, int speed, glm::vec3 _position) : Entity(atk, speed)
{
	position = _position;
	playerHitbox = Hitbox(position, 0.5f, 4.0f);
}

Player::~Player() 
{
}

void Player::UpdatePlayer(Camera* _camera, float _dt)
{
	this->UpdateEntity(_dt);
	this->position = _camera->Position;
	if (this->isInvincible())
	{
		playerHitbox.DisableHitbox();
		std::cout << "Health" << this->getHealth() << "%" << std::endl;
	}
		
	playerHitbox.UpdateHitbox(position, _dt);
	//Ya puedo poner la camara
	//_camera->Position = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Player::PickUpItem(Item item)
{
	switch (item)
	{
	case KEY:
		hasTheKey = true;
		break;
	case BATTERY:
		hasTheBattery = true;
		break;
	case CAN:
		break;
	case BAND:
		break;
	default:
		break;
	}
}

void Player::setPlayerPos(glm::vec3 _cameraPos) { position = _cameraPos; }

glm::vec3 Player::getPlayerPos() { return position; }

Hitbox Player::getHitbox() { return playerHitbox; }

bool Player::getKeyFlag()
{
	return hasTheKey;
}
bool Player::getBatteryFlag()
{
	return hasTheBattery;
}
bool Player::getTrophyFlag()
{
	return hasTheTrophy;
}