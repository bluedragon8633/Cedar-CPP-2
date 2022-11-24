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




class Area {
public:
    int width = 2; int height = 2;
    int areaId = 0; //dungeon/area ID; number added to file name for that dungeon's level data
    int levelId = 0;

    Area(int newAreaId,int newLevelId);
    void reset(int nw, int nh, int newAreaId, int newLevelId);
    sf::Vector2i level();
};

class GameProfile {
public:
    vector<string> inventoryItems;

};

class Coords {
public:
    int x;
    int y;
    Coords();
    Coords(int xin,int yin);
};