#pragma once
#include"BasicObjs.h"
#include"interactiveObj.h"
#include"game.h"
#include<iostream>
using namespace std;

class PlayerObj : public interactiveObj, public healthyObj {
public:
	
	
	int prevDir = -1;
	
	PlayerObj(GameConsts g);
	void process(KeyHandler key, GameConsts g);
};

class PlayerAtk : public interactiveObj {
public:
	int timer;

	PlayerAtk();
	void process();
};
