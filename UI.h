#pragma once
#include"Drawer.h"
#include"game.h"
#include"primitiveUI.h"
#include"KeyHandler.h"

class Elements {
public:
	vector<Billboard> elements;
	static const int textSize = 8;
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
	void process(KeyHandler k);
};

class QuitConfirm : public Elements {
public:
	TextMenu t;

	QuitConfirm();
	void draw();
	void process(KeyHandler k);
};