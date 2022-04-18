#include "Bullet.h"
#include <algorithm>
#include "PlayScene.h"
#include "MarcoRossi.h"
#include "Brick.h"

CTANKBULLET::CTANKBULLET()
{
	SetState(CSOPHIA_BULLET_STATE_FLYING);
	nx = 0;
}

void CTANKBULLET::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state != CSOPHIA_BULLET_STATE_DIE) {
		left = x;
		top = y;
		right = x + CSOPHIA_BULLET_BBOX_WIDTH;
		bottom = y + CSOPHIA_BULLET_BBOX_HEIGHT;
	}
}

void CTANKBULLET::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if ((DWORD)GetTickCount64() - reset_start > CSOPHIA_BULLET_RESET_TIME)
	{
		state = CSOPHIA_BULLET_STATE_DIE;
		reset_start = 0;
	}
	CGameObject::Update(dt, coObjects);
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	// turn off collision when die 
	if (state != CSOPHIA_BULLET_STATE_DIE)
		CalcPotentialCollisions(coObjects, coEvents);
	else
	{
		isUsed = false;
		x = STORING_LOCATION;
		y = STORING_LOCATION;
		SetState(CSOPHIA_BULLET_STATE_FLYING);
	}
	if (isUsed == false)
	{
		CMarcoRossi* CMarcoRossi = ((CPlayScene*)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
		if (CMarcoRossi->GetisFiring() == true)
		{
			if (CMarcoRossi->GetisAlreadyFired() == false)
			{
				isUsed = true;
				x = CMarcoRossi->x;
				y = CMarcoRossi->y;
				if (CMarcoRossi->GetisAimingUp())
				{
					x = x + SOPHIA_BIG_BBOX_WIDTH / 3;
					y = y - SOPHIA_BIG_BBOX_HEIGHT;
				}
				if (CMarcoRossi->GetisAimingUp())
				{
					SetSpeed(0, CSOPHIA_BULLET_SPEED);
				}
				else
				{
					SetSpeed(CMarcoRossi->nx * CSOPHIA_BULLET_SPEED);
				}
				CMarcoRossi->SetisAlreadyFired(true);
				CMarcoRossi->StartFiring();
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
			if (!dynamic_cast<CBrick*>(e->obj))
			{
				(e->obj)->setheath((e->obj)->Getheath() - SOPHIA_BULLET_DMG);
				//((CPlayScene*)CGame::GetInstance()->GetCurrentScene())->AddKaboomMng(e->obj->x, e->obj->y);
				SetState(CSOPHIA_BULLET_STATE_DIE);
			}
			else
			{
				((CPlayScene*)CGame::GetInstance()->GetCurrentScene())->AddKaboomMng(x, y);
				SetState(CSOPHIA_BULLET_STATE_DIE);
			}

		}
		// clean up collision events
		for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
	}
}

void CTANKBULLET::CalcPotentialCollisions(
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
		if (dynamic_cast<CMarcoRossi*>(e->obj))
		{
			continue;
		}
		if (dynamic_cast<CMarcoRossi*>(e->obj))
		{
			continue;
		}
		if (e->t > 0 && e->t <= 1.0f)
			coEvents.push_back(e);
		else
			delete e;
	}
	std::sort(coEvents.begin(), coEvents.end(), CCollisionEvent::compare);
}

void CTANKBULLET::Render()
{
	if (isUsed)
	{
		if (vx == 0 && vy == 0)
			return;
		else {
			int ani = -1;
			if (state == CSOPHIA_BULLET_STATE_DIE)
				return;
			switch (state)
			{
			case CSOPHIA_BULLET_STATE_FLYING:
				if (vy != 0)
					ani = 2;
				else
					if (vx > 0)
						ani = CSOPHIA_BULLET_ANI_FLYING_RIGHT;
					else
						if (vx < 0)
							ani = CSOPHIA_BULLET_ANI_FLYING_LEFT;
				break;
			}
			if (ani != -1)
				animation_set->at(ani)->Render(x, y);
		}
		//RenderBoundingBox();
	}
}

void CTANKBULLET::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case CSOPHIA_BULLET_STATE_DIE:
		vx = CSOPHIA_BULLET_STATE_DIE_SPEED;
		vy = CSOPHIA_BULLET_STATE_DIE_SPEED;
		break;

	}

}
