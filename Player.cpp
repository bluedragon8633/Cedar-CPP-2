#include<iostream>
#include"interactiveObj.h"
#include"Player.h"
#include"BasicObjs.h"
#include"game.h"
//#include"tile.h"
using namespace std;

PlayerObj::PlayerObj(GameConsts g) {
	makeAnimation("walk_right",0, 96, 0, 16, 16, 4, walkFrameLength);
	makeAnimation("walk_up",1, 96, 16, 16, 16, 4, walkFrameLength);
	makeAnimation("walk_down",2, 96, 32, 16, 16, 4, walkFrameLength);
	makeAnimation("wait_right",3, 80, 0, 16, 16, 1, 1);
	makeAnimation("wait_up",4, 80, 16, 16, 16, 1, 1);
	makeAnimation("wait_down",5, 80, 32, 16, 16, 1, 1);
	x = g.playerStartX;
	y = g.playerStartY;
	z = 0;
	canMoveDiagonally = true;
	width = 16;
	height = 16;
	canLeaveScreen = false;
	centerOrigin = true;
	className = "player";
}

void PlayerObj::processX(KeyHandler key, GameConsts g) {
	int finalxv;
	if (key.right && !((key.up || key.down) && !canMoveDiagonally)) {
		finalxv = 2;
		flipX = false;
	}
	else if (key.left && !((key.up || key.down) && !canMoveDiagonally)) {
		finalxv = -2;
		flipX = true;
	}
	else {
		finalxv = 0;
	}
	move(finalxv, 0, g);


}

void PlayerObj::processY(KeyHandler key, GameConsts g) {
	int finalyv;

	if (key.up && !((key.right || key.left) && !canMoveDiagonally)) {
		finalyv = -2;
		if (isOutOfBounds(g)) {

		}

		flipX = false;
		if (animId != 1) {
			setAnimation(1);
		}
	}
	else if (key.down && !((key.right || key.left) && !canMoveDiagonally)) {
		finalyv = 2;
		flipX = false;
		if (animId != 2) {
			setAnimation(2);
		}
	}
	else {
		finalyv = 0;
	}
	move(0, finalyv, g);

	if (!(key.up || key.down || key.right || key.left) && frameId == anims[animId].animLength) {
		setAnimation(animId);
	}
	animationTic();
}

PlayerAtk::PlayerAtk() {
	animId = 0;
	timer = 0;
	makeAnimation("swipe",0,160,0,8,32,5,3);
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


bool isOnEdge() {
	return false;
}

int newLevel() {
	return 0;
}