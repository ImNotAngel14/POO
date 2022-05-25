#include "Entity.h"

Entity::Entity()
{

}

Entity::Entity(int atk, int speed)
{
	this->health = 100;
	this->atk = atk;
	this->speed = speed;
	invencibility = false;
	elapsedTime = 0.0f;
}
Entity::~Entity()
{

}

void Entity::setHealth(int atk)
{
	if (health - atk > 0)
		health -= atk;
	else
		health = 0;
	
}

void Entity::UpdateEntity(float deltaTime)
{
	if (invencibility)
	{
		if (elapsedTime < 4.0f)
		{
			elapsedTime += deltaTime;
		}
		else
		{
			invencibility = false;
			elapsedTime = 0.0f;
		}
	}
	
}

void Entity::attack(Entity* entity)
{
	entity->setHealth(this->atk);
	entity->invencibility = true;
}

int Entity::getAtk()
{
	return atk;
}

int Entity::getHealth()
{
	return health;
}

int Entity::getSpeed()
{
	return speed;
}

bool Entity::isInvincible()
{
	return invencibility;
}