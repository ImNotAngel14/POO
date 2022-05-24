#pragma once
class FrameAnimation
{
	//Methods
public:
	FrameAnimation();
	FrameAnimation(int frameCount, float switchTime);
	~FrameAnimation();
	void UpdateAnimation(float deltaTime);
	int getActualFrame();
private:
	//Attributes
public:
private:
	int frameCount;
	int actualFrame;
	float switchTime;
	float totalTime;
};

