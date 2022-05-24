#include "Enemy.h"

Enemy::Enemy()
{
	chasingPlayer = false;

}

Enemy::Enemy(glm::vec3 spawn, int totalFrames, float switchTime)
{
	this->spawn = spawn;
	this->position = spawn;
	chasingPlayer = false;
	animation = FrameAnimation(totalFrames, switchTime);
	//houseModel = Model("Build", "models/casa/casa1.obj", ubication, glm::vec3(0, 90, 0), 0.0f, 1.0f);
	enemyModel[0] = Model("Enemy1", "models/Bandido/bandido1.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 1.0f);
	enemyModel[1] = Model("Enemy2", "models/Bandido/bandido2.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 1.0f);
	enemyModel[2] = Model("Enemy3", "models/Bandido/bandido3.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 1.0f);
	enemyModel[3] = Model("Enemy4", "models/Bandido/bandido4.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 1.0f);
	enemyModel[4] = Model("Enemy5", "models/Bandido/bandido5.obj", spawn, glm::vec3(0, 90, 0), 0.0f, 1.0f);
}

Enemy::~Enemy()
{

}

void Enemy::UpdateEnemy(float deltaTime, glm::vec3 playerPos)
{
	animation.UpdateAnimation(deltaTime);

}

void Enemy::DrawEnemy(Shader shader)
{
	enemyModel[animation.getActualFrame()].Draw(shader);
}

void Enemy::moveTo(glm::vec3 coord, float deltaTime)
{
	glm::vec3 direction;
	direction.x = coord.x - this->position.x;
	direction.z = coord.z - this->position.z;
	float hyp = sqrt(pow(direction.x, 2) + pow(direction.z, 2));
	direction.x /= hyp;
	direction.z /= hyp;
	float speed = 0.5f;
	position.x += direction.x * speed * deltaTime;
	position.z += direction.z * speed * deltaTime;
	//rotAngle = atan2(direciton.x, direction.z) + 100 /PI;
}