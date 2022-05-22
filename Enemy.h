#pragma once
#include <engine/model.h>
#include "Entity.h"
#include "FrameAnimation.h"

class Enemy : public Entity
{
public:
	Enemy(glm::vec3 spawn);
	~Enemy();
	void UpdateEnemy(float _dt, glm::vec3 playerPos);
	void DrawEnemy(Shader _shader);
private:
	void moveTo(glm::vec3 coord, float _dt);
public:

private:
	bool chasingPlayer;
	glm::vec3 position;
	glm::vec3 spawn;
	Model enemyModel[5];
	FrameAnimation animation;
};

