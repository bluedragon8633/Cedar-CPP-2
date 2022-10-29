#include"BasicObjs.h"

frameObj::frameObj() {
	flipX = false;
	flipY = false;
	sourceX = 0;
	sourceY = 0;
	sourceWidth = 16;
	sourceHeight = 16;
	frameLength = 4;
}

frameObj::frameObj(int newSrcX, int newSrcY, int newSrcWidth, int newSrcHeight, int newLen) {
	flipX = false;
	flipY = false;
	sourceX = newSrcX;
	sourceY = newSrcY;
	sourceWidth = newSrcWidth;
	sourceHeight = newSrcHeight;
	frameLength = newLen;
}

bool animObj::isOutOfBounds() {
	if (x < 0 || y < 0) {
		return true;
	}
	return false;
}

void animObj::moveTo(int xin, int yin) {
	x = xin;
	y = yin;
}

void animObj::move(int xin, int yin) {
	x += xin;
	y += yin;
	if (canLeaveScreen && isOutOfBounds()) {
		x -= xin;
		y -= yin;
	}
}

void animObj::move() {
	x += xv;
	y += yv;
	if (canLeaveScreen && isOutOfBounds()) {
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