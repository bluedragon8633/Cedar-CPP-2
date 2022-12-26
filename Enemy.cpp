#include"Enemy.h"
#include"EnemyTable.h"
#include<iostream>
#include"Level.h"
#include"Coords.h"
Enemy::Enemy() {
	 //0 = x, 1 = y, 2 = xv, yv, 4 =  hp, maxhp, 6 = frameSourceX,frameSourceY,8 = resX,resY,10 = width,height,type,frameID,14 = frameLen,frameCounter
	/*
	0,1 = x,y coordinates
	2,3 = xv,yv
	4,5 = hp,maxHP
	6,7 = frameSourceX,frameSourceY
	8,9 = resX,resY
	10,11 = width,height
	12,13 = type,frameID
	14,15 = frameLen,frameCounter
	16 = lenOfAnimation
	17 = animationID
	*/


	/*
	1 dimension = each cell is a different type (max#ofTypes)
	2 dimension = each cell is a different animation (max#ofAnimations = 8)
	3 dimension = each cell is different frame (max#ofFramesPerAnimation = 16)
	4 dimension = x/y/width/height coordinates of frame on atlas/frame length (5)
	*/


}

void Enemy::setNewTable(EnemyTable eTable) {
	et = eTable;
}

int Enemy::getEnemiesLeft() {
		int num = 0;
		for (int i = 0; i < maxEnemies; i++) {
			if (et.enemyBools[i][0]) {
				num++;
			}
		}
		return num;
	}


int Enemy::var(int enemyID,std::string varID) { //returns values from et.enemyInts in simplified form
		if (varID == "x") {
			return Enemy::et.enemyInts[enemyID][0];
		}
		else if (varID == "y") {
			return Enemy::et.enemyInts[enemyID][1];
		}
		else if (varID == "xv") {
			return Enemy::et.enemyInts[enemyID][2];
		}
		else if (varID == "yv") {
			return Enemy::et.enemyInts[enemyID][3];
		}
		else if (varID == "hp") {
			return Enemy::et.enemyInts[enemyID][4];
		}
		else if (varID == "maxhp" || varID == "maxHP") {
			return Enemy::et.enemyInts[enemyID][5];
		}
		else if (varID == "frameSourceX") {
			return Enemy::et.enemyInts[enemyID][6];
		}
		else if (varID == "frameSourceY") {
			return Enemy::et.enemyInts[enemyID][7];
		}
		else if (varID == "resX") {
			return Enemy::et.enemyInts[enemyID][8];
		}
		else if (varID == "resY") {
			return Enemy::et.enemyInts[enemyID][9];
		}
		else if (varID == "width") {
			return Enemy::et.enemyInts[enemyID][10];
		}
		else if (varID == "height") {
			return Enemy::et.enemyInts[enemyID][11];
		}
		else if (varID == "type") {
			return Enemy::et.enemyInts[enemyID][12];
		}
		else if (varID == "frameID") {
			return Enemy::et.enemyInts[enemyID][13];
		}
		else if (varID == "frameLen") {
			return Enemy::et.enemyInts[enemyID][14];
		}
		else if (varID == "frameCounter") {
			return Enemy::et.enemyInts[enemyID][15];
		}
		else if (varID == "lenOfAnimation") {
			return Enemy::et.enemyInts[enemyID][16];
		}
		else if (varID == "animationID") {
			return Enemy::et.enemyInts[enemyID][17];
		}
		return 0;
	}

void Enemy::setvar(int address, std::string name, int newVal) {
		if (address < Enemy::maxEnemies) {
			if (name == "x") {
				Enemy::et.enemyInts[address][0] = newVal;
				return;
			}
			if (name == "y") {
				Enemy::et.enemyInts[address][1] = newVal;
				return;
			}
			if (name == "xv") {
				Enemy::et.enemyInts[address][2] = newVal;
				return;
			}
			if (name == "yv") {
				Enemy::et.enemyInts[address][3] = newVal;
				return;
			}
			if (name == "hp") {
				Enemy::et.enemyInts[address][4] = newVal;
				return;
			}
		}
	}

