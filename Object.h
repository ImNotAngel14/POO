#pragma once
#include <engine/model.h>
#include <cstdlib>
#include <iostream>
#include "Hitbox.h"
#include "Building.h"
enum Item
{
	CAN, BAND, BATTERY, KEY
};
class Object
{
public:
	Object();
	Object(glm::vec3 _position, Item _item);
	Object(Item _item, Building* buildingList);
	~Object();
	void UpdateObject(float deltaTime);
	void DrawObject(Shader _shader);
	void Release();

	void SetPos(glm::vec3 newPos)
	{
		position = newPos;
	}
private:
	void loadModel();
public:

private:
	Item item;
	float angle;
	float grades;
	float height;
	glm::vec3 position;
	Model objModel;
	Hitbox objHitbox;
};

