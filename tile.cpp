#include<iostream>
#include"Drawer.h"
#include"game.h"
#include"general.h"
#include"InteractiveObj.h"
#include"tile.h"
#include"GlobalVars.h"
#include"Player.h"
#include"enemy.h"
using namespace Drawer;
using namespace std;
using namespace Global;


TileMap::TileMap() {
    addSolidTiles();
    width = Global::tileWidth;
    height = Global::tileHeight;
    console.log("Global tile size: (" + to_string(tileWidth) + to_string(tileHeight) + ")");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            tiles[x][y][0] = 0;
            tiles[x][y][1] = 0;

        }
    }
}

TileMap::TileMap(int mapId, int level) {
    width = Global::tileWidth;
    height = Global::tileHeight;
    addSolidTiles();
    load(area.areaId, level);
    console.log("other constructor used");
}



int TileMap::getTileCost(int x, int y) {
    if (tiles[x][y][0] == 1) {
        int toReturn = 0;

        toReturn += (tiles[x - 1][y][0] == 1 || x == 0) * 8; //left
        toReturn += (tiles[x][y - 1][0] == 1 || y == 0) * 4; //up
        toReturn += (tiles[x + 1][y][0] == 1 || x == Global::tileWidth - 1) * 2; //right
        toReturn += (tiles[x][y + 1][0] == 1 || y == Global::tileHeight - 1) * 1; //down
        return toReturn;
    }
    return baseFloorTile[0] + baseFloorTile[1] * 4;
}
string TileMap::getTileCostStr(int x, int y) {
    if (tiles[x][y][0] == 1) {
        string toReturn = "";

        toReturn += to_string((tiles[x - 1][y][0] == 1 || x == 0) * 8); //left
        toReturn += to_string((tiles[x][y - 1][0] == 1 || y == 0) * 4); //up
        toReturn += to_string((tiles[x + 1][y][0] == 1 || x == Global::tileWidth - 1) * 2); //right
        toReturn += to_string((tiles[x][y + 1][0] == 1 || y == Global::tileHeight - 1) * 1); //down
        return toReturn + "; translates to x,y: " + to_string(getTileCost(x, y) % 4) + "," + to_string((getTileCost(x, y) - (getTileCost(x, y) % 4)) / 4);
    }
    return to_string(baseFloorTile[0] + baseFloorTile[1] * 4);
}

void TileMap::drawTiles() {
    //console.log("drawing tiles");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int rawTileCost = getTileCost(x, y);
            int xpos = (rawTileCost % 4);
            int ypos = (rawTileCost - (rawTileCost % 4)) / 4;
            tile.set(baseFloorTile[0], baseFloorTile[1], Global::TILE_SIZE, Global::TILE_SIZE);
            stamp(tile, x * TILE_ZOOM * (Global::TILE_SIZE + spacing) + offsetX, y * TILE_ZOOM * (Global::TILE_SIZE + spacing) + offsetY,TILE_ZOOM);
            tile.set(xpos * Global::TILE_SIZE, ypos * Global::TILE_SIZE + palY, Global::TILE_SIZE, Global::TILE_SIZE);
            stamp(tile, x * TILE_ZOOM * (Global::TILE_SIZE + spacing) + offsetX, y * TILE_ZOOM * (Global::TILE_SIZE + spacing) + offsetY,TILE_ZOOM);
            console.log("tile data: " + to_string(tiles[x][y][0]) + "," + to_string(tiles[x][y][1]), true);

        }
    }

}

void TileMap::addSolidTiles() {
    solidTiles.clear();
    solidTiles.push_back(1);
    solidTiles.push_back(2);
    cout << "solidTiles contains: " << solidTiles.at(0) << endl;
}



void TileMap::load(int areaId, int level) {
    width = Global::tileWidth;
    height = Global::tileHeight;
    console.log("world path: assets/map" + to_string(areaId) + ".txt");
    console.log("level code tag: levelCode" + to_string(level));
    string tempNewLevelStr = General::findString("assets/map" + to_string(areaId) + ".txt", "levelCode" + to_string(level));
    if (tempNewLevelStr != "") {
        levelStr = tempNewLevelStr;
    }
   
    console.log("levelStr: " + levelStr);
    palY = stoi(General::findString("assets/map" + to_string(areaId) + ".txt", "pal" + to_string(level)));
    for (int y = 0; y < height; y++) { //passes tile string into array
        for (int x = 0; x < width; x++) {
            tiles[x][y][0] = stoi(levelStr.substr(0, 2));
            //tiles[x][y][1] = stoi(levelStr.substr(1,1));
            levelStr = levelStr.substr(2);

        }
    }
    string tempAreaSize = General::findString("assets/map" + to_string(areaId) + ".txt","mapSize");
    area.reset(stoi(tempAreaSize.substr(0, 2)),stoi(tempAreaSize.substr(2, 2)),areaId, level);
    justLoaded = true;
}

void TileMap::resize(int nWidth, int nHeight) {
    width = nWidth;
    height = nHeight;
}

bool TileMap::isTileSolid(int tileType) {
    for (int i = 0; i < solidTiles.size(); i++) {
        if (tileType == solidTiles.at(i)) {
            return true;
        }
    }
    return false;
}

vector<baseObj> TileMap::getEnemies() {
    vector<baseObj> newEnemies;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (tiles[x][y][0] > 10 && tiles[x][y][0] < 20) {
                switch (tiles[x][y][0]) {
                case 11:
                    newEnemies.push_back(baseObj(x * Global::TILE_SIZE,y * Global::TILE_SIZE,0,"Horizontal"));
                    console.log("Made new enemy");
                    break;
                case 12:

                    break;
                case 13:

                    break;
                case 14:

                    break;
                case 15:

                    break;
                }
            }

        }
    }
    return newEnemies;
}


bool TileMap::isObjOnWall(interactiveObj in) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (isTileSolid(tiles[x][y][0])) {
                if (in.isObjOverlapping(interactiveObj(x * Global::TILE_SIZE, y * Global::TILE_SIZE, Global::TILE_SIZE, Global::TILE_SIZE, false))) {
                    return true;
                }
            }

        }
    }
    return false;
}

bool TileMap::getJustLoaded() {
    if (justLoaded) {
        justLoaded = false;
        return true;
    }
    return false;
}


baseObj TileMap::processCollision(interactiveObj b) {
    b.move(b.xv, 0);
    if (isObjOnWall(b)) {
        b.move(-b.xv, 0);
    }
    b.move(0,b.yv);
    if (isObjOnWall(b)) {
        b.move(0,-b.yv);
    }
    return b.getBaseObj();
    
}