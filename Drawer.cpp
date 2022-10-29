#include<iostream>
#include"SFML/Graphics.hpp"
#include"Drawer.h"
#include"general.h"
#include"game.h"
#include"BasicObjs.h"


namespace Drawer {
     sf::Texture atlas;
     sf::Font font;
     sf::RectangleShape rect;
     sf::Text textObj;
     sf::Sprite block;
     sf::Sprite tile;
     sf::RenderWindow window;
     sf::RectangleShape rectangle;
     sf::Event e;
	 sf::CircleShape circle;

	 GameConsts game("Mimi's Grand Journey!");

    void setup() {
		rect = sf::RectangleShape(sf::Vector2f(1, 1));
		//window.create(sf::VideoMode(g.scrnWidth,g.scrnHeight),g.TITLE);
		window.create(sf::VideoMode(game.scrnWidth, game.scrnHeight), game.TITLE, sf::Style::Close);
		printf("Created window successfully!\n");
		loadTextures();
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
		block.setScale(float(game.GAME_SCALE), float(game.GAME_SCALE));
		block.setPosition(float(drawx), float(drawy));
		window.draw(block);
	}

	void stamp(animObj a) {
		block.setTexture(atlas);
		console::log("trying to draw rect: " + to_string(a.anims[a.animId].frames[a.frameId].sourceX) + "," + to_string(a.anims[a.animId].frames[a.frameId].sourceY) + "," + to_string(a.anims[a.animId].frames[a.frameId].sourceWidth) + "," + to_string(a.anims[a.animId].frames[a.frameId].sourceHeight)); //a.anims[a.animId].frames[a.frameId].sourceX
		block.setTextureRect(sf::IntRect(a.anims[a.animId].frames[a.frameId].sourceX, a.anims[a.animId].frames[a.frameId].sourceY, a.anims[a.animId].frames[a.frameId].sourceWidth, a.anims[a.animId].frames[a.frameId].sourceHeight));
		if (a.centerOrigin) {
			block.setOrigin(float(a.width / 2), float(a.height / 2));
			console::log("origin: " + to_string(a.width / 2) + to_string(a.height / 2));
		}
		else {
			block.setOrigin(0, 0);
		}
		
		int xMod = 1;
		int yMod = 1;
		if (a.flipX) {
			xMod = -1;
		}
		if (a.flipY) {
			yMod = -1;
		}
		block.setScale(float(game.GAME_SCALE * xMod), float(game.GAME_SCALE * yMod));
		//console::log("scale: " + to_string(block.getScale().x) + "," + to_string(block.getScale().y));

		//console::log("position: " + to_string(a.x) + "," + to_string(a.y));
		block.setPosition(float(a.x * game.GAME_SCALE), float(a.y * game.GAME_SCALE));
		window.draw(block);
		/*
		circle.setPosition(float(a.x * game.GAME_SCALE), float(a.y * game.GAME_SCALE));
		circle.setFillColor(sf::Color::Magenta); circle.setRadius(5);
		window.draw(circle);
		*/
		//console::log("drawn object");
	}
}


