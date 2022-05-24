#pragma once
#include <engine/model.h>
class Building
{
//Methods
public:
	Building();
	Building(glm::vec3 ubication);
	~Building();
	void Draw(Shader shader, glm::mat4 view, glm::mat4 projection);
	void Release();
	glm::vec3 getPosition();

private:

//Atributes
public:

private:
	glm::vec3 position;
protected:
	Model houseModel;
};