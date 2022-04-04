#pragma once
#pragma once
#include "GameObject.h"

#define CABAY_WALKING_SPEED 0.05f;

#define CABAY_BBOX_WIDTH 16
#define CABAY_BBOX_HEIGHT 15
#define CABAY_BBOX_HEIGHT_DIE 9

#define CABAY_STATE_WALKING 100
#define CABAY_STATE_DIE 200

#define CABAY_ANI_WALKING 0
#define CABAY_ANI_DIE 1

class CCabay : public CGameObject
{
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

public:
	CCabay();
	virtual void SetState(int state);
};