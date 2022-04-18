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
	__instance = this;
}

void CFeet::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt);
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
		ani = FEET_ANI_WALK;
		break;
	case FEET_STATE_WALKING_RIGHT:
		ani = FEET_ANI_WALK;
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
		nx = -1;
		break;
	case FEET_STATE_DROP_RIGHT:
		nx = 1;
		break;
	case FEET_STATE_IDLE_LEFT:
		nx = -1;
		break;
	case FEET_STATE_IDLE_RIGHT:
		nx = 1;
		break;
	case FEET_STATE_WALKING_LEFT:
		nx = -1;
		break;
	case FEET_STATE_WALKING_RIGHT:
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

void CFeet::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

CFeet* CFeet::GetInstance()
{
	if (__instance == NULL) __instance = new CFeet();
	return __instance;
}