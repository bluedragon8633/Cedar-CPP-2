#include<iostream>
#include"SFML/Graphics.hpp"
#include"Drawer.h"
#include"general.h"
#include"game.h"
#include"BasicObjs.h"
#include"primitiveUI.h"
#include"GlobalVars.h"
using namespace Global;
//#include"enemy.h"

namespace Drawer {
	sf::Texture atlas;
	sf::Font font;
	sf::RectangleShape rect;
	sf::Text textObj;
	sf::Sprite block;
	//sf::Sprite tile;
	sf::RenderWindow window;
	sf::RectangleShape rectangle;
	sf::Event e;
	sf::CircleShape circle;
	Area area(0,1);
	//GameConsts game("Mimi's Grand Journey!");
	PlayerObj player;
	KeyHandler key;
	//EnemyTable enemies;


	void setup() {
		Global::loadData();
		rect = sf::RectangleShape(sf::Vector2f(1, 1));
		window.create(sf::VideoMode(Global::scrnWidth * Global::GAME_SCALE, Global::scrnHeight * Global::GAME_SCALE), Global::TITLE, sf::Style::Close);
		console.log("Created window successfully! Size: (" + to_string(Global::scrnWidth * Global::GAME_SCALE) + "," + to_string(Global::scrnHeight * Global::GAME_SCALE) + ")");
		loadTextures();
		window.setFramerateLimit(Global::FRAME_LIMIT);
		player = PlayerObj();
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
		if (!font.loadFromFile("./assets/zelda.ttf"))
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
		block.setScale(float(Global::GAME_SCALE), float(Global::GAME_SCALE));
		block.setPosition(float(drawx * Global::GAME_SCALE), float(drawy * Global::GAME_SCALE));
		window.draw(block);
	}

