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

void console::log(string text) {
    cout << text << endl;
}

void console::log(string text,bool requireKey) {
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Q))) {
        cout << text << endl;
    }

}

void GameConsts::loadData() {
    General g;
    playerStartX = g.findInt("playerStartX");
    playerStartY = g.findInt("playerStartY");
    tileWidth = g.findInt("tileWidth");
    tileHeight = g.findInt("tileHeight");
    scrnWidth = g.findInt("scrnWidth");
    scrnHeight = g.findInt("scrnHeight");
    GAME_SCALE = g.findInt("GAME_SCALE");
    TILE_SIZE = g.findInt("TILE_SIZE");
    FRAME_LIMIT = g.findInt("FRAME_LIMIT");
    playFieldTopY = g.findInt("playFieldTopY");
    playFieldBotY = g.findInt("playFieldBotY");
    playFieldLeftX = g.findInt("playFieldLeftX");
    playFieldRightX = g.findInt("playFieldRightX");
}


GameConsts::GameConsts() {
    loadData();
    TITLE = "Default title";
    vars.STATUS = "splash";
}
GameConsts::GameConsts(string name) {
    loadData();
    TITLE = name;
}



GameVars::GameVars() {
    LEVEL = 0;
    MAP = 0;
    DEBUG = 0;
    mapWidth = 0;
    mapHeight = 0;
}

Coords::Coords() {
    x = 0;
    y = 0;
}
Coords::Coords(int xin, int yin) {
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