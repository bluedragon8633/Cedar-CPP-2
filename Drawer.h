#pragma once
#include<iostream>
#include"game.h"
#ifndef MY_HEADER_H
#define MY_HEADER_H
namespace Drawing {
     extern sf::Texture atlas;
     extern sf::Font font;
     extern sf::RectangleShape rect;
     extern sf::Text textObj;
     extern sf::Sprite block;
     extern sf::Sprite tile;
     extern sf::Sprite blockBullet;
     extern sf::RenderWindow window;
     extern sf::RectangleShape rectangle;
     extern sf::Event e;


    void resizeWindow(std::string title, int width, int height);

    void loadTextures();
    void stamp(int x, int y, int width, int height, int drawx, int drawy, bool centerOrigin);
    void stamp(animObj a);

}

#endif
