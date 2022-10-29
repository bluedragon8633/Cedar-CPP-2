#include<iostream>
#include <fstream>
#include<vector>
#include"game.h"
#include"BasicObjs.h"
#include"general.h"
#include"Drawer.h"
#include"Player.h"
#include"interactiveObj.h"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
using namespace std;
using namespace Drawer;




int main() {
    
    setup();

    PlayerObj player;
    KeyHandler key;

    console::log("Window size: " + to_string(window.getSize().x) + "," + to_string(window.getSize().y));
    window.setFramerateLimit(game.FRAME_LIMIT);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        key.process();

        window.clear();

        player.process(key);
        stamp(player);

        window.display();
    }
    return 0;
}
