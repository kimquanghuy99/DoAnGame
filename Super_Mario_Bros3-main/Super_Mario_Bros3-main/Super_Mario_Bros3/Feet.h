#pragma once
#include "GameObject.h"

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
#define FEET_ANI_JUMP_CLOSE 2

class CFeet : public CGameObject
{
	static CFeet* __instance;
public:
	CFeet(float x = 0.0f, float y = 0.0f);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	void SetPosition(float x, float y);
	void SetState(int state);

	static CFeet* GetInstance();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};