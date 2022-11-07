#include"primitiveUI.h"
#include<iostream>
#include<vector>

using namespace std;

TextMenu::TextMenu(vector<string> newOptions, int startPosX, int startPosY,int xin,int yin) {
	selectX = startPosX;
	selectY = startPosY;
	options = newOptions;
	tlx = xin;
	tly = yin;
	
}

TextMenu::TextMenu() {
	selectX = 0;
	selectY = 0;
}