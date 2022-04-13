#pragma once
#include "GameObject.h"

#define FEET_WALKING_SPEED		0.15f 
//0.1f
#define FEET_JUMP_SPEED_Y		0.5f
#define FEET_JUMP_DEFLECT_SPEED 0.2f
#define FEET_GRAVITY			0.002f
#define FEET_DIE_DEFLECT_SPEED	 0.5f

#define FEET_STATE_DROP_LEFT		0
#define FEET_STATE_DROP_RIGHT		1
#define FEET_STATE_IDLE_LEFT		2
#define FEET_STATE_IDLE_RIGHT		3
#define FEET_STATE_WALKING_LEFT		4
#define FEET_STATE_WALKING_RIGHT	5

#define FEET_STATE_JUMP				6

#define FEET_STATE_DIE			7

#define FEET_ANI_DROP		0
#define FEET_ANI_IDLE		1

#define	FEET_LEVEL_SMALL	1
#define	FEET_LEVEL_BIG		2

#define FEET_BIG_BBOX_WIDTH  15
#define FEET_BIG_BBOX_HEIGHT 27

#define FEET_SMALL_BBOX_WIDTH  13
#define FEET_SMALL_BBOX_HEIGHT 15

class CFeet : public CGameObject
{
	static CFeet* __instance;
public:
	CFeet(float x = 0.0f, float y = 0.0f);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();

	void SetState(int state);

	void Reset();

	static CFeet* GetInstance();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};