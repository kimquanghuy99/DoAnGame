#pragma once
#include "GameObject.h"

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

class CBody : public CGameObject
{
	int height;
	static CBody* __instance;
public:
	CBody(float x = 0.0f, float y = 0.0f);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	void SetPosition(float x, float y);
	void SetState(int state);
	int GetHeight() { 
		return this->height; 
		DebugOut(L"height: ", height);
	}
	static CBody* GetInstance();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};