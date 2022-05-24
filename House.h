#pragma once
#include <engine/model.h>
#include "Building.h"
#include "Furniture.h"
//Incluir wall collision

class House : public Building
{
public:
	House();
	House(glm::vec3 ubication, bool isDoorOpen);
	~House();
	void DrawHouse(Shader shader);
private:

public:

private:
	bool isDoorOpen;
	Furniture table;
	Furniture bed;
	Furniture painting;
};