void Enemy::setvar(int address, std::string name, bool newVal) {
		if (address < Enemy::maxEnemies) {
			if (name == "exists") {
				Enemy::et.enemyBools[address][0] = newVal;
				return;
			}
			if (name == "visible") {
				Enemy::et.enemyBools[address][1] = newVal;
				return;
			}
			if (name == "vulnerable") {
				Enemy::et.enemyBools[address][2] = newVal;
				return;
			}
			if (name == "collidesWithWall") {
				Enemy::et.enemyBools[address][3] = newVal;
				return;
			}
			if (name == "centeredOrigin") {
				Enemy::et.enemyBools[address][4] = newVal;
				return;
			}
			if (name == "flip") {
				Enemy::et.enemyBools[address][5] = newVal;
				return;
			}
		}
	}

void Enemy::incvar(int address, std::string name, int newVal) {
		if (address < Enemy::maxEnemies) {
			if (name == "x") {
				Enemy::et.enemyInts[address][0] += newVal;
				return;
			}
			if (name == "y") {
				Enemy::et.enemyInts[address][1] += newVal;
				return;
			}
			if (name == "xv") {
				Enemy::et.enemyInts[address][2] += newVal;
				return;
			}
			if (name == "yv") {
				Enemy::et.enemyInts[address][3] += newVal;
				return;
			}
			if (name == "hp") {
				Enemy::et.enemyInts[address][4] += newVal;
				return;
			}
		}
	}

void Enemy::setNewAnimation(int address,int id) {
		Enemy::et.enemyInts[address][17] = id;
		Enemy::et.enemyInts[address][13] = 0;
		Enemy::et.enemyInts[address][15] = 0;
		Enemy::et.enemyInts[address][6] = enemyFrameData[var(address, "type")][id][0][0]; //set sourceX
		Enemy::et.enemyInts[address][7] = enemyFrameData[var(address, "type")][id][0][1]; //set sourceY
		Enemy::et.enemyInts[address][10] = enemyFrameData[var(address, "type")][id][0][2]; //set width
		Enemy::et.enemyInts[address][11] = enemyFrameData[var(address, "type")][id][0][3]; //set height
Enemy::et.enemyInts[address][14] = enemyFrameData[var(address, "type")][id][0][4]; //set frame length
Enemy::et.enemyInts[address][16] = enemyFrameLengths[var(address, "type")][id];
	}

void Enemy::frameProcess(int address) {
		int lastFrameOfLoop = 1;
		if (var(address, "frameCounter") == var(address, "frameLen")) { //if frameCounter == frameLength ; 
			Enemy::et.enemyInts[address][15] = 0;
			if (var(address, "frameID") == var(address, "lenOfAnimation") - 1) {
				Enemy::et.enemyInts[address][13] = 0;
			}
			else {
				Enemy::et.enemyInts[address][13]++;
			}
			Enemy::et.enemyInts[address][6] = enemyFrameData[var(address, "type")][var(address, "animationID")][var(address, "frameID")][0]; //set sourceX
			Enemy::et.enemyInts[address][7] = enemyFrameData[var(address, "type")][var(address, "animationID")][var(address, "frameID")][1]; //set sourceY
			Enemy::et.enemyInts[address][10] = enemyFrameData[var(address, "type")][var(address, "animationID")][var(address, "frameID")][2]; //set width
			Enemy::et.enemyInts[address][11] = enemyFrameData[var(address, "type")][var(address, "animationID")][var(address, "frameID")][3]; //set height
			Enemy::et.enemyInts[address][14] = enemyFrameData[var(address, "type")][var(address, "animationID")][var(address, "frameID")][4]; //set frame length
		}
		else {
			Enemy::et.enemyInts[address][15]++;
		}
	}

bool Enemy::move(int address, int offsetX, int offsetY, bool collideWithWall) {
		if (collideWithWall) {
			if (!level::collisionDetect(var(address, "x"), var(address, "y"), var(address, "width"), var(address, "height"), offsetX, offsetY)) {
				incvar(address, "x", offsetX);
				incvar(address, "y", offsetY);
				return true;
			}
			else {
				return false;
			}
		}
		else {
			incvar(address, "x", offsetX);
			incvar(address, "y", offsetY);
			return true;
		}
		return true;

	}

