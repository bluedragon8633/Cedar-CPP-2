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

    


    void loadData();

    GameConsts();
    /*
    game(string presetPath);
    */
};

class KeyHandler {
    bool left, right, up, down, a, b, enter,space;

    void keyProcess();
};

class GameVars {
    int LEVEL;
    bool DEBUG;

    KeyHandler key;
    
    
};

class GameProfile {
    vector<string> inventoryItems;

};


class Menu {
    int selectX, selectY;
};