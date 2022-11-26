#include<iostream>
#include"interactiveObj.h"
#include"Player.h"
#include"BasicObjs.h"
#include"game.h"
#include"Drawer.h"
using namespace std;
using namespace Drawer;

PlayerObj::PlayerObj() {
	makeAnimation("walk_right",0, 96, 0, 16, 16, 4, walkFrameLength);
	makeAnimation("walk_up",1, 96, 16, 16, 16, 4, walkFrameLength);
	makeAnimation("walk_down",2, 96, 32, 16, 16, 4, walkFrameLength);
	makeAnimation("wait_right",3, 80, 0, 16, 16, 1, 1);
	makeAnimation("wait_up",4, 80, 16, 16, 16, 1, 1);
	makeAnimation("wait_down",5, 80, 32, 16, 16, 1, 1);
	x = game.vars.playerStartX;
	y = game.vars.playerStartY;
	z = 0;
	canMoveDiagonally = true;
	width = 16;
	height = 16;
	canLeaveScreen = false;
	centerOrigin = true;
	className = "player";
}

void PlayerObj::processX(KeyHandler key) {
	if (key.right && !((key.up || key.down) && !canMoveDiagonally)) {
		xv = 2;
		flipX = false;
		movedThisFrame = true;
	}
	else if (key.left && !((key.up || key.down) && !canMoveDiagonally)) {
		xv = -2;
		flipX = true;
		movedThisFrame = true;
	}
	else {
		xv = 0;
	}
	move(xv, 0, game);


}

void PlayerObj::processY(KeyHandler key) {

	if (key.up && !((key.right || key.left) && !canMoveDiagonally)) {
		yv = -2;
		//flipX = false;
		movedThisFrame = true;
	}
	else if (key.down && !((key.right || key.left) && !canMoveDiagonally)) {
		yv = 2;
		//flipX = false;
		movedThisFrame = true;
	}
	else {
		yv = 0;
	}
	move(0, yv, game);
}


void PlayerObj::animationProcess() {
	if (movedThisFrame) { //if changed position at all
		if (oldVel.x != xv || oldVel.y != yv) {
			console::log("changed direction");
			if (xv != 0) { //moving right or left
				setAnimation(0);
			}
			else {
				if (yv < 0) {
					setAnimation(1);
				}
				else if (yv > 0) {
					setAnimation(2);
				}
			}
		}

		
		animationTic();
	}
	else { //if hasn't changed direction
		//console::log("player is stationary");
		if (animId < 3) { //is at end of walking animation
			animationTic();
			if (isOnLastFrame()) {
				//console::log("player is on last frame");
				setAnimation(animId + 3);
			}
		}
		else {
			
		}
	}
	
}

bool PlayerObj::isOnEdge() {
	return false;
}

int PlayerObj::newLevel() {
	return 0;
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


