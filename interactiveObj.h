#pragma once
#include"basicObjs.h"

class interactiveObj : public animObj { //can be interacted with. ex. walls, liquids, pits, spikes, pushable terrain
public:
	bool bumpedWall = false;
	bool isHarmful = false;
	bool isSolid = false;
	int tileSize = 16;
	int walkFrameLength = 3;
	bool movedThisFrame;
	bool touchedWallThisFrame;

	interactiveObj(int xin, int yin, int newWidth, int newHeight);
	interactiveObj(int xin, int yin, int newWidth, int newHeight,bool centeredOrigin);
	interactiveObj();

	void moveWithCollision();
	bool isObjOverlapping(interactiveObj in1, interactiveObj in2);
	bool isObjOverlapping(interactiveObj in1);
};



class healthyObj {
public:
	int hp = 3;
	int maxhp = 3;
	int immortalFrameLength = 40;
	bool isMortal = true;
	int mortalFrame = 0;
	bool isDead = false;

	void healthTic();

	void healthTic(int decrement);
};