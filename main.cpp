#include<iostream>
#include <fstream>
#include<vector>
#include"game.h"
#include"BasicObjs.h"
#include"general.h"
#include"Drawer.h"
#include"enemy.h"
#include"tile.h"
#include"UI.h"
#include"interactiveObj.h"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"KeyHandler.h"
#include"GlobalVars.h"

using namespace std;
using namespace Drawer;
using namespace Global;

EnemyTable enemies;
TileMap tMap(0,0);


void eventHandle() {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    if (key.space) {
        string userIn;
        cout << "Enter command: " << endl;
        cin >> userIn;
        if (userIn == "refresh") {
            window.create(sf::VideoMode(Global::scrnWidth * Global::GAME_SCALE, Global::scrnHeight * Global::GAME_SCALE), Global::TITLE, sf::Style::Close);
            Global::loadData();
            loadTextures();
        }
        else if (userIn == "tileInfo") {
            console.log("tile size: " + to_string(tMap.width) + "," + to_string(tMap.height));
            console.log("size of tileMap object: " + to_string(sizeof(tMap)));
            console.log("size of tileMap array: " + to_string(sizeof(Global::tiles)));
        }
        else if (userIn == "tileData") {
            console.log("tileStr: " + tMap.getTileCostStr(0,1));
        }
        
    }
}

void processGame() {
    key.process();
    tMap.playerCollide();
    if (tMap.getJustLoaded()) {
        enemies.clear();
        enemies.addEnemies(tMap.getEnemies());
    }
    //console.log("about to process enemies");
    enemies.processAll();
    //console.log("finished processing");
    //t.processAll();
}

void drawGame() {
    window.clear();
    tMap.drawTiles();
    stamp(player);
    //console.log("enemies left: " + to_string(enemies.enemiesLeft()));
    if (enemies.enemiesLeft() > 0) {
        for (int i = 0; i < enemies.enemiesLeft(); i++) {
            //console.log("about to stamp");
            stamp(enemies.enemies.at(i));
        }
    }
    //stamp(0,16,48,48,0,0,false);


}

void process() {
    if (Global::STATUS == "splash") {

        SplashScreen s;
        for (int i = 0; i < 60; i++) {
            eventHandle();
            s.draw();
            window.display();
        }

        Global::STATUS = "title";
    }
    else if (Global::STATUS == "title") {
        TitleScreen t;

        while(Global::STATUS == "title") {
            eventHandle();
            key.process();
            t.process(key);
            t.draw();
            window.display();
        }
        
    }
    else if (Global::STATUS == "quitConfirm") {
        QuitConfirm t;
        while (Global::STATUS == "quitConfirm") {
            eventHandle();
            key.process();
            t.process(key);
            t.draw();
            window.display();
        }
    }
    else if (Global::STATUS == "game") {
        HUD h;
        tMap.load(Global::MAP,Global::LEVEL);
        console.log("Initialized game");
        while (Global::STATUS == "game") {
            eventHandle();
            processGame();
            drawGame();

            h.draw();
            window.display();
        }

    }
}



int main() {
    console.log("Look alive, sunshine!");
    setup();
    console.log("size of baseObj:" + to_string(sizeof(baseObj)));
    console.log("size of Player:" + to_string(sizeof(player)));
    console.log("Window size: " + to_string(window.getSize().x) + "," + to_string(window.getSize().y));
    console.log("game SCALE: " + to_string(Global::GAME_SCALE));
    console.log("target framerate = " + to_string(Global::FRAME_LIMIT));
    
    while (window.isOpen())
    {
        eventHandle();

        process();
    }
    return 0;
}
