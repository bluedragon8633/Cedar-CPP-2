#include"BasicObjs.h"
#include"game.h"


void baseObj::setPos(int xin,int yin,int zin) {
	x = xin;
	y = yin;
	z = zin;
}
baseObj::baseObj(int xin, int yin, int zin, int width, int height, int xvin, int yvin) {
	setPos(xin,yin,zin);

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



bool animObj::isOutOfBounds(GameConsts g) {
	if (x < g.playFieldLeftX || x > g.playFieldRightX || y < g.playFieldTopY || y > g.playFieldBotY) {
		return true;
	}
	return false;
}
bool animObj::isOutOfBounds(GameConsts g,Area area) {
	if (className == "player") {
		if (x < g.playFieldLeftX) {
			if (area.level().x == 0) {
				return true;
			}
			else {

			}

		}
		if (x < g.playFieldLeftX || x > g.playFieldRightX || y < g.playFieldTopY || y > g.playFieldBotY) {
			return true;
		}
		if (x < g.playFieldLeftX || x > g.playFieldRightX || y < g.playFieldTopY || y > g.playFieldBotY) {
			return true;
		}
		if (x < g.playFieldLeftX || x > g.playFieldRightX || y < g.playFieldTopY || y > g.playFieldBotY) {
			return true;
		}
	}
	else {
		if (x < g.playFieldLeftX || x > g.playFieldRightX || y < g.playFieldTopY || y > g.playFieldBotY) {
			return true;
		}
	}

	return false;
}



void animObj::move(int xin, int yin, GameConsts g) {
	//xv = xin;
	//yv = yin;
	x += xin;
	y += yin;
	
	if (!canLeaveScreen && isOutOfBounds(g)) {
		x -= xin;
		y -= yin;
	}
	if (z == 0) {
		
	}
}

bool animObj::isOnLastFrame() {
	//console::log("frameId = " + to_string(frameId) + "; animLength = " + to_string(anims[animId].animLength));
	return (frameId == anims[animId].animLength - 1);
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

}