#pragma once
#include <engine/model.h>
#include "Hitbox.h"
#include "Inventory.h"

class Player
{
public:
	Player(glm::vec3 _position);
	~Player();
	void UpdatePlayer(glm::vec3 _cameraPos, float _dt);
	void setPlayerPos(glm::vec3 _cameraPos);
	glm::vec3 getPlayerPos();
	//void pickUpItem(Items item, Objeto* obj);
	Hitbox* getHitbox();
private:

public:

private:
	glm::vec3 position;
	Hitbox* playerHitbox;
	Inventory inventory;
};

