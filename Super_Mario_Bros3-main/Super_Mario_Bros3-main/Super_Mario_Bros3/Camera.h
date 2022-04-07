#pragma once
#include "define.h"

#define CAMERA_STATE_IDLE	0
#define CAMERA_STATE_MOVE_LEFT	1
#define CAMERA_STATE_MOVE_RIGHT	2

class CCamera
{
	static CCamera* __instance;

	float cam_x; //position of camera at present
	float cam_y; //position of camera at present

	float boundary_right;
	float boundary_top;

	float last_cam_x; //position of camera at the past - TO DO PARALLAX
	float last_cam_y; //position of camera at the past - TO DO PARALLAX
public:
	CCamera();
	CCamera(float start_x, float start_y);

	void SetCamPos(float x, float y); //update camera follow player
	void SetBoundary(float w, float h);

	float GetCamPosX() { return cam_x; }
	float GetCamPosY() { return cam_y; }

	~CCamera();
};
