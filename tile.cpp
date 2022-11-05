#include<iostream>
#include"Drawer.h"
#include"game.h"
#include"general.h"
#include"InteractiveObj.h"
#include"tile.h"
using namespace Drawer;

void TileMap::drawTiles() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            tile.set(tiles[x][y][0] * game.TILE_SIZE, tiles[x][y][1] * game.TILE_SIZE + palY,game.TILE_SIZE,game.TILE_SIZE );
            stamp(tile,x * game.TILE_SIZE + offsetX,y * game.TILE_SIZE + offsetY);
            console::log("tile data: " + to_string(tiles[x][y][0] * game.TILE_SIZE) + "," + to_string(tiles[x][y][1] * game.TILE_SIZE + palY), true);
        }
    }
    
}
/*
int TileMap::getTileCoord(int xin, int yin, char retType, GameConsts g) {
    char returnType = retType;
    int tilePointer = 0;
    string tileID;


    if (yin == 0) {
        tileID = tileID + "1";
    }
    else if (General::contains(General::wallObjs, General::numOfWallObjs, General::tiles[xin][yin - 1])) {
        tileID = tileID + "1";
    }
    else {
        tileID = tileID + "0";
    }
    if (xin == 0) {
        tileID = tileID + "1";
    }
    else if (General::contains(General::wallObjs, General::numOfWallObjs, General::tiles[xin - 1][yin])) {
        tileID = tileID + "1";
    }
    else {
        tileID = tileID + "0";
    }
    if (yin == 9) {
        tileID = tileID + "1";
    }
    else if (General::contains(General::wallObjs, General::numOfWallObjs, General::tiles[xin][yin + 1])) {
        tileID = tileID + "1";
    }
    else {
        tileID = tileID + "0";
    }

    if (xin == 9) {
        tileID = tileID + "1";
    }
    else if (General::contains(General::wallObjs, General::numOfWallObjs, General::tiles[xin + 1][yin])) {
        tileID = tileID + "1";
    }
    else {
        tileID = tileID + "0";
    }




    //cout << tileID << "; ";
    if (xin == g.tileWidth - 1) {
        //cout << "\n";
    }
    if (returnType == 'X') {
        return tilePosCoords[index(tileCode, 15, tileID)][0];
    }
    else {
        return tilePosCoords[index(tileCode, 15, tileID)][1] + General::PAL * 5;
    }
    return 0;
}
*/
TileMap::TileMap() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            tiles[x][y][0] = 0;
            tiles[x][y][1] = 0;
        }
    }
}

TileMap::TileMap(int level) {
	
}
	
void TileMap::resize(int nWidth,int nHeight) {
	
}

void TileMap::draw(int xin,int yin, int nWidth, int nHeight) {
	
}
