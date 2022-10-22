#include"BasicObjs.h"


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