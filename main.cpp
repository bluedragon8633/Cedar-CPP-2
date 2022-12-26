#include<conio.h>
#include<iostream>
#include <fstream>
#include "SFML/Graphics.hpp"
#include"Enemy.h"
#include"Drawing.h"
#include"Level.h"
#include"Collectibles.h"
#include"Particles.h"
#include"Portals.h"
#include"Player.h"
#include"PauseScreen.h"
#include"Boss.h"
using namespace std;
using namespace Drawing;

const int tilePosCoords[16][2] = { {0,0},{1,0},{2,0},{0,1},{1,1},{2,1},{0,2},{1,2},{2,2},{3,0},{3,0},{3,0},{3,0},{3,0},{3,0} };
string tileCode[16] = { "0011","1011","1001","0111","1111","1101","0110","1110","1100" };


bool DEBUG = true;
bool existingSave = false;

int animTimer = 0; 
int pal = 0;

Player mimi(5, level::scrnWidth / 2, level::scrnHeight / 2, level::SCALE);
Portal portal1;
Portal portal2;
Enemy enemy;
Boss boss;
collectibles col;
PauseScreen pause;
GameOverScreen gameOver;

//DMG == how much damage inflicted per player attack
//FURTHESTROOM == last room player got to before dying
const int lenOfSave = 9;



int wall2Frame = 0;
int wall2i = 0;
const int wall2Delay = 4;
bool bulletVisible = false; bool bulletReady = false; ; int bulletDir = 1; int bulletSpeed = 12;



int index(string listin[], int arrayLen, string val) {
    for (int i = 0; i < arrayLen; i++) {
        if (listin[i] == val) {
            return i;
        }
    }
    return 0;
}

int getTileCoord(int xin, int yin, char retType) {
    char returnType = retType;
    int tilePointer = 0;
    string tileID;


    if (yin == 0) {
        tileID = tileID + "1";
    }
    else if (level::contains(level::wallObjs, level::numOfWallObjs, level::tiles[xin][yin - 1])) {
        tileID = tileID + "1";
    }
    else {
        tileID = tileID + "0";
    }
    if (xin == 0) {
        tileID = tileID + "1";
    }
    else if (level::contains(level::wallObjs, level::numOfWallObjs, level::tiles[xin - 1][yin])) {
        tileID = tileID + "1";
    }
    else {
        tileID = tileID + "0";
    }
    if (yin == 9) {
        tileID = tileID + "1";
    }
    else if (level::contains(level::wallObjs, level::numOfWallObjs, level::tiles[xin][yin + 1])) {
        tileID = tileID + "1";
    }
    else {
        tileID = tileID + "0";
    }

    if (xin == 9) {
        tileID = tileID + "1";
    }
    else if (level::contains(level::wallObjs, level::numOfWallObjs, level::tiles[xin + 1][yin])) {
        tileID = tileID + "1";
    }
    else {
        tileID = tileID + "0";
    }




    //cout << tileID << "; ";
    if (xin == level::scrnTileWidth - 1) {
        //cout << "\n";
    }
    if (returnType == 'X') {
        return tilePosCoords[index(tileCode, 15, tileID)][0];
    }
    else {
        return tilePosCoords[index(tileCode, 15, tileID)][1] + level::PAL * 5;
    }
    return 0;
}

class Checkpoint {
public:
    int room;
    int tileX;
    int tileY;
    Checkpoint(int checkpointRoom, int tx, int ty) {
        room = checkpointRoom;
        tileX = tx;
        tileY = ty;
    }
};
class Pedestal {
public:
    bool exists;
    int drawx, drawy;
    int x, y;
    string message;
    int imgSourceX = 96;
    int imgSourceY = 80;
    int width = 16;
    int height = 16;

    void setCoords(int xin, int yin) {
        drawx = xin;
        drawy = yin;
        x = drawx + level::finalTileSize / 2;
        y = drawy + level::finalTileSize / 2;
    }
    Pedestal(int xin, int yin, string str) {
        exists = false;
        drawx = xin;
        drawy = yin;
        x = drawx + level::finalTileSize / 2;
        y = drawy + level::finalTileSize / 2;
        message = str;
    }

