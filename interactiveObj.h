#pragma once
#include"basicObjs.h"

class interactiveObj : public animObj { //can be interacted with. ex. walls, liquids, pits, spikes, pushable terrain
public:

	bool isHarmful;
	bool isSolid;





};

class healthyObj {
	int hp;
	int maxhp;
	int immortalFrameLength;
	bool isMortal;
	int mortalFrame = 0;
	bool isDead = false;

	void healthTic();

	void healthTic(int decrement);
};