#include "Ong.h"
COng::COng()
{
	SetState(ONG_STATE_WALKING);
}

void COng::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + ONG_BBOX_WIDTH;

	if (state == ONG_STATE_DIE)
		bottom = y + ONG_BBOX_HEIGHT_DIE;
	else
		bottom = y + ONG_BBOX_HEIGHT;
}

void COng::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);

	//
	// TO-DO: make sure Ong can interact with the world and to each of them too!
	// 

	/*x += dx;
	y += dy;

	if (vx < 0 && x < 0) {
		x = 0; vx = -vx;
	}

	if (vx > 0 && x > 290) {
		x = 290; vx = -vx;
	}
	if (vy < 0 && y < 0) {
		y = 0; vy = -vy;
	}

	if (vy > 0 && y > 190) {
		y = 190; vy = -vy;
	}*/
}

void COng::Render()
{
	int ani = ONG_ANI_WALKING;
	if (state == ONG_STATE_DIE) {
		ani = ONG_ANI_DIE;
	}

	animation_set->at(ani)->Render(x, y);

	//RenderBoundingBox();
}

void COng::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case ONG_STATE_DIE:
		y += ONG_BBOX_HEIGHT - ONG_BBOX_HEIGHT_DIE + 1;
		vx = 0;
		vy = 0;
		break;
	case ONG_STATE_WALKING:
		vx = -ONG_WALKING_SPEED;
		vy = -ONG_WALKING_SPEED;

	}
}
