#pragma once
#include<iostream>
namespace level {

	const int scrnWidth = 480;
	const int scrnHeight = 480;
	const int alHUDHeight = 0;
	const int finalTileSize = 48;
	const int tileResolution = 16;
	const int scrnTileWidth = scrnWidth / finalTileSize;
	const int scrnTileHeight = scrnHeight / finalTileSize;
	const int numOfTiles = scrnTileWidth * scrnTileHeight;
	const int maxLevels = 2;
	const int mapWidth = 5;
	const int mapHeight = 5;
	const int hudMargin = 4;
	extern int tiles[10][10];// [scrnTileWidth] [scrnTileHeight] ;
	extern int LEVEL;
	extern bool isFocused;
	const int uiTileSize = 8;
	const int SCALE = 3;
	extern int tileCostumeX[10][10];//[scrnTileHeight][scrnTileWidth];
	extern int tileCostumeY[10][10];//[scrnTileHeight][scrnTileWidth];
	const int numOfSolidObjs = 3; //Solid Objects are just any stationary objects that the block cannot pass through. Examples include tree trunks, walls of any material, boulders, and  cliff bases.
	extern int solidObjs[3]; //field == numOfSolidObjs
	const int numOfWallObjs = 2;
	extern int wallObjs[2];//Wall Objects are ones that look like regular ones; that is, they comply with the tiling rules.
	extern int SCORE;
	extern int MONEY;
	extern int HP,MAXHP,POTIONCOUNT,BIGPOTIONCOUNT,WEAPONLVL,DMG;
	extern int FURTHESTROOM;
	extern int menuSelectX, menuSelectY;
	extern int hudOffset;
	extern int STATUS;
	extern int blockDir;
	extern bool upKeyReady, downKeyReady, rightKeyReady,leftKeyReady, backKeyReady, pauseKeyReady, selectKeyReady;
	extern bool leftK, rightK, upK, downK, spaceK, zK, xK, enterK;
	extern int PAL;
	extern bool isBossRoom;

	void setGameOver();
	bool collisionDetect(int xin, int yin, int width, int height, int xv, int yv);
	bool contains(int listin[], int arrayLen, int in);
	bool isPointInRect(int pX, int pY, int rectX, int rectY, int width, int height, bool centerOg);
	bool collide(int x1, int y1, int width1, int height1, bool centerOg1, int x2, int y2, int width2, int height2, bool centerOg2);
	bool collide(int x1, int y1, int width1, int height1, bool centerOg1, int x2, int y2, int width2, int height2, bool centerOg2);
}
