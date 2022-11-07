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
	t = TextMenu(v,0,0,game.scrnWidth / 2 - 20,60);

	elements.push_back(Billboard(game.scrnWidth / 2,24,176,208,80,48,true));

}

void TitleScreen::draw() {
	window.clear();
	drawElements();
	print(t);
}