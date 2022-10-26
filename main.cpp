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



int main() {
    
	GameConsts game("Mimi's Grand Journey!");
	PlayerObj player;

    window.setFramerateLimit(game.FRAME_LIMIT);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
    return 0;
}
