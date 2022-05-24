#ifndef WATER_H
#define WATER_H
#include <engine/model.h>

class Water
{
public:
	Water();
	~Water();
	void UpdateWater(float deltaTime);
	void DrawWater(Shader _shaer);
private:

public:
	
private:
	float grades;
	float height;
	Model waterModel;
};
#endif
