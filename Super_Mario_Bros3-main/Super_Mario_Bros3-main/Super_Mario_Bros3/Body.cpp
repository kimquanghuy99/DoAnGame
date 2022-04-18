#include <algorithm>
#include <assert.h>
#include "Utils.h"

#include "Body.h"
#include "Game.h"

#include "Goomba.h"
#include "Portal.h"

CBody* CBody::__instance = NULL;

CBody::CBody(float x, float y) : CGameObject()
{
	this->x = x;
	this->y = y;
	__instance = this;
}

void CBody::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt);
}

void CBody::Render()
{
	int ani = -1;
	switch (state)
	{
		case BODY_STATE_DROP_RIGHT:
			ani = BODY_ANI_DROP;
			break;
		case BODY_STATE_IDLE_LEFT:
			ani = BODY_ANI_IDLE;
			break;
		case BODY_STATE_IDLE_RIGHT:
			ani = BODY_ANI_IDLE;
			break;
		case BODY_STATE_WALKING_LEFT:
			ani = BODY_ANI_WALK;
			break;
		case BODY_STATE_WALKING_RIGHT:
			ani = BODY_ANI_WALK;
			break;
		case BODY_STATE_JUMP:
			ani = BODY_ANI_DROP;
			break;
		case BODY_STATE_SHOOT_LEFT:
			ani = BODY_ANI_DROP;
			break;
		case BODY_STATE_SHOOT_RIGHT:
			ani = BODY_ANI_DROP;
			break;
		case BODY_STATE_SHOOT_UP:
			ani = BODY_ANI_DROP;
			break;
		case BODY_STATE_SHOOT_DOWN:
			ani = BODY_ANI_DROP;
			break;
	}
	int alpha = 255;
	animation_set->at(ani)->Render(x, y, nx > 0? false:true, alpha);
}

void CBody::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case BODY_STATE_DROP_RIGHT:
		nx = 1;
		break;
	case BODY_STATE_IDLE_LEFT:
		nx = -1;
		break;
	case BODY_STATE_IDLE_RIGHT:
		nx = 1;
		break;
	case BODY_STATE_WALKING_LEFT:
		nx = -1;
		break;
	case BODY_STATE_WALKING_RIGHT:
		nx = 1;
		break;
	case BODY_STATE_JUMP:
		nx = 1;
		break;
	case BODY_STATE_SHOOT_LEFT:
		nx = -1;
		break;
	case BODY_STATE_SHOOT_RIGHT:
		nx = 1;
		break;
	case BODY_STATE_SHOOT_UP:
		nx = 1;
		break;
	case BODY_STATE_SHOOT_DOWN:
		nx = 1;
		break;
	}
}

void CBody::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void CBody::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}

CBody* CBody::GetInstance()
{
	if (__instance == NULL) __instance = new CBody();
	return __instance;
}
