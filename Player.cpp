#include<iostream>
#include"interactiveObj.h"
#include"Player.h"
#include"BasicObjs.h"
#include"game.h"
//#include"tile.h"
using namespace std;

PlayerObj::PlayerObj(GameConsts g) {
	makeAnimation(0, 96, 0, 16, 16, 2, walkFrameLength);
	makeAnimation(1, 96, 16, 16, 16, 2, walkFrameLength);
	makeAnimation(2, 96, 32, 16, 16, 2, walkFrameLength);

	x = g.playerStartX;
	y = g.playerStartY;
	z = 0;
	canMoveDiagonally = true;
	width = 16;
	height = 16;
	canLeaveScreen = false;
	centerOrigin = true;
}

void PlayerObj::process(KeyHandler key, GameConsts g) {
	if (key.up && !((key.right || key.left) && !canMoveDiagonally)) {
		move(0,-2,g);
		if (isOutOfBounds(g)) {

		}
		
		flipX = false;
		if (animId != 1) {
			setAnimation(1);
		}
	}
	else if (key.down && !((key.right || key.left) && !canMoveDiagonally)) {
		move(0, 2,g);
		flipX = false;
		if (animId != 2) {
			setAnimation(2);
		}
	}
	if (key.right && !((key.up || key.down) && !canMoveDiagonally)) {
		move(2, 0,g);
		flipX = false;
		if (animId != 0) {
			setAnimation(0);
		}
	}
	else if (key.left && !((key.up || key.down) && !canMoveDiagonally)) {
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
