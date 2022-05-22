#include "Object.h"

Object::Object()
{

}

Object::Object(glm::vec3 _position, Item _item)
{
	angle = 0;
	position = _position;
	item = _item;
	loadModel();
	//objModel = Model();
}
Object::Object(Item _item, Building* buildingList)
{
	item = _item;
	int listSize = sizeof(buildingList);
	int random = rand() % listSize;
	position = buildingList[random].getPosition();
	position.y += 5;
	loadModel();
}

Object::~Object()
{
}

void Object::UpdateObject(float _dt)
{
	angle < 360 ? angle += 45.0f * _dt : angle = 0;
	objModel.setAngles(glm::vec3(0.0f, angle, 0.0f));
	//::::::::::height animation


}

void Object::DrawObject(Shader _shader)
{
	objModel.Draw(_shader);
}

void Object::Release()
{
	objModel.Release();
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
