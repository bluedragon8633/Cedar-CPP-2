#include"basicObjs.h"
#include"interactiveObj.h"


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