#pragma once
#ifndef HEADERNAME_H
#define HEADERNAME_H
#include"Level.h"
#include"Coords.h"
#include"EnemyTable.h"
#include<iostream>
class Enemy {
public:
    const int rockSensingDist = 175;

    EnemyTable et;


    const int maxEnemies = 10;

    const int enemyFrameLengths[6][8] = { {2,5},{6},{0},{1,7,2,7,1},{1},{1} }; //how many frames per animation
    const int enemyFrameData[6][8][16][5] = {
        { //horizontal magenta soldier
            {{368,0,16,16,9},{384,0,16,16,9}}, //walk
            {{368,16,16,16,9},{368,32,32,16,9},{368,48,32,16,9},{368,64,32,16,9},{368,80,32,16,9}} //shoot
        },{ //bullet
            {{352,0,16,5},{352,16,16,16},{352,32,16,16},{352,48,16,16},{352,64,16,16},{352,80,16,16}}

        },{ //diagonal bouncing enemy
            {{208,48,16,16,9}}
        },{ //vagina rock
            {{208,64,16,16,4}},
            {{208,64,16,16,4},{208,80,16,16,4},{208,96,16,16,4},{208,112,16,16,4},{208,128,16,16,4},{208,144,16,16,4},{208,160,16,16,4}},
            {{208,160,16,16,1},{208,176,16,16,1}},
            {{208,160,16,16,4},{208,144,16,16,4},{208,128,16,16,4},{208,112,16,16,4},{208,96,16,16,4},{208,80,16,16,4},{208,64,16,16,4}},
            {{64,0,16,16,2}}
        },{ //eft bullet
            {{288,0,16,8,1}}
        },{ //right bullet
            {{288,0,16,8,1}}
        }
    };
    
    int enemiesLeft = 1;

    Enemy();
    void setNewTable(EnemyTable eTable);
    int getEnemiesLeft();
    int var(int enemyID, std::string varID);
    void setvar(int address, std::string name, int newVal);
    void setvar(int address, std::string name, bool newVal);
    void incvar(int address, std::string name, int newVal);
    void setNewAnimation(int address, int id);
    void frameProcess(int address);
    bool move(int address, int offsetX, int offsetY, bool collideWithWall);
    void setPosition(int address, int newX, int newY);

    void fullProcess(Coord player);

    void makeEnemy(int x, int y, int type);
};

#endif