    void draw() {
        Drawing::shadow(96, 96, 16, 3, drawx, drawy + 15, false);
        Drawing::stamp(imgSourceX, imgSourceY, width, height, drawx, drawy, false);
    }
};
Pedestal pedophile(0, 0, "HI DUDE");
void loadLevelData() {
    /////////////////// ERASE PREVIOUS LEVEL ///////////////////
    wall2Frame = 0;
    wall2i = 0;
    enemy.enemiesLeft = 0;
    level::solidObjs[1] = 2;
    for (int i = 0; i < enemy.maxEnemies; i++) {
        enemy.et.enemyBools[i][0] = false;
    }
    col.clearCoins();
    /////////////////// LOAD DATA FROM LEVELS.TXT ///////////////////
    string plainText;
    ifstream ScrnData("./assets/levels.txt");
    for (int i = 0; i < level::LEVEL; i++) {
        getline(ScrnData, plainText);
    }
    int i = 0;
    for (int x = 0; x < level::scrnTileHeight; x++) {
        for (int y = 0; y < level::scrnTileWidth; y++) {
            level::tiles[x][y] = plainText.at(i) - '0';
            i++;
            //cout << tiles[x][y];
        }
        //cout << "\n";
    }
    level::PAL = plainText.at(100) - '0';
    level::isBossRoom = (plainText.at(101) - '0' == 1);
    if (level::isBossRoom) {
        boss.loadBoss();
    }
    /////////////////// CELL-DEPENDENT CODE HERE ///////////////////
    pedophile.exists = false;
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            level::tileCostumeX[y][x] = getTileCoord(x, y, 'X');
            level::tileCostumeY[y][x] = getTileCoord(x, y, 'Y');
            if (level::tiles[y][x] == 3) {
                enemy.makeEnemy(x * level::finalTileSize, y * level::finalTileSize, 3);
            }
            if (level::tiles[y][x] == 5) {
                //enemy.makeEnemy(x * level::finalTileSize, y * level::finalTileSize, 0);
                col.makeCoin(x * level::finalTileSize, y * level::finalTileSize, 1);
            }
            if (level::tiles[y][x] == 4) {
                pedophile.setCoords(x * level::finalTileSize, y * level::finalTileSize);
                pedophile.exists = true;
            }
            
        }
    }
    //cout << "Finished compiling tile data" << endl;
    ScrnData.close();
    portal1.loadPortal();
}

void newGameReady() {
    level::LEVEL = 1;
    level::SCORE = 0;
    level::MONEY = 0;
    level::MAXHP = 10;
    mimi.hp = float(mimi.maxhp);
    mimi.setPosition(level::scrnWidth / 2, level::scrnHeight / 2);
}

string getLineFromFile(string fileName, int line) {
    ifstream TextFile(fileName);
    string returnThis;
    for (int i = 0; i < line; i++) {
        getline(TextFile, returnThis);
    }
    return returnThis;
}

void save() { //UNFINISHED
    ifstream SaveFile("save.txt");
    string writeThis;
    for (int i = 0; i < lenOfSave; i++) {
        writeThis = writeThis + "";
    }
}

void wall2Process() {
    if (enemy.enemiesLeft == 0) {
        if (wall2Frame == 0 && wall2i == 0) {
            wall2i = 1;
        }
        if (wall2i == wall2Delay) {
            wall2i = 0;
            if (wall2Frame < 4) {
                wall2Frame++;
            }
            else {
                level::solidObjs[1] = 1;
            }
        }
        else {
            wall2i++;
        }
    }
}


