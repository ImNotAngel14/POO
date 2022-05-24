#pragma once
#include <engine/model.h>
#include "Entity.h"
#include "FrameAnimation.h"

class Enemy : public Entity
{
public:
	Enemy();
	Enemy(glm::vec3 spawn, int totalFrames, float switchTime);
	~Enemy();
	void UpdateEnemy(float deltaTime, glm::vec3 playerPos);
	void DrawEnemy(Shader shader);
	
private:
	void moveTo(glm::vec3 coord, float deltaTime);
public:

private:
	bool chasingPlayer;
	glm::vec3 position;
	glm::vec3 spawn;
protected:
	Model enemyModel[5];
	FrameAnimation animation;
};

