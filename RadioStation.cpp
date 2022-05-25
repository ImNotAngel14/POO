#include "RadioStation.h"

RadioStation::RadioStation()
{

}

RadioStation::RadioStation(glm::vec3 ubication, const char* path) : Building(ubication, path)
{
	table = Furniture(ubication, glm::vec3(0.0f, 0.0f, 0.0f), "models/Mesa/mesita.obj");
	radio = Furniture(ubication, glm::vec3(0.0f, 1.2f, 0.0f), "models/Radio/radio.obj");
	doorOpen = false;
	openStation = Model("Build", "models/House/house4.obj", ubication, glm::vec3(0, 90, 0), 0.0f, 1.0f);
	doorHitbox = Hitbox(glm::vec3(2.47f,0,-3.21f), 1.5f);
}

RadioStation::~RadioStation()
{

}

void RadioStation::DrawBuilding(Shader shader)
{
	if (doorOpen)
	{
		openStation.Draw(shader);
	}
	else
	{
		Building::DrawBuilding(shader);
	}
	radio.DrawFurniture(shader);
	table.DrawFurniture(shader);
}

void RadioStation::openDoor()
{
	doorOpen = true;
}

Hitbox RadioStation::getHitbox()
{
	return doorHitbox;
}
Hitbox RadioStation::getRadioHitbox()
{
	return radio.getHitbox();
}