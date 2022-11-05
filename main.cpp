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
#include"interactiveObj.h"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"

using namespace std;
using namespace Drawer;


PlayerObj player(game);
TileMap tileMap(0,1);
KeyHandler key;

void process() {
    key.process();
    player.process(key,game);
    //t.processAll();
}

void draw() {
    window.clear();

    tileMap.drawTiles();
    
    stamp(tileMap.tile, 0 * game.TILE_SIZE + tileMap.offsetX, 0 * game.TILE_SIZE + tileMap.offsetY);
    stamp(player);
    
    //for (int i = 0; i < t.enemies.size();i++) {
    //  stamp(t.enemies.at(i));
    //}

    window.display();
}


int main() {
    
    setup();

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
        draw();
    }
    return 0;
}
