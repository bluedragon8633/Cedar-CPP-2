#include<iostream>
#include"SFML/Graphics.hpp"
#include"game.h"
#include"general.h"
#include"BasicObjs.h"
using namespace std;

/*
Contains 
    int tileWidth, tileHeight;
    int tileSize;
    int windowWidth, windowHeight;
    int scale;
*/

void GameConsts::loadData() {
    General g;
    tileWidth = g.findInt("tileWidth");
}


GameConsts::GameConsts() {
    loadData();
}

void KeyHandler::keyProcess() {
    //general handling- do not touch
    left = (sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
    right = (sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
    up = (sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
    down = (sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
    space = (sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
    a = (sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
    b = (sf::Keyboard::isKeyPressed(sf::Keyboard::X));
    enter = (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter));
}



