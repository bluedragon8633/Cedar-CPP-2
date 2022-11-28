#pragma once
#include<iostream>
#include"game.h"
#include"BasicObjs.h"
#include"Player.h"
#include"primitiveUI.h"
//#include"Enemy.h"
#ifndef MY_HEADER_H
#define MY_HEADER_H
namespace Drawer {
    extern sf::Texture atlas;
    extern sf::Font font;
    extern sf::RectangleShape rect;
    extern sf::Text textObj;
    extern sf::Sprite block;
    //extern sf::Sprite tile;
    extern sf::RenderWindow window;
    extern sf::RectangleShape rectangle;
    extern sf::Event e;
    extern GameConsts game;
    extern Area area;
    extern PlayerObj player;
    extern KeyHandler key;
	const int shadowAlpha = 200;

    void resizeWindow(std::string title, int width, int height);
	void setup();
    void loadTextures();
    void stamp(int x, int y, int width, int height, int drawx, int drawy, bool centerOrigin);
    void stamp(animObj a);
    void stamp(Billboard a);
    void stamp(Billboard a,int brightness);
    void stamp(frameObj a, int x, int y);
    void stamp(frameObj a, int x, int y,int zoom);
    void freezeScrnFor(int frames);

    void drawRect(int x,int y,int width,int height,sf::Color col);
    void drawRect(sf::IntRect r, sf::Color col);

    void print(int x, int y, std::string text, int fontSize, bool centerOrigin, sf::Color col);
    void print(int x, int y, std::string text, int fontSize, bool centerOrigin);
    void print(int x, int y, std::string text, int fontSize, bool centerOrigin, int concatLen);
    void print(TextMenu t);
}

#endif
