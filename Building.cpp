#include "Building.h"

Building::Building()
{
	position = glm::vec3(0.0f, 0.0f, 0.0f);
}

Building::Building(glm::vec3 ubication)
{
	position = ubication;
	houseModel = Model("Build", "models/casa/casa1.obj", ubication, glm::vec3(0, 90, 0), 0.0f, 1.0f);
}

Building::~Building()
{
}

void Building::DrawBuilding(Shader shader)
{
	/*if (position.x > 0)
		houseModel.setAngles(glm::vec3(0, 270,0));*/
	houseModel.Draw(shader);
	//houseModel.drawCollBox(view, projection);
}
void Building::Release()
{
	houseModel.Release();
}

glm::vec3 Building::getPosition()
{
	return position;
}
