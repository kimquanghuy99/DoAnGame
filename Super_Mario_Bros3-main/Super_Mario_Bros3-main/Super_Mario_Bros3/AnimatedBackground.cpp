#include "AnimatedBackground.h"

CAnimatedBackground::CAnimatedBackground(float x, float y, int type)
{
	this->type = type;
}

void CAnimatedBackground::Render()
{
	animation_set->at(type)->Render(x, y, false);
}

void CAnimatedBackground::GetBoundingBox(float& l, float& t, float& r, float& b)
{

}

