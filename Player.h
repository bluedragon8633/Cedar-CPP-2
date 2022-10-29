#pragma once
#include"BasicObjs.h"
#include"interactiveObj.h"
#include"game.h"

class PlayerObj : public interactiveObj, public healthyObj {
public:
	int walkFrameLength = 3;
	int tileSize = 16;

	
	PlayerObj();
	void process(KeyHandler key);
};