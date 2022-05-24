#ifndef BUILDING_H
#define BUILDING_H
#include <engine/model.h>
class Building
{
//Methods
public:
	Building();
	Building(glm::vec3 ubication);
	~Building();
	void DrawBuilding(Shader shader);
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
#endif