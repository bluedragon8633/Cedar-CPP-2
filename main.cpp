#include<iostream>
#include<vector>

class game { //contains general info. TileSize, WindowSize
public:
	int 
};

class frameObj {
public:
	int sourceX,sourceY;
	bool flip;
	int imgWidth,imgHeight;
};

class animationObj { //single animation. <animObj> contains multiple of these to make a fully realized character.
public:
	int animId;
	vector<frameObj> frames;
	
	
};

class baseObj {
public:
	int x, y;
	int dir;
	int width, height;
	
};

class billboardObj : frameObj { //static image. Can't be interacted with. Doesn't move. Ex. untouchable walls, plain ground tiles
public:
	
};

class animObj : public baseObj { //non-interactive animated surface, ex. particles, smoke, animated ground tiles
public:
	int frameId,frameCounter,animationId;
	vector<animationObj> anims;
};

class interactiveObj : public animObj { //can be interacted with. ex. walls, liquids, pits, spikes, pushable terrain
public:
	int xv, yv;
	bool isHarmful;
	bool isSolid;
	
	
	
	
	void move(xin,yin) {
		x = xin;
		y = yin;
	}
};

class player : public interactiveObj {
	
};
