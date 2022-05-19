#include <algorithm>
#include <assert.h>
#include "Utils.h"

#include "MarcoRossi.h"
#include "Game.h"
#include "PlayScene.h"

#include "Goomba.h"
#include "Portal.h"

CMarcoRossi* CMarcoRossi::__instance = NULL;

CMarcoRossi::CMarcoRossi(float x, float y, int state) : CGameObject()
{
	this->x = x;
	this->y = y;

	this->body = new CBody(x, y);
	this->feet = new CFeet(x, y);

	SetState(state);
	__instance = this;
}

void CMarcoRossi::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt);
	// Simple fall down
	//vy += MARCO_ROSSI_GRAVITY * dt;


	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	// turn off collision when die 
	//if (state != BODY_STATE_DIE)
		CalcPotentialCollisions(coObjects, coEvents);

	// No collision occured, proceed normally
	if (coEvents.size() == 0)
	{
		x += dx;
		y += dy;
		UpdatePosition();
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;
		float rdx = 0;
		float rdy = 0;

		// TODO: This is a very ugly designed function!!!!
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny, rdx, rdy);

		// how to push back Mario if collides with a moving objects, what if Mario is pushed this way into another object?
		//if (rdx != 0 && rdx!=dx)
		//	x += nx*abs(rdx); 

		// block every object first!
		x += min_tx * dx + nx * 0.4f;
		y += min_ty * dy + ny * 0.4f;

		if (nx != 0) vx = 0;
		if (ny != 0) vy = 0;


		//
		// Collision logic with other objects
		//
		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];

			if (dynamic_cast<CGoomba*>(e->obj)) // if e->obj is Goomba 
			{
				CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);

				// jump on top >> kill Goomba and deflect a bit 
				if (e->nx!=0)
				{
					if (goomba->GetState() != GOOMBA_STATE_DIE)
					{
						goomba->SetState(GOOMBA_STATE_DIE);
					}
				}
				else if (e->nx != 0)
				{
					
				}
			} // if Goomba
			else if (dynamic_cast<CPortal*>(e->obj))
			{
				CPortal* p = dynamic_cast<CPortal*>(e->obj);
				CGame::GetInstance()->SwitchScene(p->GetSceneId());
			}
		}
	}

	// clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

void CMarcoRossi::Render()
{
}

void CMarcoRossi::Shoot()
{
	isShooting = true;
	//CPlayScene* playscene = CPlayScene::GetInstance();
	/*
	switch (heightState)
	{
		case -1:
			if (faceState == 1)
				playscene->AddObject(x, y, OBJECT_TYPE_BULLET);
			else
				if (faceState == 2)
					playscene->AddObject(x, y, OBJECT_TYPE_BULLET);
				else
					playscene->AddObject(x, y, OBJECT_TYPE_BULLET);
			break;
		default:
			if (faceState == 1)
				playscene->AddObject(x, y, OBJECT_TYPE_BULLET);
			else
				if (faceState == 2)
					playscene->AddObject(x, y, OBJECT_TYPE_BULLET);
				else
					playscene->AddObject(x, y, OBJECT_TYPE_BULLET);
			break;
		}
	}
	*/
}

void CMarcoRossi::SetState(int state)
{
	CGameObject::SetState(state);

	switch (state)
	{
	case MARCO_ROSSI_STATE_PARACHUTE:
		vx = 0; //???
		vy = MARCO_ROSSI_GRAVITY;
		nx = 1;
		ny = 0;
		break;
	case MARCO_ROSSI_STATE_STAND_LEFT:
		body->SetState(BODY_STATE_IDLE_LEFT);
		feet->SetState(FEET_STATE_IDLE_LEFT);
		vx = 0;
		vy = 0;
		nx = -1;
		ny = 0;
		break;
	case MARCO_ROSSI_STATE_STAND_RIGHT:
		body->SetState(BODY_STATE_IDLE_RIGHT);
		feet->SetState(FEET_STATE_IDLE_RIGHT);
		vx = 0;
		vy = 0;
		ny = 0;
		break;
	case MARCO_ROSSI_STATE_NORMAL_MOVE_LEFT:
		body->SetState(BODY_STATE_WALKING_LEFT);
		feet->SetState(FEET_STATE_WALKING_LEFT);
		vx = -MARCO_ROSSI_WALKING_SPEED;
		nx = -1;
		ny = 0;
		break;
	case MARCO_ROSSI_STATE_NORMAL_MOVE_RIGHT:
		body->SetState(BODY_STATE_WALKING_RIGHT);
		feet->SetState(FEET_STATE_WALKING_RIGHT);
		vx = MARCO_ROSSI_WALKING_SPEED;
		nx = 1;
		ny = 0;
		break;
	}
}

void CMarcoRossi::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;

	
	right = x + 20;
		bottom = y + 29;
	
}

void CMarcoRossi::UpdatePosition()
{
	body->SetPosition(x, y);
	switch (state)
	{
	case MARCO_ROSSI_STATE_PARACHUTE:
		break;
	case MARCO_ROSSI_STATE_STAND_LEFT:
		feet->SetPosition(x + 9, y - 20);
		break;
	case MARCO_ROSSI_STATE_STAND_RIGHT:
		feet->SetPosition(x + 3, y - 20);
		break;
	case MARCO_ROSSI_STATE_NORMAL_MOVE_LEFT:
		feet->SetPosition(x + 9, y - 20);
		break;
	case MARCO_ROSSI_STATE_NORMAL_MOVE_RIGHT:
		feet->SetPosition(x + 3, y - 20);
		break;
	}
}

CMarcoRossi* CMarcoRossi::GetInstance()
{
	if (__instance == NULL) __instance = new CMarcoRossi();
	return __instance;
}