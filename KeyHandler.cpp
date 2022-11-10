#include"SFML/Graphics.hpp"
#include"KeyHandler.h"



void KeyHandler::process() {
    //general handling- do not touch
    left = (sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
    right = (sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
    up = (sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
    down = (sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
    space = (sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
    a = getA();
    b = (sf::Keyboard::isKeyPressed(sf::Keyboard::X));
    enter = getStart();
    if (!a) {
        aReady = true;
    }
    if (!up) {
        upReady = true;
    }
}

bool KeyHandler::canUseA() {
    a = getA();
    if (a) {
        if (aReady) {
            aReady = false;
            return true;
        }
    }
    else {
        aReady = true;
    }
    return false;
}

bool KeyHandler::canUseUp() {
    up = getUp();
    if (up) {
        if (upReady) {
            upReady = false;
            return true;
        }
    }
    else {
        upReady = true;
    }
    return false;
}
bool KeyHandler::canUseDown() {
    down = getUp();
    if (down) {
        if (downReady) {
            downReady = false;
            return true;
        }
    }
    else {
        downReady = true;
    }
    return false;
}

bool KeyHandler::getA() {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
}
bool KeyHandler::getB() {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
}
bool KeyHandler::getUp() {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
}
bool KeyHandler::getDown() {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
}
bool KeyHandler::getRight() {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
}
bool KeyHandler::getLeft() {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
}

bool KeyHandler::getStart() {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter));
}