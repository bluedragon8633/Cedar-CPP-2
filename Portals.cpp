#include"Portals.h"
#include<iostream>
#include<fstream>
#include"Level.h"
#include<string>
#include <vector>
using namespace std;

/*
    int x, y, width, height, startLevel, targetLevel;
    int targetX, targetY;
    bool isPortalInScreen;
*/

bool Portal::isEntityInBounds(int ex,int ey) {
    if (x < ex && y < ey && ex < x + width && ey < y + height && isPortalInScreen) {
        return true;
    }
	return false;
}

void Portal::erase() {
    isPortalInScreen = false;
}


void Portal::loadPortal() {
    string plainText = "000-000-000-000-000-000-000-000";
    string temp = "";
    ifstream ScrnData("./assets/portals.txt");
    bool found = false;
    //cout << "created strings for portal" << endl;
    while (!found) {
        getline(ScrnData, temp);
        //cout << "got line " << temp.substr(0,3) << endl;
        if (temp == "end") {
            //cout << "ended data search" << endl;
            break;
        } else if (level::LEVEL == stoi(temp.substr(0, 3))) {
            found = true;
            //cout << "found level's portal" << endl;
            break;
        }   
    }
    if (found) {
        plainText = temp;
        //writes raw data to values
        isPortalInScreen = true;
        x = stoi(plainText.substr(4, 3));
        y = stoi(plainText.substr(8, 3));
        width = stoi(plainText.substr(12, 3));
        height = stoi(plainText.substr(16, 3));
        targetLevel = stoi(plainText.substr(20, 3));
        targetX = stoi(plainText.substr(24, 3));
        targetY = stoi(plainText.substr(28, 3));

        //adjusts values to be readable
        x = x * level::finalTileSize;
        y = y * level::finalTileSize;
        width = width * level::finalTileSize;
        height = height * level::finalTileSize;
        targetX = targetX * level::finalTileSize;
        targetY = targetY * level::finalTileSize;
    }
}

/*
Need to find portal data in memory and load it in

*/
//LEVEL-TLX-TLY-WIDTH-HEIGHT-TGTLEVEL-TGTX-TGTY