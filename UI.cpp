#include"UI.h"
#include"Drawer.h"
#include"BasicObjs.h"
#include<iostream>
using namespace Drawer;


SplashScreen::SplashScreen() {
	brightness = 0;
	elements.push_back(Billboard(game.scrnWidth / 2,game.scrnHeight / 2,240,192,16,16,true));
	console::log("Elements: " + to_string(elements.size()));
}

void SplashScreen::draw() {
	for (int i = 0; i < elements.size(); i++) {
		stamp(elements.at(i));
	}
}