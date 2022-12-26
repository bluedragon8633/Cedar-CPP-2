#include "SFML/Graphics.hpp"
#include<iostream>
#include"Level.h"
namespace Drawing {
    sf::Texture atlas;
    sf::Font font;
    sf::RectangleShape rect(sf::Vector2f(1, 1));
    sf::Text textObj;
    sf::Sprite block;
    sf::Sprite tile;
    sf::Sprite blockBullet;
    const int shadowAlpha = 200;
    sf::RenderWindow window(sf::VideoMode(480,480), "Blank Window");
    sf::RectangleShape rectangle(sf::Vector2f(32, 32));
    sf::Event e;
    

    void resizeWindow(std::string title,int width,int height) {
        window.setSize(sf::Vector2u(width, height));
        window.setTitle(title);
        window.setFramerateLimit(45);
    }

    void loadTextures() {

        if (!atlas.loadFromFile("./assets/atlas.png", sf::IntRect(0, 0, 512, 512))) { //tlX,tlY,width,height 
            std::cout << "Atlas failed to load" << std::endl;
        }
        if (!font.loadFromFile("./assets/GBfont.ttf"))
        {
            std::cout << "Test failed to load" << std::endl;
        }
        else {
            textObj.setFont(Drawing::font);
        }
        blockBullet.setTexture(Drawing::atlas);
        blockBullet.setTextureRect(sf::IntRect(0, 8, 8, 3));
        blockBullet.setScale(sf::Vector2f(4.f, 4.f));

        Drawing::block.setTexture(Drawing::atlas);


    }

    int stamp(int x, int y, int width, int height, int drawx, int drawy, bool centerOrigin) {
        block.setTexture(atlas);
        block.setTextureRect(sf::IntRect(x, y, width, height));
        if (centerOrigin) {
            block.setOrigin(float(width / 2), float(height / 2));
        }
        else {
            block.setOrigin(0, 0);
        }
        block.setScale(4.f, 4.f);
        block.setPosition(float(drawx), float(drawy));
        window.draw(block);
        return 0;
    }
    int stamp(int x, int y, int width, int height, int drawx, int drawy, bool centerOrigin, int rot) {
        block.setTexture(atlas);
        block.setTextureRect(sf::IntRect(x, y, width, height));
        block.setRotation(float(rot));
        if (centerOrigin) {
            block.setOrigin(float(width / 2), float(height / 2));
        }
        else {
            block.setOrigin(0, 0);
        }
        block.setScale(4.f, 4.f);
        block.setPosition(float(drawx), float(drawy));
        window.draw(block);
        block.setRotation(0);
        return 0;
    }
    int stamp(int x, int y, int width, int height, int drawx, int drawy, bool centerOrigin,std::string extra) {
        block.setTexture(atlas);
        block.setTextureRect(sf::IntRect(x, y, width, height));
        if (centerOrigin) {
            block.setOrigin(float(width / 2), float(height / 2));
        }
        else {
            block.setOrigin(0, 0);
        }
        block.setScale(3.f, 3.f);
        block.setPosition(float(drawx), float(drawy));
        if (extra=="HUD") {
            block.move(float( - level::hudOffset), 0.f);
        }
        window.draw(block);
        return 0;
    } 
    int stamp(int x, int y, int width, int height, int drawx, int drawy, bool centerOrigin, int scaleX, int scaleY) {
        block.setTexture(atlas);
        block.setTextureRect(sf::IntRect(x, y, width, height));
        if (centerOrigin) {
            block.setOrigin(float(width / 2), float(height / 2));
        }
        else {
            block.setOrigin(0, 0);
        }
        block.setScale(float(scaleX), float(scaleY));
        block.setPosition(float(drawx), float(drawy));
        window.draw(block);
        return 0;
    }
    int stamp(int x, int y, int width, int height, int drawx, int drawy, bool centerOrigin, sf::Color color) {
        block.setTexture(atlas);
        block.setTextureRect(sf::IntRect(x, y, width, height));
        block.setColor(color);
        if (centerOrigin) {
            block.setOrigin(float(width / 2), float(height / 2));
        }
        else {
            block.setOrigin(0, 0);
        }
        block.setScale(4.f, 4.f);
        block.setPosition(float(drawx), float(drawy));
        window.draw(block);
        block.setColor(sf::Color(255,255,255,255));
        return 0;
    }

