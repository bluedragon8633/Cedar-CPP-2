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

vector<Enemy> enemies;
PlayerObj player(game);
TileMap tMap(0,1);
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
    player.process(key,game);
    if (tMap.isObjOnWall(player,"x")) {
        player.move(-player.xv,-player.yv,game);
    }
    for (int i = 0; i < enemies.size(); i++) {
        enemies.at(i).process();
    }
    //t.processAll();
}

void drawGame() {
    window.clear();

    tMap.drawTiles();
    
    stamp(16, 0, 16,16,48,32, false);
    //stamp(tMap.tile, 0 * game.TILE_SIZE + tMap.offsetX, 0 * game.TILE_SIZE + tMap.offsetY);
    if (tMap.isObjOnWall(player)) {
        stamp(32,0,player.width,player.height,player.x,player.y, player.centerOrigin);
    }
    else {
        stamp(16, 0, player.width, player.height, player.x, player.y, player.centerOrigin);
    }
    //cout << "isTileOverlappingPlayer: " << player.isObjOverlapping(interactiveObj(48, 32, 16, 16)) << "; player: " << player.x << ", " << player.y << "; " << player.width << ", " << player.height << endl;
    //cout << "Tile: 48,32,16,16" << endl;
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
