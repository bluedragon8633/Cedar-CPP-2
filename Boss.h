#pragma once
#include"Level.h"
#include<iostream>
#include"Enemy.h"
class Boss {
public:
    int bossID = -1;
    int counter = 0;
    bool isBossFinal = false;
    const int maxEnemies = 4;
    int enemyInts[4][18] = { 0 }; //first field == maxEnemies
    const int enemyFrameLengths[4][8] = { {2,6,14} }; //how many frames per animation
    const int enemyFrameData[4][8][16][5] = { //enemy,animation,frame,frameData
        { //green soldier boss
            {{224,96,32,32,4},{256,64,32,32,4}},
            {{224,96,32,32,4},{256,96,32,32,4},{288,96,32,32,4},{320,96,32,32,4},{352,96,32,32,4},{384, 96, 32, 32,4}}, //shoot
            {{224,128,32,32,4},{256,128,32,32,4},{288,128,32,32,4},{320,128,32,32,4},{352,128,32,32,4},{384, 128, 32, 32,4}, //die
            {224,160,32,32,4},{256,160,32,32,4},{288,160,32,32,4},{320,160,32,32,4},{352,160,32,32,4},{384, 160, 32, 32,4},
            {224,192,32,32,4},{256,192,32,32,4}}
        }
    };
    bool enemyBools[4][6] = { 0 }; //exists, visible, vulnerable, collidesWithWall, centeredOrigin, flip
    int enemiesLeft = 1;

    Boss();
    int getEnemiesLeft();
    int var(int enemyID, std::string varID);
    void setvar(int address, std::string name, int newVal);
    void setvar(int address, std::string name, bool newVal);
    void incvar(int address, std::string name, int newVal);
    void setNewAnimation(int address, int id);
    void frameProcess(int address);
    bool move(int address, int offsetX, int offsetY, bool collideWithWall);
    void setPosition(int address, int newX, int newY);
    EnemyTable makeBullet(int x, int y, int xv, EnemyTable e);
    EnemyTable fullProcess(EnemyTable e);

    void makeEnemy(int x, int y, int type);

    void loadBoss();
};
