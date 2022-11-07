#include"primitiveUI.h"
#include<iostream>
#include<vector>
#include"game.h"
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
	tlx = 0;
	tly = 0;
	upReady = false; downReady = false;
}

void TextMenu::set(vector<string> newOptions, int startPosX, int startPosY, int xin, int yin) {
	selectX = startPosX;
	selectY = startPosY;
	options = newOptions;
	tlx = xin;
	tly = yin;
	upReady = false; downReady = false;
}
void TextMenu::process(KeyHandler k) {
	if (k.up) {
		if (upReady) {
			upReady = false;
			if (selectY > 0) {
				selectY--;
			}
		}
	}
	else {
		upReady = true;
	}
	if (k.down) {
		if (downReady) {
			downReady = false;
			if (selectY < options.size()) {
				selectY++;
			}
		}
	}
	else {
		downReady = true;
	}

}