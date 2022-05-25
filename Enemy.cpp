#include "Enemy.h"

float distanceBetween(glm::vec3 positionA, glm::vec3 positionB);

Enemy::Enemy()
{

}

Enemy::Enemy(int atk, int speed, EnemyType enemyType, glm::vec3 spawn) :Entity (atk, speed)
{
	this->rotAngle = 0;
	this->enemyType = enemyType;
	this->spawn = spawn;
	this->position = spawn;

	animation = FrameAnimation(5, 1.2f);
	switch (enemyType)
	{
	case EnemyType::BANDIT:
		animation = FrameAnimation(5, 0.4f);
		enemyModel[0] = Model("Enemy1", "models/Bandit/bandit1.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 1.0f);
		enemyModel[1] = Model("Enemy2", "models/Bandit/bandit2.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 1.0f);
		enemyModel[2] = Model("Enemy3", "models/Bandit/bandit3.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 1.0f);
		enemyModel[3] = Model("Enemy4", "models/Bandit/bandit4.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 1.0f);
		enemyModel[4] = Model("Enemy5", "models/Bandit/bandit5.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 1.0f);
		break;
	case EnemyType::EAGLE:
		animation = FrameAnimation(5, 0.4f);
		enemyModel[0] = Model("Enemy1", "models/Ave/ave1.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 2.0f);
		enemyModel[1] = Model("Enemy2", "models/Ave/ave2.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 2.0f);
		enemyModel[2] = Model("Enemy3", "models/Ave/ave3.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 2.0f);
		enemyModel[3] = Model("Enemy4", "models/Ave/ave4.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 2.0f);
		enemyModel[4] = Model("Enemy5", "models/Ave/ave5.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 2.0f);
		break;
	case EnemyType::RAT:
		animation = FrameAnimation(4, 0.4f);
		enemyModel[0] = Model("Enemy1", "models/Rata/rata1.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 2.0f);
		enemyModel[1] = Model("Enemy2", "models/Rata/rata2.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 2.0f);
		enemyModel[2] = Model("Enemy3", "models/Rata/rata3.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 2.0f);
		enemyModel[3] = Model("Enemy4", "models/Rata/rata4.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 2.0f);
		//enemyModel[4] = Model("Enemy5", "models/Ave/ave5.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 2.0f);
		break;
	}
	enemyHitbox = Hitbox(this->position, 0.6f);
}

Enemy::~Enemy()
{

}

void Enemy::UpdateEnemy(float deltaTime, glm::vec3 playerPos)
{
	if (distanceBetween(playerPos, this->spawn) < 7.5f)
	{
		moveTo(playerPos, deltaTime);
	}
	else
	{
		moveTo(this->spawn, deltaTime);
	}
	animation.UpdateAnimation(deltaTime);
	enemyModel[animation.getActualFrame()].setPosition(this->position);
	enemyModel[animation.getActualFrame()].setAngles(glm::vec3(0, this->rotAngle, 0));
	enemyHitbox.UpdateHitbox(this->position);
}

float distanceBetween(glm::vec3 positionA, glm::vec3 positionB)
{
	return sqrt(
		pow(positionA.x - positionB.x, 2) + 
		pow(positionA.z - positionB.z, 2)
	);
}

void Enemy::DrawEnemy(Shader shader)
{
	enemyModel[animation.getActualFrame()].Draw(shader);
}

Hitbox Enemy::getHitbox()
{
	return enemyHitbox;
}

void Enemy::moveTo(glm::vec3 coord, float deltaTime)
{
	if (distanceBetween(coord, this->position) > 0.5f)
	{
		glm::vec3 direction(0, 0, 0);
		direction.x = coord.x - this->position.x;
		direction.z = coord.z - this->position.z;
		float hyp = sqrt(pow(direction.x, 2) + pow(direction.z, 2));
		direction.x /= hyp;
		direction.z /= hyp;
		float speed = 0.5f;
		position.x += direction.x * speed * deltaTime;
		position.z += direction.z * speed * deltaTime;
		this->rotAngle = TO_DEG(atan2(direction.x, direction.z));
	}
}