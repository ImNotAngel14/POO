#ifndef FURNITURE_H
#define FURNITURE_H
#include <engine/model.h>
#include "Building.h"
#include "Hitbox.h"

class Furniture 
{
public:
	Furniture();
	Furniture(glm::vec3 position, const char* path);
	Furniture(glm::vec3 housePosition, glm::vec3 furniturePosition, const char* path);
	~Furniture();
	void DrawFurniture(Shader shader);
	glm::vec3 getPosition();
	Hitbox getHitbox();
private:

public:

private:
	glm::vec3 position;
	Model furnitureModel;
	Hitbox furnitureHitbox;
};
#endif

