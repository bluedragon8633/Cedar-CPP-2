#include"GlobalVars.h"
#include"general.h"

namespace Global {
    int MAP;
    int LEVEL;
    bool DEBUG;
    string STATUS = "splash";
    int mapWidth, mapHeight;
    int playerStartX, playerStartY;
    int startLvl, startMap;
    vector<int> testVect;

    int tiles[25][15][2] = {};

    int tileWidth, tileHeight;
    int TILE_SIZE;
    int windowWidth, windowHeight;
    int GAME_SCALE;
    int scrnWidth, scrnHeight;
    int FRAME_LIMIT;
    int playFieldTopY, playFieldBotY;
    int playFieldLeftX, playFieldRightX;
    string TITLE;





	void loadData() {
        General g;
        playerStartX = g.findInt("playerStartX");
        playerStartY = g.findInt("playerStartY");
        tileWidth = g.findInt("tileWidth");
        tileHeight = g.findInt("tileHeight");
        scrnWidth = g.findInt("scrnWidth");
        scrnHeight = g.findInt("scrnHeight");
        GAME_SCALE = g.findInt("GAME_SCALE");
        TILE_SIZE = g.findInt("TILE_SIZE");
        FRAME_LIMIT = g.findInt("FRAME_LIMIT");
        playFieldTopY = g.findInt("playFieldTopY");
        playFieldBotY = g.findInt("playFieldBotY");
        playFieldLeftX = g.findInt("playFieldLeftX");
        playFieldRightX = g.findInt("playFieldRightX");
	}

    void loadDefault() {
        loadData();
        TITLE = "Default title";
        STATUS = "splash";
        LEVEL = 0;
        MAP = 0;
        DEBUG = 0;
        mapWidth = 0;
        mapHeight = 0;
        playerStartX = 0;
        playerStartY = 0;
        startLvl = 0;
        startMap = 0;
    }
	
	
	void Console::log(string text) {
		cout << text << endl;
	}

	void Console::log(string text,bool requireKey) {
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Q))) {
			cout << text << endl;
		}

	}
}
