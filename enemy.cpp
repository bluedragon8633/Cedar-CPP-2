#include<iostream>
#include"game.h"
//#include"basicObjs.h"
#include"interactiveObj.h"
#include"enemy.h"
#include"GlobalVars.h"
//#include"Drawer.h"
//#include"tile.h"


//using namespace Drawer;
using namespace std;
using namespace Global;

Enemy::Enemy(baseObj b) {
	setBaseProperties(b);
	create();
}

void Enemy::create() {
	if (className == "FireWorm") {
		FireWormCreate();
	}
	else if (className == "GhostKaidi") {
		GhostKaidiCreate();
	}
	else if (className == "Octorok") {
		OctorokCreate();
	}
	else if (className == "Rock") {
		RockCreate();
	}
	else if (className == "Horizontal") {
		HorizontalCreate();
	}
	else if (className == "Vertical") {
		VerticalCreate();
	}
}

void Enemy::process() {
	if (className == "FireWorm") {
		FireWormProcess();
	}
	else if (className == "GhostKaidi") {
		GhostKaidiProcess();
	}
	else if (className == "Octorok") {
		OctorokProcess();
	}
	else if (className == "Rock") {
		RockProcess();
	}
	else if (className == "Horizontal") {
		HorizontalProcess();
	}
	else if (className == "Vertical") {
		VerticalProcess();
	}
}

void Enemy::FireWormCreate() {
	name = "Fire Worm";
	className = "FireWorm";
}

void Enemy::FireWormProcess() {

}

void Enemy::HorizontalCreate() {
	name = "Horizontal";
	className = "Horizontal";
	setVel(2, 0);
	console.log("set basic properties");
	makeAnimation("move",0,192,48,16,16,4,5);
	setAnimation(0);
	console.log("horizontal created");
}

void Enemy::HorizontalProcess() {
	if (touchedWallThisFrame && processedCollision) {
		xv = xv * -1;
		console.log("touched wall; xv = " + to_string(xv));
	}
	else {
		
	}
	move(xv, 0);
	animationTic();
}

void Enemy::VerticalCreate() {
	name = "Vertical";
	className = "Vertical";
}

void Enemy::VerticalProcess() {

}

void Enemy::OctorokCreate() {
	name = "Octorok";
	className = "Octorok";
}

void Enemy::OctorokProcess() {

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
	setPos(50, 50,0);
	setSize(16, 16);
	tileSize = 16;
	canLeaveScreen = false;
	centerOrigin = true;
	walkFrameLength = 3;
	anims[0].animLength = 3;
	anims[0].frames.at(0) = {frameObj(208,0,tileSize,tileSize,walkFrameLength)};
	anims[0].frames.at(1) = {frameObj(224,0,tileSize,tileSize,walkFrameLength)};
	anims[0].frames.at(2) = {frameObj(240,0,tileSize,tileSize,walkFrameLength)};

}

void Enemy::GhostKaidiProcess() {

	animationTic();
}



void EnemyTable::clear() {
	enemies.clear();
}
int EnemyTable::enemiesLeft() {
	return int(enemies.size());
}
void EnemyTable::addEnemies(vector<baseObj> newEnemies) {
	for (int i = 0; i < newEnemies.size(); i++) {
		enemies.push_back(Enemy(newEnemies.at(i)));
		console.log("enemies.at(i) position: " + to_string(enemies.at(i).x) + "," + to_string(enemies.at(i).y) + "; className = " + enemies.at(i).className);
	}
	
}
void EnemyTable::processAll() {
	for (int i = 0; i < enemiesLeft(); i++) {
		enemies.at(i).process();
	}
}