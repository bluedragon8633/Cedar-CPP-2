#pragma once
#include"BasicObjs.h"
#include"interactiveObj.h"
#include"KeyHandler.h"
#include"game.h"
//#include"tile.h"
#include<iostream>
using namespace std;

class PlayerObj : public interactiveObj, public healthyObj {
public:
	
	
	int prevDir = -1;
	bool isOnEdge();
	int newLevel();
	PlayerObj(GameConsts g);
	void process(KeyHandler key, GameConsts g);
};

class PlayerAtk : public interactiveObj {
public:
	int timer;

	PlayerAtk();
	void process();
};
