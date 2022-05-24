#ifndef PLAYER_H
#define PLAYER_H
#include <engine/model.h>
#include <engine/camera.h>
#include "Hitbox.h"
#include "Object.h"

//#include "Inventory.h"

class Player
{
public:
	Player();
	Player(glm::vec3 _position);
	~Player();
	void UpdatePlayer(Camera* _camera, float _dt);
	void PickUpItem(Item);
	void setPlayerPos(glm::vec3 _cameraPos);
	glm::vec3 getPlayerPos();
	//void pickUpItem(Items item, Objeto* obj);
	Hitbox getHitbox();
private:

public:

private:
	bool hasTheKey;
	bool hasTheBattery;
	bool hasTheTrophy;
	glm::vec3 position;
	Hitbox playerHitbox;
};
#endif
