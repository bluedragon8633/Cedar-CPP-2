#pragma once
#include"basicObjs.h"

class interactiveObj : public animObj { //can be interacted with. ex. walls, liquids, pits, spikes, pushable terrain
public:

	bool isHarmful;
	bool isSolid;





};

class healthyObj {
	int hp = 3;
	int maxhp = 3;
	int immortalFrameLength = 40;
	bool isMortal = true;
	int mortalFrame = 0;
	bool isDead = false;

	void healthTic();

	void healthTic(int decrement);
};