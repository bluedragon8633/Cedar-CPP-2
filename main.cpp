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
	Drawer d(game);
	PlayerObj player;
    cout << "frameLimit: " << game.FRAME_LIMIT << endl;
    cout << "scrnSize: " << game.scrnWidth << "," << game.scrnHeight << endl;
    /*
    
	while (d.window.isOpen()) {
        while (d.window.pollEvent(d.e))
        {
            if (d.e.type == sf::Event::Closed)
                d.window.close();
        }


        d.window.display();
	}
    return 0;*/
    d.window.setFramerateLimit(game.FRAME_LIMIT);
    while (d.window.isOpen())
    {
        // Event processing
        sf::Event event;
        while (d.window.pollEvent(event))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                d.window.close();
        }
        // Clear the whole window before rendering a new frame
        d.window.clear();
        // Draw some graphical entities
        // End the current frame and display its contents on screen
        d.window.display();
    }
    return 0;
}