#include "AnimatedBackground.h"

CAnimatedBackground::CAnimatedBackground(float x, float y, int type, int state)
{
	this->type = type;
	this->state = state;
}

void CAnimatedBackground::Render()
{
	if(state == STATE_IDLE)
		animation_set->at(type)->Render(x, y);
	//RenderBoundingBox();
}

void CAnimatedBackground::SetState(int state)
{
	CGameObject::SetState(state);
	switch (type)
	{
		case WAVE_EFFECT_1:
			switch(state)
			{
				case 1:
					break;
			}
		break;
		case WAVE_EFFECT_2:
			switch (state)
			{
			case 1:
				break;
			}
			break;
	}
}


void CAnimatedBackground::GetBoundingBox(float& l, float& t, float& r, float& b)
{

}

