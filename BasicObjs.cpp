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


void animObj::moveTo(int xin, int yin) {
	x = xin;
	y = yin;
}

void animObj::move(int xin, int yin) {
	x += xin;
	y += yin;
}

void animObj::move() {
	x += xv;
	y += yv;
}

void animObj::animationTic() {

}

void animObj::setAnimation() {

}