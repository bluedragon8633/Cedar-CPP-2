#include<iostream>
#include"Drawer.h"
#include"game.h"
#include"general.h"
#include"InteractiveObj.h"
#include"tile.h"
//#include"Player.h"
using namespace Drawer;
using namespace std;

int TileMap::getTileCost(int x, int y) {
    if (tiles[x][y][0] == 1) {
        int toReturn = 0;

        toReturn += (tiles[x - 1][y][0] == 1 || x == 0) * 8; //left
        toReturn += (tiles[x][y - 1][0] == 1 || y == 0) * 4; //up
        toReturn += (tiles[x + 1][y][0] == 1 || x == game.tileWidth - 1) * 2; //right
        toReturn += (tiles[x][y + 1][0] == 1 || y == game.tileHeight - 1) * 1; //down
        return toReturn;
    }
    return baseFloorTile[0] + baseFloorTile[1] * 4;
}
string TileMap::getTileCostStr(int x, int y) {
    if (tiles[x][y][0] == 1) {
        string toReturn = "";

        toReturn += to_string((tiles[x - 1][y][0] == 1 || x == 0) * 8); //left
        toReturn += to_string((tiles[x][y - 1][0] == 1 || y == 0) * 4); //up
        toReturn += to_string((tiles[x + 1][y][0] == 1 || x == game.tileWidth - 1) * 2); //right
        toReturn += to_string((tiles[x][y + 1][0] == 1 || y == game.tileHeight - 1) * 1); //down
        return toReturn + "; translates to x,y: " + to_string(getTileCost(x,y) % 4) + "," + to_string((getTileCost(x, y) - (getTileCost(x, y) % 4)) / 4);
    }
    return to_string(baseFloorTile[0] + baseFloorTile[1] * 4);
}

void TileMap::drawTiles() {
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int rawTileCost = getTileCost(x,y);
            int xpos = (rawTileCost % 4);
            int ypos = (rawTileCost - (rawTileCost % 4)) / 4;
            tile.set(0,0,16,16);
            stamp(tile, x * (game.TILE_SIZE + spacing) + offsetX, y * (game.TILE_SIZE + spacing) + offsetY);
            tile.set(xpos * game.TILE_SIZE, ypos * game.TILE_SIZE + palY, game.TILE_SIZE, game.TILE_SIZE);
            stamp(tile,x * (game.TILE_SIZE + spacing) + offsetX,y * (game.TILE_SIZE + spacing) + offsetY);
            //console::log("tile data: " + to_string(tiles[x][y][0]) + "," + to_string(tiles[x][y][1]), true);

        }
    }
    
}

TileMap::TileMap() {
    width = game.tileWidth;
    height = game.tileHeight;
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
    console::log("map path: assets/map" + to_string(mapId) + ".txt");
    console::log("level code tag: levelCode" + to_string(level));
    levelStr = General::findString("assets/map" + to_string(mapId) + ".txt", "levelCode" + to_string(level));
    console::log("levelStr: " + levelStr);
    palY = stoi(General::findString("assets/map" + to_string(mapId) + ".txt", "pal" + to_string(level)));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) { 
            tiles[x][y][0] = stoi(levelStr.substr(0,2));
            //tiles[x][y][1] = stoi(levelStr.substr(1,1));
            levelStr = levelStr.substr(2);

        }
    }
}

TileMap::TileMap(int map,int level) {
    width = game.tileWidth;
    height = game.tileHeight;

    load(map, level);
}
	
void TileMap::resize(int nWidth,int nHeight) {
    width = nWidth;
    height = nHeight;
}

bool TileMap::isObjOverlapping(interactiveObj in) {
    for (int y = 0; y < height;y++) {
        for (int x = 0; x < width; x++) {
            if (General::contains(solidTiles,1,tiles[x][y])) {
                if (sf::IntRect(x * game.TILE_SIZE, y * game.TILE_SIZE, game.TILE_SIZE, game.TILE_SIZE).intersects(sf::IntRect(in.x, in.y, in.width, in.height))) {
                    return true;
                }
            }

        }
    }



    return false;
}