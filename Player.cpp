#include<iostream>
#include"interactiveObj.h"
#include"Player.h"
#include"BasicObjs.h"
#include"game.h"
#include"Drawer.h"
#include"GlobalVars.h"
using namespace std;
using namespace Drawer;

PlayerObj::PlayerObj() {
	makeAnimation("walk_right",0, 96, 0, 16, 16, 4, walkFrameLength);
	makeAnimation("walk_up",1, 96, 16, 16, 16, 4, walkFrameLength);
	makeAnimation("walk_down",2, 96, 32, 16, 16, 4, walkFrameLength);
	makeAnimation("wait_right",3, 80, 0, 16, 16, 1, 1);
	makeAnimation("wait_up",4, 80, 16, 16, 16, 1, 1);
	makeAnimation("wait_down",5, 80, 32, 16, 16, 1, 1);
	x = Global::playerStartX;
	y = Global::playerStartY;
	z = 0;
	canMoveDiagonally = true;
	width = 16;
	height = 16;
	canLeaveScreen = true;
	centerOrigin = true;
	className = "player";
	hasShadow = true;
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
	move(xv, 0);


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
	move(0, yv);
}


void PlayerObj::animationProcess() {
	if (movedThisFrame) { //if changed position at all
		if (oldVel.x != xv || oldVel.y != yv) {
			//console.log("changed direction");
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
		//console.log("player is stationary");
		if (animId < 3) { //is at end of walking animation
			animationTic();
			if (isOnLastFrame()) {
				//console.log("player is on last frame");
				setAnimation(animId + 3);
			}
		}
		else {
			
		}
	}
	
}

int PlayerObj::getLevelIncrement() {
	
	if ((x < Global::playFieldLeftX + 2) && xv < 0) { //on left edge and moving left
		if (area.level().x == 0) { //if on far left edge of area
			x -= xv;
			return 0;
		}
		else { //if can move further left
			x = Global::scrnWidth;
			return -1;
		}

	}
	if (x > Global::playFieldRightX + 2 && xv > 0) { //on right edge and moving right

		if (area.level().x == area.width - 1) { //if on far right edge of area
			x -= xv;
		}
		else { //if can move further right
			x = 0;
			return 1;
		}

	}
	if (x < Global::playFieldLeftX || x > Global::playFieldRightX || y < Global::playFieldTopY || y > Global::playFieldBotY) {

	}
	if (x < Global::playFieldLeftX || x > Global::playFieldRightX || y < Global::playFieldTopY || y > Global::playFieldBotY) {

	}
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


