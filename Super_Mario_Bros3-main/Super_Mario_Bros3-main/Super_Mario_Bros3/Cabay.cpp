#include "Cabay.h"
CCabay::CCabay()
{
	SetState(CABAY_STATE_WALKING);
}

void CCabay::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + CABAY_BBOX_WIDTH;

	if (state == CABAY_STATE_DIE)
		bottom = y + CABAY_BBOX_HEIGHT_DIE;
	else
		bottom = y + CABAY_BBOX_HEIGHT;
}

void CCabay::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);

	//
	// TO-DO: make sure Cabay can interact with the world and to each of them too!
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

void CCabay::Render()
{
	int ani = CABAY_ANI_WALKING;
	if (state == CABAY_STATE_DIE) {
		ani = CABAY_ANI_DIE;
	}

	animation_set->at(ani)->Render(x, y);

	//RenderBoundingBox();
}

void CCabay::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case CABAY_STATE_DIE:
		y += CABAY_BBOX_HEIGHT - CABAY_BBOX_HEIGHT_DIE + 1;
		vx = 0;
		vy = 0;
		break;
	case CABAY_STATE_WALKING:
		vx = -CABAY_WALKING_SPEED;
		vy = -CABAY_WALKING_SPEED;

	}
}
