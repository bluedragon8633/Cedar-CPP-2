#pragma once
#include"SFML/Graphics.hpp"
#include"general.h"
//#include"tables.h"
#include<vector>
#include<iostream>
using namespace std;




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
    void set(int xin, int yin);
};
