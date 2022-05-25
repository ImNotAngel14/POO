#ifndef OBJECT_H
#define OBJECT_H

#include <engine/model.h>
#include <cstdlib>
#include "Hitbox.h"
#include "House.h"
enum Item
{
	CAN, BAND, BATTERY, KEY, TROPHY
};
class Object
{
public:
	Object();
	Object(glm::vec3 _position, Item _item);
	~Object();
	void UpdateObject(float deltaTime);
	void DrawObject(Shader _shader);
	void Release();

	//void SetPos(glm::vec3 newPos)
	//{
	//	position = newPos;
	//}
	Hitbox getHitbox();
	void itemConsumed();
private:
	void loadModel();
public:

private:
	bool consumedItem;
	Item item;
	float angle;
	float grades;
	float height;
	glm::vec3 position;
	Model objModel;
	Hitbox objHitbox;
};
#endif
