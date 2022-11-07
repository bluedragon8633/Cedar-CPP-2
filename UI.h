#pragma once
#include"Drawer.h"
#include"game.h"
#include"primitiveUI.h"


class Elements {
public:
	vector<Billboard> elements;

	void drawElements();
};

class SplashScreen : public Elements {
public:
	
	int brightness;

	SplashScreen();
	void draw();
};

class TitleScreen : public Elements {
public:
	TextMenu t;

	TitleScreen();
	void draw();
};

