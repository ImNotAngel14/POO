#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
class Entity
{
public:
	Entity();
	Entity(int atk, int speed);
	~Entity();
	void UpdateEntity(float deltaTime);
	void attack(Entity* entity);
	void setHealth(int atk);
	int getAtk();
	int getHealth();
	int getSpeed();
	bool isInvincible();
private:

public:

private:
	bool invencibility;
	int health;
	int atk;
	int speed;
	float elapsedTime;
};

#endif