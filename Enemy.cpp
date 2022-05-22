#include "Enemy.h"

//Enemy::Enemy()
//{
//
//}

Enemy::Enemy(glm::vec3 spawn)
{
	this->spawn = spawn;
	this->position = spawn;
	chasingPlayer = false;
	animation = FrameAnimation(5, 1.2f);
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

void Enemy::UpdateEnemy(float _dt, glm::vec3 playerPos)
{
	animation.UpdateAnimation(_dt);
}

void Enemy::DrawEnemy(Shader _shader)
{

}

void Enemy::moveTo(glm::vec3 coord, float _dt)
{
	glm::vec3 direction;
	direction.x = coord.x - this->position.x;
	direction.z = coord.z - this->position.z;
	float hyp = sqrt(pow(direction.x, 2) + pow(direction.z, 2));
	direction.x /= hyp;
	direction.z /= hyp;
	float speed = 0.5f;
	position.x += direction.x * speed * _dt;
	position.z += direction.z * speed * _dt;
	//rotAngle = atan2(direciton.x, direction.z) + 100 /PI;
}