#pragma once
#include "Scene.h"

using namespace std;

class CCamera
{
	static CCamera* __instance;
public:

	float cam_x = 50.0f;
	float cam_y = 100.0f;

	int screen_width;
	int screen_height;

	float boundary_top;
	float boundary_right;

	int GetScreenWidth() { return screen_width; }
	int GetScreenHeight() { return screen_height; }

	void SetCamPos(float x, float y)
	{
		cam_x = x - screen_width / 2;
		cam_y = y + screen_height / 2;
	}

	~CCamera();
};


