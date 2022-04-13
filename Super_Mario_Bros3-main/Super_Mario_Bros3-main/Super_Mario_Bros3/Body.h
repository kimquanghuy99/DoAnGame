#pragma once
#include "GameObject.h"

#define BODY_WALKING_SPEED		0.15f 
//0.1f
#define BODY_JUMP_SPEED_Y		0.5f
#define BODY_JUMP_DEFLECT_SPEED 0.2f
#define BODY_GRAVITY			0.002f
#define BODY_DIE_DEFLECT_SPEED	 0.5f

#define BODY_STATE_DROP_LEFT		0
#define BODY_STATE_DROP_RIGHT		1
#define BODY_STATE_IDLE_LEFT		2
#define BODY_STATE_IDLE_RIGHT		3
#define BODY_STATE_WALKING_LEFT		4
#define BODY_STATE_WALKING_RIGHT	5

#define BODY_STATE_JUMP				6

#define BODY_STATE_DIE			7

#define BODY_ANI_DROP		0
#define BODY_ANI_IDLE		1

#define	BODY_LEVEL_SMALL	1
#define	BODY_LEVEL_BIG		2

#define BODY_BIG_BBOX_WIDTH  15
#define BODY_BIG_BBOX_HEIGHT 27

class CBody : public CGameObject
{
	static CBody* __instance;
public:
	CBody(float x = 0.0f, float y = 0.0f);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	void SetPosition(float x, float y);
	void SetState(int state);

	static CBody* GetInstance();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};