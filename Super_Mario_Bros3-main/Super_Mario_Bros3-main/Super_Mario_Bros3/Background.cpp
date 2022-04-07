#include "Background.h"

CBackground::CBackground(float x, float y, int w)
{
	x = x;
	y = y;
	width = w;
	height = y;
}
void CBackground::Render()
{
	animation_set->at(0)->Render(x, y);
	RenderBoundingBox();
}

void CBackground::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + width;
	b = y + height;
}

int CBackground::GetBackgroundWidth()
{
	return width;
}

int CBackground::GetBackgroundHeight()
{
	return height;
}