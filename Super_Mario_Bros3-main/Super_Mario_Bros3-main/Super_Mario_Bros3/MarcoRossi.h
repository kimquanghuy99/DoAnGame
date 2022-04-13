#pragma once
#include "GameObject.h"
#include "Body.h"
#include "Feet.h"

//speed
#define MARCO_ROSSI_WALKING_SPEED		0.15f
#define MARCO_ROSSI_JUMP_SPEED_Y		0.5f
#define MARCO_ROSSI_JUMP_DEFLECT_SPEED 0.2f
#define MARCO_ROSSI_GRAVITY			0.002f

#define MARCO_ROSSI_STATE_PARACHUTE		0
#define MARCO_ROSSI_DROP_LEFT	1
#define MARCO_ROSSI_DROP_RIGHT	2
#define MARCO_ROSSI_IDLE_LEFT	3
#define MARCO_ROSSI_IDLE_RIGHT	4
#define MARCO_ROSSI_WALKING_LEFT	5
#define MARCO_ROSSI_WALKING_RIGHT	6

#define MARCO_ROSSI_STATE_JUMP		7

class CMarcoRossi : public CGameObject
{
	CBody* body;
	CFeet* feet;
	static CMarcoRossi* __instance;
public:
	CMarcoRossi(float x = 0.0f, float y = 0.0f, int state = 1);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);

	void SetBodyPosition(float x, float y);
	void SetFeetPosition(float x, float y);

	//int GetBodyHeight();
	//void SetFeetPosition(float x, float y);
	//void SetBodyPosition(float x, float y);

	static CMarcoRossi* GetInstance();
};