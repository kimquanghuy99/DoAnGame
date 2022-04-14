#pragma once
#include "GameObject.h"
#include "Body.h"
#include "Feet.h"

//speed
#define MARCO_ROSSI_WALKING_SPEED		0.15f
#define MARCO_ROSSI_JUMP_SPEED_Y		0.5f
#define MARCO_ROSSI_ACCELERATION_Y	0.02f
#define MARCO_ROSSI_GRAVITY			-0.002f

//state
#define MARCO_ROSSI_STATE_PARACHUTE		0
#define MARCO_ROSSI_STATE_IDLE_LEFT		1
#define MARCO_ROSSI_STATE_IDLE_RIGHT	2
#define MARCO_ROSSI_STATE_MOVE_LEFT		3
#define MARCO_ROSSI_STATE_MOVE_RIGHT	4

class CMarcoRossi : public CGameObject
{
	CBody* body;
	CFeet* feet;

	bool isShooting = false;

	int faceState = 0; //left & right = 0; up = 1; down = -1 
	int heightState = 0; //jumping = 1; normal = 0; lower = -1;

	static CMarcoRossi* __instance;
public:
	CMarcoRossi(float x = 0.0f, float y = 0.0f, int state = 1);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	
	void SetState(int state);
	int GetState() { return this->state; }

	void Shoot(bool _isShooting);
	bool isShoot() { return this->isShooting; }

	void SetFaceState(bool _isUp);

	void SetHeightState();
	int GetHeightState() { return this->heightState; }

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);

	CBody* GetBody() { return body; }
	CFeet* GetFeet() { return feet; }

	void UpdatePosition();
	static CMarcoRossi* GetInstance();
};