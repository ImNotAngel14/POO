#include "Building.h"

Building::Building()
{
	position = glm::vec3(0.0f, 0.0f, 0.0f);
}

Building::Building(glm::vec3 ubication, const char* path)
{
	position = ubication;
	houseModel = Model("Build", path, ubication, glm::vec3(0, 90, 0), 0.0f, 1.0f);
}

Building::~Building()
{
}

void Building::DrawBuilding(Shader shader)
{
	houseModel.Draw(shader);
}
void Building::Release()
{
	houseModel.Release();
}

glm::vec3 Building::getPosition()
{
	return position;
}
