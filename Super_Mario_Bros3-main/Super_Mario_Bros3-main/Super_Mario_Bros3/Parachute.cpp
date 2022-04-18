#include "Parachute.h"
CParachute::CParachute()
{
	SetState(PARACHUTE_STATE_IDLE);
}

void CParachute::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + PARACHUTE_BBOX_WIDTH;

	if (state == PARACHUTE_STATE_IDLE)
		bottom = y + PARACHUTE_BBOX_HEIGHT_DIE;
	else
		bottom = y + PARACHUTE_BBOX_HEIGHT;
}

void CParachute::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);
}

void CParachute::Render()
{
	int ani = PARACHUTE_ANI_IDLE;
	if (vx > 0)
	{
		ani = PARACHUTE_ANI_WALKING_RIGHT;
	}
	if (state == PARACHUTE_STATE_IDLE) {
		ani = PARACHUTE_ANI_IDLE;
	}

	animation_set->at(ani)->Render(x, y);

	//RenderBoundingBox();
}

void CParachute::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case PARACHUTE_STATE_IDLE:
		vx = 0;
		vy = 0;
		break;
	case PARACHUTE_STATE_DROP:
		vx = -PARACHUTE_WALKING_SPEED;
		break;
	}
}
