#pragma once
#include <engine/model.h>
#include "Hitbox.h"
enum Item
{
	CAN, BAND, BATTERY, KEY
};
class Object
{
public:
	Object(glm::vec3 _position, Item _item);
	~Object();
	void UpdateObject(float _dt);
	void DrawObject(Shader _shader);
private:

public:

private:
	Item item;
	glm::vec3 position;
	Model* objModel;
	Hitbox* objHitbox;
};

