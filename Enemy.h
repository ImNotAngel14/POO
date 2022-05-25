#ifndef ENEMY_H
#define ENEMY_H
#define PI 3.1416
#define TO_DEG(RAD) (RAD / PI * 180.0)
#include <engine/model.h>
#include <math.h>
#include "Entity.h"
#include "FrameAnimation.h"
#include "Hitbox.h"

enum class EnemyType
{
	BANDIT,
	EAGLE
};

class Enemy : public Entity
{
public:
	Enemy();
	Enemy(int atk, int speed, EnemyType enemyType, glm::vec3 spawn);
	~Enemy();
	void UpdateEnemy(float deltaTime, glm::vec3 playerPos);
	void DrawEnemy(Shader shader);
	Hitbox getHitbox();
	
private:
	void moveTo(glm::vec3 coord, float deltaTime);
public:

private:
	EnemyType enemyType;
	float rotAngle;
	glm::vec3 position;
	glm::vec3 spawn;
	Model enemyModel[5];
	FrameAnimation animation;
	Hitbox enemyHitbox;
};
#endif