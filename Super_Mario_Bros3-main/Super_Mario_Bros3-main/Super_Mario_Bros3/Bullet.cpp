#include "Bullet.h"
#include <algorithm>
#include "PlayScene.h"
#include "MarcoRossi.h"

BULLET::BULLET()
{
	SetState(BULLET_STATE_FLYING);
	nx = 0;
}

//void BULLET::GetBoundingBox(float& left, float& top, float& right, float& bottom)
//{
	//if (state != BULLET_STATE_DIE) {
	//	left = x;
	//	top = y;
	//	right = x + BULLET_BBOX_WIDTH;
	//	bottom = y + BULLET_BBOX_HEIGHT;
	//}
//}

void BULLET::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if ((DWORD)GetTickCount64() - reset_start > BULLET_RESET_TIME)
	{
		state = BULLET_STATE_DIE;
		reset_start = 0;
	}
	CGameObject::Update(dt, coObjects);
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	// turn off collision when die 
	if (state != BULLET_STATE_DIE)
		CalcPotentialCollisions(coObjects, coEvents);
	else
	{
		isUsed = false;
		x = STORING_LOCATION;
		y = STORING_LOCATION;
		SetState(BULLET_STATE_FLYING);
	}
	if (isUsed == false)
	{
		CMarcoRossi* player = ((CPlayScene*)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
		if (player->GetisFiring() == true)
		{
			if (player->GetisAlreadyFired() == false)
			{
				isUsed = true;
				x = player->x;
				y = player->y - 20;
				if (player->GetisAimingUp())
				{
					//x = x + PLAYER_BIG_BBOX_WIDTH / 3;
					//y = y - PLAYER_BIG_BBOX_HEIGHT;
				}
				if (player->GetisAimingUp())
				{
					SetSpeed(0, BULLET_SPEED);
				}
				else
				{
					SetSpeed(player->nx * BULLET_SPEED);
				}
				player->SetisAlreadyFired(true);
				player->StartFiring();
				StartReset();
				DebugOut(L"FIRED \n");
			}
		}
	}
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

		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];
			//if (!dynamic_cast<CBrick*>(e->obj))
			//{
			//	(e->obj)->setheath((e->obj)->Getheath() - SOPHIA_BULLET_DMG);
			//	//((CPlayScene*)CGame::GetInstance()->GetCurrentScene())->AddKaboomMng(e->obj->x, e->obj->y);
			//	SetState(CSOPHIA_BULLET_STATE_DIE);
			//}
			//else
			//{
			//	((CPlayScene*)CGame::GetInstance()->GetCurrentScene())->AddKaboomMng(x, y);
			//	SetState(CSOPHIA_BULLET_STATE_DIE);
			//}

		}
		// clean up collision events
		for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
	}
}

void BULLET::CalcPotentialCollisions(
	vector<LPGAMEOBJECT>* coObjects,
	vector<LPCOLLISIONEVENT>& coEvents)
{
	for (UINT i = 0; i < coObjects->size(); i++)
	{
		LPCOLLISIONEVENT e = SweptAABBEx(coObjects->at(i));
		if (dynamic_cast<CMarcoRossi*>(e->obj))
		{
			continue;
		}
		if (dynamic_cast<CGoomba*>(e->obj)) // if e->obj is Goomba 
		{
			CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);

			// jump on top >> kill Goomba and deflect a bit 
			if (e->nx != 0)
			{
				if (goomba->GetState() != GOOMBA_STATE_DIE)
				{
					goomba->SetState(GOOMBA_STATE_DIE);
				}
			}
			else if (e->nx != 0)
			{

			}
		}
		if (e->t > 0 && e->t <= 1.0f)
			coEvents.push_back(e);
		else
			delete e;
	}
	std::sort(coEvents.begin(), coEvents.end(), CCollisionEvent::compare);
}

void BULLET::Render()
{
	if (isUsed)
	{
		if (vx == 0 && vy == 0)
			return;
		else {
			int ani = -1;
			if (state == BULLET_STATE_DIE)
				return;
			switch (state)
			{
			case BULLET_STATE_FLYING:
				if (vy != 0)
					ani = 2;
				else
					if (vx > 0)
						ani = BULLET_ANI_FLYING_RIGHT;
					else
						if (vx < 0)
							ani = BULLET_ANI_FLYING_RIGHT;
				break;
			}
			if (ani != -1)
				animation_set->at(ani)->Render(x, y);
		}
		//RenderBoundingBox();
	}
}

void BULLET::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;


	right = x + 20;
	bottom = y + 29;

}

void BULLET::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case BULLET_STATE_DIE:
		vx = BULLET_STATE_DIE_SPEED;
		vy = BULLET_STATE_DIE_SPEED;
		break;

	}

}
