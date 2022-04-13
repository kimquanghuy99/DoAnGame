#include <algorithm>
#include <assert.h>
#include "Utils.h"

#include "Feet.h"
#include "Game.h"

#include "Goomba.h"
#include "Portal.h"

CFeet* CFeet::__instance = NULL;

CFeet::CFeet(float x, float y) : CGameObject()
{
	this->x = x;
	this->y = y;
}

void CFeet::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	// Calculate dx, dy 
	CGameObject::Update(dt);

	// Simple fall down
	//vy += FEET_GRAVITY * dt;

	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	// turn off collision when die 
	if (state != FEET_STATE_DIE)
		CalcPotentialCollisions(coObjects, coEvents);

	// No collision occured, proceed normally
	if (coEvents.size() == 0)
	{
		x += dx;
		y += dy;
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
						vy = -FEET_JUMP_DEFLECT_SPEED;
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

void CFeet::Render()
{
	int ani = -1;
	switch (state)
	{
	case FEET_STATE_DROP_LEFT:
		ani = FEET_ANI_DROP;
		break;
	case FEET_STATE_DROP_RIGHT:
		ani = FEET_ANI_DROP;
		break;
	case FEET_STATE_IDLE_LEFT:
		ani = FEET_ANI_IDLE;
		break;
	case FEET_STATE_IDLE_RIGHT:
		ani = FEET_ANI_IDLE;
		break;
	case FEET_STATE_WALKING_LEFT:
		ani = FEET_ANI_IDLE;
		break;
	case FEET_STATE_WALKING_RIGHT:
		ani = FEET_ANI_IDLE;
		break;

	}
	int alpha = 255;

	animation_set->at(ani)->Render(x, y, nx > 0 ? false : true, alpha);

	//RenderBoundingBox();
}

void CFeet::SetState(int state)
{
	CGameObject::SetState(state);

	switch (state)
	{
	case FEET_STATE_DROP_LEFT:
		vy = -FEET_GRAVITY;
		vx = 0;
		nx = -1;
		break;
	case FEET_STATE_DROP_RIGHT:
		vy = -FEET_GRAVITY;
		vx = 0;
		nx = 1;
		break;
	case FEET_STATE_IDLE_LEFT:
		vx = 0;
		vy = 0;
		nx = -1;
		break;
	case FEET_STATE_IDLE_RIGHT:
		nx = 1;
		vx = 0;
		vy = 0;
		break;
	case FEET_STATE_WALKING_LEFT:
		vx = -FEET_WALKING_SPEED;
		vy = 0;
		nx = -1;
		break;
	case FEET_STATE_WALKING_RIGHT:
		vx = FEET_WALKING_SPEED;
		vy = 0;
		nx = 1;
		break;
	}
}

void CFeet::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	/*left = x;
	top = y;

	if (level == FEET_LEVEL_BIG)
	{
		right = x + FEET_BIG_BBOX_WIDTH;
		bottom = y + FEET_BIG_BBOX_HEIGHT;
	}
	else
	{
		right = x + FEET_SMALL_BBOX_WIDTH;
		bottom = y + FEET_SMALL_BBOX_HEIGHT;
	}*/
}

/*
	Reset Mario status to the beginning state of a scene
*/
void CFeet::Reset()
{
	SetState(FEET_STATE_IDLE_RIGHT);
	//SetPosition(start_x, start_y);
	SetSpeed(0, 0);
}

CFeet* CFeet::GetInstance()
{
	if (__instance == NULL) __instance = new CFeet();
	return __instance;
}