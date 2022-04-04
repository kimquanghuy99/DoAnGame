#pragma once
#pragma once
#include "GameObject.h"

#define ONG_WALKING_SPEED 0.05f;

#define ONG_BBOX_WIDTH 16
#define ONG_BBOX_HEIGHT 15
#define ONG_BBOX_HEIGHT_DIE 9

#define ONG_STATE_WALKING 100
#define ONG_STATE_DIE 200

#define ONG_ANI_WALKING 0
#define ONG_ANI_DIE 1

class COng : public CGameObject
{
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

public:
	COng();
	virtual void SetState(int state);
};