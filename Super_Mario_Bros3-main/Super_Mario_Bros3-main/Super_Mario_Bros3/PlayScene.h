#pragma once
#include "Game.h"
#include "Scene.h"
#include "GameObject.h"

#include "Textures.h"
#include "define.h"
#include "Background.h"
#include "AnimatedBackground.h"
#include "Parallax.h"
#include "MarcoRossi.h"
#include "Portal.h"
#include "Goomba.h"
#include "Event.h"


class CPlayScene : public CScene
{
protected:
	static CPlayScene* __instance;

	CMarcoRossi* player;		// A play scene has to have player, right?					
	vector<LPGAMEOBJECT> objects;
	vector<Event*> KaboomMng;


	void _ParseSection_TEXTURES(string line);
	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);
	void _ParseSection_ANIMATION_SETS(string line);
	void _ParseSection_OBJECTS(string line);

public:
	CPlayScene() {};
	CPlayScene(int id, LPCWSTR filePath);

	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();

	void AddObject(float x, float y, int objId);

	CMarcoRossi* GetPlayer() { return player; }

	static CPlayScene* GetInstance();

	~CPlayScene();

	void AddKaboomMng(float x, float y)
	{
		Event* obj = new Event(x, y);
		this->KaboomMng.push_back(obj);
	}

	//friend class CPlayScenceKeyHandler;
};

class CPlayScenceKeyHandler : public CScenceKeyHandler
{
public:
	virtual void KeyState(BYTE* states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	CPlayScenceKeyHandler(CScene* s) :CScenceKeyHandler(s) {};
};

