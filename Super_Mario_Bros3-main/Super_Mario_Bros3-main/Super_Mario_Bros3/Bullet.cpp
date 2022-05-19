#include "Bullet.h"


CBullet::CBullet(float x, float y)
{
	this->x = x;
	this->y = y;

	SetState(BULLET_STATE_WALKING);
}
CBullet::CBullet()
{
	SetState(BULLET_STATE_WALKING);
}

void CBullet::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + BULLET_BBOX_WIDTH;

	if (state == BULLET_STATE_DIE)
		bottom = y + BULLET_BBOX_HEIGHT_DIE;
	else
		bottom = y + BULLET_BBOX_HEIGHT;
}

void CBullet::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);

	//
	// TO-DO: make sure Goomba can interact with the world and to each of them too!
	// 
	/*if (vy < 0 && y < 0) {
		y = 0; vy = -vy;
	}

	if (vy > 0 && y > 190) {
		y = 190; vy = -vy;
	}*/
}

void CBullet::Render()
{
	int ani = BULLET_ANI_WALKING;
	
	DebugOut(L"Render");
	animation_set->at(ani)->Render(x, y, true);

	RenderBoundingBox();
}

void CBullet::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case BULLET_STATE_DIE:
		x = 0;
		y = 50;
		//y += GOOMBA_BBOX_HEIGHT - GOOMBA_BBOX_HEIGHT_DIE + 1;
		vx = 0;
		vy = 0;
		break;
	case BULLET_STATE_WALKING:
		vx = 0;// BULLET_WALKING_SPEED;
		vy = 0;
		break;
	}
}
