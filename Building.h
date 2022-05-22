#pragma once
#include <engine/model.h>
class Building
{
//Methods
public:
	Building(glm::vec3 ubication);
	~Building();
	void Draw(Shader shader, glm::mat4 view, glm::mat4 projection);
	void Release();
	glm::vec3 getPosition();
private:

//Atributes
public:

private:
	Model houseModel;
	glm::vec3 position;
};