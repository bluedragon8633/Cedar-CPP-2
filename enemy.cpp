#include<iostream>
#include"game.h"
#include"basicObjs.h"
#include"interactiveObj.h"
#include"enemy.h"



void Enemy::FireWormCreate() {
	name = "Fire Worm";
	className = "FireWorm";
}

void Enemy::OctorokCreate() {
	name = "Octorok";
	className = "Octorok";
}

void Enemy::RockCreate() {
	className = "Rock";
	//((abs(player.x - var(i, "x")) * abs(player.x - var(i, "x"))) + (abs(player.y - var(i, "y")) * abs(player.y - var(i, "y"))) < rockSensingDist * rockSensingDist)
}

void Enemy::RockProcess() {
	/*
	if ((abs(player.x - var(i, "x")) * abs(player.x - var(i, "x"))) + (abs(player.y - var(i, "y")) * abs(player.y - var(i, "y"))) < rockSensingDist * rockSensingDist) {
		if (var(i, "animationID") == 0) { //resting
			setNewAnimation(i, 1);
		}
		else if (var(i, "animationID") == 1) { //opening mouth
			if (var(i, "frameID") == var(i, "lenOfAnimation") - 1) {
				setNewAnimation(i, 2);
			}
		}
		else if (var(i, "animationID") == 2) { //mouth is open
			if (player.x < var(i, "x")) {
				setvar(i, "flip", false);
				move(i, -2, 0, true);
			}
			else {
				setvar(i, "flip", false);
				move(i, 2, 0, true);
			}
		}
	}
	else {
		if (var(i, "animationID") == 1) { //opening mouth
			if (var(i, "frameID") == var(i, "lenOfAnimation") - 1) {
				setNewAnimation(i, 3);
			}
		}
		else if (var(i, "animationID") == 2) { //starts closing mouth
			setNewAnimation(i, 3);

		}
		else if (var(i, "animationID") == 3) { //closing mouth
			if (var(i, "frameID") == var(i, "lenOfAnimation") - 1) {
				setNewAnimation(i, 0);
			}
		}
	}

	*/
}

void Enemy::GhostKaidiCreate() {
	name = "Ghost Kaidi";
	className = "GhostKaidi";
	moveTo(50, 50);
	width = 16;
	height = 16;
	tileSize = 16;
	canLeaveScreen = false;
	centerOrigin = true;
	walkFrameLength = 3;
	anims[0].animLength = 3;
	anims[0].frames[0] = { frameObj(208,0,tileSize,tileSize,walkFrameLength) };
	anims[0].frames[1] = { frameObj(224,0,tileSize,tileSize,walkFrameLength) };
	anims[0].frames[2] = { frameObj(240,0,tileSize,tileSize,walkFrameLength) };

}

void Enemy::GhostKaidiProcess() {

	animationTic();
}

