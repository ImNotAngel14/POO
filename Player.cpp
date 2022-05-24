#include "Player.h"

Player::Player()
{

}

Player::Player(glm::vec3 _position)
{
	position = _position;
	playerHitbox = Hitbox(position, 0.5f, 4.0f);
}

Player::~Player() 
{
}

void Player::UpdatePlayer(Camera* _camera, float _dt)
{
	playerHitbox.UpdateHitbox(position, _dt);
	//Ya puedo poner la camara
	//_camera->Position = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Player::setPlayerPos(glm::vec3 _cameraPos) { position = _cameraPos; }

glm::vec3 Player::getPlayerPos() { return position; }

Hitbox Player::getHitbox() { return playerHitbox; }