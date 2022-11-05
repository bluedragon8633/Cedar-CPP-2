#pragma once
#include"SFML/Graphics.hpp"
#include"general.h"
//#include"tables.h"
#include<vector>
#include<iostream>
using namespace std;

class console{
public:
    void static log(string text);
    void static log(string text, bool requireKey);
};

class GameVars {
public:
    int MAP;
    int LEVEL;
    bool DEBUG;
    string STATUS = "splash";
    int mapWidth, mapHeight;

    GameVars();
};

class GameConsts { //contains general info. TileSize, WindowSize
public:

    int tileWidth, tileHeight;
    int playerStartX, playerStartY;
    int TILE_SIZE;
    int windowWidth, windowHeight;
    int GAME_SCALE;
    int scrnWidth, scrnHeight;
    int FRAME_LIMIT;
    int playFieldTopY, playFieldBotY;
    int playFieldLeftX, playFieldRightX;
    string TITLE;
    GameVars vars;

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

    void process();
};

class Tiles {
public:
    vector<int> tileCostumeX[10][10];
    vector<int> tileCostumeY[10][10];

};



class GameProfile {
public:
    vector<string> inventoryItems;

};


class Menu {
public:
    int selectX, selectY;
};

class TextMenu : public Menu {
public:
    vector<string> options;

    TextMenu(vector<string> newOptions,int startPos);
};