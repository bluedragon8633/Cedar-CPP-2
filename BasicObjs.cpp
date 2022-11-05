#include"BasicObjs.h"
#include"game.h"
frameObj::frameObj() {
	sourceX = 0;
	sourceY = 0;
	sourceWidth = 16;
	sourceHeight = 16;
	frameLength = 4;
}

frameObj::frameObj(int newSrcX, int newSrcY, int newSrcWidth, int newSrcHeight, int newLen) {
	sourceX = newSrcX;
	sourceY = newSrcY;
	sourceWidth = newSrcWidth;
	sourceHeight = newSrcHeight;
	frameLength = newLen;
}

void frameObj::set(int newSrcX, int newSrcY, int newSrcWidth, int newSrcHeight) {
	sourceX = newSrcX;
	sourceY = newSrcY;
	sourceWidth = newSrcWidth;
	sourceHeight = newSrcHeight;
}

bool animObj::isOutOfBounds(GameConsts g) {
	if (x < g.playFieldLeftX || x > g.playFieldRightX || y < g.playFieldTopY || y > g.playFieldBotY) {
		return true;
	}
	return false;
}

void animObj::moveTo(int xin, int yin) {
	x = xin;
	y = yin;
}

void animObj::move(int xin, int yin, GameConsts g) {
	x += xin;
	y += yin;
	if (!canLeaveScreen && isOutOfBounds(g)) {
		x -= xin;
		y -= yin;
	}
}

void animObj::move(GameConsts g) {
	x += xv;
	y += yv;
	if (!canLeaveScreen && isOutOfBounds(g)) {
		x -= xv;
		y -= yv;
	}
}

void animObj::animationTic() {
	int lastFrameOfLoop = 1;
	if (frameCounter == anims[animId].frames[frameId].frameLength) { //if frameCounter == frameLength ; 
		frameCounter = 0;
		if (frameId == anims[animId].animLength - 1) {
			frameId = 0;
		}
		else {
			frameId++;
		}
	}
	else {
		frameCounter++;
	}
}

void animObj::setAnimation(int newId) {
	animId = newId;
	frameCounter = 0;
	frameId = 0;
}

void animObj::makeAnimation(int id,int startX,int startY,int tileWidth,int tileHeight,int length,int frameLen) {
	anims[id].animLength = length;
	
	for (int i=0;i<length;i++) {
		anims[id].frames[i] = { frameObj(startX + (i * tileWidth),startY,tileWidth,tileHeight,frameLen) };
	}
}
