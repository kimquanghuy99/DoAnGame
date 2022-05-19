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
#include "Bullet.h"

#define QUADTREE_SECTION_SETTINGS	1
#define QUADTREE_SECTION_OBJECTS	2
#define MAX_QUADTREE_LINE 1024

class CQuadTree
{
	bool isLeaf = false;
	float x = 0;
	float y = 0;
	float cellWidth = 0;
	float  cellHeight = 0;
	CQuadTree* BrachTL = NULL;
	CQuadTree* BrachTR = NULL;
	CQuadTree* BrachBL = NULL;
	CQuadTree* BrachBR = NULL;
	//MapObj* obj;
	vector<LPGAMEOBJECT> listObjects;


	void _ParseSection_SETTINGS(string line);
	void _ParseSection_OBJECTS(string line);
	void _ParseSection_MapObj(string line);
public:
	CQuadTree(float cellWidth, float cellHeight, float x, float y);
	CQuadTree(LPCWSTR filePath);
	void GetObjects(vector<LPGAMEOBJECT>& listObject, int playerX, int playerY);
	void Load(LPCWSTR filePath);
	void Unload();
	void Add(CGameObject* obj)
	{
		listObjects.push_back(obj);
	}
	int getVollunm() {
		return listObjects.size();
	}
	void Render();
	void Plit();
	void ObjectPlit(CQuadTree* brach);
	bool inRange(float ox, float oy, float x, float y, float width, float height);
	void Pop(vector<LPGAMEOBJECT>& listObject, int CamX, int CamY);

};
class CPlayScene : public CScene
{
protected:
	static CPlayScene* __instance;
	int mapHeight;

	CQuadTree* quadtree;

	CMarcoRossi* player;		// A play scene has to have player, right?					
	vector<LPGAMEOBJECT> objects;

	void _ParseSection_TEXTURES(string line);
	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);
	void _ParseSection_ANIMATION_SETS(string line);
	void _ParseSection_OBJECTS(string line);
	void _ParseSection_QUADTREE(string line);


public:
	CPlayScene() {};
	CPlayScene(int id, LPCWSTR filePath);

	void setMapheight(int height)
	{
		mapHeight = height;
	}

	int getMapheight()
	{
		return mapHeight;
	}
	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();

	void AddObject(CGameObject* obj)
	{
		objects.push_back(obj);
	}

	CMarcoRossi* GetPlayer() { return player; }

	static CPlayScene* GetInstance();

	~CPlayScene();

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

