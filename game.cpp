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

void console::log(string text) {
    cout << text << endl;
}

void console::log(string text,bool requireKey) {
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Q))) {
        cout << text << endl;
    }

}

void GameConsts::loadData() {
    General g;
    playerStartX = g.findInt("playerStartX");
    playerStartY = g.findInt("playerStartY");
    tileWidth = g.findInt("tileWidth");
    tileHeight = g.findInt("tileHeight");
    scrnWidth = g.findInt("scrnWidth");
    scrnHeight = g.findInt("scrnHeight");
    GAME_SCALE = g.findInt("GAME_SCALE");
    FRAME_LIMIT = g.findInt("FRAME_LIMIT");
    playFieldTopY = g.findInt("playFieldTopY");
    playFieldBotY = g.findInt("playFieldBotY");
    playFieldLeftX = g.findInt("playFieldLeftX");
    playFieldRightX = g.findInt("playFieldRightX");
}


GameConsts::GameConsts() {
    loadData();
    TITLE = "Default title";
}
GameConsts::GameConsts(string name) {
    loadData();
    TITLE = name;
}

void KeyHandler::process() {
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



