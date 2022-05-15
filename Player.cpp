#include "Player.h"

Player::Player(glm::vec3 _position)
{
	position = _position;
	playerHitbox = new Hitbox(position, 0.5f, 4.0f);
}

Player::~Player() 
{
	delete playerHitbox;
}

void Player::UpdatePlayer(glm::vec3 _cameraPos, float _dt)
{
	playerHitbox->UpdateHitbox(position, _dt);
}

void Player::setPlayerPos(glm::vec3 _cameraPos)
{
	position = _cameraPos;
}

glm::vec3 Player::getPlayerPos() { return position; }

Hitbox* Player::getHitbox() { return playerHitbox; }