#include "Hitbox.h"

Hitbox::Hitbox(glm::vec3 _position, float _radius, float _cooldown)
{
	position = _position;
	radius = _radius;
	disabled = false;
	cooldown;
}

Hitbox::~Hitbox()
{

}

void Hitbox::UpdateHitbox(glm::vec3 _newPos, float _deltaTime)
{
	position = _newPos;
}

bool Hitbox::areColliding(Hitbox* obj1, Hitbox* obj2)
{
	return false;
}