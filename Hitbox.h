#ifndef HITBOX_H
#define HITBOX_H
#include <engine/model.h>
class Hitbox
{
	//Methods
public:
	Hitbox();
	Hitbox(glm::vec3 _position, float _radius, float _cooldown);
	Hitbox(glm::vec3 _position, float _radius);
	~Hitbox();
	void UpdateHitbox(glm::vec3 _newPos, float _deltaTime);
	void UpdateHitbox(glm::vec3 _newPos);
	bool areColliding(Hitbox obj1, Hitbox obj2);
	void DisableHitbox();
private:
	//Attributes
public:

private:
	bool disabled;
	float cooldown;
	float elapsedTime;
	float radius;
	glm::vec3 position;
};
#endif
