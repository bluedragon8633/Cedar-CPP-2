#include"basicObjs.h"
#include"interactiveObj.h"

interactiveObj::interactiveObj(int xin, int yin, int newWidth, int newHeight) {
    moveTo(xin,yin);
    setSize(newWidth,newHeight);
}

interactiveObj::interactiveObj(int xin, int yin, int newWidth, int newHeight, bool centeredOrigin) {
    moveTo(xin, yin);
    setSize(newWidth, newHeight);
    centerOrigin = centeredOrigin;
}

interactiveObj::interactiveObj() {

}

bool interactiveObj::isObjOverlapping(interactiveObj in1, interactiveObj in2) {
    return (sf::IntRect(in1.topleft().x, in1.topleft().y, in1.width, in1.height).intersects(sf::IntRect(in2.topleft().x, in2.topleft().y, in2.width, in2.height)));
}

bool interactiveObj::isObjOverlapping(interactiveObj in1) {
    return (sf::IntRect(topleft().x, topleft().y, width, height).intersects(sf::IntRect(in1.topleft().x, in1.topleft().y, in1.width, in1.height)));
}

void healthyObj::healthTic() {
    if (hp == 0) {
        isDead = true;
        return;
    }
    if (isMortal) {

    }
    else {
        if (mortalFrame == immortalFrameLength) {
            isMortal = true;
            mortalFrame = 0;
        }
        else {
            mortalFrame++;
        }
    }
}

void healthyObj::healthTic(int decrement) {
    if (isMortal) {
        if (hp + decrement <= 0) {
            hp = 0;
            isDead = true;
        }
        else {
            hp += decrement;
            isMortal = false;
            mortalFrame = 0;
        }
    }
}