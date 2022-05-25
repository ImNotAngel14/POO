#include "Player.h"

Player::Player()
{

}

Player::Player(int atk, int speed, glm::vec3 _position, Camera* playerCamera) : Entity(atk, speed)
{
	hungry = 100;
	position = _position;
	playerHitbox = Hitbox(position, 0.5f, 4.0f);
	this->playerCamera = playerCamera;
}

Player::~Player() 
{
}

void Player::UpdatePlayer(float _dt)
{
	hungry -= 10 * _dt;
	this->UpdateEntity(_dt);
	this->position = playerCamera->Position;
	if (this->isInvincible())
	{
		playerHitbox.DisableHitbox();
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
		hungry += 20;
		break;
	case BAND:
		this->setHealth(-20);
		break;
	case TROPHY:
		hasTheTrophy = true;
		break;
	}
}

void Player::moveBack()
{
	playerCamera->ProcessKeyboard(BACKWARD, 0.05f);
	this->position = playerCamera->Position;
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