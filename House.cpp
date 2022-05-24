#include "House.h"

House::House()
{
	isDoorOpen = false;
}
House::House(glm::vec3 ubication, bool isDoorOpen) : Building(ubication)
{
	this->isDoorOpen = isDoorOpen;
	table = Furniture(ubication, glm::vec3(0.1349f, 0.25f, 3.8589f), "models/Mesa/mesita.obj");
	bed = Furniture(ubication, glm::vec3(-0.85f, 0.25f, -1.0f), "models/Cama/camita.obj");
	painting = Furniture(ubication, glm::vec3(-2.45f, 1.5f, 0.97f), "models/Cuadro/painting.obj");
}
House::~House()
{
	
}
void House::DrawHouse(Shader shader)
{
	houseModel.Draw(shader);
	table.DrawFurniture(shader);
	bed.DrawFurniture(shader);
	painting.DrawFurniture(shader);
}

glm::vec3 House::getTable()
{
	glm::vec3 overTableCoord = table.getPosition();
	overTableCoord.y = 1.5f;
	return overTableCoord;
}