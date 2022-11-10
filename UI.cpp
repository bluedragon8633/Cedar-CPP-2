#include"UI.h"
#include"Drawer.h"
#include"BasicObjs.h"
#include"primitiveUI.h"
#include<iostream>
using namespace Drawer;

void Elements::drawElements() {
	for (int i = 0; i < elements.size(); i++) {
		stamp(elements.at(i));
	}
}




SplashScreen::SplashScreen() {
	brightness = 0;
	elements.push_back(Billboard(game.scrnWidth / 2,game.scrnHeight / 2,240,192,16,16,true));
	console::log("Elements: " + to_string(elements.size()));
}

void SplashScreen::draw() {
	window.clear();
	drawElements();
	print(game.scrnWidth / 2, game.scrnHeight / 2 + 16, "BLUEDRAGON8633", 4, true);
	//print(100, 32, "WINTERDRAGONFLY8633", 4, false);
}



TitleScreen::TitleScreen() {
	vector<string> v;
	v.insert(v.end(), { "NEW GAME","EXTRAS","OPTIONS","EXIT"});
	t.set(v,0,0,game.scrnWidth / 2 - 20,60);

	elements.push_back(Billboard(game.scrnWidth / 2,24,176,208,80,48,true));

}



void TitleScreen::draw() {
	window.clear();
	drawElements();
	print(t);
}

void TitleScreen::process(KeyHandler k) {
	t.process(k);
	if (k.a) {
		switch (t.selectY) {
		case 0: //new game
			game.vars.STATUS = "game";
		break;
		case 1: 

		break;
		case 2:

		break;
		case 3: //quit
			game.vars.STATUS = "quitConfirm";
		break;
		}
	}
}

QuitConfirm::QuitConfirm() {
	vector<string> v;
	v.insert(v.end(), { "YES","NO"});
	t.set(v, 0, 0, game.scrnWidth / 2 - 20, 60);

	elements.push_back(Billboard(game.scrnWidth / 2, 24, 176, 208, 80, 48, true));

}



void QuitConfirm::draw() {
	window.clear();
	print(game.scrnWidth / 2, game.scrnHeight / 2 + 16, "ARE YOU SURE YOU WANT TO QUIT?", 4, true);
	drawElements();
	print(t);
}

void QuitConfirm::process(KeyHandler k) {
	t.process(k);
	console::log("A pressed: " + to_string(k.a) + "; aReady: " + to_string(k.aReady));
	if (k.canUseA()) {
		
		switch (t.selectY) {
		case 0: //no
			game.vars.STATUS = "title";
			break;
		case 1: //yes
			window.close();
			break;
		}
	}
}