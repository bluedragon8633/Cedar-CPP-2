#pragma once
#include<iostream>
#include<vector>

using namespace std;

class Menu {
public:
	int selectX, selectY;

};

class TextMenu : public Menu {
public:
	vector<string> options;
	int tlx, tly;

	TextMenu(vector<string> newOptions, int startPosX, int startPosY, int xin, int yin);
	TextMenu();
};