#include<iostream>
#include<string>
#include <fstream>
#include<vector>
using namespace std;


int findInt(string name) {
    string plainText;
    ifstream ScrnData("./assets/presets.txt");
    for (int i = 0; i < 3; i++) {
        if (plainText.find(name) != string::npos) {
            break;
        }
        getline(ScrnData, plainText);
    }
    int startOfValue = 0;
    for (int i = 0; i < plainText.length(); i++) {
        if (plainText[i] == ':') {
            startOfValue = i + 1;
            break;
        }
    }
    return stoi(plainText.substr(startOfValue, plainText.length()));
}




class game { //contains general info. TileSize, WindowSize
public:
    int tileWidth,tileHeight;
    int tileSize;
};

class frameObj {
public:
	int sourceX, sourceY;
	bool flip;
	int imgWidth, imgHeight;
};

class animationObj { //single animation. <animObj> contains multiple of these to make a fully realized character.
public:
	int animId;
	vector<frameObj> frames;


};

class baseObj {
public:
	int x, y;
	int dir;
	int width, height;

};

class billboardObj : frameObj { //static image. Can't be interacted with. Doesn't move. Ex. untouchable walls, plain ground tiles
public:

};

class animObj : public baseObj { //non-interactive animated surface, ex. particles, smoke, animated ground tiles
public:
	int frameId, frameCounter, animationId;
	vector<animationObj> anims;
};

class interactiveObj : public animObj { //can be interacted with. ex. walls, liquids, pits, spikes, pushable terrain
public:
	int xv, yv;
	bool isHarmful;
	bool isSolid;




	void move(int xin, int yin) {
		x = xin;
		y = yin;
	}
};

class player : public interactiveObj {

};

int main() {
    cout << "playerStartX: " << findInt("playerStartX") << endl;
    cout << "playerStartY: " << findInt("playerStartY") << endl;
    cout << "playerStartLvl: " << findInt("playerStartLvl") << endl;
    return 0;
}
