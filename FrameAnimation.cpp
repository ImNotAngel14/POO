#include "FrameAnimation.h"

FrameAnimation::FrameAnimation()
{

}

FrameAnimation::FrameAnimation(int _frames, float _duration)
{
	frame = _frames;
	duration = _duration;
	actualFrame = 0;
}

FrameAnimation::~FrameAnimation()
{

}

int FrameAnimation::UpdateAnimation(float _deltaTime)
{
	float frameDuration = duration / frame;
	if(_deltaTime > frameDuration)
	return actualFrame;
}