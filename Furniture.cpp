#include "Furniture.h"

Furniture::Furniture()
{

}

Furniture::Furniture(glm::vec3 position, const char* path)
{
	this->position = position;
	furnitureModel = Model("Furniture", path, this->position, glm::vec3(0, 90, 0), 0.0f, 1.0f);
}

Furniture::Furniture(glm::vec3 housePosition, glm::vec3 furniturePosition, const char* path)
{
	glm::vec3 temp(0.0f, 0.0f, 0.0f);
	temp.x = housePosition.x + furniturePosition.x;
	temp.y = housePosition.y + furniturePosition.y;
	temp.z = housePosition.z + furniturePosition.z;
	this->position = temp;
	furnitureModel = Model("Furniture", path, this->position, glm::vec3(0, 90, 0), 0.0f, 1.0f);
}

Furniture:: ~Furniture()
{

}

void Furniture::DrawFurniture(Shader shader)
{
	furnitureModel.Draw(shader);
}