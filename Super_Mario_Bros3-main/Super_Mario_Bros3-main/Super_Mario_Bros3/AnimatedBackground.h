#pragma once
#include "GameObject.h"

class CAnimatedBackground : public CGameObject
{
	int type;
public:
	CAnimatedBackground(float x, float y, int type);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};