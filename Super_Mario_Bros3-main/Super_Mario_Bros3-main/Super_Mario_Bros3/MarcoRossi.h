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
#define MARCO_ROSSI_STATE_PARACHUTE				0
#define MARCO_ROSSI_STATE_STAND					1
#define MARCO_ROSSI_STATE_STAND_LEFT			2
#define MARCO_ROSSI_STATE_STAND_RIGHT			3

#define MARCO_ROSSI_STATE_NORMAL_MOVE_LEFT		4
#define MARCO_ROSSI_STATE_NORMAL_MOVE_RIGHT		5

#define MARCO_ROSSI_STATE_LOWER					6
#define MARCO_ROSSI_STATE_LOWER_LEFT			7
#define MARCO_ROSSI_STATE_LOWER_RIGHT			8
#define MARCO_ROSSI_STATE_LOWER_MOVE_LEFT		9
#define MARCO_ROSSI_STATE_LOWER_MOVE_RIGHT		10

#define MARCO_ROSSI_STATE_JUMP					11
#define MARCO_ROSSI_STATE_JUMP_LEFT				12
#define MARCO_ROSSI_STATE_JUMP_RIGHT			13


class CMarcoRossi : public CGameObject
{
	CBody* body;
	CFeet* feet;

	bool isShooting = false;
	int Jump = 0; //0 = no jump; 1 = jump; 2 = height-jump

	static CMarcoRossi* __instance;

	int level;
	int untouchable;
	DWORD firing_start;
	DWORD untouchable_start;

	bool isJumping = false;

	int dir = 0;

	bool isAimingUp;

	float start_x;			// initial position of SOPHIA at scene
	float start_y;

	bool isFiring = 0;
	bool isAlreadyFired = 0;
public:
	CMarcoRossi(float x = 0.0f, float y = 0.0f, int state = 1);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	
	void SetState(int state);
	int GetState() { return this->state; }

	void Shoot();
	bool isShoot() { return this->isShooting; }

	void SetNy(int _ny) { this->ny = _ny; }
	int GetNy() { return ny; }

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);

	CBody* GetBody() { return body; }
	CFeet* GetFeet() { return feet; }

	void StartFiring() { if (firing_start == 0) firing_start = GetTickCount(); }


	bool GetIsJumping() { return isJumping; }
	void SetIsJumping(bool value) { isJumping = value; }

	void SetisAimingUp(bool value) { isAimingUp = value; }
	bool GetisAimingUp() { return isAimingUp; }

	void SetisFiring(bool value) { isFiring = value; }
	bool GetisFiring() { return isFiring; }
	void SetisAlreadyFired(bool value) { isAlreadyFired = value; }
	bool GetisAlreadyFired() { return isAlreadyFired; }

	void UpdatePosition();
	static CMarcoRossi* GetInstance();
};