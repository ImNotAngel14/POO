#pragma once
#include <engine/model.h>
class Hitbox
{
	//Methods
public:
	Hitbox();
	Hitbox(glm::vec3 _position, float _radius, float _cooldown);
	~Hitbox();
	void UpdateHitbox(glm::vec3 _newPos, float _deltaTime);
	bool areColliding(Hitbox* obj1, Hitbox* obj2);
private:
	//Attributes
public:

private:
	bool disabled;
	float cooldown;
	float radius;
	glm::vec3 position;
};

