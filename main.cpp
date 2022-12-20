#include<iostream>
#include <fstream>
#include<vector>
#include"game.h"
#include"BasicObjs.h"
#include"general.h"
#include"Drawer.h"
#include"enemy.h"
#include"tile.h"
#include"UI.h"
#include"interactiveObj.h"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"KeyHandler.h"
#include"GlobalVars.h"

using namespace std;
using namespace Drawer;
using namespace Global;


TileMap tMap(0,0);
EnemyTable enemies;

void eventHandle() {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    if (key.space) {
        string userIn;
        cout << "Enter command: " << endl;
        cin >> userIn;
        if (userIn == "refresh") {
            window.create(sf::VideoMode(Global::scrnWidth * Global::GAME_SCALE, Global::scrnHeight * Global::GAME_SCALE), Global::TITLE, sf::Style::Close);
            Global::loadData();
            loadTextures();
        }
        else if (userIn == "tileInfo") {
            console.log("tile size: " + to_string(tMap.width) + "," + to_string(tMap.height));
            console.log("size of tileMap object: " + to_string(sizeof(tMap)));
            console.log("size of tileMap array: " + to_string(sizeof(Global::tiles)));
        }
        else if (userIn == "tileData") {
            console.log("tileStr: " + tMap.getTileCostStr(0,1));
        }
        
    }
}

void playerCollision() {
    player.oldPos.set(player.x,player.y);
    player.oldVel.set(player.xv,player.yv);
    player.movedThisFrame = false;
    player.processX(key);
    if (tMap.isObjOnWall(player)) {
        player.move(-player.xv, 0);
    }
    player.processY(key);
    if (tMap.isObjOnWall(player)) {
        player.move(0, -player.yv);
    }
    int canChangeLevel = player.getLevelIncrement();
    if ((canChangeLevel != 0)) {
        console.log("level increment: " + to_string(canChangeLevel));
        tMap.load(area.areaId,area.levelId += canChangeLevel);
    }
    player.animationProcess();

}

interactiveObj tileCollision(interactiveObj obj) {
    //obj.oldPos.set(player.x, player.y);
    //obj.oldVel.set(player.xv, player.yv);
    //interactiveObj obj = *objIn;
    //obj.movedThisFrame = false;
    obj.touchedWallThisFrame = false;
    obj.move(obj.xv,0);
    if (tMap.isObjOnWall(obj)) {

        obj.move(-obj.xv, 0);
        obj.touchedWallThisFrame = true;
        //console.log("oops :skull:");
    }
    obj.move(0,obj.yv);
    if (tMap.isObjOnWall(obj)) {
        obj.move(0, -obj.yv);
        obj.touchedWallThisFrame = true;
    }
    //obj.animationTic();
    return obj;
}

void processGame() {
    key.process();
    playerCollision();
    for (int i = 0; i < enemies.enemiesLeft(); i++) {
        enemies.enemies.at(i).processedCollision = false;
    }
    enemies.processAll();
    for (int i = 0; i < enemies.enemiesLeft();i++) {
        enemies.enemies.at(i).setBaseProperties(tileCollision(enemies.enemies.at(i)).getBaseObj()); //process collisions
        enemies.enemies.at(i).processedCollision = true;
    }
    enemies.processAll();
    if (tMap.getJustLoaded()) {
        enemies.clear();
        enemies.addEnemies(tMap.getEnemies());
    }
    //console.log("about to process enemies");
    
    //console.log("finished processing");
    //t.processAll();
}

void drawGame() {
    window.clear();
    tMap.drawTiles();
    stamp(player);
    //console.log("enemies left: " + to_string(enemies.enemiesLeft()));
    if (enemies.enemiesLeft() > 0) {
        for (int i = 0; i < enemies.enemiesLeft(); i++) {
            //console.log("about to stamp");
            stamp(enemies.enemies.at(i));
        }
    }
    //stamp(0,16,48,48,0,0,false);


}

void process() {
    if (Global::STATUS == "splash") {

        SplashScreen s;
        for (int i = 0; i < 30; i++) {
            eventHandle();
            s.draw();
            window.display();
        }

        Global::STATUS = "title";
    }
    else if (Global::STATUS == "title") {
        TitleScreen t;

        while(Global::STATUS == "title") {
            eventHandle();
            key.process();
            t.process(key);
            t.draw();
            window.display();
        }
        
    }
    else if (Global::STATUS == "quitConfirm") {
        QuitConfirm t;
        while (Global::STATUS == "quitConfirm") {
            eventHandle();
            key.process();
            t.process(key);
            t.draw();
            window.display();
        }
    }
    else if (Global::STATUS == "game") {
        HUD h;
        tMap.load(Global::MAP,Global::LEVEL);
        console.log("Initialized game");
        while (Global::STATUS == "game") {
            eventHandle();
            processGame();
            drawGame();

            h.draw();
            window.display();
        }

    }
}



int main() {
    console.log("Look alive, sunshine!");
    setup();
    console.log("size of baseObj:" + to_string(sizeof(baseObj)));
    console.log("size of Player:" + to_string(sizeof(player)));
    console.log("Window size: " + to_string(window.getSize().x) + "," + to_string(window.getSize().y));
    console.log("game SCALE: " + to_string(Global::GAME_SCALE));
    console.log("target framerate = " + to_string(Global::FRAME_LIMIT));
    
    while (window.isOpen())
    {
        eventHandle();

        process();
    }
    return 0;
}
