#include<iostream>
#include"interactiveObj.h"
#include"Player.h"
#include"BasicObjs.h"
#include"game.h"
using namespace std;

PlayerObj::PlayerObj() {
	anims[0].animLength = 4;
	anims[0].frames[0] = { frameObj(80,0,tileSize,tileSize,walkFrameLength) };
	anims[0].frames[1] = { frameObj(96,0,tileSize,tileSize,walkFrameLength) };
	anims[0].frames[2] = { frameObj(112,0,tileSize,tileSize,walkFrameLength) };
	anims[0].frames[3] = { frameObj(128,0,tileSize,tileSize,walkFrameLength) };
	anims[1].animLength = 4;
	anims[1].frames[0] = { frameObj(80,16,tileSize,tileSize,walkFrameLength) };
	anims[1].frames[1] = { frameObj(96,16,tileSize,tileSize,walkFrameLength) };
	anims[1].frames[2] = { frameObj(112,16,tileSize,tileSize,walkFrameLength) };
	anims[1].frames[3] = { frameObj(128,16,tileSize,tileSize,walkFrameLength) };
	anims[2].animLength = 4;
	anims[2].frames[0] = { frameObj(80,32,tileSize,tileSize,walkFrameLength) };
	anims[2].frames[1] = { frameObj(96,32,tileSize,tileSize,walkFrameLength) };
	anims[2].frames[2] = { frameObj(112,32,tileSize,tileSize,walkFrameLength) };
	anims[2].frames[3] = { frameObj(128,32,tileSize,tileSize,walkFrameLength) };



	x = 0;
	y = 0;
	canLeaveScreen = false;
}

void PlayerObj::process(KeyHandler key) {
	if (key.up) {
		y -= 2;
		if (isOutOfBounds()) {

		}
		
		anims[animId].frames[frameId].flipX = false;
	}
	else if (key.down) {
		y += 2;
		anims[animId].frames[frameId].flipX = false;
	}
	if (key.right) {
		x += 2;
		anims[animId].frames[frameId].flipX = false;
	}
	else if (key.left) {
		x -= 2;
		anims[animId].frames[frameId].flipX = true;
	}



	animationTic();
}