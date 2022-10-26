#include<iostream>
#include"SFML/Graphics.hpp"
#include"Drawer.h"
#include"general.h"
#include"BasicObjs.h"

namespace Drawing {
     sf::Texture atlas;
     sf::Font font;
     sf::RectangleShape rect;
     sf::Text textObj;
     sf::Sprite block;
     sf::Sprite tile;
     sf::Sprite blockBullet;
     sf::RenderWindow window;
     sf::RectangleShape rectangle;
     sf::Event e;
    
    void setup() {
		rect = sf::RectangleShape(sf::Vector2f(1, 1));
		//window.create(sf::VideoMode(g.scrnWidth,g.scrnHeight),g.TITLE);
		window.create(sf::VideoMode(g.scrnWidth, g.scrnHeight), g.TITLE, sf::Style::Close);
    }
	
	void resizeWindow(std::string title, int width, int height) {
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
			textObj.setFont(font);
		}

		block.setTexture(atlas);


	}

	void stamp(int x, int y, int width, int height, int drawx, int drawy, bool centerOrigin) {
		block.setTexture(atlas);
		block.setTextureRect(sf::IntRect(x, y, width, height));
		if (centerOrigin) {
			block.setOrigin(float(width / 2), float(height / 2));
		}
		else {
			block.setOrigin(0, 0);
		}
		block.setScale(float(g.GAME_SCALE), float(g.GAME_SCALE));
		block.setPosition(float(drawx), float(drawy));
		window.draw(block);
	}

	void stamp(animObj a) {
		block.setTexture(atlas);
		block.setTextureRect(sf::IntRect(a.anims[a.animId].frames[a.frameId].sourceX, a.anims[a.animId].frames[a.frameId].sourceY, a.anims[a.animId].frames[a.frameId].sourceWidth, a.anims[a.animId].frames[a.frameId].sourceHeight));
		if (a.centerOrigin) {
			block.setOrigin(float(a.width / 2), float(a.height / 2));
		}
		else {
			block.setOrigin(0, 0);
		}
		block.setScale(float(g.GAME_SCALE), float(g.GAME_SCALE));
		block.setPosition(float(a.x), float(a.x));
		window.draw(block);
	}
}


