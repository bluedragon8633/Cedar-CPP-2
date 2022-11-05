#include<iostream>
#include"interactiveObj.h"
#include"Player.h"
#include"BasicObjs.h"
#include"game.h"
using namespace std;

PlayerObj::PlayerObj(GameConsts g) {
	makeAnimation(0, 80, 0, 16, 16, 4, walkFrameLength);
	makeAnimation(1, 80, 16, 16, 16, 4, walkFrameLength);
	makeAnimation(2, 80, 32, 16, 16, 4, walkFrameLength);

	x = g.playerStartX;
	y = g.playerStartY;
	width = 16;
	height = 16;
	canLeaveScreen = false;
	centerOrigin = true;
}

void PlayerObj::process(KeyHandler key, GameConsts g) {
	if (key.up) {
		move(0,-2,g);
		if (isOutOfBounds(g)) {

		}
		
		flipX = false;
		if (animId != 1) {
			setAnimation(1);
		}
	}
	else if (key.down) {
		move(0, 2,g);
		flipX = false;
		if (animId != 2) {
			setAnimation(2);
		}
	}
	if (key.right) {
		move(2, 0,g);
		flipX = false;
		if (animId != 0) {
			setAnimation(0);
		}
	}
	else if (key.left) {
		move(-2, 0,g);
		flipX = true;
		if (animId != 0 || !flipX) {
			setAnimation(0);
		}
	}



	animationTic();
}

PlayerAtk::PlayerAtk() {
	animId = 0;
	timer = 0;
}

void PlayerAtk::process() {
	if (timer != -1) {
		if (timer == 20) {
			timer = -1;
			return;
		}
		else {
			if (timer % 4 == 0) {
				frameId++;
			}
			timer++;

		}
	}
}
