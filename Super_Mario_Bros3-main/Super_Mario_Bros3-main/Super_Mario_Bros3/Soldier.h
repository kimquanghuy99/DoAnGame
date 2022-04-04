#pragma once
#pragma once
#include "GameObject.h"

#define SOLDIER_WALKING_SPEED 0.05f;

#define SOLDIER_BBOX_WIDTH 16
#define SOLDIER_BBOX_HEIGHT 15
#define SOLDIER_BBOX_HEIGHT_DIE 9

#define SOLDIER_STATE_WALKING 100
#define SOLDIER_STATE_DIE 200

#define SOLDIER_ANI_WALKING 0
#define SOLDIER_ANI_DIE 1

class CSoldier : public CGameObject
{
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

public:
	CSoldier();
	virtual void SetState(int state);
};