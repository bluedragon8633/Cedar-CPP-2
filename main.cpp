#include<iostream>
#include <fstream>
#include<vector>
#include"game.h"
#include"BasicObjs.h"
#include"general.h"
#include"Drawer.h"
#include"Player.h"
#include"enemy.h"
#include"tile.h"
#include"UI.h"
#include"interactiveObj.h"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"KeyHandler.h"

using namespace std;
using namespace Drawer;


PlayerObj player(game);
TileMap tileMap(0,1);
KeyHandler key;

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
            console::log("tile size: " + to_string(tileMap.width) + "," + to_string(tileMap.height));
            console::log("size of tileMap object: " + to_string(sizeof(tileMap)));
            console::log("size of tileMap array: " + to_string(sizeof(tileMap.tiles)));
        }
        else if (userIn == "tileData") {
            console::log("tileStr: " + tileMap.getTileCostStr(0,1));
        }
        
    }
}

void processGame() {
    key.process();
    player.process(key,game);
    //t.processAll();
}

void drawGame() {
    window.clear();

    tileMap.drawTiles();
    
    stamp(tileMap.tile, 0 * game.TILE_SIZE + tileMap.offsetX, 0 * game.TILE_SIZE + tileMap.offsetY);
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
    
    setup();
    console::log("size of gamevars:" + to_string(sizeof(GameVars)));
    console::log("size of TextObj:" + to_string(sizeof(TextObj)));
    console::log("Window size: " + to_string(window.getSize().x) + "," + to_string(window.getSize().y));
    console::log("game SCALE: " + to_string(game.GAME_SCALE));
    while (window.isOpen())
    {
        eventHandle();

        process();
    }
    return 0;
}
