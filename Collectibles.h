#pragma once

class collectibles {
public:
	const int maxNumOfCoins = 32;
	int coins[32][3];
	bool coinsExist[32];
	int coinTimer = 0;
	int coinFrame = 0;


	collectibles();
	void processCoinFrame();
	void setTo(collectibles newCol);
	void makeCoin(int x, int y, int value);
	void clearCoins();
};