#pragma once
#include "GameObject.h"

#define BODY_STATE_DROP_LEFT		0
#define BODY_STATE_DROP_RIGHT		1
#define BODY_STATE_IDLE_LEFT		2
#define BODY_STATE_IDLE_RIGHT		3
#define BODY_STATE_WALKING_LEFT		4
#define BODY_STATE_WALKING_RIGHT	5
#define BODY_STATE_JUMP				6
#define BODY_STATE_SHOOT_LEFT		7
#define BODY_STATE_SHOOT_RIGHT		8
#define BODY_STATE_SHOOT_UP			9
#define BODY_STATE_SHOOT_DOWN		10

#define BODY_ANI_DROP			0
#define BODY_ANI_IDLE			1
#define BODY_ANI_WALK			2
#define BODY_ANI_THROW			3
#define BODY_ANI_JUMP			4
#define BODY_ANI_SHOOT_RIGHT	5
#define BODY_ANI_SHOOT_DOWN		6
#define BODY_ANI_SHOOT_UP		7


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