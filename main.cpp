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

using namespace std;
using namespace Drawer;


vector<Enemy> enemies;
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
            window.create(sf::VideoMode(game.scrnWidth * game.GAME_SCALE, game.scrnHeight * game.GAME_SCALE), game.TITLE, sf::Style::Close);
            game.loadData();
            loadTextures();
        }
        else if (userIn == "tileInfo") {
            console::log("tile size: " + to_string(tMap.width) + "," + to_string(tMap.height));
            console::log("size of tileMap object: " + to_string(sizeof(tMap)));
            console::log("size of tileMap array: " + to_string(sizeof(tMap.tiles)));
        }
        else if (userIn == "tileData") {
            console::log("tileStr: " + tMap.getTileCostStr(0,1));
        }
        
    }
}

void processGame() {
    key.process();
    tMap.playerCollide();

    for (int i = 0; i < enemies.size(); i++) {
        enemies.at(i).process();
    }
    //t.processAll();
}

void drawGame() {
    window.clear();
    tMap.drawTiles();
    stamp(player);
    
    //for (int i = 0; i < t.enemies.size();i++) {
    //  stamp(t.enemies.at(i));
    //}

    window.display();
}

void process() {
    if (game.vars.STATUS == "splash") {

        SplashScreen s;
        for (int i = 0; i < 60; i++) {
            eventHandle();
            s.draw();
            window.display();
        }

        game.vars.STATUS = "title";
    }
    else if (game.vars.STATUS == "title") {
        TitleScreen t;

        while(game.vars.STATUS == "title") {
            eventHandle();
            key.process();
            t.process(key);
            t.draw();
            window.display();
        }
        
    }
    else if (game.vars.STATUS == "quitConfirm") {
        QuitConfirm t;
        while (game.vars.STATUS == "quitConfirm") {
            eventHandle();
            key.process();
            t.process(key);
            t.draw();
            window.display();
        }
    }
    else if (game.vars.STATUS == "game") {
        processGame();
        drawGame();
    }
}



int main() {
    console::log("Look alive, sunshine!");
    setup();
    console::log("size of baseObj:" + to_string(sizeof(baseObj)));
    console::log("size of Player:" + to_string(sizeof(player)));
    console::log("Window size: " + to_string(window.getSize().x) + "," + to_string(window.getSize().y));
    console::log("game SCALE: " + to_string(game.GAME_SCALE));
    console::log("target framerate = " + to_string(game.FRAME_LIMIT));
    
    while (window.isOpen())
    {
        eventHandle();

        process();
    }
    return 0;
}
