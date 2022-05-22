#pragma once
class Entity
{
public:
	Entity();
	Entity(int _maxHealth, int _atk, int _speed);
	~Entity();
	void initEntity(int _maxHealth, int _atk, int _speed);
	void attack();
	int getAtk();
	int getHealth();
	int getSpeed();
private:

public:

private:
	int health[2];
	int atk;
	int speed;
};

