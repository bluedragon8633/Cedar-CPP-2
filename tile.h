#include<iostream>
#include<vector>
#include"Drawer.h"
#include"game.h"
#include"InteractiveObj.h"

class TileMap {
public:
	const int baseFloorTile[2] = { 0,4 };
	int spacing = 0;
	int mapId = 0; //dungeon/area ID; number added to file name for that dungeon's level data
	int levelId = 1;
	char ID = 'A';
	int width, height;
	int offsetX = 0;
	int offsetY = 0;
	std::string levelStr;
	int palY = 112;//top left corner of tileset in atlas
	frameObj tile;
	int tiles[25][15][2] = {};
	int drawableTiles[25][15][2] = {};
	vector<int> solidTiles;


	TileMap();
	TileMap(int map, int level);

	void addSolidTiles();

	void drawTiles();
	void resize(int nWidth, int nHeight);
	void load(int map, int level);
	int getTileCost(int x, int y);
	string getTileCostStr(int x, int y);
	bool isObjOnWall(interactiveObj in);
	bool isTileSolid(int tileType);
private:
	/*
	const std::string tileCodes[16] = { //[x][0] = cardinal directions
		"","","","",
		"","","","",
		"","","","",
		"","","","",
	};
	const int tileCoords[16][2] = {
		{},{},{},{},
		{},{},{},{},
		{},{},{},{},
		{},{},{},{}
	};
	*/
};