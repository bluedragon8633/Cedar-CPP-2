#pragma once
#include"Drawer.h"
#include"game.h"


class SplashScreen {
public:
	vector<Billboard> elements;
	int brightness;

	SplashScreen();
	void draw();
};