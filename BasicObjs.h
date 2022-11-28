#pragma once
#include"game.h"
#include<iostream>
#include<vector>
using namespace std;

class baseObj {
public:
	int x, y,z;
	int dir;
	int width, height;
	int xv = 0; int yv = 0;
	baseObj(int xin,int yin,int zin, int widthin,int heightin,int xvin,int yvin);
	void setPos(int xin,int yin,int zin);
	void setSize(int widthin, int heightin);
	void setVel(int xvin, int yvin);
	baseObj();
};

class frameObj {
public:
	int sourceX, sourceY;
	int sourceWidth, sourceHeight;
	int frameLength;

	frameObj();
	frameObj(int newSrcX,int newSrcY,int newSrcWidth,int newSrcHeight,int newLen);
	void set(int newSrcX, int newSrcY, int newSrcWidth, int newSrcHeight);
};

class Billboard : public frameObj {
public:
	int x, y;
	bool centerOrigin;
	Billboard(int xin,int yin,int newSrcX, int newSrcY, int newSrcWidth, int newSrcHeight,bool origin);
	
};

class animationObj { //single animation. <animObj> contains multiple of these to make a fully realized character.
public:
	int animLength = 1;
	vector <frameObj> frames;
	string name = "";

};


class animObj : public baseObj { //non-interactive animated surface, ex. particles, smoke, animated ground tiles
public:
	int frameId = 0;
	int frameCounter = 0;
	
	bool hasShadow = false;
	bool canLeaveScreen = false;
	int animId = 0;
	bool flipX = false; bool flipY = false;
	bool centerOrigin = false;
	bool canMoveDiagonally = false; //what the fuck did you think this meant? why do you need a comment for it?
	string animName = ""; //name of current animation
	std::string className = ""; //internal name for object
	animationObj anims[16];
	void animationTic();
	void setAnimation(int newId);
	void setAnimation(string newName);
	void makeAnimation(int id,int startX,int startY,int tileWidth,int tileHeight,int length, int frameLen);
	void makeAnimation(string newName,int id, int startX, int startY, int tileWidth, int tileHeight, int length, int frameLen);
	void move(int xin, int yin, GameConsts g);
	void move(GameConsts g);
	bool isOnLastFrame();
	//bool isOutOfBounds(GameConsts g, Area area);
	bool isOutOfBounds(GameConsts g);
	void setSize(int newWidth,int newHeight);
	sf::Vector2f topleft();
	baseObj getBaseObj();
	animObj();
};

class TextObj {
	string text;
	int x, y;
	bool centerOrigin;
	sf::Color color;
	int fontSize;
};
