#include "Hitbox.h"

Hitbox::Hitbox()
{
	radius = 0.0f;
	disabled = false;
	cooldown = 0.0f;
	elapsedTime = 0.0f;
}

Hitbox::Hitbox(glm::vec3 _position, float _radius, float _cooldown)
{
	position = _position;
	radius = _radius;
	disabled = false;
	cooldown = _cooldown;
	elapsedTime = 0.0f;
}
Hitbox::Hitbox(glm::vec3 _position, float _radius)
{
	position = _position;
	radius = _radius;
	disabled = false;
	cooldown = 0.0f;
	elapsedTime = 0.0f;
}

Hitbox::~Hitbox()
{

}

void Hitbox::UpdateHitbox(glm::vec3 _newPos, float _deltaTime)
{
	position = _newPos;
	if (disabled)
	{
		if (elapsedTime > cooldown)
		{
			elapsedTime = 0.0f;
			disabled = false;
		}
		else
		{
			elapsedTime += _deltaTime;
		}
	}
}

void Hitbox::UpdateHitbox(glm::vec3 _newPos)
{
	position = _newPos;
}

bool Hitbox::areColliding(Hitbox obj1, Hitbox obj2)
{
	if (obj1.disabled || obj2.disabled)
	{
		return false;
	}
	else {
		glm::vec2 axisDistance(
			obj1.position.x - obj2.position.x,
			obj1.position.z - obj2.position.z
		);
		float totalDistance = sqrt(pow(axisDistance.x, 2) + pow(axisDistance.y, 2));
		return totalDistance < obj1.radius + obj2.radius;
	}
}

void Hitbox::DisableHitbox()
{
	disabled = true;
}