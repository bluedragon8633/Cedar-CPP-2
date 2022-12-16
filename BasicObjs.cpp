#include"BasicObjs.h"
#include"game.h"
#include"GlobalVars.h"

void baseObj::move() {
	setPos(x + xv,y + yv,0);
}

void baseObj::move(int xin, int yin) {
	setPos(x + xin,y + yin,0);
}

void baseObj::setPos(int xin,int yin,int zin) {
	x = xin;
	y = yin;
	z = zin;
}

void baseObj::setSize(int widthin, int heightin) {
	width = widthin;
	height = heightin;
}

void baseObj::setVel(int xvin, int yvin) {
	xv = xvin; yv = yvin;
}

baseObj::baseObj(int xin, int yin, int zin, int widthin, int heightin, int xvin, int yvin) {
	setPos(xin,yin,zin);
	setVel(xvin,yvin);
	setSize(widthin,heightin);
}
baseObj::baseObj() {
	setPos(0,0,0);
	setSize(16,16);
	setVel(0,0);
}
baseObj::baseObj(int xin, int yin, int zin, std::string newClassName) {
	setPos(xin, yin, zin);
	setSize(16, 16);
	setVel(0, 0);
	className = newClassName;
}




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





Billboard::Billboard(int xin,int yin,int newSrcX, int newSrcY, int newSrcWidth, int newSrcHeight,bool origin) {
	x = xin;
	y = yin;
	centerOrigin = origin;
	sourceX = newSrcX;
	sourceY = newSrcY;
	sourceWidth = newSrcWidth;
	sourceHeight = newSrcHeight;
}



bool animObj::isOutOfBounds() {
	if (x < Global::playFieldLeftX || x > Global::playFieldRightX || y < Global::playFieldTopY || y > Global::playFieldBotY) {
		return true;
	}
	return false;
}


animObj::animObj() {

}

void animObj::move(int xin, int yin) {
	//xv = xin;
	//yv = yin;
	x += xin;
	y += yin;
	
	if (!canLeaveScreen && isOutOfBounds()) {
		x -= xin;
		y -= yin;
	}
	if (z == 0) {
		
	}
}

bool animObj::isOnLastFrame() {
	//console.log("frameId = " + to_string(frameId) + "; animLength = " + to_string(anims[animId].animLength));
	return (frameId == anims[animId].animLength - 1);
}

void animObj::move() {
	x += xv;
	y += yv;
	if (!canLeaveScreen && isOutOfBounds()) {
		x -= xv;
		y -= yv;
	}
}

void animObj::animationTic() {
	int lastFrameOfLoop = 1;
	if (frameCounter == anims[animId].frames.at(frameId).frameLength) { //if frameCounter == frameLength ; 
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

void animObj::setAnimation(string newName) {
	for (int i = 0;i < 8;i++) {
		if (anims[i].name == newName) {
			animId = i;
		}
	}
	animName = newName;
	frameCounter = 0;
	frameId = 0;
}

void animObj::makeAnimation(int id,int startX,int startY,int tileWidth,int tileHeight,int length,int frameLen) {
	anims[id].animLength = length;
	anims[id].frames.clear();
	for (int i=0;i<length;i++) {
		anims[id].frames.push_back(frameObj(startX + (i * tileWidth),startY,tileWidth,tileHeight,frameLen));
	}
}
void animObj::makeAnimation(string newName,int id, int startX, int startY, int tileWidth, int tileHeight, int length, int frameLen) {
	for (int i = 0;i < length;i++) {
		if (anims[i].name == newName) {
			animId = i;
		}
	}
	anims[id].animLength = length;
	anims[id].frames.clear(); //empties out slot in preparation for filling new frames in
	for (int i=0;i<length;i++) {
		anims[id].frames.push_back(frameObj(startX + (i * tileWidth),startY,tileWidth,tileHeight,frameLen));
	}
}

sf::Vector2f animObj::topleft() {
	if (centerOrigin) {
		return sf::Vector2f(float(x - width / 2),float(y - height / 2));
	}
	else {
		return sf::Vector2f(float(x), float(y));
	}
}

void animObj::setSize(int newWidth, int newHeight) {
	width = newWidth;
	height = newHeight;
}

baseObj animObj::getBaseObj() {
	return baseObj(x,y,z,width,height,xv,yv);
}


void animObj::setBaseProperties(baseObj b) {
	setPos(b.x,b.y,b.z);
	setVel(b.xv,b.yv);
	setSize(b.width,b.height);
	className = b.className;
}