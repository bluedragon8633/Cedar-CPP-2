#include"Boss.h"
#include<iostream>
#include<fstream>
#include<string>
#include"Level.h"
#include"Enemy.h"
using namespace std;
Boss::Boss() {
    //0 = x, 1 = y, 2 = xv, yv, 4 =  hp, maxhp, 6 = frameSourceX,frameSourceY,8 = resX,resY,10 = width,height,type,frameID,14 = frameLen,frameCounter
   /*
   0,1 = x,y coordinates
   2,3 = xv,yv
   4,5 = hp,maxHP
   6,7 = frameSourceX,frameSourceY
   8,9 = resX,resY
   10,11 = width,height
   12,13 = type,frameID
   14,15 = frameLen,frameCounter
   16 = lenOfAnimation
   17 = animationID
   */


   /*
   1 dimension = each cell is a different type (max#ofTypes)
   2 dimension = each cell is a different animation (max#ofAnimations = 8)
   3 dimension = each cell is different frame (max#ofFramesPerAnimation = 16)
   4 dimension = x/y/width/height coordinates of frame on atlas/frame length (5)
   */


}
int Boss::getEnemiesLeft() {
    int num = 0;
    for (int i = 0; i < maxEnemies; i++) {
        if (enemyBools[i][0]) {
            num++;
        }
    }
    return num;
}


int Boss::var(int enemyID, std::string varID) { //returns values from enemyInts in simplified form
    if (varID == "x") {
        return Boss::enemyInts[enemyID][0];
    }
    else if (varID == "y") {
        return Boss::enemyInts[enemyID][1];
    }
    else if (varID == "xv") {
        return Boss::enemyInts[enemyID][2];
    }
    else if (varID == "yv") {
        return Boss::enemyInts[enemyID][3];
    }
    else if (varID == "hp") {
        return Boss::enemyInts[enemyID][4];
    }
    else if (varID == "maxhp" || varID == "maxHP") {
        return Boss::enemyInts[enemyID][5];
    }
    else if (varID == "frameSourceX") {
        return Boss::enemyInts[enemyID][6];
    }
    else if (varID == "frameSourceY") {
        return Boss::enemyInts[enemyID][7];
    }
    else if (varID == "resX") {
        return Boss::enemyInts[enemyID][8];
    }
    else if (varID == "resY") {
        return Boss::enemyInts[enemyID][9];
    }
    else if (varID == "width") {
        return Boss::enemyInts[enemyID][10];
    }
    else if (varID == "height") {
        return Boss::enemyInts[enemyID][11];
    }
    else if (varID == "type") {
        return Boss::enemyInts[enemyID][12];
    }
    else if (varID == "frameID") {
        return Boss::enemyInts[enemyID][13];
    }
    else if (varID == "frameLen") {
        return Boss::enemyInts[enemyID][14];
    }
    else if (varID == "frameCounter") {
        return Boss::enemyInts[enemyID][15];
    }
    else if (varID == "lenOfAnimation") {
        return Boss::enemyInts[enemyID][16];
    }
    return 0;
}

void Boss::setvar(int address, std::string name, int newVal) {
    if (address < Boss::maxEnemies) {
        if (name == "x") {
            Boss::enemyInts[address][0] = newVal;
            return;
        }
        if (name == "y") {
            Boss::enemyInts[address][1] = newVal;
            return;
        }
        if (name == "xv") {
            Boss::enemyInts[address][2] = newVal;
            return;
        }
        if (name == "yv") {
            Boss::enemyInts[address][3] = newVal;
            return;
        }
        if (name == "hp") {
            Boss::enemyInts[address][4] = newVal;
            return;
        }
    }
}

void Boss::setvar(int address, std::string name, bool newVal) {
    if (address < Boss::maxEnemies) {
        if (name == "exists") {
            Boss::enemyBools[address][0] = newVal;
            return;
        }
        if (name == "visible") {
            Boss::enemyBools[address][1] = newVal;
            return;
        }
        if (name == "vulnerable") {
            Boss::enemyBools[address][2] = newVal;
            return;
        }
        if (name == "collidesWithWall") {
            Boss::enemyBools[address][3] = newVal;
            return;
        }
        if (name == "centeredOrigin") {
            Boss::enemyBools[address][4] = newVal;
            return;
        }
        if (name == "flip") {
            Boss::enemyBools[address][5] = newVal;
            return;
        }
    }
}

void Boss::incvar(int address, std::string name, int newVal) {
    if (address < Boss::maxEnemies) {
        if (name == "x") {
            Boss::enemyInts[address][0] += newVal;
            return;
        }
        if (name == "y") {
            Boss::enemyInts[address][1] += newVal;
            return;
        }
        if (name == "xv") {
            Boss::enemyInts[address][2] += newVal;
            return;
        }
        if (name == "yv") {
            Boss::enemyInts[address][3] += newVal;
            return;
        }
        if (name == "hp") {
            Boss::enemyInts[address][4] += newVal;
            return;
        }
    }
}

void Boss::setNewAnimation(int address, int id) {
    Boss::enemyInts[address][17] = id;
    Boss::enemyInts[address][13] = 0;
    Boss::enemyInts[address][15] = 0;
    Boss::enemyInts[address][6] = enemyFrameData[var(address, "type")][id][0][0]; //set sourceX
    Boss::enemyInts[address][7] = enemyFrameData[var(address, "type")][id][0][1]; //set sourceY
    Boss::enemyInts[address][10] = enemyFrameData[var(address, "type")][id][0][2]; //set width
    Boss::enemyInts[address][11] = enemyFrameData[var(address, "type")][id][0][3]; //set height
    Boss::enemyInts[address][14] = enemyFrameData[var(address, "type")][id][0][4]; //set frame length
    Boss::enemyInts[address][16] = enemyFrameLengths[var(address, "type")][id];
}

