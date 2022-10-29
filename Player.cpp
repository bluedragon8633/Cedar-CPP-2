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
	width = 16;
	height = 16;
	canLeaveScreen = false;
	centerOrigin = true;
}

void PlayerObj::process(KeyHandler key) {
	if (key.up) {
		move(0,-2);
		if (isOutOfBounds()) {

		}
		
		flipX = false;
		if (animId != 1) {
			setAnimation(1);
		}
	}
	else if (key.down) {
		move(0, 2);
		flipX = false;
		if (animId != 2) {
			setAnimation(2);
		}
	}
	if (key.right) {
		move(2, 0);
		flipX = false;
		if (animId != 0) {
			setAnimation(0);
		}
	}
	else if (key.left) {
		move(-2, 0);
		flipX = true;
		if (animId != 0 || !flipX) {
			setAnimation(0);
		}
	}



	animationTic();
}