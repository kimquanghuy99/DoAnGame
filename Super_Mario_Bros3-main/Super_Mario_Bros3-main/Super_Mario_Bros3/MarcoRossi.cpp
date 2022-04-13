#include <algorithm>
#include <assert.h>
#include "Utils.h"

#include "MarcoRossi.h"
#include "Game.h"

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
	//vy += BODY_GRAVITY * dt;

	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	// turn off collision when die 
	if (state != BODY_STATE_DIE)
		CalcPotentialCollisions(coObjects, coEvents);

	// No collision occured, proceed normally
	if (coEvents.size() == 0)
	{
		x += dx;
		y += dy;
		body->SetPosition(x, y);
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
				if (e->ny < 0)
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
	//int ani = body->GetState();
	//body = CBody::GetInstance();
	//body->Render();
	//body->animation_set->at(1)->Render(x, y, false, 255);
	//animation_set->at(ani)->Render(x, y, nx > 0 ? false : true, alpha);
}

void CMarcoRossi::SetState(int state)
{
	CGameObject::SetState(state);

	switch (state)
	{
	case MARCO_ROSSI_STATE_PARACHUTE:
		body->SetState(BODY_STATE_IDLE_RIGHT);
		vy = MARCO_ROSSI_GRAVITY;
		vx = 0;
		nx = 1;
		break;
	case MARCO_ROSSI_STATE_IDLE_LEFT:
		body->SetState(BODY_STATE_IDLE_LEFT);
		vy = 0;
		vx = 0;
		nx = -1;
		break;
	case MARCO_ROSSI_STATE_IDLE_RIGHT:
		body->SetState(BODY_STATE_IDLE_RIGHT);
		vy = 0;
		vx = 0;
		nx = 1;
		break;
	case MARCO_ROSSI_STATE_WALKING_LEFT:
		body->SetState(BODY_STATE_IDLE_LEFT);
		vy = 0;
		vx = -MARCO_ROSSI_WALKING_SPEED;
		nx = -1;
		break;
	case MARCO_ROSSI_STATE_WALKING_RIGHT:
		body->SetState(BODY_STATE_IDLE_RIGHT);
		vy = 0;
		vx = MARCO_ROSSI_WALKING_SPEED;
		nx = 1;
		break;
	//case BODY_STATE_DROP_RIGHT:
	//	vy = -BODY_GRAVITY;
	//	vx = 0;
	//	nx = 1;
	//	break;
	//case BODY_STATE_IDLE_LEFT:
	//	vx = 0;
	//	vy = 0;
	//	nx = -1;
	//	break;
	//case BODY_STATE_IDLE_RIGHT:
	//	nx = 1;
	//	vx = 0;
	//	vy = 0;
	//	break;
	//case BODY_STATE_WALKING_LEFT:
	//	vx = -BODY_WALKING_SPEED;
	//	vy = 0;
	//	nx = -1;
	//	break;
	//case BODY_STATE_WALKING_RIGHT:
	//	vx = BODY_WALKING_SPEED;
	//	vy = 0;
	//	nx = 1;
	//	break;
	}
}

void CMarcoRossi::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	/*left = x;
	top = y;

	if (level == BODY_LEVEL_BIG)
	{
		right = x + BODY_BIG_BBOX_WIDTH;
		bottom = y + BODY_BIG_BBOX_HEIGHT;
	}
	else
	{
		right = x + BODY_SMALL_BBOX_WIDTH;
		bottom = y + BODY_SMALL_BBOX_HEIGHT;
	}*/
}

/*
	Reset Mario status to the beginning state of a scene
*/

CMarcoRossi* CMarcoRossi::GetInstance()
{
	if (__instance == NULL) __instance = new CMarcoRossi();
	return __instance;
}

CBody* CMarcoRossi::GetBody()
{
	//body = CBody::GetInstance();
	return body;
}