#pragma once
#include "GameObject.h"
#include "define.h"
#include "Camera.h"

#define PARALLAX_STATE_IDLE	0
#define PARALLAX_STATE_MOVE_LEFT	1
#define PARALLAX_STATE_MOVE_RIGHT	2

#define PARALLAX_ANI	0

class CParallax : public CGameObject
{
public:
	CParallax();
	CParallax(float start_x, float start_y);
	void Render();
	void SetState(int state);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};