#include<iostream>
#include"Drawer.h"
#include"game.h"
#include"general.h"
#include"InteractiveObj.h"
#include"tile.h"
#include"Player.h"
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
        return toReturn + "; translates to x,y: " + to_string(getTileCost(x, y) % 4) + "," + to_string((getTileCost(x, y) - (getTileCost(x, y) % 4)) / 4);
    }
    return to_string(baseFloorTile[0] + baseFloorTile[1] * 4);
}

void TileMap::drawTiles() {

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int rawTileCost = getTileCost(x, y);
            int xpos = (rawTileCost % 4);
            int ypos = (rawTileCost - (rawTileCost % 4)) / 4;
            tile.set(0, 0, 16, 16);
            stamp(tile, x * (game.TILE_SIZE + spacing) + offsetX, y * (game.TILE_SIZE + spacing) + offsetY);
            tile.set(xpos * game.TILE_SIZE, ypos * game.TILE_SIZE + palY, game.TILE_SIZE, game.TILE_SIZE);
            stamp(tile, x * (game.TILE_SIZE + spacing) + offsetX, y * (game.TILE_SIZE + spacing) + offsetY);
            //console::log("tile data: " + to_string(tiles[x][y][0]) + "," + to_string(tiles[x][y][1]), true);

        }
    }

}

void TileMap::addSolidTiles() {
    solidTiles.clear();
    solidTiles.push_back(1);
    cout << "solidTiles contains: " << solidTiles.at(0) << endl;
}

TileMap::TileMap() {
    addSolidTiles();
    width = game.tileWidth;
    height = game.tileHeight;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            tiles[x][y][0] = 0;
            tiles[x][y][1] = 0;

        }
    }
}

void TileMap::load(int areaId, int level) {
    
    console::log("world path: assets/map" + to_string(areaId) + ".txt");
    console::log("level code tag: levelCode" + to_string(level));
    levelStr = General::findString("assets/map" + to_string(areaId) + ".txt", "levelCode" + to_string(level));
    console::log("levelStr: " + levelStr);
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
}

TileMap::TileMap(int mapId, int level) {
    width = game.tileWidth;
    height = game.tileHeight;
    addSolidTiles();
    load(area.areaId, level);
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




bool TileMap::isObjOnWall(interactiveObj in) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (isTileSolid(tiles[x][y][0])) {
                if (in.isObjOverlapping(interactiveObj(x * game.TILE_SIZE, y * game.TILE_SIZE, game.TILE_SIZE, game.TILE_SIZE, false))) {
                    return true;
                }
            }

        }
    }
    return false;
}



void TileMap::playerCollide() {
    Coords oldDir(player.xv,player.yv);
    Coords oldPos(player.x,player.y);
    player.processX(key, game);
    if (isObjOnWall(player)) {
        player.move(-player.xv, 0, game);
    }
    player.processY(key, game);
    if (isObjOnWall(player)) {
        player.move(0, -player.yv, game);
    }

    if ((oldDir.x != player.xv || oldDir.y != player.yv)) { //if changed position at all
        if (player.xv != 0) { //moving right
            player.setAnimation(0);
        }
        
    }
    else {
        if (player.isOnLastFrame()) {
            player.setAnimation(player.animId + 3);
        }
    }
    player.animationTic();
}