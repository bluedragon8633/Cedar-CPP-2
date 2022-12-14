#include<iostream>
#include<vector>
#include"Drawer.h"
#include"game.h"
#include"InteractiveObj.h"
#include"GlobalVars.h"

class TileMap {
public:
	const int baseFloorTile[2] = { 0,4 }; //default floor tile
	int spacing = 0; //how much distance between each tile
	char ID = 'A'; //what the actual fuck
	int width, height;
	int TILE_ZOOM = 1;
	int offsetX = 0;
	int offsetY = 0;
	std::string levelStr;
	int palY = 112;//top left corner of tileset in atlas
	frameObj tile;
	
	//int drawableTiles[25][15][2] = {};
	vector<int> solidTiles;
	bool justLoaded = false;

	TileMap();
	TileMap(int mapId, int level);

	void addSolidTiles();
	bool getJustLoaded();
	vector<baseObj> getEnemies();
	void drawTiles();
	void resize(int nWidth, int nHeight);
	void load(int mapId, int level);
	int getTileCost(int x, int y);
	string getTileCostStr(int x, int y);
	bool isObjOnWall(interactiveObj in);
	bool isObjOnWall(interactiveObj in,string returnType); //returns either x or y overlap based on returnType
	bool isTileSolid(int tileType);
	baseObj processCollision(interactiveObj b);
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