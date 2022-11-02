#include<iostream>
#include <fstream>
#include<vector>
#include"game.h"
#include"BasicObjs.h"
#include"general.h"
#include"Drawer.h"
#include"Player.h"
#include"enemy.h"
#include"tables.h"
#include"interactiveObj.h"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
using namespace std;
using namespace Drawer;

PlayerObj player;
Tables t;
KeyHandler key;

void process() {
    key.process();
    player.process(key);
    k.process();
}

void draw() {
    window.clear();


    stamp(player);
    stamp(k);


    window.display();
}


int main() {
    
    setup();

    console::log("Window size: " + to_string(window.getSize().x) + "," + to_string(window.getSize().y));
    

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
