#include "Parallax.h"

CParallax::CParallax()
{
}

CParallax::CParallax(float start_x, float start_y) 
{
	this->x = start_x;
	this->y = start_y;
}

void CParallax::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{

}

void CParallax::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);
	CCamera* cam = CCamera::GetInstance();
	SetPosition(cam->GetCamPosX());
}

void CParallax::Render()
{
	animation_set->at(0)->Render(x, y);
}

void CParallax::SetPosition(float cam_x)
{
	this->x = cam_x/ 2;
}
