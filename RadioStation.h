#ifndef RADIOSTATION_H
#define RADIOSTATION_H

#include "Building.h"
#include "Furniture.h"
#include "Hitbox.h"

class RadioStation :public Building
{
public:
	RadioStation();
	RadioStation(glm::vec3 ubication, const char* path);
	~RadioStation();
	void DrawBuilding(Shader shader);
	void openDoor();
	Hitbox getHitbox();
	Hitbox getRadioHitbox();
private:

public:

private:
	bool doorOpen;
	Furniture radio;
	Furniture table;
	Model openStation;
	Hitbox doorHitbox;
};
#endif
