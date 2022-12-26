#include"Level.h"
#include"Portals.h"
#include"Player.h"
#include"Collectibles.h"
#include"Enemy.h"
#include "SFML/Graphics.hpp"



Player::Player(int maxHpIn, int startX, int startY, int scale) {
    maxhp = maxHpIn;
    hp = float(maxhp);
    x = startX;
    y = startY;
    scaleX = scale;
    scaleY = scale;
    width = scaleX * resX;
    height = scaleY * resY;
}

void Player::move(int offsetX, int offsetY) {
    x += offsetX;
    y += offsetY;
}

void Player::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

bool Player::checkPortal(Portal port) {
    if (port.isEntityInBounds(x, y) && port.isPortalInScreen) {
        level::LEVEL = port.targetLevel;
        setPosition(port.targetX, port.targetY);
        return true;
    }
    return false;
}

collectibles Player::processCollisions(collectibles col) {
    collectibles newCollect = col;
    for (int i = 0; i < col.maxNumOfCoins; i++) {
        if (newCollect.coinsExist[i]) {

            if (level::collide(x, y, width, height, true, col.coins[i][0], col.coins[i][1], 8 * level::SCALE, 8 * level::SCALE, false)) {
                newCollect.coinsExist[i] = false;
                level::MONEY++;
            }
        }
    }
    return newCollect;
}

void Player::healthProcess(float decrement) { //decrements health
    if (isMortal) {
        if (hp + decrement <= 0) {
            hp = 0;
            level::setGameOver();
        }
        else {
            hp += decrement;
            isMortal = false;
            mortalI = 0;
        }
    }
}
void Player::healthProcess() {
    if (hp == 0) {
        level::setGameOver();
        return;
    }
    if (isMortal) {

    }
    else {
        if (mortalI == mortalLength) {
            isMortal = true;
            mortalI = 0;
        }
        else {
            mortalI++;
        }
    }
    //cout << "mortalI = " << mortalI << "; hp = " << hp << "; STATUS = " << STATUS << endl;
}

void Player::tryKillEnemy(int address, Enemy e) {
    if (spinAtkTimer == -1) {
        if (level::collide(e.et.enemyInts[address][0], e.et.enemyInts[address][1], e.et.enemyInts[address][10], e.et.enemyInts[address][11], e.et.enemyBools[address][4], x, y, width, height, true)) {
            healthProcess(-armourLevel);
        }
    }
    else {
        if (level::collide(e.et.enemyInts[address][0], e.et.enemyInts[address][1], e.et.enemyInts[address][10], e.et.enemyInts[address][11], e.et.enemyBools[address][4], position.x + xv * 36, position.y + yv * 36, 8 * level::SCALE , 32 * level::SCALE, true)) {
            e.et.enemyBools[address][0] = false;
            e.enemiesLeft--;
        }
    }

}

void Player::processFrames() {
    if (isBlasting) {
        blastI++;
        x += scaleX * 4;
        if (blastI >= blastLength) {
            isBlasting = false;
            frame = -1;
        }
        if (frameCounter == 2) {
            frameCounter = 0;
            if (frame == 1) {
                frame = 0;
            }
            else {
                frame++;
            }
        }
        else {
            frameCounter++;
        }
    }
    else {
        if (frameCounter == 4) { //edit this to change the length of each animation frame, in game frames
            frameCounter = 0;
            if (frame != -1) {
                frameCounter = 0;
                if (frame == 3) {
                    frame = 0;
                }
                else {
                    frame++;
                }
            }
        }
        else {
            frameCounter++;
        }
        sourceY = sourceRow * resY;
        sourceX = frame * resX + 80;
    }
    position.set(x, y);
}

void Player::spinAtkProcess() {
    if (spinAtkTimer != -1) {
        if (spinAtkTimer == 20) {
            spinAtkTimer = -1;
            return;
        }
        else {
            if (spinAtkTimer % 4 == 0) {
                atkFrame++;
            }
            spinAtkTimer++;
            
        }
    }
}


bool Player::keyReact(bool up, bool down, bool right, bool left, bool kA, bool kB, bool collU, bool collD, bool collR, bool collL) {
    if (spinAtkTimer != -1) {
        spinAtkProcess();
    }
    if (sourceRow == 1) {
        xv = 0;
        yv = -1;
    }
    else if (sourceRow == 2) {
        xv = 0;
        yv = 1;
    }
    else if (sourceRow == 0) {
        yv = 0;
        if (scaleX < 0) {
            xv = -1;
        }
        else {
            xv = 1;
        }
    }
    if (kB) {
        if (atkReady) {
            atkReady = false;
            if (spinAtkTimer == -1) {
                spinAtkTimer = 0;
                atkFrame = 0;
            }
        }
    }
    else {
        atkReady = true;
    }
    if (up || down || right || left || kA || kB) {
        //touching stats stuff
        if (frame == -1 && (up || down || left || right)) {
            frame = 0;

        }
        if (up && !collU) {
            move(0, -speed);
            sourceRow = 1;
            scaleX = 3;
            if (y <= 0) {
                if (level::LEVEL < 21) {
                    setPosition(x, level::scrnWidth);
                    level::LEVEL += 5;
                    return true;
                }
                else {
                    move(0, speed);
                }
            }
        }
        else if (down && !collD) {
            move(0, speed);
            sourceRow = 2;
            scaleX = 3;
            if (y > level::scrnHeight - 20) {
                if (level::LEVEL > 5) {
                    setPosition(x, 0);
                    level::LEVEL -= 5;
                    return true;
                }
                else {
                    move(0, -speed);
                }
            }
        }
        if (left && !collL) {
            move(-speed, 0);
            scaleX = -3;
            level::blockDir = -1;
            sourceRow = 0;
            if (x <= 0) {
                if (level::LEVEL > 1) {
                    setPosition(level::scrnWidth, y);
                    level::LEVEL--;
                    return true;
                }
                else {
                    move(speed, 0);
                }
            }
        }
        else if (right && !collR) {
            move(speed, 0);
            scaleX = 3;
            level::blockDir = 1;
            sourceRow = 0;
            if (x >= level::scrnWidth - resX / 2 * scaleX) {
                //if (LEVEL < maxLevels) {
                setPosition(0, y);
                level::LEVEL++;
                return true;
                //} else {
                //move(-speed, 0);
                //}
            }
        }


    }
    else {
        frameCounter = 0;
        if (frame == 3) {
            frame = -1;
        }
        if (idleCounter < maxIdle) {
            idleCounter++;
        }
    }
    return false;
}

