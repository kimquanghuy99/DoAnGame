#pragma once
#include "GameObject.h"

#define BULLET_WALKING_SPEED 0.05f;

#define BULLET_BBOX_WIDTH 16
#define BULLET_BBOX_HEIGHT 15
#define BULLET_BBOX_HEIGHT_DIE 9

#define BULLET_STATE_WALKING 100
#define BULLET_STATE_DIE 200

#define BULLET_ANI_WALKING 0
#define BULLET_ANI_DIE 1
#define BULLET_ANI_WALKING_RIGHT 2


class CBullet : public CGameObject
{
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

public:
	CBullet();
	CBullet(float x, float y);

	virtual void SetState(int state);
};