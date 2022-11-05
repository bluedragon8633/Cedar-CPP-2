#include<iostream>
#include"Drawer.h"
#include"game.h"
#include"InteractiveObj.h"

class TileMap {
public:
	int mapId = 0; //dungeon/area ID; number added to file name for that dungeon's level data
	int levelId = 1;
	char ID = 'A';
	int width = 25;
	int height = 15;
	int offsetX = 0;
	int offsetY = 0;
	int palY = 16;//top left corner of tileset in atlas
	frameObj tile;
	int tiles[25][15][2] = {};
	TileMap();
	TileMap(int map,int level);
	
	void drawTiles();
	void resize(int nWidth,int nHeight);
	void load(int map, int level);
};
