#include<iostream>
#include"SFML/Graphics.hpp"
#include"game.h"
#include"general.h"
#include"BasicObjs.h"
#include"KeyHandler.h"

using namespace std;

/*
Contains 
    int tileWidth, tileHeight;
    int tileSize;
    int windowWidth, windowHeight;
    int scale;
*/




Coords::Coords() {
    x = 0;
    y = 0;
}
Coords::Coords(int xin, int yin) {
    x = xin;
    y = yin;
}
void Coords::set(int xin, int yin) {
    x = xin;
    y = yin;
}


sf::Vector2i Area::level() {
    return sf::Vector2i(levelId % width,(levelId - (levelId % width)) / width);
}

Area::Area(int newAreaId,int newLevelId) {
    areaId = newAreaId;
    levelId = newLevelId;
}

void Area::reset(int nw,int nh,int newAreaId,int newLevelId) {
    areaId = newAreaId;
    levelId = newLevelId;
    width = nw;
    height = nh;
}