	void stamp(animObj a) {
		
		block.setTexture(atlas);
		if (a.centerOrigin) {
			block.setOrigin(float(a.width / 2), float(a.height / 2));
			//console.log("origin: " + to_string(a.width / 2) + to_string(a.height / 2), true);
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
		block.setScale(float(Global::GAME_SCALE * xMod), float(Global::GAME_SCALE * yMod));
		block.setPosition(float(a.x * Global::GAME_SCALE), float(a.y * Global::GAME_SCALE));
		if (a.hasShadow) {
			block.setTextureRect(sf::IntRect(64,0,16,32));
			window.draw(block);
		}
		//console.log("trying to draw rect: " + to_string(a.anims[a.animId].frames.at(a.frameId).sourceX) + "," + to_string(a.anims[a.animId].frames.at(a.frameId).sourceY) + "," + to_string(a.anims[a.animId].frames.at(a.frameId).sourceWidth) + "," + to_string(a.anims[a.animId].frames.at(a.frameId).sourceHeight), true); //a.anims[a.animId].frames.at(a.frameId).sourceX
		block.setTextureRect(sf::IntRect(a.anims[a.animId].frames.at(a.frameId).sourceX, a.anims[a.animId].frames.at(a.frameId).sourceY, a.anims[a.animId].frames.at(a.frameId).sourceWidth, a.anims[a.animId].frames.at(a.frameId).sourceHeight));

		window.draw(block);
		/*
		circle.setPosition(float(a.x * Global::GAME_SCALE), float(a.y * Global::GAME_SCALE));
		circle.setFillColor(sf::Color::Magenta); circle.setRadius(5);
		window.draw(circle);
		*/
		//console.log("drawn object");
	}
	void stamp(frameObj a, int x, int y) {
		block.setTexture(atlas);
		block.setTextureRect(sf::IntRect(a.sourceX, a.sourceY, a.sourceWidth, a.sourceHeight));
		block.setOrigin(0, 0);

		int xMod = 1;
		int yMod = 1;

		block.setScale(float(Global::GAME_SCALE * xMod), float(Global::GAME_SCALE * yMod));

		block.setPosition(float(x * Global::GAME_SCALE), float(y * Global::GAME_SCALE));
		window.draw(block);
	}
	void stamp(frameObj a, int x, int y,int zoom) {
		block.setTexture(atlas);
		block.setTextureRect(sf::IntRect(a.sourceX, a.sourceY, a.sourceWidth, a.sourceHeight));
		block.setOrigin(0, 0);

		int xMod = 1;
		int yMod = 1;

		block.setScale(float(Global::GAME_SCALE * xMod * zoom), float(Global::GAME_SCALE * yMod * zoom));

		block.setPosition(float(x * Global::GAME_SCALE), float(y * Global::GAME_SCALE));
		window.draw(block);
	}

	void stamp(Billboard a) {
		block.setTexture(atlas);
		block.setTextureRect(sf::IntRect(a.sourceX, a.sourceY, a.sourceWidth, a.sourceHeight));
		if (a.centerOrigin) {
			block.setOrigin(float(a.sourceWidth / 2), float(a.sourceHeight / 2));
			console.log("origin: " + to_string(a.sourceWidth / 2) + to_string(a.sourceWidth / 2), true);
		}
		else {
			block.setOrigin(0, 0);
		}

		int xMod = 1;
		int yMod = 1;
		block.setScale(float(Global::GAME_SCALE * xMod), float(Global::GAME_SCALE * yMod));
		block.setPosition(float(a.x * Global::GAME_SCALE), float(a.y * Global::GAME_SCALE));
		window.draw(block);

	}

	void stamp(Billboard a,int brightness) {
		block.setTexture(atlas);
		block.setTextureRect(sf::IntRect(a.sourceX, a.sourceY, a.sourceWidth, a.sourceHeight));
		if (a.centerOrigin) {
			block.setOrigin(float(a.sourceWidth / 2), float(a.sourceHeight / 2));
			console.log("origin: " + to_string(a.sourceWidth / 2) + to_string(a.sourceWidth / 2), true);
		}
		else {
			block.setOrigin(0, 0);
		}

		int xMod = 1;
		int yMod = 1;
		block.setScale(float(Global::GAME_SCALE * xMod), float(Global::GAME_SCALE * yMod));
		block.setPosition(float(a.x * Global::GAME_SCALE), float(a.y * Global::GAME_SCALE));
		block.setColor(sf::Color(0,0,0));
		window.draw(block);

	}

	void freezeScrnFor(int frames) {
		
		for (int i = 0; i < frames;i++) {
			window.display();
		}
		
	}

	void setTextOrigin(int x,int y,bool centerOrigin,std::string text,int fontSize) {
		
		if (centerOrigin) {
			//cout << y << " - " << (textObj.getCharacterSize()) << " / " << 2 << " = " << float(y - textObj.getCharacterSize() / 2) << endl;
			//cout << "text.length() * fontSize / 2 = " << text.length() * fontSize / 2 << endl;
			textObj.setPosition(float(x - text.length() * fontSize / 2), float(y - fontSize / 2));
		}
		else {
			textObj.setPosition(float(x), float(y));
		}
		//console.log("Old coordinates: " + to_string(textObj.getPosition().x) + "," + to_string(textObj.getPosition().y));
		textObj.setPosition(textObj.getPosition().x * Global::GAME_SCALE,textObj.getPosition().y * Global::GAME_SCALE);
		//console.log("Final coordinates: " + to_string(textObj.getPosition().x) + "," + to_string(textObj.getPosition().y));
	}

	void print(int x, int y, std::string text, int fontSize, bool centerOrigin, sf::Color col) {
		textObj.setString(text);
		textObj.setFillColor(col);
		setTextOrigin(x, y, centerOrigin,text,fontSize);
		textObj.setCharacterSize(fontSize * Global::GAME_SCALE);
		window.draw(textObj);
	}
	void print(int x, int y, std::string text, int fontSize, bool centerOrigin) {
		setTextOrigin(x, y, centerOrigin, text, fontSize);
		textObj.setString(text);
		textObj.setFillColor(sf::Color::White);
		textObj.setCharacterSize(fontSize * Global::GAME_SCALE);
		
		window.draw(textObj);
	}

	void print(int x, int y, std::string text, int fontSize, bool centerOrigin, int concatLen) {
		textObj.setString(text);
		if (text.length() < concatLen) {
			std::string printThis = text;
			for (int i = 0; i < concatLen - text.length(); i++) {
				printThis = "0" + printThis;
			}
			textObj.setString(printThis);
		}
		setTextOrigin(x, y, centerOrigin, text, fontSize);
		textObj.setFillColor(sf::Color::White);
		textObj.setCharacterSize(fontSize * Global::GAME_SCALE);
		
		window.draw(textObj);
	}

	void print(TextMenu t) {
		
		string raw = "";
		for (int i = 0; i < t.options.size();i++) {
			raw += t.options.at(i);
			raw += "\n";
		}
		textObj.setString(raw);
		textObj.setFillColor(sf::Color::White);
		textObj.setCharacterSize(t.fontSize * Global::GAME_SCALE);
		textObj.setPosition(float(t.tlx * Global::GAME_SCALE), float(t.tly * Global::GAME_SCALE));
		//cout << "tlx,tly = " << float(t.tlx) << "," << float(t.tly) << endl;
		window.draw(textObj);
		textObj.setString("=");
		textObj.setPosition(textObj.getPosition().x - textObj.getCharacterSize(), textObj.getPosition().y + t.selectY * textObj.getCharacterSize());
		//console.log("Y pos: " + to_string(t.selectY * textObj.getCharacterSize()));
		window.draw(textObj);
	}




	void drawRect(int x, int y, int width, int height, sf::Color col) {
		rect.setPosition(float(x * Global::GAME_SCALE), float(y * Global::GAME_SCALE));
		rect.setFillColor(col);
		rect.setScale(float(Global::GAME_SCALE), float(Global::GAME_SCALE));
		rect.setSize(sf::Vector2f(float(width), float(height)));
		window.draw(rect);
	}
	void drawRect(sf::IntRect r, sf::Color col) {
		rect.setPosition(float(r.top * Global::GAME_SCALE), float(r.left * Global::GAME_SCALE));
		rect.setFillColor(col);
		rect.setScale(float(Global::GAME_SCALE), float(Global::GAME_SCALE));
		rect.setSize(sf::Vector2f(float(r.width), float(r.height)));
		window.draw(rect);
	}
}


