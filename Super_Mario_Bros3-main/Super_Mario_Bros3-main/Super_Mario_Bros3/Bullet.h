#pragma once
#include "GameObject.h"
#include "define.h"

class BULLET : public CGameObject
{
	DWORD reset_start;
	void StartReset() { reset_start = (DWORD)GetTickCount64(); }
	bool isUsed = false;
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
	void CalcPotentialCollisions(vector<LPGAMEOBJECT>* coObjects, vector<LPCOLLISIONEVENT>& coEvents);

public:
	BULLET();
	void SetisUsed(bool value) { isUsed = value; }
	bool GetisUsed() { return isUsed; }
	virtual void SetState(int state);
};