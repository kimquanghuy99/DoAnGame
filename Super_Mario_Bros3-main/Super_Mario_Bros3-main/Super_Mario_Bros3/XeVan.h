#pragma once
#include "GameObject.h"

#define XEVAN_WALKING_SPEED 0.05f;

#define XEVAN_BBOX_WIDTH 16
#define XEVAN_BBOX_HEIGHT 15
#define XEVAN_BBOX_HEIGHT_DIE 9

#define XEVAN_STATE_WALKING 100
#define XEVAN_STATE_DIE 200

#define XEVAN_ANI_WALKING 0
#define XEVAN_ANI_DIE 1

class CXeVan : public CGameObject
{
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

public:
	CXeVan();
	virtual void SetState(int state);
};