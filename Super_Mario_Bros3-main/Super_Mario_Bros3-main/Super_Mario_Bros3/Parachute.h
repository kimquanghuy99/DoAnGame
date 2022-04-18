#pragma once
#pragma once
#include "GameObject.h"

#define PARACHUTE_WALKING_SPEED 0.15f;

#define PARACHUTE_BBOX_WIDTH 16
#define PARACHUTE_BBOX_HEIGHT 15
#define PARACHUTE_BBOX_HEIGHT_DIE 9

#define PARACHUTE_STATE_IDLE 100
#define PARACHUTE_STATE_DROP 200

#define PARACHUTE_ANI_IDLE 0
#define PARACHUTE_ANI_DROP 1
#define PARACHUTE_ANI_WALKING_RIGHT 2


class CParachute : public CGameObject
{
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

public:
	CParachute();
	virtual void SetState(int state);
};