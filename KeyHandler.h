#pragma once
class KeyHandler {
public:
    bool left, right, up, down, a, b, enter, space;
    bool leftReady, rightReady, upReady, downReady, aReady, bReady, enterReady, spaceReady;

    void process();
    bool getA();
    bool getB();
    bool getUp();
    bool getDown();
    bool getRight();
    bool getLeft();
    bool getStart();
    bool canUseA();
    bool canUseUp();
    bool canUseDown();
};