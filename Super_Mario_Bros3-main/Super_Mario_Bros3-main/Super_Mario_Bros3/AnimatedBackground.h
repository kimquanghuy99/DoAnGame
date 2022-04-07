#pragma once
#include "GameObject.h"
#include "define.h"

class CAnimatedBackground : public CGameObject
{
	int type;
public:
	CAnimatedBackground(float x, float y, int type, int state);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void SetState(int state);
};