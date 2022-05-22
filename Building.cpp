#include "Building.h"

Building::Building(glm::vec3 ubication)
{
	position = ubication;
	houseModel = Model("Build", "models/casa/casa1.obj", ubication, glm::vec3(0, 90, 0), 0.0f, 1.0f);
}

Building::~Building()
{
}

void Building::Draw(Shader shader, glm::mat4 view, glm::mat4 projection)
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