void keyProcess() {
    //general handling- do not touch
    level::leftK = (sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
    level::rightK = (sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
    level::upK = (sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
    level::downK = (sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
    level::spaceK = (sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
    level::zK = (sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
    level::xK = (sf::Keyboard::isKeyPressed(sf::Keyboard::X));
    level::enterK = (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter));


    //DEV TOOL
    if (DEBUG) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            cout << "STATUS: " << level::STATUS << endl;
            cout << "LEVEL: " << level::LEVEL << endl;
            cout << "IS BOSS ROOM: " << level::isBossRoom << endl;
            cout << "Player: (" << mimi.position.x << "," << mimi.y << ")" << endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            cout << "Which level to fast-travel to?" << endl;
            cin >> level::LEVEL;
            loadLevelData();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
            enemy.enemiesLeft = 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
            level::STATUS = 8; //dialogue
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            mimi.hp = 0;
        }
        else {
            if (level::STATUS == 8) {
                level::STATUS = 6;
            }
        }
    }
    //END DEV TOOL



    //add project-specific code below
    if (level::STATUS == 6) {
        if (mimi.keyReact(level::upK, level::downK, level::rightK, level::leftK, level::zK, level::xK, level::collisionDetect(mimi.position.x, mimi.y, 32, 32, 0, -2), level::collisionDetect(mimi.position.x, mimi.y, 32, 32, 0, 2), level::collisionDetect(mimi.position.x, mimi.y, 32, 32, 2, 0), level::collisionDetect(mimi.position.x, mimi.y, 32, 32, -2, 0))) {
            loadLevelData();
        }
        if (level::zK) {
            if (!bulletVisible && bulletReady) {
                bulletVisible = true;
                //blockBullet.setPosition(float(mimi.position.x), float(mimi.y));
                //bulletDir = blockDir;
            }
        }
    }
}




//DRAWING
void drawParticles(string layer) { //"front" or "back"
    if (layer=="front") {
        for (int i = 0; i < particle::PARTICLE_CAP; i++) {
            if (particle::particleExists[i] && particle::particleData[i][2] == 0) {
                Drawing::drawFloatRect(particle::particleData[i][0], particle::particleData[i][1], 8 - particle::particleData[i][2] * 2, 8 - particle::particleData[i][2] * 2, sf::Color(int(255 - particle::particleData[i][2] * 40), int(255 - particle::particleData[i][2] * 40), int(255 - particle::particleData[i][2] * 40)));
            }
        }
    }
    else {
        for (int i = 0; i < int(particle::PARTICLE_CAP); i++) {
            if (particle::particleExists[i] && particle::particleData[i][2] != 0) {
                Drawing::drawFloatRect(particle::particleData[i][0], particle::particleData[i][1], 8 - particle::particleData[i][2] * 2, 8 - particle::particleData[i][2] * 2, sf::Color(int(255 - particle::particleData[i][2] * 40), int(255 - particle::particleData[i][2] * 40), int(255 - particle::particleData[i][2] * 40)));
            }
        }
    }
    
}
void drawEnemies() { //contains enemy kill code because *efficiency*
    if (enemy.enemiesLeft != 0) {
        for (int i = 0; i < enemy.maxEnemies; i++) {
            if (enemy.et.enemyBools[i][0]) {
                mimi.tryKillEnemy(i,enemy);

                if (enemy.et.enemyBools[i][1]) {
                    if (enemy.et.enemyBools[i][5]) {
                        Drawing::stamp(enemy.et.enemyInts[i][6], enemy.et.enemyInts[i][7], enemy.et.enemyInts[i][10], enemy.et.enemyInts[i][11], enemy.et.enemyInts[i][0], enemy.et.enemyInts[i][1], false, -3, 3);
                    }
                    else {
                        Drawing::stamp(enemy.et.enemyInts[i][6], enemy.et.enemyInts[i][7], enemy.et.enemyInts[i][10], enemy.et.enemyInts[i][11], enemy.et.enemyInts[i][0], enemy.et.enemyInts[i][1], false, 3, 3);
                    }
                }
            }
        }
    }
    if (level::isBossRoom) {
        int i = 0;
        if (boss.enemyBools[i][5]) {
            Drawing::stamp(boss.enemyInts[i][6], boss.enemyInts[i][7], boss.enemyInts[i][10], boss.enemyInts[i][11], boss.enemyInts[i][0], boss.enemyInts[i][1], false, -3, 3);
        }
        else {
            Drawing::stamp(boss.enemyInts[i][6], boss.enemyInts[i][7], boss.enemyInts[i][10], boss.enemyInts[i][11], boss.enemyInts[i][0], boss.enemyInts[i][1], false, 3, 3);
        }
    }
}
void uiBorder(int tlx, int tly, int width, int height, int type) { //Width and height in tiles, not pixels. tlx,tly,width,height,type
    Drawing::stamp(408, 16 + (type * level::uiTileSize * 3), level::uiTileSize, level::uiTileSize, tlx, tly, false); //top left
    Drawing::stamp(408, 16 + (type * level::uiTileSize * 3) + level::uiTileSize * 2, level::uiTileSize, level::uiTileSize, tlx, tly + ((height - 1) * level::SCALE * level::uiTileSize) - (level::SCALE * 2), false); //bottom left tly + ((height - 1) * scale * uiTileSize)
    Drawing::stamp(408 + (level::uiTileSize * 2), 16 + (type * level::uiTileSize * 3), level::uiTileSize, level::uiTileSize, tlx + ((width - 1) * level::SCALE * level::uiTileSize) - (level::SCALE * 2), tly, false); //top right
    Drawing::stamp(408 + (level::uiTileSize * 2), 16 + (type * level::uiTileSize * 3) + level::uiTileSize * 2, level::uiTileSize, level::uiTileSize, (tlx + (width * level::uiTileSize * level::SCALE)) - level::uiTileSize * level::SCALE - (level::SCALE * 2), tly + ((height - 1) * level::SCALE * level::uiTileSize) - (level::SCALE * 2), false); //bottom right

    for (int i = 1; i < height - 1; i++) {
        Drawing::stamp(408, 16 + (type * level::uiTileSize * 3) + level::uiTileSize, level::uiTileSize, level::uiTileSize, tlx, tly + (i * level::SCALE * level::uiTileSize), false); //left side
        Drawing::stamp(424, 16 + (type * level::uiTileSize * 3) + level::uiTileSize, level::uiTileSize, level::uiTileSize, tlx + ((width - 1) * level::SCALE * level::uiTileSize) - (level::SCALE * 2), tly + (i * level::SCALE * level::uiTileSize), false); //right side
    }
    for (int i = 1; i < width - 1; i++) {
        Drawing::stamp(408 + (level::uiTileSize), 16 + (type * level::uiTileSize * 3), level::uiTileSize, level::uiTileSize, tlx + (i * level::SCALE * level::uiTileSize), tly, false); //top side
        Drawing::stamp(408 + (level::uiTileSize), 16 + (type * level::uiTileSize * 3) + level::uiTileSize * 2, level::uiTileSize, level::uiTileSize, tlx + (i * level::SCALE * level::uiTileSize), tly + ((height - 1) * level::SCALE * level::uiTileSize) - (level::SCALE * 2), false); //bottom side
    }

    //cout << "Drawn border" << endl;

}
void drawTiles() {

    Drawing::tile.setScale(sf::Vector2f((level::finalTileSize / level::tileResolution), (level::finalTileSize / level::tileResolution)));
    for (int y = 0; y < level::scrnTileHeight; y++) {
        for (int x = 0; x < level::scrnTileWidth; x++) {

            Drawing::stamp(32, 144/* + level::PAL * 80*/, 16, 16, x * level::finalTileSize, y * level::finalTileSize, false);
            Drawing::tile.setTexture(Drawing::atlas);
            Drawing::tile.setPosition(float(x * level::finalTileSize), float(y * level::finalTileSize));

            if (level::tiles[y][x] == 1) {
                Drawing::tile.setTextureRect(sf::IntRect(level::tileCostumeX[x][y] * level::tileResolution, level::tileCostumeY[x][y] * level::tileResolution + 80, level::tileResolution, level::tileResolution));
                Drawing::window.draw(Drawing::tile);
            }
            else if (level::tiles[y][x] == 2) {
                Drawing::tile.setTextureRect(sf::IntRect(2 * level::tileResolution, 4 * level::tileResolution + 80, level::tileResolution, level::tileResolution));
                Drawing::window.draw(Drawing::tile);
                Drawing::tile.setTexture(Drawing::atlas);
                Drawing::tile.setTextureRect(sf::IntRect((level::tileResolution / 2) * wall2Frame, 64, level::tileResolution / 2, level::tileResolution));
                Drawing::window.draw(Drawing::tile);
            }
            else {
                if (level::tiles[y][x] == 7 && (level::LEVEL == 1 || level::LEVEL == 5 || level::LEVEL == 21 || level::LEVEL == 25)) {
                    Drawing::stamp(80, 112 + level::PAL * 80, 16, 16, x * level::finalTileSize, y * level::finalTileSize, false);
                }
            }

            
            for (int i = 0; i < col.maxNumOfCoins; i++) { //draw coins
                if (level::collide(x * level::finalTileSize + 24, y * level::finalTileSize + 24, 48, 48, true, col.coins[i][0], col.coins[i][0], 8 * level::SCALE, 8 * level::SCALE, false)) {
                    Drawing::stamp(48, 80, 16, 16, x * level::finalTileSize, y * level::finalTileSize, false);
                }
            }
        }
    }

    //drawCollisionBox(false);
}
void drawHUD(bool paused) {
    /////////////////// HEALTH BAR ///////////////////
    if (mimi.hp == 0) {
        Drawing::stamp(408, 8, 8, 8, level::hudMargin, level::hudMargin, false, "HUD");
    }
    else {
        Drawing::stamp(408, 0, 8, 8, level::hudMargin, level::hudMargin, false, "HUD");
    }
    for (int i = 1; i < mimi.maxhp - 1; i++) {
        if (i <= mimi.hp) {
            Drawing::stamp(416, 0, 8, 8, i * 24 + level::hudMargin, level::hudMargin, false, "HUD");
        }
        else {
            Drawing::stamp(416, 8, 8, 8, i * 24 + level::hudMargin, level::hudMargin, false, "HUD");
        }
    }
    if (mimi.hp == mimi.maxhp) {
        Drawing::stamp(424, 0, 8, 8, level::hudMargin + (mimi.maxhp - 1) * 24, level::hudMargin, false, "HUD");
    }
    else {
        Drawing::stamp(424, 8, 8, 8, level::hudMargin + (mimi.maxhp - 1) * 24, level::hudMargin, false, "HUD");
    }
    /////////////////// MONEY ///////////////////
    //Drawing::stamp(0,0,0,0,0,0,true);
    Drawing::stamp(400, 8, 8, 8, level::hudMargin, 24 + (level::hudMargin * 2), false, 3, 3);
    print(level::hudMargin * 2 + 40, 32 + level::hudMargin * 2, to_string(level::MONEY), 24, true, 3);

    /////////////////// ENEMY COUNTER ///////////////////
    Drawing::stamp(400, 16, 8, 8, level::hudMargin, 48 + (level::hudMargin * 3), false, 3, 3);
    print(level::hudMargin * 2 + 40, 56 + level::hudMargin * 3, to_string(enemy.enemiesLeft), 24, true, 3);

    /////////////////// LEVEL # ///////////////////
    print(level::scrnWidth / 2, 10, to_string(level::LEVEL), 16, true);

    //print(4,440,to_string(mimi.position.x),16,false);
}
void drawMainMenu(int variant) {
    Drawing::window.clear(sf::Color::Black);
    if (variant == 1) { //TITLE
        drawParticles("back");
        Drawing::stamp(432, 0, 80, 48, level::scrnWidth / 2, 120, true);
        print(level::scrnWidth / 2, 230, "Z TO START", 16, true, sf::Color::White);
        drawParticles("front");
    }
    else if (variant == 2) { //MAIN MENU
        Drawing::stamp(432, 0, 80, 48, level::scrnWidth / 2, 120, true);
        if (existingSave) {
            print(164, 230, "NEW GAME\nCONTINUE\nEXTRAS\nOPTIONS\nEXIT", 16, false);
        }
        else {
            print(164, 230, "NEW GAME\nEXTRAS\nOPTIONS\nEXIT", 16, false);
        }
        print(144, 230 + level::menuSelectY * 20, "~", 16, false);
    }
    else if (variant == 3) { //EXTRAS SCREEN
        print(level::hudMargin, level::hudMargin, "EXTRAS\nPRESS X TO RETURN", 16, false);
    }
    else if (variant == 4) { //SETTINGS
        print(level::hudMargin, level::hudMargin, "SETTINGS\nPRESS X TO RETURN", 16, false);
        print(level::hudMargin, level::hudMargin + 50, "VOLUME <10>", 16, false);
        print(level::hudMargin, level::hudMargin + 70, "SPEEDRUN CLOCK <ON>", 16, false);
    }
    else if (variant == 9) { //GAME OVER
        Drawing::window.clear(sf::Color::Black);
        Drawing::stamp(440,176,72,24,240,120,true);
        print(120, 240, "RESTART\nQUIT", 16, false);
        print(104, 240 + level::menuSelectY * 20, "~", 16, false);
        if (gameOver.areYouSure) {
            Drawing::drawRect(120, 120, 240, 80, sf::Color::Black);
            Drawing::drawOutlineRect(120, 120, 240, 80, 2);
            print(240, 128, "ARE YOU SURE?", 16, true);
            print(140, 140, " YES    NO", 16, false);
            print(126 + level::menuSelectX * 80, 140, "~", 16, false);
        }
    }

}
void drawPauseScreen() {
    Drawing::window.clear(sf::Color::Black);
    
    print(32,48,"-PAUSED-\n RESUME\n QUIT",16,false);
    print(30,68 + level::menuSelectY * 20,"~",16,false);
    if (pause.areYouSure) {
        Drawing::drawRect(120, 120, 240, 120, sf::Color::Black);
        Drawing::drawOutlineRect(120, 120, 240, 120, 2);
        print(240, 128, "ARE YOU SURE?", 16, true);
        print(140,140," YES    NO",16,false);
        print(126 + level::menuSelectX * 80, 140, "~", 16, false);
    }
}
void drawCoins() {
    col.processCoinFrame();
    for (int i = 0; i < col.maxNumOfCoins; i++) {
        if (col.coinsExist[i]) {
            Drawing::stamp(48 + col.coinFrame * 8, 64, 8, 8, col.coins[i][0], col.coins[i][1], false, 3, 3);
        }
    }
}
void drawGame() {
    Drawing::window.clear(sf::Color::Red);
    drawTiles();
    drawEnemies();
    drawCoins();
    if (bulletVisible) {
        //Drawing::window.draw(blockBullet);
    }


    Drawing::block.setColor(sf::Color(255, 255, 255, 255));
    if (pedophile.exists) {

        pedophile.draw();
        if (pedophile.y < mimi.y && mimi.y < pedophile.y + level::finalTileSize + 16 && mimi.position.x - 16 < pedophile.x && pedophile.x < mimi.position.x + 16) {
            if (mimi.y > level::scrnHeight / 2) {
                Drawing::drawRect(42, 42, 396, 120);
                print(42 + level::hudMargin, 42 + level::hudMargin, pedophile.message, 16, false);
            }
            else {
                Drawing::drawRect(42, 318, 396, 120);
                print(42 + level::hudMargin, 318 + level::hudMargin, pedophile.message, 16, false);
            }

        }
    }

    Drawing::stamp(mimi.sourceX, mimi.sourceY, mimi.resX, mimi.resY, mimi.position.x, mimi.position.y, true, mimi.scaleX, mimi.scaleY);
    if (mimi.spinAtkTimer != -1) {
        int dir = 0;
        if (mimi.xv == 0 && mimi.yv == 1) {
            dir = 90;
        }
        else if (mimi.xv == 0 && mimi.yv == -1) {
            dir = -90;
        }
        else if (mimi.xv == -1) {
            dir = 180;
        }
        Drawing::stamp(144 + mimi.atkFrame * 8, 0, 8, 32, mimi.position.x + mimi.xv * 36, mimi.position.y + mimi.yv * 36, true,dir);
        Drawing::drawRect(Drawing::block.getPosition().x,Drawing::block.getPosition().y,4,4,sf::Color::Red);
    }
    
    Drawing::drawRect(mimi.position.x + mimi.xv * 36, mimi.position.y + mimi.yv * 36, 4, 4, sf::Color::Magenta);
    //cout << "ATKREADY: " << mimi.atkReady << "; ATKTIMER: " << mimi.spinAtkTimer << endl;


}


//MAIN
void process() {
    switch (level::STATUS) {
    case 0: //0 == LOGO SCREEN
        animTimer += 1;
        if (animTimer == 25) { //original timer value was 100, but was shortened for testing purposes
            level::STATUS = 1;
            particle::particlesOn(0,40);
        }


        Drawing::window.clear(sf::Color::Black);
        Drawing::stamp(24, 48, 16, 16, level::scrnWidth / 2, level::scrnHeight / 2, true);
        print(level::scrnWidth / 2, 280, "bluedragon8633", 16, true);
        break;
    case 1: //1 == TITLE SCREEN
        if (level::zK) {
            level::STATUS = 2;
            animTimer = 0;
            level::selectKeyReady = false;
            level::menuSelectX = 0;
            level::menuSelectY = 0;
            particle::particlesOff();
        }
        drawMainMenu(1);
        particle::fullProcess();
        break;
    case 2: //MAIN MENU SCREEN
        if (level::zK && level::selectKeyReady) {
            int offset = 1;
            if (existingSave) {
                offset = -1;
            }
            if (level::menuSelectY == 0) { //NEW GAME
                level::STATUS = 6;
                newGameReady();
                loadLevelData();
                level::hudOffset = -80;
            }
            else if (level::menuSelectY + offset == 1) { //CONTINUE GAME
                cout << "CONTINUE GAME; menuSelect + offset = " << level::menuSelectY + offset << endl;
            }
            else if (level::menuSelectY + offset == 2) { //EXTRAS OPTION
                level::STATUS = 3;
                level::menuSelectX = 0;
                level::menuSelectY = 0;
            }
            else if (level::menuSelectY + offset == 3) { //SETTINGS OPTION
                level::STATUS = 4;
                level::menuSelectX = 0;
                level::menuSelectY = 0;
            }
            else if (level::menuSelectY + offset == 4) { //QUIT OPTION
                cout << "Window quitted" << endl;
                Drawing::window.close();
                break;
            }

            animTimer = 0;
        }
        else if (!level::zK) {
            level::selectKeyReady = true;
        }
        if (level::downK && level::downKeyReady && ((level::menuSelectY <= 4 && existingSave) || (level::menuSelectY <= 3 && !existingSave))) {
            level::menuSelectY++;
            level::downKeyReady = false;
        }
        else if (!level::downK) {
            level::downKeyReady = true;
        }
        if (level::upK && level::upKeyReady && level::menuSelectY > 0) {
            level::menuSelectY--;
            cout << level::menuSelectY << endl;
            level::upKeyReady = false;
        }
        else if (!level::upK) {
            level::upKeyReady = true;
        }
        drawMainMenu(level::STATUS);
        break;
    case 3: //3 == EXTRAS MENU SCREEN
        if (level::xK) {
            if (level::backKeyReady) {
                level::backKeyReady = false;
                level::STATUS = 2;
                if (existingSave) {
                    level::menuSelectY = 2;
                }
                else {
                    level::menuSelectY = 1;
                }
            }
        }
        else {
            level::backKeyReady = true;
        }
        drawMainMenu(level::STATUS);
        break;
    case 4: //SETTINGS MENU SCREEN
        if (level::xK) {
            if (level::backKeyReady) {
                level::backKeyReady = false;
                level::STATUS = 2;
            }
        }
        else {
            level::backKeyReady = true;
        }
        drawMainMenu(level::STATUS);
        break;
    case 5: //STATS SCREEN

        break;
    case 6: //6 == GAME
        if (level::enterK) {
            if (level::pauseKeyReady) {
                level::pauseKeyReady = false;
                level::STATUS = 7;
                pause.areYouSure = false;
                
            }
        }
        else {
            level::pauseKeyReady = true;
        }
        //bulletProcess();
        if (animTimer == 10) {
            bulletReady = true;
        }
        else {
            animTimer++;
        }
        if (level::hudOffset > 0) {
            level::hudOffset -= 5;
        }
        else {
            level::hudOffset = 0;
        }
        wall2Process();
        enemy.fullProcess(mimi.position);
        enemy.setNewTable(boss.fullProcess(enemy.et));
        
        mimi.processFrames();
        col.setTo(mimi.processCollisions(col));
        mimi.healthProcess();
        if (mimi.checkPortal(portal1) || mimi.checkPortal(portal2)) {
            loadLevelData();
            portal1.erase();
        }
        drawGame();
        drawHUD(false);
        break;
    case 7: //7 == PAUSE MENU
        pause.process();
        drawPauseScreen();
        break;
    case 8: //8 == DIALOGUE BOXES
        Drawing::drawRect(42, 42, 396, 180);
        uiBorder(47, 48, 16, 7, 0);
        break;
    case 9: //9 == GAME OVER
        gameOver.process();
        if (level::selectKeyReady && level::zK && level::menuSelectY == 0) {
            level::STATUS = 6;
            newGameReady();
            loadLevelData();
        }


        drawMainMenu(9);
        break;
    case 10: //CREDITS

        break;
    }
    Drawing::window.display();
}

void setFocus() {
    sf::Event event;
    while (Drawing::window.pollEvent(event)) 
    {
        if (event.type == sf::Event::GainedFocus) {
            level::isFocused = true;
            cout << "Gained focus" << endl;
        }
        else if (event.type == sf::Event::LostFocus) {
            level::isFocused = false;
            cout << "Lost focus" << endl;
        }
    }
}


int main() {
    Drawing::loadTextures();
    Drawing::resizeWindow("Mimi's Test!", level::scrnWidth, level::scrnHeight);
    while (Drawing::window.isOpen()) {

        while (Drawing::window.pollEvent(Drawing::e))
        {
            if (Drawing::e.type == sf::Event::Closed)
                Drawing::window.close();
        }
        setFocus();
        if (level::isFocused) {
            keyProcess();
            process();
        }
        
    }

    return 0;
}
