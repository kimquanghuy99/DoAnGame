#pragma once
#include "GameObject.h"
#include "Camera.h"

#define PARALLAX_ANI	0

class CParallax : public CGameObject
{
public:
	CParallax();
	CParallax(float start_x, float start_y);
	void Render();
	void SetPosition(float cam_x);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};