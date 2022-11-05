#include<iostream>
#include"Drawer.h"
#include"game.h"
#include"general.h"
#include"InteractiveObj.h"
#include"tile.h"
using namespace Drawer;
using namespace std;

void TileMap::drawTiles() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            tile.set(tiles[x][y][1] * game.TILE_SIZE, tiles[x][y][0] * game.TILE_SIZE + palY,game.TILE_SIZE,game.TILE_SIZE );
            stamp(tile,x * game.TILE_SIZE + offsetX,y * game.TILE_SIZE + offsetY);
            console::log("tile data: " + to_string(tiles[x][y][0]) + "," + to_string(tiles[x][y][1]), true);
        }
    }
    
}

TileMap::TileMap() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            tiles[x][y][0] = 0;
            tiles[x][y][1] = 0;

        }
    }
}

void TileMap::load(int map,int level) {
    mapId = map;
    levelId = level;
    string levelStr = General::getLineFromFile("assets/map" + to_string(mapId) + ".txt", level);
    console::log("levelStr: " + levelStr);
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) { 
            tiles[x][y][0] = stoi(levelStr.substr(0,1));
            tiles[x][y][1] = stoi(levelStr.substr(1,1));
            levelStr = levelStr.substr(2);

        }
    }
}

TileMap::TileMap(int map,int level) {
    load(map, level);
}
	
void TileMap::resize(int nWidth,int nHeight) {
    width = nWidth;
    height = nHeight;
}
