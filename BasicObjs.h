#pragma once
#include<iostream>
#include<vector>
using namespace std;

class baseObj {
public:
	int x, y;
	int dir;
	int width, height;

};

class frameObj {
public:
	int sourceX, sourceY;
	bool flipX,flipY;
	int sourceWidth, sourceHeight;
	int frameLength;
};

class animationObj { //single animation. <animObj> contains multiple of these to make a fully realized character.
public:
	int animLength;
	frameObj frames[8];
	

};

class animObj : public baseObj { //non-interactive animated surface, ex. particles, smoke, animated ground tiles
public:
	int frameId, frameCounter;
	int xv, yv;
	int animId;

	bool centerOrigin;

	animationObj anims[8];

	void animationTic();
	void setAnimation();

	void moveTo(int xin, int yin);
	void move(int xin, int yin);
	void move();
};