void Boss::frameProcess(int address) {
    int lastFrameOfLoop = 1;
    if (var(address, "frameCounter") == var(address, "frameLen")) { //if frameCounter == frameLength ; 
        Boss::enemyInts[address][15] = 0;
        if (var(address, "frameID") == var(address, "lenOfAnimation") - 1) {
            Boss::enemyInts[address][13] = 0;
        }
        else {
            Boss::enemyInts[address][13]++;
        }
        Boss::enemyInts[address][6] = enemyFrameData[var(address, "type")][var(address, "animationID")][var(address, "frameID")][0]; //set sourceX
        Boss::enemyInts[address][7] = enemyFrameData[var(address, "type")][var(address, "animationID")][var(address, "frameID")][1]; //set sourceY
        Boss::enemyInts[address][10] = enemyFrameData[var(address, "type")][var(address, "animationID")][var(address, "frameID")][2]; //set width
        Boss::enemyInts[address][11] = enemyFrameData[var(address, "type")][var(address, "animationID")][var(address, "frameID")][3]; //set height
        Boss::enemyInts[address][14] = enemyFrameData[var(address, "type")][var(address, "animationID")][var(address, "frameID")][4]; //set frame length
    }
    else {
        Boss::enemyInts[address][15]++;
    }
}

bool Boss::move(int address, int offsetX, int offsetY, bool collideWithWall) {
    if (collideWithWall) {
        if (!level::collisionDetect(var(address, "x"), var(address, "y"), var(address, "width"), var(address, "height"), offsetX, offsetY)) {
            incvar(address, "x", offsetX);
            incvar(address, "y", offsetY);
            return true;
        }
        else {
            return false;
        }
    }
    else {
        incvar(address, "x", offsetX);
        incvar(address, "y", offsetY);
        return true;
    }
    return true;

}

void Boss::setPosition(int address, int newX, int newY) {
    setvar(address, "x", newX);
    setvar(address, "y", newY);
}

EnemyTable Boss::makeBullet(int x,int y, int xv, EnemyTable e) {
    Enemy tempEnemy;
    tempEnemy.setNewTable(e);
    tempEnemy.makeEnemy(var(0,"x"),var(0,"y"),4);
    return tempEnemy.et;
}

EnemyTable Boss::fullProcess(EnemyTable e) {
    EnemyTable enemy = e;
    if (Boss::enemiesLeft > 0) {
        for (int i = 0; i < Boss::maxEnemies; i++) {
            if (Boss::enemyBools[i][0]) {
                switch (var(i, "type")) {
                case 0: //green boss
                    if (counter == 128) {
                        counter = 0;
                    }
                    else {
                        counter++;
                    }
                    if (counter < 32) {
                        move(i, 2, 0, true);
                    }
                    else if (counter < 64) {
                        move(i, -2, 0, true);
                    }
                    else if (counter == 96) {
                        enemy = makeBullet(var(i, "x"), var(i, "y"), -2,enemy);
                    }



                    break;

                }
                frameProcess(i);
            }
        }
    }
    return enemy;
}

void Boss::makeEnemy(int x, int y, int type) {
    bool foundSlot = false;
    int i = 0;
    while (i < Boss::maxEnemies - 1 && !foundSlot) {
        if (!Boss::enemyBools[i][0]) {
            foundSlot = true;
            Boss::enemyInts[i][0] = x; //set x location
            Boss::enemyInts[i][1] = y; //set y location
            Boss::enemyInts[i][12] = type; //set typeID
            Boss::enemyBools[i][0] = true; //set exists
            Boss::enemyBools[i][1] = true; //set visibility
            Boss::enemyInts[i][6] = enemyFrameData[type][0][0][0]; //set sourceX
            Boss::enemyInts[i][7] = enemyFrameData[type][0][0][1]; //set sourceY
            Boss::enemyInts[i][10] = enemyFrameData[type][0][0][2]; //set width
            Boss::enemyInts[i][11] = enemyFrameData[type][0][0][3]; //set height
            Boss::enemyInts[i][14] = enemyFrameData[type][0][0][4]; //set frame length
            Boss::enemyInts[i][16] = enemyFrameLengths[type][0];
            Boss::enemyInts[i][17] = 0;
            Boss::enemiesLeft++;
        }
        i++;
    }
    if (foundSlot) {
        frameProcess(i);
    }
}

void Boss::loadBoss() {
    for (int i = 0; i < maxEnemies; i++) {
        enemyBools[i][0] = false;
    }
    string plainText = "000-000-000-000-000-000-000-000";
    string temp = "";
    ifstream ScrnData("./assets/bosses.txt");
    bool found = false;
    //cout << "created strings for portal" << endl;
    while (!found) {
        getline(ScrnData, temp);
        //cout << "got line " << temp.substr(0,3) << endl;
        if (temp == "end") {
            //cout << "ended data search" << endl;
            break;
        }
        else if (level::LEVEL == stoi(temp.substr(0, 3))) {
            found = true;
            //cout << "found level's portal" << endl;
            break;
        }
    }
    if (found) {
        plainText = temp;
        //writes raw data to values
        level::isBossRoom = true;
        int x = stoi(plainText.substr(4, 3));
        int y = stoi(plainText.substr(8, 3));
        isBossFinal = (stoi(plainText.substr(12, 1)) == 1);

        //adjusts values to be readable
        x = x * level::finalTileSize;
        y = y * level::finalTileSize;
        setvar(0, "x", x);
        setvar(0, "y", y);
        makeEnemy(x,y,0);
    }
}