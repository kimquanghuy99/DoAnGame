#pragma once
#include "GameObject.h"

class CBackground: public CGameObject
{
	int width;
	int height;
public:
	CBackground(float x, float y, int w);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int GetBackgroundWidth();
	int GetBackgroundHeight();
};