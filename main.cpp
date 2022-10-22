#include<iostream>
#include <fstream>
#include<vector>
#include"game.h"
#include"BasicObjs.h"
#include"general.h"
#include"Drawer.h"
#include"Player.h"
#include"interactiveObj.h"
#include"SFML/Graphics.hpp"
using namespace std;











int main() {
	GameConsts game;
	Drawer d(game);
	PlayerObj player;

	while (d.window.isOpen()) {
        while (d.window.pollEvent(d.e))
        {
            if (d.e.type == sf::Event::Closed)
                d.window.close();
        }
	}
    return 0;
}