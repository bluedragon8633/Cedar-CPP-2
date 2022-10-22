#include<iostream>
#include"BasicObjs.h"
#include"game.h"

class Drawer {
public:
    const int shadowAlpha = 200;
    sf::Texture atlas;
    sf::Font font;
    sf::RectangleShape rect;
    sf::Text textObj;
    sf::Sprite block;
    sf::Sprite tile;
    sf::Event e;
    sf::RenderWindow window;
    GameConsts g;

    Drawer();
    Drawer(GameConsts newGameConsts);

    void resizeWindow(std::string title, int width, int height);

    void loadTextures();
    void stamp(int x, int y, int width, int height, int drawx, int drawy, bool centerOrigin);
    void stamp(animObj a);

};