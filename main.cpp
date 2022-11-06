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

using namespace std;
using namespace Drawer;


PlayerObj player(game);
TileMap tileMap(0,1);
KeyHandler key;

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
        for (int i = 0; i < 30; i++) {
            s.draw();
            window.display();
        }

        game.vars.STATUS = "title";
    } else if (game.vars.STATUS == "title") {

    } else if (game.vars.STATUS == "game") {
        processGame();
        drawGame();
    }
}


int main() {
    
    setup();
    console::log("size of gamevars:" + to_string(sizeof(GameVars)));
    console::log("size of textObj:" + to_string(sizeof(sf::Text)));
    console::log("Window size: " + to_string(window.getSize().x) + "," + to_string(window.getSize().y));
    console::log("game TILE_SIZE: " + to_string(game.TILE_SIZE));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        process();
    }
    return 0;
}
