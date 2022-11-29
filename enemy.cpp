#include<iostream>
#include"game.h"
#include"basicObjs.h"
#include"interactiveObj.h"
#include"enemy.h"

void EnemyTable::clear() {
	enemies.clear();
}
int EnemyTable::enemiesLeft() {
	return enemies.size();
}
void EnemyTable::addEnemies(vector<baseObj> newEnemies) {
	for (int i = 0; i < newEnemies.size();i++) {
		enemies.push_back(Enemy(newEnemies.at(i)));
	}
}
void EnemyTable::processAll() {
	for (int i = 0; i < enemiesLeft(); i++) {
		enemies.at(i).process();
	}
}

Enemy::Enemy(baseObj b) {
	setBaseProperties(b);
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
}

void Enemy::FireWormCreate() {
	name = "Fire Worm";
	className = "FireWorm";
}

void Enemy::FireWormProcess() {

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
	width = 16;
	height = 16;
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

