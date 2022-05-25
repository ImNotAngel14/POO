#ifndef PLAYER_H
#define PLAYER_H
#include <engine/model.h>
#include <engine/camera.h>
#include "Entity.h"
#include "Hitbox.h"
#include "Object.h"

//#include "Inventory.h"

class Player : public Entity
{
public:
	Player();
	Player(int atk, int speed, glm::vec3 _position, Camera* playerCamera);
	~Player();
	void UpdatePlayer(float _dt);
	void PickUpItem(Item);
	void moveBack();
	void setPlayerPos(glm::vec3 _cameraPos);
	glm::vec3 getPlayerPos();
	Hitbox getHitbox();
	bool getKeyFlag();
	bool getBatteryFlag();
	bool getTrophyFlag();
private:

public:

private:
	int hungry;
	bool hasTheKey;
	bool hasTheBattery;
	bool hasTheTrophy;
	glm::vec3 position;
	Hitbox playerHitbox;
	Camera* playerCamera;
};
#endif
