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
	
	Coords oldPos;
	Coords oldVel;
	int prevDir = -1;
	int getLevelIncrement();
	PlayerObj();
	void processX(KeyHandler key);
	void processY(KeyHandler key);
	void animationProcess();
};

class PlayerAtk : public interactiveObj {
public:
	int timer;

	PlayerAtk();
	void process();
};
