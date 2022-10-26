#pragma once
#include"SFML/Graphics.hpp"
#include"general.h"
#include<vector>
#include<iostream>
using namespace std;

class GameConsts { //contains general info. TileSize, WindowSize
public:

    int tileWidth, tileHeight;
    int TILE_SIZE;
    int windowWidth, windowHeight;
    int GAME_SCALE;
    int scrnWidth, scrnHeight;
    int FRAME_LIMIT;
    string TITLE;
    


    void loadData();

    GameConsts(string name);
    GameConsts();
    /*
    game(string presetPath);
    */
};

class KeyHandler {
public:
    bool left, right, up, down, a, b, enter,space;

    void keyProcess();
};

class Tiles {
public:
    vector<int> tileCostumeX[10][10];
    vector<int> tileCostumeY[10][10];

};

class GameVars {
public:
    int LEVEL;
    bool DEBUG;

    int mapWidth, mapHeight;
    

    KeyHandler key;
    
    
};

class GameProfile {
public:
    vector<string> inventoryItems;

};


class Menu {
public:
    int selectX, selectY;
};