    void drawRect(int x, int y, int width, int height, sf::Color color) {
        rect.setPosition(float(x), float(y));
        rect.setSize(sf::Vector2f(float(width), float(height)));
        rect.setFillColor(color);
        window.draw(Drawing::rect);
    }
    void drawRect(int x, int y, int width, int height) {
        rect.setPosition(float(x), float(y));
        rect.setSize(sf::Vector2f(float(width), float(height)));
        rect.setFillColor(sf::Color::Black);
        window.draw(Drawing::rect);
    }

    void drawFloatRect(float x, float y, float width, float height, sf::Color color) {
        rect.setPosition(float(x), float(y));
        rect.setSize(sf::Vector2f(width, height));
        rect.setFillColor(color);
        window.draw(Drawing::rect);
    }
    void drawFloatRect(float x, float y, float width, float height) {
        rect.setPosition(float(x), float(y));
        rect.setSize(sf::Vector2f(width, height));
        rect.setFillColor(sf::Color::Black);
        window.draw(Drawing::rect);
    }

    void shadow(int x,int y,int width,int height,int drawx,int drawy,bool centerOrigin) {
        block.setColor(sf::Color(255,255,255,shadowAlpha));
        stamp(x,y,width,height,drawx,drawy,centerOrigin);
        block.setColor(sf::Color(255,255,255,255));
    }
    void drawOutlineRect(int x, int y, int width, int height,int thicc) {
        rect.setPosition(float(x), float(y));
        rect.setFillColor(sf::Color(0, 0, 0, 0));
        rect.setOutlineColor(sf::Color(255, 255, 255));
        rect.setSize(sf::Vector2f(width, height));
        rect.setOutlineThickness(thicc);
        window.draw(Drawing::rect);
    }

    void print(int x, int y, std::string text, int fontSize, bool centerOrigin, sf::Color col) {
        Drawing::textObj.setString(text);
        Drawing::textObj.setFillColor(col);
        Drawing::textObj.setCharacterSize(fontSize);
        if (centerOrigin) {
            Drawing::textObj.setPosition(float(x - (text.length() * fontSize) / 2), float(y - fontSize / 2));
        }
        else {
            Drawing::textObj.setPosition(float(x), float(y));
        }
        Drawing::window.draw(Drawing::textObj);
    }
    void print(int x, int y, std::string text, int fontSize, bool centerOrigin) {
        Drawing::textObj.setString(text);
        Drawing::textObj.setFillColor(sf::Color::White);
        Drawing::textObj.setCharacterSize(fontSize);
        if (centerOrigin) {
            Drawing::textObj.setPosition(float(x - (text.length() * fontSize) / 2), float(y - fontSize / 2));
        }
        else {
            Drawing::textObj.setPosition(float(x), float(y));
        }
        Drawing::window.draw(Drawing::textObj);
    }
    void print(int x, int y, std::string text, int fontSize, std::string justif) {
        Drawing::textObj.setString(text);
        Drawing::textObj.setFillColor(sf::Color::White);
        Drawing::textObj.setCharacterSize(fontSize);
        Drawing::textObj.setPosition(float(x - (text.length() - 1) * fontSize), float(y));
        Drawing::window.draw(Drawing::textObj);
    }
    void print(int x, int y, std::string text, int fontSize, bool centerOrigin, int concatLen) {
        Drawing::textObj.setString(text);
        if (text.length() < concatLen) {
            std::string printThis = text;
            for (int i = 0; i < concatLen - text.length(); i++) {
                printThis = "0" + printThis;
            }
            Drawing::textObj.setString(printThis);
        }

        Drawing::textObj.setFillColor(sf::Color::White);
        Drawing::textObj.setCharacterSize(fontSize);
        if (centerOrigin) {
            Drawing::textObj.setPosition(float(x - (text.length() * fontSize) / 2), float(y - fontSize / 2));
        }
        else {
            Drawing::textObj.setPosition(float(x), float(y));
        }
        Drawing::window.draw(Drawing::textObj);
    }
}