#include"PauseScreen.h"
#include"Level.h"

using namespace level;

void PauseScreen::process() {

    if (areYouSure) {
        //RIGHT KEY
        if (rightK && rightKeyReady && level::menuSelectX < 1) {
            level::menuSelectX++;
            rightKeyReady = false;
        }
        else if (!rightK) {
            rightKeyReady = true;
        }
        //LEFT KEY
        if (leftK && leftKeyReady && level::menuSelectX > 0) {
            level::menuSelectX--;
            leftKeyReady = false;
        }
        else if (!leftK) {
            leftKeyReady = true;
        }
        //Z KEY
        if (!level::zK) {
            selectKeyReady = true;
        }
        if (level::selectKeyReady && level::zK) {
            printf("onstandby" + menuSelectX);
            level::selectKeyReady = false;
            if (level::menuSelectX == 1) {
                areYouSure = false;
            }
            if (level::menuSelectX == 0) {
                level::STATUS = 1;
            }
            menuSelectX = 0;
        }
    }
    else {
        //UNPAUSE
        if (enterK || (level::zK && level::selectKeyReady && menuSelectY == 0)) {
            if (pauseKeyReady) {
                pauseKeyReady = false;
                level::STATUS = 6;
            }
        }
        else {
            pauseKeyReady = true;
        }

        //UP AND DOWN
        if (downK && downKeyReady && level::menuSelectY < 1) {
            level::menuSelectY++;
            downKeyReady = false;
        }
        else if (!downK) {
            downKeyReady = true;
        }
        if (upK && upKeyReady && level::menuSelectY > 0) {
            level::menuSelectY--;
            upKeyReady = false;
        }
        else if (!upK) {
            upKeyReady = true;
        }
        //SELECT
        if (!level::zK) {
            selectKeyReady = true;
        }
        if (level::selectKeyReady && level::zK && level::menuSelectY == 1) {
            areYouSure = true;
            selectKeyReady = false;
            level::menuSelectX = 0;
        }
    }
}


void GameOverScreen::process() {

    if (areYouSure) {
        //RIGHT KEY
        if (rightK && rightKeyReady && level::menuSelectX < 1) {
            level::menuSelectX++;
            rightKeyReady = false;
        }
        else if (!rightK) {
            rightKeyReady = true;
        }
        //LEFT KEY
        if (leftK && leftKeyReady && level::menuSelectX > 0) {
            level::menuSelectX--;
            leftKeyReady = false;
        }
        else if (!leftK) {
            leftKeyReady = true;
        }
        //Z KEY
        if (!level::zK) {
            selectKeyReady = true;
        }
        if (level::selectKeyReady && level::zK) {
            printf("onstandby" + menuSelectX);
            level::selectKeyReady = false;
            if (level::menuSelectX == 1) {
                areYouSure = false;
            }
            if (level::menuSelectX == 0) {
                level::STATUS = 1;
            }
            menuSelectX = 0;
        }
    }
    else {
        //UNPAUSE
        if (enterK || (level::zK && level::selectKeyReady && menuSelectY == 0)) {
            if (pauseKeyReady) {
                pauseKeyReady = false;
                level::STATUS = 6;
            }
        }
        else {
            pauseKeyReady = true;
        }

        //UP AND DOWN
        if (downK && downKeyReady && level::menuSelectY < 1) {
            level::menuSelectY++;
            downKeyReady = false;
        }
        else if (!downK) {
            downKeyReady = true;
        }
        if (upK && upKeyReady && level::menuSelectY > 0) {
            level::menuSelectY--;
            upKeyReady = false;
        }
        else if (!upK) {
            upKeyReady = true;
        }
        //SELECT
        if (!level::zK) {
            selectKeyReady = true;
        }
        if (level::selectKeyReady && level::zK && level::menuSelectY == 1) {
            areYouSure = true;
            selectKeyReady = false;
            level::menuSelectX = 0;
        }
    }
}