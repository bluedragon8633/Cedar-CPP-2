#pragma once
#include<iostream>

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


    int stamp(int x, int y, int width, int height, int drawx, int drawy, bool centerOrigin);
    int stamp(int x, int y, int width, int height, int drawx, int drawy, bool centerOrigin, int rot);
    int stamp(int x, int y, int width, int height, int drawx, int drawy, bool centerOrigin, std::string extra);
    int stamp(int x, int y, int width, int height, int drawx, int drawy, bool centerOrigin,sf::Color color);
    int stamp(int x, int y, int width, int height, int drawx, int drawy, bool centerOrigin, int scaleX, int scaleY);
    void loadTextures();
    void resizeWindow(std::string title, int width, int height);
    void drawRect(int x, int y, int width, int height, sf::Color color);
    void drawRect(int x, int y, int width, int height);
    void drawFloatRect(float x, float y, float width, float height, sf::Color color);
    void drawFloatRect(float x, float y, float width, float height);
    void shadow(int x, int y, int width, int height, int drawx, int drawy, bool centerOrigin);
    void drawOutlineRect(int x, int y, int width, int height,int thicc);

    void print(int x, int y, std::string text, int fontSize, bool centerOrigin, sf::Color col);
    void print(int x, int y, std::string text, int fontSize, bool centerOrigin);
    void print(int x, int y, std::string text, int fontSize, std::string justif);
    void print(int x, int y, std::string text, int fontSize, bool centerOrigin, int concatLen);

}

#endif