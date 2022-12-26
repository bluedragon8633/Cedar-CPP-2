#include"Level.h"

namespace level {
    int tiles[10][10] = {}; //[scrnTileWidth][scrnTileHeight] = {};
    int solidObjs[3] = { 1,2,4 }; //field == numOfSolidObjs
    int wallObjs[2] = { 1 , 7};
    int tileCostumeX[10][10] = {}; //[scrnTileWidth][scrnTileHeight] = {};
    int tileCostumeY[10][10] = {}; //[scrnTileWidth][scrnTileHeight] = {};
    int hudOffset = 0;
    int LEVEL = 3;
    bool isFocused = true;
    int STATUS = 0;
    int blockDir = 1;
    int MONEY = 0;
    int SCORE = 0;
    int menuSelectY = 0;
    int menuSelectX = 0;
    int HP = 0; int MAXHP = 0;
    int PAL = 1;
    bool upKeyReady, downKeyReady, rightKeyReady, leftKeyReady, backKeyReady, pauseKeyReady, selectKeyReady;
    bool leftK, rightK, upK, downK, spaceK, zK, xK, enterK;
    bool isBossRoom = false;

    bool contains(int listin[], int arrayLen, int in) {
        for (int i = 0; i < arrayLen; i++) {
            if (listin[i] == in) {
                return true;
            }
        }
        return false;
    }

    bool isPointInRect(int pX, int pY, int rectX, int rectY, int width, int height, bool centerOg) {
        int leftSide = rectX;
        int rightSide = rectX + width;
        int topSide = rectY;
        int bottomSide = rectY + height;
        if (centerOg) {
            leftSide -= width / 2;
            rightSide -= width / 2;
            topSide -= height / 2;
            bottomSide -= height / 2;
        }
        if (leftSide < pX && pX < rightSide && topSide < pY && pY < bottomSide) {
            return true;
        }
        return false;
    }

    bool collisionDetect(int xin, int yin, int width, int height, int xv, int yv) { //detects whether an entity is colliding with the walls, NOT other sprites!
        int currTile = 0;
        int currTile2 = 0;
        if (xv < 0) {
            currTile = level::tiles[int((yin) / level::finalTileSize)][int((xin - (16) - 1) / level::finalTileSize)];
        }
        if (xv > 0) {
            currTile = level::tiles[int((yin) / level::finalTileSize)][int((xin + (16) + 1) / level::finalTileSize)];
        }
        if (yv < 0) {
            currTile = level::tiles[int(ceil((yin - (16) + 1) / level::finalTileSize))][int(ceil((xin) / level::finalTileSize))];
            currTile2 = level::tiles[int(floor((yin - (16) + 1) / level::finalTileSize))][int((xin) / level::finalTileSize)];
        }
        if (yv > 0) {
            currTile = tiles[int(ceil((yin + (16) + 1) / level::finalTileSize))][int((xin) / level::finalTileSize)];
            currTile2 = level::tiles[int(floor((yin + (16) + 1) / level::finalTileSize))][int((xin) / level::finalTileSize)];
        }
        if (contains(solidObjs, numOfSolidObjs, currTile) || contains(solidObjs, numOfSolidObjs, currTile2)) {
            return true;
        }
        return false;
    }

    bool collide(int x1, int y1, int width1, int height1, bool centerOg1, int x2, int y2, int width2, int height2, bool centerOg2) {
        int leftSide = x1;
        int rightSide = x1 + width1;
        int topSide = y1;
        int bottomSide = y1 + height1;
        if (centerOg1) {
            leftSide -= width1 / 2;
            rightSide -= width1 / 2;
            topSide -= height1 / 2;
            bottomSide -= height1 / 2;
        }
        if (isPointInRect(leftSide, topSide, x2, y2, width2, height2, centerOg2)) { //top left corner
            return true;
        }
        if (isPointInRect(rightSide, topSide, x2, y2, width2, height2, centerOg2)) { //top right corner
            return true;
        }
        if (isPointInRect(leftSide, bottomSide, x2, y2, width2, height2, centerOg2)) { //bottom left corner
            return true;
        }
        if (isPointInRect(rightSide, bottomSide, x2, y2, width2, height2, centerOg2)) { //bottom right corner
            return true;
        }
        if (isPointInRect(leftSide, topSide + height1 / 2, x2, y2, width2, height2, centerOg2)) { //left center
            return true;
        }
        if (isPointInRect(rightSide, topSide + height1 / 2, x2, y2, width2, height2, centerOg2)) { //right center
            return true;
        }
        if (isPointInRect(leftSide + width1 / 2, topSide, x2, y2, width2, height2, centerOg2)) { //top center
            return true;
        }
        if (isPointInRect(leftSide + width1 / 2, bottomSide, x2, y2, width2, height2, centerOg2)) { //bottom center
            return true;
        }
        if (isPointInRect(leftSide + width1 / 2, topSide + height1 / 2, x2, y2, width2, height2, centerOg2)) { //center
            return true;
        }
        return false;
    }

    void setGameOver() {
        STATUS = 9;
        menuSelectY = 0;
        
    }



}