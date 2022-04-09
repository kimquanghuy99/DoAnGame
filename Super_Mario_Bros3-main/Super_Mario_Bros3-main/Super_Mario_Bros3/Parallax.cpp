#include "Parallax.h"

CParallax::CParallax()
{
	SetState(PARALLAX_STATE_IDLE);
}

CParallax::CParallax(float start_x, float start_y)
{
	this->x = start_x;
	this->y = start_y;
	SetState(PARALLAX_STATE_IDLE);
}

void CParallax::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{

}

void CParallax::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);
	/*
	x += dx;
	y += dy;

	if (vx < 0 && x < 0) {
		x = 0; vx = -vx;
	}
	*/
	
	/*if (vy < 0 && y < 0) {
		y = 0; vy = -vy;
	}

	if (vy > 0 && y > 190) {
		y = 190; vy = -vy;
	}*/
}

void CParallax::Render()
{
	animation_set->at(0)->Render(x, y);
}

void CParallax::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case PARALLAX_STATE_IDLE:
		break;
	case PARALLAX_STATE_MOVE_LEFT:
		
		break;
	case PARALLAX_STATE_MOVE_RIGHT:

		break;
	}
}
