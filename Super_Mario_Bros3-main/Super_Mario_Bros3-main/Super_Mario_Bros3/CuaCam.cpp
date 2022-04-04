#include "CuaCam.h"
CCuaCam::CCuaCam()
{
	SetState(CUACAM_STATE_WALKING);
}

void CCuaCam::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + CUACAM_BBOX_WIDTH;

	if (state == CUACAM_STATE_DIE)
		bottom = y + CUACAM_BBOX_HEIGHT_DIE;
	else
		bottom = y + CUACAM_BBOX_HEIGHT;
}

void CCuaCam::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);

	//
	// TO-DO: make sure CuaCam can interact with the world and to each of them too!
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

void CCuaCam::Render()
{
	int ani = CUACAM_ANI_WALKING;
	if (state == CUACAM_STATE_DIE) {
		ani = CUACAM_ANI_DIE;
	}

	animation_set->at(ani)->Render(x, y);

	//RenderBoundingBox();
}

void CCuaCam::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case CUACAM_STATE_DIE:
		y += CUACAM_BBOX_HEIGHT - CUACAM_BBOX_HEIGHT_DIE + 1;
		vx = 0;
		vy = 0;
		break;
	case CUACAM_STATE_WALKING:
		vx = -CUACAM_WALKING_SPEED;
		vy = -CUACAM_WALKING_SPEED;

	}
}
