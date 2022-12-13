#pragma once
#include"game.h"
#ifndef GLOBAL_H
#define GLOBAL_H
namespace Global {
	//extern GameConsts game;
    extern int MAP;
    extern int LEVEL;
    extern bool DEBUG;
    extern string STATUS;
    extern int mapWidth, mapHeight;
    extern int playerStartX, playerStartY;
    extern int startLvl, startMap;
    
    extern int tiles[25][15][2];

    extern int tileWidth, tileHeight;
    extern int TILE_SIZE;
    extern int windowWidth, windowHeight;
    extern int GAME_SCALE;
    extern int scrnWidth, scrnHeight;
    extern int FRAME_LIMIT;
    extern int playFieldTopY, playFieldBotY;
    extern int playFieldLeftX, playFieldRightX;
    extern string TITLE;

    void loadData();
    void loadDefault();
}

#endif
