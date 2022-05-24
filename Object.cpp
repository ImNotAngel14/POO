#include "Object.h"

Object::Object()
{
	angle = 0;
	grades = 0;
	position = glm::vec3(0, 0, 0);
	height = 0;
	consumedItem = false;
}

Object::Object(glm::vec3 _position, Item _item)
{
	angle = 0;
	grades = 0;
	position = _position;
	item = _item;
	loadModel();
	objHitbox = Hitbox(position, 1.5f);
	consumedItem = false;
	//objModel = Model();
}
Object::Object(Item _item, vector<House> city)
{
	////arriba de la mesa
	item = _item;
	int listSize = sizeof(city);
	int random = rand() % listSize;
	position = city[random].getPosition();
	position.y += 5;
	loadModel();
	consumedItem = false;
}

Object::~Object()
{
}

void Object::UpdateObject(float deltaTime)
{
	if (consumedItem == false)
	{
		angle < 360 ? angle += 45.0f * deltaTime : angle = 0;
		grades < 180 ? grades += 0.5f * deltaTime : grades = 0;
		objModel.setAngles(glm::vec3(0.0f, angle, 0.0f));
		height = sin(grades) / 4;
		objModel.setPosition(glm::vec3(position.x, position.y + height, position.z));
		objHitbox.UpdateHitbox(position);
	}
	
}

void Object::DrawObject(Shader _shader)
{
	if (consumedItem == false)
		objModel.Draw(_shader);
}

void Object::Release()
{
	objModel.Release();
}


Hitbox Object::getHitbox()
{
	return objHitbox;
}

void Object::itemConsumed()
{
	consumedItem = true;
	objHitbox.DisableHitbox();
}

void Object::loadModel()
{
	string ubication;
	switch (item)
	{
	case CAN:
		ubication = "models/Lata/lata.obj";
		break;
	case BAND:
		ubication = "models/Vendas/vendas.obj";
		break;
	case BATTERY:
		ubication = "models/Bateria/bateria.obj";
		break;
	case KEY:
		ubication = "models/Llave/llave.obj";
		break;
	}
	objModel = Model("Object", ubication.c_str(), position, glm::vec3(0, 90, 0), 0.0f, 1.0f);
}
