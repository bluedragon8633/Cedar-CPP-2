#pragma once

#include"Level.h"
#include"Enemy.h"
#include"Portals.h"
#include"Collectibles.h"
#include"Coords.h"

class Player {
public:
    const int maxIdle = 500;
    const int speed = 4;
    Coord position;
    float armourLevel = 1;
    int x, y; int xv = 0; int yv = 0;
    int sourceX = 64; int sourceY = 0; int sourceRow = 0;
    float hp;
    int maxhp;
    bool isMortal = true; int mortalI = 0; const int mortalLength = 50;
    int frameCounter = 0; int frame = -1;
    bool touchingStats = false;
    int idleCounter = 0;
    int scaleX, scaleY;
    int resX = 16; int resY = 16;
    int spinAtkTimer = -1; int atkFrame = 0; bool atkReady = true;
    bool isBlasting = false;
    int blastI = 0;
    const int blastLength = 15;
    const int blastSpeed = 4;
    int width, height;

    Player(int maxHpIn, int startX, int startY, int scale);
    void move(int offsetX, int offsetY);

    void setPosition(int newX, int newY);

    bool checkPortal(Portal port);
    collectibles processCollisions(collectibles col);

    void healthProcess(float decrement);
    void healthProcess();

    void tryKillEnemy(int address, Enemy e);

    void processFrames();


    void spinAtkProcess();


    bool keyReact(bool up, bool down, bool right, bool left, bool kA, bool kB, bool collU, bool collD, bool collR, bool collL);

    
};

