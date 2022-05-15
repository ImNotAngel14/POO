#include "Object.h"

Object::Object(glm::vec3 _position, Item _item)
{
	position = _position;
	item = _item;
}

Object::~Object()
{

}

void Object::UpdateObject(float _dt)
{

}

void Object::DrawObject(Shader _shader)
{

}