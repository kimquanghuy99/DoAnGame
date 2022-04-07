//include all game object
#include "Background.h"
#include "AnimatedBackground.h"
#include "Parallax.h"
#include "Brick2.h"
#include "Mario.h"
#include "Goomba.h"
#include "Koopas.h"
#include "Portal.h"

//Screen
#define WINDOW_CLASS_NAME L"SampleWindow"
#define MAIN_WINDOW_TITLE L"METAL SLUG 3"

#define BACKGROUND_COLOR D3DCOLOR_XRGB(255, 255, 200)
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 260

#define MAX_FRAME_RATE 120

//scene section
#define SCENE_SECTION_UNKNOWN -1
#define SCENE_SECTION_TEXTURES 2
#define SCENE_SECTION_SPRITES 3
#define SCENE_SECTION_ANIMATIONS 4
#define SCENE_SECTION_ANIMATION_SETS	5
#define SCENE_SECTION_OBJECTS	6

//object id
#define OBJECT_TYPE_MARIO	0
#define OBJECT_TYPE_BRICK	1
#define OBJECT_TYPE_GOOMBA	2
#define OBJECT_TYPE_KOOPAS	3
#define OBJECT_TYPE_BRICK2	4
#define OBJECT_TYPE_BACKGROUND	36
#define OBJECT_TYPE_ANIMATED_BACKGROUND	39
#define OBJECT_TYPE_PARALLAX	42

#define OBJECT_TYPE_PORTAL	50

#define MAX_SCENE_LINE 1024

//animated background
#define STATE_IDLE	0
#define ANI_IDLE	0
#define WAVE_EFFECT_1	0
#define WAVE_EFFECT_2	1

//define player distance to camera
#define DISTANCE_LEFT	0
#define DISTANCE_TOP	0
#define DISTANCE_RIGHT	0
#define DISTANCE_BOTTOM	0