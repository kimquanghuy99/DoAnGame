#pragma once
#pragma once
#include "GameObject.h"

#define CUACAM_WALKING_SPEED 0.05f;

#define CUACAM_BBOX_WIDTH 16
#define CUACAM_BBOX_HEIGHT 15
#define CUACAM_BBOX_HEIGHT_DIE 9

#define CUACAM_STATE_WALKING 100
#define CUACAM_STATE_DIE 200

#define CUACAM_ANI_WALKING 0
#define CUACAM_ANI_DIE 1

class CCuaCam : public CGameObject
{
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

public:
	CCuaCam();
	virtual void SetState(int state);
};