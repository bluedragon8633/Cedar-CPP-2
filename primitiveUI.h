#pragma once
#include<iostream>
#include<vector>
#include"game.h"
using namespace std;

class Menu {
public:
	int selectX, selectY;

};

class TextMenu : public Menu {
public:
	vector<string> options;
	int tlx, tly;
	const int fontSize = 4;
	TextMenu(vector<string> newOptions, int startPosX, int startPosY, int xin, int yin);
	TextMenu();
	void set(vector<string> newOptions, int startPosX, int startPosY, int xin, int yin);
	void process(KeyHandler k);
};