#include "FrameAnimation.h"

FrameAnimation::FrameAnimation()
{

}

FrameAnimation::FrameAnimation(int _frames, float switchTime)
{
	this->frameCount = frameCount;
	this->switchTime = switchTime;
	actualFrame = 0;
	totalTime = 0.0f;
}

FrameAnimation::~FrameAnimation()
{

}

void FrameAnimation::UpdateAnimation(float deltaTime)
{
	totalTime += deltaTime;
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		actualFrame++;
		if (actualFrame >= frameCount)
		{
			actualFrame = 0;
		}
	}
}

int FrameAnimation::getActualFrame() { return actualFrame; }