void Enemy::setPosition(int address, int newX, int newY) {
		setvar(address, "x", newX);
		setvar(address, "y", newY);
	}


void Enemy::fullProcess(Coord player) {
		if (Enemy::enemiesLeft > 0) {
			for (int i = 0; i < Enemy::maxEnemies; i++) {
				if (Enemy::et.enemyBools[i][0]) {
					switch (var(i, "type")) {
					case 0:
						////// START: Magenta Soldiers /////
						//setNewAnimation(i, 0);
						if (var(i, "xv") == 0) {
							setvar(i, "xv", 1);
						}
						if (var(i, "xv") > 0) {
							if (!move(i, 2, 0, true)) {
								setvar(i, "xv", -1);
								setvar(i, "flip", true);
							}
						}
						else if (var(i, "xv") < 0) {
							if (!move(i, -2, 0, true)) {
								setvar(i, "xv", 1);
								setvar(i, "flip", false);
							}
						}
						////// END: Magenta Soldiers /////
						break;
					case 1:
						////// START: Magenta Bullet /////
						////// END: Magenta Bullet /////
						break;

					case 2:
						////// START: Diagonal Bouncer /////
						incvar(i, "x", var(i, "xv"));
						incvar(i, "y", var(i, "yv"));
						////// END: Diagonal Bouncer /////
						break;
					case 3:
						////// START: ROCK /////
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
						////// END: ROCK /////
						break;
					case 4:
						////// START: LEFT BULLET /////
						if (var(i, "xv") < 0 && var(i, "x") < 0) {
							setvar(i, "exists", false);
						}
						else {
							move(i, -4, 0, false);
						}
						////// END: LEFT BULLET /////
						break;
					case 5:
						////// START: LEFT BULLET /////
						if (var(i, "xv") > 0 && var(i, "x") > level::scrnWidth) {
							setvar(i, "exists", false);
						}
						else {
							move(i, 4, 0, false);
						}
						////// END: LEFT BULLET /////
						break;
					case 6:
						////// START: Vertical /////
						if (var(i, "yv") == 0) {
							setvar(i, "yv", 1);
						}
						if (var(i, "yv") > 0) {
							if (!move(i, 0, 2, true)) {
								setvar(i, "xv", -1);
								setvar(i, "flip", true);
							}
						}
						else if (var(i, "yv") < 0) {
							if (!move(i, 0, -2, true)) {
								setvar(i, "yv", 1);
								setvar(i, "flip", false);
							}
						}
						////// END: Vertical /////
						break;
					}
					frameProcess(i);
				}
			}
		}
	}

	void Enemy::makeEnemy(int x, int y, int type) {
		bool foundSlot = false;
		int i = 0;
		while (i < Enemy::maxEnemies - 1 && !foundSlot) {
			if (!Enemy::et.enemyBools[i][0]) {
				foundSlot = true;
				Enemy::et.enemyInts[i][0] = x; //set x location
				Enemy::et.enemyInts[i][1] = y; //set y location
				Enemy::et.enemyInts[i][12] = type; //set typeID
				Enemy::et.enemyBools[i][0] = true; //set exists
				Enemy::et.enemyBools[i][1] = true; //set visibility
				Enemy::et.enemyInts[i][6] = enemyFrameData[type][0][0][0]; //set sourceX
				Enemy::et.enemyInts[i][7] = enemyFrameData[type][0][0][1]; //set sourceY
				Enemy::et.enemyInts[i][10] = enemyFrameData[type][0][0][2]; //set width
				Enemy::et.enemyInts[i][11] = enemyFrameData[type][0][0][3]; //set height
				Enemy::et.enemyInts[i][14] = enemyFrameData[type][0][0][4]; //set frame length
				Enemy::et.enemyInts[i][16] = enemyFrameLengths[type][0];
				Enemy::et.enemyInts[i][17] = 0;
				Enemy::enemiesLeft++;
			}
			i++;
		}
		if (foundSlot) {
			frameProcess(i);
		}
	}

