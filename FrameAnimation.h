#pragma once
class FrameAnimation
{
	//Methods
public:
	FrameAnimation(int _frames, float _duration);
	~FrameAnimation();
	int UpdateAnimation(float _deltaTime);
private:
	//Attributes
public:
private:
	int frame;
	int actualFrame;
	float duration;
};

