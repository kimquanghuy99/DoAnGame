#include "XeVan.h"
CXeVan::CXeVan()
{
	SetState(XEVAN_STATE_WALKING);
}

void CXeVan::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + XEVAN_BBOX_WIDTH;

	if (state == XEVAN_STATE_DIE)
		bottom = y + XEVAN_BBOX_HEIGHT_DIE;
	else
		bottom = y + XEVAN_BBOX_HEIGHT;
}

void CXeVan::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);

	//
	// TO-DO: make sure XeVan can interact with the world and to each of them too!
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

void CXeVan::Render()
{
	int ani = XEVAN_ANI_WALKING;
	if (state == XEVAN_STATE_DIE) {
		ani = XEVAN_ANI_DIE;
	}

	animation_set->at(ani)->Render(x, y);

	//RenderBoundingBox();
}

void CXeVan::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case XEVAN_STATE_DIE:
		y += XEVAN_BBOX_HEIGHT - XEVAN_BBOX_HEIGHT_DIE + 1;
		vx = 0;
		vy = 0;
		break;
	case XEVAN_STATE_WALKING:
		vx = -XEVAN_WALKING_SPEED;
		vy = -XEVAN_WALKING_SPEED;

	}
}
