#include "House.h"

House::House()
{
}
House::House(glm::vec3 ubication, const char* path) : Building(ubication, path)
{
	table = Furniture(ubication, glm::vec3(0.1349f, 0.0f, 3.8589f), "models/Mesa/mesita.obj");
	bed = Furniture(ubication, glm::vec3(-0.85f, 0.0f, -1.0f), "models/Cama/camita.obj");
	painting = Furniture(ubication, glm::vec3(-2.45f, 1.0f, 0.97f), "models/Cuadro/painting.obj");
}
House::~House()
{
	
}
void House::DrawBuilding(Shader shader)
{
	Building::DrawBuilding(shader);
	table.DrawFurniture(shader);
	bed.DrawFurniture(shader);
	painting.DrawFurniture(shader);
}

glm::vec3 House::getTableCoord()
{
	glm::vec3 overTableCoord = table.getPosition();
	overTableCoord.y = 1.5f;
	return overTableCoord;
}

Furniture House::getTable()
{
	return table;
}
Furniture House::getBed()
{
	return bed;
}
Furniture House::getPainting()
{
	return painting;
}