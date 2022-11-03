#include<iostream>
#include"Drawer.h"
#include"game.h"
#include"InteractiveObj.h"

class TileMap {
	int tileMapLocation = 0;
	char ID = 'A';
	int width, height;
	
	TileMap();
	TileMap(int level);
	
	//int getTileCoord(int xin, int yin, char retType, GameConsts g);
	void resize(int nWidth,int nHeight);
	void draw(int xin,int yin, int nWidth, int nHeight);
};
