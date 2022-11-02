#include<iostream>
#include"Drawer.h"
#include"game.h"
#include"InteractiveObjs.h"

class TileMap {
	int tileMapLocation = 0;
	char ID = '';
	int width, height;
	
	TileMap();
	resize(int nWidth,int nHeight);
	draw(int xin,int yin, int nWidth, int nHeight);
};
