#ifndef ENTITY_H
#define ENTITY_H

#define PI 3.1416
#define TO_RAD(DEG) (DEG * PI / 180)
#define TO_DEG(RAD) (RAD / PI * 180.0)
#define POSITION_INC 1

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