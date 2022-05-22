#include "Water.h"

Water::Water()
{
	waterModel = Model(
		"Water", "models/Water/water.obj",
		glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0, 90, 0),
		0.0f, 3.98f);
	grades = 0.0f;
	height = 0.0f;
}

Water::~Water()
{

}

void Water::UpdateWater(float deltaTime)
{
	grades < 180 ? grades += 0.5f * deltaTime : grades = 0;
	height = sin(grades) - 1.5f;
	waterModel.setPosition(glm::vec3(0, height, 0));
}
void Water::DrawWater(Shader _shader)
{
	waterModel.Draw(_shader);
}